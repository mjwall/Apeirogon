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
