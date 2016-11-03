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

#ifndef MASTER_H_
#define MASTER_H_

//#define SIGNED_RIGHT_SHIFT_IS 5
//#define ARITHMETIC_RIGHT_SHIFT 5

#include "../data/constructs/client/Instance.h"
#include <protocol/TBinaryProtocol.h>
#include <protocol/TCompactProtocol.h>
#include <server/TSimpleServer.h>

#include <transport/TServerSocket.h>
#include <transport/TServerTransport.h>
#include <transport/TTransport.h>
#include <transport/TSocket.h>
#include <server/TNonblockingServer.h>
#include <transport/TBufferTransports.h>
#include <concurrency/ThreadManager.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

#include "TabletServer.h"

#include <string>
#include <vector>
#include <memory>
#include "ClientInterface.h"
using namespace std;

#include <boost/shared_ptr.hpp>
using boost::shared_ptr;

#include "tableOps/ClientTableOps.h"
#include "namespaceOps/NamespaceOperations.h"
#include "securityOps/SecurityOperations.h"
#include "../data/constructs/inputvalidation.h"
#include "transport/AccumuloMasterTransporter.h"

namespace interconnect
{
using namespace cclient::data;

static DistributedConnector<interconnect::AccumuloMasterTransporter> MASTER_COORDINATOR;
/**
 * Purpose: Accumulo master connector.
 *
 * Design: Extends root interface provuding a master transport, which
 * is based on the thrift connector
 *
 */
class MasterConnect : public RootInterface<
    interconnect::AccumuloMasterTransporter, KeyValue*, ResultBlock<KeyValue*>>
{
public:
    /**
     * Constructor
     * @param credentials incoming user credentials
     * @param instance incoming instance
     */
    MasterConnect (AuthInfo *credentials, Instance *instance);

    /**
     * Returns an instance of table operations
     * @param table incoming table
     * @returns instance of table ops for this type of interface
     */
    std::unique_ptr<AccumuloTableOperations>
            tableOps (string table);
	   
    std::unique_ptr<NamespaceOperations> namespaceOps(string nm = "");
  
    std::unique_ptr<SecurityOperations> securityOps();

    virtual
    ~MasterConnect ();

protected:
  
    void findTservers();

    Instance *instance;
    
    vector<ServerConnection> tabletServers;
    
    CachedTransport<interconnect::AccumuloMasterTransporter> *cachedTransport;

    friend class AccumuloTableOperations;
    
    friend class SecurityOperations;

};
}
#endif /* MASTER_H_ */
