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

#include "../../../include/data/client/TabletServerLocator.h"
#include "../../../include/data/client/TabletLocationObtainer.h"
#include "../../../include/data/client/TabletLocation.h"

namespace cclient
{
namespace impl
{

TabletServerLocator::TabletServerLocator (string tableId,
                TabletLocator *parent,
                TabletLocationObtainer *lc,
                Instance *inst) :
	tableId (tableId), parent (parent), locator (lc), instance (inst)
{
	lastTabletRow = tableId;
	lastTabletRow.append ("<");

}

TabletServerLocator::~TabletServerLocator ()
{

}

} /* namespace data */
} /* namespace cclient */
