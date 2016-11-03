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

#ifndef METABLOCK_H_
#define METABLOCK_H_

// magic number for RFile.
#define MAGIC_NUMBER 0x20637474
#define MAGIC_NUMBER2 0x74746320
// rfile version.
#define RFILE_VERSION 4
#define RFILE_VERSION_3 3
#define RFILE_VERSION_6 6
#define RFILE_VERSION_7 7


#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stdexcept>

using namespace std;

#include "../../../streaming/DataOutputStream.h"
#include "../../../streaming/Streams.h"

#include "LocalityGroupMetaData.h"

namespace cclient {
namespace data {
using namespace cclient::data::streams;

class MetaBlock: public StreamInterface {
public:
    /**
     Default constructor.
     **/
    MetaBlock();

    ~MetaBlock();

    /**
     Adds a list of locality groups to the RFile Meta Block
     **/
    void addLocalityGroups(list<LocalityGroupMetaData*> lgs) {
        localityGroups.insert(localityGroups.end(), lgs.begin(), lgs.end());
    }

    uint64_t write(DataOutputStream *outStream);
protected:
    list<LocalityGroupMetaData*> localityGroups;
};

}
}
#endif /* METABLOCK_H_ */
