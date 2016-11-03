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
