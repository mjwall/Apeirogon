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
#include "../../include/data/constructs/column.h"
#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
using namespace cclient::data;



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
