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
#ifndef HEADER_E27852E033C484A1
#define HEADER_E27852E033C484A1

#ifndef CONNECTOR_H_
#define CONNECTOR_H_
#include <iostream>
#include <string>
#include <memory>
using namespace std;
#include "../../../scanner/impl/Scanner.h"
#include "Instance.h"
#include "zookeeperinstance.h"
#include "../security/AuthInfo.h"
#include "../security/Authorizations.h"
namespace cclient
{
namespace connector
{
namespace impl
{
using namespace interconnect;
using namespace cclient::data::security;
using namespace cclient::data;
using namespace cclient::data::zookeeper;
using namespace scanners;

class IConnector
{

public:
    virtual Scanner *
    createScanner (string tableName, Authorizations *authorizations,
                   int numQueryThreads) = 0;
    virtual
    ~IConnector ()
    {
    }

};

class AccumuloConnector : public IConnector
{
public:
    AccumuloConnector (ZookeeperInstance *instance, AuthInfo *auths) :
        myInstance (instance), credentials (NULL)
    {

    }

    Scanner *
    createScanner (string tableName, Authorizations *authorizations,
                   int numQueryThreads)
    {
        return 0;
    }
protected:
    cclient::data::Instance *myInstance;
    AuthInfo *credentials;
};

class Connector : public IConnector
{

public:

    Connector (ZookeeperInstance *instance, AuthInfo *auths)
    {
        base_connector = std::unique_ptr<IConnector> (
                             new AccumuloConnector (instance, auths));
    }

    Scanner *
    createScanner (string tableName, Authorizations *authorizations,
                   int numQueryThreads)
    {
        return base_connector->createScanner (tableName, authorizations,
                                              numQueryThreads);
    }

    virtual
    ~Connector ()
    {

    }
protected:
    std::unique_ptr<IConnector> base_connector;

};

} /* namespace impl */
} /* namespace cclient */
}

#endif /* CONNECTOR_H_ */

#endif // header guard

