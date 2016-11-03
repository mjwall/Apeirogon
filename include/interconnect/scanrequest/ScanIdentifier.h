/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2016
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
