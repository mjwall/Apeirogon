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

#include "../../../../include/data/constructs/security/Authorizations.h"

#include <iostream>

#include <list>
#include <string>
#include <set>

using namespace std;

using namespace cclient::data::security;

Authorizations::Authorizations ()
{

}

Authorizations::Authorizations (string authorizations, char *validCharacters,
                                int valid)
{
    for (int i = 0; i < valid; i++)
    {
        validAuthChars[(uint8_t) validCharacters[i]] = true;
    }
    addAuthorization (authorizations);
}

Authorizations::Authorizations (list<string> *authorizations)
{
    for (auto it = authorizations->begin (); it != authorizations->end (); it++)
        addAuthorization (*it);

}

void
Authorizations::addAuthorization (string auth)
{
    authStrings.insert (auth);
}

Authorizations::~Authorizations ()
{

}