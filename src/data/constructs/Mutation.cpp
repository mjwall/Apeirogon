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

#include "../../../include/data/constructs/Mutation.h"
#include "../../../include/data/constructs/../streaming/ByteOutputStream.h"
#include "../../../include/data/constructs/../streaming/EndianTranslation.h"
namespace cclient
{

namespace data
{

using namespace cclient::data::streams;

Mutation::Mutation (string row) :
    mut_row (row), ptr (0), entries (0)
{
    outStream = new ByteOutputStream (1024);
    endianStream = new EndianTranslationStream (outStream);
    baseStream = new DataOutputStream (endianStream);
}

Mutation::~Mutation ()
{
    delete baseStream;
    delete outStream;
    delete endianStream;
}

void
Mutation::put (string cf, string cq, string cv, int64_t ts, bool deleted,
               uint8_t *value, uint64_t value_len)
{
    baseStream->writeVLong (cf.size ());
    //writeInt(cf.size());

    baseStream->write ((uint8_t*) cf.c_str (), cf.size ());
    //write((uint8_t*)cf.c_str(),cf.size());
    baseStream->writeVLong (cq.size ());
    //writeInt(cq.size());
    baseStream->write ((uint8_t*) cq.c_str (), cq.size ());
    //write((uint8_t*)cq.c_str(),cq.size());
    baseStream->writeVLong (cv.size ());
//	writeInt(cv.size());
    baseStream->write ((uint8_t*) cv.c_str (), cv.size ());
    //write((uint8_t*)cv.c_str(),cv.size());
    baseStream->writeBoolean (true);
    //write(true);
    baseStream->writeVLong (ts);
    //writeLong(ts);
    baseStream->writeBoolean (deleted);
    //write(false);
    baseStream->writeVLong (value_len);
    //writeInt(value_len);
    baseStream->write (value, value_len);
    //write(value,value_len);
    entries++;

}

void
Mutation::put (string cf, string cq, string cv, unsigned long ts)
{

}

}
}
