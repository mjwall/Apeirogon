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
#include "../../../../include/data/extern/thrift/trace_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace org
{
  namespace apache
  {
    namespace accumulo
    {
      namespace trace
      {
	namespace thrift
	{

	  RemoteSpan::~RemoteSpan () throw ()
	  {
	  }

	  void
	  RemoteSpan::__set_sender (const std::string& val)
	  {
	    this->sender = val;
	  }

	  void
	  RemoteSpan::__set_svc (const std::string& val)
	  {
	    this->svc = val;
	  }

	  void
	  RemoteSpan::__set_traceId (const int64_t val)
	  {
	    this->traceId = val;
	  }

	  void
	  RemoteSpan::__set_spanId (const int64_t val)
	  {
	    this->spanId = val;
	  }

	  void
	  RemoteSpan::__set_parentId (const int64_t val)
	  {
	    this->parentId = val;
	  }

	  void
	  RemoteSpan::__set_start (const int64_t val)
	  {
	    this->start = val;
	  }

	  void
	  RemoteSpan::__set_stop (const int64_t val)
	  {
	    this->stop = val;
	  }

	  void
	  RemoteSpan::__set_description (const std::string& val)
	  {
	    this->description = val;
	  }

	  void
	  RemoteSpan::__set_data (
	      const std::map<std::string, std::string> & val)
	  {
	    this->data = val;
	  }

	  const char* RemoteSpan::ascii_fingerprint =
	      "22EA46E738FDCE7962363D25AEC46FDF";
	  const uint8_t RemoteSpan::binary_fingerprint[16] =
	    { 0x22, 0xEA, 0x46, 0xE7, 0x38, 0xFD, 0xCE, 0x79, 0x62, 0x36, 0x3D,
		0x25, 0xAE, 0xC4, 0x6F, 0xDF };

	  uint32_t
	  RemoteSpan::read (::apache::thrift::protocol::TProtocol* iprot)
	  {

	    uint32_t xfer = 0;
	    std::string fname;
	    ::apache::thrift::protocol::TType ftype;
	    int16_t fid;

	    xfer += iprot->readStructBegin (fname);

	    using ::apache::thrift::protocol::TProtocolException;

	    while (true)
	      {
		xfer += iprot->readFieldBegin (fname, ftype, fid);
		if (ftype == ::apache::thrift::protocol::T_STOP)
		  {
		    break;
		  }
		switch (fid)
		  {
		  case 1:
		    if (ftype == ::apache::thrift::protocol::T_STRING)
		      {
			xfer += iprot->readString (this->sender);
			this->__isset.sender = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 2:
		    if (ftype == ::apache::thrift::protocol::T_STRING)
		      {
			xfer += iprot->readString (this->svc);
			this->__isset.svc = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 3:
		    if (ftype == ::apache::thrift::protocol::T_I64)
		      {
			xfer += iprot->readI64 (this->traceId);
			this->__isset.traceId = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 4:
		    if (ftype == ::apache::thrift::protocol::T_I64)
		      {
			xfer += iprot->readI64 (this->spanId);
			this->__isset.spanId = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 5:
		    if (ftype == ::apache::thrift::protocol::T_I64)
		      {
			xfer += iprot->readI64 (this->parentId);
			this->__isset.parentId = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 6:
		    if (ftype == ::apache::thrift::protocol::T_I64)
		      {
			xfer += iprot->readI64 (this->start);
			this->__isset.start = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 7:
		    if (ftype == ::apache::thrift::protocol::T_I64)
		      {
			xfer += iprot->readI64 (this->stop);
			this->__isset.stop = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 8:
		    if (ftype == ::apache::thrift::protocol::T_STRING)
		      {
			xfer += iprot->readString (this->description);
			this->__isset.description = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 9:
		    if (ftype == ::apache::thrift::protocol::T_MAP)
		      {
			  {
			    this->data.clear ();
			    uint32_t _size0;
			    ::apache::thrift::protocol::TType _ktype1;
			    ::apache::thrift::protocol::TType _vtype2;
			    xfer += iprot->readMapBegin (_ktype1, _vtype2,
							 _size0);
			    uint32_t _i4;
			    for (_i4 = 0; _i4 < _size0; ++_i4)
			      {
				std::string _key5;
				xfer += iprot->readString (_key5);
				std::string& _val6 = this->data[_key5];
				xfer += iprot->readString (_val6);
			      }
			    xfer += iprot->readMapEnd ();
			  }
			this->__isset.data = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  default:
		    xfer += iprot->skip (ftype);
		    break;
		  }
		xfer += iprot->readFieldEnd ();
	      }

	    xfer += iprot->readStructEnd ();

	    return xfer;
	  }

	  uint32_t
	  RemoteSpan::write (::apache::thrift::protocol::TProtocol* oprot) const
	  {
	    uint32_t xfer = 0;
	    oprot->incrementRecursionDepth ();
	    xfer += oprot->writeStructBegin ("RemoteSpan");

	    xfer += oprot->writeFieldBegin (
		"sender", ::apache::thrift::protocol::T_STRING, 1);
	    xfer += oprot->writeString (this->sender);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin (
		"svc", ::apache::thrift::protocol::T_STRING, 2);
	    xfer += oprot->writeString (this->svc);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin ("traceId",
					    ::apache::thrift::protocol::T_I64,
					    3);
	    xfer += oprot->writeI64 (this->traceId);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin ("spanId",
					    ::apache::thrift::protocol::T_I64,
					    4);
	    xfer += oprot->writeI64 (this->spanId);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin ("parentId",
					    ::apache::thrift::protocol::T_I64,
					    5);
	    xfer += oprot->writeI64 (this->parentId);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin ("start",
					    ::apache::thrift::protocol::T_I64,
					    6);
	    xfer += oprot->writeI64 (this->start);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin ("stop",
					    ::apache::thrift::protocol::T_I64,
					    7);
	    xfer += oprot->writeI64 (this->stop);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin (
		"description", ::apache::thrift::protocol::T_STRING, 8);
	    xfer += oprot->writeString (this->description);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin ("data",
					    ::apache::thrift::protocol::T_MAP,
					    9);
	      {
		xfer += oprot->writeMapBegin (
		    ::apache::thrift::protocol::T_STRING,
		    ::apache::thrift::protocol::T_STRING,
		    static_cast<uint32_t> (this->data.size ()));
		std::map<std::string, std::string>::const_iterator _iter7;
		for (_iter7 = this->data.begin (); _iter7 != this->data.end ();
		    ++_iter7)
		  {
		    xfer += oprot->writeString (_iter7->first);
		    xfer += oprot->writeString (_iter7->second);
		  }
		xfer += oprot->writeMapEnd ();
	      }
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldStop ();
	    xfer += oprot->writeStructEnd ();
	    oprot->decrementRecursionDepth ();
	    return xfer;
	  }

	  void
	  swap (RemoteSpan &a, RemoteSpan &b)
	  {
	    using ::std::swap;
	    swap (a.sender, b.sender);
	    swap (a.svc, b.svc);
	    swap (a.traceId, b.traceId);
	    swap (a.spanId, b.spanId);
	    swap (a.parentId, b.parentId);
	    swap (a.start, b.start);
	    swap (a.stop, b.stop);
	    swap (a.description, b.description);
	    swap (a.data, b.data);
	    swap (a.__isset, b.__isset);
	  }

	  RemoteSpan::RemoteSpan (const RemoteSpan& other8)
	  {
	    sender = other8.sender;
	    svc = other8.svc;
	    traceId = other8.traceId;
	    spanId = other8.spanId;
	    parentId = other8.parentId;
	    start = other8.start;
	    stop = other8.stop;
	    description = other8.description;
	    data = other8.data;
	    __isset = other8.__isset;
	  }
	  RemoteSpan&
	  RemoteSpan::operator= (const RemoteSpan& other9)
	  {
	    sender = other9.sender;
	    svc = other9.svc;
	    traceId = other9.traceId;
	    spanId = other9.spanId;
	    parentId = other9.parentId;
	    start = other9.start;
	    stop = other9.stop;
	    description = other9.description;
	    data = other9.data;
	    __isset = other9.__isset;
	    return *this;
	  }
	  std::ostream&
	  operator<< (std::ostream& out, const RemoteSpan& obj)
	  {
	    using ::apache::thrift::to_string;
	    out << "RemoteSpan(";
	    out << "sender=" << to_string (obj.sender);
	    out << ", " << "svc=" << to_string (obj.svc);
	    out << ", " << "traceId=" << to_string (obj.traceId);
	    out << ", " << "spanId=" << to_string (obj.spanId);
	    out << ", " << "parentId=" << to_string (obj.parentId);
	    out << ", " << "start=" << to_string (obj.start);
	    out << ", " << "stop=" << to_string (obj.stop);
	    out << ", " << "description=" << to_string (obj.description);
	    out << ", " << "data=" << to_string (obj.data);
	    out << ")";
	    return out;
	  }

	  TInfo::~TInfo () throw ()
	  {
	  }

	  void
	  TInfo::__set_traceId (const int64_t val)
	  {
	    this->traceId = val;
	  }

	  void
	  TInfo::__set_parentId (const int64_t val)
	  {
	    this->parentId = val;
	  }

	  const char* TInfo::ascii_fingerprint =
	      "F33135321253DAEB67B0E79E416CA831";
	  const uint8_t TInfo::binary_fingerprint[16] =
	    { 0xF3, 0x31, 0x35, 0x32, 0x12, 0x53, 0xDA, 0xEB, 0x67, 0xB0, 0xE7,
		0x9E, 0x41, 0x6C, 0xA8, 0x31 };

	  uint32_t
	  TInfo::read (::apache::thrift::protocol::TProtocol* iprot)
	  {

	    uint32_t xfer = 0;
	    std::string fname;
	    ::apache::thrift::protocol::TType ftype;
	    int16_t fid;

	    xfer += iprot->readStructBegin (fname);

	    using ::apache::thrift::protocol::TProtocolException;

	    while (true)
	      {
		xfer += iprot->readFieldBegin (fname, ftype, fid);
		if (ftype == ::apache::thrift::protocol::T_STOP)
		  {
		    break;
		  }
		switch (fid)
		  {
		  case 1:
		    if (ftype == ::apache::thrift::protocol::T_I64)
		      {
			xfer += iprot->readI64 (this->traceId);
			this->__isset.traceId = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 2:
		    if (ftype == ::apache::thrift::protocol::T_I64)
		      {
			xfer += iprot->readI64 (this->parentId);
			this->__isset.parentId = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  default:
		    xfer += iprot->skip (ftype);
		    break;
		  }
		xfer += iprot->readFieldEnd ();
	      }

	    xfer += iprot->readStructEnd ();

	    return xfer;
	  }

	  uint32_t
	  TInfo::write (::apache::thrift::protocol::TProtocol* oprot) const
	  {
	    uint32_t xfer = 0;
	    oprot->incrementRecursionDepth ();
	    xfer += oprot->writeStructBegin ("TInfo");

	    xfer += oprot->writeFieldBegin ("traceId",
					    ::apache::thrift::protocol::T_I64,
					    1);
	    xfer += oprot->writeI64 (this->traceId);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin ("parentId",
					    ::apache::thrift::protocol::T_I64,
					    2);
	    xfer += oprot->writeI64 (this->parentId);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldStop ();
	    xfer += oprot->writeStructEnd ();
	    oprot->decrementRecursionDepth ();
	    return xfer;
	  }

	  void
	  swap (TInfo &a, TInfo &b)
	  {
	    using ::std::swap;
	    swap (a.traceId, b.traceId);
	    swap (a.parentId, b.parentId);
	    swap (a.__isset, b.__isset);
	  }

	  TInfo::TInfo (const TInfo& other10)
	  {
	    traceId = other10.traceId;
	    parentId = other10.parentId;
	    __isset = other10.__isset;
	  }
	  TInfo&
	  TInfo::operator= (const TInfo& other11)
	  {
	    traceId = other11.traceId;
	    parentId = other11.parentId;
	    __isset = other11.__isset;
	    return *this;
	  }
	  std::ostream&
	  operator<< (std::ostream& out, const TInfo& obj)
	  {
	    using ::apache::thrift::to_string;
	    out << "TInfo(";
	    out << "traceId=" << to_string (obj.traceId);
	    out << ", " << "parentId=" << to_string (obj.parentId);
	    out << ")";
	    return out;
	  }

	}
      }
    }
  }
} // namespace
