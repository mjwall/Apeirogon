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
