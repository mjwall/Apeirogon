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
#ifndef HADOOP_DOUT_STREAM
#define HADOOP_DOUT_STREAM

#include <cstdint>

using namespace std;

#include "OutputStream.h"

namespace cclient {
namespace data {
namespace streams {

class HadoopDataOutputStream: public OutputStream {
public:


    HadoopDataOutputStream(OutputStream *out_stream)  : OutputStream(out_stream), output_stream_ref( out_stream )
    {

    }

    virtual ~HadoopDataOutputStream();
    virtual uint64_t getPos();
    uint64_t write(const char *bytes, long cnt);
    virtual uint64_t writeByte(int byte);
    virtual uint64_t writeString(string s);
    virtual uint64_t write(const uint8_t *bytes, long cnt);
    virtual uint64_t writeBytes(const uint8_t *bytes, size_t cnt);
    virtual uint64_t writeByte(const uint8_t byte);
    virtual uint64_t writeShort(const short shortVal);
    virtual uint64_t writeInt(const int intVal);
    virtual uint64_t writeLong(const uint64_t val);
    virtual uint64_t writeBoolean(const bool val);
    virtual uint64_t writeHadoopLong(const int64_t n);
    OutputStream* outputStream;

protected:
    // output stream reference.
    cclient::data::streams::OutputStream *output_stream_ref;

};
}
}
}
#endif
