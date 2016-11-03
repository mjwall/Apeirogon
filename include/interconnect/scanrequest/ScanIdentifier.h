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
#ifndef SCAN_IDENT_H_
#define SCAN_IDENT_H_

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

namespace interconnect {
struct CopyKey {
    template<typename T>
    typename T::first_type operator()(T keyValuePair) const {
        return keyValuePair.first;
    }
};

template<typename M, typename V>
class ScanIdentifier {
protected:
    map<M, vector<V> > globalIdentifierMapping;

public:
    ScanIdentifier() {

    }

    vector<V> getIdentifiers(M m) {
        return globalIdentifierMapping[m];
    }

    void putIdentifier(M m, V v) {
        globalIdentifierMapping[m].push_back(v);
    }

    vector<M> getGlobalMapping() {
        vector<M> keys;
        transform(globalIdentifierMapping.begin(),
                  globalIdentifierMapping.end(), back_inserter(keys), CopyKey());
        return keys;
    }
};
}
#endif
