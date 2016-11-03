#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;
#include <netinet/in.h>
#include <stdint.h>
#include "../../include/data/constructs/compressor/compressor.h"
#include "../../include/data/constructs/compressor/zlibCompressor.h"
#include "../../include/data/constructs/../extern/cpp-btree/btree.h"
#include "../../include/data/constructs/../streaming/HdfsStream.h"
#include "../../include/data/constructs/rfile/RFile.h"

#include "../../include/data/constructs/Key.h"
#include "../../include/data/constructs/value.h"
#include "../../include/data/constructs/KeyValue.h"
#include "../../include/data/constructs/rkey.h"
#include <sys/time.h>
//#include <snappy.h>

#include <hdfs/hdfs.h>

using namespace cclient::data;
using namespace cclient::data::streams;

#define CATCH_CONFIG_MAIN

#define NUMBER 50000
#include "../catch.hpp"


/**
 * This test simply verifies that an RFile can be created.
 * It must be verified externally
 */


std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

TEST_CASE("Create rfile", "[CreateRfile]") {
	for (int j = 0; j < 1; j++) {


		 struct hdfsBuilder *builder = hdfsNewBuilder ();

		std::ofstream ofs ("/tmp/test.rf", std::ofstream::out);

		OutputStream *stream = new OutputStream(&ofs,0);


//		fstream fileStream("/test.rf",
	//			fstream::in | fstream::out | fstream::trunc);

		Compressor *compressor = new ZLibCompressor(256*1024);

		BlockCompressedFile bcFile(compressor);

		ByteOutputStream *outStream = new BigEndianByteStream(250 * 1024 * 1024,stream);
		RFile *newRFile = new RFile(outStream, &bcFile);

		set<KeyValue*> keyValues;

		Key *prevKey = NULL;
		struct timeval start, end;
		long mtime, seconds, useconds;

		char rw[13], cf[9], cq[9], cv[9];
		int i = 0;
		for (i = 0; i < NUMBER; i++) {

			Key *k = new Key();
			Value v;
			string rowSt = "2";

			memset(rw, 0x00, 13);
			sprintf(rw, "%08d", i);

			k->setRow((const char*) rw, 8);

			sprintf(cf, "%03d", i);

			k->setColFamily((const char*)  cf, 3);

			sprintf(cq, "%08d", i);
			sprintf(cv, "%08d", i);

			k->setColQualifier((const char*)  cq, 8);
			k->setColVisibility((const char*)  cv, 8);

			KeyValue *kv = new KeyValue();


			kv->setKey(k,true);
			kv->setValue(&v);

			keyValues.insert(kv);
			prevKey = k;
		}
		cout << "Time to actually insert " << i << endl;
		gettimeofday(&start, NULL);
		newRFile->addLocalityGroup();
		for(std::set<KeyValue*>::iterator it = keyValues.begin(); it != keyValues.end(); ++it)
		{
			newRFile->append(*it);
		}


		newRFile->close();
		
		
		for(std::set<KeyValue*>::iterator it = keyValues.begin(); it != keyValues.end(); ++it)
		{
			delete *it;
		}
		

		gettimeofday(&end, NULL);

		delete outStream;

		seconds = end.tv_sec - start.tv_sec;
		useconds = end.tv_usec - start.tv_usec;

		mtime = ((seconds) * 1000 + useconds / 1000.0) + 0.5;
		cout << "Elapsed Time: " << mtime << " milliseconds" << endl;
		delete newRFile;
		delete stream;

		//free hdfs builder
		hdfsFreeBuilder(builder);
	}

}
