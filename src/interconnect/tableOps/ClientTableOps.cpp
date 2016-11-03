/*
 * AccumuloTableOperations.cpp
 *
 *  Created on: 4 Oct 2015
 *      Author: phrocker
 */

#include <list>
#include <string>
using namespace std;

#include "../../../include/interconnect/tableOps/ClientTableOps.h"
#include "../../../include/interconnect/tableOps/TableOperations.h"
#include "../../../include/interconnect/tableOps/../accumulo/AccumuloStreams.h"
#include "../../../include/interconnect/tableOps/../../scanner/impl/Scanner.h"
#include "../../../include/interconnect/tableOps/../../writer/impl/SinkImpl.h"
#include "../../../include/interconnect/tableOps/../../data/constructs/ConfigurationOptions.h"
#include "../../../include/interconnect/tableOps/../transport/AccumuloMasterTransporter.h"
#include "../../../include/data/client/LocatorCache.h"
#include "../../../include/data/client/ExtentLocator.h"
#include <pthread.h>
namespace interconnect
{

using namespace scanners;
using namespace writer;

AccumuloTableOperations::~AccumuloTableOperations ()
{
	// we don't own client interface.
//	delete clientInterface;
    distributedConnector->freeTransport(tserverConn);
}

Source<KeyValue*, ResultBlock<KeyValue*>> *
                                       AccumuloTableOperations::createScanner (Authorizations *auths, uint16_t threads)
{
	return new AccumuloStreams (myInstance, this, auths, threads);
}

Sink<KeyValue*> *
AccumuloTableOperations::createWriter (Authorizations *auths, uint16_t threads)
{
	return new AccumuloStreams (myInstance, this, auths, threads);

}


void
AccumuloTableOperations::loadTableOps (bool force)
{
	pthread_mutex_lock (&tableOpMutex);
	const Configuration *conf = myInstance->getConfiguration ();

	string fsRoot = conf->get (FILE_SYSTEM_ROOT_CFG);

	fsRoot.append ("/");
	fsRoot.append (myInstance->getInstanceId ());
	fsRoot.append ( TABLE_SUFFIX);

	InstanceCache *cache = myInstance->getInstanceCache ();
	list<string> tableIds = cache->getChildren (fsRoot,force);

	cachedTableIds.clear ();
	tableNames.clear();
	for (string retrievedId : tableIds) {
		string tablePath = fsRoot;
		tablePath.append ("/");
		tablePath.append (retrievedId);

		string namePath = tablePath;
		namePath.append (TABLE_GET_NAME);
		char *path = (char*) cache->getData (namePath);
		if (IsEmpty (path)) {

			loadTableOps ();
			pthread_mutex_unlock (&tableOpMutex);

			return;

		}
		string tableName = string (path);

		string nameSpacePath = tablePath;
		nameSpacePath.append (TABLE_GET_NAMESPACE);
		string namespaceId = string ((char*) cache->getData (nameSpacePath));

		string namespaceName = "";
		if (!IsEmpty (&namespaceId)) {
		    if (namespaceId != DEFAULT_NAMESPACE_ID)
		    {
		    }
		}

		if (!IsEmpty (&tableName)) {
			// insert both representations
			cachedTableIds.insert (std::make_pair (retrievedId, tableName));
			cachedTableIds.insert (std::make_pair (tableName, retrievedId));
			tableNames.insert(tableName);
		}

	}
	pthread_mutex_unlock (&tableOpMutex);
}

string
AccumuloTableOperations::getTableId ()
{
	string retTable = "";
	pthread_mutex_lock (&tableOpMutex);
	if (IsEmpty (&tableId)) {

		string ephemeralTableId = "";

		try {
			cachedTableIds.at (myTable);
		} catch (const std::out_of_range& e) {
			// do nothing since it isn't cached
		}
		// it's not cached!!!
		if (IsEmpty (&ephemeralTableId)) {
			loadTableOps ();
			try {
				ephemeralTableId = cachedTableIds.at (myTable);
			} catch(std::out_of_range o) {
				cout << "table does not exist" << endl;
				// do nothing
			}

		}
		tableId = ephemeralTableId;
	}
	retTable = tableId;
	pthread_mutex_unlock (&tableOpMutex);
	return retTable;
}

bool
AccumuloTableOperations::import (string dir, string fail_path, bool setTime)
{
	interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();
  
	if (!baseTransport->importDirectory (credentials, myTable, dir, fail_path,
	                                     setTime)) {
		return false;
	}

	return true;
}

bool AccumuloTableOperations::flush(string startRow, string endRow, bool wait)
{
	interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();
	
	if (!baseTransport->flush (credentials,tableId,startRow,endRow, wait)) {
		return false;
	}

	return true;
}


bool AccumuloTableOperations::compact(string startRow, string endRow, bool wait)
{
	interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();


	if (!baseTransport->compact (credentials,tableId,startRow,endRow,wait)) {
		return false;
	}

	return true;
}

bool
AccumuloTableOperations::create (bool recreate)
{
	interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();
		
	pthread_mutex_lock (&tableOpMutex);
	if (recreate) {
		remove ();
	}
	if (!baseTransport->createTable (credentials, myTable)) {
		pthread_mutex_unlock (&tableOpMutex);
		return false;
	}
	tableId = "";
	loadTableOps ();
	pthread_mutex_unlock (&tableOpMutex);

	return true;
}

vector< string > AccumuloTableOperations::listSplits()
{
      if (IsEmpty(&tableId))
      {	
	loadTableOps();
      }

	    ZookeeperInstance *connectorInstance = dynamic_cast<ZookeeperInstance*> (myInstance);
       
    TabletLocator *tabletLocator = cachedLocators.getLocator (
                       LocatorKey (connectorInstance, tableId));
    
      list<TabletLocation*> locations = tabletLocator->locations(credentials);
      
      vector<string> tablets;
      for(auto location : locations)
      {
	KeyExtent *extent = location->getExtent();
	tablets.push_back( extent->getEndRow() );
	delete location;
	
      }
      return tablets;
}

void AccumuloTableOperations::addSplits(set<string> partitions)
{
	    ZookeeperInstance *connectorInstance = dynamic_cast<ZookeeperInstance*> (myInstance);


  // need better error handling here	    
  for(string partition : partitions)
  {
    bool success = false;
    while(!success)
    {
      TabletLocator *tabletLocator = cachedLocators.getLocator (
			LocatorKey (connectorInstance, tableId));
      TabletLocation *location = tabletLocator->locateTablet(credentials,partition,false,false);
      
      ServerConnection *connection = new ServerConnection(location->getServer(),location->getPort(),-1);
      
      CachedTransport<interconnect::AccumuloMasterTransporter> *cachedTransport = distributedConnector->getTransporter(connection);
      
      try{
	
      cachedTransport->getTransport()->splitTablet(credentials,location->getExtent(),partition);
      success = true;
       }catch(TProtocolException tpe)
	{
	  cachedTransport->sawError(true);   
	  distributedConnector->freeTransport(cachedTransport);
	  success = false;
	}
	catch(TTransportException tpe)
	{
	  cachedTransport->sawError(true);   
	  distributedConnector->freeTransport(cachedTransport);
	  success = false;
	}
		
      delete connection;
      
      delete location;
      
      distributedConnector->freeTransport(cachedTransport);
      
      
    }
  }
}



void AccumuloTableOperations::removeProperty(string property)
{

  interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();
  baseTransport->removeTableProperty(credentials,myTable,property);
      
}

void AccumuloTableOperations::setProperty(string property, string value)
{
interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();
  baseTransport->setTableProperty(credentials,myTable,property,value);
}

map< string, string > AccumuloTableOperations::getProperties()
{
  interconnect::AccumuloMasterTransporter *baseTransport =
	        tserverConn->getTransport();
		
    return baseTransport->getTableConfiguration(credentials,myTable);
}


bool
AccumuloTableOperations::remove ()
{
	interconnect::AccumuloMasterTransporter *baseTransport =
	        clientInterface->getTransport ().get ();
	pthread_mutex_lock (&tableOpMutex);
	if (!baseTransport->removeTable (credentials, myTable)) {
		pthread_mutex_unlock (&tableOpMutex);
		return false;
	}
	tableId = "";
	loadTableOps(true);
	pthread_mutex_unlock (&tableOpMutex);

	return true;
}

bool
AccumuloTableOperations::exists (bool createIfNot)
{
	bool contains = cachedTableIds.find (myTable) != std::end (cachedTableIds);

	if (!contains && createIfNot) {
		if (create ())
			return true;
	}
	return contains;
}

map<string, string> nameSpaceIds;
} /* namespace impl */
