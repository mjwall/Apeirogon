#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "../../../../../../include/data/constructs/client/zookeeper/test/../zoocache.h"

#include "../../../../../../include/data/constructs/client/zookeeper/test/../zookeepers.h"
using namespace cclient::data::zookeeper;

int main(int argc, char **argv) {

	string host = "localhost:2181";
	string instance = "instance";
	int timeout = 1000;
	if (argc == 3) {
		host = argv[1];
		instance = argv[2];
	}
	Watch myWatch;
	ZooKeeper *newKeeper = new ZooKeeper(host.c_str(), timeout);
	newKeeper->init(&myWatch);

	ZooCache cache(newKeeper);

	stringstream instancePath;

	instancePath << ZROOT << ZINSTANCES << "/" << instance;

	uint8_t *instanceId = cache.getData(instancePath.str());

	stringstream zRootLocation;

	zRootLocation << ZROOT << "/" << instanceId << "/" << "tservers";

	cout << "looking for tservers at " << zRootLocation.str() << endl;

	list<string> children = cache.getChildren(zRootLocation.str());
	for (auto child : children) {
		cout << "Found " << child << endl;
	}

	delete newKeeper;
	return 0;
}

