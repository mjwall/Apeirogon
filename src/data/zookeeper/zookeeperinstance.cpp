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
#include "../../../include/data/constructs/client/Instance.h"
#include "../../../include/data/constructs/client/./zookeeperinstance.h"
#include "../../../include/data/constructs/client/./zookeeper/zookeepers.h"
#include "../../../include/data/constructs/client/./zookeeper/zoocache.h"
#include "../../../include/data/constructs/client/../configuration/Configuration.h"
#include "../../../include/data/constructs/client/Connector.h"

#include "../../../include/data/constructs/client/../inputvalidation.h"
#include "../../../include/data/constructs/client/../../../interconnect/InterConnect.h"

#include "../../../include/data/exceptions/ClientException.h"

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>
#include <boost/iterator/iterator_concepts.hpp>

namespace cclient
{
namespace data
{
namespace zookeeper
{

using namespace interconnect;

using namespace cclient::impl;

using namespace std;

string
ZookeeperInstance::getRootTabletLocation ()
{

    stringstream zRootLocation;

    zRootLocation << getRoot () << ZROOT_TABLET_LOCATION;

    uint8_t *rootLoc = myZooCache->getData (zRootLocation.str ());

    if (IsEmpty ((char*) rootLoc))
    {
        return NULL;
    }

    return split (string ((char*) rootLoc), '|').at (0);
}

string
ZookeeperInstance::getRoot ()
{
    stringstream st;
    st << ZROOT << "/" << instanceId;
    return st.str ();
}

vector<string>
ZookeeperInstance::getMasterLocations ()
{
    string masterLockPath = getRoot () + ZMASTER_LOCK;

    list<string> lockData = myZooCache->getChildren (masterLockPath);

    vector<string> masters;

    if (IsEmpty (&lockData))
    {
        return masters;
    }

    masters.insert (masters.begin (), lockData.begin (), lockData.end ());

    std::sort (masters.begin (), masters.end ());

    stringstream ss;
    ss << masterLockPath << "/" << masters.at (0);

    vector<string> firstMaster;

    string str = string ((const char*) myZooCache->getData (ss.str ()));
    firstMaster.push_back (str);

    return firstMaster;

}
//
string
ZookeeperInstance::getInstanceId ()
{
    if (IsEmpty (&instanceId))
    {

        stringstream instancePath;

        instancePath << ZROOT << ZINSTANCES << "/" << instanceName;

        uint8_t *zkInstanceId = myZooCache->getData (instancePath.str ());

        if (IsEmpty (zkInstanceId))
        {
            throw ClientException (
                "Instance Id does not exist within zookeeper");
        }

        instanceId.insert (0, (char*) zkInstanceId);

    }
    return instanceId;

}


vector<interconnect::ServerConnection> ZookeeperInstance::getServers()
{
   string tserverPath = getRoot () + TSERVERS;
   
   list<string> servers = myZooCache->getChildren (tserverPath);

    vector<interconnect::ServerConnection> tabletServers;

    if (IsEmpty (&servers))
    {
        return tabletServers;
    }

    for(auto server : servers)
    {
	stringstream ss;
	ss << tserverPath << "/" << server;
	string data = string ((const char*) myZooCache->getData (ss.str ()));
	
	vector<string> addresses = split(data,';');
	if (addresses.size() == 0 && IsEmpty(&data))
	{
	  addresses.push_back(server);
	}
	else
	if (addresses.size() == 0)
	{
	    addresses.push_back(data);
	}
	for(auto address : addresses)
	{
	  vector<string> addressSplit = split(address,'=');
	  string location = "";
	  if (addressSplit.size() != 2 )
	  {
	    if (addressSplit.size() == 0)
	      location = address;
	    else
	      location = addressSplit.at(0);
	  }
	  else
	  {
	    location = addressSplit.at(1);
	  }
	  
	  
	  vector<string> locationAndPort = split(location,':');
	  if (locationAndPort.size() != 2 )
	  {
	    throw cclient::exceptions::ClientException( INVALID_ZK_SERVER_DATA);
	  }
	  char *res = 0;
	  errno = 0;
	  int64_t port = strtol(locationAndPort.at(1).c_str(),&res,10);
	  if (((port == LONG_MIN || port == LONG_MAX ) && errno != 0 ) || *res !='\0') 
	  {
	      throw cclient::exceptions::ClientException( INVALID_ZK_SERVER_PORT);
	  }

	  interconnect::ServerConnection newConnection(locationAndPort.at(0),port,-1);
	  tabletServers.push_back(newConnection);
	}
    }

    return tabletServers;
    
}

string
ZookeeperInstance::getInstanceName ()
{
    return instanceName;
}

const Configuration *
ZookeeperInstance::getConfiguration ()
{
    return myConfiguration.get();
}

void
ZookeeperInstance::setConfiguration (std::unique_ptr<Configuration> conf)
{
    myConfiguration = std::move(conf);
}

}
}
}
