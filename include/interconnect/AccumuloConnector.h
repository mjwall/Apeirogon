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

#ifndef SRC_INTERCONNECT_ACCUMULOCONNECTOR_H_
#define SRC_INTERCONNECT_ACCUMULOCONNECTOR_H_

#include "../data/constructs/inputvalidation.h"
#include "../data/constructs/IterInfo.h"
#include "../data/constructs/configuration/Configuration.h"
#include "../data/extern/thrift/data_types.h"
#include "../data/constructs/scanstate.h"
#include "../data/exceptions/ClientException.h"
#include "../data/exceptions/IllegalArgumentException.h"
#include "../data/constructs/tablet/TabletType.h"
#include "../interconnect/ClientInterface.h"

#include "../data/constructs/server/RangeDefinition.h"
#include "DistributedConnector.h"
#include "../data/constructs/server/ServerDefinition.h"

using namespace cclient::exceptions;
using namespace cclient::data;
using namespace org::apache::accumulo::core::data::thrift;
using namespace cclient::data::tserver;
using namespace cclient::impl;

namespace interconnect {

  /**
 * Default Accumulo Connector
 * Purpose: acts as the the most basic interface supplying connecting objects
 * Design: Extends the most basic thrift interface, ClientInterface for
 * thrift rpc calls
 */
template<typename Tr>
class AccumuloConnector: virtual public ClientInterface<Tr> {
public:
    AccumuloConnector() :
        ClientInterface<Tr>(), myDistributedConnector(NULL), credentials(
            NULL), rangeDef(NULL), tServer(NULL), serverDef(NULL) {

    }
    AccumuloConnector(const string host, const int port) :
        ClientInterface<Tr>(host, port), myDistributedConnector(NULL), credentials(
            NULL), rangeDef(NULL), tServer(NULL), serverDef(NULL) {

    }
    virtual ~AccumuloConnector() {

    }


    
    AuthInfo *getCredentials() {
        return credentials;
    }
protected:
    DistributedConnector<Tr> *myDistributedConnector;
    AuthInfo *credentials;
    RangeDefinition *rangeDef;
    ServerConnection *tServer;
    ServerDefinition *serverDef;
};

} /* namespace interconnect */

#endif /* SRC_INTERCONNECT_ACCUMULOCONNECTOR_H_ */
