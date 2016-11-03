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

#ifndef EXTENTLOCATOR_H_
#define EXTENTLOCATOR_H_

#include <string>
#include <map>
#include <vector>
#include <set>
#include "../constructs/client/TabletServerMutations.h"
#include "../constructs/Mutation.h"
#include "../constructs/Range.h"
#include "../constructs/client/Instance.h"
using namespace std;

#include "TabletLocation.h"
namespace cclient
{
namespace impl
{

using namespace cclient::data;

class LocatorKey
{
public:
    LocatorKey (Instance *instance, string table) :
        instance (instance), tableName (table)
    {

    }
    Instance *instance;
    string tableName;
    bool
    operator== (const LocatorKey &key)
    {
        return instance->getInstanceId () == key.instance->getInstanceId ()
               && tableName == key.tableName;
    }

    bool
    operator > (const LocatorKey &key) const
    {

        return instance->getInstanceId () >= key.instance->getInstanceId ()
               && tableName > key.tableName;
    }

    bool
    operator < (const LocatorKey &key) const
    {
        return instance->getInstanceId () <= key.instance->getInstanceId ()
               && tableName < key.tableName;
    }

};

class TabletLocator
{
public:
    TabletLocator ();
    virtual
    ~TabletLocator ();

    virtual TabletLocation *
    locateTablet (AuthInfo *creds, string row, bool skipRow, bool retry) = 0;

    
    virtual list<TabletLocation*> locations(AuthInfo *credentials)
    {
      return list<TabletLocation*>();
    } 
    
    virtual void
    binMutations (AuthInfo *credentials, vector<Mutation*> *mutations,
                  map<string, TabletServerMutations*> *binnedMutations,
                  set<string> *locations, vector<Mutation*> *failures) = 0;

    virtual vector<Range*>
    binRanges (
        AuthInfo *credentials,
        vector<Range*> *ranges,
        set<string> *locations,
        map<string,
        map<KeyExtent*, vector<Range*>, pointer_comparator<KeyExtent*> > > *binnedRanges) = 0;

    virtual void
    invalidateCache (KeyExtent failedExtent) = 0;

    virtual void
    invalidateCache () = 0;

    virtual void
    invalidateCache (vector<KeyExtent> keySet) = 0;

};

} /* namespace data */
} /* namespace cclient */
#endif /* EXTENTLOCATOR_H_ */
