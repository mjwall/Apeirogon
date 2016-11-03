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


std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}


void
readRfile (string outputFile, uint16_t port, bool dump)
{
    struct hdfsBuilder *builder = hdfsNewBuilder ();

    std::ifstream ifs (outputFile.c_str(), std::ifstream::binary | std::ifstream::in);


    InputStream *stream = new InputStream(&ifs,0);


    std::fstream::pos_type size = filesize(outputFile.c_str());
    cout << "tellg is " << size << endl;
    RFile *newRFile = new RFile (stream, size);

    cout << newRFile << endl;

    if (dump)
    {

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

    }

    cout << "we done" << endl;

    delete stream;

    delete newRFile;

    hdfsFreeBuilder(builder);

}
int
main (int argc, char **argv)
{

    if (argc < 2)
    {
        cout << "Arguments required: ./PrintInfo"
             << " <output file>" << endl;
        exit (1);
    }

    string inputFile = argv[1];

    bool dump = false;
    if (argc == 3)
    {
        if (!strcmp(argv[2],"-d") || !strcmp(argv[2],"dump"))
        {
            dump = true;
        }
    }

    if (!IsEmpty (&inputFile))
    {
        readRfile(inputFile, 0 , dump);
    }



    return 0;
}

