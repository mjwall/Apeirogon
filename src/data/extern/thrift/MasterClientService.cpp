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
#include "../../../../include/data/extern/thrift/MasterClientService.h"

namespace org
{
  namespace apache
  {
    namespace accumulo
    {
      namespace core
      {
	namespace master
	{
	  namespace thrift
	  {

	    MasterClientService_initiateFlush_args::~MasterClientService_initiateFlush_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_initiateFlush_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tableName);
			  this->__isset.tableName = true;
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
	    MasterClientService_initiateFlush_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_initiateFlush_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->tableName);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_initiateFlush_pargs::~MasterClientService_initiateFlush_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_initiateFlush_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_initiateFlush_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->tableName)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_initiateFlush_result::~MasterClientService_initiateFlush_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_initiateFlush_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->success);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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
	    MasterClientService_initiateFlush_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_initiateFlush_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_I64, 0);
		  xfer += oprot->writeI64 (this->success);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.tope)
		{
		  xfer += oprot->writeFieldBegin (
		      "tope", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->tope.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_initiateFlush_presult::~MasterClientService_initiateFlush_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_initiateFlush_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 ((*(this->success)));
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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

	    MasterClientService_waitForFlush_args::~MasterClientService_waitForFlush_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_waitForFlush_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tableName);
			  this->__isset.tableName = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->startRow);
			  this->__isset.startRow = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->endRow);
			  this->__isset.endRow = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->flushID);
			  this->__isset.flushID = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->maxLoops);
			  this->__isset.maxLoops = true;
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
	    MasterClientService_waitForFlush_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_waitForFlush_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->tableName);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("flushID",
					      ::apache::thrift::protocol::T_I64,
					      3);
	      xfer += oprot->writeI64 (this->flushID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("maxLoops",
					      ::apache::thrift::protocol::T_I64,
					      4);
	      xfer += oprot->writeI64 (this->maxLoops);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "startRow", ::apache::thrift::protocol::T_STRING, 6);
	      xfer += oprot->writeBinary (this->startRow);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "endRow", ::apache::thrift::protocol::T_STRING, 7);
	      xfer += oprot->writeBinary (this->endRow);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_waitForFlush_pargs::~MasterClientService_waitForFlush_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_waitForFlush_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_waitForFlush_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->tableName)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("flushID",
					      ::apache::thrift::protocol::T_I64,
					      3);
	      xfer += oprot->writeI64 ((*(this->flushID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("maxLoops",
					      ::apache::thrift::protocol::T_I64,
					      4);
	      xfer += oprot->writeI64 ((*(this->maxLoops)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "startRow", ::apache::thrift::protocol::T_STRING, 6);
	      xfer += oprot->writeBinary ((*(this->startRow)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "endRow", ::apache::thrift::protocol::T_STRING, 7);
	      xfer += oprot->writeBinary ((*(this->endRow)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_waitForFlush_result::~MasterClientService_waitForFlush_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_waitForFlush_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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
	    MasterClientService_waitForFlush_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_waitForFlush_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.tope)
		{
		  xfer += oprot->writeFieldBegin (
		      "tope", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->tope.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_waitForFlush_presult::~MasterClientService_waitForFlush_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_waitForFlush_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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

	    MasterClientService_setTableProperty_args::~MasterClientService_setTableProperty_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setTableProperty_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tableName);
			  this->__isset.tableName = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->property);
			  this->__isset.property = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->value);
			  this->__isset.value = true;
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
	    MasterClientService_setTableProperty_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setTableProperty_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->tableName);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->property);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "value", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString (this->value);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_setTableProperty_pargs::~MasterClientService_setTableProperty_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setTableProperty_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setTableProperty_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->tableName)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString ((*(this->property)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "value", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString ((*(this->value)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_setTableProperty_result::~MasterClientService_setTableProperty_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setTableProperty_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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
	    MasterClientService_setTableProperty_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setTableProperty_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.tope)
		{
		  xfer += oprot->writeFieldBegin (
		      "tope", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->tope.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_setTableProperty_presult::~MasterClientService_setTableProperty_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setTableProperty_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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

	    MasterClientService_removeTableProperty_args::~MasterClientService_removeTableProperty_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeTableProperty_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tableName);
			  this->__isset.tableName = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->property);
			  this->__isset.property = true;
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
	    MasterClientService_removeTableProperty_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_removeTableProperty_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->tableName);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->property);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_removeTableProperty_pargs::~MasterClientService_removeTableProperty_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeTableProperty_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_removeTableProperty_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->tableName)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString ((*(this->property)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_removeTableProperty_result::~MasterClientService_removeTableProperty_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeTableProperty_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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
	    MasterClientService_removeTableProperty_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_removeTableProperty_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.tope)
		{
		  xfer += oprot->writeFieldBegin (
		      "tope", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->tope.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_removeTableProperty_presult::~MasterClientService_removeTableProperty_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeTableProperty_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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

	    MasterClientService_setNamespaceProperty_args::~MasterClientService_setNamespaceProperty_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setNamespaceProperty_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->ns);
			  this->__isset.ns = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->property);
			  this->__isset.property = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->value);
			  this->__isset.value = true;
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
	    MasterClientService_setNamespaceProperty_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setNamespaceProperty_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ns", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->ns);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->property);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "value", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString (this->value);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_setNamespaceProperty_pargs::~MasterClientService_setNamespaceProperty_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setNamespaceProperty_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setNamespaceProperty_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ns", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->ns)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString ((*(this->property)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "value", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString ((*(this->value)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_setNamespaceProperty_result::~MasterClientService_setNamespaceProperty_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setNamespaceProperty_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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
	    MasterClientService_setNamespaceProperty_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setNamespaceProperty_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.tope)
		{
		  xfer += oprot->writeFieldBegin (
		      "tope", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->tope.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_setNamespaceProperty_presult::~MasterClientService_setNamespaceProperty_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setNamespaceProperty_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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

	    MasterClientService_removeNamespaceProperty_args::~MasterClientService_removeNamespaceProperty_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeNamespaceProperty_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->ns);
			  this->__isset.ns = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->property);
			  this->__isset.property = true;
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
	    MasterClientService_removeNamespaceProperty_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_removeNamespaceProperty_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ns", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->ns);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->property);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_removeNamespaceProperty_pargs::~MasterClientService_removeNamespaceProperty_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeNamespaceProperty_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_removeNamespaceProperty_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ns", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->ns)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString ((*(this->property)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_removeNamespaceProperty_result::~MasterClientService_removeNamespaceProperty_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeNamespaceProperty_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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
	    MasterClientService_removeNamespaceProperty_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_removeNamespaceProperty_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.tope)
		{
		  xfer += oprot->writeFieldBegin (
		      "tope", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->tope.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_removeNamespaceProperty_presult::~MasterClientService_removeNamespaceProperty_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeNamespaceProperty_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tope.read (iprot);
			  this->__isset.tope = true;
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

	    MasterClientService_setMasterGoalState_args::~MasterClientService_setMasterGoalState_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setMasterGoalState_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast90;
			  xfer += iprot->readI32 (ecast90);
			  this->state = (MasterGoalState::type) ecast90;
			  this->__isset.state = true;
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
	    MasterClientService_setMasterGoalState_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setMasterGoalState_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("state",
					      ::apache::thrift::protocol::T_I32,
					      2);
	      xfer += oprot->writeI32 ((int32_t) this->state);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_setMasterGoalState_pargs::~MasterClientService_setMasterGoalState_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setMasterGoalState_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setMasterGoalState_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("state",
					      ::apache::thrift::protocol::T_I32,
					      2);
	      xfer += oprot->writeI32 ((int32_t) (*(this->state)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_setMasterGoalState_result::~MasterClientService_setMasterGoalState_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setMasterGoalState_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    MasterClientService_setMasterGoalState_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setMasterGoalState_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_setMasterGoalState_presult::~MasterClientService_setMasterGoalState_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setMasterGoalState_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    MasterClientService_shutdown_args::~MasterClientService_shutdown_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_shutdown_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->stopTabletServers);
			  this->__isset.stopTabletServers = true;
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
	    MasterClientService_shutdown_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_shutdown_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "stopTabletServers", ::apache::thrift::protocol::T_BOOL, 2);
	      xfer += oprot->writeBool (this->stopTabletServers);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_shutdown_pargs::~MasterClientService_shutdown_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_shutdown_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_shutdown_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "stopTabletServers", ::apache::thrift::protocol::T_BOOL, 2);
	      xfer += oprot->writeBool ((*(this->stopTabletServers)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_shutdown_result::~MasterClientService_shutdown_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_shutdown_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    MasterClientService_shutdown_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_shutdown_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_shutdown_presult::~MasterClientService_shutdown_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_shutdown_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    MasterClientService_shutdownTabletServer_args::~MasterClientService_shutdownTabletServer_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_shutdownTabletServer_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tabletServer);
			  this->__isset.tabletServer = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->force);
			  this->__isset.force = true;
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
	    MasterClientService_shutdownTabletServer_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_shutdownTabletServer_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tabletServer", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->tabletServer);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "force", ::apache::thrift::protocol::T_BOOL, 4);
	      xfer += oprot->writeBool (this->force);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_shutdownTabletServer_pargs::~MasterClientService_shutdownTabletServer_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_shutdownTabletServer_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_shutdownTabletServer_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tabletServer", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->tabletServer)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "force", ::apache::thrift::protocol::T_BOOL, 4);
	      xfer += oprot->writeBool ((*(this->force)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_shutdownTabletServer_result::~MasterClientService_shutdownTabletServer_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_shutdownTabletServer_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    MasterClientService_shutdownTabletServer_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_shutdownTabletServer_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_shutdownTabletServer_presult::~MasterClientService_shutdownTabletServer_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_shutdownTabletServer_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    MasterClientService_setSystemProperty_args::~MasterClientService_setSystemProperty_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setSystemProperty_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->property);
			  this->__isset.property = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->value);
			  this->__isset.value = true;
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
	    MasterClientService_setSystemProperty_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setSystemProperty_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->property);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "value", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->value);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_setSystemProperty_pargs::~MasterClientService_setSystemProperty_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setSystemProperty_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setSystemProperty_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->property)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "value", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString ((*(this->value)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_setSystemProperty_result::~MasterClientService_setSystemProperty_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setSystemProperty_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    MasterClientService_setSystemProperty_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_setSystemProperty_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_setSystemProperty_presult::~MasterClientService_setSystemProperty_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_setSystemProperty_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    MasterClientService_removeSystemProperty_args::~MasterClientService_removeSystemProperty_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeSystemProperty_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->property);
			  this->__isset.property = true;
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
	    MasterClientService_removeSystemProperty_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_removeSystemProperty_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->property);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_removeSystemProperty_pargs::~MasterClientService_removeSystemProperty_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeSystemProperty_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_removeSystemProperty_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "property", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->property)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_removeSystemProperty_result::~MasterClientService_removeSystemProperty_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeSystemProperty_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    MasterClientService_removeSystemProperty_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_removeSystemProperty_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_removeSystemProperty_presult::~MasterClientService_removeSystemProperty_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_removeSystemProperty_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    MasterClientService_getMasterStats_args::~MasterClientService_getMasterStats_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_getMasterStats_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
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
	    MasterClientService_getMasterStats_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_getMasterStats_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_getMasterStats_pargs::~MasterClientService_getMasterStats_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_getMasterStats_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_getMasterStats_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_getMasterStats_result::~MasterClientService_getMasterStats_result () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_getMasterStats_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->success.read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    MasterClientService_getMasterStats_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "MasterClientService_getMasterStats_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRUCT, 0);
		  xfer += this->success.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    MasterClientService_getMasterStats_presult::~MasterClientService_getMasterStats_presult () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_getMasterStats_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += (*(this->success)).read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    MasterClientService_reportSplitExtent_args::~MasterClientService_reportSplitExtent_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_reportSplitExtent_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->serverName);
			  this->__isset.serverName = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->split.read (iprot);
			  this->__isset.split = true;
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
	    MasterClientService_reportSplitExtent_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_reportSplitExtent_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "serverName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->serverName);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "split", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->split.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_reportSplitExtent_pargs::~MasterClientService_reportSplitExtent_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_reportSplitExtent_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_reportSplitExtent_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "serverName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->serverName)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "split", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->split)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_reportTabletStatus_args::~MasterClientService_reportTabletStatus_args () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_reportTabletStatus_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->serverName);
			  this->__isset.serverName = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast91;
			  xfer += iprot->readI32 (ecast91);
			  this->status = (TabletLoadState::type) ecast91;
			  this->__isset.status = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tablet.read (iprot);
			  this->__isset.tablet = true;
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
	    MasterClientService_reportTabletStatus_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_reportTabletStatus_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "serverName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->serverName);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("status",
					      ::apache::thrift::protocol::T_I32,
					      3);
	      xfer += oprot->writeI32 ((int32_t) this->status);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tablet", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->tablet.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    MasterClientService_reportTabletStatus_pargs::~MasterClientService_reportTabletStatus_pargs () throw ()
	    {
	    }

	    uint32_t
	    MasterClientService_reportTabletStatus_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "MasterClientService_reportTabletStatus_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "serverName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->serverName)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("status",
					      ::apache::thrift::protocol::T_I32,
					      3);
	      xfer += oprot->writeI32 ((int32_t) (*(this->status)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tablet", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->tablet)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    int64_t
	    MasterClientServiceClient::initiateFlush (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableName)
	    {
	      send_initiateFlush (tinfo, credentials, tableName);
	      return recv_initiateFlush ();
	    }

	    void
	    MasterClientServiceClient::send_initiateFlush (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableName)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("initiateFlush",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_initiateFlush_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.tableName = &tableName;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    int64_t
	    MasterClientServiceClient::recv_initiateFlush ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("initiateFlush") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      int64_t _return;
	      MasterClientService_initiateFlush_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  return _return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      if (result.__isset.tope)
		{
		  throw result.tope;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "initiateFlush failed: unknown result");
	    }

	    void
	    MasterClientServiceClient::waitForFlush (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableName, const std::string& startRow,
		const std::string& endRow, const int64_t flushID,
		const int64_t maxLoops)
	    {
	      send_waitForFlush (tinfo, credentials, tableName, startRow,
				 endRow, flushID, maxLoops);
	      recv_waitForFlush ();
	    }

	    void
	    MasterClientServiceClient::send_waitForFlush (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableName, const std::string& startRow,
		const std::string& endRow, const int64_t flushID,
		const int64_t maxLoops)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("waitForFlush",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_waitForFlush_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.tableName = &tableName;
	      args.startRow = &startRow;
	      args.endRow = &endRow;
	      args.flushID = &flushID;
	      args.maxLoops = &maxLoops;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_waitForFlush ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("waitForFlush") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_waitForFlush_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      if (result.__isset.tope)
		{
		  throw result.tope;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::setTableProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableName, const std::string& property,
		const std::string& value)
	    {
	      send_setTableProperty (tinfo, credentials, tableName, property,
				     value);
	      recv_setTableProperty ();
	    }

	    void
	    MasterClientServiceClient::send_setTableProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableName, const std::string& property,
		const std::string& value)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("setTableProperty",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_setTableProperty_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.tableName = &tableName;
	      args.property = &property;
	      args.value = &value;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_setTableProperty ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("setTableProperty") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_setTableProperty_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      if (result.__isset.tope)
		{
		  throw result.tope;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::removeTableProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableName, const std::string& property)
	    {
	      send_removeTableProperty (tinfo, credentials, tableName,
					property);
	      recv_removeTableProperty ();
	    }

	    void
	    MasterClientServiceClient::send_removeTableProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableName, const std::string& property)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("removeTableProperty",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_removeTableProperty_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.tableName = &tableName;
	      args.property = &property;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_removeTableProperty ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("removeTableProperty") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_removeTableProperty_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      if (result.__isset.tope)
		{
		  throw result.tope;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::setNamespaceProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& ns, const std::string& property,
		const std::string& value)
	    {
	      send_setNamespaceProperty (tinfo, credentials, ns, property,
					 value);
	      recv_setNamespaceProperty ();
	    }

	    void
	    MasterClientServiceClient::send_setNamespaceProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& ns, const std::string& property,
		const std::string& value)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("setNamespaceProperty",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_setNamespaceProperty_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.ns = &ns;
	      args.property = &property;
	      args.value = &value;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_setNamespaceProperty ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("setNamespaceProperty") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_setNamespaceProperty_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      if (result.__isset.tope)
		{
		  throw result.tope;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::removeNamespaceProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& ns, const std::string& property)
	    {
	      send_removeNamespaceProperty (tinfo, credentials, ns, property);
	      recv_removeNamespaceProperty ();
	    }

	    void
	    MasterClientServiceClient::send_removeNamespaceProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& ns, const std::string& property)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("removeNamespaceProperty",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_removeNamespaceProperty_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.ns = &ns;
	      args.property = &property;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_removeNamespaceProperty ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("removeNamespaceProperty") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_removeNamespaceProperty_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      if (result.__isset.tope)
		{
		  throw result.tope;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::setMasterGoalState (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const MasterGoalState::type state)
	    {
	      send_setMasterGoalState (tinfo, credentials, state);
	      recv_setMasterGoalState ();
	    }

	    void
	    MasterClientServiceClient::send_setMasterGoalState (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const MasterGoalState::type state)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("setMasterGoalState",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_setMasterGoalState_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.state = &state;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_setMasterGoalState ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("setMasterGoalState") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_setMasterGoalState_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::shutdown (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const bool stopTabletServers)
	    {
	      send_shutdown (tinfo, credentials, stopTabletServers);
	      recv_shutdown ();
	    }

	    void
	    MasterClientServiceClient::send_shutdown (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const bool stopTabletServers)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("shutdown",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_shutdown_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.stopTabletServers = &stopTabletServers;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_shutdown ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("shutdown") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_shutdown_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::shutdownTabletServer (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tabletServer, const bool force)
	    {
	      send_shutdownTabletServer (tinfo, credentials, tabletServer,
					 force);
	      recv_shutdownTabletServer ();
	    }

	    void
	    MasterClientServiceClient::send_shutdownTabletServer (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tabletServer, const bool force)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("shutdownTabletServer",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_shutdownTabletServer_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.tabletServer = &tabletServer;
	      args.force = &force;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_shutdownTabletServer ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("shutdownTabletServer") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_shutdownTabletServer_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::setSystemProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& property, const std::string& value)
	    {
	      send_setSystemProperty (tinfo, credentials, property, value);
	      recv_setSystemProperty ();
	    }

	    void
	    MasterClientServiceClient::send_setSystemProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& property, const std::string& value)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("setSystemProperty",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_setSystemProperty_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.property = &property;
	      args.value = &value;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_setSystemProperty ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("setSystemProperty") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_setSystemProperty_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::removeSystemProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& property)
	    {
	      send_removeSystemProperty (tinfo, credentials, property);
	      recv_removeSystemProperty ();
	    }

	    void
	    MasterClientServiceClient::send_removeSystemProperty (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& property)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("removeSystemProperty",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_removeSystemProperty_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.property = &property;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_removeSystemProperty ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("removeSystemProperty") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_removeSystemProperty_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      return;
	    }

	    void
	    MasterClientServiceClient::getMasterStats (
		MasterMonitorInfo& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      send_getMasterStats (tinfo, credentials);
	      recv_getMasterStats (_return);
	    }

	    void
	    MasterClientServiceClient::send_getMasterStats (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("getMasterStats",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      MasterClientService_getMasterStats_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::recv_getMasterStats (
		MasterMonitorInfo& _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("getMasterStats") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      MasterClientService_getMasterStats_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "getMasterStats failed: unknown result");
	    }

	    void
	    MasterClientServiceClient::reportSplitExtent (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& serverName, const TabletSplit& split)
	    {
	      send_reportSplitExtent (tinfo, credentials, serverName, split);
	    }

	    void
	    MasterClientServiceClient::send_reportSplitExtent (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& serverName, const TabletSplit& split)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("reportSplitExtent",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      MasterClientService_reportSplitExtent_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.serverName = &serverName;
	      args.split = &split;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    MasterClientServiceClient::reportTabletStatus (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& serverName,
		const TabletLoadState::type status,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& tablet)
	    {
	      send_reportTabletStatus (tinfo, credentials, serverName, status,
				       tablet);
	    }

	    void
	    MasterClientServiceClient::send_reportTabletStatus (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& serverName,
		const TabletLoadState::type status,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& tablet)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("reportTabletStatus",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      MasterClientService_reportTabletStatus_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.serverName = &serverName;
	      args.status = &status;
	      args.tablet = &tablet;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    bool
	    MasterClientServiceProcessor::dispatchCall (
		::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot,
		const std::string& fname, int32_t seqid, void* callContext)
	    {
	      ProcessMap::iterator pfn;
	      pfn = processMap_.find (fname);
	      if (pfn == processMap_.end ())
		{
		  return FateServiceProcessor::dispatchCall (iprot, oprot,
							     fname, seqid,
							     callContext);
		}
	      (this->*(pfn->second)) (seqid, iprot, oprot, callContext);
	      return true;
	    }

	    void
	    MasterClientServiceProcessor::process_initiateFlush (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.initiateFlush", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.initiateFlush");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.initiateFlush");
		}

	      MasterClientService_initiateFlush_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.initiateFlush", bytes);
		}

	      MasterClientService_initiateFlush_result result;
	      try
		{
		  result.success = iface_->initiateFlush (args.tinfo,
							  args.credentials,
							  args.tableName);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &tope)
		{
		  result.tope = tope;
		  result.__isset.tope = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.initiateFlush");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "initiateFlush", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.initiateFlush");
		}

	      oprot->writeMessageBegin ("initiateFlush",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.initiateFlush", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_waitForFlush (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.waitForFlush", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.waitForFlush");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.waitForFlush");
		}

	      MasterClientService_waitForFlush_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.waitForFlush", bytes);
		}

	      MasterClientService_waitForFlush_result result;
	      try
		{
		  iface_->waitForFlush (args.tinfo, args.credentials,
					args.tableName, args.startRow,
					args.endRow, args.flushID,
					args.maxLoops);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &tope)
		{
		  result.tope = tope;
		  result.__isset.tope = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.waitForFlush");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "waitForFlush", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.waitForFlush");
		}

	      oprot->writeMessageBegin ("waitForFlush",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.waitForFlush", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_setTableProperty (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.setTableProperty", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.setTableProperty");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.setTableProperty");
		}

	      MasterClientService_setTableProperty_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.setTableProperty", bytes);
		}

	      MasterClientService_setTableProperty_result result;
	      try
		{
		  iface_->setTableProperty (args.tinfo, args.credentials,
					    args.tableName, args.property,
					    args.value);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &tope)
		{
		  result.tope = tope;
		  result.__isset.tope = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.setTableProperty");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "setTableProperty",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.setTableProperty");
		}

	      oprot->writeMessageBegin ("setTableProperty",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.setTableProperty", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_removeTableProperty (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.removeTableProperty", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.removeTableProperty");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.removeTableProperty");
		}

	      MasterClientService_removeTableProperty_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.removeTableProperty", bytes);
		}

	      MasterClientService_removeTableProperty_result result;
	      try
		{
		  iface_->removeTableProperty (args.tinfo, args.credentials,
					       args.tableName, args.property);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &tope)
		{
		  result.tope = tope;
		  result.__isset.tope = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.removeTableProperty");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "removeTableProperty",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.removeTableProperty");
		}

	      oprot->writeMessageBegin ("removeTableProperty",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.removeTableProperty", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_setNamespaceProperty (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.setNamespaceProperty", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.setNamespaceProperty");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.setNamespaceProperty");
		}

	      MasterClientService_setNamespaceProperty_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.setNamespaceProperty", bytes);
		}

	      MasterClientService_setNamespaceProperty_result result;
	      try
		{
		  iface_->setNamespaceProperty (args.tinfo, args.credentials,
						args.ns, args.property,
						args.value);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &tope)
		{
		  result.tope = tope;
		  result.__isset.tope = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.setNamespaceProperty");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "setNamespaceProperty",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.setNamespaceProperty");
		}

	      oprot->writeMessageBegin ("setNamespaceProperty",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.setNamespaceProperty", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_removeNamespaceProperty (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.removeNamespaceProperty",
		      callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.removeNamespaceProperty");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.removeNamespaceProperty");
		}

	      MasterClientService_removeNamespaceProperty_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.removeNamespaceProperty",
		      bytes);
		}

	      MasterClientService_removeNamespaceProperty_result result;
	      try
		{
		  iface_->removeNamespaceProperty (args.tinfo, args.credentials,
						   args.ns, args.property);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException &tope)
		{
		  result.tope = tope;
		  result.__isset.tope = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.removeNamespaceProperty");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "removeNamespaceProperty",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.removeNamespaceProperty");
		}

	      oprot->writeMessageBegin ("removeNamespaceProperty",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.removeNamespaceProperty",
		      bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_setMasterGoalState (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.setMasterGoalState", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.setMasterGoalState");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.setMasterGoalState");
		}

	      MasterClientService_setMasterGoalState_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.setMasterGoalState", bytes);
		}

	      MasterClientService_setMasterGoalState_result result;
	      try
		{
		  iface_->setMasterGoalState (args.tinfo, args.credentials,
					      args.state);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.setMasterGoalState");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "setMasterGoalState",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.setMasterGoalState");
		}

	      oprot->writeMessageBegin ("setMasterGoalState",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.setMasterGoalState", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_shutdown (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.shutdown", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.shutdown");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (ctx,
						"MasterClientService.shutdown");
		}

	      MasterClientService_shutdown_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (ctx,
						 "MasterClientService.shutdown",
						 bytes);
		}

	      MasterClientService_shutdown_result result;
	      try
		{
		  iface_->shutdown (args.tinfo, args.credentials,
				    args.stopTabletServers);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.shutdown");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "shutdown", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.shutdown");
		}

	      oprot->writeMessageBegin ("shutdown",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.shutdown", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_shutdownTabletServer (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.shutdownTabletServer", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.shutdownTabletServer");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.shutdownTabletServer");
		}

	      MasterClientService_shutdownTabletServer_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.shutdownTabletServer", bytes);
		}

	      MasterClientService_shutdownTabletServer_result result;
	      try
		{
		  iface_->shutdownTabletServer (args.tinfo, args.credentials,
						args.tabletServer, args.force);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.shutdownTabletServer");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "shutdownTabletServer",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.shutdownTabletServer");
		}

	      oprot->writeMessageBegin ("shutdownTabletServer",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.shutdownTabletServer", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_setSystemProperty (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.setSystemProperty", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.setSystemProperty");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.setSystemProperty");
		}

	      MasterClientService_setSystemProperty_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.setSystemProperty", bytes);
		}

	      MasterClientService_setSystemProperty_result result;
	      try
		{
		  iface_->setSystemProperty (args.tinfo, args.credentials,
					     args.property, args.value);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.setSystemProperty");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "setSystemProperty",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.setSystemProperty");
		}

	      oprot->writeMessageBegin ("setSystemProperty",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.setSystemProperty", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_removeSystemProperty (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.removeSystemProperty", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.removeSystemProperty");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.removeSystemProperty");
		}

	      MasterClientService_removeSystemProperty_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.removeSystemProperty", bytes);
		}

	      MasterClientService_removeSystemProperty_result result;
	      try
		{
		  iface_->removeSystemProperty (args.tinfo, args.credentials,
						args.property);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.removeSystemProperty");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "removeSystemProperty",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.removeSystemProperty");
		}

	      oprot->writeMessageBegin ("removeSystemProperty",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.removeSystemProperty", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_getMasterStats (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.getMasterStats", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.getMasterStats");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.getMasterStats");
		}

	      MasterClientService_getMasterStats_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.getMasterStats", bytes);
		}

	      MasterClientService_getMasterStats_result result;
	      try
		{
		  iface_->getMasterStats (result.success, args.tinfo,
					  args.credentials);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.getMasterStats");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "getMasterStats", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "MasterClientService.getMasterStats");
		}

	      oprot->writeMessageBegin ("getMasterStats",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "MasterClientService.getMasterStats", bytes);
		}
	    }

	    void
	    MasterClientServiceProcessor::process_reportSplitExtent (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.reportSplitExtent", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.reportSplitExtent");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.reportSplitExtent");
		}

	      MasterClientService_reportSplitExtent_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.reportSplitExtent", bytes);
		}

	      try
		{
		  iface_->reportSplitExtent (args.tinfo, args.credentials,
					     args.serverName, args.split);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.reportSplitExtent");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "MasterClientService.reportSplitExtent");
		}

	      return;
	    }

	    void
	    MasterClientServiceProcessor::process_reportTabletStatus (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "MasterClientService.reportTabletStatus", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "MasterClientService.reportTabletStatus");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "MasterClientService.reportTabletStatus");
		}

	      MasterClientService_reportTabletStatus_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "MasterClientService.reportTabletStatus", bytes);
		}

	      try
		{
		  iface_->reportTabletStatus (args.tinfo, args.credentials,
					      args.serverName, args.status,
					      args.tablet);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "MasterClientService.reportTabletStatus");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "MasterClientService.reportTabletStatus");
		}

	      return;
	    }

	    ::boost::shared_ptr<::apache::thrift::TProcessor>
	    MasterClientServiceProcessorFactory::getProcessor (
		const ::apache::thrift::TConnectionInfo& connInfo)
	    {
	      ::apache::thrift::ReleaseHandler<MasterClientServiceIfFactory> cleanup (
		  handlerFactory_);
	      ::boost::shared_ptr<MasterClientServiceIf> handler (
		  handlerFactory_->getHandler (connInfo), cleanup);
	      ::boost::shared_ptr<::apache::thrift::TProcessor> processor (
		  new MasterClientServiceProcessor (handler));
	      return processor;
	    }
	  }
	}
      }
    }
  }
} // namespace

