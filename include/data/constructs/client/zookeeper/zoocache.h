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

#ifndef ZOOCACHE_H
#define ZOOCACHE_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <initializer_list>
using namespace std;

#include "../../inputvalidation.h"
#include "../InstanceCache.h"
#include "zookeepers.h"
#include "watch.h"

#include <time.h>
#include <pthread.h>

namespace cclient {
namespace data {
namespace zookeeper {

  
  
class ZooCache: public cclient::data::InstanceCache {
public:
    ZooCache(ZooKeeper *zk) :
        myZk(zk) {
        pthread_mutex_init(&syncBarrier, NULL);
        cache = new map<string, uint8_t*>();
        childrenCache = new map<string, list<string>*>();
    }

    ~ZooCache() {
	
	cout << "Clearing out zoocache" << endl;
	clear();
	pthread_mutex_lock(&syncBarrier);
	for(auto fn : fns)
	{
	  delete fn;
	}
	fns.clear();
        delete cache;
        delete childrenCache;
	pthread_mutex_unlock(&syncBarrier);
    }

    inline static void cache_watcher(zhandle_t *, int type, int state,
                              const char *path, void*v) {

        WatchFn *ctx = (WatchFn*) v;
        ZooCache *cacheRef = (ZooCache*) ctx->Fn;
        Event *event = new Event();
        event->path = path;
        event->type = type;
        if (type == ZOO_CHANGED_EVENT || type == ZOO_CHILD_EVENT
                || type == ZOO_CREATED_EVENT || type == ZOO_DELETED_EVENT) {
            cacheRef->removePath(event);
        } else if (type == ZOO_SESSION_EVENT) {
            if (state != ZOO_CONNECTED_STATE) {
                cacheRef->clear();
            }

        } else {
            // do nothing
        }
        
        pthread_mutex_lock(&cacheRef->syncBarrier);
        std::set<WatchFn*>::iterator it = cacheRef->fns.find(ctx);
	cacheRef->fns.erase(it);
	pthread_mutex_unlock(&cacheRef->syncBarrier);
        
	assert(ctx != NULL);
	delete ctx;

    }

    uint8_t *getData(string path) {

        if (IsEmpty(&path)) {
            return NULL;
        }
        pthread_mutex_lock(&syncBarrier);

        map<string, uint8_t*>::iterator cachedData = cache->find(path);

        if (cachedData == cache->end()) {

            WatchFn *watchFp = new WatchFn();
	    fns.insert(watchFp);
            watchFp->Fn = this;
            if (myZk->exists(path, cache_watcher, watchFp)) {
                watchFp = new WatchFn();
		fns.insert(watchFp);
                watchFp->Fn = this;

                uint8_t *data = (uint8_t*) myZk->getData(path, cache_watcher,
                                watchFp);
                cache->insert(
                    std::pair<string, uint8_t*>(string(path),
                                                (uint8_t*) data));
                pthread_mutex_unlock(&syncBarrier);
                return data;
            } else {
                pthread_mutex_unlock(&syncBarrier);
                return NULL;
            }

            cachedData = cache->find(path);
        }

        uint8_t *ptr = cachedData->second;

        pthread_mutex_unlock(&syncBarrier);

        return ptr;
    }

    list<string> getChildren(const string path, bool force = false) {


        if (IsEmpty(&path)) {
            return list<string>();
        }
        if (force)
            clear();
        pthread_mutex_lock(&syncBarrier);

        map<string, list<string>*>::iterator children = childrenCache->find(
                    path);

        if (children == childrenCache->end()) {
            WatchFn *watchFp = new WatchFn();
	    fns.insert(watchFp);
            watchFp->Fn = this;

            list<string> *results = myZk->getChildren(path, cache_watcher,
                                    watchFp);

            if (NULL != results) {
                childrenCache->insert(
                    std::pair<string, list<string>*>(string(path),
                                                     results));
            }

            children = childrenCache->find(path);
        }

        if (children == childrenCache->end()) {
            pthread_mutex_unlock(&syncBarrier);
            return list<string>();
        }
        list<string> strings(*children->second);
        pthread_mutex_unlock(&syncBarrier);

        return strings;
    }

protected:

    void removePath(Event *event) {
        if (NULL == event || IsEmpty(&event->path)) {
            delete event;
            return;
        }
        pthread_mutex_lock(&syncBarrier);
        // critical section

        map<string, uint8_t*>::iterator find = cache->find(event->path);
        if (find != std::end(*cache)) {
            uint8_t *prevMemory = find->second;
            cache->erase(find);
            delete[] prevMemory;
        }
        map<string, list<string>*>::iterator childFind = childrenCache->find(
                    event->path);
        if (childFind != std::end(*childrenCache)) {
            list<string>* children = childFind->second;
            childrenCache->erase(childFind);
            delete children;
        }

        pthread_mutex_unlock(&syncBarrier);
        delete event;

    }

    void clear() {

        pthread_mutex_lock(&syncBarrier);
        // critical section

        for (auto it = cache->begin(); it != cache->end(); it++) {
            delete[] it->second;
        }

        cache->clear();

        for (auto it = childrenCache->begin(); it != childrenCache->end();
                it++) {
            delete it->second;
        }

        childrenCache->clear();

        pthread_mutex_unlock(&syncBarrier);

    }

    set<WatchFn*> fns;
    ZooKeeper *myZk;
    map<string, uint8_t*> *cache;
    map<string, list<string>*> *childrenCache;
    pthread_mutex_t syncBarrier;
};

}
}
}
#endif // ZOOCACHE\_H
