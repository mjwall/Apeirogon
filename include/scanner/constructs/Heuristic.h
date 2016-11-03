/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2015
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

#ifndef HEURISTIC_H_
#define HEURISTIC_H_

#include "../../interconnect/ClientInterface.h"

namespace scanners
{
using namespace interconnect;
template<typename T>
class Heuristic
{

protected:

	vector<ClientInterface<T>*> servers;

	virtual void addClientInterface(ClientInterface<T> *ifc)
	{
		servers.push_back(ifc);
	}


public:
	Heuristic()
	{
	}

	virtual ~Heuristic()
	{
		/**
		 * we maintain ownership of the client interface at this point
		 **/
		for(auto ifc : servers) {
			delete ifc;
		}

	}
};
}
#endif /* HEURISTIC_H_ */
