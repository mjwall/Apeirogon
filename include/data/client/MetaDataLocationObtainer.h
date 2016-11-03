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

