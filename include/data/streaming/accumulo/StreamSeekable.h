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
#ifndef INCLUDE_DATA_STREAMING_ACCUMULO_STREAMSEEKABLE_H_
#define INCLUDE_DATA_STREAMING_ACCUMULO_STREAMSEEKABLE_H_

#include <cstdlib>

#include <vector>
#include "../StreamRelocation.h"
#include "../../constructs/Range.h"

namespace cclient
{
namespace data
{
namespace streams
{

using namespace cclient::data;

class StreamSeekable : public StreamRelocation
{
protected:
    Range *range;
    vector<uint8_t*> columnFamilies;
    bool inclusive;
public:

    StreamSeekable (Range *range, vector<uint8_t*> columnFamilies,
                    bool inclusive) :
        range (range), columnFamilies (columnFamilies), inclusive (
            inclusive)
    {

    }

    Range *
    getRange ()
    {
        return range;
    }

    vector<uint8_t*> *
    getColumnFamilies ()
    {
        return &columnFamilies;
    }

    bool
    isInclusive ()
    {
        return inclusive;
    }
};

}
}
}

#endif /* INCLUDE_DATA_STREAMING_ACCUMULO_STREAMSEEKABLE_H_ */