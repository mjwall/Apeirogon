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

#ifndef USEROPERATIONS_H
#define USEROPERATIONS_H

#include <iostream>
#include "../../data/constructs/security/Authorizations.h"


#include "../../data/constructs/KeyValue.h"
#include "../../data/constructs/security/AuthInfo.h"
#include "../../data/constructs/client/Instance.h"
#include "../../scanner/Source.h"
#include "../../scanner/constructs/Results.h"
#include "../transport/AccumuloMasterTransporter.h"
#include "../RootInterface.h"



#include <map>
#include <string>

using namespace scanners;
using namespace writer;
using namespace cclient::data;
using namespace cclient::data::security;

namespace interconnect
{
class SecurityOperations
{
public:
	SecurityOperations(AuthInfo *creds, Instance *instance,
	               CachedTransport<interconnect::AccumuloMasterTransporter> *interface, DistributedConnector<interconnect::AccumuloMasterTransporter> *distributedConnector) : credentials(creds), myInstance(instance),clientInterface(interface->getTransport())
	{
	  ptr = boost::shared_ptr<interconnect::AccumuloMasterTransporter>(interface->getTransporter());
	  cachedTransport = interface;
	  refDistributedConnector = distributedConnector;
	}
	
	~SecurityOperations();
	
	bool createUser(string user,string password);
	
	bool changeUserPassword(string user, string password);
	
	bool dropUser(string user);
	
	cclient::data::security::Authorizations *getAuths(string user);
	
	bool grantAuthorizations(Authorizations *auths, string user);
protected:
  boost::shared_ptr<interconnect::AccumuloMasterTransporter> ptr;
    interconnect::AccumuloMasterTransporter *clientInterface;
    CachedTransport<interconnect::AccumuloMasterTransporter> *cachedTransport;
    DistributedConnector<interconnect::AccumuloMasterTransporter> *refDistributedConnector;
    Instance *myInstance;
    AuthInfo *credentials;
  
};
}
#endif // USEROPERATIONS_H
