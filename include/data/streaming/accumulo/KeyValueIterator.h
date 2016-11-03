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
#ifndef INCLUDE_INTERCONNECT_ACCUMULO_KEYVALUEITERATOR_H_
#define INCLUDE_INTERCONNECT_ACCUMULO_KEYVALUEITERATOR_H_

#include "../../constructs/Key.h"
#include "../../constructs/value.h"
#include "../DataStream.h"

namespace cclient
{
namespace data
{
namespace streams
{

using namespace cclient::data;

class KeyValueIterator : public DataStream<std::pair<Key*, Value*>>
{
public:
    KeyValueIterator (KeyValueIterator *source,
                      StreamConfiguration *configuration)
    {
        setConfiguration (configuration);
    }

    KeyValueIterator ()
    {

    }

    virtual
    ~KeyValueIterator ()
    {
    }

    virtual bool
    hasNext ()
    {
        return false;
    }

    virtual void
    relocate (StreamRelocation *location)
    {
    }

    virtual DataStream *
    begin ()
    {
        return this;
    }

    virtual DataStream *
    end ()
    {
        return this;
    }

    virtual std::pair<Key*, Value*>
    operator* ()
    {
        return std::make_pair ((Key*) NULL, (Value*) NULL);
    }

    virtual void next()
    {

    }

    virtual DataStream*
    operator++ ()
    {
        return this;
    }

    virtual DataStream*
    operator++ (int t)
    {
        return this;
    }
}
;
}
}
}
#endif /* INCLUDE_INTERCONNECT_ACCUMULO_KEYVALUEITERATOR_H_ */
