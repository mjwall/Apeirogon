/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2016
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

#include <string>
using namespace std;

#include "../catch.hpp"

#include "../../include/data/constructs/security/Authorizations.h"
#include "../../include/data/constructs/security/AuthInfo.h"

using namespace cclient::data::security;


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


