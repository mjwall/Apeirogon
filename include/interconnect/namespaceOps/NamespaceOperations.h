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

#ifndef NAMEOPERATIONS_H
#define NAMEOPERATIONS_H

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
#include <list>
#include <string>

using namespace std;

using namespace scanners;
using namespace writer;
using namespace cclient::data;
using namespace cclient::data::security;

namespace interconnect
{
class NamespaceOperations
{
public:
	/**
	 * Namespaces constructor. Does not focus the namespace operations on a given instance.
	 * @param creds credentials
	 * @param instance instance provided by connector
	 * @param interface connector interface
	 * @param distributedConnector distributed interface for tablet servers
	 **/
	NamespaceOperations(AuthInfo *creds, Instance *instance,
	               RootInterface<interconnect::AccumuloMasterTransporter, KeyValue*,
	               ResultBlock<KeyValue*>> *interface, DistributedConnector<interconnect::AccumuloMasterTransporter> *distributedConnector) : 
	               NamespaceOperations(creds,"",instance,interface,distributedConnector)
	{
	  // simply calls the other constructor
	}
	
	/**
	 * Namespaces constructor. Does not focus the namespace operations on a given instance.
	 * @param creds credentials
	 * @param myNamespace namespace 
	 * @param instance instance provided by connector
	 * @param interface connector interface
	 * @param distributedConnector distributed interface for tablet servers
	 **/
	NamespaceOperations(AuthInfo *creds, string myNamespace, Instance *instance,
	               RootInterface<interconnect::AccumuloMasterTransporter, KeyValue*,
	               ResultBlock<KeyValue*>> *interface, DistributedConnector<interconnect::AccumuloMasterTransporter> *distributedConnector) :
	               myNamespace(myNamespace), credentials(creds), myInstance(instance),clientInterface(interface)
	{
	  refDistributedConnector = distributedConnector;
	  
	   pthread_mutexattr_t Attr;

	  pthread_mutexattr_init(&Attr);
	  // ensure that our threading mutex is recursive since loadNamespaces
	  // will recursively call itself.
	  pthread_mutexattr_settype(&Attr, PTHREAD_MUTEX_RECURSIVE);
	  pthread_mutex_init(&namesOpMutex, &Attr);
	  
	  loadNamespaces();
	}
	
	/**
	 * Provides a list of namespaces
	 * @return namespaces
	 **/
	std::list<string> list();
	
	 /**
	  * Namespaces destructor
	  **/
	~NamespaceOperations();
	
	/**
	 * Returns a list of system namespaces
	 * @return system namespaces
	 **/
	string systemNamespace();
	
	/**
	 * Returns the default namesapce
	 * @return returns ""
	 **/
	string defaultNamespace(){ return ""; }
	
	/**
	 * Removes a namespace if specified, otherwise myNamespace is removed
	 * @param name namespace to remove (optional )
	 * @return status of operation.
	 **/
	bool remove(std::string name = "");
	
	/**
	 * Determines if namespace exists
	 * @param name namespace to test (optional )
	 * @return true if namespace exists, false otherwise
	 **/
	bool exists(std::string name = "");
	
	/**
	 * Creates a namespace
	 * @param name namespace to create (optional, otherwise myNamespace )
	 **/
	void create(std::string name = "");
	
	/**
	 * Renames a namespace
	 * @param newName new namespace name
	 * @param oldName previous name. if not specified myNamespace will be renamed
	 **/
	void rename(std::string newName, std::string oldName = "");
	
protected:
  
    /**
     * Loads the namespaces
     * @param force forces the load if necessary
     **/
    void loadNamespaces(bool force = false);
    
    // client interface
    RootInterface<interconnect::AccumuloMasterTransporter, KeyValue*,
	               ResultBlock<KeyValue*>> *clientInterface;
    // distributed connector to tservers
    DistributedConnector<interconnect::AccumuloMasterTransporter> *refDistributedConnector;
    // instance ptr
    Instance *myInstance;
    // credentials
    AuthInfo *credentials;
    // provided namespace
    string myNamespace;
    // namespace mutex
    pthread_mutex_t namesOpMutex;
    
    // loaded namespaces
    map<string, string> namespaces;
    std::list<string> namespaceNames;
  
};
}
#endif // USEROPERATIONS_H
