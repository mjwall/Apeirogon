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

#include "../../../include/interconnect/securityOps/SecurityOperations.h"

using namespace interconnect;


SecurityOperations::~SecurityOperations()
{
  refDistributedConnector->freeTransport(cachedTransport);
  clientInterface->close();
}

bool SecurityOperations::dropUser(string user)
{
 // create the client interface so that this service is usable.
  clientInterface->closeAndCreateClient();
  return clientInterface->dropUser(credentials,user);
}

bool SecurityOperations::changeUserPassword(string user, string password)
{
  clientInterface->closeAndCreateClient();
  return clientInterface->changeUserPassword(credentials,user,password);
}


bool 
SecurityOperations::createUser(string user, string password)
{
  // create the client interface so that this service is usable.
  clientInterface->closeAndCreateClient();
  return clientInterface->createUser(credentials,user,password);
}

      
cclient::data::security::Authorizations *SecurityOperations::getAuths(string user)
{
  // TODO 
  return NULL;
}

bool SecurityOperations::grantAuthorizations(Authorizations* auths, string user)
{
  // create the client interface so that this service is usable.
  clientInterface->closeAndCreateClient();
  clientInterface->changeUserAuths(credentials,user,auths);
  return true;
}

