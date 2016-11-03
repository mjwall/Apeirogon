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

#ifndef LOCALITYGROUPMETADATA_H_
#define LOCALITYGROUPMETADATA_H_

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stdexcept>

using namespace std;

#include "../../../streaming/ByteOutputStream.h"
#include "../../../streaming/NetworkOrderStream.h"
#include "../../../streaming/Streams.h"
#include "../../compressor/compressor.h"

#include "IndexManager.h"
#include "IndexEntry.h"

namespace cclient
{
namespace data
{
using namespace cclient::data::streams;
using namespace cclient::data::compression;

/**
 * Stores the locality group metadata
 */
class LocalityGroupMetaData : StreamInterface
{

public:
    /**
     Constructor
     @param starBlockVal start block value
     @param name The name of the locality group.

     **/
    LocalityGroupMetaData (uint32_t startBlockVal, std::string name = "");

    LocalityGroupMetaData (Compressor *compressorRef, int version,
                           InputStream *reader);

    ~LocalityGroupMetaData ();

    /**
     Sets the first key
     @param key incoming key to set.
     **/
    void
    setFirstKey (StreamInterface *key)
    {
        firstKey = key;
    }

    StreamInterface *
    getFirstKey ()
    {
        return firstKey;
    }

    uint32_t
    getStartBlock ()
    {
        return startBlock;
    }

    /**
     read function for the Locality Meta Data
     @param outStream output stream.
     @return position of output stream.
     **/
    uint64_t
    read (InputStream *in);

    /**
     write function for the Locality Meta Data
     @param outStream output stream.
     @return position of output stream.
     **/
    uint64_t
    write (DataOutputStream *outStream);

    /**
     Add the index entry to the meta data.
     @param ind incoming index entry.
     **/
    void
    addIndexEntry (IndexEntry ind)
    {
        index.push_back (ind);
    }

    LocalityGroupMetaData &
    operator= (const LocalityGroupMetaData &other)
    {
        startBlock = other.startBlock;
        firstKey = other.firstKey;
        offsets.insert (offsets.end (), other.offsets.begin (),
                        other.offsets.end ());

        columnFamilies = other.columnFamilies;

        return *this;
    }

    void
    setDefaultLG ()
    {
        isDefaultLG = true;

    }

    IndexManager *
    getIndexManager ()
    {
        return indexManager;
    }

protected:

    /**
     Build the index array of IndexEntry objects.
     @return std pair containing the array and the size
     of this array. note that this array is allocated within
     this function, therefore, the memory must be freed
     in the calling function.
     **/
    std::pair<char*, size_t>
    buildIndexArray ()
    {
        BigEndianByteStream *byteOutStream = new BigEndianByteStream (
            index.size () * 120);
        DataOutputStream *outputStream = new DataOutputStream (byteOutStream);
        //BigEndianOutStream outputStream(&byteOutStream);

        uint64_t totalPos = 0;
        uint32_t off = byteOutStream->getPos ();
        for (list<IndexEntry>::iterator it = index.begin (); it != index.end ();
                it++)
        {

            offsets.push_back (off);
            off = (*it).write (outputStream);
            totalPos += off;
        }

        char *arr = new char[off];

        memcpy (arr, byteOutStream->getByteArray (), off);
        delete byteOutStream;
        delete outputStream;
        return make_pair (arr, off);
    }
    // start block of this meta data group.
    uint32_t startBlock;
    // first key in the locality group.
    StreamInterface *firstKey;
    // region of index entry offsets.
    list<int> offsets;
    // column families for this locality group.
    map<std::pair<uint8_t *, size_t>, uint64_t> columnFamilies;
    // index entries.
    list<IndexEntry> index;

    Compressor *compressorRef;

    IndexManager *indexManager;
    // boolean value identifying this as the default locality group.
    bool isDefaultLG;
    // name of this locality group.
    std::string name;
};
}
}
#endif /* LOCALITYGROUPMETADATA_H_ */