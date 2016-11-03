/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2015
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/
#include "../../../include/writer/impl/SinkImpl.h"

#include "../../../include/writer/impl/../../data/constructs/KeyValue.h"
#include "../../../include/writer/impl/../../data/constructs/Mutation.h"
#include "../../../include/writer/impl/../../data/constructs/Key.h"
#include "../../../include/writer/impl/../../data/constructs/value.h"
#include "../../../include/writer/impl/WriterHeuristic.h"
using namespace writer;

using namespace cclient::data;

BatchWriter::BatchWriter (Instance *instance,
                    TableOperations<KeyValue*, ResultBlock<KeyValue*>> *tops,
                    Authorizations *auths, uint16_t threads) :
	Sink<KeyValue*> (500)
{
	connectorInstance = dynamic_cast<ZookeeperInstance*> (instance);
	tableLocator = cachedLocators.getLocator (
	                       LocatorKey (connectorInstance, tops->getTableId ()));
	credentials = tops->getCredentials ();
	writerHeuristic = new WriterHeuristic (threads);
}

BatchWriter::~BatchWriter ()
{
	writerHeuristic->close();
	delete writerHeuristic;
}

void
BatchWriter::flush (bool override)
{
	while(sinkQueue->size_approx() > 0)
	{
	KeyValue **kv = new KeyValue*[queueSize];
	size_t dequeued = sinkQueue->try_dequeue_bulk (kv, queueSize);
	Mutation *prevMutation = NULL;
	vector<Mutation*> *mutation = new vector<Mutation*> ();
	for (uint64_t i = 0; i < dequeued; i++) {
		Key *key = kv[i]->getKey ();
		Value *value = kv[i]->getValue ();
		if (NULL != prevMutation) {
			std::pair<char*, size_t> row = key->getRow ();
			if (row.second > 0) {
				string rowStr = string (row.first, row.second);
				if (prevMutation->getRow () == rowStr) {

					prevMutation->put (key->getColFamilyStr (),
					                   key->getColQualifierStr (),
					                   key->getColVisibilityStr (),
					                   key->getTimeStamp (), key->isDeleted (),
					                   value->data (), value->size ());
					delete kv[i];
					continue;
				}

			}

		}
		Mutation *m = new Mutation (key->getRowStr ());
		m->put (key->getColFamilyStr (), key->getColQualifierStr (),
		        key->getColVisibilityStr (), key->getTimeStamp (),
		        key->isDeleted (), value->data (), value->size ());
		prevMutation = m;
		mutation->push_back (m);
		delete kv[i];

	}
	//delete kv;

	map<string, TabletServerMutations*> binnedMutations;
	set<string> locations;
	vector<Mutation*> failures;
	tableLocator->binMutations (credentials, mutation, &binnedMutations,
	                            &locations, &failures);
	for (string location : locations) {
		vector<string> locationSplit = split (location, ':');
		ServerDefinition *rangeDef = new ServerDefinition (
		        credentials,
		        NULL,
		        locationSplit.at (0), atoi (locationSplit.at (1).c_str ()));
		writerHeuristic->write (rangeDef, connectorInstance->getConfiguration(), binnedMutations.at (location));

	}
	

	  
	    delete[] kv;

	    delete mutation;
	}

	      if (override) {
		writerHeuristic->close ();
	      }
	
}
	


