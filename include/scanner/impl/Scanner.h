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

#ifndef SCANNER_H_
#define SCANNER_H_

#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

#include <pthread.h>

#include "../Source.h"
#include "../../data/constructs/Key.h"
#include "../../data/constructs/security/AuthInfo.h"
#include "../../data/constructs/security/Authorizations.h"
#include "../../data/constructs/value.h"
#include "../constructs/Results.h"
#include "../../data/constructs/inputvalidation.h"
#include "../../data/client/ExtentLocator.h"
#include "../../data/exceptions/ClientException.h"
#include "../../data/constructs/client/zookeeperinstance.h"
#include "../../data/client/LocatorCache.h"
#include "../constructs/ServerHeuristic.h"
#include "../../interconnect/ClientInterface.h"
#include "../../interconnect/tableOps/TableOperations.h"

namespace scanners {

using namespace interconnect;
using namespace cclient::data::zookeeper;
using namespace cclient::data;
using namespace cclient::data::security;
using namespace cclient::exceptions;

/**
  Scanner scans uses the interconnect to retrieve Keys and Values from the data source.
  **/
class Scanner: public scanners::Source<KeyValue*, ResultBlock<KeyValue*>> {
public:
    /**
     * Scanner constructor
     * @param instance connector instance
     * @param top table operations refereuce
     * @param auths authorizations
     * @param threads threads for the scanner
     **/
    Scanner(Instance *instance,
            TableOperations<KeyValue*, ResultBlock<KeyValue*>> *tops,
            Authorizations *auths, uint16_t threads);

    /**
     * Adds a range to the scanner
     * @param range 
     **/
    void addRange(Range *range) {
        pthread_mutex_lock(&scannerLock);
        // throw exception if running
        ranges->push_back(range);
        pthread_mutex_unlock(&scannerLock);

    }
    
    
    /**
     * Returns a result set. 
     * @return results iterator.
     **/
    Results<KeyValue*, ResultBlock<KeyValue*>> *getResultSet() {
        pthread_mutex_lock(&scannerLock);


        if (IsEmpty(resultSet) && IsEmpty(&servers)) {

            resultSet = new Results<KeyValue*, ResultBlock<KeyValue*>>();

            map<string,
                map<KeyExtent*, vector<Range*>,
                pointer_comparator<KeyExtent*> > > returnRanges;
            set<string> locations;
            tableLocator->binRanges(credentials, ranges, &locations,
                                    &returnRanges);

            for (string location : locations) {
                vector<string> locationSplit = split(location, ':');
		if (locationSplit.size() != 2 )
		{
		  
		}
		char *res = 0;
		errno = 0;
		uint64_t port = strtoul(locationSplit.at(1).c_str(),&res,10);
		if (((port == (uint64_t)LONG_MIN || port == (uint64_t)LONG_MAX ) && errno != 0 ) || *res !='\0') 
		{
		    throw cclient::exceptions::ClientException( INVALID_SERVER_PORT);
		}
                for (auto hostExtents : returnRanges.at(location)) {
                    vector<KeyExtent*> extents;
                    extents.push_back(hostExtents.first);
                    RangeDefinition *rangeDef = new RangeDefinition(credentials,
                            scannerAuths, locationSplit.at(0),
                            port,
                            &hostExtents.second, &extents, &columns);

                    interconnect::ServerInterconnect *directConnect =
                        new interconnect::ServerInterconnect(rangeDef,
                                connectorInstance->getConfiguration());
                    scannerHeuristic->addClientInterface(directConnect);
                }
            }

            // begin the scan, however the pre-configured heuristic chooses
            scannerHeuristic->scan(this);

        }
        pthread_mutex_unlock(&scannerLock);

        return resultSet;
    }

    void addResults(Results<KeyValue*, ResultBlock<KeyValue*>> *results) {

    }

    /**
     * Sets the heuristic for this scanner
     * @param heuristic scanner heuristic
     */
    void setHeuristic(ScannerHeuristic *heuristic) {
        scannerHeuristic = heuristic;
    }

    virtual ~Scanner() {
        delete ranges;
        delete scannerHeuristic;
    }
    
protected:

    /**
     * Flushes the scanner
     * @param override ensures that flushes occur despite not meeting requirements
     **/
    void flush(bool override = false);

    /**
     * Adds a connecting server definition 
     * @param ifc server definition
     **/
    void addServerDefinition(
        ClientInterface<interconnect::ThriftTransporter> *ifc) {
        servers.push_back(ifc);
    }

    /**
     * Adds a vector of connecting server definition 
     * @param ifc server definition
     **/
    void addServerDefinition(
        vector<ClientInterface<interconnect::ThriftTransporter>*> ifc) {
        servers.insert(servers.end(), ifc.begin(), ifc.end());
    }

    // scanner
    pthread_mutex_t scannerLock = PTHREAD_MUTEX_INITIALIZER;
    // vector of ranges to interrogate.
    vector<Range*> *ranges;
    // result set iterator
    Results<KeyValue*, ResultBlock<KeyValue*>> *resultSet;
    // credentials
    AuthInfo *credentials;
    // scanner authorizations
    Authorizations *scannerAuths;
    // servers to access
    vector<ClientInterface<interconnect::ThriftTransporter>*> servers;
    // zookeeper instance
    ZookeeperInstance *connectorInstance;
    // scanner heuristic to control server access
    ScannerHeuristic *scannerHeuristic;
    // tablet locator
    TabletLocator *tableLocator;
};
}
#endif /* SCANNER_H_ */

