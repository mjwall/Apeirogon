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

#include <memory>
#include <string>
using namespace std;

#include <sys/socket.h>
#include <arpa/inet.h>

#include "../../include/interconnect/TabletServer.h"

using namespace interconnect;

ServerInterconnect::ServerInterconnect (
    const string host, const int port, const Configuration *conf,
    DistributedConnector<ThriftTransporter> *distributedConnector) :
    AccumuloConnector<interconnect::ThriftTransporter> (host, port)
{

    ConnectorService conn ("tserver", host, port);

    const uint16_t tserverPort = (uint16_t) conf->getLong (TSERVER_PORT_OPT,
                                 TSERVER_DEFAULT_PORT);

    cout << tserverPort << endl;
    if (!isValidPort (tserverPort))
    {
        throw IllegalArgumentException ("Invalid port");
    }

    const uint32_t timeout = conf->getLong (GENERAL_RPC_TIMEOUT_OPT,
                                            GENERAL_RPC_TIMEOUT);

    tServer = new ServerConnection (
        conn.getAddressString (interconnect::INTERCONNECT_TYPES::TSERV_CLIENT),
        rangeDef->getPort (), timeout);

    myTransport = distributedConnector->getTransporter (tServer);
    setTransport (myTransport->getTransporter());

    authenticate (rangeDef->getCredentials ());

    vector<cclient::data::IterInfo*> list;

    map<string, map<string, string>> map;

}

ServerInterconnect::~ServerInterconnect ()
{
    myDistributedConnector->freeTransport(myTransport);
    delete tServer;
    delete rangeDef;

}

void
ServerInterconnect::authenticate (AuthInfo *credentials)
{
    bool success = false;
    do
      {
	    try{
		transport->authenticate (credentials);
	      this->credentials = credentials;
	      string username = credentials->getUserName ();
	      string password = credentials->getPassword ();

	      setCredentials (username, password);
	      setAuthenticated (true);
	      success = true;
	    }catch(apache::thrift::TApplicationException ta)
	    {
	      recreateConnection(true);
	    }catch(apache::thrift::transport::TTransportException te)
	    {
	      recreateConnection(true);
	    }
	    catch(apache::thrift::protocol::TProtocolException tp)
	    {
		recreateConnection(true);
	    }
	    
      }while(!success);
	  // need to return those that could not be written or those that failed. 
  

}

