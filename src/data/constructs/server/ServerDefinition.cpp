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
