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

#ifndef RANGE_H_
#define RANGE_H_

#include "../exceptions/IllegalArgumentException.h"
#include "Key.h"
namespace cclient {
namespace data {

using namespace cclient::exceptions;
class Range {
public:
    Range();

    Range(Key *startKey, bool startInclusive, Key *endKey, bool endKeyInclusive);

    Key *getStartKey()
    {
        return start;
    }

    Key *getStopKey()
    {
        return stop;
    }

    bool getStartKeyInclusive()
    {
        return startKeyInclusive;
    }

    bool getStopKeyInclusive()
    {
        return stopKeyInclusive;
    }

    bool getInfiniteStartKey()
    {
        return infiniteStartKey;
    }

    bool getInfiniteStopKey()
    {
        return infiniteStopKey;
    }

    virtual ~Range();
protected:
    Key *start;
    Key *stop;
    bool startKeyInclusive;
    bool stopKeyInclusive;
    bool infiniteStartKey;
    bool infiniteStopKey;
};

} /* namespace data */
} /* namespace cclient */
#endif /* RANGE_H_ */
