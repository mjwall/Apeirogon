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

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <string>
#include <map>

using namespace std;

namespace cclient {
namespace impl {

/**
 * Purpose & Design: Based on the hadoop configuration object
 */
class Configuration {
public:
    /**
     * Constructor
     */
    Configuration();
    virtual ~Configuration();
    /**
     * Sets the value of the name
     * @param name config option name
     * @param value
     */
    void set(string name, string value);
    /**
     * Returns the config option
     * @param name
     */
    string get(string name) const ;

    /**
     * Returns the config option using default if the map option isn't set
     */
    string get(string name, string def) const ;

    uint32_t getLong(string name) const ;
    uint32_t getLong(string name, uint32_t def) const ;

protected:
    map<string, string> configurationMap;
};

} /* namespace impl */
} /* namespace cclient */
#endif /* CONFIGURATION_H_ */
