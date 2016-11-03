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
