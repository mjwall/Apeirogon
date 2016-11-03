/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2015
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
#ifndef INCLUDE_DATA_CONSTRUCTS_RFILE_META_SERIALIZEDINDEX_H_
#define INCLUDE_DATA_CONSTRUCTS_RFILE_META_SERIALIZEDINDEX_H_

#include <vector>
using namespace std;
#include "../../../streaming/OutputStream.h"
#include "../../../streaming/input/InputStream.h"
#include "../../../streaming/input/ByteInputStream.h"
#include "../../../streaming/input/NetworkOrderInputStream.h"
#include "../../../streaming/Streams.h"
#include "IndexEntry.h"
#include "BaseMetaBlock.h"

namespace cclient
{
namespace data
{
using namespace cclient::data::streams;

class SerializedIndex : public StreamInterface, public std::iterator<
    std::forward_iterator_tag, IndexEntry>
{
public:
    SerializedIndex (vector<int> offsetList, uint8_t *datums, uint32_t dataLength,
                     bool newFormat) :
        newFormat (newFormat), dataLength (
            dataLength), currentPosition (0), ptr (NULL), blockParty (NULL)
    {
        offsets = new vector<int>();
        offsets->insert(offsets->end(),offsetList.begin(),offsetList.end());

        data = new uint8_t[dataLength];
        memcpy(data,datums,dataLength);
    }

    SerializedIndex( BaseMetaBlock *source,BaseMetaBlock *block) :
        data (NULL), dataLength (0), newFormat (true), blockParty (block)
    {

        currentPosition = block->getCurrentPosition ();
        ptr = dynamic_cast<SerializedIndex*> (block->getBlock ());

        offsets = new vector<int>();

        if (source != block)
        {

            delete source;
        }

    }


    SerializedIndex (BaseMetaBlock *block) :
        data (NULL), dataLength (0), newFormat (true), blockParty (block)
    {
        currentPosition = block->getCurrentPosition ();
        ptr = dynamic_cast<SerializedIndex*> (block->getBlock ());

        offsets = new vector<int>();

    }

    virtual
    ~SerializedIndex ()
    {
        if (NULL != data)
        {
            delete[] data;
        }
        if (NULL != ptr)
        {
            delete ptr;
        }
        delete offsets;
    }

    size_t
    size ()
    {
        if (NULL != ptr)
        {
            return ptr->size ();
        }
        return offsets->size ();
    }

    IndexEntry *
    get (uint64_t index)
    {

        if (NULL != ptr)
        {

            return ptr->get (index);
        }
        int len = 0;

        //if (index == offsets->size () - 1)
        //{
	cout << "index is " << index << endl;
        len = dataLength - offsets->at (index);
        /*  }
        else
          {
            len = offsets->at (index + 1) - offsets->at (index);
          }*/
        IndexEntry *returnKey = new IndexEntry (newFormat);

        EndianInputStream *inputStream = new EndianInputStream (
            (char*) data + offsets->at (index), len);
        returnKey->read (inputStream);
        delete inputStream;

        return returnKey;
    }

    IndexEntry *
    get ()
    {
        return get (currentPosition);
    }

    SerializedIndex*
    begin ()
    {
        return this;
    }

    SerializedIndex
    end ()
    {
        return SerializedIndex (true, ptr->offsets->size ());
    }

    IndexEntry *
    operator* ()
    {
        return get (currentPosition);
    }

    SerializedIndex&
    operator++ ()
    {
        currentPosition++;
        return *this;
    }

    SerializedIndex&
    operator++ (int t)
    {
        for (int32_t i = 0; i < (t + 1); i++)
        {
            currentPosition++;
        }

        return *this;
    }

    bool
    isEnd ()
    {
        if (ptr != NULL)
            return currentPosition == ptr->offsets->size ();
        else
            return false;
    }

    bool
    hasPrevious ()
    {
        if (ptr == NULL)
            return false;
        return currentPosition > 0;
    }

    bool
    hasNext ()
    {
        if (blockParty == NULL)
            return false;
        if (!ptr->hasNext ())
            return blockParty->hasNextKey ();
        else
            return true;
    }

    IndexEntry *
    getPrevious ()
    {
	if (currentPosition == 0)
	  return get (0);
      else
	  return get (currentPosition - 1);
    }

    uint32_t
    getPreviousIndex ()
    {
        if (NULL == blockParty)
            return 0;
        int offset = blockParty->getOffset ();
        int prev = 0;
        if (NULL != ptr )
            prev = ptr->getPreviousIndex();
        return offset + prev;
    }

    IndexEntry *
    previous ()
    {
        if (!ptr->hasPrevious ())
        {
            blockParty = blockParty->getPreviousBlock ();
            currentPosition = blockParty->getCurrentPosition ();
            ptr = dynamic_cast<SerializedIndex*> (blockParty->getBlock ());
        }

        return ptr->previous ();
    }

    bool
    operator!= (const SerializedIndex &rhs)
    {
        return !(currentPosition == rhs.currentPosition);
    }

    SerializedIndex (bool isEnd, int maxSize) :
        currentPosition (maxSize)
    {

    }

protected:

    uint8_t *data;
    uint32_t dataLength;
    bool newFormat;
    BaseMetaBlock *blockParty;
    uint32_t currentPosition;
    SerializedIndex *ptr;

    vector<int> *offsets;
    
};

}
}

#endif /* INCLUDE_DATA_CONSTRUCTS_RFILE_META_SERIALIZEDINDEX_H_ */
