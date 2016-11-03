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
#ifndef HADOOP_DIN_STREAM
#define HADOOP_DIN_STREAM

#include <iostream>
#include <stdexcept>
using namespace std;
#include "InputStream.h"

namespace cclient {
namespace data {
namespace streams {

/**
 * Hadoop input stream
 * Purpose: Meant to be interconnect to hadoop. based entirely on Hdfs JAVA code
 */
class HadoopDataInputStream: public InputStream {
public:

    HadoopDataInputStream(InputStream *out_stream) :
        InputStream(out_stream), input_stream_ref(out_stream) {

    }

    virtual ~HadoopDataInputStream() {

    }

    virtual InputStream *seek(uint64_t pos) {
        input_stream_ref->seek(pos);
        return this;
    }

    virtual uint64_t readBytes(const uint8_t *bytes, size_t cnt) {
        return input_stream_ref->readBytes((char*) bytes, cnt);
    }

protected:
    // output stream reference.
    InputStream *input_stream_ref;

};
}
}
}
#endif
