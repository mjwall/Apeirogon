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

#ifndef META_INDEX_H_
#define META_INDEX_H_

#include <vector>
#include <map>
#include <cassert>
using namespace std;

#include "BlockRegion.h"

#include "../../compressor/algorithm.h"
#include "../../compressor/compression_algorithm.h"
#include "../../compressor/compressor.h"
#include "../../../streaming/Streams.h"
#include "../../../streaming/OutputStream.h"
#include "block_comp_stream.h"

using namespace cclient::data::compression;

namespace cclient
{
namespace data
{

using namespace cclient::data::streams;

class MetaIndexEntry : public StreamInterface
{
public:
    MetaIndexEntry () :
        metaName (""), comp (NULL)
    {

    }

    virtual
    ~MetaIndexEntry ()
    {

    }

    MetaIndexEntry (Compressor *compressor) :
        metaName (""), comp (compressor)
    {

    }

    MetaIndexEntry (InputStream *in)
    {
        read (in);
    }

    MetaIndexEntry (std::string metameta, BlockRegion reg) :
        metaName (metameta), compressionAlgo (
            (CompressionAlgorithm)reg.getCompressor ()->getAlgorithm ()), region (reg), comp (
                NULL)
    {

    }

    InputStream *
    readDataStream (InputStream *in)
    {
        comp = compressionAlgo.create ();
        /*

        uint64_t prevPosition = in->getPos();



        in->seek (region.getOffset ());

        uint8_t *compressedValue = new uint8_t[region.getCompressedSize ()];

        in->readBytes (compressedValue, region.getCompressedSize ());

        comp->setInput ((const char*) compressedValue, 0,
        		region.getCompressedSize ());

        ByteOutputStream *outStream = new ByteOutputStream (
            region.getRawSize ());

        comp->decompress (outStream);

        ByteInputStream *returnStream = new ByteInputStream (
            outStream->getByteArray (), outStream->getSize (), true);

        // reset the location

        in->seek(prevPosition);

        delete[] compressedValue;

        delete outStream;

        return returnStream;*/
        uint64_t prevPosition = in->getPos();
	assert(prevPosition > 0);
        return new BlockCompressorStream(in,comp,&region);
    }

    uint64_t
    read (InputStream *in)
    {
        string fullMetaName = in->readString ();

        if (fullMetaName.at (0) == 'd' && fullMetaName.at (4) == ':')
        {
            metaName = fullMetaName.substr (5);
        }
        else
        {

            throw std::runtime_error ("Corrupted Meta region Index");
        }
        compressionAlgo = CompressionAlgorithm (in->readString ());

        region.read (in);
        return in->getPos ();

    }

    uint64_t
    write (OutputStream *out)
    {

        std::string writeString = "data:";
        writeString.append (metaName);

        out->writeString (writeString);
        out->writeString (compressionAlgo.getName ());
        return region.write (out);
    }

    std::string
    getMetaName ()
    {

        return metaName;
    }

    MetaIndexEntry &
    operator= (const MetaIndexEntry &other)
    {
        metaName = other.metaName;
        compressionAlgo = other.compressionAlgo;
        region = other.region;

        if (other.comp != NULL)
        {

            comp = other.comp;
        }

        return *this;
    }

    BlockRegion *
    getRegion ()
    {
        return &region;
    }

    void
    setName (std::string name)
    {
        metaName = name;
    }

    void
    setAlgorithm (CompressionAlgorithm algo)
    {

        compressionAlgo = algo;
    }

    void
    setBlockRegion (BlockRegion reg)
    {

        region = reg;
    }

protected:
    std::string metaName;
    CompressionAlgorithm compressionAlgo;
    BlockRegion region;
    Compressor *comp;
};

/**
 * Meta Indices can be thought of as meta entries for all index entries
 * The index entries contain the BlockRegion, which are the compressed
 * regions for the particular entry we are describing.
 */
class MetaIndex : public StreamInterface
{
public:

    MetaIndex ();

    virtual
    ~MetaIndex ();

    /**
     * Adds an entry to the Meta Index
     * @param indexEntry the Meta Index entry
     * @param out output stream, from which we gather the region
     * offset
     */
    void
    addEntry (MetaIndexEntry indexEntry, DataOutputStream *out)
    {
        index[indexEntry.getMetaName ()] = indexEntry;
        BlockRegion *region = index[indexEntry.getMetaName ()].getRegion ();
        if (out != NULL)
        {
            region->setOffset (out->getPos ());
        }
    }

    /**
     * Returns the entry associatd with the given name.
     * @param name name of entry we wish to retrieve
     * @returns MetaIndexEntry pointer. Not constant as we may
     * wish, and are allowed, to modify the index Entry. Note
     * that this may return null.
     */
    MetaIndexEntry *
    getEntry (const std::string name)
    {
        return &index[name];
    }

    /**
     * Prepares a new MetaIndexEntry for this meta index table.
     * @param name name of index entry
     * @param comp compressor. not constant as this will eventually
     * be used for modifications and compression ( thus potentially
     * modifying the internals of the compressor )
     * @returns newly allocated MetaIndexEntry
     */
    MetaIndexEntry *
    prepareNewEntry (const std::string name, Compressor *comp)
    {

        MetaIndexEntry entry (comp);
        entry.setName (name);
        entry.setAlgorithm (comp->getAlgorithm ());
        addEntry (entry, NULL);
        return getEntry (name);

    }

    uint64_t
    read (InputStream *in)
    {
        //uint32_t count = in->readEnc
        uint64_t count = in->readHadoopLong ();

        for (uint64_t i = 0; i < count; i++)
        {
            MetaIndexEntry entry (in);

            index.insert (std::make_pair (entry.getMetaName (), entry));
        }

        return in->getPos ();
    }

    /**
     * @Override
     */
    uint64_t
    write (OutputStream *out)
    {

        out->writeEncodedLong (index.size ());
        // write out all the meta index entries
        for (map<std::string, MetaIndexEntry>::iterator it = index.begin ();
                it != index.end (); it++)
        {

            (*it).second.write (out);
        }
        return out->getPos ();
    }

    map<std::string, MetaIndexEntry> *getEntries()
    {
        return &index;
    }

protected:
    // meta index map. This will map the names of those
    // meta index entries to the entries.
    map<std::string, MetaIndexEntry> index;

};
}
}
#endif /* META_INDEX_H_ */
