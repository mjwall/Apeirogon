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
#ifndef FAST_OBJ_H_
#define FAST_OBJ_H_


#include "../extern/cpp-btree/btree_set.h"
#include "../extern/cpp-btree/btree_map.h"
#include "../extern/concurrentqueue/concurrentqueue.h"

template<typename T, typename V>
struct GoogleMap
{

    typedef btree::btree_map<T,V> Map;

};

template<typename T>
struct GoogleSet
{
    typedef btree::btree_set<T> Set;
};

template<typename T>
struct ConcurrentQueue
{
    typedef moodycamel::ConcurrentQueue<T> Queue;
};

#endif


