/*
 * Copyright (c) 2016 <copyright holder> <email>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef TABLETSERVER_H_
#define TABLETSERVER_H_ 1

#ifndef SIGNED_RIGHT_SHIFT_IS
#define SIGNED_RIGHT_SHIFT_IS 5
#endif

#ifndef ARITHMETIC_RIGHT_SHIFT
#define ARITHMETIC_RIGHT_SHIFT 5
#endif

#include <chrono>
#include <thread>
#include <string>
#include "InterConnect.h"
#include "DistributedConnector.h"
#include "../data/constructs/inputvalidation.h"
#include "../data/constructs/IterInfo.h"
#include "../data/constructs/configuration/Configuration.h"
#include "../data/extern/thrift/data_types.h"
#include "../data/constructs/scanstate.h"
#include "../data/exceptions/ClientException.h"
#include "../data/exceptions/IllegalArgumentException.h"
#include "../data/constructs/tablet/TabletType.h"
#include "../data/constructs/client/TabletServerMutations.h"
#include "../interconnect/ClientInterface.h"

#include <boost/shared_ptr.hpp>
#include "transport/ServerTransport.h"
#include "transport/BaseTransport.h"
#include "DistributedConnector.h"
#include "AccumuloConnector.h"
#include "../data/constructs/server/RangeDefinition.h"
#include "../data/constructs/server/ServerDefinition.h"
#include "../data/extern/thrift/ClientService.h"
#include "../data/extern/thrift/TabletClientService.h"

using namespace std;

namespace interconnect
{

using namespace cclient::exceptions;
using namespace cclient::data;
using namespace org::apache::accumulo::core::data::thrift;
using namespace cclient::data::tserver;
using namespace cclient::impl;

static DistributedConnector<ThriftTransporter> CLUSTER_COORDINATOR;

extern void closeAllThriftConnections();

class ServerInterconnect : public AccumuloConnector<
	interconnect::ThriftTransporter>
{

protected:
	ServerInterconnect (
	        AuthInfo *creds,
	        DistributedConnector<ThriftTransporter> *distributedConnector =
	                &CLUSTER_COORDINATOR)
	{
		myDistributedConnector = distributedConnector;
		this->credentials = creds;
		myTransport = NULL;
	}
	CachedTransport< ThriftTransporter > *myTransport;
	
	void recreateConnection(bool errorOcurred = false)
	{
	    do{
		  myTransport->sawError(errorOcurred);   
		  try
		  {
		    myDistributedConnector->freeTransport(myTransport);
		  }catch(apache::thrift::transport::TTransportException te)
		  {
		    cout << te.what() << endl;
		      // close may occur on a partial write this is okay
		      // to know
		  }
		    
		
//		 myTransport->getTransporter()->createIfClosed();

		  try
		  {
		    myTransport = myDistributedConnector->getTransporter (tServer);
		    setTransport (myTransport->getTransporter());
		    break;
		    
		  }catch(TProtocolException tpe)
		  {
		    cout << tpe.what() << endl;
		    myTransport->sawError(true);   
		    myDistributedConnector->freeTransport(myTransport);
		    std::this_thread::sleep_for (std::chrono::milliseconds (50));
		    continue;
		  }
		  catch(TTransportException tpe)
		  {
		    cout << tpe.what() << endl;
		    myTransport->sawError(true);   
		    myDistributedConnector->freeTransport(myTransport);
		    std::this_thread::sleep_for (std::chrono::milliseconds (50));
		    continue;
		  }
		 
		 break;
		}while(true);
	}

public:

	ServerInterconnect (
	        const string host, const int port, const Configuration *conf,
	        DistributedConnector<ThriftTransporter> *distributedConnector =
	                &CLUSTER_COORDINATOR);

	ServerInterconnect (
	        RangeDefinition *rangeDef,const Configuration *conf,
	        DistributedConnector<ThriftTransporter> *distributedConnector =
	                &CLUSTER_COORDINATOR)
	{
		ConnectorService conn ("tserver", rangeDef->getServer (),
		                       rangeDef->getPort ());

		const uint16_t tserverPort = (uint16_t) conf->getLong (TSERVER_PORT_OPT,
		                             TSERVER_DEFAULT_PORT);

		if (!isValidPort (tserverPort)) {
			throw IllegalArgumentException ("Invalid port");
		}

		const uint32_t timeout = conf->getLong (GENERAL_RPC_TIMEOUT_OPT,
		                                        GENERAL_RPC_TIMEOUT);

		tServer = new ServerConnection (
		        conn.getAddressString (
		                interconnect::INTERCONNECT_TYPES::TSERV_CLIENT),
		        rangeDef->getPort (), timeout);
		
		
		do{
		  
		    try
		    {
			myTransport = distributedConnector->getTransporter (tServer);
		      }catch(apache::thrift::transport::TTransportException te)
		      {
			//myTransport->sawError(true);
			//distributedConnector->freeTransport(myTransport);
			std::this_thread::sleep_for (std::chrono::milliseconds (100));
			  // close may occur on a partial write this is okay
			  // to know
			continue;
		      }
		      
		
//		 myTransport->getTransporter()->createIfClosed();

		  try
		  {
	    
		    setTransport (myTransport->getTransporter());		    
		    break;

		  }catch(TProtocolException tpe)
		  {
		    myTransport->sawError(true);   
		    distributedConnector->freeTransport(myTransport);
		    continue;
		  }
		  catch(TTransportException tpe)
		  {
		    myTransport->sawError(true);   
		    distributedConnector->freeTransport(myTransport);
		    continue;
		  }
		 
		 break;
		}while(true);
		
		
		myDistributedConnector = distributedConnector;
		
		authenticate (rangeDef->getCredentials ());
		
		vector<cclient::data::IterInfo*> list;

		map<string, map<string, string>> map;

		this->rangeDef = rangeDef;

		//	limitedRanges.insert(limitedRanges.end(), ranges->begin(),
//				ranges->end());

		
	}

	Scan *
	scan (vector<Column*> *cols,
	      vector<cclient::data::IterInfo*> *serverSideIterators)
	{
		ScanRequest<ScanIdentifier<KeyExtent*, Range*>> request (
		                        credentials, rangeDef->getAuthorizations (), tServer);

		request.addColumns (cols);

		request.setIters (serverSideIterators);

		for (KeyExtent *extent : *rangeDef->getExtents ()) {
			ScanIdentifier<KeyExtent*, Range*> *ident = new ScanIdentifier<
			KeyExtent*, Range*> ();
			if (rangeDef->getRanges ()->size () == 0) {
				return NULL;
			}
			for (Range *range : *rangeDef->getRanges ()) {
				ident->putIdentifier (extent, range);
			}

			request.putIdentifier (ident);
		}

		return transport->beginScan (&request);

	}

	ServerInterconnect (
	        ServerDefinition *rangeDef, const Configuration *conf,
	        DistributedConnector<ThriftTransporter> *distributedConnector =
	                &CLUSTER_COORDINATOR)
	{
		ConnectorService conn ("tserver", rangeDef->getServer (),
		                       rangeDef->getPort ());

		const uint16_t tserverPort = (uint16_t) conf->getLong (TSERVER_PORT_OPT,
		                             TSERVER_DEFAULT_PORT);

		if (!isValidPort (tserverPort)) {
			throw IllegalArgumentException ("Invalid port");
		}

		const uint32_t timeout = conf->getLong (GENERAL_RPC_TIMEOUT_OPT,
		                                        GENERAL_RPC_TIMEOUT);

		tServer = new ServerConnection (
		        conn.getAddressString (
		                interconnect::INTERCONNECT_TYPES::TSERV_CLIENT),
		        rangeDef->getPort (), timeout);
		do{
		  
		    try
		    {
			myTransport = distributedConnector->getTransporter (tServer);
		      }catch(apache::thrift::transport::TTransportException te)
		      {
			myTransport->sawError(true);
			distributedConnector->freeTransport(myTransport);
			std::this_thread::sleep_for (std::chrono::milliseconds (100));
			  // close may occur on a partial write this is okay
			  // to know
			continue;
		      }
		      
		
//		 myTransport->getTransporter()->createIfClosed();

		  try
		  {
	    
		    setTransport (myTransport->getTransporter());
		    break;

		  }catch(TProtocolException tpe)
		  {
		    myTransport->sawError(true);   
		    distributedConnector->freeTransport(myTransport);
		    continue;
		  }
		  /*catch(apache::thrift::TApplicationException)
		  {
		    myTransport->sawError(true);   
		    distributedConnector->freeTransport(myTransport);
		    continue;
		  }*/
		  catch(TTransportException tpe)
		  {
		    myTransport->sawError(true);   
		    distributedConnector->freeTransport(myTransport);
		    continue;
		  }
		 
		 break;
		}while(true);
		
		myDistributedConnector = distributedConnector;
				
		authenticate (rangeDef->getCredentials ());		    

		vector<cclient::data::IterInfo*> list;
	}

	Scan *
	scan ()
	{

		vector<Column*> emptyCols;

		vector<cclient::data::IterInfo*> emptyServerSideIterators;

		return scan (&emptyCols, &emptyServerSideIterators);

	}

	Scan *continueScan(Scan *scan)
	{
		if (scan->getHasMore()) {
			return transport->continueScan(scan);
		}
		return NULL;
	}

	TabletServerMutations *
	write (TabletServerMutations *mutations)
	{

	  bool success = false;
	  do
	  {
		try{
		  transport->write (credentials, mutations->getMutations ());
		  success = true;
		}catch(apache::thrift::transport::TTransportException te)
		{
		  recreateConnection(true);
		}
		/*
		catch(apache::thrift::TApplicationException ta)
		{
		   recreateConnection(true);
		}*/
		catch(apache::thrift::protocol::TProtocolException tp)
		{
		   recreateConnection(true);
		}
		
	  }while(!success);
	  // need to return those that could not be written or those that failed.   
	  return NULL;
	}

	void
	authenticate (AuthInfo *credentials);

	void
	authenticate (string username, string password)
	{
	}

	virtual
	~ServerInterconnect ();

};

}
#endif /* TABLETSERVER_H_ */

