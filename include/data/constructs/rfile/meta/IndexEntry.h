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
