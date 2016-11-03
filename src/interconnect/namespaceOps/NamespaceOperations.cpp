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

#include <list>
#include <string>
using namespace std;
#include "../../../include/data/exceptions/ClientException.h"
#include "../../../include/interconnect/namespaceOps/NamespaceOperations.h"
#include "../../../include/interconnect/tableOps/../../data/constructs/ConfigurationOptions.h"


using namespace cclient::exceptions;

namespace interconnect{

NamespaceOperations::~NamespaceOperations()
{

}

bool NamespaceOperations::exists(std::string name){
  if (IsEmpty(&name))
    name = myNamespace;
  return  namespaces.find (name) != std::end (namespaces);  
}

void NamespaceOperations::create(string name)
{
  interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();
		
  if (IsEmpty(&name))
    name = myNamespace;
  if (!baseTransport->createNamespace(credentials,name))
  {
    throw ClientException(COULD_NOT_CREATE_NAMESPACE);
  }
  else{
    loadNamespaces();
  }
}

bool NamespaceOperations::remove(string name)
{
  if (IsEmpty(&name))
    name = myNamespace;
  string id = namespaces[name];
  
  if (IsEmpty(&id) || id == "accumulo" )
  {
    throw ClientException(DELETE_DEFAULT_NAMESPACE);
  }
  else
  {
    interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();
		
    if (!baseTransport->deletenamespace(credentials,name))
    {
      throw ClientException(COULD_NOT_CREATE_NAMESPACE);
    }
    else{
      loadNamespaces();
    }
  }
    
  
  return false;
  
}

void NamespaceOperations::rename(string newName, string oldName)
{
  if (IsEmpty(&oldName))
  {
    oldName = myNamespace;
  }
  
  string id = namespaces[oldName];
  
  if (IsEmpty(&id) || id == "accumulo" )
  {
    throw ClientException(DELETE_DEFAULT_NAMESPACE);
  }
  else
  {
    interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();
		
    if (!baseTransport->renamenamespace(credentials,oldName,newName))
    {
      throw ClientException(COULD_NOT_CREATE_NAMESPACE);
    }
    else{
      loadNamespaces();
    }
  }
}


string NamespaceOperations::systemNamespace()
{
  return "accumulo";
}

list< string > NamespaceOperations::list()
{
  
  return namespaceNames;
}

void NamespaceOperations::loadNamespaces(bool force)
{
      pthread_mutex_lock (&namesOpMutex);
	const Configuration *conf = myInstance->getConfiguration ();

	string fsRoot = conf->get (FILE_SYSTEM_ROOT_CFG);

	fsRoot.append ("/");
	fsRoot.append (myInstance->getInstanceId ());
	fsRoot.append ( TABLE_GET_NAMESPACES);

	InstanceCache *cache = myInstance->getInstanceCache ();
	std::list<string> namespaceIds = cache->getChildren (fsRoot,force);

	namespaces.clear ();
	namespaceNames.clear();
	for (string retrievedId : namespaceIds) {
		string tablePath = fsRoot;
		tablePath.append ("/");
		tablePath.append (retrievedId);

		string namePath = tablePath;
		namePath.append (TABLE_GET_NAME);
		char *path = (char*) cache->getData (namePath);
		if (IsEmpty (path)) {

			continue;
			pthread_mutex_unlock (&namesOpMutex);


		}
		std::string namespaceName = string (path);


		if (!IsEmpty (&namespaceName)) {
			// insert both representations
			namespaces.insert (std::make_pair (retrievedId, namespaceName));
			namespaces.insert (std::make_pair (namespaceName, retrievedId));
			namespaceNames.push_back(namespaceName);
		}

	}
	pthread_mutex_unlock (&namesOpMutex);
}

}
