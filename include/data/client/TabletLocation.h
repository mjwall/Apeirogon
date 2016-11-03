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
#ifndef TABLETLOCATION_H_
#define TABLETLOCATION_H_

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
#include "../constructs/KeyExtent.h"

namespace cclient
{
namespace data
{

class TabletLocation
{
public:
    TabletLocation ();
    TabletLocation (KeyExtent *extent, string loc) :
        tablet_extent (extent), tablet_location (loc)
    {

    }

    TabletLocation (KeyExtent *extent, string loc, string sesh) :
        tablet_extent (extent), tablet_location (loc), session (sesh)
    {
        vector<string> tokens = split (tablet_location, ':');
        if (!IsEmpty (&tokens))
        {
            server = tokens.at (0);
            port = atoi (tokens.at (1).c_str ());
        }
    }

    KeyExtent *
    getExtent ()
    {
        return tablet_extent;
    }
    
    void setExtent(KeyExtent *extent)
    {
      tablet_extent = extent;
    }

    string
    getLocation ()
    {
        return tablet_location;
    }

    string
    getServer ()
    {
        return server;
    }

    string
    getSession ()
    {
        return session;
    }

    int
    getPort ()
    {
        return port;
    }

    virtual
    ~TabletLocation ();
protected:
    KeyExtent *tablet_extent;
    string tablet_location;
    string server;
    int port;
    string session;
};

} /* namespace data */
} /* namespace cclient */
#endif /* TABLETLOCATION_H_ */
