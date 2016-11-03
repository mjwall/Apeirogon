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

#include <iostream>
#include <sstream>
#include <assert.h>
using namespace std;
#include "../include/data/constructs/KeyValue.h"
#include "../include/data/constructs/security/Authorizations.h"
#include "../include/scanner/constructs/Results.h"
#include "../include/scanner/impl/Scanner.h"
#include "../include/data/constructs/client/zookeeperinstance.h"
#include "../include/interconnect/Master.h"
#include "../include/interconnect/tableOps/TableOperations.h"

#include "../include/data/constructs/rfile/RFile.h"
#include "../include/data/constructs/compressor/compressor.h"
#include "../include/data/constructs/compressor/zlibCompressor.h"

#include "../include/data/streaming/HdfsStream.h"

#define BOOST_IOSTREAMS_NO_LIB 1

using namespace cclient::data;
using namespace cclient::data::compression;
using namespace cclient::data::zookeeper;
using namespace cclient::data::streams;
using namespace interconnect;
using namespace scanners;
using namespace boost::iostreams;

bool
keyCompare (KeyValue* a, KeyValue* b)
{
	return *(a->getKey ()) < *(b->getKey ());
}

int
main (int argc, char **argv)
{

	struct hdfsBuilder *builder = hdfsNewBuilder ();
	if (argc < 6) {
		cout << "Arguments required: ./TableOps"
		     << " <instance name> <zks> <user> <password>"
		     << " <table>" << endl;
		exit (1);
	}

	string table = argv[5];

	std::shared_ptr<Configuration>  conf(new Configuration());
	conf->set ("FILE_SYSTEM_ROOT", "/accumulo");
	ZookeeperInstance *instance = new ZookeeperInstance (argv[1], argv[2], 1000,
	                conf);

	AuthInfo creds (argv[3], argv[4], instance->getInstanceId ());

	interconnect::MasterConnect *master = new MasterConnect (&creds, instance);

	TableOperations<KeyValue*, ResultBlock<KeyValue*>> *ops = master->tableOps (
	                        table);

	// create the table. no harm/no foul if it exists
	cout << "Checking if " << table << " exists." << endl;
	if (!ops->exists ()) {
		cout << "It does, so I am creating it." << endl;
		ops->create ();
	} else {
		cout << table << " already exists, not creating it" << endl;
	}


	cout << "Compacting table " << endl;
	((AccumuloTableOperations*)ops)->compact("a","z",false);

	NamespaceOperations *nameOps = master->namespaceOps();
	
	for(auto nm : nameOps->list())
	{
	  
	  cout << "found namespace " << nm << endl;
	}
	
	nameOps->create("testing");
	
	nameOps->rename("blahblah","testing");
	
	
	for(auto nm : nameOps->list())
	{
	  assert(nm != "testing");
	}
	
	nameOps->remove("blahblah");
	
	delete ops;
	hdfsFreeBuilder(builder);

	return 0;
}

