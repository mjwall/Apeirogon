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


#ifndef AUTHORIZATIONS_H_
#define AUTHORIZATIONS_H_ 1

#pragma once

#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>

using namespace std;

#include "../../exceptions/ClientException.h"

using namespace cclient::exceptions;

namespace cclient {
namespace data {
namespace security {

static bool validAuthChars[256];

class Authorizations {
public:
    Authorizations();

    Authorizations(string authorizations, char *validCharacters, int valid);

    ~Authorizations();

    Authorizations(list<string> *);

    void addAuthorization(string auth);

    vector<string> getAuthorizations() {
        vector<string> strAuths;
        for (auto it : authStrings) {
            strAuths.push_back(it);
        }
        return strAuths;
    }

    inline static int init_auths() {
        return buildDefaultAuths();
    }

protected:

    void validateAuths() {
        for (auto it = authStrings.begin(); it != authStrings.end(); it++) {
            for (uint32_t i = 0; i < (*it).size(); i++) {
                if (!isValidAuthCharacter((*it).at(i))) {
                    throw ClientException("Invalid authorization character");
                }
            }
        }
    }
    static int buildDefaultAuths() {
        for (uint8_t i = 0; i < 256; i++) {
            validAuthChars[i] = false;
        }

        for (uint8_t i = 'a'; i <= 'z'; i++) {
            validAuthChars[i] = true;
        }

        for (uint8_t i = 'A'; i <= 'Z'; i++) {
            validAuthChars[i] = true;
        }

        for (uint8_t i = '0'; i <= '9'; i++) {
            validAuthChars[i] = true;
        }

        validAuthChars['_'] = true;
        validAuthChars['-'] = true;
        validAuthChars[':'] = true;
        return 0;
    }

    static bool isValidAuthCharacter(char c) {
        return validAuthChars[(uint8_t)c];
    }

    set<string> authStrings;

};

}
}
}
#endif /* AUTHORIZATIONS_H_ */
