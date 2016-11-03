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

#include <map>
#include <algorithm>
using namespace std;
#include "../../../include/data/client/TabletLocationObtainer.h"

#include "../../../include/data/client/../constructs/Key.h"
#include "../../../include/data/client/../constructs/value.h"
#include "../../../include/data/client/../streaming/input/NetworkOrderInputStream.h"

namespace cclient
{
namespace impl
{

using namespace cclient::data;
using namespace cclient::data::streams;

TabletLocationObtainer::TabletLocationObtainer ()
{
    // TODO Auto-generated constructor stub

}

TabletLocationObtainer::~TabletLocationObtainer ()
{
    // TODO Auto-generated destructor stub
}

map<Key*, Value*, pointer_comparator<Key*>>
        TabletLocationObtainer::decodeResults (vector<KeyValue*> *results)
{

    map<Key*, Value*, pointer_comparator<Key*>> sortedMap;

    for (vector<KeyValue*>::iterator it = results->begin ();
            it != results->end (); it++)
    {

        KeyValue *kv = (KeyValue*) (*it);

        Key *key = kv->getKey ();
        Value *value = kv->getValue ();
        std::pair<uint8_t*, size_t> pair = value->getValue ();

        EndianInputStream *byteStream = new EndianInputStream (
            (char*) pair.first, pair.second);

        int numKeys = byteStream->readInt ();
        for (int i = 0; i < numKeys; i++)
        {
            std::pair<uint32_t, uint8_t*> cf = readByteArray (byteStream);
            std::pair<uint32_t, uint8_t*> cq = readByteArray (byteStream);
            std::pair<uint32_t, uint8_t*> cv = readByteArray (byteStream);
            uint64_t timestamp = byteStream->readLong ();
            std::pair<uint32_t, uint8_t*> createdValue = readByteArray (
                        byteStream);

            Key *newKey = new Key ();
            std::pair<const char*, uint32_t> row = key->getRow ();
            newKey->setRow (row.first, row.second);
            newKey->setColFamily ((const char*) cf.second, cf.first);
            newKey->setColQualifier ((const char*) cq.second, cq.first);
            newKey->setColVisibility ((const char*) cv.second, cv.first);
            newKey->setTimeStamp (timestamp);
            Value *newValue = new Value ();
            newValue->setValue (createdValue.second, createdValue.first);

            sortedMap.insert (std::make_pair (newKey, newValue));
            delete[] cf.second;
            delete[] cq.second;
	    delete[] cv.second;
            delete[] createdValue.second;
        }
        
        delete byteStream;
	
        if (!kv->hasOwnerShip())
	  delete key;
        delete kv;
	

    }
    return sortedMap;
}

inline std::pair<uint32_t, uint8_t*>
TabletLocationObtainer::readByteArray (InputStream *stream)
{
    int length = stream->readInt ();
    
    uint8_t * array = new uint8_t[length];

    stream->readBytes (array, length);

    return std::make_pair (length, array);
}

} /* namespace data */
} /* namespace cclient */
