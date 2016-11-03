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
#include "../../../../include/data/constructs/client/TabletServerMutations.h"

namespace cclient
{
namespace data
{

TabletServerMutations::TabletServerMutations (string sessionId) :
    session (sessionId)
{
    mutations = new map<KeyExtent*, vector<Mutation*>> ();

}

TabletServerMutations::~TabletServerMutations ()
{
    for (map<KeyExtent*, vector<Mutation*>>::iterator it =
                mutations->begin (); it != mutations->end (); it++)
    {
        delete it->first;
        for (auto mutation : it->second)
        {
            delete mutation;
        }
    }
    delete mutations;

}

} /* namespace data */
} /* namespace cclient */
