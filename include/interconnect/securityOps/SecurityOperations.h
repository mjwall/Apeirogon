/*
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * Key/value connector. Copyright (c) 2016 Marc marc.parisi@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
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
