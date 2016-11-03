

/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2015
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
#include "../../../../include/data/services/accumulo/TabletServer.h"
#include "../../../../include/data/services/accumulo/ScanSession.h"
#include "../../../../include/data/services/Server.h"
#include "../../../../include/data/extern/thrift/TabletClientService.h"

#include <map>
#include <set>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <chrono>
//#include <protocol/TBinaryProtocol.h>
#include <protocol/TCompactProtocol.h>
#include <server/TSimpleServer.h>

#include <transport/TServerSocket.h>
#include <transport/TServerTransport.h>
#include <transport/TTransport.h>
#include <transport/TSocket.h>
#include <transport/TTransportException.h>
#include <transport/TBufferTransports.h>

#include <concurrency/ThreadManager.h>

#include <chrono>
#include <thread>
#include <pthread.h>
#include <sys/time.h>


#include "../../../../include/data/extern/thrift/ThriftWrapper.h"

using namespace std;
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;


namespace services
{
namespace accumulo
{

using namespace interconnect;

void TabletServer::startScan ( ::org::apache::accumulo::core::data::thrift::InitialScan&  result ,
                               const  ::org::apache::accumulo::trace::thrift::TInfo&  tinfo ,
                               const  ::org::apache::accumulo::core::security::thrift::TCredentials&  credentials ,
                               const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent ,
                               const  ::org::apache::accumulo::core::data::thrift::TRange&  range ,
                               const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & columns ,
                               const int32_t  batchSize , const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> &  ssiList ,
                               const std::map<std::string, std::map<std::string, std::string> > &  ssio ,
                               const std::vector<std::string> & authorizations ,
                               const bool waitForWrites , const bool  isolated , const int64_t readaheadThreshold  ) {

    Scan *scan = new Scan(scanId++);


    scan->addRange( ThriftWrapper::convert(range) );
    scan->setCredentials( ThriftWrapper::convert(credentials) );
    scan->setExtent( ThriftWrapper::convert(extent) );
    scan->setColumns( ThriftWrapper::convert(columns) );
    scan->setIterators( ThriftWrapper::convert(ssiList ) );
    scan->setIteratorOptions(ssio);
    scan->setAuthorizations( authorizations );

    boost::shared_future<ReturnType*> ret = executor->submit( scan );

    scan.setFuture( &ret );


    boost::future_status status = ret.wait_for(std::chrono::seconds(2));

    return;
}
}
}