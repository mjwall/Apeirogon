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
#ifndef BLOCKREGION_H_
#define BLOCKREGION_H_

#include "../../compressor/compressor.h"

#include "../../../streaming/Streams.h"
#include "../../../streaming/ByteOutputStream.h"
#include "../../../streaming/input/ByteInputStream.h"
#include "../../../streaming/input/NetworkOrderInputStream.h"

namespace cclient
{
namespace data
{

using namespace compression;
using namespace cclient::data::streams;

class BlockRegion : public StreamInterface
{
public:
    BlockRegion () :
        offset (0), compressedSize (0), rawSize (0), compressor (NULL)
    {

    }

    BlockRegion (uint64_t offset, uint64_t compressedSize, uint64_t rawSize,
                 Compressor *compressor) :
        offset (offset), compressedSize (compressedSize), rawSize (rawSize), compressor (
            compressor)
    {

    }

    BlockRegion (InputStream *in)
    {
        read (in);
    }
    /**
     Copy constructor.
     @param object from which we copy our items.
     **/
    BlockRegion (const BlockRegion &copy)
    {

        *this = copy;
    }

    virtual ~BlockRegion() {

        delete compressor;
    }

    /**
     sets of the offset.
     @param off offset.
     **/
    void
    setOffset (uint32_t off)
    {
        offset = off;
    }

    /**
     Sets the compressed size
     @param csize compressed size.
     **/
    void
    setCompressedSize (uint32_t csize)
    {
        compressedSize = csize;
    }

    /**
     Sets the raw size
     **/
    void
    setRawSize (uint32_t rsize)
    {
        rawSize = rsize;
    }

    /**
     Sets the compressor
     @param comp compressor.
     **/
    void
    setCompressor (Compressor *comp)
    {
        compressor = comp;
    }

    /**
     * Returns the reference to the compressor
     * Should not be constant as compressor could be used
     * and subsequently the internal components could be modified
     * @returns compressor reference
     */
    Compressor *
    getCompressor ()
    {
        return compressor;
    }
    uint64_t
    read (InputStream *in);

    uint64_t
    write (OutputStream *out);

    InputStream *
    readDataStream (InputStream *in)
    {

        uint64_t pos = in->getPos();


        in->seek (offset);

        uint8_t *compressedValue = new uint8_t[compressedSize];

        in->readBytes (compressedValue, compressedSize);


        compressor->setInput ((const char*) compressedValue, 0, compressedSize);

        ByteOutputStream *outStream = new ByteOutputStream (rawSize);

        compressor->decompress (outStream);


        EndianInputStream *returnStream = new EndianInputStream (
            outStream->getByteArray (), outStream->getSize (), true);

        in->seek(pos);
        delete[] compressedValue;
        delete outStream;

        return returnStream;
    }

    BlockRegion &
    operator= (const BlockRegion &other)
    {

        offset = other.offset;
        compressedSize = other.compressedSize;
        rawSize = other.rawSize;
        compressor = other.compressor;
        return *this;
    }

    uint32_t
    getOffset ()
    {
        return offset;
    }

    uint32_t
    getCompressedSize ()
    {
        return compressedSize;
    }

    uint32_t
    getRawSize ()
    {
        return rawSize;
    }

protected:
    // compressor.
    Compressor *compressor;
    // offset.
    uint32_t offset;
    // compressed size.
    uint32_t compressedSize;
    // raw size.
    uint32_t rawSize;
};
}
}
#endif /* BLOCKREGION_H_ */
