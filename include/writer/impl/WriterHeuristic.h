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
#ifndef SRC_WRITER_IMPL_WRITERHEURISTIC_H_
#define SRC_WRITER_IMPL_WRITERHEURISTIC_H_

#include <pthread.h>
#include "../../scanner/constructs/Heuristic.h"
#include "../../data/constructs/server/ServerDefinition.h"
#include "../../data/extern/concurrentqueue/concurrentqueue.h"
#include "../SinkConditionals.h"
#include "../../interconnect/TabletServer.h"

namespace writer {

using namespace interconnect;
using namespace scanners;
using namespace cclient::data::tserver;

struct WritePair {
    //ServerInterconnect *interconnect;
    ServerDefinition *rangeDef;
    const Configuration *conf;
    TabletServerMutations *mutations;
};

/*
 *
 */
class WriterHeuristic: public Heuristic<interconnect::ThriftTransporter> {
public:

    WriterHeuristic(short numThreads = 10);
    /**
     * Add a server interconnect
     */
    void addClientInterface(
        ClientInterface<interconnect::ThriftTransporter> *serverIfc) {
        pthread_mutex_lock(&serverLock);
        Heuristic::addClientInterface(serverIfc);
        pthread_mutex_unlock(&serverLock);
    }

    uint16_t write(//ServerInterconnect *interConnect,
		   ServerDefinition *rangeDef,
		   const Configuration *conf,
                   TabletServerMutations *mutations) {

        if (!started) {
            pthread_mutex_lock(&serverLock);
            if (!started) {
                for (int i = 0; i < threadCount; i++) {
                    pthread_create(&threads[i], NULL, write_thrift,
                                   (void*) this);
                }
            }
            started = true;
            pthread_mutex_unlock(&serverLock);
        }

        WritePair *pair = new WritePair;
        //pair->interconnect = interConnect;
	pair->conf = conf;
	pair->rangeDef = rangeDef;
        pair->mutations = mutations;
	while(!queue->try_enqueue(pair))
	{
	  if (!conditionals->isAlive())
	    throw runtime_error("Closed during write");
	}

        conditionals->awakeThreadsForResults();
        return queue->size_approx();
    }

    void close() {

      pthread_mutex_lock(&serverLock);
      if (threads == NULL)
      {

	pthread_mutex_unlock(&serverLock);
	return;
      }
      closed = true;
      
	if (started)
	{
	  conditionals->awakeThreadsFinished();
	  for (int i = 0; i < threadCount; i++) {
	      pthread_join(threads[i], NULL);
	  }
	  
	}
	conditionals->close();

        delete[] threads;
        
        threads = NULL;
	pthread_mutex_unlock(&serverLock);

    }

     uint64_t maxThreads()
    {
      return threadCount;
    }
    
    uint64_t size()
    {
      return queue->size_approx();
    }
    virtual ~WriterHeuristic();
protected:

    static void *write_thrift(void *ptr) {
      

        WriterHeuristic *heuristic = static_cast<WriterHeuristic*>(ptr);

	WritePair *pair = NULL;
        do {
            pair = heuristic->next();
	    
            if (NULL != pair) {
                ServerInterconnect *conn=
		        new interconnect::ServerInterconnect (
		        pair->rangeDef, pair->conf);

                if (NULL != conn) {

                    conn->write(pair->mutations);

                    delete pair->rangeDef;
                    delete pair->mutations;
		    delete conn;
                }

                delete pair;
            } else {
                break;
            }
            

        } while (NULL != pair);

        return 0;
    }

    virtual WritePair *next() {
        WritePair *pair = NULL;
	
	if (!conditionals->isAlive())
	{
	  return pair;
	}

        do {
            if (!queue->try_dequeue(pair)) {
                conditionals->waitForResults();
                if (queue->try_dequeue(pair)) {
                    break;
                }
                if (conditionals->isClosing()) {
                    return NULL;
                }

            }
            else
	    {
	      break;
	    }
            
        } while (conditionals->isAlive());

        return pair;

    }

    volatile bool started;

    moodycamel::ConcurrentQueue<WritePair*> *queue;
private:
    SinkConditions *conditionals;
    pthread_mutex_t serverLock = PTHREAD_MUTEX_INITIALIZER;
    pthread_t *threads;
    uint16_t threadCount;
    volatile bool closed;
}
;

} /* namespace data */

#endif /* SRC_WRITER_IMPL_WRITERHEURISTIC_H_ */
