/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2015
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
#ifndef INCLUDE_DATA_CONSTRUCTS_COMPRESSOR_ALGORITHM_H_
#define INCLUDE_DATA_CONSTRUCTS_COMPRESSOR_ALGORITHM_H_
#include <string>

using namespace std;

namespace cclient
{
namespace data
{
namespace compression
{

class Algorithm
{
public:
    Algorithm () :
        compressionAlgo ("")
    {

    }

    Algorithm (const string compressionName) :
        compressionAlgo (compressionName)
    {

    }

    /**
     * Set the algorithm name
     * @param algorithm algorithm name
     */
    void
    setAlgorithm (const string algorithm)
    {
        compressionAlgo = algorithm;
    }

    /**
     * Get the algorithm name
     * @returns algorith name
     */
    string
    getName ()
    {
        return compressionAlgo;
    }

    Algorithm &
    operator= (const Algorithm &other)
    {
        compressionAlgo = other.compressionAlgo;
        return *this;
    }

    std::string getAlgorithm() const
    {
        return compressionAlgo;
    }

protected:
    std::string compressionAlgo;

};
}
}
}
#endif /* INCLUDE_DATA_CONSTRUCTS_COMPRESSOR_ALGORITHM_H_ */
