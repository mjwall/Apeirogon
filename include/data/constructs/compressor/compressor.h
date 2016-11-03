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
#ifndef COMPRESSOR
#define COMPRESSOR

#include <stdexcept>

#include "../../streaming/DataOutputStream.h"
#include "algorithm.h"

#include "zlib.h"

namespace cclient
{
namespace data
{
namespace compression
{

using namespace cclient::data::streams;

class Compressor
{
public:

    Compressor () :
        len (0), off (0), stream_offset (0)
    {
        buffer = NULL;
    }

    virtual
    ~Compressor ()
    {

        if (buffer != NULL)
            delete[] buffer;
        buffer=NULL;
    }
    /**
     Set the input.
     @param b input buffer.
     @param offset offset within this buffer.
     @param length input length.
     **/
    void
    setInput (const char *b, uint32_t offset, uint32_t length);

    /**
     Sets the stream offset.
     @param soff stream offset.
     **/
    void
    setStreamOffset (uint32_t soff)
    {
        stream_offset = soff;
    }

    /**
     Retrieves the stream offset.
     @return stream offset.
     **/
    uint32_t
    getStreamOffset ()
    {
        return stream_offset;
    }

    /**
     Pure virtual function that sparks
     compression. It is intended that each call to compress
     be exclusive so that the compressor can be reused.
     @param out_stream output stream.
     **/
    virtual void
    compress (OutputStream *out_stream) = 0;

    /**
     * Pure virtual function that sparks decompression.
     * It is intended to be used following setInput
     * @param out_stream output stream.
     */
    virtual void
    decompress (OutputStream *out_stream)
    {
        throw std::runtime_error ("Decompression not supported");
    }

    /**
     Retrieves the buffer size.
     @return buffer size.
     **/
    virtual uint32_t
    getBufferSize () = 0;

    /**
     Returns the compression overhead for the algorithm.
     @return compression overhead.
     **/
    virtual uint32_t
    getCompressionOverHead () = 0;

    /**
     Returns the bytes written thus far.
     This is defined by the codec
     @return bytes written.
     **/
    virtual uint32_t
    bytesWritten () = 0;

    /**
     Returns the compressed size.
     @return compressed size.
     **/
    virtual uint32_t
    getCompressedSize () = 0;

    /**
     Returns the compression algorithm for this compressor
     @returns CompressionAlgorithm instance.
     **/
    Algorithm &
    getAlgorithm ()
    {
        return algorithm;
    }

    /**
     * Returns the canonical name for this compressor
     * @returns canonical name
     */
    virtual string
    getName () = 0;

    /**
     * Gets the number of bytes read
     * @returns bytes read
     */
    int
    getBytesRead ()
    {
        return len;
    }

protected:
    // buffer length.
    uint32_t len;
    // offset within buffer.
    uint32_t off;
    // stream offset.
    uint32_t stream_offset;
    // input buffer.
    char *buffer;
    Algorithm algorithm;
    
    
    

};

}
}
}

#endif
