/*
 * Copyright (c) 2016 Marc Parisi marc.parisi@gmail.com
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

#ifndef SRC_INTERCONNECT_TABLEOPS_TABLEOPERATIONS_H_
#define SRC_INTERCONNECT_TABLEOPS_TABLEOPERATIONS_H_


#include "../../data/constructs/inputvalidation.h"
#include "../../data/constructs/client/Instance.h"
#include "../../scanner/Source.h"
#include "../../writer/Sink.h"

namespace interconnect {

#include <string>
#include <map>
using namespace std;

#include <pthread.h>


using namespace cclient::data;
using namespace scanners;
using namespace writer;

extern set<string> tableNames;

template<typename K, typename V>
class TableOperations {
public:
    /**
     * Table Operations constructur
     * @param creds credentials
     * @param instance instance to use for connection
     * @param table table name
     **/
    TableOperations(AuthInfo *creds, Instance *instance, string table);

    /**
      * Create a table. 
      * @param recreate will recreate a table if necessary
      * @return whether or not the table was created.
      **/
    void createTable(string table);

    /**
      * Creates a new scanner
      * @param auths authorizations for this scanner
      * @param threads current threads
      * @return new scanner
      **/
    virtual Source<K, V> *createScanner(Authorizations *auths,
                                        uint16_t threads) = 0;

    /**				
      * Creates a writer for the current table
      * @param auths authorizations for this writer
      * @param threads number of threads for writer
      * @return new batch writer
      */
    virtual Sink<K> *createWriter(Authorizations *auths,
                                  uint16_t threads) = 0;

    virtual ~TableOperations();

    /**
      * Returns the table ID
      * @return table ID
      **/
    virtual string getTableId() = 0;

    /**
      * Create a table. 
      * @param recreate will recreate a table if necessary
      * @return whether or not the table was created.
      **/
    virtual bool create(bool recreate=false) = 0;

    /**
      * Removes the current table
      * @return whether or not removal was successful.
      **/
    virtual bool remove() = 0;

    /**
      * Determines if the table exists.
      * @param createIfNot will create the table if true and it does not exist
      * @return returns boolean of whether or not the table exists
      **/
    virtual bool exists(bool createIfNot=false) = 0;
    
    /**
      * Sets a table property
      * @param property property names
      * @param value property value
      */
    virtual void setProperty(string property, string value) = 0;
    
    /**
      * Removes a property on this table.
      * @param property property name to remove
      */
    virtual void removeProperty(string property) = 0;
    
    
    /**
      * Returns all table properties.
      * @return table properties
      */
    virtual map<string,string> getProperties()=0;
    
    
    /**
     * Lists tables 
     * @return tables
     **/
    virtual set<string> listTables()
    {
      return tableNames;
    }

    /**
     * Gets user credentials
     * @return credentials
     **/
    AuthInfo *getCredentials() {
        return credentials;
    }
protected:

    // table mutex
    pthread_mutex_t tableOpMutex;
    // instance pointer
    Instance *myInstance;
    // credentials of the calling user
    AuthInfo *credentials;
    // current table id
    string tableId;
    // current table name
    string myTable;
};


extern map<string, string> cachedTableIds;

/**
  * Create a table. 
  * @param recreate will recreate a table if necessary
  * @return whether or not the table was created.
  **/
template<typename K, typename V>
void TableOperations<K, V>::createTable(string table) {

}
 /**
  * Table Operations constructur
  * @param creds credentials
  * @param instance instance to use for connection
  * @param table table name
  **/
template<typename K, typename V>
TableOperations<K, V>::TableOperations(AuthInfo *creds, Instance *instance,
                                       string table) :
    myInstance(instance), myTable(table), credentials(creds) {
    pthread_mutexattr_t Attr;

    pthread_mutexattr_init(&Attr);
    // make sure that the mutex is recursive
    pthread_mutexattr_settype(&Attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&tableOpMutex, &Attr);
}

template<typename K, typename V>
TableOperations<K, V>::~TableOperations() {
    
}
}
#endif /* SRC_INTERCONNECT_TABLEOPS_TABLEOPERATIONS_H_ */
