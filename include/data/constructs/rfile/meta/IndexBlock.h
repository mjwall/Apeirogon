/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2015
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
#ifndef INCLUDE_DATA_CONSTRUCTS_RFILE_META_INDEXBLOCK_H_
#define INCLUDE_DATA_CONSTRUCTS_RFILE_META_INDEXBLOCK_H_

#include "../../../streaming/OutputStream.h"
#include "../../../streaming/ByteOutputStream.h"
#include "../../../streaming/input/InputStream.h"
#include "../../../streaming/Streams.h"
#include "IndexEntry.h"
#include "SerializedIndex.h"
#include "KeyIndex.h"


#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setfill, std::setw
namespace cclient
{
namespace data
{
using namespace cclient::data::streams;

class IndexBlock : public StreamInterface
{
  protected:
    int level;
    int offset;
    int version;
    bool hasNext;

    SerializedIndex *index;
    uint8_t *serializedIndex;
    
    KeyIndex *keyIndex;

public:
    IndexBlock (int version) :
        level (0), offset (0), version (version), hasNext (false), index (
            NULL), serializedIndex (
                NULL), keyIndex (NULL)
    {

    }

    virtual
    ~IndexBlock ()
    {
        if (index != 0)
        {
            delete index;
        }
        if (serializedIndex != 0)
        {
            delete[] serializedIndex;
        }

        if (NULL != keyIndex)
        {
            delete keyIndex;
        }
    }

    SerializedIndex *
    getIndex ()
    {
        return index;
    }

    uint64_t
    read (InputStream *in)
    {
        if (version == 6 || version == 7)
        {
            level = in->readInt ();
            offset = in->readInt ();
            hasNext = in->readBoolean ();

            int numOffsets = in->readInt ();
            vector<int> offsets;
            offsets.reserve (numOffsets);

            for (int i = 0; i < numOffsets; i++)
            {
                offsets.push_back (in->readInt ());
            }

            int indexSize = in->readInt ();
            serializedIndex = new uint8_t[indexSize];
            in->readBytes (serializedIndex, indexSize);

            index = new SerializedIndex (offsets, serializedIndex, indexSize,
                                         true);
            keyIndex = new KeyIndex (offsets, serializedIndex, indexSize);
        }
        else if (version == 3)
        {
            level = 0;
            offset = 0;
            hasNext = false;
            int size = in->readInt ();

            ByteOutputStream *byteOutStream = new ByteOutputStream (0);
            DataOutputStream *outStream = new DataOutputStream (byteOutStream);
            vector<int> offsetList;
            for (int i = 0; i < size; i++)
            {
                IndexEntry entry;
                offsetList.push_back (byteOutStream->getSize ());
                entry.read (in);
                entry.write (outStream);

            }
            serializedIndex = new uint8_t[byteOutStream->getSize ()];
            byteOutStream->getByteArray ((char*) serializedIndex,
                                         byteOutStream->getSize ());
            delete outStream;
            delete byteOutStream;

            index = new SerializedIndex (offsetList, serializedIndex,
                                         byteOutStream->getSize (), false);
            keyIndex = new KeyIndex (offsetList, serializedIndex,
                                     byteOutStream->getSize ());

        }
        else if (version == 4)
        {
            level = 0;
            offset = 0;
            hasNext = false;

            int numIndexEntries = in->readInt ();


            vector<int> offsets;
            for (int i = 0; i < numIndexEntries; i++)
            {
                int offset = in->readInt();
                offsets.push_back (offset);
            }

            int size = in->readInt ();

            serializedIndex = new uint8_t[size];
            in->readBytes (serializedIndex, size);

            index = new SerializedIndex (offsets, serializedIndex, size, false);
            keyIndex = new KeyIndex (offsets, serializedIndex, size);
        }
        else
        {
            std::runtime_error ("Unexpected version");
        }

        return in->getPos ();
    }

    KeyIndex *
    getKeyIndex ()
    {
        return keyIndex;
    }

    int
    getLevel ()
    {
        return level;
    }

    int
    getOffset ()
    {
        return offset;
    }

    bool
    hasNextKey ()
    {
        return hasNext;
    }


}
;

}
}

#endif /* INCLUDE_DATA_CONSTRUCTS_RFILE_META_INDEXBLOCK_H_ */
