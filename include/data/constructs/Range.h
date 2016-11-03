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
