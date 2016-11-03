/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * Key/value connector. Copyright (C)  2015
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

