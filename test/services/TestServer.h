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
#ifndef INCLUDE_DATA_SERVICES_SERVER_H_
#define INCLUDE_DATA_SERVICES_SERVER_H_


#include "../../include/concurrency/ThreadPool.h"
#include "../../include/concurrency/Executor.h"
#include "../../include/concurrency/ReturnType.h"

#include <protocol/TCompactProtocol.h>
#include <server/TSimpleServer.h>

#include <transport/TServerSocket.h>
#include <transport/TServerTransport.h>
#include <transport/TTransport.h>
#include <transport/TSocket.h>
#include <transport/TTransportException.h>
#include <transport/TBufferTransports.h>


#include <server/TThreadedServer.h>
#include <transport/TServerSocket.h>


#include <chrono>
#include <thread>
#include <pthread.h>
#include <sys/time.h>

#include "../../include/data/services/accumulo/TestTabletServer.h"

using namespace std;
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace services::accumulo;

class MockServer
{
protected:
    ThreadPool *executor;
    uint16_t port;
public:
    MockServer(int port) : port(port){
        executor = new ThreadPool();
    }

    void open()
    {
      shared_ptr<TProcessor> processor(new TestTabletServer());
      shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
      shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
      shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

      // start the threaded server.
      TThreadedServer server(processor, serverTransport, transportFactory, protocolFactory);
      server.serve();
    }
    
    
};


#endif /* INCLUDE_DATA_SERVICES_SERVER_H_ */
