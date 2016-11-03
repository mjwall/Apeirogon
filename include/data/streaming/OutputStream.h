/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2016
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
#ifndef OUTPUT_STREAM
#define OUTPUT_STREAM

#include <iostream>

#include <stdint.h>

using namespace std;

namespace cclient {
namespace data {
namespace streams {

class OutputStream {
public:

    OutputStream(ostream *ptr, uint64_t pos);

    OutputStream();

    virtual ~OutputStream();

    virtual void flush();

    virtual uint64_t getPos();

    virtual uint64_t write(const char *bytes, long cnt);

    virtual uint64_t writeByte(int byte);

    virtual uint64_t writeString(string s);

    virtual uint64_t write(const uint8_t *bytes, long cnt);

    virtual uint64_t writeBytes(const uint8_t *bytes, size_t cnt);

    virtual uint64_t writeBytes(const char *bytes, size_t cnt);

    virtual uint64_t writeByte(const uint8_t byte);

    virtual uint64_t writeShort(const short shortVal);

    virtual uint64_t writeInt(const int intVal);

    virtual uint64_t writeLong(const uint64_t val);

    virtual uint64_t writeVLong(const int64_t val);

    virtual uint64_t writeBoolean(const bool val);

    virtual uint64_t writeHadoopLong(const int64_t n = 0);

    virtual uint64_t writeEncodedLong(const int64_t n=0);

    virtual uint32_t bytesWritten();
    friend class HadoopDataOutputStream;
    friend class DataOutputStream;

protected:

    int numberOfLeadingZeros(uint64_t i) {
        // HD, Figure 5-6
        if (i == 0)
            return 64;
        int n = 1;
        unsigned int x = i >> 32;
        if (x == 0) {
            n += 32;
            x = (int) i;
        }
        if (x >> (unsigned int)16 == 0) {
            n += 16;
            x <<= 16;
        }
        if (x >> (unsigned int)24 == 0) {
            n += 8;
            x <<= 8;
        }
        if (x >> (unsigned int)28 == 0) {
            n += 4;
            x <<= 4;
        }
        if (x >> (unsigned int)30 == 0) {
            n += 2;
            x <<= 2;
        }
        n -= x >> (unsigned int)31;
        return n;
    }

    /**
     * Constructor, which is to be used by DataOutputStream. Note that it is
     * a friend class
     * @param ptr stream pointer
     */
    OutputStream(OutputStream *ptr) :
        ostream_ref(ptr == NULL ? NULL : ptr->ostream_ref), position(ptr == NULL ? 0 : ptr->position), copy(true) {

    }
     // ostream reference.
    ostream *ostream_ref;
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
