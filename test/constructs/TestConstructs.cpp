/*
 * Copyright (c) 2016 Marc Parisi marc.parisi@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;
#include <netinet/in.h>
#include <stdint.h>

#include "../../include/data/constructs/Key.h"
#include "../../include/data/constructs/KeyExtent.h"
#include "../../include/data/constructs/value.h"
#include "../../include/data/constructs/KeyValue.h"
#include "../../include/data/constructs/rkey.h"
#include <sys/time.h>
//#include <snappy.h>

#define CATCH_CONFIG_MAIN

#include <hdfs/hdfs.h>


#include "../../include/data/constructs/column.h"
#include "../../include/data/constructs/security/Authorizations.h"
#include "../../include/data/constructs/security/AuthInfo.h"

using namespace cclient::data::security;
using namespace cclient::data;
using namespace cclient::data::streams;


#define NUMBER 50000
#include "../catch.hpp"

TEST_CASE("TestMain", "[TestMain]") {
	struct hdfsBuilder *builder = hdfsNewBuilder ();
	  hdfsFreeBuilder(builder);
}




TEST_CASE("Test Key", "[createAndSetParameters]") {

	char testVal[3] = { 0x01, 0x02, 0x03 };

	Key key;

	// test reuse
	for (int i = 0; i < 1000; i++) {

		REQUIRE(false == key.isDeleted());

		key.setRow(testVal, 3);
		std::pair<char*, size_t> rowRet = key.getRow();

		REQUIRE(memcmp(testVal, rowRet.first, 3) == 0);
		REQUIRE(3 == rowRet.second);

		key.setColFamily(testVal, 3);
		std::pair<char*, size_t> colFamRet = key.getColFamily();

		REQUIRE(memcmp(testVal, colFamRet.first, 3) == 0);
		REQUIRE(3 == colFamRet.second);

	}

}

TEST_CASE("Test KeyExtent", "[createAndSetParameters]") {

	char testVal[3] = { 0x01, 0x02, 0x03 };

	KeyExtent *newExtent = new KeyExtent("tableId","row");
	REQUIRE("tableId" == newExtent->getTableId());
	
	delete newExtent;


}

TEST_CASE("Test Key -- testStreamInterface", "[testStreamInterface]") {

	StreamInterface **kv = new StreamInterface*[25];
	for (int i = 0; i < 25; i++) {
		kv[i] = new KeyValue();
		delete kv[i];
	}

	delete[] kv;

	KeyValue *kvList = new KeyValue[200];

	char tst[400];
	memset(tst, 0x01, 400);

	for (int i = 0; i < 200; i++) {
		REQUIRE(kvList[i].getValue() != NULL);

		kvList[i].getValue()->setValue((uint8_t*) tst, 400);

		REQUIRE(0 ==
				memcmp(tst, kvList[i].getValue()->getValue().first,
						kvList[i].getValue()->getValue().second));

		REQUIRE(dynamic_cast<Key*>(kvList[i].getKey()) != NULL);
		REQUIRE(dynamic_cast<Key*>(kvList[i].getStream()) != NULL);

	}
	
	delete []kvList;
	
}




TEST_CASE("Test Authorizations", "[createAndSetParameters]") {

	list<string> auths;
	auths.push_back("one");
	auths.push_back("two");

	Authorizations *authorizations = new Authorizations(&auths);

	REQUIRE(2 == authorizations->getAuthorizations().size());

	delete authorizations;
}

TEST_CASE("Test Authorizations -- createAuthInfoNoNulls", "[createAuthInfoNoNulls]") {
	AuthInfo *auth = new AuthInfo("testuser", "testpassword", "instance");

	REQUIRE("instance"== auth->getInstanceId());

	REQUIRE("testpassword"== auth->getPassword());

	REQUIRE("testuser"== auth->getUserName());

	delete auth;
}



TEST_CASE("Test Column", "[createAndSet]") {
  
	Column *column = new Column("family", "qualifier", "viz");
  
	REQUIRE(string(column->getColFamily().first).compare("family") == 0);

	REQUIRE(
			string(column->getColQualifier().first).compare(0,
					column->getColQualifier().second, "qualifier") == 0);

	REQUIRE(
			string(column->getColVisibility().first).compare(0,
					column->getColVisibility().second, "viz") == 0);

	REQUIRE(column->getColFamily().second == strlen("family"));

	REQUIRE(column->getColQualifier().second == strlen("qualifier"));

	REQUIRE(column->getColVisibility().second == strlen("viz"));
	
	delete column;
}
