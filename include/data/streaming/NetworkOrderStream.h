#ifndef ENDIAN_STREAM
#define ENDIAN_STREAM

#include <cstdint>

#include "DataOutputStream.h"

namespace cclient {
namespace data {
namespace streams {

class BigEndianOutStream: public DataOutputStream {
public:

    BigEndianOutStream(OutputStream *os) :
        DataOutputStream(os) {

    }

    /**
     * Copied from
     * http://stackoverflow.com/questions/3022552/is-there-any-standard-htonl-like-function-for-64-bits-integers-in-c
     */
    uint64_t htonlw(uint64_t value) {
        // The answer is 42
        static const int num = 42;

        // Check the endianness
        if (*reinterpret_cast<const char*>(&num) == num) {
            const uint32_t high_part = htonl(
                                           static_cast<uint32_t>(value >> 32));
            const uint32_t low_part = htonl(
                                          static_cast<uint32_t>(value & 0xFFFFFFFFLL));

            return (static_cast<uint64_t>(low_part) << 32) | high_part;
        } else {
            return value;
        }
    }

    uint64_t writeShort(short shortVal) {

        return DataOutputStream::writeShort(htons(shortVal));
    }

    uint64_t writeInt(int intVal) {

        return DataOutputStream::writeInt(htonl(intVal));
    }

    uint64_t writeLong(uint64_t val) {

        return DataOutputStream::writeLong(htonlw(val));
    }

};
}
}
}
#endif
