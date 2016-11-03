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
