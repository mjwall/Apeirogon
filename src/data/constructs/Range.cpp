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

#include "../../../include/data/constructs/Range.h"

namespace cclient
{
namespace data
{

Range::~Range ()
{
    // TODO Auto-generated destructor stub
}

Range::Range() :
    start(NULL), stop(NULL), startKeyInclusive(true), stopKeyInclusive(
        false) {
    infiniteStartKey = true;
    infiniteStopKey = true;
}

Range::Range(Key *startKey, bool startInclusive, Key *endKey, bool endKeyInclusive) :
    start(startKey), startKeyInclusive(startInclusive), stop(endKey), stopKeyInclusive(
        endKeyInclusive) {
    infiniteStartKey = startKey == NULL;
    infiniteStopKey = stop == NULL;

    if (stopKeyInclusive)
    {
        std::pair<char*, size_t> row = stop->getRow();
        char *newRow = new char[row.second+1];
        memset(newRow,0x00,row.second+1);
        memcpy(newRow,row.first,row.second);
        stop->setRow(newRow,row.second+1);
        delete [] newRow;
    }
    if (!infiniteStartKey && !infiniteStopKey && (*stop < *start))
    {
        throw new IllegalArgumentException("Start key must be less than end key in range");
    }
}

} /* namespace data */
} /* namespace cclient */
