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
#ifndef SRC_INTERCONNECT_TRANSPORT_ACCUMULOMASTERTRANSPOTER_H_
#define SRC_INTERCONNECT_TRANSPORT_ACCUMULOMASTERTRANSPOTER_H_


#include <concurrency/ThreadManager.h>

#include <chrono>
#include <thread>
#include <pthread.h>
#include <sys/time.h>

#include <map>
#include <set>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand


using namespace std;


#include "../../data/constructs/inputvalidation.h"
#include "../../data/constructs/IterInfo.h"
#include "../../data/constructs/configuration/Configuration.h"
#include "../../data/extern/thrift/data_types.h"
#include "../../data/extern/thrift/tabletserver_types.h"
#include "../../data/constructs/scanstate.h"
#include "../../data/exceptions/ClientException.h"
#include "../../data/exceptions/IllegalArgumentException.h"
#include "../../data/constructs/tablet/TabletType.h"
#include "../scanrequest/ScanIdentifier.h"

#include "Transport.h"
#include <boost/concept_check.hpp>
#include <boost/shared_ptr.hpp>

#include "../../data/extern/thrift/ClientService.h"
#include "../../data/extern/thrift/master_types.h"
#include "../../data/extern/thrift/MasterClientService.h"
#include "../../data/extern/thrift/ThriftWrapper.h"
#include "../../data/constructs/security/AuthInfo.h"
#include "../Scan.h"

using namespace cclient::data;

using namespace cclient::exceptions;

#include "BaseTransport.h"
#include "FateInterface.h"
namespace interconnect
{
//#include <protocol/TBinaryProtocol.h>
#include <protocol/TCompactProtocol.h>
#include <server/TSimpleServer.h>

#include <transport/TServerSocket.h>
#include <transport/TServerTransport.h>
#include <transport/TTransport.h>
#include <transport/TSocket.h>
#include <transport/TTransportException.h>
#include <transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

/**
 * Represents the interconnect to the master client
 * Purpose: Provides the API connection capabilities to the master client
 * Design: Isa ThriftTransporter and FateInterface, therefore it allows for fate operations
 **/
class AccumuloMasterTransporter : public ThriftTransporter, public FateInterface
{
protected:
  
	// thrift master client interface.
	org::apache::accumulo::core::master::thrift::MasterClientServiceClient *masterClient;


	/**
	 * creates a new transporter
	 * @return new transporter
	 **/
	virtual boost::shared_ptr<TTransport> recreateTransport()
	{
	  return createTransporter();
	}
	
	/**
	 * Provides a pointer to the master client. Does not provide ownership
	 * @return master client interface.
	 **/
	org::apache::accumulo::core::master::thrift::MasterClientServiceClient *getMasterClient()
	{
	  return masterClient;
	}

	/**
	 * Creates a new master client for this instance.
	 * 
	 **/
	void createMasterClient()
	{
		boost::shared_ptr<TProtocol> protocolPtr (
		        new TCompactProtocol (underlyingTransport));
		if (NULL != masterClient)
		{
		
		  delete masterClient;
		  masterClient = NULL;
		}
		masterClient =
		        new org::apache::accumulo::core::master::thrift::MasterClientServiceClient (
		        protocolPtr);
	}

	void recreateMasterClient()
	{
		underlyingTransport->close();
		underlyingTransport.reset();
		if (NULL != masterClient)
		{
		
		  delete masterClient;
		  masterClient = NULL;
		}
		underlyingTransport = createTransporter();
		createMasterClient();
		createClientService();
	}

public:

	virtual void
	registerService (std::string instance, std::string clusterManagers)
	{
		createMasterClient();
		createClientService();

	}



	AccumuloMasterTransporter (ServerConnection *conn) :
		interconnect::ThriftTransporter (conn), interconnect::ServerTransport<
		TTransport, KeyExtent*, Range*, Mutation*> (conn)
	{
		masterClient = NULL;
		createMasterClient();
		createClientService();
	}


	
	bool
	createTable (AuthInfo *auth, string table)
	{

		vector<string> tableArgs;
		tableArgs.push_back (table);
		tableArgs.push_back ("MILLIS");
		map<string, string> options;
		try {
			string returnValue =
			        doFateOperations (
			                auth,
			                org::apache::accumulo::core::master::thrift::FateOperation::TABLE_CREATE,
			                tableArgs, options,true);
		} catch (org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &e) {
			switch (e.type) {
			case org::apache::accumulo::core::client::impl::thrift::TableOperationExceptionType::EXISTS:
			default:
				return false;
			}
		}

		return true;

	}

	bool
	importDirectory (AuthInfo *auth, string table, string dir,
	                 string failure_dir, bool setTime)
	{

		vector<string> tableArgs;

		tableArgs.push_back (table);
		tableArgs.push_back (dir);
		tableArgs.push_back (failure_dir);
		if (__builtin_expect (setTime, false))
			tableArgs.push_back ("false");
		else
			tableArgs.push_back ("true");

		map<string, string> options;
		try {
			string returnValue =
			        doFateOperations (
			                auth,
			                org::apache::accumulo::core::master::thrift::FateOperation::TABLE_BULK_IMPORT,
			                tableArgs, options,false);
		} catch (org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &e) {
			switch (e.type) {
			case org::apache::accumulo::core::client::impl::thrift::TableOperationExceptionType::EXISTS:
				cout << "Table already exist" << endl;
			default:
				cout << e.description << " " << e.tableName << endl;
				return false;
			}
		} catch (apache::thrift::TApplicationException &e) {
			cout << e.what () << " " << e.getType () << endl;
		}

		return true;

	}

	bool compact(AuthInfo *auth, string table, string startrow, string endrow, bool wait)
	{
		vector<string> tableArgs;
		tableArgs.push_back (table);
		tableArgs.push_back (startrow);
		tableArgs.push_back (endrow);
		boost::shared_ptr<TMemoryBuffer> strBuffer(new TMemoryBuffer());
		boost::shared_ptr<TBinaryProtocol> binaryProtcol(new TBinaryProtocol(strBuffer));
		org::apache::accumulo::core::tabletserver::thrift::IteratorConfig config;
		config.write(binaryProtcol.get());

		string buff = strBuffer->getBufferAsString();
		tableArgs.push_back(buff);



		map<string, string> options;
		try {
			string returnValue =
			        doFateOperations (
			                auth,
			                org::apache::accumulo::core::master::thrift::FateOperation::TABLE_COMPACT,
			                tableArgs, options,wait);
			cout << "return value is " << returnValue << endl;
		} catch (org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &e) {
			return false;
		} catch (apache::thrift::TApplicationException &e) {
			return false;
		}

		return true;
	}

	bool flush(AuthInfo *auth, string table, string startrow, string endrow, bool wait)
	{
		org::apache::accumulo::trace::thrift::TInfo transId;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert (auth);
		transId.parentId = 0;
		transId.traceId = rand ();


		int64_t flushId = 0;
		try {
			flushId = masterClient->initiateFlush(transId,creds,table);

		} catch (org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &e) {
			recreateMasterClient();
			return false;
		} catch (apache::thrift::TApplicationException &e) {
			cout << e.what () << " " << e.getType () << endl;
			recreateMasterClient();
			return false;
		}

		uint64_t maxLoops = -1;
		if ( !wait) {
			maxLoops = 1;
		}

		while(true) {
			try {
				transId.parentId=transId.traceId;
				transId.traceId++;
				recreateMasterClient();
				masterClient->waitForFlush(transId,creds,table,startrow,endrow,flushId,maxLoops);
				break;
			} catch (apache::thrift::transport::TTransportException &e) {
				recreateMasterClient();
				cout << "error, retrying " << e.what() << endl;
				std::this_thread::sleep_for (std::chrono::milliseconds (100));
			} catch (org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &e) {
				recreateMasterClient();
				return false;
			} catch (apache::thrift::TApplicationException &e) {
				cout << e.what () << " " << e.getType () << endl;
				recreateMasterClient();
				return false;
			}
		}

		return true;
	}

	bool
	removeTable (AuthInfo *auth, string table)
	{

		vector<string> tableArgs;
		tableArgs.push_back (table);
		map<string, string> options;
		try {
			string returnValue =
			        doFateOperations (
			                auth,
			                org::apache::accumulo::core::master::thrift::FateOperation::TABLE_DELETE,
			                tableArgs, options);
		} catch (org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &e) {
			switch (e.type) {
			case org::apache::accumulo::core::client::impl::thrift::TableOperationExceptionType::EXISTS:
				cout << "Table already exist" << endl;
			default:
				return false;
			}
		}

		return true;

	}
	
	void removeTableProperty(AuthInfo *auth, string table, string property)
	{
	   org::apache::accumulo::trace::thrift::TInfo transId;
	    org::apache::accumulo::core::security::thrift::TCredentials creds =
		      ThriftWrapper::convert (auth);
	    transId.parentId = 0;
	    transId.traceId = rand ();

	    masterClient->removeTableProperty(transId,creds,table,property);
	}
	
	void setTableProperty(AuthInfo *auth, string table, string property, string value)
	{
	    org::apache::accumulo::trace::thrift::TInfo transId;
	    org::apache::accumulo::core::security::thrift::TCredentials creds =
		      ThriftWrapper::convert (auth);
	    transId.parentId = 0;
	    transId.traceId = rand ();

	    masterClient->setTableProperty(transId,creds,table,property,value);
	}

	
	/**namespace operations**/
	
	bool createNamespace(AuthInfo *auth, string name)
	{

		vector<string> tableArgs;
		tableArgs.push_back (name);
		//tableArgs.push_back ("MILLIS");
		map<string, string> options;
		try {
			string returnValue =
			        doFateOperations (
			                auth,
			                org::apache::accumulo::core::master::thrift::FateOperation::NAMESPACE_CREATE,
			                tableArgs, options,true);
		} catch (org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &e) {
			switch (e.type) {
			case org::apache::accumulo::core::client::impl::thrift::TableOperationExceptionType::NAMESPACE_NOTFOUND:
			default:
				cout << "what ? " << e.what() << endl;
				return false;
			}
		}

		return true;

	}
	
	bool deletenamespace(AuthInfo *auth, string name)
	{

		vector<string> tableArgs;
		tableArgs.push_back (name);
		//tableArgs.push_back ("MILLIS");
		map<string, string> options;
		try {
			string returnValue =
			        doFateOperations (
			                auth,
			                org::apache::accumulo::core::master::thrift::FateOperation::NAMESPACE_DELETE,
			                tableArgs, options,true);
		} catch (org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &e) {
			switch (e.type) {
			case org::apache::accumulo::core::client::impl::thrift::TableOperationExceptionType::NAMESPACE_NOTFOUND:
			default:
				cout << "what ? " << e.what() << endl;
				return false;
			}
		}

		return true;

	}
	
	
	bool renamenamespace(AuthInfo *auth, string oldName,string newName)
	{

		vector<string> tableArgs;
		tableArgs.push_back (oldName);
		tableArgs.push_back (newName);
		map<string, string> options;
		try {
			string returnValue =
			        doFateOperations (
			                auth,
			                org::apache::accumulo::core::master::thrift::FateOperation::NAMESPACE_RENAME,
			                tableArgs, options,true);
		} catch (org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &e) {
			switch (e.type) {
			case org::apache::accumulo::core::client::impl::thrift::TableOperationExceptionType::NAMESPACE_NOTFOUND:
			default:
				cout << "what ? " << e.what() << endl;
				return false;
			}
		}

		return true;

	}

	virtual
	~AccumuloMasterTransporter ()
	{
	    if (NULL != masterClient)
			delete masterClient;
	}
};

} /* namespace data */

#endif /* SRC_INTERCONNECT_TRANSPORT_ACCUMULOMASTERTRANSPOTER_H_ */

