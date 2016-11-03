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

#include <sstream>
using namespace std;
#include "../../../include/data/client/RootTabletLocator.h"
#include "../../../include/data/client/../constructs/client/Instance.h"
#include "../../../include/data/client/ExtentLocator.h"

using namespace cclient::impl;
using namespace cclient::data;
using namespace cclient::data::zookeeper;

RootTabletLocator::RootTabletLocator (Instance *instance) :
    myInstance (dynamic_cast<ZookeeperInstance*> (instance))
{

}

RootTabletLocator::~RootTabletLocator ()
{

}

TabletLocation *
RootTabletLocator::getRootTabletLocation ()
{

    ZooCache *cache = myInstance->getZooCache ();

    stringstream zRootLocation;
    zRootLocation << myInstance->getRoot () << ZROOT_TABLET_LOCATION;

    uint8_t *rootLoc = cache->getData (zRootLocation.str ());

    if (IsEmpty ((char*) rootLoc))
    {
        return 0;
    }

    vector<string> tokens = split (string ((char*) rootLoc), '|');

    return new TabletLocation (new KeyExtent( ROOT_EXTENT), tokens.at (0), tokens.at (1));

}
