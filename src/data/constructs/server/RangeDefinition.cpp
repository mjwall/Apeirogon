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
#include "../../../../include/data/constructs/server/RangeDefinition.h"

#include <string>
#include <vector>

using namespace std;

#include "../../../../include/data/constructs/server/ServerDefinition.h"
#include "../../../../include/data/constructs/server/../security/AuthInfo.h"
#include "../../../../include/data/constructs/server/../Range.h"
#include "../../../../include/data/constructs/server/../KeyExtent.h"
#include "../../../../include/data/constructs/column.h"

namespace cclient
{

namespace data
{
using namespace security;
namespace tserver
{

/**
 * Constructor
 * @param creds ptr to credentials
 * @param auths pointer to auths used in range definition
 * @param host host name we're connecting to
 * @param port port connecting to
 * @param keyRange range
 * @param keyExt key extent
 * @param inCols incoming columns
 *
 */
RangeDefinition::RangeDefinition (AuthInfo *creds, Authorizations *auths,
                                  std::string host, uint32_t port,
                                  std::vector<Range*> *keyRange,
                                  std::vector<KeyExtent*> *keyExt,std::vector<Column*> *inCols) :
    ServerDefinition (creds, auths, host, port)
{
    if (NULL != keyRange)
    {

        ranges.insert (ranges.end (), keyRange->begin (), keyRange->end ());
    }

    if (NULL != keyExt)
        extents.insert (extents.end (), keyExt->begin (), keyExt->end ());
    
    if (NULL != inCols)
        columns.insert (columns.end (), inCols->begin (), inCols->end ());

}

/**
 * Returns ranges
 * @returns ranges
 */
vector<Range*> *
RangeDefinition::getRanges ()
{
    return &ranges;
}

/**
 * Returns key extents
 * @returns key extents;
 */
vector<KeyExtent*> *
RangeDefinition::getExtents ()
{
    return &extents;
}
}
}
}
