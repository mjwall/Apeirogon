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
#include <vector>
#include <memory>
using namespace std;

#include "../../../include/data/client/MetaDataLocationObtainer.h"
#include "../../../include/data/client/../constructs/server/RangeDefinition.h"
#include "../../../include/data/client/../constructs/StructureDefinitions.h"
#include "../../../include/data/client/../../interconnect/TabletServer.h"
#include "../../../include/data/client/../../interconnect/Scan.h"
#include "../../../include/data/client/../constructs/Range.h"
#include "../../../include/data/client/../constructs/KeyExtent.h"
#include "../../../include/data/client/../constructs/Key.h"
#include "../../../include/data/client/../constructs/IterInfo.h"
#include "../../../include/data/client/../constructs/value.h"
#include "../../../include/data/client/TabletLocation.h"

namespace cclient
{
namespace impl
{

using namespace cclient::data;
using namespace cclient::data::tserver;

MetaDataLocationObtainer::~MetaDataLocationObtainer ()
{
    for (vector<Column*>::iterator locIt = columns->begin ();
            locIt != columns->end (); locIt++)
    {
        delete (*locIt);
    }

    delete columns;

}

list<TabletLocation*>
MetaDataLocationObtainer::findTablet (AuthInfo *credentials,
                                      TabletLocation *source, string row,
                                      string stopRow, TabletLocator *parent)
{
    list<TabletLocation*> tabletLocations;
    Key startKey;
    startKey.setRow (row.c_str (), row.size ());
    Key endKey;
    endKey.setRow (stopRow.c_str (), stopRow.size ());
    Range *range = new Range (&startKey, true, &endKey, true);

    map<Key, Value> resultSet;

    Authorizations emptyAuths;

    vector<Range*> ranges;
    ranges.push_back (range);

    vector<KeyExtent*> extents;
    extents.push_back (source->getExtent ());
    RangeDefinition *rangeDef = new RangeDefinition (credentials, &emptyAuths,
            source->getServer (),
            source->getPort (),
            &ranges, &extents);

    Configuration conf;
    interconnect::ServerInterconnect *directConnect =
        new interconnect::ServerInterconnect (rangeDef, &conf);

    IterInfo wriIter (
        "WRI", "org.apache.accumulo.core.iterators.user.WholeRowIterator",
        10000);

    vector<IterInfo*> iters;
    iters.push_back (&wriIter);

    interconnect::Scan *initScan = directConnect->scan (columns, &iters);
    vector<KeyValue*> kvResults;
    initScan->getNextResults (&kvResults);

    map<Key*, Value*, pointer_comparator<Key*>> results = decodeResults (
                &kvResults);

    Key *key = 0;
    Value * value = 0;
    string lastRowFromKey = "";
    string currentRow = "";

    string location = "", session = "";

    Value *prevRow = 0;
    KeyExtent *ke;

    for (map<Key*, Value*>::iterator it = results.begin ();
            it != results.end (); it++)
    {
        key = it->first;
        currentRow = string (key->getRow ().first, key->getRow ().second);
        if (currentRow != lastRowFromKey)
        {
            prevRow = 0;
            location = session = "";
            lastRowFromKey = currentRow;

        }

        std::pair<char*, size_t> cfBytes = key->getColFamily ();
        string cf = string (cfBytes.first, cfBytes.second);
        std::pair<char*, size_t> cqBytes = key->getColQualifier ();
        string cq = string (cqBytes.first, cqBytes.second);

        value = it->second;
        std::pair<uint8_t*, size_t> valBytes = value->getValue ();
        if (cf == METADATA_CURRENT_LOCATION_COLUMN_FAMILY
                || cf == METADATA_FUTURE_LOCATION_COLUMN_FAMILY)
        {
            location = string ((char*) valBytes.first, valBytes.second);
            session = cq;
        } 
        else if (cf == METADATA_TABLET_COLUMN_FAMILY
                 && cq == METADATA_PREV_ROW_COLUMN_CQ)
        {
            prevRow = value;
        }

        if (prevRow != NULL)
        {

            ke = new KeyExtent (currentRow, prevRow);
            if (location.length () > 0)
            {

                TabletLocation *te = new TabletLocation (ke, location,
                        session);

                tabletLocations.push_back (te);
            }
        }

    }

    for (map<Key*, Value*>::iterator it = results.begin ();
            it != results.end (); it++)
    {
        delete it->first;
        delete it->second;
    }

    delete initScan;

    // cleanup
   // delete rangeDef;
    
    
    delete range;
    
    delete directConnect;

    return tabletLocations;
}

} /* namespace impl */
} /* namespace cclient */

