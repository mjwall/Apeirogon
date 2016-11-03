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

#ifndef SRC_INTERCONNECT_TABLEOPS_CLIENTTABLEOPS_H_
#define SRC_INTERCONNECT_TABLEOPS_CLIENTTABLEOPS_H_
#include "TableOperations.h"

#include "../../data/constructs/KeyValue.h"
#include "../../data/constructs/security/AuthInfo.h"
#include "../../data/constructs/client/Instance.h"
#include "../../scanner/Source.h"
#include "../../scanner/constructs/Results.h"
#include "../transport/AccumuloMasterTransporter.h"
#include "../RootInterface.h"
#include "../../writer/Sink.h"

namespace interconnect
{


#include <map>
#include <vector>
#include <string>

using namespace scanners;
using namespace writer;
using namespace cclient::data;

/**
 * Accumulo Table Operations;
 */
class AccumuloTableOperations: public interconnect::TableOperations<KeyValue*,
	ResultBlock<KeyValue*>>
{
public:
	AccumuloTableOperations(AuthInfo *creds, Instance *instance, string table,
	               RootInterface<interconnect::AccumuloMasterTransporter, KeyValue*,
	               ResultBlock<KeyValue*>> *interface, CachedTransport<interconnect::AccumuloMasterTransporter> *tserverConn, DistributedConnector<interconnect::AccumuloMasterTransporter> *distributedConnector) :
		TableOperations<KeyValue*, ResultBlock<KeyValue*>>(creds, instance,
		                table), clientInterface(interface), tserverConn(tserverConn), distributedConnector(distributedConnector)
	{
		loadTableOps();
		getTableId();

	}
	virtual ~AccumuloTableOperations();

	/**
	 * Create a table. 
	 * @param recreate will recreate a table if necessary
	 * @return whether or not the table was created.
	 **/
	virtual bool create(bool recreate=false);

	/**
	  * Removes the current table
	  * @return whether or not removal was successful.
	  **/
	virtual bool remove();

	/**
	 * Determines if the table exists.
	 * @param createIfNot will create the table if true and it does not exist
	 * @return returns boolean of whether or not the table exists
	 **/
	virtual bool exists(bool createIfNot=false);


	/**
	 * Imports rfiles in path specified in dir
	 * @param dir dir containing rfiles
	 * @param fail_path failure path directory
	 * @param setTime Accumulo will set the time
	 * @return status of create
	 **/
	virtual bool import(string dir, string fail_path, bool setTime=false);

	/**
	 * Flushes the current table
	 * @param startRow start row on which to begin the flush
	 * @param endRow end point for the flush
	 * @param wait wait on this operation before returning
	 * @return status of flush
	 **/
	virtual bool flush(std::string startRow, std::string endRow, bool wait);

	/**
	 * Compacts the current table
	 * @param startRow start row on which to begin the compaction
	 * @param endRow end point for the compaction
	 * @param wait wait on this operation before returning
	 * @return status of compaction
	 **/
	virtual bool compact(std::string startRow, std::string endRow, bool wait);

	/**
	 * Returns the table ID
	 * @return table ID
	 **/
	std::string getTableId();
	
	/**
	 * Sets a table property
	 * @param property property names
	 * @param value property value
	 */
	virtual void setProperty(string property, string value);
    
	/**
	 * Removes a property on this table.
	 * @param property property name to remove
	 */
	virtual void removeProperty(string property);
	
	/**
	 * Returns all table properties.
	 * @return table properties
	 */
	virtual map<string,string> getProperties();
	
	/**
	 * Returns splits for this table.
	 * @return table splits.
	 */
	vector<string> listSplits();
	
	/**
	 * Adds splits for the current table
	 * @param partitions table splits
	 **/
	void addSplits(set<string> partitions);

	/**
	 * Creates a new scanner
	 * @param auths authorizations for this scanner
	 * @param threads current threads
	 * @return new scanner
	 **/
	Source<KeyValue*, ResultBlock<KeyValue*>> *createScanner(
	                Authorizations *auths, uint16_t threads);

	/**
	 * Creates a writer for the current table
	 * @param auths authorizations for this writer
	 * @param threads number of threads for writer
	 * @return new batch writer
	 */
	Sink<KeyValue*> *createWriter(Authorizations *auths,
	                              uint16_t threads);

protected:
  
	DistributedConnector<interconnect::AccumuloMasterTransporter> *distributedConnector;
  
	CachedTransport<interconnect::AccumuloMasterTransporter> *tserverConn;
  
	RootInterface<interconnect::AccumuloMasterTransporter, KeyValue*,
	              ResultBlock<KeyValue*>> *clientInterface;

	void loadTableOps(bool force = false);
};

extern map<string, string> nameSpaceIds;

} /* namespace impl */

#endif /* SRC_INTERCONNECT_TABLEOPS_CLIENTTABLEOPS_H_ */
