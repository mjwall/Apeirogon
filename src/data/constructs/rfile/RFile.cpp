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

#include "../../../../include/data/streaming/input/NetworkOrderInputStream.h"
#include "../../../../include/data/constructs/rfile/RFile.h"

using namespace cclient::data;
using namespace cclient::data::streams;

RFile::RFile (OutputStream *output_stream, BlockCompressedFile *bWriter) :
    out_stream (output_stream), blockWriter (bWriter), dataClosed (false), currentBlockWriter (
        NULL), closed (false), dataBlockCnt (0), entries (0), currentLocalityGroup (
            NULL)
{
    if (output_stream == NULL || bWriter == NULL)
    {
        throw std::runtime_error (
            "Output Stream and BC File Writer should not be NULL");
    }

    compressorRef = bWriter->getCompressor ();

    maxBlockSize = compressorRef->getBufferSize () * 8;

    myDataStream = output_stream;

    lastKeyValue = NULL;
}

RFile::RFile (InputStream *input_stream, long fileLength) :
    in_stream (input_stream), dataClosed (false), currentBlockWriter (
        NULL), closed (false), dataBlockCnt (0), entries (0), currentLocalityGroup (
            NULL)
{
    if (input_stream == NULL)
    {
        throw std::runtime_error (
            "InputSTream Stream and BC Reader Writer should not be NULL");
    }

    maxBlockSize = 128*1024;

    myInputStream = input_stream;

    lastKeyValue = NULL;

    blockWriter = new BlockCompressedFile (in_stream, fileLength);
    cout << "open rfile index" << endl;
    InputStream *metaBlock = blockWriter->getMetaIndex ()->getEntry (
                                 "RFile.index")->readDataStream (in_stream);
    cout << " have meta block" << endl;
    readLocalityGroups (metaBlock);

    delete metaBlock;

}

void
RFile::readLocalityGroups (InputStream *metaBlock)
{
    //EndianInputStream *endian = new EndianInputStream(metaBlock);
    int magic = metaBlock->readInt ();

    int version = metaBlock->readInt ();

    cout << "magic number is " << magic << " " << MAGIC_NUMBER2 << endl;
    if (magic != MAGIC_NUMBER && magic != MAGIC_NUMBER2)
        throw std::runtime_error ("Did not see expected magic number");
    cout << "version is " << version << endl;
    switch (version)
    {
    case RFILE_VERSION:
    case RFILE_VERSION_3:
    case RFILE_VERSION_6:
    case RFILE_VERSION_7:
        break;
    default:
        throw std::runtime_error ("Did not see expected magic number");
    };

    int size = metaBlock->readInt ();



    localityGroups.resize (size);
    cout << "reading " << size << " locality groups" << endl;
    for (int i = 0; i < size; i++)
    {
        LocalityGroupMetaData *meatadata = new LocalityGroupMetaData (
            compressorRef, version, in_stream);
        meatadata->read(metaBlock);
        localityGroups.push_back (meatadata);
        localityGroupReaders.push_back (
            new LocalityGroupReader (blockWriter, in_stream, meatadata, version));

    }

    currentLocalityGroupReader = localityGroupReaders.front();

}

RFile::~RFile ()
{

}

bool
RFile::append (KeyValue *kv)
{
    if (dataClosed || closed)
        throw std::runtime_error ("Appending data failed, data block closed");

    if (currentLocalityGroup->getFirstKey () == NULL)
    {
        StreamInterface *firstKey = kv->getKey ();
        // set the first key for the current locality group.
        setCurrentLocalityKey (firstKey);
    }

    Key *prevKey = NULL;
    if (NULL != lastKeyValue)
    {
        prevKey = lastKeyValue->getKey ();
    }
    RelativeKey *key = new RelativeKey (prevKey, kv->getKey ());

    if (NULL == currentBlockWriter)
    {

        currentBlockWriter =
            (BlockCompressorStream*) blockWriter->createDataStream (myDataStream);
        currentBlockCount = 0;
    }

    entries++;
    currentBlockCount++;
    key->write (currentBlockWriter);
    uint64_t position = kv->getValue ()->write (currentBlockWriter);

    lastKeyValue = kv;
    // we've written all we can write doctor.
    if (position >= maxBlockSize)
    {
        currentBlockWriter->flush ();
        closeBlock (kv);

        delete currentBlockWriter;
        currentBlockWriter = NULL;
    }

    delete key;
    
    return true;

}

bool
RFile::append (vector<StreamInterface*> *keyValues, uint32_t average_recordSize,
               bool isSorted)
{

    if (dataClosed || closed)
        throw std::runtime_error ("Appending data failed, data block closed");

    if (keyValues == NULL || keyValues->size () == 0)
        return false;

    uint32_t recordIncrement = (maxBlockSize / average_recordSize);

    StreamInterface *key;
    StreamInterface *firstKey = NULL;
    firstKey = keyValues->at (0)->getStream ();
    // set the first key for the current locality group.
    setCurrentLocalityKey (firstKey);

    uint64_t j = 0;
    for (uint64_t i = 0; i < keyValues->size (); i += (j - i))
    {
        currentBlockWriter =
            (BlockCompressorStream*) blockWriter->createDataStream (myDataStream);
        for (j = i; j < keyValues->size () && j < (i + recordIncrement); j++)
        {
            keyValues->at (j)->write (currentBlockWriter);
            entries++;
        }
        currentBlockWriter->flush ();
        closeBlock (keyValues->at (j - 1)->getStream ());

        delete currentBlockWriter;
        currentBlockWriter = NULL;
    }

    if (currentBlockWriter != NULL)
    {
        currentBlockWriter->flush ();
        delete currentBlockWriter;
    }
    key = keyValues->back ()->getStream ();
    closeBlock (key);

    return true;

}

void
RFile::close ()
{
    closeData ();

    // create  new compression stream.

    BlockCompressorStream *outStream =
        (BlockCompressorStream*) blockWriter->createCompressorStream (
            myDataStream, blockWriter->prepareNewEntry ("RFile.index"));
    // prepare the RFile Index.

    MetaBlock block;
    closeCurrentGroup ();
    block.addLocalityGroups (localityGroups);
    block.write (outStream);
    outStream->flush ();
    blockWriter->write (myDataStream);
    blockWriter->close ();

    delete outStream;
    closed = true;
}
