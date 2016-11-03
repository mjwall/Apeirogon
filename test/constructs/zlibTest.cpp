#include <iostream>

#include <stdexcept>
#include <cstring>

using namespace std;

#include <assert.h>

#include "../../../../../include/data/constructs/compressor/test/../compressor.h"
#include "../../../../../include/data/constructs/compressor/test/../zlibCompressor.h"
#include "../../../../../include/data/constructs/compressor/test/../../../streaming/dataoutstream.h"
#include "../../../../../include/data/constructs/compressor/test/../../../streaming/ByteOutputStream.h"

using namespace cclient::data::compression;
using namespace cclient::data::streams;
int main() {
	Compressor *compress = new ZLibCompressor(64 * 1024 * 1024);
	char test[4] = { 0xde, 0xad, 0xbe, 0xef };
	compress->setInput(test, 0, 4);
	ByteOutputStream outStream(1024);
	compress->compress(&outStream);

	char *compressed = outStream.getByteArray();
	uint32_t size = outStream.getPos();

	compress->setInput(compressed, 0, size);

	ByteOutputStream decStream(1024);
	compress->decompress(&decStream);

	assert( memcmp(decStream.getByteArray(),test,4) == 0);

	delete compress;
	compress = new ZLibCompressor(64 * 1024 * 1024);
	outStream.flush();
	compress->compress(&outStream);

	assert( outStream.getPos() == 0);

	cout << "Successfully passed" << endl;

}
