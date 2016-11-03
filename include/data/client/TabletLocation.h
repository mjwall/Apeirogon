/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * Key/value connector. Copyright (C)  2016
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
