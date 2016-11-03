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

#ifndef DATAINDEX_H_
#define DATAINDEX_H_

#include <vector>

using namespace std;

#include "../../compressor/compressor.h"
#include "../../compressor/compression_algorithm.h"
#include "../../../streaming/DataOutputStream.h"
#include "../../../streaming/Streams.h"

#include "BlockRegion.h"
namespace cclient {
namespace data {
using namespace compression;
using namespace cclient::data::streams;
class DataIndex: public StreamInterface {
public:
    DataIndex(Compressor *compressor);
    DataIndex();
    ~DataIndex();

    void setCompressionAlgorithm(Compressor *compressor)

    {
        compressionAlgorithm = compressor->getAlgorithm();
    }

    BlockRegion *addBlockRegion(BlockRegion region) {
        BlockRegion *reg = new BlockRegion(region);
        reg->setCompressor(compressionAlgorithm.create());
        listRegions.push_back(reg);
        return reg;
    }

    BlockRegion *addBlockRegion() {
        BlockRegion *reg = new BlockRegion();
        reg->setCompressor(compressionAlgorithm.create());
        listRegions.push_back(reg);
        return reg;
    }

    BlockRegion *getBlockRegion(int index) {
        return listRegions.at(index);
    }

    CompressionAlgorithm getCompressionAlgorithm() {
        return compressionAlgorithm;
    }

    uint64_t  read(InputStream *in) {
        compressionAlgorithm = CompressionAlgorithm(in->readString());

        uint64_t count = in->readEncodedLong();

        cout << "count is " << count << endl;

        for (uint64_t i = 0; i < count; i++) {
            listRegions.push_back(new BlockRegion(in));
        }

        cout << "finished reading " << endl;

        return in->getPos();
    }

    uint64_t write(OutputStream *out) {

        out->writeString(compressionAlgorithm.getName());

        out->writeEncodedLong(listRegions.size());
        for (vector<BlockRegion*>::iterator it = listRegions.begin();
                it != listRegions.end(); it++) {
            (*it)->write(out);
        }

        return out->getPos();
    }

    DataIndex &operator=(const DataIndex &other) {
        compressionAlgorithm = other.compressionAlgorithm;
        listRegions.insert(listRegions.end(), other.listRegions.begin(),
                           other.listRegions.end());
	return *this;
    }

protected:
    vector<BlockRegion*> listRegions;
    CompressionAlgorithm compressionAlgorithm;

};
}
}
#endif /* DATAINDEX_H_ */
