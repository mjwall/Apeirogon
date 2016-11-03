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
#ifndef INCLUDE_INTERCONNECT_STREAMING_DATASTREAM_H_
#define INCLUDE_INTERCONNECT_STREAMING_DATASTREAM_H_

#include <iterator>
using namespace std;
#include "StreamEnvironment.h"
#include "StreamRelocation.h"

namespace cclient
{
namespace data
{
namespace streams
{

template<typename T>
class DataStream : public std::iterator<std::forward_iterator_tag, T>
{
protected:

    StreamConfiguration *myConfiguration;

public:

    DataStream ()
    {
    }

    void
    setConfiguration (StreamConfiguration *configuration)
    {
        myConfiguration = configuration;
    }
    virtual
    ~DataStream ()
    {
    }

    virtual bool
    hasNext () = 0;

    virtual void
    relocate (StreamRelocation *location) = 0;

    virtual DataStream
    *
    begin () = 0;

    virtual DataStream
    *
    end () = 0;

    virtual T
    operator* () = 0;

    virtual DataStream*
    operator++ () = 0;

    virtual void next() = 0;

    virtual DataStream*
    operator++ (int t) = 0;

};
}
}
}
#endif /* INCLUDE_INTERCONNECT_STREAMING_DATASTREAM_H_ */
