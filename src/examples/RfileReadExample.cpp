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
#include <fstream>
#include <iostream>
#include <sstream>
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
#include "../include/data/streaming/OutputStream.h"

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

void
writeRfile (string outputFile,bool bigEndian, uint16_t port)
{
    struct hdfsBuilder *builder = hdfsNewBuilder ();

    std::ofstream ofs (outputFile.c_str(), std::ofstream::out);

    OutputStream *stream = new OutputStream(&ofs,0);

    if (bigEndian)
        stream = new EndianTranslationStream(stream);

    Compressor *compressor = new ZLibCompressor (256 * 1024);

    BlockCompressedFile bcFile (compressor);

// ByteOutputStream *outStream = new BigEndianByteStream (5 * 1024 * 1024,
//							 stream);
    RFile *newRFile = new RFile (stream, &bcFile);

    vector<KeyValue*> keyValues;

    char rw[13], cf[4], cq[9], cv[9];
    int i = 0;

    string moto = "hello moto";
    string vis = "00000001";
    for (i = 1; i < 25; i++)
    {

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
            it != keyValues.end (); ++it)
    {
        newRFile->append (*it);
    }

    stream->flush ();
    newRFile->close ();

    //outStream->flush ();


    //delete outStream;
    delete stream;

    delete newRFile;


    for (std::vector<KeyValue*>::iterator it = keyValues.begin ();
            it != keyValues.end (); ++it)
    {
        delete (*it)->getKey ();
        delete (*it);
    }






    //free hdfs builder
  hdfsFreeBuilder (builder);
// dir = "/testImport/";
    //fail = "/testImportFail/";
    //return std::make_pair (path, fail);
}

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}


void
readRfile (string outputFile, uint16_t port, bool bigEndian)
{
    struct hdfsBuilder *builder = hdfsNewBuilder ();

    std::ifstream ifs (outputFile.c_str(), std::ifstream::binary | std::ifstream::in);


    InputStream *stream = new InputStream(&ifs,0);

    if (bigEndian)
    {
        // stream = new EndianInputStream(stream);
    }


    std::fstream::pos_type size = filesize(outputFile.c_str());
    RFile *newRFile = new RFile (stream, size);
    std::vector<uint8_t*> cf;
    StreamSeekable *seekable = new StreamSeekable(new Range(),cf,false);


    newRFile->relocate(seekable);
    while (newRFile->hasNext())
    {
        cout << "has next " << (**newRFile).first <<  endl;

        newRFile->next();


        if (!newRFile->hasNext())
        {
            cout << "no next" << endl;
        }

    }





    cout << "we done" << endl;

    delete stream;

    delete newRFile;






    //free hdfs builder
  hdfsFreeBuilder (builder);
// dir = "/testImport/";
    //fail = "/testImportFail/";
    //return std::make_pair (path, fail);
}
int
main (int argc, char **argv)
{

    if (argc < 3)
    {
        cout << "Arguments required: ./RfileReadExample"
             << " <output file>" << endl;
        exit (1);
    }

    string outputFile = argv[1];

    string endian = argv[2];


    bool bigEndian = false;

    if (endian == "big" )
        bigEndian = true;
    if (!IsEmpty (&outputFile))
    {
        cout << "Writing test Rfile to " << outputFile << endl;
        writeRfile (outputFile, bigEndian, 0);
        if (bigEndian)
        {
            cout << "skipping read" << endl;
            //return 0;
        }
        cout << "Reading test rfile from " << outputFile << endl;
        readRfile(outputFile, 0 , bigEndian);
    }



    return 0;
}

