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
#ifndef COMPRESSION_ALGO
#define COMPRESSION_ALGO
#include <string>

using namespace std;

#include "algorithm.h"
#include "compressor.h"
#include "zlibCompressor.h"

namespace cclient
{
namespace data
{
namespace compression
{

class CompressionAlgorithm : public Algorithm
{
public:
    CompressionAlgorithm () :
        Algorithm ("")
    {

    }

    CompressionAlgorithm (const string compressionName) :
        Algorithm (compressionName)
    {

    }

    CompressionAlgorithm (Algorithm other) :
        Algorithm (other.getAlgorithm())
    {

    }

    Compressor *
    create ()
    {
        if (compressionAlgo == "gz")
        {
            return new ZLibCompressor ();
        }
        else
        {
            std::runtime_error ("Unsupported compression algorithm");
        }
        return 0;
    }

    CompressionAlgorithm &
    operator= (const Algorithm &other)
    {
        this->setAlgorithm( other.getAlgorithm() );
        return *this;
    }

};
}
}
}
#endif

