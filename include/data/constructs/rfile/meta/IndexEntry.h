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

#ifndef INDEXENTRY_H_
#define INDEXENTRY_H_

#include "../../../streaming/OutputStream.h"
#include "../../../constructs/Key.h"
#include "../../../streaming/Streams.h"

namespace cclient
{
namespace data
{
using namespace cclient::data::streams;

class IndexEntry : StreamInterface
{
public:

    IndexEntry (StreamInterface *mKey, uint32_t entryCount);

    virtual
    ~IndexEntry ();
    /**
     Copy constructor.
     **/
    IndexEntry (const IndexEntry &other)
    {

        *this = other;
        allocated = false;
    }

    IndexEntry () :
        newFormat (false), allocated(false), key(NULL)
    {

    }

    IndexEntry (bool newFormat) :
        newFormat (newFormat), allocated(false), key(NULL)
    {

    }

    /**
     Gets the key for this index entry
     @return pointer to key.
     */
    StreamInterface *
    getKey ()
    {
        return key;
    }

    /**
     Returns the number of entries in this block region.
     @param block region.
     **/
    uint32_t
    getNumEntries ()
    {

        return entries;
    }

    uint64_t
    read (InputStream * in)
    {
        if (allocated && NULL != key)
        {
            delete key;
        }
        key = new Key ();
        allocated = true;
        key->read (in);
        entries = in->readInt ();

        if (newFormat)
        {
            offset = in->readEncodedLong ();
            compressedSize = in->readEncodedLong ();
            rawSize = in->readEncodedLong ();
        }
        else
        {
            offset = -1;
            compressedSize = -1;
            rawSize = -1;
        }

        return in->getPos ();
    }

    /**
     Writes the index entry to the output stream.
     @param outStream output stream.
     @return final position of the output streamm.
     **/
    uint64_t
    write (DataOutputStream * outStream)
    {

        key->write (outStream);
        cout << "Wrigin entries " << entries << endl;
        return outStream->writeInt (entries);

    }

    IndexEntry &
    operator= (const IndexEntry &other)
    {

        key = other.key;
        entries = other.entries;
        newFormat = other.newFormat;
        return *this;
    }

    bool
    operator == (const IndexEntry & rhs) const
    {
        if (offset != rhs.offset)
            return false;
        if (compressedSize != rhs.compressedSize)
            return false;
        if (rawSize != rawSize)
            return false;
        return true;
    }

    uint64_t
    getOffset ()
    {
        return offset;
    }

    uint64_t
    getCompressedSize ()
    {
        return compressedSize;
    }

    uint64_t
    getRawSize ()
    {
        return rawSize;
    }

protected:
   

   
    // number of entries.
    uint32_t entries;
     StreamInterface *key;
    // new format stuff
    bool newFormat;
     bool allocated;
    // initial key
    uint64_t offset;
    uint64_t compressedSize;
    uint64_t rawSize;
}
;
}
}
#endif /* INDEXENTRY_H_ */
