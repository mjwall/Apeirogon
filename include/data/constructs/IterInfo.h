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

#ifndef ITERINFO_H_
#define ITERINFO_H_

#include <string>
#include <map>
using namespace std;
namespace cclient
{
namespace data
{

class IterInfo
{
public:
    IterInfo (string name, string cl, uint32_t pri) :
        iterName (name), iterClass (cl), priority (pri)
    {

    }
    virtual
    ~IterInfo ()
    {

    }

    uint32_t
    getPriority () const
    {
        return priority;
    }

    string
    getName () const
    {
        return iterName;
    }

    string
    getClass () const
    {
        return iterClass;
    }

    void
    addOption (string optionName, string optionValue)
    {
        options[optionName] = optionValue;
    }

    const map<string, string>
    getOptions () const
    {
        return options;
    }
protected:

    map<string, string> options;
    uint32_t priority;
    string iterName;
    string iterClass;
};

} /* namespace data */
} /* namespace cclient */
#endif /* ITERINFO_H_ */