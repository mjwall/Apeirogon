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
#include <string>
#include <map>
#include <set>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
using namespace std;

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

#include "../../include/interconnect/../data/exceptions/ClientException.h"
#include "../../include/interconnect/../data/exceptions/IllegalArgumentException.h"
#include "../../include/interconnect/../data/constructs/inputvalidation.h"
#include "../../include/interconnect/transport/BaseTransport.h"
#include "../../include/interconnect/transport/ServerConnection.h"
#include "../../include/interconnect/transport/CachedTransport.h"
#include <boost/concept_check.hpp>

#include "../../include/interconnect/InterConnect.h"

using namespace interconnect;

