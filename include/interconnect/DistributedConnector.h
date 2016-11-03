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

#ifndef DISTRIBUTEDCONNECTOR_H_
#define DISTRIBUTEDCONNECTOR_H_

#include "transport/BaseTransport.h"
#include "InterConnect.h"
#include <sstream>
#include <algorithm>
#include <random>

#include "transport/ServerConnection.h"
#include "transport/CachedTransport.h"

#include <map>
#include <vector>
#include <set>
#include <arpa/inet.h>

#include <pthread.h>
#include <boost/shared_ptr.hpp>

namespace interconnect {
template<typename Tr>
class DistributedConnector {
public:
    DistributedConnector();

    ~DistributedConnector();

    void freeTransport(CachedTransport<Tr> *cachedTransport);

    
    std::pair<string, CachedTransport<Tr>*> getTransporter(
            const vector<ServerConnection> *servers,
            const bool preferCachedConnection);

    CachedTransport<Tr> * getTransporter(ServerConnection *conn)
    {
      vector<ServerConnection> servers;
      servers.push_back(*conn);
      std::pair<string, CachedTransport<Tr>*> cached = getTransporter(&servers,true);
      return cached.second;
    }
    
    
    
    void closeAll()
    {
      if (!closed)
      {
	pthread_mutex_lock(&cacheLock);
	
	if (!closed)
	{
	  closing = true;	
	  for(auto ent1 : *cache) {      
	  for(auto sec : ent1.second)
	  {
	      sec->close();
	      
	      delete sec;
	  }
	}
	}
	closed = true;
	pthread_mutex_unlock(&cacheLock);
      }
    }	

protected:
  
    volatile bool closed;
    volatile bool closing;
    CachedTransport<Tr> *createNewTransport(ServerConnection *conn);

    pthread_mutex_t cacheLock;

    std::map<ServerConnection, std::vector<CachedTransport<Tr>*>> *cache;
    std::map<ServerConnection, uint32_t> errorCount;
    std::map<ServerConnection, uint32_t> errorTime;
    std::set<ServerConnection> badServers;
};

template<typename Tr>
DistributedConnector<Tr>::DistributedConnector() : closed(false), closing(false){
    cache = new map<ServerConnection, vector<CachedTransport<Tr>*>>();
    cacheLock= PTHREAD_MUTEX_INITIALIZER;
    pthread_mutexattr_t Attr;

    pthread_mutexattr_init(&Attr);
    pthread_mutexattr_settype(&Attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&cacheLock, &Attr);
}

template<typename Tr>
DistributedConnector<Tr>::~DistributedConnector() {
  if (cache != NULL)
  {
    closeAll();
    delete cache;
    cache= NULL;
  }
}

template<typename Tr>
void DistributedConnector<Tr>::freeTransport(
    CachedTransport<Tr> *cachedTransport) {
  
  if (IsEmpty(cachedTransport) || closed)
        return;
    
    vector<CachedTransport<Tr>*> *closeList =
        new vector<CachedTransport<Tr>*>();
    pthread_mutex_lock(&cacheLock);
    
    if( closing || closed) 
    {
      
      pthread_mutex_unlock(&cacheLock);
      return;
    }

    ServerConnection *cacheKey = cachedTransport->getCacheKey();

    vector<CachedTransport<Tr>*> *cachedConnections = &(cache->at(*cacheKey));
    typename vector<CachedTransport<Tr>*>::iterator cacheIter =
        cachedConnections->begin();
    
    timeval time;
    gettimeofday(&time, NULL);
    long millis = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    for (; cacheIter != cachedConnections->end(); cacheIter++) {
        if (std::addressof(**cacheIter) == std::addressof(*cachedTransport)) {
            if (cachedTransport->hasError()) {

                uint32_t errors = 0;

                if (errorCount.find(*cacheKey) != errorCount.end()) {
                    errors = errorCount.at(*cacheKey);
                }

                errors++;

                errorCount[*cacheKey] = errors;

                errorTime[*cacheKey] = millis;

                if (errors > ERROR_THRESHOLD
                        && badServers.find(*cacheKey) == badServers.end()) {
                    badServers.insert(*cacheKey);
                }

            } else {
            }
            (*cacheIter)->setReturnTime(millis);
            (*cacheIter)->reserve(false);
            break;

        }
    }

    if (cachedTransport->hasError()) {
        cacheIter = cachedConnections->begin();
        for (; cacheIter != cachedConnections->end(); ) {
            if (!(*cacheIter)->isReserved()) {
                closeList->push_back(*cacheIter);
                cacheIter = cachedConnections->erase(cacheIter);
            }else{
	      cacheIter++;
	    }
        }

    }
    
    for(auto closer : *closeList)
    {
	closer->close();
    }
    
    delete closeList;

    pthread_mutex_unlock(&cacheLock);

}

template<typename Tr>
std::pair<string, CachedTransport<Tr>*> DistributedConnector<Tr>::getTransporter(
        const vector<ServerConnection> *servers,
const bool preferCachedConnection) {

  
    if (preferCachedConnection) { 
        pthread_mutex_lock(&cacheLock);
        set<ServerConnection> serverSet(
            servers->begin(), servers->end());
        typename map<ServerConnection, vector<CachedTransport<Tr>*>>::iterator it =
                    cache->begin();
        for (; it != cache->end(); it++) {
            ServerConnection conn = it->first;
            serverSet.insert(conn);
        }
        if (!IsEmpty(&serverSet)) {
	  
	    vector<ServerConnection> connections(std::begin(serverSet),std::end(serverSet));
	    auto engine = std::default_random_engine{};
	    
            std::shuffle(connections.begin(), connections.end(),engine );

            for (ServerConnection conn : connections) {
                vector<CachedTransport<Tr>*> *cachedConnections = &(*cache)[conn];
                for (CachedTransport<Tr> *cacheTransport : *cachedConnections) {
                    if (!cacheTransport->isReserved() && !cacheTransport->hasError())
		    {
                        cacheTransport->reserve();
                        stringstream hostname;
                        hostname << conn.getHost() << ":" << conn.getPort();
                        pthread_mutex_unlock(&cacheLock);
                        return std::make_pair(
                                   hostname.str(),
                                   cacheTransport);
                    }
                    else
		    {

		    }
                }
            }

        }
        pthread_mutex_unlock(&cacheLock);

    }

    vector<ServerConnection> serverPool(*servers);

    short retryCount = 0;

    ServerConnection *conn;
    while (serverPool.size() > 0 && retryCount < 10) {
        int index = std::rand() % serverPool.size();
        conn = &serverPool.at(index);
        if (preferCachedConnection) {
            pthread_mutex_lock(&cacheLock);
            vector<CachedTransport<Tr>*> *cachedConnections = &(*cache)[*conn];
            if (!IsEmpty(cachedConnections)) {
                for (CachedTransport<Tr> *cacheTransport : *cachedConnections) {
                    if (!cacheTransport->isReserved() && !cacheTransport->hasError()) {
                        cacheTransport->reserve();
                        stringstream hostname;
                        hostname << conn->getHost() << ":" << conn->getPort();
                        pthread_mutex_unlock(&cacheLock);

                        return std::make_pair(
                                   hostname.str(),
                                   cacheTransport);
                    }
                }
            }
            
        }

        try {
            stringstream hostname;
            hostname << conn->getHost() << ":" << conn->getPort();
	    std::pair<string, CachedTransport<Tr>*> pair = std::make_pair(hostname.str(),
                    createNewTransport(conn));
	    pthread_mutex_unlock(&cacheLock);
            return pair;
        } catch (runtime_error &tfe) {
	  cout << "runtime error occurred" << endl;
            serverPool.erase(serverPool.begin() + index);
            retryCount++;
        }

    }

    throw runtime_error("Failed to connect to server");
}

template<typename Tr>
CachedTransport<Tr> *DistributedConnector<Tr>::createNewTransport(
    ServerConnection *conn) {
  
  
    
    pthread_mutex_lock(&cacheLock);
    
    Tr *t = new Tr(conn);
   
    CachedTransport<Tr> *cachedTransport = new CachedTransport<Tr>(t,
            conn);

    cachedTransport->reserve();


    try {
        vector<CachedTransport<Tr>*> *cachedConnections = &cache->at(*conn);

        cachedConnections->push_back(cachedTransport);
    } catch (const std::out_of_range& ex) {
        vector<CachedTransport<Tr>*> *cachedConnections = new vector<
        CachedTransport<Tr>*>();

        cachedConnections->push_back(cachedTransport);
	
	cache->insert(std::make_pair(*conn,*cachedConnections));
	
	delete cachedConnections;
      
    }

    pthread_mutex_unlock(&cacheLock);

    return cachedTransport;

}

}

#endif /* DISTRIBUTEDCONNECTOR_H_ */
