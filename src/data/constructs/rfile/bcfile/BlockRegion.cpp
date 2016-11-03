/*
 * BlockRegion.cpp
 *
 *  Created on: May 1, 2015
 *      Author: marc
 */

#include "../../../../../include/data/constructs/rfile/bcfile/BlockRegion.h"

using namespace cclient::data;
using namespace cclient::data::streams;
uint64_t
BlockRegion::read (InputStream *in)
{
    offset = in->readHadoopLong ();
    compressedSize = in->readHadoopLong ();
    rawSize = in->readHadoopLong ();
    cout << "offset is " << offset << " compressedSize is " << compressedSize << "  rawSize is " << rawSize << " position is " << in->getPos() << endl;
    return in->getPos ();
}

uint64_t
BlockRegion::write (OutputStream *out)
{
    /*if (compressor != NULL)
     {
     // only set these values if the compressor isn't null
     // otherwise take what we have.
     setOffset( compressor->getStreamOffset() );
     setCompressedSize(compressor->getCompressedSize());
     setRawSize(compressor->bytesWritten());
     }*/
    out->writeEncodedLong (offset);
    out->writeEncodedLong (compressedSize);
    uint64_t pos = out->writeEncodedLong(rawSize);
    cout << "offset is " << offset << " compressedSize is " << compressedSize << "  rawSize is " << rawSize << " position is " << pos << endl;
    return pos;

}
