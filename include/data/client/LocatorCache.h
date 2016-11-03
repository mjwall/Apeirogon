/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * Key/value connector. Copyright (C)  2015
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
