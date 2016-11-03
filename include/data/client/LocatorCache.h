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

#ifndef SRC_DATA_CLIENT_LOCATORCACHE_H_
#define SRC_DATA_CLIENT_LOCATORCACHE_H_

#include <map>
using namespace std;
#include "ExtentLocator.h"

#include <pthread.h>

namespace cclient {
namespace impl {



class LocatorCache {
public:
    LocatorCache();
    virtual ~LocatorCache();
    void put(LocatorKey key, TabletLocator *locator) {
        locatorCache->insert(std::make_pair(key, locator));
    }

    TabletLocator *getLocator(LocatorKey key);
protected:
    map<LocatorKey, TabletLocator*> *locatorCache;
    pthread_mutex_t locatorMutex;
};

extern LocatorCache cachedLocators;

} /* namespace impl */
} /* namespace cclient */

#endif /* SRC_DATA_CLIENT_LOCATORCACHE_H_ */
