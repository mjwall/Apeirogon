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

#ifndef METADATALOCATIONOBTAINER_H_
#define METADATALOCATIONOBTAINER_H_

#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#include "TabletLocationObtainer.h"

#include "../constructs/column.h"
#include "../constructs/StructureDefinitions.h"
#include "../constructs/client/Instance.h"
#include "../constructs/security/AuthInfo.h"
namespace cclient {
namespace impl {

using namespace cclient::data;
using namespace cclient::data::security;

class MetaDataLocationObtainer: public TabletLocationObtainer {

public:
    MetaDataLocationObtainer(Instance *instance) :
        instance(instance) {
        columns = new vector<Column*>();
        columns->push_back(
            new Column(METADATA_CURRENT_LOCATION_COLUMN_FAMILY));
        columns->push_back(new Column(METADATA_TABLET_COLUMN_FAMILY,
                                      METADATA_PREV_ROW_COLUMN_CQ));
        sort(columns->begin(),columns->end());

    }

    virtual ~MetaDataLocationObtainer();

    list<TabletLocation*> findTablet(AuthInfo *credentials, TabletLocation *source, string row,
                                     string stopRow, TabletLocator *parent);
    list<TabletLocation*> findTablet(AuthInfo *credentials, string tabletserver,
                                     map<KeyExtent, list<Range> > *map, TabletLocator *parent) {
        return list<TabletLocation*>();
    }
protected:
    vector<Column*> *columns;
    Instance *instance;
};

} /* namespace impl */
} /* namespace cclient */
#endif /* METADATALOCATIONOBTAINER_H_ */

