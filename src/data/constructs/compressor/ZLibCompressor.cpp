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
#include <stdexcept>
#include <cstring>
#include <vector>

using namespace std;

#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filter/gzip.hpp>

#include "../../../../include/data/constructs/compressor/../../streaming/OutputStream.h"
#include "../../../../include/data/constructs/compressor/compressor.h"
#include "../../../../include/data/constructs/compressor/zlibCompressor.h"


namespace io = boost::iostreams; //<-- good practice
typedef std::vector<char> buffer_t;

using namespace cclient::data::compression;

/**
 * Compression method.
 * @param out_stream.
 */
void
ZLibCompressor::compress (OutputStream *out_stream)
{
    if (!init)
        throw std::runtime_error (
            "Failure during compression; compression not initialized");

    if (len == 0)
        return;

    // variable used for the return code.
    int r = 0;


    c_stream.zalloc = (alloc_func) 0;
    c_stream.zfree = (free_func) 0;
    c_stream.opaque = (voidpf) 0;

    r = deflateInit(&c_stream, 6);
    if (r != Z_OK)
        throw std::runtime_error ("Failure initializing compression");

    rawSize += len;
    // estimate the output buffer.
    output_length = len + len / 1000 + 12 + 1;

    out_buf = new Bytef[output_length];

    in_buf = new Bytef[len];
    memcpy (in_buf, buffer + off, len);
    delete[] buffer;
    buffer = NULL;

    c_stream.next_in = in_buf;
    c_stream.next_out = out_buf;
    c_stream.avail_in = len;
    c_stream.avail_out = output_length;
    c_stream.total_in = 0;
    c_stream.total_out = 0;
    total_out = 0;

    /*
     * Attempt to go through all input data. we know we have enough
     * length in the out_buf to compress the data, so we will go through
     * as many attempts at compression as the compressor will allow.
     */
    while (c_stream.total_in < len && c_stream.total_out < output_length)
    {

        r = deflate (&c_stream, Z_NO_FLUSH);
        if (r != Z_OK)
            throw std::runtime_error ("Failure during compression; r != Z_OK");
    }
    // finish compression.
    r = deflate (&c_stream, Z_FINISH);

    if (r == Z_STREAM_END)
    {
        // if we have successful compression, write the data
        // to the output stream. and increment total_out.
        out_stream->write ((const char*) out_buf, c_stream.total_out);

        total_out += c_stream.total_out;
    }
    else
    {
        throw std::runtime_error (
            "Failure during compression; r != Z_STREAM_END");
    }

    len = 0;
    // delete the output buffer and end compression.
    delete[] out_buf;
    delete[] in_buf;

    deflateEnd (&c_stream);
    len = 0;

}

#define CHECK_ERR(err, msg) { \
    if (err != Z_OK) { \
	cout << "Error on " << msg << endl; \
        throw std::runtime_error ("Failure during decompression"); \
    } \
}

/**
 * Deompression method.
 * @param out_stream.
 */
void
ZLibCompressor::decompress (OutputStream *out_stream)
{
    if (!init)
        throw std::runtime_error (
            "Failure during compression; compression not initialized");

    if (len == 0)
        return;


    // variable used for the return code.
    int r = 0;


    c_stream.zalloc = (alloc_func) 0;
    c_stream.zfree = (free_func) 0;
    c_stream.opaque = (voidpf) 0;

    r = inflateInit(&c_stream);
    if (r != Z_OK)
        throw std::runtime_error ("Failure initializing compression");

    rawSize += len;
    // estimate the output buffer.

    output_length = len + len / 1000 + 12 + 1;

    out_buf = new Bytef[output_length];

    in_buf = new Bytef[len];
    memcpy (in_buf, buffer + off, len);
    delete[] buffer;
    buffer = NULL;

    c_stream.next_in = in_buf;
    c_stream.next_out = out_buf;
    c_stream.avail_in = len;
    c_stream.avail_out = output_length;
    c_stream.total_in = 0;
    c_stream.total_out = 0;
    total_out = 0;
    int ret = 0;
    int err = 0;
    int have = 0;
    for(uint32_t i=0; i <  len; i += output_length)
    {
        c_stream.avail_in = len - i;
        c_stream.next_in = in_buf + i;

        do {
            have =0;
            c_stream.avail_out = output_length;       // H
            c_stream.next_out = out_buf;

            ret = inflate(&c_stream, Z_NO_FLUSH);  // I

            assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
            switch (ret) {
            case Z_NEED_DICT:
                ret = Z_DATA_ERROR;     /* and fall through */
            case Z_DATA_ERROR:
            case Z_MEM_ERROR:

                (void)inflateEnd(&c_stream);
                CHECK_ERR(err, "Z_MEM_ERROR");
            }

            have = output_length - c_stream.avail_out;     // J
            out_stream->write ((const char*) out_buf,have);

        } while (c_stream.avail_out == 0);         // K
    }
    total_out += c_stream.total_out;
    err = inflateEnd(&c_stream);


    /*
      // finish compression.
      r = inflate (&c_stream, Z_FINISH);

      if (r == Z_STREAM_END)
        {
          // if we have successful compression, write the data
          // to the output stream. and increment total_out.
          out_stream->write ((const char*) out_buf, c_stream.total_out);

          total_out += c_stream.total_out;
        }
      else
        {
          throw std::runtime_error (
    	  "Failure during compression; r != Z_STREAM_END");
        }
    */
    len = 0;
    // delete the output buffer and end compression.
    delete[] out_buf;
    delete[] in_buf;


    len = 0;


}
