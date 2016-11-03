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

#include "../../../include/interconnect/transport/FateInterface.h"


using namespace interconnect;



string
	FateInterface::doFateOperations (
	        AuthInfo *auth,
	        org::apache::accumulo::core::master::thrift::FateOperation::type type,
	        vector<string> tableArgs, map<string, string> options, bool wait)
	{
	  
		org::apache::accumulo::core::master::thrift::MasterClientServiceClient *myMasterClient = getMasterClient();
		org::apache::accumulo::trace::thrift::TInfo transId;
		org::apache::accumulo::core::security::thrift::TCredentials creds =
		        ThriftWrapper::convert (auth);
		transId.parentId = 0;
		transId.traceId = rand ();
		int64_t fateTransId = myMasterClient->beginFateOperation (transId, creds);

		transId.parentId = transId.traceId;
		transId.traceId = transId.traceId + 1;


		bool succeeded = false;
		while (!succeeded) {

			try {
				myMasterClient->executeFateOperation (transId, creds, fateTransId, type,
				                                    tableArgs, options, !wait);
				succeeded = true;
			} catch (apache::thrift::transport::TTransportException &e) {
				recreateMasterClient();
				cout << "error, retrying " << e.what() << endl;
				succeeded = false;
				std::this_thread::sleep_for (std::chrono::milliseconds (100));
			}



		}


		string returnValue = "";
		if (wait) {
			while (true) {
				transId.parentId = transId.traceId;
				transId.traceId = transId.traceId + 1;
				boost::shared_ptr<TTransport> myTransport = recreateTransport ();
				boost::shared_ptr<TProtocol> protocolPtr (
				        new TCompactProtocol (myTransport));
				org::apache::accumulo::core::master::thrift::MasterClientServiceClient *waitClient = NULL;
				try {
					

					waitClient =
					        new org::apache::accumulo::core::master::thrift::MasterClientServiceClient (
					        protocolPtr);
					waitClient->waitForFateOperation (returnValue, transId, creds,
					                                  fateTransId);
					delete waitClient;
					
					break;

				} catch (apache::thrift::transport::TTransportException &e) {
					if (waitClient != NULL)
					  delete waitClient;
					std::this_thread::sleep_for (std::chrono::milliseconds (100));
					myTransport->close ();
				} catch (std::runtime_error &e) {
				  if (waitClient != NULL)
					  delete waitClient;
					myTransport->close ();
					throw e;
				}
				myTransport->close ();

			}

			transId.parentId = transId.traceId;
			transId.traceId = transId.traceId + 1;
			myMasterClient->finishFateOperation (transId, creds, fateTransId);
			recreateMasterClient();
		}
		return returnValue;
	}