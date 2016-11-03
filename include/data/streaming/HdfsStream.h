/*
 * HdfsStream.h
 *
 *  Created on: 28 Sep 2015
 *      Author: phrocker
 */

#ifndef SRC_DATA_STREAMING_HDFSSTREAM_H_
#define SRC_DATA_STREAMING_HDFSSTREAM_H_


#include <hdfs/hdfs.h>

#include <cstdint>


using namespace std;

#include "OutputStream.h"

namespace cclient {
namespace data {
namespace streams {
/**
 *
 *
 hdfsFile hdfsOpenFile(hdfsFS fs, const char * path, int flags, int bufferSize,
                      short replication, tOffset blocksize);
 *
 */
class HdfsStream : public OutputStream {
public:
    HdfsStream(hdfsFS fs, const char *path, const int flags, const int bufferSize, short replication, tOffset blockSize);
    virtual ~HdfsStream();
    virtual uint64_t getPos();
    uint64_t write(const char *bytes, long cnt);
    virtual uint64_t writeByte(int byte);
    virtual uint64_t writeString(string s);
    virtual uint64_t write(const uint8_t *bytes, long cnt);
    virtual uint64_t writeBytes(const uint8_t *bytes, size_t cnt);
    virtual uint64_t writeByte(const uint8_t byte);
    virtual uint64_t writeShort(const short shortVal);
    virtual uint64_t writeInt(const int intVal);
    virtual uint64_t writeLong(const uint64_t val);
    virtual uint64_t writeBoolean(const bool val);
protected:
    uint64_t amountWritten;
    hdfsFS fs;
    hdfsFile file;
};

} /* namespace streams */
} /* namespace data */
} /* namespace cclient */

#endif /* SRC_DATA_STREAMING_HDFSSTREAM_H_ */
