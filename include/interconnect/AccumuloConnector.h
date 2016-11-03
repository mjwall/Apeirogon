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
