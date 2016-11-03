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
#ifndef BLOCKCOMPRESSEDFILE_H_
#define BLOCKCOMPRESSEDFILE_H_

#include "data_index.h"
#include "meta_index.h"
#include "block_comp_stream.h"
#include "../../compressor/compressor.h"
#include "../../../streaming/Streams.h"
#include "../../inputvalidation.h"
#include "../rfile_version.h"

// ... total of 16 bytes
static const uint8_t B_MAGIC_BCFILE[16] =
{   0xd1, 0x11, 0xd3, 0x68, 0x91, 0xb5, 0xd7, 0xb6, 0x39, 0xdf, 0x41, 0x40,
    0x92, 0xba, 0xe1, 0x50
};

namespace cclient
{
namespace data
{

using namespace compression;
using namespace cclient::data::streams;

class BlockCompressedFile : public StreamInterface
{
public:
    /**
     * Constructor accepts a compressor as the only argument
     * @param compressor our compressor for this BCFile
     */
    BlockCompressedFile (Compressor *compressor) :
        compressorRef (compressor)
    {
        version.setMajor (1);
        version.setMinor (0);
        dataIndex.setCompressionAlgorithm (compressor);

    }

    /**
     * Constructor accepts a compressor as the only argument
     * @param compressor our compressor for this BCFile
     */
    BlockCompressedFile (InputStream *in_stream, long fileLength) :
        in_stream (in_stream)
    {
        verifyStructure (fileLength);

    }

    void
    setDataIndex (DataIndex dataIndex)
    {
        this->dataIndex = dataIndex;
    }

    /**
     * Get the compressor. since it may be used
     * let's not set this function to constant
     * @returns compressor reference
     */
    Compressor *
    getCompressor ()
    {
        return compressorRef;
    }

    DataIndex *
    getDataIndex ()
    {

        return &dataIndex;
    }

    MetaIndex *
    getMetaIndex ()
    {
        return &metaIndex;
    }

    DataOutputStream *
    createCompressorStream (OutputStream *out, MetaIndexEntry *entry)
    {
        return new BlockCompressorStream (out, compressorRef,
                                          entry->getRegion ());
    }

    DataOutputStream *
    createDataStream (OutputStream *out)
    {
        return new BlockCompressorStream (out, compressorRef,
                                          dataIndex.addBlockRegion ());
    }

    MetaIndexEntry *
    prepareNewEntry (std::string name)
    {
        return metaIndex.prepareNewEntry (name, compressorRef);
    }

    uint64_t
    write (OutputStream *out)
    {

        out->writeBytes (B_MAGIC_BCFILE, 16);

        MetaIndexEntry *entry = metaIndex.prepareNewEntry ("BCFile.index",
                                compressorRef);

        BlockCompressorStream *blockStream = new BlockCompressorStream (
            out, compressorRef, entry->getRegion ());

        dataIndex.write (blockStream);
        blockStream->flush ();

        uint64_t offsetIndexMeta = out->getPos ();

        // should synchronize

        delete blockStream;

        metaIndex.write (out);
        out->writeLong (offsetIndexMeta);
        version.write (out);
        out->writeBytes (B_MAGIC_BCFILE, 16);
        //out->flush();
        return out->getPos ();
    }

    void
    close ()
    {

    }

protected:

    void
    verifyStructure (long fileLength)
    {
        const size_t magic_size = array_length (B_MAGIC_BCFILE);
        in_stream->seek (fileLength - magic_size - VERSION_SIZE);
        version.read (in_stream);
        uint8_t* magicVerify = new uint8_t[16];
        in_stream->readBytes (magicVerify, 16);
        if (memcmp (B_MAGIC_BCFILE, magicVerify, 16) != 0)
        {
            throw std::runtime_error ("Invalid Magic Number");
        }
        delete[] magicVerify;
        // get the index meta
        in_stream->seek (fileLength - magic_size - VERSION_SIZE - 8);
        offsetIndexMeta = in_stream->readLong ();


        in_stream->seek (offsetIndexMeta);

        metaIndex.read (in_stream);

        MetaIndexEntry *min = metaIndex.getEntry("BCFile.index");

        // should be using block comp stream?
        InputStream *dataIndexStream = min->readDataStream(in_stream);

        dataIndex.read (dataIndexStream);
        delete dataIndexStream;
    }

    Compressor *compressorRef;

    DataIndex dataIndex;
    MetaIndex metaIndex;
    RFileVersion version;

    // for reading
    InputStream *in_stream;
    uint64_t offsetIndexMeta;
};

}
}
#endif /* BLOCKCOMPRESSEDFILE_H_ */

