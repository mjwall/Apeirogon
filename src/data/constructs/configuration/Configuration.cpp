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
#include "../../../../include/data/constructs/configuration/Configuration.h"

#include <string>
#include <map>

using namespace std;

namespace cclient
{
namespace impl
{

Configuration::Configuration ()
{

}

Configuration::~Configuration ()
{

}

void
Configuration::set (string name, string value)
{
    configurationMap[name] = value;

}

string
Configuration::get (string name) const
{
    return get (name, "");

}

string
Configuration::get (string name, string def) const
{
    auto getter = configurationMap.find (name);
    if (getter == configurationMap.end ())
    {
        return def;
    }
    else
    {
        return getter->second;
    }

}

uint32_t
Configuration::getLong (string name) const 
{
    return atol (get (name, 0).c_str ());

}

uint32_t
Configuration::getLong (string name, uint32_t def) const 
{
    auto getter = configurationMap.find (name);
    if (getter == configurationMap.end ())
    {
        return def;
    }
    else
        return atol (getter->second.c_str ());

}

} /* namespace impl */
} /* namespace cclient */
