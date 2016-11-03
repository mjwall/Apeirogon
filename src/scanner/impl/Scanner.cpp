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

#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

#include <pthread.h>

#include "../../../include/scanner/impl/../Source.h"
#include "../../../include/scanner/impl/../../data/constructs/Key.h"
#include "../../../include/scanner/impl/../../data/constructs/security/AuthInfo.h"
#include "../../../include/scanner/impl/../../data/constructs/security/Authorizations.h"
#include "../../../include/scanner/impl/../../data/constructs/value.h"
#include "../../../include/scanner/impl/../constructs/Results.h"
#include "../../../include/scanner/impl/../../data/constructs/inputvalidation.h"
#include "../../../include/scanner/impl/../../data/client/ExtentLocator.h"
#include "../../../include/scanner/impl/../../data/constructs/client/zookeeperinstance.h"
#include "../../../include/scanner/impl/../../data/client/LocatorCache.h"
#include "../../../include/scanner/impl/../constructs/ServerHeuristic.h"
#include "../../../include/scanner/impl/../../interconnect/ClientInterface.h"
#include "../../../include/scanner/impl/../../interconnect/tableOps/TableOperations.h"
#include "../../../include/scanner/impl/Scanner.h"

namespace scanners
{

Scanner::Scanner (Instance *instance,
                  TableOperations<KeyValue*, ResultBlock<KeyValue*>> *tops,
                  Authorizations *auths, uint16_t threads) :
    scannerAuths (auths)
{
    scannerHeuristic = new ScannerHeuristic (threads);
    connectorInstance = dynamic_cast<ZookeeperInstance*> (instance);
    resultSet = NULL;
    tableLocator = cachedLocators.getLocator (
                       LocatorKey (connectorInstance, tops->getTableId ()));
    credentials = tops->getCredentials ();
    ranges = new vector<Range*> ();
}

}
