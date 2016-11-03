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

#include "../../../../../include/data/constructs/Key.h"
#include "../../../../../include/data/constructs/rfile/meta/LocalityGroupMetaData.h"
#include "../../../../../include/data/constructs/rfile/meta/../../../streaming/DataOutputStream.h"
using namespace cclient::data;

LocalityGroupMetaData::LocalityGroupMetaData (uint32_t startBlockVal,
        std::string name) :
    startBlock (startBlockVal), firstKey (NULL), indexManager (NULL)
{
    this->name = name;
    if (name == "")
    {
        isDefaultLG = true;
    }
    else
    {
        isDefaultLG = false;
    }
}

LocalityGroupMetaData::LocalityGroupMetaData (Compressor *compressorRef,
        int version, InputStream *reader) :
    firstKey (NULL), compressorRef (compressorRef)
{
    indexManager = new IndexManager (compressorRef, reader, version);
}

LocalityGroupMetaData::~LocalityGroupMetaData ()
{
    if (NULL != indexManager)
        delete indexManager;

    if (NULL != firstKey)
        delete firstKey;

    for (auto pair : columnFamilies)
    {
        delete[] pair.first.first;
    }

}
/**
 read function for the Locality Meta Data
 @param outStream output stream.
 @return position of output stream.
 **/
uint64_t
LocalityGroupMetaData::read (InputStream *in)
{
    isDefaultLG = in->readBoolean ();
    if (!isDefaultLG)
    {
        name = in->readString ();
    }

    startBlock = in->readInt ();

    int size = in->readInt ();


    if (size == -1)
    {
        if (!isDefaultLG)
            throw std::runtime_error ("Non default LG");

    }
    else
    {
        columnFamilies.clear ();
	
        for (int32_t i = 0; i < size; i++)
        {
            int len = in->readInt ();
            uint8_t *cf = new uint8_t[len];
            in->readBytes (cf, len);
            uint64_t count = in->readLong ();
            columnFamilies.insert (
                std::make_pair (std::make_pair (cf, len), count));
        }
    }

    if (in->readBoolean ())
    {
        firstKey = new Key ();

        firstKey->read (in);
    }
    else
    {
        firstKey = NULL;
    }

    indexManager->read (in);

    return in->getPos ();
}

/**
 write function for the Locality Meta Data
 @param outStream output stream.
 @return position of output stream.
 **/
uint64_t
LocalityGroupMetaData::write (DataOutputStream *outStream)
{

    outStream->writeBoolean (isDefaultLG);
    if (!isDefaultLG)
        outStream->writeString (name);

    outStream->writeInt (startBlock);
    // write a -1 indicating that we're writing
    // a default locality group.
    if (isDefaultLG)
    {
        outStream->writeInt (-1);

    }
    else
    {
        outStream->writeInt (columnFamilies.size ());
        // now write out columnFamilies
    }
    bool haveKey = (firstKey != NULL);
    outStream->writeBoolean (haveKey);
    if (haveKey)
        firstKey->write (outStream);
    // retrieved the encoded indices.
    std::pair<char*, size_t> indices = buildIndexArray ();

    outStream->writeInt (offsets.size ());

    for (list<int>::iterator it = offsets.begin (); it != offsets.end (); it++)
    {
        outStream->writeInt ((*it));
    }

    // write out the number of indices.
    outStream->writeInt (indices.second);

    uint64_t pos = outStream->writeBytes ((const uint8_t*) indices.first,
                                          indices.second);

    delete[] indices.first;

    return pos;

}
