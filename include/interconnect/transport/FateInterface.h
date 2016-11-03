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

#ifndef SRC_INTERCONNECT_FATEINTERFACE_H_
#define SRC_INTERCONNECT_FATEINTERFACE_H_


#include <concurrency/ThreadManager.h>

#include <chrono>
#include <thread>
#include <pthread.h>
#include <sys/time.h>

#include <map>
#include <set>
#include <string>
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


//#include <protocol/TBinaryProtocol.h>
#include <protocol/TCompactProtocol.h>
#include <server/TSimpleServer.h>

#include <transport/TServerSocket.h>
#include <transport/TServerTransport.h>
#include <transport/TTransport.h>
#include <transport/TSocket.h>
#include <transport/TTransportException.h>
#include <transport/TBufferTransports.h>

#include "MasterInterface.h"
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
namespace interconnect
{

/**
 * Fate implementation class
 * Purpose: Defines the interface for all fate operations
 * Design: Extends MasterInterface to be able to access
 * master objects for re-creation 
 **/
class FateInterface : public MasterInterface
{
protected:
  /**
   * Executes fate operations. 
   * @param auth authorization info
   * @param type fate operation
   * @param tableArgs namespace or table arguments
   * @param options options for this fate operation
   * @param wait determines if we will wait on the fate operation
   * @return return value of the fate operation
   **/ 
  string
	doFateOperations (
	        AuthInfo *auth,
	        org::apache::accumulo::core::master::thrift::FateOperation::type type,
	        vector<string> tableArgs, map<string, string> options, bool wait = false);
};

}

#endif
