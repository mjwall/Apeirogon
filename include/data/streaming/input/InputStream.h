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
#ifndef INPUT_INPUT_STREAM
#define INPUT_INPUT_STREAM

#include <cstring>
#include <cstdio>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace cclient
{
namespace data
{
namespace streams
{

/**
 * Input stream reference
 * Purpose: Meant to be generic interface for all inputstream types
 * Design: based explicitly on java implementation
 */
class InputStream
{
public:

    InputStream (istream *ptr, uint64_t pos) :
        istream_ref (ptr), position (new uint64_t (pos)), copy (false)
    {
    }

    InputStream () :
        istream_ref (NULL), position (new uint64_t (0)), copy (false)
    {

    }

    virtual void
    close ()
    {
    }

    virtual InputStream *
    seek (uint64_t pos)
    {
        istream_ref->seekg(pos);
        *position = pos;
        return this;
    }

    virtual
    ~InputStream ()
    {

        if (!copy)
            delete position;
    }

    virtual uint64_t
    getPos ()
    {
        return *position;
    }

    virtual string
    readString ()
    {
        // write size of string
        long vLong = readHadoopLong ();
        uint8_t *bytes = new uint8_t[vLong+1];
        memset(bytes,0x00,vLong+1);
        readBytes (bytes, vLong);
        //delete[] bytes;
        return string((char*)bytes);
    }

    virtual uint64_t
    readBytes (uint8_t *bytes, size_t cnt)
    {

        istream_ref->read ((char*) bytes, cnt);
        *position += cnt;
        return *position;
    }

    virtual uint64_t
    readBytes (char *bytes, size_t cnt)
    {

        istream_ref->read ((char*) bytes, cnt);
        *position += cnt;
        return *position;
    }

    virtual uint64_t
    readBytes (uint8_t **bytes, size_t cnt)
    {
        if (*bytes == NULL)
        {
            *bytes = new uint8_t[cnt];
        }
        return readBytes (*bytes, cnt);
    }

    virtual uint8_t
    readByte ()
    {
        uint8_t byte;
        readBytes ((uint8_t*) &byte, 1);
        //*position += 1;
        return byte;
    }

    virtual short
    readShort ()
    {
        //  memcpy(shortByte,shortVal,2);
        short shortVal;
        readBytes ((uint8_t*) &shortVal, 2);
        //  *position += 2;
        return shortVal;
    }

    virtual int
    readInt ()
    {
        int intVal = 0;
        readBytes ((uint8_t*) &intVal, 4);
        // *position += 4;
        return intVal;
    }

    virtual uint64_t
    readLong ()
    {
        uint64_t val;
        readBytes ((uint8_t*) &val, 8);
        // *position += 8;
        return val;
    }

    virtual uint64_t
    readBoolean ()
    {

        uint8_t byte = 0x00;
        ;
        readBytes ((uint8_t*) &byte, 1);
        //  *position += 1;
        if (byte)
            return 0x01;
        else
            return 0x00;
    }

    /**
     * Taken directly from accumulo code.
     */
    virtual int64_t
    readHadoopLong ()
    {
        int8_t firstByte = 0;

        firstByte = readByte ();

        if (firstByte >= -32)
        {
            return firstByte;
        }

        int len = firstByte + 129;
        switch ((firstByte + 128) / 8)
        {
        case 11:
        case 10:
        case 9:
        case 8:
        case 7:
            return ((firstByte + 52) << 8) | readByte ();
        case 6:
        case 5:
        case 4:
        case 3:
            return ((firstByte + 88) << 16) | readByte ();
        case 2:
        case 1:
            return ((firstByte + 112) << 24) | (readByte () << 8)
                   | readByte ();
        case 0:

            switch (len)
            {
            case 4:
                return readInt ();
            case 5:
                return ((long) readInt ()) << 8 | readByte ();
            case 6:
                return ((long) readInt ()) << 16 | readByte ();
            case 7:
                return ((long) readInt ()) << 24 | (readByte () << 8)
                       | readByte ();
            case 8:
                return readLong ();
            default:
                throw std::runtime_error ("Unsupported file type");
            }
            break;
        default:
            throw std::runtime_error ("Unsupported file type");
        }

    }

    long
    readEncodedLong ()
    {
        char firstByte = readByte ();
        int len =
            firstByte >= -112 ?
            1 : (firstByte < -120 ? -119 - firstByte : -111 - firstByte);
        if (len == 1)
            return firstByte;
        else
        {
            long i = 0L;
            for (int idx = 0; idx < len - 1; ++idx)
            {
                char b = readByte ();
                i <<= 8;
                i |= (long) (b & 255);
            }

            if (i < -120 || (i >= -112 && i < 0))
            {
                return ~i;
            }
            else
                return i;
        }

        /*
         int firstByte = readByte();
         if (firstByte >= -32) {
         return firstByte;
         }

         switch ((firstByte + 128) / 8) {
         case 11:
         case 10:
         case 9:
         case 8:
         case 7:
         return ((firstByte + 52) << 8) | readByte();
         case 6:
         case 5:
         case 4:
         case 3:
         return ((firstByte + 88) << 16) | readShort();
         case 2:
         case 1:
         return ((firstByte + 112) << 24) | (readShort() << 8) | readByte();
         case 0:
         int len = firstByte + 129;
         switch (len) {
         case 4:
         return readInt();
         case 5:
         return ((long) readInt()) << 8 | readByte();
         case 6:
         return ((long) readInt()) << 16 | readShort();
         case 7:
         return ((long) readInt()) << 24 | (readShort() << 8)
         | readByte();
         case 8:
         return readLong();
         default:
         throw std::runtime_error("Corrupted Encoded Long");
         }
         break;
         default:
         throw std::runtime_error("Internal Error");
         }
         */
    }
    /**
     * Bytes written shall always return the current position
     * of the stream ( this stream )
     * @returns stream position
     */
    virtual uint32_t
    bytesRead ()
    {

        return *position;
    }

    virtual uint64_t
    bytesAvailable ()
    {
        // by default, return the maximum
        return -1;
    }

protected:

    int
    numberOfLeadingZeros (uint64_t i)
    {
        // HD, Figure 5-6
        if (i == 0)
            return 64;
        int n = 1;
        int x = (int) (i >> 32);
        if (x == 0)
        {
            n += 32;
            x = (int) i;
        }
        if (x >> 16 == 0)
        {
            n += 16;
            x <<= 16;
        }
        if (x >> 24 == 0)
        {
            n += 8;
            x <<= 8;
        }
        if (x >> 28 == 0)
        {
            n += 4;
            x <<= 4;
        }
        if (x >> 30 == 0)
        {
            n += 2;
            x <<= 2;
        }
        n -= x >> 31;
        return n;
    }

    /**
     * Constructor, which is to be used by DataOutputStream. Note that it is
     * a friend class
     * @param ptr stream pointer
     */
    InputStream (InputStream *ptr) :
        istream_ref (ptr->istream_ref), position (ptr->position), copy (
            true)
    {

    }
    
    // ostream reference.
    istream *istream_ref;
    // position pointer.
    uint64_t *position;
    // identify that we have copied a stream
    // useful when deleting position
    bool copy;
    

};
}
}
}

#endif
