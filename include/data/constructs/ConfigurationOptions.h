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

#ifndef CONFIG_OPTS_H_
#define CONFIG_OPTS_H_

#include <string>

using namespace std;

// configuration options
#define FILE_SYSTEM_ROOT_CFG "FILE_SYSTEM_ROOT"

// options that may be used
#define TABLE_SUFFIX "/tables"
#define TABLE_GET_NAME "/name"
#define TABLE_GET_NAMESPACE "/namespace"
#define TABLE_GET_NAMESPACES "/namespaces"
#define DEFAULT_NAMESPACE_ID "+default"
#define DEFAULT_NAMESPACE "+"
#endif

