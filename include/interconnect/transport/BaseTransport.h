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
#ifndef BASE_TRANSPORT_H
#define BASE_TRANSPORT_H


#include <chrono>
#include <thread>
#include <map>
#include <set>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <protocol/TBinaryProtocol.h>
#include <protocol/TCompactProtocol.h>
#include <server/TSimpleServer.h>

#include <transport/TServerSocket.h>
#include <transport/TServerTransport.h>
#include <transport/TTransport.h>
#include <transport/TSocket.h>
#include <transport/TTransportException.h>
#include <transport/TBufferTransports.h>

#include <concurrency/ThreadManager.h>

#include <pthread.h>
#include <sys/time.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

#include "Transport.h"
#include <boost/concept_check.hpp>
#include <boost/shared_ptr.hpp>

#include "../../data/extern/thrift/ClientService.h"
#include "../../data/extern/thrift/TabletClientService.h"
#include "../scanrequest/ScanRequest.h"
#include "../scanrequest/ScanIdentifier.h"
#include "ServerTransport.h"
#include "../../data/extern/thrift/ThriftWrapper.h"
#include "../../data/constructs/security/AuthInfo.h"
#include "../Scan.h"

using namespace cclient::data;

using namespace cclient::exceptions;

namespace interconnect
{

class ThriftTransporter: virtual public ServerTransport<TTransport, KeyExtent*,
	Range*, Mutation*>
{
protected:

	boost::shared_ptr<TTransport> underlyingTransport;
	org::apache::accumulo::core::client::impl::thrift::ClientServiceClient *client;
	org::apache::accumulo::core::tabletserver::thrift::TabletClientServiceClient *tserverClient;

	ServerConnection *clonedConnection;

	virtual void newTransporter(ServerConnection *conn)
	{

		clonedConnection = new ServerConnection(conn);

		boost::shared_ptr<TSocket> serverTransport(
		        new TSocket(conn->getHost(), conn->getPort()));
		
		serverTransport->setLinger(false,0);
		serverTransport->setNoDelay(true);
		serverTransport->setConnTimeout(0);

		boost::shared_ptr<TTransport> transporty(
		        new TFramedTransport(serverTransport));

		try
		{
		  transporty->open();
		}
		catch( apache::thrift::transport::TTransportException te)
		{
		    try
		    {
		      transporty->close();
		    }
		    catch( apache::thrift::transport::TTransportException to )
		    {
		    }
		    throw te;
		}

		underlyingTransport = transporty;


	}

	boost::shared_ptr<TTransport> createTransporter()
	{
		
		boost::shared_ptr<TSocket> serverTransport(
		        new TSocket(clonedConnection->getHost(), clonedConnection->getPort()));
		
		serverTransport->setLinger(false,0);
		serverTransport->setNoDelay(true);
		serverTransport->setConnTimeout(0);

		boost::shared_ptr<TTransport> transporty(
		        new TFramedTransport(serverTransport));

		transporty->open();

		return transporty;


	}

	Scan *
	singleScan(ScanRequest<ScanIdentifier<KeyExtent*, Range*> > *request)
	{
		Scan *initialScan = new Scan();

		org::apache::accumulo::core::data::thrift::InitialScan scan;

		org::apache::accumulo::trace::thrift::TInfo scanId;

		scanId.parentId = 0;
		scanId.traceId = rand();

		vector<IterInfo*> *iters = request->getIterators();
		map<std::string, std::map<std::string, std::string> > iterOptions;
		for (auto it = iters->begin(); it != iters->end(); it++) {
			auto myOptions = (*it)->getOptions();
			for (auto optIt = myOptions.begin(); optIt != myOptions.end();
			     optIt++) {
				iterOptions[(*it)->getName()][(*optIt).first] = (*optIt).second;
			}
		}


		ScanIdentifier<KeyExtent*, Range*> *ident =
		        request->getRangeIdentifiers()->at(0);
		KeyExtent *extent = ident->getGlobalMapping().at(0);
		Range *range = ident->getIdentifiers(extent).at(0);
		tserverClient->startScan(scan, scanId,
		                         ThriftWrapper::convert(request->getCredentials()),
		                         ThriftWrapper::convert(extent), ThriftWrapper::convert(range),
		                         ThriftWrapper::convert(request->getColumns()), 1024,
		                         ThriftWrapper::convert(iters), iterOptions,
		                         request->getAuthorizations()->getAuthorizations(), true, false,
		                         1024);


		org::apache::accumulo::core::data::thrift::ScanResult results =
		        scan.result;

		vector<KeyValue*> *kvs = ThriftWrapper::convert(results.results);


		initialScan->setHasMore(results.more);

		
		initialScan->setScanId(scan.scanID);

		initialScan->setNextResults(kvs);

		if (!results.more) {
			tserverClient->closeScan(scanId, scan.scanID);
		}

		delete kvs;

		return initialScan;
	}

	Scan *
	multiScan(ScanRequest<ScanIdentifier<KeyExtent*, Range*> > *request)
	{
		Scan *initialScan = new Scan();

		org::apache::accumulo::core::data::thrift::InitialMultiScan scan;

		org::apache::accumulo::trace::thrift::TInfo scanId;

		scanId.traceId = scan.scanID;
		scanId.parentId = scan.scanID;

		vector<IterInfo*> *iters = request->getIterators();
		map<std::string, std::map<std::string, std::string> > iterOptions;
		for (auto it = iters->begin(); it != iters->end(); it++) {
			auto myOptions = (*it)->getOptions();
			for (auto optIt = myOptions.begin(); optIt != myOptions.end();
			     optIt++) {
				iterOptions[(*it)->getName()][(*optIt).first] = (*optIt).second;
			}
		}

		tserverClient->startMultiScan(scan, scanId,
		                              ThriftWrapper::convert(request->getCredentials()),
		                              ThriftWrapper::convert(request->getRangeIdentifiers()),
		                              ThriftWrapper::convert(request->getColumns()),
		                              ThriftWrapper::convert(iters), iterOptions,
		                              request->getAuthorizations()->getAuthorizations(), true);

		org::apache::accumulo::core::data::thrift::MultiScanResult results =
		        scan.result;

		vector<KeyValue*> *kvs = ThriftWrapper::convert(results.results);

		initialScan->setHasMore(results.more);

		initialScan->setNextResults(kvs);

		tserverClient->closeMultiScan(scanId, scan.scanID);

		delete kvs;

		return initialScan;
	}

public:

	ThriftTransporter(ServerConnection *conn) :
		interconnect::ServerTransport<TTransport, KeyExtent*, Range*,
		Mutation*>(conn), client(NULL), tserverClient(NULL)
	{

		newTransporter(conn);
	}

	virtual ~ThriftTransporter()
	{
		underlyingTransport->close();
		delete clonedConnection;
		if (NULL != tserverClient)
			delete tserverClient;
		if (NULL != client)
			delete client;
	}

	TTransport getTransport()
	{
		return *underlyingTransport;
	}

	void authenticate(AuthInfo *auth)
	{

		org::apache::accumulo::trace::thrift::TInfo tinfo;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert(auth);

		tinfo.parentId = 0;
		tinfo.traceId = rand();

		try{
		  if (!client->authenticateUser(tinfo, creds, creds)) {
			  throw ClientException("Invalid username");
		  }
		}catch(org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException tse)
		{
		  throw ClientException(INVALID_USERNAME_PASSWORD);
		}
	}
	
	void createIfClosed()
	{
	     if (underlyingTransport.get() != NULL && !underlyingTransport->isOpen())
	    {
	 
	      underlyingTransport = createTransporter();
	      createClientService();
	    }
	}
	
	
	void closeAndCreateClient()
	{
	     if (underlyingTransport.get() != NULL &&  underlyingTransport->isOpen())
	    {
	      underlyingTransport->close();
	    }

	    underlyingTransport = createTransporter();
	    createClientService();
	}
	
	void createClientService()
	{
	 
	    boost::shared_ptr<TProtocol> protocolPtr(
		        new TCompactProtocol(underlyingTransport));

		  if (NULL != client)
		{
		  delete client;
		  client = NULL;
		}
		if (NULL != tserverClient)
		{
		  delete tserverClient;
		  tserverClient = NULL;
		}
		client =
		        new org::apache::accumulo::core::client::impl::thrift::ClientServiceClient(
		        protocolPtr);
		tserverClient =
		        new org::apache::accumulo::core::tabletserver::thrift::TabletClientServiceClient(
		        protocolPtr);
	}
	

	virtual void registerService(std::string instance,
	                             std::string clusterManagers)
	{
		boost::shared_ptr<TProtocol> protocolPtr(
		        new TCompactProtocol(underlyingTransport));
			
		
		if (NULL != client)
		{
		  delete client;
		  client = NULL;
		}
		if (NULL != tserverClient)
		{
		  delete tserverClient;
		  tserverClient = NULL;
		}

		client =
		        new org::apache::accumulo::core::client::impl::thrift::ClientServiceClient(
		        protocolPtr);
		tserverClient =
		        new org::apache::accumulo::core::tabletserver::thrift::TabletClientServiceClient(
		        protocolPtr);


		client->getZooKeepers(clusterManagers);
		client->getInstanceId(instance);
	}

	Scan *
	beginScan(ScanRequest<ScanIdentifier<KeyExtent*, Range*> > *request)
	{
		Scan *initialScan = NULL;
		if (request->getRangeIdentifiers()->size() > 1) {
			initialScan = multiScan(request);
		} else {
			initialScan = singleScan(request);

		}
		return initialScan;
	}


	Scan *
	continueScan(Scan *originalScan)
	{
		org::apache::accumulo::core::data::thrift::ScanResult results;
		org::apache::accumulo::trace::thrift::TInfo tinfo;

		org::apache::accumulo::core::data::thrift::ScanID scanId = originalScan->getId();


		tinfo.traceId = originalScan->getId()+1;
		tinfo.parentId = originalScan->getId();
		tserverClient->continueScan(results,tinfo,scanId);

		vector<KeyValue*> *kvs = ThriftWrapper::convert(results.results);


		originalScan->setHasMore(results.more);

		originalScan->setNextResults(kvs);

		if (!results.more) {
			tinfo.traceId++;
			tserverClient->closeScan(tinfo, originalScan->getId());
		}

		delete kvs;


		return originalScan;
	}


	void *write(AuthInfo *auth, map<KeyExtent*, vector<Mutation*>> *request)
	{

		org::apache::accumulo::trace::thrift::TInfo tinfo;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert(auth);

		tinfo.parentId = 0;
		tinfo.traceId = rand();
		org::apache::accumulo::core::data::thrift::UpdateID upId =
		        tserverClient->startUpdate(tinfo, creds);
		for (map<KeyExtent*, vector<Mutation*>>::iterator it = request->begin();
		     it != request->end(); it++) {

			tserverClient->applyUpdates(tinfo, upId,
			                            ThriftWrapper::convert(it->first),
			                            ThriftWrapper::convert(&it->second));
		}
		tinfo.parentId=tinfo.traceId;
		tinfo.traceId=tinfo.traceId+1;
		org::apache::accumulo::core::data::thrift::UpdateErrors errors;
		tserverClient->closeUpdate(errors, tinfo, upId);
		//@TODO return errors
		return 0;
	}

	bool dropUser(AuthInfo *auth, string user )
	{
	     org::apache::accumulo::trace::thrift::TInfo tinfo;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert(auth);

		tinfo.parentId = 0;
		tinfo.traceId = rand();
		try
		{
		  client->dropLocalUser(tinfo,creds,user);
		  return true;
		}
		catch(org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException tse)
		{
		  // could not create the user for some reason
		  return false;
		  
		}
	}
	
	bool changeUserPassword(AuthInfo *auth, string user, string password )
	{
	     org::apache::accumulo::trace::thrift::TInfo tinfo;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert(auth);

		tinfo.parentId = 0;
		tinfo.traceId = rand();
		
		try
		{
		  client->changeLocalUserPassword(tinfo,creds,user,password);
		  return true;
		}
		catch(org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException tse)
		{
		  // could not create the user for some reason
		  return false;
		  
		}
	}
	bool createUser(AuthInfo *auth, string user, string password)
	{
	    org::apache::accumulo::trace::thrift::TInfo tinfo;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert(auth);

		tinfo.parentId = 0;
		tinfo.traceId = rand();
		try
		{
		  client->createLocalUser(tinfo,creds,user,password);
		  return true;
		}
		catch(org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException tse)
		{
		  // could not create the user for some reason
		  return false;
		  
		}
		
	}
	
	map<string,string> getTableConfiguration(AuthInfo *auth, string table)
	{
	  org::apache::accumulo::trace::thrift::TInfo tinfo;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert(auth);

		tinfo.parentId = 0;
		tinfo.traceId = rand();
		map<string,string> ret;
		client->getTableConfiguration(ret,tinfo,creds,table);
	  
	  return ret;
	}
	
	void changeUserAuths(AuthInfo *auth, string user, Authorizations *auths)
	{
	  org::apache::accumulo::trace::thrift::TInfo tinfo;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert(auth);

		tinfo.parentId = 0;
		tinfo.traceId = rand();
		  client->changeAuthorizations(tinfo,creds,user,auths->getAuthorizations());
	}
	
	
	void splitTablet(AuthInfo *auth, KeyExtent *extent, string split)
	{
	   org::apache::accumulo::trace::thrift::TInfo tinfo;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert(auth);

		org::apache::accumulo::core::data::thrift::TKeyExtent ke = ThriftWrapper::convert(extent);
		tinfo.parentId = 0;
		tinfo.traceId = rand();
		tserverClient->splitTablet(tinfo,creds,ke,split);
	}
	void close()
	{
	  if (NULL != client)
	  {
	    delete client;
	    client = NULL;
	  }
	  if (NULL != tserverClient)
	  {
	    delete tserverClient;
	    tserverClient = NULL;
	  }
	  underlyingTransport->close();
	}

	void close(Scan *scan)
	{
	  
	}

	bool open()
	{
	  return underlyingTransport->isOpen();
	}

	bool isOpen()
	{
	  return underlyingTransport->isOpen();
	}

};
}
#endif
