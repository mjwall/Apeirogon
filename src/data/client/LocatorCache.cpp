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
