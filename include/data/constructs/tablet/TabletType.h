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
#ifndef TABLETTYPE_H_
#define TABLETTYPE_H_

#include "../KeyExtent.h"
#include "../inputvalidation.h"

using namespace cclient::data;

namespace cclient
{
namespace data
{
namespace tserver
{

enum TabletType
{
    ROOT, METADATA, USER
};

static TabletType fromExtent(KeyExtent *extent)
{
    if (!IsEmpty(extent))
    {

        if (*extent == ROOT_TABLET_EXTENT)
        {
            return ROOT;
        }
        if (extent->getTableId() == METADATA_TABLE_ID)
        {
            return METADATA;
        }
    }
    return USER;
}

}
}
}

#endif /* TABLETTYPE_H_ */
