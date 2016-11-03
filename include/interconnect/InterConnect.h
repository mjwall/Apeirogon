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

#ifndef INTERCONNECT_H_
#define INTERCONNECT_H_ 1

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

#include "../data/exceptions/ClientException.h"
#include "../data/exceptions/IllegalArgumentException.h"
#include "../data/constructs/inputvalidation.h"
#include "transport/BaseTransport.h"
#include "transport/ServerConnection.h"
#include "transport/CachedTransport.h"
#include <boost/concept_check.hpp>

using namespace cclient::exceptions;

namespace interconnect
{

#define TSERVER_PORT_OPT "tserver.port.client"
#define TSERVER_DEFAULT_PORT 9997

#define GENERAL_RPC_TIMEOUT_OPT "general.rpc.timeout"
#define GENERAL_RPC_TIMEOUT 120*1000

enum INTERCONNECT_TYPES
{
    TSERV_CLIENT, MASTER_CLIENT, GC_CLIENT
};

#define SERVICE_SEPARATOR ';'
#define SEPARATOR_CHAR '='

template<typename T>
class EnumParser
{
protected:
    map<string, T> enumMap;
public:
    EnumParser ()
    {
    }

    T
    ParseSomeEnum (const string &value)
    {
        auto iValue = enumMap.find (value);
        if (iValue == enumMap.end ())
            throw IllegalArgumentException ("");
        return iValue->second;
    }
};

class TYPE_PARSER : public EnumParser<INTERCONNECT_TYPES>
{
public:
    TYPE_PARSER ()
    {
        enumMap["TSERV_CLIENT"] = INTERCONNECT_TYPES::TSERV_CLIENT;
        enumMap["tserv_client"] = INTERCONNECT_TYPES::TSERV_CLIENT;
        enumMap["tserver"] = INTERCONNECT_TYPES::TSERV_CLIENT;

        enumMap["MASTER_CLIENT"] = INTERCONNECT_TYPES::MASTER_CLIENT;
        enumMap["master_client"] = INTERCONNECT_TYPES::MASTER_CLIENT;
        enumMap["master"] = INTERCONNECT_TYPES::MASTER_CLIENT;

        enumMap["GC_CLIENT"] = INTERCONNECT_TYPES::GC_CLIENT;
        enumMap["gc_client"] = INTERCONNECT_TYPES::GC_CLIENT;
        enumMap["gc"] = INTERCONNECT_TYPES::GC_CLIENT;
    }
};

/**
 * Connector service instance
 * Purpose: Acts as a reference within the map of known connection types
 *
 */
class ConnectorService
{
public:
    ConnectorService (string service, string server, uint16_t port)
    {
        serviceMap.insert (
            std::pair<INTERCONNECT_TYPES, string> (parser.ParseSomeEnum (service),
                    server));

    }

    string
    getAddressString (INTERCONNECT_TYPES type)
    {
        return serviceMap[type];
    }

protected:
    map<INTERCONNECT_TYPES, string> serviceMap;
    TYPE_PARSER parser;
};

#define ERROR_THRESHOLD 20L
#define STUCK_THRESHOLD 2*60*1000

}
#endif
