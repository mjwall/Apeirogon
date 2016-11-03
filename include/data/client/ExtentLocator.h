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
