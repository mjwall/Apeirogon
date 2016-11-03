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
