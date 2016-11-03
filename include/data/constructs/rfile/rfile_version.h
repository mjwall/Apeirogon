#ifndef RVERSION
#define RVERSION

#include "../../streaming/Streams.h"
#include "../../streaming/DataOutputStream.h"

namespace cclient {
namespace data {

using namespace cclient::data::streams;

#define VERSION_SIZE 4

class RFileVersion: public StreamInterface {

public:

    RFileVersion() :
        maj(0), min(0) {

    }

    /**
     * Constructor for RFile Version
     * @param majorV major version
     * @param minorV minor version
     */
    RFileVersion(const short majorV, const short minorV) :
        maj(majorV), min(minorV) {

    }

    RFileVersion(InputStream *input)
    {
        maj = input->readShort();
        min = input->readShort();
    }


    uint64_t read(InputStream *input)
    {
        maj = input->readShort();
        min = input->readShort();
        return input->getPos();
    }

    /**
     * Write the RFile File Version
     * @param out output stream
     * @returns location of output stream
     */
    uint64_t write(OutputStream *out) {

        out->writeShort(maj);
        return out->writeShort(min);
    }

    /**
     * Sets the major version
     * @param val major version
     */
    void setMajor(const short val) {

        maj = val;
    }

    /**
     * Gets the major version
     * @returns the major versions
     */
    short getMajor() {
        return maj;
    }

    /**
     * Sets the minor version
     * @param val minor version
     */
    void setMinor(const short val) {
        min = val;
    }

    /**
     * Returns the minor version
     * @returns minor version
     */
    short getMinor() {
        return min;
    }

public:

    // major and minor versions.
    short maj, min;

};
}
}

#endif
