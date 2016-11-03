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

#ifndef DATA_CLIENT_IMPL_METADATA_ROOTTABLETLOCATOR_H_
#define DATA_CLIENT_IMPL_METADATA_ROOTTABLETLOCATOR_H_

#include <set>
#include <vector>
using namespace std;
#include "ExtentLocator.h"

#include "../constructs/column.h"
#include "../constructs/StructureDefinitions.h"
#include "../constructs/client/Instance.h"
#include "../constructs/client/zookeeperinstance.h"
#include "TabletLocationObtainer.h"
#include "../constructs/security/AuthInfo.h"
namespace cclient {
namespace impl {

using namespace cclient::data;
using namespace cclient::data::zookeeper;
using namespace cclient::data::security;

static KeyExtent *ROOT_EXTENT = new KeyExtent("+r", "", "");

class RootTabletLocator: public TabletLocator {
public:
    RootTabletLocator(Instance *instance);
    ~RootTabletLocator();

    TabletLocation *locateTablet(AuthInfo *creds, string row, bool skipRow, bool retry) {
        TabletLocation *location = getRootTabletLocation();

        while (retry && location == NULL) {
            pthread_yield();

            location = getRootTabletLocation();

        }

        return location;

    }

    void binMutations(AuthInfo *credentials, vector<Mutation*> *mutations,
                      map<string, TabletServerMutations*> *binnedMutations,
                      set<string> *locations, vector<Mutation*> *failures) {
    }

    virtual vector<Range*> binRanges(AuthInfo *credentials,vector<Range*> *ranges,
                                     set<string> *locations,
                                     map<string, map<KeyExtent*, vector<Range*>,pointer_comparator<KeyExtent*> > > *binnedRanges) {
        return vector<Range*>();
    }

    void invalidateCache(KeyExtent failedExtent) {
    }

    void invalidateCache() {
    }

    void invalidateCache(vector<KeyExtent> keySet) {
    }



protected:

    TabletLocation *getRootTabletLocation();
    ZookeeperInstance *myInstance;
};
}
}
#endif /* DATA_CLIENT_IMPL_METADATA_ROOTTABLETLOCATOR_H_ */
