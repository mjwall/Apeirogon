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

#ifndef INDEXMANAGER_H_
#define INDEXMANAGER_H_

#include "../../../streaming/OutputStream.h"
#include "../../../streaming/input/InputStream.h"
#include "../../../streaming/input/NetworkOrderInputStream.h"
#include "../../../streaming/Streams.h"

#include "../../compressor/compressor.h"
#include "SerializedIndex.h"
#include "IndexEntry.h"
#include "IndexBlock.h"
#include "BlockLookup.h"
#include "Block.h"
#include "../../Key.h"
namespace cclient
{
namespace data
{
using namespace cclient::data::streams;
using namespace cclient::data::compression;
using namespace cclient::data;

class IndexManager : public BlockLookup, public StreamInterface
{
public:
    IndexManager (Compressor *compressorRef, InputStream *blockReader,
                  int version);

    virtual
    ~IndexManager ()
    {
        if (NULL != indexBlock)
        {
            delete indexBlock;
        }
    }
    uint64_t
    read (InputStream *in);

    SerializedIndex *
    lookup (Key *key)
    {
        Block *block = new Block (this, indexBlock);
        SerializedIndex *index = new SerializedIndex (block,block->lookup (key));

        return index;
    }

    int
    getSize ()
    {
        return size;
    }

    IndexBlock *
    getIndexBlock (IndexEntry *ie)
    {

        blockReader->seek (ie->getOffset ());

        uint8_t *compressedValue = new uint8_t[ie->getCompressedSize ()];

        blockReader->readBytes (compressedValue, ie->getCompressedSize ());

        compressorRef->setInput ((const char*) compressedValue, 0,
                                 ie->getCompressedSize ());

        ByteOutputStream *outStream = new ByteOutputStream (ie->getRawSize ());

        compressorRef->decompress (outStream);

        EndianInputStream *returnStream = new EndianInputStream (
            outStream->getByteArray (), outStream->getSize (), true);

        delete outStream;

        IndexBlock *block = new IndexBlock (version);
        block->read (returnStream);

        delete returnStream;

        return block;

    }
protected:
    int size = 0;
    int version;
    InputStream *blockReader;
    Compressor *compressorRef;
    IndexBlock *indexBlock;

};

}
}

#endif
