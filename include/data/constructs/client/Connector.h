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

