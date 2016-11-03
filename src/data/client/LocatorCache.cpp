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
#include <map>
using namespace std;
#include "../../../include/data/client/../constructs/tables/tables.h"
#include "../../../include/data/client/../constructs/client/Instance.h"
#include "../../../include/data/client/TabletServerLocator.h"
#include "../../../include/data/client/MetaDataLocationObtainer.h"
#include "../../../include/data/client/RootTabletLocator.h"
#include "../../../include/data/client/ExtentLocator.h"
#include "../../../include/data/client/LocatorCache.h"
namespace cclient
{
namespace impl
{

LocatorCache cachedLocators;

LocatorCache::LocatorCache ()
{
    locatorCache = new map<LocatorKey, TabletLocator*> ();
    pthread_mutexattr_t Attr;

    pthread_mutexattr_init (&Attr);
    pthread_mutexattr_settype (&Attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init (&locatorMutex, &Attr);
}

LocatorCache::~LocatorCache ()
{
    for (auto& locatorEntry : *locatorCache)
    {
        delete locatorEntry.second;
    }
    delete locatorCache;
}

TabletLocator *
LocatorCache::getLocator (LocatorKey key)
{
    pthread_mutex_lock (&locatorMutex);

    // critical section

    map<LocatorKey, TabletLocator*>::iterator it = locatorCache->find (key);
    TabletLocator *locator = NULL;
    if (it != locatorCache->end ())
    {
        locator = it->second;

    }
    Instance *instance = key.instance;

    if (NULL == locator)
    {

        MetaDataLocationObtainer *mlo = new MetaDataLocationObtainer (
            instance);

        if (key.tableName.find (ROOT_TABLE_ID) != std::string::npos)
        {
            locator = new RootTabletLocator (instance);
        }
        else if (key.tableName.find (META_TABLE_ID) != std::string::npos)
        {
            locator = new TabletServerLocator (
                META_TABLE_ID,
                getLocator (LocatorKey (instance, ROOT_TABLE_ID)), mlo,
                instance);
        }
        else
        {
            locator = new TabletServerLocator (
                key.tableName,
                getLocator (LocatorKey (instance, META_TABLE_ID)), mlo,
                instance);

        }

        put (key, locator);

    }

    pthread_mutex_unlock (&locatorMutex);
    return locator;
}

} /* namespace impl */
} /* namespace cclient */
