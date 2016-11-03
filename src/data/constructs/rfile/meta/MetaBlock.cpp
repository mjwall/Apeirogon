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

#include "../../../../../include/data/constructs/rfile/meta/MetaBlock.h"
#include "../../../../../include/data/constructs/rfile/meta/LocalityGroupMetaData.h"
#include "../../../../../include/data/constructs/rfile/meta/../../../streaming/DataOutputStream.h"

using namespace cclient::data;

MetaBlock::MetaBlock ()
{

}

MetaBlock::~MetaBlock ()
{
}

uint64_t
MetaBlock::write (DataOutputStream *outStream)
{
    // write the magic number.
    outStream->writeInt (MAGIC_NUMBER);
    // write version of the RFIle
    outStream->writeInt (RFILE_VERSION);
    // write the size of the locaity groups.
    outStream->writeInt (localityGroups.size ());
    uint64_t offset = 0;
    for (list<LocalityGroupMetaData*>::iterator it = localityGroups.begin ();
            it != localityGroups.end (); it++)
    {

        offset = (*it)->write (outStream);
    }
    return offset;
    //return outStream->getPos();
}
