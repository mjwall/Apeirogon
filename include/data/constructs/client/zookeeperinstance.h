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

#ifndef ZOOKEEPERINSTANCE_H
#define ZOOKEEPERINSTANCE_H

#include <memory>
#include "Instance.h"
#include <sstream>
#include <iostream>
#include <string>
#include "./zookeeper/zookeepers.h"
#include "./zookeeper/zoocache.h"
#include "../inputvalidation.h"
#include "../../exceptions/ClientException.h"
#include "../configuration/Configuration.h"
#include "../../../interconnect/Master.h"

using namespace std;
namespace cclient
{
namespace data
{
namespace zookeeper
{


/**
 * Instance that uses zookeeper
 * 
 * Purpose: provides connecting capabilities through zookeeper
 * 
 * Design: Simply inherits Instance, which is a purely virtual class.
 **/
class ZookeeperInstance: public Instance
{
public:
  
	/**
	  * ZK constructor
	  * @param in instance name
	  * @param zks zookeepers
	  * @param zkTimeoutMs timeout for zookeeper
	  * @param conf configuration object
	  **/
	ZookeeperInstance(string in, string zks, uint32_t zkTimeoutMs,
	                  std::unique_ptr<Configuration> conf) :
		instanceName(in), zookeeperList(zks), timeoutMs(zkTimeoutMs), myConfiguration(
		        std::move(conf))
	{
		if (IsEmpty(&in) || IsEmpty(&zks)) {
			throw ClientException("instance name or zookeeper list is empty");
		}

		myKeeper = new ZooKeeper(zks.c_str(), zkTimeoutMs);

		myKeeper->init(&myWatch);

		myZooCache = new ZooCache(myKeeper);

		getInstanceId();

	}
	
	/**
	  * ZK constructor
	  * @param in instance name
	  * @param zks zookeepers
	  * @param zkTimeoutMs timeout for zookeeper
	  **/
	ZookeeperInstance(string in, string zks, uint32_t zkTimeoutMs) :
		instanceName(in), zookeeperList(zks), timeoutMs(zkTimeoutMs), myConfiguration(
		        new Configuration())
	{
		myConfiguration->set ("FILE_SYSTEM_ROOT", "/accumulo");
		
		if (IsEmpty(&in) || IsEmpty(&zks)) {
			throw ClientException("instance name or zookeeper list is empty");
		}

		myKeeper = new ZooKeeper(zks.c_str(), zkTimeoutMs);

		myKeeper->init(&myWatch);

		myZooCache = new ZooCache(myKeeper);

		getInstanceId();

	}

	/**
	 * ZK Destructor
	 **/
	~ZookeeperInstance()
	{
		if (NULL != myZooCache)
		  delete myZooCache;
		if (NULL != myKeeper)
		  delete myKeeper;

	}

	/**
	  * Returns the controller
	  * @return root location
	  **/
	string getRootTabletLocation();

	/**
	  * Returns the controller
	  * @return root location
	  **/
	vector<string> getMasterLocations();

	/**
	  * return instance ID
	  * @return instance ID
	  **/
	string getInstanceId();
	/**
	  * Return instance namespace
	  * @return instance name
	  **/
	string getInstanceName();
	/**
	  * Returns configuration
	  * @return configuration reference
	  **/
	const Configuration *getConfiguration();
	/**
	  * Sets configuration object
	  * @param configuration object
	  **/
	void setConfiguration( std::unique_ptr<Configuration> conf);

	/**
	  * Returns a reference to zoocache
	  * @return zoo cache ptr
	  **/
	ZooCache *getZooCache()
	{
		return myZooCache;
	}

	/**
	  * Return link to instance instance cache
	  * @return instance cache
	  **/
	InstanceCache *getInstanceCache()
	{
		return myZooCache;
	}
	
	/**
	  * Returns a list of server that will do work
	  * @return a vector of serverconnections
	  **/
	virtual vector<interconnect::ServerConnection> getServers();
	
	/**
	 * Gets the root node
	 * @return root node.
	 **/
	string getRoot();

protected:
	// zoo cache ptr
	ZooCache *myZooCache;

	// zookeeper reference.
	ZooKeeper *myKeeper;

	// watch for the current zk
	Watch myWatch;

	// configuration object
	std::unique_ptr<Configuration> myConfiguration;
	
	// instance id
	string instanceId;
	// instance name
	string instanceName;
	// zk list
	string zookeeperList;

	// time out in ms
	uint32_t timeoutMs;

};



}
}
}

#endif // ZOOKEEPERINSTANCE_H
