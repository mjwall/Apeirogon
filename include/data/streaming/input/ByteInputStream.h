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

#ifndef BYTE_IN_STREAM
#define BYTE_IN_STREAM

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <cstring>
using namespace std;
#include "InputStream.h"

namespace cclient
{
namespace data
{
namespace streams
{

class ByteInputStream : public InputStream
{
public:

    ByteInputStream (InputStream *out_stream) :
        InputStream (out_stream), input_stream_ref (out_stream), allocated (
            false)
    {
        length = 0;
        offset = 0;
    }

    ByteInputStream (char *byteArray, size_t len) :
        allocated (false), input_stream_ref (NULL)
    {
        iBytes = byteArray;
        length = len;
        offset = 0;

    }

    ByteInputStream() : input_stream_ref(NULL), allocated(false)
    {
    }

    ByteInputStream (char *byteArray, size_t len, bool allocate) :
        input_stream_ref (NULL)
    {
        if (allocate)
        {
            allocated = true;
            iBytes = new char[len];
            memcpy (iBytes, byteArray, len);
        }
        else
        {
            iBytes = byteArray; //new char[ len ];
        }
        //memcpy(iBytes,byteArray,len);
        length = len;
        offset = 0;

    }

    void setArray(char *byteArray, size_t len, bool allocate)
    {

        if (allocate)
        {
            allocated = true;
            iBytes = new char[len];
            memcpy (iBytes, byteArray, len);
        }
        else
        {
            iBytes = byteArray; //new char[ len ];
        }
        //memcpy(iBytes,byteArray,len);
        length = len;
        offset = 0;
    }

    virtual
    ~ByteInputStream ()
    {
        if (allocated)
            delete[] iBytes;
    }

    virtual InputStream *
    seek (uint64_t pos)
    {
        if (NULL != input_stream_ref)
            input_stream_ref->seek (pos);
        return this;
    }

    virtual uint64_t
    readBytes (uint8_t *bytes, size_t cnt)
    {
        if (input_stream_ref  != NULL)
        {
            return input_stream_ref->readBytes(bytes,cnt);
            offset+=cnt;
        }

        if ((cnt + offset) > length)
            throw runtime_error ("Stream unavailable");
        memcpy (bytes, iBytes + offset, cnt);
        offset += cnt;
        return cnt;
    }

    virtual uint64_t
    readBytes (char *bytes, size_t cnt)
    {
        if (input_stream_ref  != NULL)
        {
            return input_stream_ref->readBytes(bytes,cnt);
            offset+=cnt;
        }
        if ((cnt + offset) > length)
            throw runtime_error ("Stream unavailable");
        memcpy (bytes, iBytes + offset, cnt);
        offset += cnt;
        return cnt;
    }

    virtual uint64_t
    bytesAvailable ()
    {
        return (length - offset);
    }

protected:
    // output stream reference.
    InputStream *input_stream_ref;
    bool allocated;
    uint64_t length;
    uint32_t offset;
    char *iBytes;

    

   

};
}
}
}
#endif
