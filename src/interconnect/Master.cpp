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
#include "../../include/interconnect/Master.h"
#include "../../include/interconnect/../data/constructs/security/AuthInfo.h"
#include "../../include/interconnect/../scanner/constructs/Results.h"
#include <string>

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

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

#include "../../include/interconnect/../data/constructs/Mutation.h"
#include "../../include/interconnect/TabletServer.h"
#include "../../include/interconnect/../data/exceptions/ClientException.h"

using namespace std;
namespace interconnect
{

using namespace cclient::exceptions;
using namespace cclient::data::security;
using namespace scanners;

/**
 * Constructor
 * @param credentials incoming user credentials
 * @param instance incoming instance
 */
MasterConnect::MasterConnect (AuthInfo *credentials, Instance *instance) :
    RootInterface<interconnect::AccumuloMasterTransporter, KeyValue*,
    ResultBlock<KeyValue*>> (credentials, instance), instance (instance)
{

    this->myDistributedConnector = &MASTER_COORDINATOR;
    this->credentials = credentials;

    vector<string> locations = instance->getMasterLocations ();
    
    if (locations.size() == 0)
    {
	throw ClientException(NO_MASTER_FOUND);
    }

    string master = locations.at (0);

    vector<string> masterSplit = split (master, ':');

    uint16_t port = atoi (masterSplit.at (1).c_str ());
    ConnectorService conn ("master", masterSplit.at (0), port);

    // create time out from system configuration
    uint64_t timeout = instance->getConfiguration ()->getLong ("MASTER_TIMEOUT",
                       60000);

    // even though we're within the accumulo master, tserver object is just
    // a reference to the connecting server
    tServer = new ServerConnection (
        conn.getAddressString (interconnect::INTERCONNECT_TYPES::MASTER_CLIENT),
        port, timeout);
    
    cachedTransport = myDistributedConnector->getTransporter (tServer);


    setTransport (cachedTransport->getTransporter());
    
    findTservers();
    
    CachedTransport<interconnect::AccumuloMasterTransporter> *tserverConnection =
        myDistributedConnector->getTransporter(&tabletServers,true).second;

    // let's authenticate the user early
    tserverConnection->getTransport()->authenticate(credentials);
	
	
    myDistributedConnector->freeTransport(tserverConnection);

}

void MasterConnect::findTservers()
{
  tabletServers = instance->getServers();
}
/**
 * Returns an instance of table operations
 * @param table incoming table
 * @returns instance of table ops for this type of interface
 */
std::unique_ptr<AccumuloTableOperations>
        MasterConnect::tableOps (string table)
{
  CachedTransport<interconnect::AccumuloMasterTransporter> *tserverConnection =
        myDistributedConnector->getTransporter(&tabletServers,true).second;
    return std::unique_ptr<AccumuloTableOperations>(new AccumuloTableOperations (
               AccumuloConnector<interconnect::AccumuloMasterTransporter>::getCredentials (),
               instance, table, this,tserverConnection,myDistributedConnector));
}

/**
 * Creates Namespace operations
 * @param nm namespace to create. optional argument.
 * @returns Namespace Operations.
 */
std::unique_ptr<NamespaceOperations> MasterConnect::namespaceOps(string nm)
{
  return std::unique_ptr<NamespaceOperations>(new NamespaceOperations(AccumuloConnector<interconnect::AccumuloMasterTransporter>::getCredentials (),nm,
               instance,  this, myDistributedConnector));
}

/**
 * Create Security Operations
 * @returns new Security operations argument.
 */
std::unique_ptr<SecurityOperations> MasterConnect::securityOps()
{
  
  CachedTransport<interconnect::AccumuloMasterTransporter> *ptr =
        myDistributedConnector->getTransporter(&tabletServers,true).second;
  return std::unique_ptr<SecurityOperations>(new SecurityOperations(AccumuloConnector<interconnect::AccumuloMasterTransporter>::getCredentials (),
               instance,  ptr, myDistributedConnector));
}

/**
 * Master connect destructor.
 */
MasterConnect::~MasterConnect ()
{
  myDistributedConnector->closeAll();
}
}
