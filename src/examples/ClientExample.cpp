/*
 * ClientExample.cpp
 *
 *  Created on: 4 Oct 2015
 *      Author: phrocker
 */

#include <iostream>
#include <sstream>
using namespace std;
#include "../include/data/constructs/KeyValue.h"
#include "../include/data/constructs/security/Authorizations.h"
#include "../include/scanner/constructs/Results.h"
#include "../include/scanner/impl/Scanner.h"
#include "../include/writer/impl/SinkImpl.h"
#include "../include/data/constructs/client/zookeeperinstance.h"
#include "../include/interconnect/Master.h"
#include "../include/interconnect/tableOps/TableOperations.h"
#include "../include/interconnect/securityOps/SecurityOperations.h"

#include "../include/data/constructs/rfile/RFile.h"
#include "../include/data/constructs/compressor/compressor.h"
#include "../include/data/constructs/compressor/zlibCompressor.h"

#include "../include/data/streaming/HdfsStream.h"

#include <assert.h>

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

std::pair<string, string>
writeRfile (string nameNode, uint16_t port)
{
	struct hdfsBuilder *builder = hdfsNewBuilder ();

	string dir = "/testImport/";
	string fail = "/testImportFail/";
	string path = dir;
	path.append ("test.rf");

	//set namenode address.
	hdfsBuilderSetNameNode (builder, nameNode.c_str ());

	//set namenode port.
	hdfsBuilderSetNameNodePort (builder, port);

	//connect to hdfs
	hdfsFS fs = hdfsBuilderConnect (builder);

	hdfsDelete (fs, dir.c_str (), 1);

	if (hdfsCreateDirectory (fs, dir.c_str ()) == -1) {
		cout << "Could not create directory " << dir << endl;
		exit (1);
	}

	hdfsDelete (fs, fail.c_str (), 1);

	if (hdfsCreateDirectory (fs, fail.c_str ()) == -1) {
		cout << "Could not create directory " << fail << endl;
		exit (1);
	}

	HdfsStream *stream = new HdfsStream (fs, path.c_str (), O_WRONLY | O_APPEND,
	                                     1024 * 5, 3, 1024 * 1024 * 1);

	Compressor *compressor = new ZLibCompressor (256 * 1024);

	BlockCompressedFile bcFile (compressor);

	EndianTranslationStream *outStream = new EndianTranslationStream (stream);

	RFile *newRFile = new RFile (outStream, &bcFile);

	vector<KeyValue*> keyValues;

	char rw[13], cf[3], cq[8], cv[8];
	int i = 0;

	string moto = "hello moto";
	string vis = "00000001";
	for (i = 1; i < 150; i++) {

		Value *v = new Value (moto);

		Key *k = new Key ();

		string rowSt = "2";

		memset (rw, 0x00, 13);
		sprintf (rw, "bat");

		k->setRow ((const char*) rw, 8);

		sprintf (cf, "%03d", i);

		k->setColFamily ((const char*) cf, 3);

		sprintf (cq, "%08d", i);
		sprintf (cv, "%08d", i);

		k->setColQualifier ((const char*) cq, 8);
		k->setColVisibility (vis.c_str (), vis.size ());

		k->setTimeStamp (1445105294261L);

		KeyValue *kv = new KeyValue ();

		kv->setKey (k);
		kv->setValue (v);

		keyValues.push_back (kv);
	}
	std::sort (keyValues.begin (), keyValues.end (), keyCompare);
	newRFile->addLocalityGroup ();
	for (std::vector<KeyValue*>::iterator it = keyValues.begin ();
	     it != keyValues.end (); ++it) {
		newRFile->append (*it);
	}

	newRFile->close ();



	outStream->flush ();
	stream->flush ();

	delete outStream;
	delete stream;

	delete newRFile;

	for (std::vector<KeyValue*>::iterator it = keyValues.begin ();
	     it != keyValues.end (); ++it) {
		delete (*it)->getKey ();
		delete (*it);
	}



	//free hdfs builder
	hdfsFreeBuilder (builder);
	dir = "/testImport/";
	fail = "/testImportFail/";
	stringstream nd;
	nd << nameNode << ":" << port << dir;
	path = nd.str();
	stringstream faildir;
	faildir << nameNode << ":" << port << fail;
	fail = faildir.str();
	return std::make_pair (path, fail);
}

int
main (int argc, char **argv)
{

	if (argc < 5) {
		cout << "Arguments required: ./ClientExample"
		     << " <instance name> <zks> <user> <password>"
		     << " <optional hdfsNN> <optional hdfsPort>" << endl;
		exit (1);
	}

	string nameNode = "";
	uint16_t nnPort = 0;
	if (argc == 6) {
		cout << "Arguments must contains namenode port" << endl;
		exit (1);
	} else if (argc == 7) {
		nameNode = argv[5];
		nnPort = atoi (argv[6]);
	}

	string table = "blah2";

	std::unique_ptr<Configuration>  conf(new Configuration());
	conf->set ("FILE_SYSTEM_ROOT", "/accumulo");
	
	ZookeeperInstance *instance = 0;
	
	try{
	instance = new ZookeeperInstance (argv[1], argv[2], 1000,
	                conf);
	}catch(ClientException ce)
	{
	  cout << "Could not connect to ZK. Error: " << ce.what()  << endl;
	  return 1;
	}

	AuthInfo creds (argv[3], argv[4], instance->getInstanceId ());

	interconnect::MasterConnect *master = 0;
	
	try{
	master = new MasterConnect (&creds, instance);
	}catch(ClientException ce)
	{
	  cout << "Could not connect: " << ce.what() << endl;
	  return 1;
	}
	
	AccumuloTableOperations *ops = dynamic_cast<AccumuloTableOperations*>(master->tableOps (
	                        table));
	
	SecurityOperations *secOps = master->securityOps();

	// create the table. no harm/no foul if it exists
	cout << "Checking if " << table << " exists." << endl;
	if (!ops->exists ()) {
		cout << "Now, creating " << table << endl;
		if (!ops->create ()) {
			cout << "Could not create table " << endl;
		}
		std::this_thread::sleep_for (std::chrono::milliseconds (1000));
	}





	Authorizations auths;
	
	Authorizations scanAuths;
	scanAuths.addAuthorization("00000001");
	
	if (secOps->createUser("dude","thedude"))
	{
	
	  // now let's drop the user
	
	  secOps->dropUser("dude");
	  
	}
	else
	  cout << "Could not create user 'dude'" << endl;
	
	secOps->grantAuthorizations(&scanAuths,"root");

	int fruit_to_write = 200;

	cout << "Writing " << fruit_to_write << " apples and bananas" << endl;

	BatchWriter *writer = dynamic_cast<BatchWriter*>(ops->createWriter (&auths, 1));

	for (int i = 0; i < fruit_to_write; i++) {

		KeyValue *newKv = new KeyValue ();
		Key *newKey = new Key ();
		newKey->setRow ("a", 1);
		newKey->setColFamily ("apple", 5);
		stringstream cq;
		cq << "banana" << i;
		newKey->setColQualifier (cq.str ().c_str (), cq.str ().length ());
		newKey->setTimeStamp(1445105294261L);
		newKv->setKey (newKey);
		newKv->setValue (new Value ());
		writer->push (newKv);
	}
	
	for (int i = 0; i < fruit_to_write; i++) {

		KeyValue *newKv = new KeyValue ();
		Key *newKey = new Key ();
		newKey->setRow ("a", 1);
		newKey->setColFamily ("avacado", 7);
		stringstream cq;
		cq << "banana" << i;
		newKey->setColQualifier (cq.str ().c_str (), cq.str ().length ());
		newKey->setTimeStamp(1445105294261L);
		newKv->setKey (newKey);
		newKv->setValue (new Value ());
		writer->push (newKv);
	}
	
	

	// close will free memory for objects given to it
	writer->close ();

	delete writer;

	if ( ops->flush("a","z",true) ) {
		cout << "flush successful " << endl;
	}


	if (((AccumuloTableOperations*) ops)->compact("a","z",true)) {
		cout << "Compaction successful " << endl;
	}
	

      //scan with 10 threads
      int counter = 0;
      try{
	cout << "Reading values from row a to d" << endl;
	Scanner *scanner =
	        dynamic_cast<Scanner*> (ops->createScanner (&scanAuths, 10));

	// range from a to d
	Key *startkey = new Key ();
	startkey->setRow ("a", 1);
	Key *stopKey = new Key ();
	stopKey->setRow ("z", 1);
	Range *range = new Range (startkey, true, stopKey, false);

	scanner->addRange (range);
	
	scanner->fetchColumn("avacado");

	Results<KeyValue*, ResultBlock<KeyValue*>> *results =
	                scanner->getResultSet ();

	
	
	for (auto iter = results->begin (); iter != results->end ();
	     iter++, counter++) {
		KeyValue *kv = *iter;

		if (kv != NULL && kv->getKey () != NULL)
			cout << "got -- " << (*iter)->getKey () << endl;
		else
			cout << "Key is null" << endl;
		delete kv;

	}

	delete range;
	delete scanner;
	}catch(ClientException ce)
	{
	  cout << "Failed message: " << ce.what() << endl;
	}

	cout << "Received " << counter << " results " << endl;
	if (counter >= 200)
	{
	  cout << "Removing table" << endl;
	
	  ops->remove ();
	}
	else
	{
	  cout << "did not get expected results. Please look into this" << endl;
	}

	delete ops;

	//assert(counter == fruit_to_write/2 );

	delete master;

	delete instance;

	return 0;
}

