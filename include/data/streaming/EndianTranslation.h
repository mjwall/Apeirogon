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
#ifndef TRANSLATION_STREAM
#define TRANSLATION_STREAM

#include "DataOutputStream.h"
#include "HdfsOutputStream.h"
#include "OutputStream.h"

namespace cclient {
namespace data {
namespace streams {

class EndianTranslationStream: public HadoopDataOutputStream {
public:

    EndianTranslationStream(OutputStream *os) :
        HadoopDataOutputStream(os) {

    }

    uint64_t htonlw(uint64_t value);

    uint64_t writeShort(short shortVal);

    uint64_t writeInt(int intVal);

    uint64_t writeLong(uint64_t val);

};
}
}
}
#endif
