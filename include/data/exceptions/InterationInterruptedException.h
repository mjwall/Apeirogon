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

#ifndef ITERINTERRUPT_H
#define ITERINTERRUPT_H

#include <string>

#include <iostream>
using namespace std;
namespace cclient {
namespace exceptions {

class IterationInterruptedException: public std::exception {
public:
    IterationInterruptedException(string excp) :
        excp_str(excp) {

    }

    ~IterationInterruptedException() throw () {

    }
    const char *what() {
        return excp_str.c_str();
    }
private:
    string excp_str;
};
} /* namespace data */
} /* namespace cclient */
#endif /* ITERINTERRUPT_H */
