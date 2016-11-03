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
