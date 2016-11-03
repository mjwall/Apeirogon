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
