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
