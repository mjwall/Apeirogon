/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2015
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
#ifndef INCLUDE_DATA_CONSTRUCTS_RFILE_META_BASEMETABLOCK_H_
#define INCLUDE_DATA_CONSTRUCTS_RFILE_META_BASEMETABLOCK_H_
#include "../../../streaming/Streams.h"

namespace cclient
{
namespace data
{
using namespace cclient::data::streams;
using namespace cclient::data;

class BaseMetaBlock
{

public:

    virtual
    ~BaseMetaBlock ()
    {
    }

    virtual uint32_t
    getCurrentPosition () = 0;

    virtual StreamInterface*
    getBlock () = 0;

    virtual BaseMetaBlock *
    getPreviousBlock () = 0;

    virtual uint32_t
    getOffset () = 0;

    virtual bool
    hasNextKey () =0;

};

}
}

#endif /* INCLUDE_DATA_CONSTRUCTS_RFILE_META_BASEMETABLOCK_H_ */
