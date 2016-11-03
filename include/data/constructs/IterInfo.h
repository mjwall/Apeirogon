/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
