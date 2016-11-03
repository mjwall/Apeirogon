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

#ifndef RANGEDEFINITION_H_
#define RANGEDEFINITION_H_

#include <string>
#include <vector>

using namespace std;

#include "ServerDefinition.h"
#include "../security/AuthInfo.h"
#include "../Range.h"
#include "../column.h"
#include "../KeyExtent.h"

namespace cclient
{

namespace data
{
using namespace security;
namespace tserver
{

/**
 * Range definition is a server definition that contains the key extent and
 * ranges in which we are accessing
 *
 * Design: extends Server definition
 */
class RangeDefinition : public ServerDefinition
{
public:
    /**
     * Constructor
     * @param creds ptr to credentials
     * @param auths pointer to auths used in range definition
     * @param host host name we're connecting to
     * @param port port connecting to
     * @param keyRange range
     * @param keyExt key extent
     *
     */
    RangeDefinition (AuthInfo *creds, Authorizations *auths,
                     std::string host, uint32_t port,
                     std::vector<Range*> *keyRange,
                     std::vector<KeyExtent*> *keyExt,std::vector<Column*> *columns =NULL);

    /**
     * Returns ranges
     * @returns ranges
     */
    vector<Range*> *
    getRanges ();

    /**
     * Returns key extents
     * @returns key extents;
     */
    vector<KeyExtent*> *
    getExtents ();

    vector<Column*> *getColumn()
    {
      return &columns;
    }
    virtual
    ~RangeDefinition ()
    {

    }
protected:
    std::vector<Range*> ranges;
    std::vector<KeyExtent*> extents;
    std::vector<Column*> columns;
};
}
}
}
#endif /* RANGEDEFINITION_H_ */
