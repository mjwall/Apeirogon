/*
 * Copyright (c) 2016 Marc Parisi marc.parisi@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef TABLETLOCATIONOBTAINER_H_
#define TABLETLOCATIONOBTAINER_H_

#include <list>
#include <iostream>
#include <map>
#include <string>

using namespace std;

#include "../constructs/KeyExtent.h"
#include "../constructs/Key.h"
#include "../constructs/KeyValue.h"
#include "../constructs/value.h"
#include "../constructs/Range.h"
#include "../streaming/input/InputStream.h"
#include "ExtentLocator.h"
#include "TabletLocation.h"
namespace cclient {
namespace impl {

using namespace cclient::data;
using namespace cclient::data::streams;
class TabletLocationObtainer {
public:
    TabletLocationObtainer();

    virtual ~TabletLocationObtainer();

    virtual list<TabletLocation*> findTablet(AuthInfo *credentials, TabletLocation *source, string row,
            string stopRow, TabletLocator *parent) = 0;
    virtual list<TabletLocation*> findTablet(AuthInfo *credentials, string tabletserver,
            map<KeyExtent, list<Range> > *map, TabletLocator *parent) = 0;

protected:
    inline std::pair<uint32_t, uint8_t*> readByteArray(InputStream *stream);
    map<Key*, Value*,pointer_comparator<Key*>> decodeResults(vector<KeyValue*> *results);
};

} /* namespace data */
} /* namespace cclient */
#endif /* TABLETLOCATIONOBTAINER_H_ */
