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
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "../../../../../../include/data/constructs/client/zookeeper/test/../zoocache.h"
#include "../../../../../../include/data/constructs/client/zookeeper/test/../../../configuration/Configuration.h"

#include "../../../../../../include/data/constructs/client/zookeeper/test/../../zookeeperinstance.h"
using namespace cclient::data::zookeeper;
using namespace cclient::impl;

int main(int argc, char **argv) {


	string host = "localhost:2181";
	string instance = "instance";
	uint32_t timeout = 1000;
	if (argc == 3) {
		host = argv[1];
		instance = argv[2];
	}
	ZookeeperInstance *zkInst = new ZookeeperInstance(instance,host,timeout,new Configuration());

	cout << zkInst->getInstanceId() << endl;

	vector<string> locs = zkInst->getMasterLocations();
	for(vector<string>::iterator it = locs.begin(); it != locs.end(); it++)
		{
			cout << *it << endl;
		}



	delete zkInst;
	return 0;
}

