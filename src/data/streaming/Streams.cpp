#include "../../../include/data/streaming/ByteOutputStream.h"
#include "../../../include/data/streaming/OutputStream.h"
#include "../../../include/data/streaming/Streams.h"

#include "../../../include/data/streaming/input/ByteInputStream.h"
#include "../../../include/data/streaming/input/InputStream.h"

/*
 */

using namespace cclient::data::streams;

StreamInterface::StreamInterface ()
{

}

StreamInterface::~StreamInterface ()
{

}

StreamInterface*
StreamInterface::getStream ()
{
    return NULL;
}

uint64_t
StreamInterface::write (OutputStream *out)
{
    return 0;
}

uint64_t
StreamInterface::read (InputStream *in)
{
    return 0;
}

