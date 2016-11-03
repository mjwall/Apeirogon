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
#include "../../../../include/data/constructs/server/ServerDefinition.h"

#include <iostream>
#include <string>

using namespace std;

#include "../../../../include/data/constructs/server/../security/AuthInfo.h"
#include "../../../../include/data/constructs/server/../security/Authorizations.h"
#include "../../../../include/data/constructs/server/../Range.h"
#include "../../../../include/data/constructs/server/../KeyExtent.h"

namespace cclient
{

namespace data
{
using namespace security;
namespace tserver
{

/**
 * Constructor
 * @param creds ptr to creds
 * @param auths ptr to auths
 * @param host host name we're connecting to
 * @param port incoming port
 */
ServerDefinition::ServerDefinition (AuthInfo *creds,
                                    Authorizations *auths, string host,
                                    uint32_t port) :
    credentials (creds), auths (auths), server (host), port (port)
{

}
// default to a port

ServerDefinition::~ServerDefinition ()
{

}

AuthInfo *
ServerDefinition::getCredentials ()
{
    return credentials;
}

Authorizations *
ServerDefinition::getAuthorizations () const
{
    return auths;
}

string
ServerDefinition::getServer () const
{
    return server;
}

uint32_t
ServerDefinition::getPort () const
{
    return port;
}
}
}
}
