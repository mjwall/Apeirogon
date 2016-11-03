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
#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <memory>
#include <string>
#include <list>
#include <vector>
using namespace std;


#include "../security/AuthInfo.h"
#include "InstanceCache.h"
#include "../configuration/Configuration.h"
#include "../include/interconnect/transport/ServerConnection.h"

#include <string>
#include <list>
using namespace std;

namespace cclient {
namespace data {

using namespace cclient::impl;
using namespace cclient::data::security;


/**
 * Instance represents a connecting object for the key value store
 * Nearly all key value stores follow a root/worker paradigm.
 * This class is meant to facilitate that paradigm.
 * 
 **/
class Instance {
public:
    Instance() {

    }
    /**
     * Returns the controller
     * @return root location
     **/
    virtual string getRootTabletLocation() = 0;
    /**
     * Returns the controller
     * @return root location
     **/
    virtual vector<string> getMasterLocations() = 0;
    /**
     * Returns a list of server that will do work
     * @return a vector of serverconnections
     **/
    virtual vector<interconnect::ServerConnection> getServers() = 0;
    /**
      * return instance ID
      * @return instance ID
      **/
    virtual string getInstanceId() = 0;
    /**
     * Return instance namespace
     * @return instance name
     **/
    virtual string getInstanceName() = 0;
    /**
      * Return link to instance instance cache
      * @return instance cache
      **/
    virtual InstanceCache *getInstanceCache() =0;
    /**
     * Returns configuration
     * @return configuration reference
     **/
    virtual const Configuration *getConfiguration() = 0;
    /**
     * Sets configuration object
     * @param configuration object
     **/
    virtual void setConfiguration(std::unique_ptr<Configuration> conf) = 0;
    /**
     * Destructor
     **/
    virtual ~Instance() {

    }
};

} /* namespace impl */
} /* namespace cclient */
#endif /* INSTANCE_H_ */

