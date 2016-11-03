/*
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
#ifndef SRC_DATA_CONSTRUCTS_CLIENT_INSTANCECACHE_H_
#define SRC_DATA_CONSTRUCTS_CLIENT_INSTANCECACHE_H_

#include <string>
#include <list>
using namespace std;

namespace cclient {
namespace data {

class InstanceCache {
public:
    InstanceCache() {
    }
    virtual ~InstanceCache() {
    }

    virtual uint8_t *getData(string path) = 0;
    virtual list<string> getChildren(const string path, bool force=false) = 0;
};

} /* namespace impl */
} /* namespace cclient */

#endif /* SRC_DATA_CONSTRUCTS_CLIENT_INSTANCECACHE_H_ */
