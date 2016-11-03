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
#include "../../../../include/data/extern/thrift/FateService.h"

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

	    FateService_beginFateOperation_args::~FateService_beginFateOperation_args () throw ()
	    {
	    }

	    uint32_t
	    FateService_beginFateOperation_args::read (
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
	    FateService_beginFateOperation_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "FateService_beginFateOperation_args");

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

	    FateService_beginFateOperation_pargs::~FateService_beginFateOperation_pargs () throw ()
	    {
	    }

	    uint32_t
	    FateService_beginFateOperation_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "FateService_beginFateOperation_pargs");

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

	    FateService_beginFateOperation_result::~FateService_beginFateOperation_result () throw ()
	    {
	    }

	    uint32_t
	    FateService_beginFateOperation_result::read (
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
	    FateService_beginFateOperation_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "FateService_beginFateOperation_result");

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
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    FateService_beginFateOperation_presult::~FateService_beginFateOperation_presult () throw ()
	    {
	    }

	    uint32_t
	    FateService_beginFateOperation_presult::read (
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
		    default:
		      xfer += iprot->skip (ftype);
		      break;
		    }
		  xfer += iprot->readFieldEnd ();
		}

	      xfer += iprot->readStructEnd ();

	      return xfer;
	    }

	    FateService_executeFateOperation_args::~FateService_executeFateOperation_args () throw ()
	    {
	    }

	    uint32_t
	    FateService_executeFateOperation_args::read (
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
		    case 7:
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
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->opid);
			  this->__isset.opid = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast73;
			  xfer += iprot->readI32 (ecast73);
			  this->op = (FateOperation::type) ecast73;
			  this->__isset.op = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->arguments.clear ();
			      uint32_t _size74;
			      ::apache::thrift::protocol::TType _etype77;
			      xfer += iprot->readListBegin (_etype77, _size74);
			      this->arguments.resize (_size74);
			      uint32_t _i78;
			      for (_i78 = 0; _i78 < _size74; ++_i78)
				{
				  xfer += iprot->readBinary (
				      this->arguments[_i78]);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.arguments = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->options.clear ();
			      uint32_t _size79;
			      ::apache::thrift::protocol::TType _ktype80;
			      ::apache::thrift::protocol::TType _vtype81;
			      xfer += iprot->readMapBegin (_ktype80, _vtype81,
							   _size79);
			      uint32_t _i83;
			      for (_i83 = 0; _i83 < _size79; ++_i83)
				{
				  std::string _key84;
				  xfer += iprot->readString (_key84);
				  std::string& _val85 = this->options[_key84];
				  xfer += iprot->readString (_val85);
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.options = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->autoClean);
			  this->__isset.autoClean = true;
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
	    FateService_executeFateOperation_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "FateService_executeFateOperation_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("opid",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->opid);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("op",
					      ::apache::thrift::protocol::T_I32,
					      3);
	      xfer += oprot->writeI32 ((int32_t) this->op);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "arguments", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->arguments.size ()));
		  std::vector<std::string>::const_iterator _iter86;
		  for (_iter86 = this->arguments.begin ();
		      _iter86 != this->arguments.end (); ++_iter86)
		    {
		      xfer += oprot->writeBinary ((*_iter86));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("options",
					      ::apache::thrift::protocol::T_MAP,
					      5);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->options.size ()));
		  std::map<std::string, std::string>::const_iterator _iter87;
		  for (_iter87 = this->options.begin ();
		      _iter87 != this->options.end (); ++_iter87)
		    {
		      xfer += oprot->writeString (_iter87->first);
		      xfer += oprot->writeString (_iter87->second);
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "autoClean", ::apache::thrift::protocol::T_BOOL, 6);
	      xfer += oprot->writeBool (this->autoClean);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 7);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    FateService_executeFateOperation_pargs::~FateService_executeFateOperation_pargs () throw ()
	    {
	    }

	    uint32_t
	    FateService_executeFateOperation_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "FateService_executeFateOperation_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("opid",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 ((*(this->opid)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("op",
					      ::apache::thrift::protocol::T_I32,
					      3);
	      xfer += oprot->writeI32 ((int32_t) (*(this->op)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "arguments", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> ((*(this->arguments)).size ()));
		  std::vector<std::string>::const_iterator _iter88;
		  for (_iter88 = (*(this->arguments)).begin ();
		      _iter88 != (*(this->arguments)).end (); ++_iter88)
		    {
		      xfer += oprot->writeBinary ((*_iter88));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("options",
					      ::apache::thrift::protocol::T_MAP,
					      5);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> ((*(this->options)).size ()));
		  std::map<std::string, std::string>::const_iterator _iter89;
		  for (_iter89 = (*(this->options)).begin ();
		      _iter89 != (*(this->options)).end (); ++_iter89)
		    {
		      xfer += oprot->writeString (_iter89->first);
		      xfer += oprot->writeString (_iter89->second);
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "autoClean", ::apache::thrift::protocol::T_BOOL, 6);
	      xfer += oprot->writeBool ((*(this->autoClean)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 7);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    FateService_executeFateOperation_result::~FateService_executeFateOperation_result () throw ()
	    {
	    }

	    uint32_t
	    FateService_executeFateOperation_result::read (
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
	    FateService_executeFateOperation_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "FateService_executeFateOperation_result");

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

	    FateService_executeFateOperation_presult::~FateService_executeFateOperation_presult () throw ()
	    {
	    }

	    uint32_t
	    FateService_executeFateOperation_presult::read (
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

	    FateService_waitForFateOperation_args::~FateService_waitForFateOperation_args () throw ()
	    {
	    }

	    uint32_t
	    FateService_waitForFateOperation_args::read (
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
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->opid);
			  this->__isset.opid = true;
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
	    FateService_waitForFateOperation_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "FateService_waitForFateOperation_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("opid",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->opid);
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

	    FateService_waitForFateOperation_pargs::~FateService_waitForFateOperation_pargs () throw ()
	    {
	    }

	    uint32_t
	    FateService_waitForFateOperation_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "FateService_waitForFateOperation_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("opid",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 ((*(this->opid)));
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

	    FateService_waitForFateOperation_result::~FateService_waitForFateOperation_result () throw ()
	    {
	    }

	    uint32_t
	    FateService_waitForFateOperation_result::read (
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
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->success);
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
	    FateService_waitForFateOperation_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "FateService_waitForFateOperation_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRING, 0);
		  xfer += oprot->writeString (this->success);
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

	    FateService_waitForFateOperation_presult::~FateService_waitForFateOperation_presult () throw ()
	    {
	    }

	    uint32_t
	    FateService_waitForFateOperation_presult::read (
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
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString ((*(this->success)));
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

	    FateService_finishFateOperation_args::~FateService_finishFateOperation_args () throw ()
	    {
	    }

	    uint32_t
	    FateService_finishFateOperation_args::read (
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
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->opid);
			  this->__isset.opid = true;
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
	    FateService_finishFateOperation_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "FateService_finishFateOperation_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("opid",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->opid);
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

	    FateService_finishFateOperation_pargs::~FateService_finishFateOperation_pargs () throw ()
	    {
	    }

	    uint32_t
	    FateService_finishFateOperation_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "FateService_finishFateOperation_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("opid",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 ((*(this->opid)));
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

	    FateService_finishFateOperation_result::~FateService_finishFateOperation_result () throw ()
	    {
	    }

	    uint32_t
	    FateService_finishFateOperation_result::read (
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
	    FateService_finishFateOperation_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "FateService_finishFateOperation_result");

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

	    FateService_finishFateOperation_presult::~FateService_finishFateOperation_presult () throw ()
	    {
	    }

	    uint32_t
	    FateService_finishFateOperation_presult::read (
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

	    int64_t
	    FateServiceClient::beginFateOperation (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      send_beginFateOperation (tinfo, credentials);
	      return recv_beginFateOperation ();
	    }

	    void
	    FateServiceClient::send_beginFateOperation (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("beginFateOperation",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      FateService_beginFateOperation_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    int64_t
	    FateServiceClient::recv_beginFateOperation ()
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
	      if (fname.compare ("beginFateOperation") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      int64_t _return;
	      FateService_beginFateOperation_presult result;
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
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "beginFateOperation failed: unknown result");
	    }

	    void
	    FateServiceClient::executeFateOperation (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const int64_t opid, const FateOperation::type op,
		const std::vector<std::string> & arguments,
		const std::map<std::string, std::string> & options,
		const bool autoClean)
	    {
	      send_executeFateOperation (tinfo, credentials, opid, op,
					 arguments, options, autoClean);
	      recv_executeFateOperation ();
	    }

	    void
	    FateServiceClient::send_executeFateOperation (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const int64_t opid, const FateOperation::type op,
		const std::vector<std::string> & arguments,
		const std::map<std::string, std::string> & options,
		const bool autoClean)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("executeFateOperation",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      FateService_executeFateOperation_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.opid = &opid;
	      args.op = &op;
	      args.arguments = &arguments;
	      args.options = &options;
	      args.autoClean = &autoClean;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    FateServiceClient::recv_executeFateOperation ()
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
	      if (fname.compare ("executeFateOperation") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      FateService_executeFateOperation_presult result;
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
	    FateServiceClient::waitForFateOperation (
		std::string& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const int64_t opid)
	    {
	      send_waitForFateOperation (tinfo, credentials, opid);
	      recv_waitForFateOperation (_return);
	    }

	    void
	    FateServiceClient::send_waitForFateOperation (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const int64_t opid)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("waitForFateOperation",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      FateService_waitForFateOperation_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.opid = &opid;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    FateServiceClient::recv_waitForFateOperation (std::string& _return)
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
	      if (fname.compare ("waitForFateOperation") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      FateService_waitForFateOperation_presult result;
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
	      if (result.__isset.tope)
		{
		  throw result.tope;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "waitForFateOperation failed: unknown result");
	    }

	    void
	    FateServiceClient::finishFateOperation (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const int64_t opid)
	    {
	      send_finishFateOperation (tinfo, credentials, opid);
	      recv_finishFateOperation ();
	    }

	    void
	    FateServiceClient::send_finishFateOperation (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const int64_t opid)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("finishFateOperation",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      FateService_finishFateOperation_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.opid = &opid;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    FateServiceClient::recv_finishFateOperation ()
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
	      if (fname.compare ("finishFateOperation") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      FateService_finishFateOperation_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      return;
	    }

	    bool
	    FateServiceProcessor::dispatchCall (
		::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot,
		const std::string& fname, int32_t seqid, void* callContext)
	    {
	      ProcessMap::iterator pfn;
	      pfn = processMap_.find (fname);
	      if (pfn == processMap_.end ())
		{
		  iprot->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot->readMessageEnd ();
		  iprot->getTransport ()->readEnd ();
		  ::apache::thrift::TApplicationException x (
		      ::apache::thrift::TApplicationException::UNKNOWN_METHOD,
		      "Invalid method name: '" + fname + "'");
		  oprot->writeMessageBegin (
		      fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return true;
		}
	      (this->*(pfn->second)) (seqid, iprot, oprot, callContext);
	      return true;
	    }

	    void
	    FateServiceProcessor::process_beginFateOperation (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "FateService.beginFateOperation", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "FateService.beginFateOperation");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "FateService.beginFateOperation");
		}

	      FateService_beginFateOperation_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "FateService.beginFateOperation", bytes);
		}

	      FateService_beginFateOperation_result result;
	      try
		{
		  result.success = iface_->beginFateOperation (
		      args.tinfo, args.credentials);
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
			  ctx, "FateService.beginFateOperation");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "beginFateOperation",
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
		      ctx, "FateService.beginFateOperation");
		}

	      oprot->writeMessageBegin ("beginFateOperation",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "FateService.beginFateOperation", bytes);
		}
	    }

	    void
	    FateServiceProcessor::process_executeFateOperation (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "FateService.executeFateOperation", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "FateService.executeFateOperation");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "FateService.executeFateOperation");
		}

	      FateService_executeFateOperation_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "FateService.executeFateOperation", bytes);
		}

	      FateService_executeFateOperation_result result;
	      try
		{
		  iface_->executeFateOperation (args.tinfo, args.credentials,
						args.opid, args.op,
						args.arguments, args.options,
						args.autoClean);
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
			  ctx, "FateService.executeFateOperation");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "executeFateOperation",
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
		      ctx, "FateService.executeFateOperation");
		}

	      oprot->writeMessageBegin ("executeFateOperation",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "FateService.executeFateOperation", bytes);
		}
	    }

	    void
	    FateServiceProcessor::process_waitForFateOperation (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "FateService.waitForFateOperation", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "FateService.waitForFateOperation");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "FateService.waitForFateOperation");
		}

	      FateService_waitForFateOperation_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "FateService.waitForFateOperation", bytes);
		}

	      FateService_waitForFateOperation_result result;
	      try
		{
		  iface_->waitForFateOperation (result.success, args.tinfo,
						args.credentials, args.opid);
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
			  ctx, "FateService.waitForFateOperation");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "waitForFateOperation",
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
		      ctx, "FateService.waitForFateOperation");
		}

	      oprot->writeMessageBegin ("waitForFateOperation",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "FateService.waitForFateOperation", bytes);
		}
	    }

	    void
	    FateServiceProcessor::process_finishFateOperation (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "FateService.finishFateOperation", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "FateService.finishFateOperation");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "FateService.finishFateOperation");
		}

	      FateService_finishFateOperation_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "FateService.finishFateOperation", bytes);
		}

	      FateService_finishFateOperation_result result;
	      try
		{
		  iface_->finishFateOperation (args.tinfo, args.credentials,
					       args.opid);
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
			  ctx, "FateService.finishFateOperation");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "finishFateOperation",
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
		      ctx, "FateService.finishFateOperation");
		}

	      oprot->writeMessageBegin ("finishFateOperation",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "FateService.finishFateOperation", bytes);
		}
	    }

	    ::boost::shared_ptr<::apache::thrift::TProcessor>
	    FateServiceProcessorFactory::getProcessor (
		const ::apache::thrift::TConnectionInfo& connInfo)
	    {
	      ::apache::thrift::ReleaseHandler<FateServiceIfFactory> cleanup (
		  handlerFactory_);
	      ::boost::shared_ptr<FateServiceIf> handler (
		  handlerFactory_->getHandler (connInfo), cleanup);
	      ::boost::shared_ptr<::apache::thrift::TProcessor> processor (
		  new FateServiceProcessor (handler));
	      return processor;
	    }
	  }
	}
      }
    }
  }
} // namespace

