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

