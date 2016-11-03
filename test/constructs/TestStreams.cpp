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

#include <string>
using namespace std;
#include "../../include/data/streaming/ByteOutputStream.h"
#include "../../include/data/streaming/input/ByteInputStream.h"
#include <hdfs/hdfs.h>


#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
using namespace cclient::data;
using namespace cclient::data::streams;


TEST_CASE("TestMain", "[TestMain]") {
	struct hdfsBuilder *builder = hdfsNewBuilder ();
	  hdfsFreeBuilder(builder);
}




TEST_CASE("TestByteStream", "[testSerDer]") {
  
  
	ByteOutputStream *endian = new ByteOutputStream(250 * 1024 * 1024);
	
	endian->writeInt(5);
	endian->writeString("Hello world");
	
	ByteInputStream *inVerification = new ByteInputStream(endian->getByteArray(),endian->getSize());
	
	REQUIRE(5 == inVerification->readInt());
	REQUIRE("Hello world" == inVerification->readString());
	
	
	
	delete inVerification;
	
	
	
	delete endian;
	
}
