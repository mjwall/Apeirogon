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

#ifndef SCAN_H_
#define SCAN_H_ 1

#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include "../data/constructs/KeyValue.h"

//http://sector.sourceforge.net/software.html

/**
 * Represents a running scan
 */

namespace interconnect
{
using namespace cclient::data;

class Scan
{
public:

	Scan();

	~Scan();

	bool setNextResults(vector<KeyValue*> *resultSet)
	{
		results.insert(results.end(), resultSet->begin(),
		               resultSet->end());
		return true;
	}

	bool getNextResults(vector<KeyValue*> *resultSet)
	{
		resultSet->insert(resultSet->end(), results.begin(), results.end());
		results.clear();
		return hasMore;
	}

	void setHasMore(bool more)
	{
		hasMore = more;
	}

	bool getHasMore()
	{
		return hasMore;
	}
	int64_t getId()
	{

		return scanId;

	}

	void setScanId(int64_t scanId)
	{
		this->scanId = scanId;
	}

protected:
	int64_t scanId;
	bool hasMore;
	vector<KeyValue*> results;
};
}
#endif /* SCAN_H_ */
