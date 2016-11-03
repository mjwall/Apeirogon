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
#ifndef ENDIAN_IN_STREAM
#define ENDIAN_IN_STREAM

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <netinet/in.h>
using namespace std;
#include "InputStream.h"
#include "ByteInputStream.h"

namespace cclient {
namespace data {
namespace streams {

/**
 * Purpose: converts all network ordered data into host ordered data
 * Meant to be used between thrift calls
 */
class EndianInputStream: public ByteInputStream {
public:

    EndianInputStream(InputStream *out_stream) :
        ByteInputStream(out_stream) {

    }

    EndianInputStream(char *byteArray, size_t len) :
        ByteInputStream(byteArray, len) {

    }

    EndianInputStream(char *byteArray, size_t len, bool allocated) :
        ByteInputStream(byteArray, len,allocated) {

    }

    EndianInputStream() : ByteInputStream()
    {
    }

    virtual ~EndianInputStream() {

    }

    short readShort() {
        return ntohs(ByteInputStream::readShort());
    }

    int readInt() {


        return ntohl(ByteInputStream::readInt());
    }

    uint64_t readLong() {
        return ntohl(ByteInputStream::readLong());
    }

};
}
}
}
#endif
