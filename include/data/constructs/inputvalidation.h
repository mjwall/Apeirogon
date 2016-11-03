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

#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

template<typename T>
class has_size {
    typedef char one;
    typedef long two;

    template<typename C> static one test(decltype(&C::size));
    template<typename C> static two test(...);

public:
    enum {
        value = sizeof(test<T>(0)) == sizeof(char)
    };
};

template<typename T>
static auto IsEmpty(
    T *t) -> typename enable_if<has_size<T>::value ==1, bool>::type {
    return (NULL == t || t->size() == 0);
}

template<typename T>
static auto IsEmpty(
    T *t) -> typename enable_if<not has_size<T>::value , bool>::type {
    return (NULL == t);
}

static auto IsEmpty(char *t)-> decltype(NULL !=t, bool()) {
    return (NULL == t || strlen(t) == 0);
}

template<typename ... T>
bool IsEmpty() {

    return false;
}

static bool isValidPort(uint32_t port) {
    if (port < 1024 || port > 65535) {
        return false;
    }
    return true;
}

template< typename T >
class pointer_comparator : public std::binary_function< T, T, bool >
{
public :
    bool operator()( T x, T y ) const {
        return *x < *y;
    }
};

template<typename T, size_t N>
inline size_t array_length(T data[N])
{
    return N;
};

template<typename T, size_t N>
size_t array_length(const T (&x)[N])
{
    return N;
}

static vector<string> split(string str, char delim) {

    stringstream test(str);
    string segment;
    vector<string> seglist;

    while (std::getline(test, segment, delim)) {

        seglist.push_back(segment);
    }

    return seglist;
}

#endif // INPUTVALIDATION_H
