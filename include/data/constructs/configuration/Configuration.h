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
