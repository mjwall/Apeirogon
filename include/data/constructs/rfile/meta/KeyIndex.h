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
#ifndef INCLUDE_DATA_CONSTRUCTS_RFILE_META_KEYINDEX_H_
#define INCLUDE_DATA_CONSTRUCTS_RFILE_META_KEYINDEX_H_

#include "../../../streaming/OutputStream.h"
#include "../../../streaming/input/InputStream.h"
#include "../../../streaming/input/ByteInputStream.h"
#include "../../../streaming/input/NetworkOrderInputStream.h"
#include "../../../streaming/Streams.h"
#include "IndexEntry.h"

namespace cclient
{
namespace data
{
using namespace cclient::data::streams;

class KeyIndex : StreamInterface
{
public:
    KeyIndex (vector<int> offsetList, uint8_t *datums, int dataLength) :
        newFormat (false), dataLength (
            dataLength)
    {
        offsets = new vector<int>();
        offsets->insert(offsets->end(),offsetList.begin(),offsetList.end());
        data = new uint8_t[dataLength];
        memcpy(data,datums,dataLength);
    }

    virtual
    ~KeyIndex ()
    {
        if (NULL != data)
        {
            delete[] data;
        }
        delete offsets;
    }


    Key *
    get (uint64_t index)
    {
        uint64_t len = 0;
        if (index == offsets->size () - 1)
        {
            len = dataLength - offsets->at (index);
        }
        else
        {
            len = offsets->at (index + 1) - offsets->at (index);
        }
        Key *returnKey = new Key ();

        EndianInputStream *inputStream = new EndianInputStream (
            (char*) data + offsets->at (index), len);
        returnKey->read (inputStream);
        delete inputStream;

        return returnKey;
    }

    int
    binary_search (Key *search_key)
    {
        return binary_search (0, offsets->size () - 1, search_key);
    }

    int
    binary_search (int first, int last, Key *search_key)
    {
        int index;

        if (first > last)
            index = -1;

        else
        {
            int mid = (first + last) / 2;

            Key *midKey = get (mid);
            if (*search_key == *midKey)
                index = mid;
            else

                if (*search_key < *midKey)
                    index = binary_search (first, mid - 1, search_key);
                else
                    index = binary_search (mid + 1, last, search_key);

        } // end if
        return index;
    } // end binarySearch

protected:
    int currentValue = 0;
    vector<int> *offsets;
    uint8_t *data;
    uint32_t dataLength;
    bool newFormat;
};

}
}

#endif /* INCLUDE_DATA_CONSTRUCTS_RFILE_META_KEYINDEX_H_ */
