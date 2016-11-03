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
