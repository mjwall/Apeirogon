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
#ifndef DATA_WRITER
#define DATA_WRITER

#include <string>
#include <iostream>
#include <cstring>
using namespace std;

#include <stdint.h>
#include <netinet/in.h>

#include "input/InputStream.h"

#include "OutputStream.h"
#include "DataOutputStream.h"
#include "HdfsOutputStream.h"

namespace cclient {
namespace data {
namespace streams {

class StreamInterface {
public:

    StreamInterface();
    virtual ~StreamInterface();

    virtual StreamInterface *getStream();

    virtual uint64_t write(OutputStream *out);
    virtual uint64_t read(InputStream *in);

    virtual DataOutputStream *createDataStream(
        DataOutputStream *out,
        string name = "") {
        return NULL;
    }

};
}
}
}

#endif

