/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
	


