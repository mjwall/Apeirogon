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
#ifndef BLOCK_COMP_STREAM_H_
#define BLOCK_COMP_STREAM_H_
#include <iostream>
#include <vector>
using namespace std;

#include "../../compressor/compressor.h"
#include "../../../streaming/Streams.h"
#include "../../../streaming/input/NetworkOrderInputStream.h"
#include "BlockRegion.h"

namespace cclient {
namespace data {

class BlockStreambuffer: public streambuf {
public:

    BlockStreambuffer(size_t s) :
        bfptr(new char[s]), max_size(s) {

    }
    virtual ~BlockStreambuffer() {
        delete[] bfptr;
    }

    char *getPtr() {

        return bfptr;
    }

    virtual streamsize xsputn(const char * s, streamsize n) = 0;

protected:
    size_t max_size;
private:
    char* bfptr;
};

using namespace compression;
using namespace cclient::data::streams;
class BlockCompressorStream: private BlockStreambuffer,
    public DataOutputStream,
    public EndianInputStream,
    public ostream,
    public istream {

public:
    // takes ownership of the compressor
    BlockCompressorStream(OutputStream *out_stream, Compressor *compressor,
                          BlockRegion *region);

    BlockCompressorStream(InputStream *in_stream,Compressor *decompressor,BlockRegion *region);

    ~BlockCompressorStream();

    inline virtual int sync() {
	return 0;

    }
    /**
     * Returns the number of bytes written
     * @returns number of bytes written by the compressor
     * and any remaining data left in the growing buffer.
     **/
    uint32_t bytesWritten() {
        return compress->bytesWritten() + growingBuffer.size();
    }

    /**
     * Returns the current position.
     * @returns the current position of the output stream.
     */
    uint64_t getPos() {
        if (NULL != output_stream) {
            return output_stream->getPos();
        } else {
            return EndianInputStream::getPos();
        }

    }

    /**
     * Returns the reference to the compressor
     */
    Compressor *getCompressor() {

        return compress;
    }

    /**
     * Flushes the block compressor stream.
     * should be called when finished or by xsputn
     */
    void flush() {

        output_stream_ref->getPos();
        ostream_ref->flush();
        size_t location = growingBuffer.size();
        if (location == 0)
            return;

        // copy the input bufer to the compressor and call the
        // compress function on it.

        compress->setInput(&growingBuffer.at(0), 0, location);
        compress->compress(output_stream);

        associatedRegion->setOffset(compress->getStreamOffset());
        associatedRegion->setRawSize(compress->bytesWritten());
        associatedRegion->setCompressedSize(compress->getCompressedSize());
        // clear the buffer and the block location so that
        // this object can be reused.
        growingBuffer.clear();
        blockLoc = 0;
    }

    inline int overflow( int ch ) {
      return ch;
    }

    /**
     * Function is automatically called by the output stream since
     * we are based on sstream.
     * @param s the input buffer
     * @param n stream size
     * @returns stream size written
     */

    inline streamsize xsputn(const char * s, streamsize n) {

        if (n == 0)
            return 0;
        // if we have not started writing we need to set the stream
        // offset of the compressor
        if (!writeStart)
            compress->setStreamOffset(output_stream->getPos());

        writeStart = true;

        size_t location = growingBuffer.size();
        // resize the growing buffer.
        growingBuffer.resize(location + n);

        memcpy(&growingBuffer.at(location), s, n);

        return n;
    }

protected:
    // output steram.
    OutputStream *output_stream;
    // block location.
    uint64_t blockLoc;
    vector<char> growingBuffer;
    // identifies whether compression has started
    // if not true, then we neet to set the stream offset
    bool writeStart;
    // compressor reference.
    Compressor *compress;
    BlockRegion *associatedRegion;

    InputStream *input_stream;

};
}
}
#endif /* BLOCK_COMP_STREAM_H_ */
