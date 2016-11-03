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
#ifndef TABLETSERVERMUTATIONS_H_
#define TABLETSERVERMUTATIONS_H_

#include <map>
#include <list>

#include "../KeyExtent.h"
#include "../Mutation.h"

using namespace std;
namespace cclient {
namespace data {

class TabletServerMutations {
public:
    TabletServerMutations(string sessionId);
    virtual ~TabletServerMutations();

    void addMutation(KeyExtent *extent, Mutation* m) {
        vector<Mutation*> &mutationList = (*mutations)[extent];
        mutationList.push_back(m);
    }

    map<KeyExtent*, vector<Mutation*> > *getMutations() {
        return mutations;
    }

protected:
    map<KeyExtent*, vector<Mutation*> > *mutations;
    string session;

};

} /* namespace data */
} /* namespace cclient */
#endif /* TABLETSERVERMUTATIONS_H_ */
