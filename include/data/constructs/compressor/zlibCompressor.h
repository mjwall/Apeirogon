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
#ifndef ZLIB_COMPRESSOR_H
#define ZLIB_COMPRESSOR_H

#include <exception>
#include <stdexcept>
#include "compressor.h"
#include "../../streaming/DataOutputStream.h"
#define GZ_NAME "gz"

namespace cclient {
namespace data {
namespace compression {

using namespace cclient::data::streams;

class ZLibCompressor: public Compressor {
public:
    ZLibCompressor() :
        Compressor(), rawSize(0), total_out(0), in_buf(NULL) {
        init = false;
        // initialize with the defautl buffer size.
        initialize(64 * 1024);
        buffer = NULL;
    }
    /**
     * Sets the input length and intializes the compressor
     * @param in_len input length
     */
    ZLibCompressor(uint32_t in_len) :
        Compressor(), rawSize(0), total_out(0), in_buf(NULL) {
        init = false;
        initialize(in_len);
        buffer = NULL;
    }

    virtual ~ZLibCompressor() {
    }

    /**
     * Returns the input length
     * @returns input length
     */
    uint32_t getBufferSize() {

        return input_length;
    }

    /**
     * Returns the compression overhead. Please ZLib for more info
     * @returns compression overhead
     */
    uint32_t getCompressionOverHead() {
        return (input_length >> 4) + 64 + 3;
    }

    /**
     * Returns the number of bytes written
     * @returns raw, uncompressed size, of the data
     *
     */
    uint32_t bytesWritten() {
        return rawSize;
    }

    /**
     * Returns the compressed size of the data
     * @returns total_out
     */
    uint32_t getCompressedSize() {
        return total_out;
    }

    /**
     * Compression method.
     * @param out_stream.
     */
    void compress(OutputStream *out_stream);

    /**
     * Deompression method.
     * @param out_stream.
     */
    void decompress(OutputStream *out_stream);

protected:

    /**
     * Initializes the Zlib compressor, accepts the input
     * length
     * @param in_len input length
     */
    void initialize(uint32_t in_len) {

        if (init) // do not re-initialize;
            return;

        Compressor::algorithm.setAlgorithm("gz");

        input_length = in_len;

        init = true;
    }

    string getName() {
        return GZ_NAME;
    }

    bool init;
    // z lib stream
    z_stream c_stream;
    // raw size of the uncompressed data.
    uint32_t rawSize;
    // input buffer.
    Bytef *in_buf;
    // total output size.
    uint32_t total_out;
    
    // output buffer.
    Bytef *out_buf;
    // input length.
    uint32_t input_length;
    // output length
    uint32_t output_length;

//	static DerivedCompressor<ZLibCompressor> reg;

};
}
}
}
#endif
