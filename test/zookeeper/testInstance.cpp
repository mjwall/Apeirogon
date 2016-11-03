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

