/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * Key/value connector. Copyright (C)  2015
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

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
