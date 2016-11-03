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

#ifndef SERVERDEFINITION_H_
#define SERVERDEFINITION_H_

#include <iostream>
#include <string>

using namespace std;

#include "../security/AuthInfo.h"
#include "../security/Authorizations.h"
#include "../Range.h"
#include "../KeyExtent.h"

namespace cclient {

namespace data {
using namespace security;
namespace tserver {

class ServerDefinition {
public:
    /**
     * Constructor
     * @param creds ptr to creds
     * @param auths ptr to auths
     * @param host host name we're connecting to
     * @param port incoming port
     */
    ServerDefinition(AuthInfo *creds, Authorizations *auths, string host,
                     uint32_t port);

    // default to a port

    ~ServerDefinition();

    AuthInfo *getCredentials();

    Authorizations *getAuthorizations() const;

    string getServer() const;

    uint32_t getPort() const;

protected:
    AuthInfo *credentials;
    Authorizations *auths;
    string server;
    uint32_t port;

};
}
}
}
#endif /* SERVERDEFINITION_H_ */
