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

#ifndef R_KEY
#define R_KEY

#include "Key.h"
#include <stdint.h>

#include "../streaming/Streams.h"

#include <stdint.h>
#include <cstdio>
#include <vector>
#include <cstring>
#include <stdexcept>

namespace cclient
{
namespace data
{

using namespace cclient::data::streams;

/**
 * Based on the accumulo relative key.
 */
class RelativeKey : public StreamInterface
{

public:
    RelativeKey ();

    RelativeKey (Key *previous_key, Key *my_key);

    StreamInterface *
    getStream ();

    void
    setBase (Key *my_key);

    virtual uint64_t read(InputStream *in);

    void
    setPrevious (Key *previous_key);

    uint64_t
    write (OutputStream *outStream);

    bool
    operator < (const RelativeKey &rhs) const;

    bool
    operator < (const RelativeKey *rhs) const;

    ~RelativeKey ();

    // flags taken from java relative key
    static const uint8_t ROW_SAME = 0x01;
    static const uint8_t CF_SAME = 0x02;
    static const uint8_t CQ_SAME = 0x04;
    static const uint8_t CV_SAME = 0x08;
    static const uint8_t TS_SAME = 0x10;
    static const uint8_t DELETED = 0x20;

    static const uint8_t ROW_PREFIX = 0x01;
    static const uint8_t CF_PREFIX = 0x02;
    static const uint8_t CQ_PREFIX = 0x04;
    static const uint8_t CV_PREFIX = 0x08;
    static const uint8_t TS_DIFF = 0x10;

    static const uint8_t PREFIX_COMPRESSION_ENABLED = 128;
protected:

    void readPrefix (InputStream *stream, vector<char> *row, vector<char> *prevRow);

    bool
    readPrefix (InputStream *stream, int *comparison, uint8_t SAME_FIELD,
                uint8_t PREFIX, char fieldsSame,char fieldsPrefixed, vector<char> *field,
                vector<char> *prevField)
    {
        vector<char> tmp;

        //field->swap (*prevField);

        if ((fieldsSame & SAME_FIELD) != SAME_FIELD)
        {
            if ((fieldsPrefixed & PREFIX) == PREFIX)
            {
                readPrefix (stream, field, prevField);
            }
            else
            {
                read (stream, field);
            }
            return true;
        }
        else {
            //field->resize(prevField->size());
            field->insert(field->begin(),prevField->data (),prevField->data ()+prevField->size());
        }
        return false;
    }


    void
    read (InputStream *stream, vector<char> *row)
    {
        uint32_t len = stream->readEncodedLong();
        read (stream, row, len);
    }

    void
    read (InputStream *stream, vector<char> *input, uint32_t len)
    {
        char *array = new char[len];
        stream->readBytes (array, len);

        input->insert (input->begin (), array, array + len);
        delete[] array;
    }

    inline int
    commonPrefix (std::pair<char*, size_t> prev,
                  std::pair<char*, size_t> curr);

    inline void
    writePrefix (OutputStream *outStream, std::pair<char*, size_t> *var,
                 int commonPrefixLength)
    {
        // should be writevint, below
        outStream->writeVLong (commonPrefixLength);
        uint32_t remainder = var->second - commonPrefixLength;
        outStream->writeVLong (remainder);
        outStream->writeBytes (var->first + commonPrefixLength, remainder);

    }

    Key *key;

    char fieldsSame;

    Key *prevKey;

    void
    setKey (Key *keyToCopy, Key *keyToCopyTo);

    bool
    isSame (std::pair<char*, size_t> a, std::pair<char*, size_t> b);

    int32_t rowCommonPrefixLen;
    int32_t cfCommonPrefixLen;
    int32_t cqCommonPrefixLen;
    int32_t cvCommonPrefixLen;
    uint8_t fieldsPrefixed;
    long tsDiff;

};
}
}

#endif

