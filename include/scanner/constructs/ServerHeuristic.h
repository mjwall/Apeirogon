/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2016
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

#ifndef SERVERHEURISTIC_H_
#define SERVERHEURISTIC_H_

#include "Heuristic.h"
#include "../../interconnect/TabletServer.h"
#include "../../interconnect/Scan.h"
#include "../Source.h"

#include <pthread.h>

namespace scanners
{

template<typename T>
struct ScanPair {
	Source<KeyValue*, ResultBlock<KeyValue*>> *src;
	Heuristic<T> *heuristic;
};

/**
 * Contains base functionality to support multi scanning
 */

class ScannerHeuristic : Heuristic<interconnect::ThriftTransporter>
{

public:

	/**
	 * Add a server interconnect
	 */
	void
	addClientInterface (
	        ClientInterface<interconnect::ThriftTransporter> *serverIfc)
	{
		pthread_mutex_lock (&serverLock);
		Heuristic::addClientInterface (serverIfc);
		pthread_mutex_unlock (&serverLock);
	}

	ScannerHeuristic (short numThreads = 10) :
		threadCount (numThreads), threads (NULL), started (false)
	{
		threads = new pthread_t[threadCount];
	}

	~ScannerHeuristic ()
	{
		if (threads != NULL) {
		    pthread_mutex_lock (&serverLock);
		    if (threads != NULL) {
			if (started)
			{
			      for (int i = 0; i < threadCount; i++) {
				      pthread_exit (&threads[i]);
			      }
			}
			  delete threads;
			  threads = NULL;
			  started= false;
		    }
		  pthread_mutex_unlock (&serverLock);
		}

	}

	uint16_t
	scan (Source<KeyValue*, ResultBlock<KeyValue*>> *source)
	{

		uint16_t scans = 0;
		for (int i = 0; i < threadCount; i++) {
			ScanPair<interconnect::ThriftTransporter> *pair = new ScanPair<
			interconnect::ThriftTransporter>;
			pair->src = source;
			pair->heuristic = this;
			pthread_create (&threads[i], NULL, scanRoutine, (void*) pair);
		}
		return scans;
	}

private:
	pthread_mutex_t serverLock = PTHREAD_MUTEX_INITIALIZER;
	pthread_t *threads;
	uint16_t threadCount;
protected:

	static void
	closeScan (void *ptr)
	{
		Source<KeyValue*, ResultBlock<KeyValue*>> *source = static_cast<Source<
		                                       KeyValue*, ResultBlock<KeyValue*>>*> (ptr);
		source->getResultSet ()->decrementProducers ();

	}

	static void *
	scanRoutine (void *ptr)
	{

		ScanPair<ScannerHeuristic> *scanResource = static_cast<ScanPair<
		                ScannerHeuristic>*> (ptr);
		Source<KeyValue*, ResultBlock<KeyValue*>> *source = scanResource->src;

		source->getResultSet ()->registerProducer ();

		pthread_cleanup_push(closeScan,source);

		ServerInterconnect *conn = 0;
		do {
			conn = ((ScannerHeuristic*) scanResource->heuristic)->next ();
			if (NULL != conn) {

				Scan *scan = conn->scan (source->getColumns(),source->getIters());

				do {
					vector<KeyValue*> nextResults;

					scan->getNextResults (&nextResults);

					source->getResultSet ()->add (&nextResults);
					nextResults.clear ();
					
					Scan *newScan = conn->continueScan(scan);
					
					if (NULL == newScan)
					{
					  delete scan;
					  scan = NULL;
					}
					else
					  scan = newScan;
					
				} while( scan != NULL);
				


			} else {
				delete scanResource;
				break;
			}
		} while (NULL != conn);

		pthread_cleanup_pop(1);

		return 0;

	}

	virtual ServerInterconnect *
	next ()
	{
		ClientInterface<interconnect::ThriftTransporter> *nextService = NULL;

		pthread_mutex_lock (&serverLock);

		if (!servers.empty ()) {
			nextService = servers.back ();
			servers.pop_back ();
		}

		pthread_mutex_unlock (&serverLock);

		ServerInterconnect *connector =
		        dynamic_cast<ServerInterconnect*> (nextService);

		return connector;

	}

	bool started;
	vector<ClientInterface<interconnect::ThriftTransporter>*>::iterator it;

};
}
#endif /* SERVERHEURISTIC_H_ */
