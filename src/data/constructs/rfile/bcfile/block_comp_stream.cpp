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
#include <fstream>
using namespace std;
#include "../../../../../include/data/constructs/rfile/bcfile/block_comp_stream.h"
#include "../../../../../include/data/constructs/compressor/compressor.h"
#include "../../../../../include/data/constructs/rfile/bcfile/../../../streaming/input/InputStream.h"
#include "../../../../../include/data/constructs/rfile/bcfile/../../../streaming/DataOutputStream.h"
#include "../../../../../include/data/constructs/rfile/bcfile/../../../streaming/input/NetworkOrderInputStream.h"
#include "../../../../../include/data/constructs/rfile/bcfile/../../../streaming/NetworkOrderStream.h"
using namespace cclient::data;
using namespace cclient::data::compression;
using namespace streams;

BlockCompressorStream::BlockCompressorStream (OutputStream *out_stream,
        Compressor *compressor,
        BlockRegion *region) :
    BlockStreambuffer (compressor->getBufferSize ()), DataOutputStream (
        new BigEndianOutStream (
            new OutputStream ((ostream*) this, out_stream->getPos ()))), compress (
                compressor), output_stream (out_stream), std::ostream (
                    (BlockStreambuffer*) this), std::istream(this), ios (0), blockLoc (0), writeStart (false), associatedRegion (
                        region)
{
}


BlockCompressorStream::BlockCompressorStream(InputStream *in_stream,  Compressor *decompressor,  BlockRegion *region) :
    BlockStreambuffer (decompressor->getBufferSize ()),DataOutputStream (NULL),EndianInputStream(),std::istream(this), ios (0), blockLoc (0), writeStart (false), associatedRegion(region),output_stream(NULL),compress (
        decompressor)
{
    uint64_t prevPosition = in_stream->getPos();

    in_stream->seek (region->getOffset ());

    uint8_t *compressedValue = new uint8_t[region->getCompressedSize ()];

    in_stream->readBytes (compressedValue, region->getCompressedSize ());

    decompressor->setInput ((const char*) compressedValue, 0,
                            region->getCompressedSize ());

    ByteOutputStream *outStream = new ByteOutputStream (
        region->getRawSize ());

    decompressor->decompress (outStream);

    cout << "array " << outStream->getSize() << "- " << outStream->getByteArray() <<  endl;

    setArray(outStream->getByteArray (), outStream->getSize (), true);

    cout << "oh boi" << endl;
    // reset the location

    in_stream->seek(prevPosition);

    delete[] compressedValue;

    delete outStream;


}

BlockCompressorStream::~BlockCompressorStream ()
{

    compress = NULL;
    //     delete compress;
}

