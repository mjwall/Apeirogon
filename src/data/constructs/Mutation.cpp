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
