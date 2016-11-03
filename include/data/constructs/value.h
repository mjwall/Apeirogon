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

#ifndef VALUE_H
#define VALUE_H

#include <stdint.h>
#include <cstdio>
#include <cstring>
#include "../streaming/Streams.h"

namespace cclient {
namespace data {
using namespace cclient::data::streams;

/**
 * Purpose: basic value.
 *
 * Design: contains a byte array and an offset.
 * Based in design on accumulo value.
 */
class Value: public StreamInterface {
public:

    Value();

    Value(string val) {
        value=NULL;
        valueSize =0;
        offset=0;
        setValue((uint8_t*) val.c_str(), val.size());
    }

    virtual ~Value();

    void setValue(uint8_t *val, size_t size, uint32_t ptrOff = 0);

    void append(uint8_t *val, size_t size);

    void deepCopy(Value *v);

    uint8_t *data();

    size_t size();

    StreamInterface *getStream();

    std::pair<uint8_t*, size_t> getValue() const;

    uint64_t write(OutputStream *outStream);

    uint64_t read(InputStream *in);

    bool operator ==(const Value & rhs) const;

    bool operator !=(const Value &rhs) const;

private:

    // value array.
    uint8_t *value;
    // offset;
    uint16_t offset;
    // value size.
    size_t valueSize;
};
}
}

#endif
