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
#include "../../../../include/data/extern/thrift/ClientService.h"

namespace org
{
  namespace apache
  {
    namespace accumulo
    {
      namespace core
      {
	namespace client
	{
	  namespace impl
	  {
	    namespace thrift
	    {

	      ClientService_getRootTabletLocation_args::~ClientService_getRootTabletLocation_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getRootTabletLocation_args::read (
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
		    xfer += iprot->skip (ftype);
		    xfer += iprot->readFieldEnd ();
		  }

		xfer += iprot->readStructEnd ();

		return xfer;
	      }

	      uint32_t
	      ClientService_getRootTabletLocation_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getRootTabletLocation_args");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getRootTabletLocation_pargs::~ClientService_getRootTabletLocation_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getRootTabletLocation_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getRootTabletLocation_pargs");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getRootTabletLocation_result::~ClientService_getRootTabletLocation_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getRootTabletLocation_result::read (
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
	      ClientService_getRootTabletLocation_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_getRootTabletLocation_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_STRING, 0);
		    xfer += oprot->writeString (this->success);
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ClientService_getRootTabletLocation_presult::~ClientService_getRootTabletLocation_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getRootTabletLocation_presult::read (
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
		      default:
			xfer += iprot->skip (ftype);
			break;
		      }
		    xfer += iprot->readFieldEnd ();
		  }

		xfer += iprot->readStructEnd ();

		return xfer;
	      }

	      ClientService_getInstanceId_args::~ClientService_getInstanceId_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getInstanceId_args::read (
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
		    xfer += iprot->skip (ftype);
		    xfer += iprot->readFieldEnd ();
		  }

		xfer += iprot->readStructEnd ();

		return xfer;
	      }

	      uint32_t
	      ClientService_getInstanceId_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getInstanceId_args");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getInstanceId_pargs::~ClientService_getInstanceId_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getInstanceId_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getInstanceId_pargs");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getInstanceId_result::~ClientService_getInstanceId_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getInstanceId_result::read (
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
	      ClientService_getInstanceId_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_getInstanceId_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_STRING, 0);
		    xfer += oprot->writeString (this->success);
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ClientService_getInstanceId_presult::~ClientService_getInstanceId_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getInstanceId_presult::read (
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
		      default:
			xfer += iprot->skip (ftype);
			break;
		      }
		    xfer += iprot->readFieldEnd ();
		  }

		xfer += iprot->readStructEnd ();

		return xfer;
	      }

	      ClientService_getZooKeepers_args::~ClientService_getZooKeepers_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getZooKeepers_args::read (
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
		    xfer += iprot->skip (ftype);
		    xfer += iprot->readFieldEnd ();
		  }

		xfer += iprot->readStructEnd ();

		return xfer;
	      }

	      uint32_t
	      ClientService_getZooKeepers_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getZooKeepers_args");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getZooKeepers_pargs::~ClientService_getZooKeepers_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getZooKeepers_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getZooKeepers_pargs");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getZooKeepers_result::~ClientService_getZooKeepers_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getZooKeepers_result::read (
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
	      ClientService_getZooKeepers_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_getZooKeepers_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_STRING, 0);
		    xfer += oprot->writeString (this->success);
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ClientService_getZooKeepers_presult::~ClientService_getZooKeepers_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getZooKeepers_presult::read (
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
		      default:
			xfer += iprot->skip (ftype);
			break;
		      }
		    xfer += iprot->readFieldEnd ();
		  }

		xfer += iprot->readStructEnd ();

		return xfer;
	      }

	      ClientService_bulkImportFiles_args::~ClientService_bulkImportFiles_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_bulkImportFiles_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 8:
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
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_I64)
			  {
			    xfer += iprot->readI64 (this->tid);
			    this->__isset.tid = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 4:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->tableId);
			    this->__isset.tableId = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 5:
			if (ftype == ::apache::thrift::protocol::T_LIST)
			  {
			      {
				this->files.clear ();
				uint32_t _size15;
				::apache::thrift::protocol::TType _etype18;
				xfer += iprot->readListBegin (_etype18,
							      _size15);
				this->files.resize (_size15);
				uint32_t _i19;
				for (_i19 = 0; _i19 < _size15; ++_i19)
				  {
				    xfer += iprot->readString (
					this->files[_i19]);
				  }
				xfer += iprot->readListEnd ();
			      }
			    this->__isset.files = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 6:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->errorDir);
			    this->__isset.errorDir = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 7:
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->setTime);
			    this->__isset.setTime = true;
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
	      ClientService_bulkImportFiles_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_bulkImportFiles_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tid", ::apache::thrift::protocol::T_I64, 3);
		xfer += oprot->writeI64 (this->tid);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableId", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString (this->tableId);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "files", ::apache::thrift::protocol::T_LIST, 5);
		  {
		    xfer += oprot->writeListBegin (
			::apache::thrift::protocol::T_STRING,
			static_cast<uint32_t> (this->files.size ()));
		    std::vector<std::string>::const_iterator _iter20;
		    for (_iter20 = this->files.begin ();
			_iter20 != this->files.end (); ++_iter20)
		      {
			xfer += oprot->writeString ((*_iter20));
		      }
		    xfer += oprot->writeListEnd ();
		  }
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "errorDir", ::apache::thrift::protocol::T_STRING, 6);
		xfer += oprot->writeString (this->errorDir);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "setTime", ::apache::thrift::protocol::T_BOOL, 7);
		xfer += oprot->writeBool (this->setTime);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 8);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_bulkImportFiles_pargs::~ClientService_bulkImportFiles_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_bulkImportFiles_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_bulkImportFiles_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tid", ::apache::thrift::protocol::T_I64, 3);
		xfer += oprot->writeI64 ((*(this->tid)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableId", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString ((*(this->tableId)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "files", ::apache::thrift::protocol::T_LIST, 5);
		  {
		    xfer += oprot->writeListBegin (
			::apache::thrift::protocol::T_STRING,
			static_cast<uint32_t> ((*(this->files)).size ()));
		    std::vector<std::string>::const_iterator _iter21;
		    for (_iter21 = (*(this->files)).begin ();
			_iter21 != (*(this->files)).end (); ++_iter21)
		      {
			xfer += oprot->writeString ((*_iter21));
		      }
		    xfer += oprot->writeListEnd ();
		  }
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "errorDir", ::apache::thrift::protocol::T_STRING, 6);
		xfer += oprot->writeString ((*(this->errorDir)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "setTime", ::apache::thrift::protocol::T_BOOL, 7);
		xfer += oprot->writeBool ((*(this->setTime)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 8);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_bulkImportFiles_result::~ClientService_bulkImportFiles_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_bulkImportFiles_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_LIST)
			  {
			      {
				this->success.clear ();
				uint32_t _size22;
				::apache::thrift::protocol::TType _etype25;
				xfer += iprot->readListBegin (_etype25,
							      _size22);
				this->success.resize (_size22);
				uint32_t _i26;
				for (_i26 = 0; _i26 < _size22; ++_i26)
				  {
				    xfer += iprot->readString (
					this->success[_i26]);
				  }
				xfer += iprot->readListEnd ();
			      }
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
	      ClientService_bulkImportFiles_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_bulkImportFiles_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_LIST, 0);
		      {
			xfer += oprot->writeListBegin (
			    ::apache::thrift::protocol::T_STRING,
			    static_cast<uint32_t> (this->success.size ()));
			std::vector<std::string>::const_iterator _iter27;
			for (_iter27 = this->success.begin ();
			    _iter27 != this->success.end (); ++_iter27)
			  {
			    xfer += oprot->writeString ((*_iter27));
			  }
			xfer += oprot->writeListEnd ();
		      }
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

	      ClientService_bulkImportFiles_presult::~ClientService_bulkImportFiles_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_bulkImportFiles_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_LIST)
			  {
			      {
				(*(this->success)).clear ();
				uint32_t _size28;
				::apache::thrift::protocol::TType _etype31;
				xfer += iprot->readListBegin (_etype31,
							      _size28);
				(*(this->success)).resize (_size28);
				uint32_t _i32;
				for (_i32 = 0; _i32 < _size28; ++_i32)
				  {
				    xfer += iprot->readString (
					(*(this->success))[_i32]);
				  }
				xfer += iprot->readListEnd ();
			      }
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

	      ClientService_isActive_args::~ClientService_isActive_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_isActive_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
			if (ftype == ::apache::thrift::protocol::T_I64)
			  {
			    xfer += iprot->readI64 (this->tid);
			    this->__isset.tid = true;
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
	      ClientService_isActive_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("ClientService_isActive_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tid", ::apache::thrift::protocol::T_I64, 2);
		xfer += oprot->writeI64 (this->tid);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_isActive_pargs::~ClientService_isActive_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_isActive_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_isActive_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tid", ::apache::thrift::protocol::T_I64, 2);
		xfer += oprot->writeI64 ((*(this->tid)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_isActive_result::~ClientService_isActive_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_isActive_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->success);
			    this->__isset.success = true;
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
	      ClientService_isActive_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_isActive_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ClientService_isActive_presult::~ClientService_isActive_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_isActive_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool ((*(this->success)));
			    this->__isset.success = true;
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

	      ClientService_ping_args::~ClientService_ping_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_ping_args::read (
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
	      ClientService_ping_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("ClientService_ping_args");

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_ping_pargs::~ClientService_ping_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_ping_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("ClientService_ping_pargs");

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_ping_result::~ClientService_ping_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_ping_result::read (
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
	      ClientService_ping_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin ("ClientService_ping_result");

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

	      ClientService_ping_presult::~ClientService_ping_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_ping_presult::read (
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

	      ClientService_getDiskUsage_args::~ClientService_getDiskUsage_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getDiskUsage_args::read (
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
			if (ftype == ::apache::thrift::protocol::T_SET)
			  {
			      {
				this->tables.clear ();
				uint32_t _size33;
				::apache::thrift::protocol::TType _etype36;
				xfer += iprot->readSetBegin (_etype36, _size33);
				uint32_t _i37;
				for (_i37 = 0; _i37 < _size33; ++_i37)
				  {
				    std::string _elem38;
				    xfer += iprot->readString (_elem38);
				    this->tables.insert (_elem38);
				  }
				xfer += iprot->readSetEnd ();
			      }
			    this->__isset.tables = true;
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
	      ClientService_getDiskUsage_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getDiskUsage_args");

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tables", ::apache::thrift::protocol::T_SET, 2);
		  {
		    xfer += oprot->writeSetBegin (
			::apache::thrift::protocol::T_STRING,
			static_cast<uint32_t> (this->tables.size ()));
		    std::set<std::string>::const_iterator _iter39;
		    for (_iter39 = this->tables.begin ();
			_iter39 != this->tables.end (); ++_iter39)
		      {
			xfer += oprot->writeString ((*_iter39));
		      }
		    xfer += oprot->writeSetEnd ();
		  }
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getDiskUsage_pargs::~ClientService_getDiskUsage_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getDiskUsage_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getDiskUsage_pargs");

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tables", ::apache::thrift::protocol::T_SET, 2);
		  {
		    xfer += oprot->writeSetBegin (
			::apache::thrift::protocol::T_STRING,
			static_cast<uint32_t> ((*(this->tables)).size ()));
		    std::set<std::string>::const_iterator _iter40;
		    for (_iter40 = (*(this->tables)).begin ();
			_iter40 != (*(this->tables)).end (); ++_iter40)
		      {
			xfer += oprot->writeString ((*_iter40));
		      }
		    xfer += oprot->writeSetEnd ();
		  }
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getDiskUsage_result::~ClientService_getDiskUsage_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getDiskUsage_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_LIST)
			  {
			      {
				this->success.clear ();
				uint32_t _size41;
				::apache::thrift::protocol::TType _etype44;
				xfer += iprot->readListBegin (_etype44,
							      _size41);
				this->success.resize (_size41);
				uint32_t _i45;
				for (_i45 = 0; _i45 < _size41; ++_i45)
				  {
				    xfer += this->success[_i45].read (iprot);
				  }
				xfer += iprot->readListEnd ();
			      }
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
			    xfer += this->toe.read (iprot);
			    this->__isset.toe = true;
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
	      ClientService_getDiskUsage_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_getDiskUsage_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_LIST, 0);
		      {
			xfer += oprot->writeListBegin (
			    ::apache::thrift::protocol::T_STRUCT,
			    static_cast<uint32_t> (this->success.size ()));
			std::vector<TDiskUsage>::const_iterator _iter46;
			for (_iter46 = this->success.begin ();
			    _iter46 != this->success.end (); ++_iter46)
			  {
			    xfer += (*_iter46).write (oprot);
			  }
			xfer += oprot->writeListEnd ();
		      }
		    xfer += oprot->writeFieldEnd ();
		  }
		else if (this->__isset.sec)
		  {
		    xfer += oprot->writeFieldBegin (
			"sec", ::apache::thrift::protocol::T_STRUCT, 1);
		    xfer += this->sec.write (oprot);
		    xfer += oprot->writeFieldEnd ();
		  }
		else if (this->__isset.toe)
		  {
		    xfer += oprot->writeFieldBegin (
			"toe", ::apache::thrift::protocol::T_STRUCT, 2);
		    xfer += this->toe.write (oprot);
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ClientService_getDiskUsage_presult::~ClientService_getDiskUsage_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getDiskUsage_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_LIST)
			  {
			      {
				(*(this->success)).clear ();
				uint32_t _size47;
				::apache::thrift::protocol::TType _etype50;
				xfer += iprot->readListBegin (_etype50,
							      _size47);
				(*(this->success)).resize (_size47);
				uint32_t _i51;
				for (_i51 = 0; _i51 < _size47; ++_i51)
				  {
				    xfer += (*(this->success))[_i51].read (
					iprot);
				  }
				xfer += iprot->readListEnd ();
			      }
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
			    xfer += this->toe.read (iprot);
			    this->__isset.toe = true;
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

	      ClientService_listLocalUsers_args::~ClientService_listLocalUsers_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_listLocalUsers_args::read (
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
		      case 3:
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
	      ClientService_listLocalUsers_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_listLocalUsers_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_listLocalUsers_pargs::~ClientService_listLocalUsers_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_listLocalUsers_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_listLocalUsers_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_listLocalUsers_result::~ClientService_listLocalUsers_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_listLocalUsers_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_SET)
			  {
			      {
				this->success.clear ();
				uint32_t _size52;
				::apache::thrift::protocol::TType _etype55;
				xfer += iprot->readSetBegin (_etype55, _size52);
				uint32_t _i56;
				for (_i56 = 0; _i56 < _size52; ++_i56)
				  {
				    std::string _elem57;
				    xfer += iprot->readString (_elem57);
				    this->success.insert (_elem57);
				  }
				xfer += iprot->readSetEnd ();
			      }
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
	      ClientService_listLocalUsers_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_listLocalUsers_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_SET, 0);
		      {
			xfer += oprot->writeSetBegin (
			    ::apache::thrift::protocol::T_STRING,
			    static_cast<uint32_t> (this->success.size ()));
			std::set<std::string>::const_iterator _iter58;
			for (_iter58 = this->success.begin ();
			    _iter58 != this->success.end (); ++_iter58)
			  {
			    xfer += oprot->writeString ((*_iter58));
			  }
			xfer += oprot->writeSetEnd ();
		      }
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

	      ClientService_listLocalUsers_presult::~ClientService_listLocalUsers_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_listLocalUsers_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_SET)
			  {
			      {
				(*(this->success)).clear ();
				uint32_t _size59;
				::apache::thrift::protocol::TType _etype62;
				xfer += iprot->readSetBegin (_etype62, _size59);
				uint32_t _i63;
				for (_i63 = 0; _i63 < _size59; ++_i63)
				  {
				    std::string _elem64;
				    xfer += iprot->readString (_elem64);
				    (*(this->success)).insert (_elem64);
				  }
				xfer += iprot->readSetEnd ();
			      }
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

	      ClientService_createLocalUser_args::~ClientService_createLocalUser_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_createLocalUser_args::read (
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
		      case 6:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readBinary (this->password);
			    this->__isset.password = true;
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
	      ClientService_createLocalUser_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_createLocalUser_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "password", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeBinary (this->password);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 6);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_createLocalUser_pargs::~ClientService_createLocalUser_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_createLocalUser_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_createLocalUser_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "password", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeBinary ((*(this->password)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 6);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_createLocalUser_result::~ClientService_createLocalUser_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_createLocalUser_result::read (
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
	      ClientService_createLocalUser_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_createLocalUser_result");

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

	      ClientService_createLocalUser_presult::~ClientService_createLocalUser_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_createLocalUser_presult::read (
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

	      ClientService_dropLocalUser_args::~ClientService_dropLocalUser_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_dropLocalUser_args::read (
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
		      case 4:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
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
	      ClientService_dropLocalUser_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_dropLocalUser_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_dropLocalUser_pargs::~ClientService_dropLocalUser_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_dropLocalUser_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_dropLocalUser_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_dropLocalUser_result::~ClientService_dropLocalUser_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_dropLocalUser_result::read (
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
	      ClientService_dropLocalUser_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_dropLocalUser_result");

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

	      ClientService_dropLocalUser_presult::~ClientService_dropLocalUser_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_dropLocalUser_presult::read (
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

	      ClientService_changeLocalUserPassword_args::~ClientService_changeLocalUserPassword_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_changeLocalUserPassword_args::read (
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
		      case 5:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readBinary (this->password);
			    this->__isset.password = true;
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
	      ClientService_changeLocalUserPassword_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_changeLocalUserPassword_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "password", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeBinary (this->password);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_changeLocalUserPassword_pargs::~ClientService_changeLocalUserPassword_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_changeLocalUserPassword_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_changeLocalUserPassword_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "password", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeBinary ((*(this->password)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_changeLocalUserPassword_result::~ClientService_changeLocalUserPassword_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_changeLocalUserPassword_result::read (
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
	      ClientService_changeLocalUserPassword_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_changeLocalUserPassword_result");

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

	      ClientService_changeLocalUserPassword_presult::~ClientService_changeLocalUserPassword_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_changeLocalUserPassword_presult::read (
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

	      ClientService_authenticate_args::~ClientService_authenticate_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_authenticate_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
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
	      ClientService_authenticate_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_authenticate_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_authenticate_pargs::~ClientService_authenticate_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_authenticate_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_authenticate_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_authenticate_result::~ClientService_authenticate_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_authenticate_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->success);
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
	      ClientService_authenticate_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_authenticate_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
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

	      ClientService_authenticate_presult::~ClientService_authenticate_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_authenticate_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool ((*(this->success)));
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

	      ClientService_authenticateUser_args::~ClientService_authenticateUser_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_authenticateUser_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
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
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_STRUCT)
			  {
			    xfer += this->toAuth.read (iprot);
			    this->__isset.toAuth = true;
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
	      ClientService_authenticateUser_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_authenticateUser_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "toAuth", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += this->toAuth.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_authenticateUser_pargs::~ClientService_authenticateUser_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_authenticateUser_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_authenticateUser_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "toAuth", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += (*(this->toAuth)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_authenticateUser_result::~ClientService_authenticateUser_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_authenticateUser_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->success);
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
	      ClientService_authenticateUser_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_authenticateUser_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
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

	      ClientService_authenticateUser_presult::~ClientService_authenticateUser_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_authenticateUser_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool ((*(this->success)));
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

	      ClientService_changeAuthorizations_args::~ClientService_changeAuthorizations_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_changeAuthorizations_args::read (
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
		      case 5:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_LIST)
			  {
			      {
				this->authorizations.clear ();
				uint32_t _size65;
				::apache::thrift::protocol::TType _etype68;
				xfer += iprot->readListBegin (_etype68,
							      _size65);
				this->authorizations.resize (_size65);
				uint32_t _i69;
				for (_i69 = 0; _i69 < _size65; ++_i69)
				  {
				    xfer += iprot->readBinary (
					this->authorizations[_i69]);
				  }
				xfer += iprot->readListEnd ();
			      }
			    this->__isset.authorizations = true;
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
	      ClientService_changeAuthorizations_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_changeAuthorizations_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "authorizations", ::apache::thrift::protocol::T_LIST, 3);
		  {
		    xfer += oprot->writeListBegin (
			::apache::thrift::protocol::T_STRING,
			static_cast<uint32_t> (this->authorizations.size ()));
		    std::vector<std::string>::const_iterator _iter70;
		    for (_iter70 = this->authorizations.begin ();
			_iter70 != this->authorizations.end (); ++_iter70)
		      {
			xfer += oprot->writeBinary ((*_iter70));
		      }
		    xfer += oprot->writeListEnd ();
		  }
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_changeAuthorizations_pargs::~ClientService_changeAuthorizations_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_changeAuthorizations_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_changeAuthorizations_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "authorizations", ::apache::thrift::protocol::T_LIST, 3);
		  {
		    xfer +=
			oprot->writeListBegin (
			    ::apache::thrift::protocol::T_STRING,
			    static_cast<uint32_t> ((*(this->authorizations)).size ()));
		    std::vector<std::string>::const_iterator _iter71;
		    for (_iter71 = (*(this->authorizations)).begin ();
			_iter71 != (*(this->authorizations)).end (); ++_iter71)
		      {
			xfer += oprot->writeBinary ((*_iter71));
		      }
		    xfer += oprot->writeListEnd ();
		  }
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_changeAuthorizations_result::~ClientService_changeAuthorizations_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_changeAuthorizations_result::read (
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
	      ClientService_changeAuthorizations_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_changeAuthorizations_result");

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

	      ClientService_changeAuthorizations_presult::~ClientService_changeAuthorizations_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_changeAuthorizations_presult::read (
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

	      ClientService_getUserAuthorizations_args::~ClientService_getUserAuthorizations_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getUserAuthorizations_args::read (
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
		      case 4:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
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
	      ClientService_getUserAuthorizations_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getUserAuthorizations_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getUserAuthorizations_pargs::~ClientService_getUserAuthorizations_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getUserAuthorizations_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getUserAuthorizations_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getUserAuthorizations_result::~ClientService_getUserAuthorizations_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getUserAuthorizations_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_LIST)
			  {
			      {
				this->success.clear ();
				uint32_t _size72;
				::apache::thrift::protocol::TType _etype75;
				xfer += iprot->readListBegin (_etype75,
							      _size72);
				this->success.resize (_size72);
				uint32_t _i76;
				for (_i76 = 0; _i76 < _size72; ++_i76)
				  {
				    xfer += iprot->readBinary (
					this->success[_i76]);
				  }
				xfer += iprot->readListEnd ();
			      }
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
	      ClientService_getUserAuthorizations_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_getUserAuthorizations_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_LIST, 0);
		      {
			xfer += oprot->writeListBegin (
			    ::apache::thrift::protocol::T_STRING,
			    static_cast<uint32_t> (this->success.size ()));
			std::vector<std::string>::const_iterator _iter77;
			for (_iter77 = this->success.begin ();
			    _iter77 != this->success.end (); ++_iter77)
			  {
			    xfer += oprot->writeBinary ((*_iter77));
			  }
			xfer += oprot->writeListEnd ();
		      }
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

	      ClientService_getUserAuthorizations_presult::~ClientService_getUserAuthorizations_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getUserAuthorizations_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_LIST)
			  {
			      {
				(*(this->success)).clear ();
				uint32_t _size78;
				::apache::thrift::protocol::TType _etype81;
				xfer += iprot->readListBegin (_etype81,
							      _size78);
				(*(this->success)).resize (_size78);
				uint32_t _i82;
				for (_i82 = 0; _i82 < _size78; ++_i82)
				  {
				    xfer += iprot->readBinary (
					(*(this->success))[_i82]);
				  }
				xfer += iprot->readListEnd ();
			      }
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

	      ClientService_hasSystemPermission_args::~ClientService_hasSystemPermission_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasSystemPermission_args::read (
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
		      case 5:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_BYTE)
			  {
			    xfer += iprot->readByte (this->sysPerm);
			    this->__isset.sysPerm = true;
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
	      ClientService_hasSystemPermission_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_hasSystemPermission_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "sysPerm", ::apache::thrift::protocol::T_BYTE, 3);
		xfer += oprot->writeByte (this->sysPerm);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_hasSystemPermission_pargs::~ClientService_hasSystemPermission_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasSystemPermission_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_hasSystemPermission_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "sysPerm", ::apache::thrift::protocol::T_BYTE, 3);
		xfer += oprot->writeByte ((*(this->sysPerm)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_hasSystemPermission_result::~ClientService_hasSystemPermission_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasSystemPermission_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->success);
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
	      ClientService_hasSystemPermission_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_hasSystemPermission_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
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

	      ClientService_hasSystemPermission_presult::~ClientService_hasSystemPermission_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasSystemPermission_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool ((*(this->success)));
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

	      ClientService_hasTablePermission_args::~ClientService_hasTablePermission_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasTablePermission_args::read (
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
		      case 6:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
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
		      case 4:
			if (ftype == ::apache::thrift::protocol::T_BYTE)
			  {
			    xfer += iprot->readByte (this->tblPerm);
			    this->__isset.tblPerm = true;
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
	      ClientService_hasTablePermission_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_hasTablePermission_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableName", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->tableName);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tblPerm", ::apache::thrift::protocol::T_BYTE, 4);
		xfer += oprot->writeByte (this->tblPerm);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 6);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_hasTablePermission_pargs::~ClientService_hasTablePermission_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasTablePermission_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_hasTablePermission_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableName", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->tableName)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tblPerm", ::apache::thrift::protocol::T_BYTE, 4);
		xfer += oprot->writeByte ((*(this->tblPerm)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 6);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_hasTablePermission_result::~ClientService_hasTablePermission_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasTablePermission_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->success);
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
	      ClientService_hasTablePermission_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_hasTablePermission_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
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

	      ClientService_hasTablePermission_presult::~ClientService_hasTablePermission_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasTablePermission_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool ((*(this->success)));
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

	      ClientService_hasNamespacePermission_args::~ClientService_hasNamespacePermission_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasNamespacePermission_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
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
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 4:
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
		      case 5:
			if (ftype == ::apache::thrift::protocol::T_BYTE)
			  {
			    xfer += iprot->readByte (this->tblNspcPerm);
			    this->__isset.tblNspcPerm = true;
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
	      ClientService_hasNamespacePermission_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_hasNamespacePermission_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "ns", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString (this->ns);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tblNspcPerm", ::apache::thrift::protocol::T_BYTE, 5);
		xfer += oprot->writeByte (this->tblNspcPerm);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_hasNamespacePermission_pargs::~ClientService_hasNamespacePermission_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasNamespacePermission_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_hasNamespacePermission_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "ns", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString ((*(this->ns)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tblNspcPerm", ::apache::thrift::protocol::T_BYTE, 5);
		xfer += oprot->writeByte ((*(this->tblNspcPerm)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_hasNamespacePermission_result::~ClientService_hasNamespacePermission_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasNamespacePermission_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->success);
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
	      ClientService_hasNamespacePermission_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_hasNamespacePermission_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
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

	      ClientService_hasNamespacePermission_presult::~ClientService_hasNamespacePermission_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_hasNamespacePermission_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool ((*(this->success)));
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

	      ClientService_grantSystemPermission_args::~ClientService_grantSystemPermission_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantSystemPermission_args::read (
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
		      case 5:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_BYTE)
			  {
			    xfer += iprot->readByte (this->permission);
			    this->__isset.permission = true;
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
	      ClientService_grantSystemPermission_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_grantSystemPermission_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 3);
		xfer += oprot->writeByte (this->permission);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_grantSystemPermission_pargs::~ClientService_grantSystemPermission_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantSystemPermission_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_grantSystemPermission_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 3);
		xfer += oprot->writeByte ((*(this->permission)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_grantSystemPermission_result::~ClientService_grantSystemPermission_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantSystemPermission_result::read (
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
	      ClientService_grantSystemPermission_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_grantSystemPermission_result");

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

	      ClientService_grantSystemPermission_presult::~ClientService_grantSystemPermission_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantSystemPermission_presult::read (
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

	      ClientService_revokeSystemPermission_args::~ClientService_revokeSystemPermission_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeSystemPermission_args::read (
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
		      case 5:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_BYTE)
			  {
			    xfer += iprot->readByte (this->permission);
			    this->__isset.permission = true;
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
	      ClientService_revokeSystemPermission_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_revokeSystemPermission_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 3);
		xfer += oprot->writeByte (this->permission);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_revokeSystemPermission_pargs::~ClientService_revokeSystemPermission_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeSystemPermission_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_revokeSystemPermission_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 3);
		xfer += oprot->writeByte ((*(this->permission)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_revokeSystemPermission_result::~ClientService_revokeSystemPermission_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeSystemPermission_result::read (
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
	      ClientService_revokeSystemPermission_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_revokeSystemPermission_result");

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

	      ClientService_revokeSystemPermission_presult::~ClientService_revokeSystemPermission_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeSystemPermission_presult::read (
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

	      ClientService_grantTablePermission_args::~ClientService_grantTablePermission_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantTablePermission_args::read (
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
		      case 6:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
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
		      case 4:
			if (ftype == ::apache::thrift::protocol::T_BYTE)
			  {
			    xfer += iprot->readByte (this->permission);
			    this->__isset.permission = true;
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
	      ClientService_grantTablePermission_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_grantTablePermission_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableName", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->tableName);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 4);
		xfer += oprot->writeByte (this->permission);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 6);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_grantTablePermission_pargs::~ClientService_grantTablePermission_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantTablePermission_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_grantTablePermission_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableName", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->tableName)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 4);
		xfer += oprot->writeByte ((*(this->permission)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 6);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_grantTablePermission_result::~ClientService_grantTablePermission_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantTablePermission_result::read (
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
	      ClientService_grantTablePermission_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_grantTablePermission_result");

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

	      ClientService_grantTablePermission_presult::~ClientService_grantTablePermission_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantTablePermission_presult::read (
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

	      ClientService_revokeTablePermission_args::~ClientService_revokeTablePermission_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeTablePermission_args::read (
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
		      case 6:
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
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
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
		      case 4:
			if (ftype == ::apache::thrift::protocol::T_BYTE)
			  {
			    xfer += iprot->readByte (this->permission);
			    this->__isset.permission = true;
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
	      ClientService_revokeTablePermission_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_revokeTablePermission_args");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableName", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->tableName);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 4);
		xfer += oprot->writeByte (this->permission);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 6);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_revokeTablePermission_pargs::~ClientService_revokeTablePermission_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeTablePermission_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_revokeTablePermission_pargs");

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableName", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->tableName)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 4);
		xfer += oprot->writeByte ((*(this->permission)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 6);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_revokeTablePermission_result::~ClientService_revokeTablePermission_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeTablePermission_result::read (
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
	      ClientService_revokeTablePermission_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_revokeTablePermission_result");

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

	      ClientService_revokeTablePermission_presult::~ClientService_revokeTablePermission_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeTablePermission_presult::read (
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

	      ClientService_grantNamespacePermission_args::~ClientService_grantNamespacePermission_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantNamespacePermission_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
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
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 4:
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
		      case 5:
			if (ftype == ::apache::thrift::protocol::T_BYTE)
			  {
			    xfer += iprot->readByte (this->permission);
			    this->__isset.permission = true;
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
	      ClientService_grantNamespacePermission_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_grantNamespacePermission_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "ns", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString (this->ns);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 5);
		xfer += oprot->writeByte (this->permission);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_grantNamespacePermission_pargs::~ClientService_grantNamespacePermission_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantNamespacePermission_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_grantNamespacePermission_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "ns", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString ((*(this->ns)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 5);
		xfer += oprot->writeByte ((*(this->permission)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_grantNamespacePermission_result::~ClientService_grantNamespacePermission_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantNamespacePermission_result::read (
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
	      ClientService_grantNamespacePermission_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_grantNamespacePermission_result");

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

	      ClientService_grantNamespacePermission_presult::~ClientService_grantNamespacePermission_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_grantNamespacePermission_presult::read (
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

	      ClientService_revokeNamespacePermission_args::~ClientService_revokeNamespacePermission_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeNamespacePermission_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
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
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->principal);
			    this->__isset.principal = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 4:
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
		      case 5:
			if (ftype == ::apache::thrift::protocol::T_BYTE)
			  {
			    xfer += iprot->readByte (this->permission);
			    this->__isset.permission = true;
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
	      ClientService_revokeNamespacePermission_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_revokeNamespacePermission_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->principal);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "ns", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString (this->ns);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 5);
		xfer += oprot->writeByte (this->permission);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_revokeNamespacePermission_pargs::~ClientService_revokeNamespacePermission_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeNamespacePermission_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_revokeNamespacePermission_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "principal", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->principal)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "ns", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString ((*(this->ns)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "permission", ::apache::thrift::protocol::T_BYTE, 5);
		xfer += oprot->writeByte ((*(this->permission)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_revokeNamespacePermission_result::~ClientService_revokeNamespacePermission_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeNamespacePermission_result::read (
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
	      ClientService_revokeNamespacePermission_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_revokeNamespacePermission_result");

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

	      ClientService_revokeNamespacePermission_presult::~ClientService_revokeNamespacePermission_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_revokeNamespacePermission_presult::read (
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

	      ClientService_getConfiguration_args::~ClientService_getConfiguration_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getConfiguration_args::read (
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
		      case 3:
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
		      case 1:
			if (ftype == ::apache::thrift::protocol::T_I32)
			  {
			    int32_t ecast83;
			    xfer += iprot->readI32 (ecast83);
			    this->type = (ConfigurationType::type) ecast83;
			    this->__isset.type = true;
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
	      ClientService_getConfiguration_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getConfiguration_args");

		xfer += oprot->writeFieldBegin (
		    "type", ::apache::thrift::protocol::T_I32, 1);
		xfer += oprot->writeI32 ((int32_t) this->type);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getConfiguration_pargs::~ClientService_getConfiguration_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getConfiguration_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getConfiguration_pargs");

		xfer += oprot->writeFieldBegin (
		    "type", ::apache::thrift::protocol::T_I32, 1);
		xfer += oprot->writeI32 ((int32_t) (*(this->type)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getConfiguration_result::~ClientService_getConfiguration_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getConfiguration_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_MAP)
			  {
			      {
				this->success.clear ();
				uint32_t _size84;
				::apache::thrift::protocol::TType _ktype85;
				::apache::thrift::protocol::TType _vtype86;
				xfer += iprot->readMapBegin (_ktype85, _vtype86,
							     _size84);
				uint32_t _i88;
				for (_i88 = 0; _i88 < _size84; ++_i88)
				  {
				    std::string _key89;
				    xfer += iprot->readString (_key89);
				    std::string& _val90 = this->success[_key89];
				    xfer += iprot->readString (_val90);
				  }
				xfer += iprot->readMapEnd ();
			      }
			    this->__isset.success = true;
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
	      ClientService_getConfiguration_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_getConfiguration_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_MAP, 0);
		      {
			xfer += oprot->writeMapBegin (
			    ::apache::thrift::protocol::T_STRING,
			    ::apache::thrift::protocol::T_STRING,
			    static_cast<uint32_t> (this->success.size ()));
			std::map<std::string, std::string>::const_iterator _iter91;
			for (_iter91 = this->success.begin ();
			    _iter91 != this->success.end (); ++_iter91)
			  {
			    xfer += oprot->writeString (_iter91->first);
			    xfer += oprot->writeString (_iter91->second);
			  }
			xfer += oprot->writeMapEnd ();
		      }
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ClientService_getConfiguration_presult::~ClientService_getConfiguration_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getConfiguration_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_MAP)
			  {
			      {
				(*(this->success)).clear ();
				uint32_t _size92;
				::apache::thrift::protocol::TType _ktype93;
				::apache::thrift::protocol::TType _vtype94;
				xfer += iprot->readMapBegin (_ktype93, _vtype94,
							     _size92);
				uint32_t _i96;
				for (_i96 = 0; _i96 < _size92; ++_i96)
				  {
				    std::string _key97;
				    xfer += iprot->readString (_key97);
				    std::string& _val98 =
					(*(this->success))[_key97];
				    xfer += iprot->readString (_val98);
				  }
				xfer += iprot->readMapEnd ();
			      }
			    this->__isset.success = true;
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

	      ClientService_getTableConfiguration_args::~ClientService_getTableConfiguration_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getTableConfiguration_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
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
	      ClientService_getTableConfiguration_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getTableConfiguration_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableName", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->tableName);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getTableConfiguration_pargs::~ClientService_getTableConfiguration_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getTableConfiguration_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getTableConfiguration_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableName", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->tableName)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 3);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getTableConfiguration_result::~ClientService_getTableConfiguration_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getTableConfiguration_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_MAP)
			  {
			      {
				this->success.clear ();
				uint32_t _size99;
				::apache::thrift::protocol::TType _ktype100;
				::apache::thrift::protocol::TType _vtype101;
				xfer += iprot->readMapBegin (_ktype100,
							     _vtype101,
							     _size99);
				uint32_t _i103;
				for (_i103 = 0; _i103 < _size99; ++_i103)
				  {
				    std::string _key104;
				    xfer += iprot->readString (_key104);
				    std::string& _val105 =
					this->success[_key104];
				    xfer += iprot->readString (_val105);
				  }
				xfer += iprot->readMapEnd ();
			      }
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
	      ClientService_getTableConfiguration_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_getTableConfiguration_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_MAP, 0);
		      {
			xfer += oprot->writeMapBegin (
			    ::apache::thrift::protocol::T_STRING,
			    ::apache::thrift::protocol::T_STRING,
			    static_cast<uint32_t> (this->success.size ()));
			std::map<std::string, std::string>::const_iterator _iter106;
			for (_iter106 = this->success.begin ();
			    _iter106 != this->success.end (); ++_iter106)
			  {
			    xfer += oprot->writeString (_iter106->first);
			    xfer += oprot->writeString (_iter106->second);
			  }
			xfer += oprot->writeMapEnd ();
		      }
		    xfer += oprot->writeFieldEnd ();
		  }
		else if (this->__isset.tope)
		  {
		    xfer += oprot->writeFieldBegin (
			"tope", ::apache::thrift::protocol::T_STRUCT, 1);
		    xfer += this->tope.write (oprot);
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ClientService_getTableConfiguration_presult::~ClientService_getTableConfiguration_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getTableConfiguration_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_MAP)
			  {
			      {
				(*(this->success)).clear ();
				uint32_t _size107;
				::apache::thrift::protocol::TType _ktype108;
				::apache::thrift::protocol::TType _vtype109;
				xfer += iprot->readMapBegin (_ktype108,
							     _vtype109,
							     _size107);
				uint32_t _i111;
				for (_i111 = 0; _i111 < _size107; ++_i111)
				  {
				    std::string _key112;
				    xfer += iprot->readString (_key112);
				    std::string& _val113 =
					(*(this->success))[_key112];
				    xfer += iprot->readString (_val113);
				  }
				xfer += iprot->readMapEnd ();
			      }
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

	      ClientService_getNamespaceConfiguration_args::~ClientService_getNamespaceConfiguration_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getNamespaceConfiguration_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
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
		      case 3:
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
	      ClientService_getNamespaceConfiguration_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getNamespaceConfiguration_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "ns", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->ns);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getNamespaceConfiguration_pargs::~ClientService_getNamespaceConfiguration_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getNamespaceConfiguration_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_getNamespaceConfiguration_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "ns", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->ns)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_getNamespaceConfiguration_result::~ClientService_getNamespaceConfiguration_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getNamespaceConfiguration_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_MAP)
			  {
			      {
				this->success.clear ();
				uint32_t _size114;
				::apache::thrift::protocol::TType _ktype115;
				::apache::thrift::protocol::TType _vtype116;
				xfer += iprot->readMapBegin (_ktype115,
							     _vtype116,
							     _size114);
				uint32_t _i118;
				for (_i118 = 0; _i118 < _size114; ++_i118)
				  {
				    std::string _key119;
				    xfer += iprot->readString (_key119);
				    std::string& _val120 =
					this->success[_key119];
				    xfer += iprot->readString (_val120);
				  }
				xfer += iprot->readMapEnd ();
			      }
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
	      ClientService_getNamespaceConfiguration_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_getNamespaceConfiguration_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_MAP, 0);
		      {
			xfer += oprot->writeMapBegin (
			    ::apache::thrift::protocol::T_STRING,
			    ::apache::thrift::protocol::T_STRING,
			    static_cast<uint32_t> (this->success.size ()));
			std::map<std::string, std::string>::const_iterator _iter121;
			for (_iter121 = this->success.begin ();
			    _iter121 != this->success.end (); ++_iter121)
			  {
			    xfer += oprot->writeString (_iter121->first);
			    xfer += oprot->writeString (_iter121->second);
			  }
			xfer += oprot->writeMapEnd ();
		      }
		    xfer += oprot->writeFieldEnd ();
		  }
		else if (this->__isset.tope)
		  {
		    xfer += oprot->writeFieldBegin (
			"tope", ::apache::thrift::protocol::T_STRUCT, 1);
		    xfer += this->tope.write (oprot);
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ClientService_getNamespaceConfiguration_presult::~ClientService_getNamespaceConfiguration_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_getNamespaceConfiguration_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_MAP)
			  {
			      {
				(*(this->success)).clear ();
				uint32_t _size122;
				::apache::thrift::protocol::TType _ktype123;
				::apache::thrift::protocol::TType _vtype124;
				xfer += iprot->readMapBegin (_ktype123,
							     _vtype124,
							     _size122);
				uint32_t _i126;
				for (_i126 = 0; _i126 < _size122; ++_i126)
				  {
				    std::string _key127;
				    xfer += iprot->readString (_key127);
				    std::string& _val128 =
					(*(this->success))[_key127];
				    xfer += iprot->readString (_val128);
				  }
				xfer += iprot->readMapEnd ();
			      }
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

	      ClientService_checkClass_args::~ClientService_checkClass_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkClass_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 4:
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
			    xfer += iprot->readString (this->className);
			    this->__isset.className = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->interfaceMatch);
			    this->__isset.interfaceMatch = true;
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
	      ClientService_checkClass_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_checkClass_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "className", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->className);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "interfaceMatch", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->interfaceMatch);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_checkClass_pargs::~ClientService_checkClass_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkClass_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_checkClass_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "className", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->className)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "interfaceMatch", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->interfaceMatch)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 4);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_checkClass_result::~ClientService_checkClass_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkClass_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->success);
			    this->__isset.success = true;
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
	      ClientService_checkClass_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_checkClass_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ClientService_checkClass_presult::~ClientService_checkClass_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkClass_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool ((*(this->success)));
			    this->__isset.success = true;
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

	      ClientService_checkTableClass_args::~ClientService_checkTableClass_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkTableClass_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 5:
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
			    xfer += iprot->readString (this->tableId);
			    this->__isset.tableId = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->className);
			    this->__isset.className = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 4:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->interfaceMatch);
			    this->__isset.interfaceMatch = true;
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
	      ClientService_checkTableClass_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_checkTableClass_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableId", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->tableId);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "className", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->className);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "interfaceMatch", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString (this->interfaceMatch);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_checkTableClass_pargs::~ClientService_checkTableClass_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkTableClass_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_checkTableClass_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableId", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString ((*(this->tableId)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "className", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->className)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "interfaceMatch", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString ((*(this->interfaceMatch)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 5);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_checkTableClass_result::~ClientService_checkTableClass_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkTableClass_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->success);
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
	      ClientService_checkTableClass_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_checkTableClass_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
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

	      ClientService_checkTableClass_presult::~ClientService_checkTableClass_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkTableClass_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool ((*(this->success)));
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

	      ClientService_checkNamespaceClass_args::~ClientService_checkNamespaceClass_args () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkNamespaceClass_args::read (
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
			    xfer += this->tinfo.read (iprot);
			    this->__isset.tinfo = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
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
		      case 3:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->namespaceId);
			    this->__isset.namespaceId = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 4:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->className);
			    this->__isset.className = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 5:
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->interfaceMatch);
			    this->__isset.interfaceMatch = true;
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
	      ClientService_checkNamespaceClass_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_checkNamespaceClass_args");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += this->tinfo.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += this->credentials.write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "namespaceId", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString (this->namespaceId);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "className", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString (this->className);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "interfaceMatch", ::apache::thrift::protocol::T_STRING, 5);
		xfer += oprot->writeString (this->interfaceMatch);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_checkNamespaceClass_pargs::~ClientService_checkNamespaceClass_pargs () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkNamespaceClass_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ClientService_checkNamespaceClass_pargs");

		xfer += oprot->writeFieldBegin (
		    "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
		xfer += (*(this->tinfo)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
		xfer += (*(this->credentials)).write (oprot);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "namespaceId", ::apache::thrift::protocol::T_STRING, 3);
		xfer += oprot->writeString ((*(this->namespaceId)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "className", ::apache::thrift::protocol::T_STRING, 4);
		xfer += oprot->writeString ((*(this->className)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "interfaceMatch", ::apache::thrift::protocol::T_STRING, 5);
		xfer += oprot->writeString ((*(this->interfaceMatch)));
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ClientService_checkNamespaceClass_result::~ClientService_checkNamespaceClass_result () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkNamespaceClass_result::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool (this->success);
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
	      ClientService_checkNamespaceClass_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ClientService_checkNamespaceClass_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
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

	      ClientService_checkNamespaceClass_presult::~ClientService_checkNamespaceClass_presult () throw ()
	      {
	      }

	      uint32_t
	      ClientService_checkNamespaceClass_presult::read (
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
			if (ftype == ::apache::thrift::protocol::T_BOOL)
			  {
			    xfer += iprot->readBool ((*(this->success)));
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

	      void
	      ClientServiceClient::getRootTabletLocation (std::string& _return)
	      {
		send_getRootTabletLocation ();
		recv_getRootTabletLocation (_return);
	      }

	      void
	      ClientServiceClient::send_getRootTabletLocation ()
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("getRootTabletLocation",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_getRootTabletLocation_pargs args;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_getRootTabletLocation (
		  std::string& _return)
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
		if (fname.compare ("getRootTabletLocation") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_getRootTabletLocation_presult result;
		result.success = &_return;
		result.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();

		if (result.__isset.success)
		  {
		    // _return pointer has now been filled
		    return;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "getRootTabletLocation failed: unknown result");
	      }

	      void
	      ClientServiceClient::getInstanceId (std::string& _return)
	      {
		send_getInstanceId ();
		recv_getInstanceId (_return);
	      }

	      void
	      ClientServiceClient::send_getInstanceId ()
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("getInstanceId",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_getInstanceId_pargs args;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_getInstanceId (std::string& _return)
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
		if (fname.compare ("getInstanceId") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_getInstanceId_presult result;
		result.success = &_return;
		result.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();

		if (result.__isset.success)
		  {
		    // _return pointer has now been filled
		    return;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "getInstanceId failed: unknown result");
	      }

	      void
	      ClientServiceClient::getZooKeepers (std::string& _return)
	      {
		send_getZooKeepers ();
		recv_getZooKeepers (_return);
	      }

	      void
	      ClientServiceClient::send_getZooKeepers ()
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("getZooKeepers",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_getZooKeepers_pargs args;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_getZooKeepers (std::string& _return)
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
		if (fname.compare ("getZooKeepers") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_getZooKeepers_presult result;
		result.success = &_return;
		result.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();

		if (result.__isset.success)
		  {
		    // _return pointer has now been filled
		    return;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "getZooKeepers failed: unknown result");
	      }

	      void
	      ClientServiceClient::bulkImportFiles (
		  std::vector<std::string> & _return,
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const int64_t tid, const std::string& tableId,
		  const std::vector<std::string> & files,
		  const std::string& errorDir, const bool setTime)
	      {
		send_bulkImportFiles (tinfo, credentials, tid, tableId, files,
				      errorDir, setTime);
		recv_bulkImportFiles (_return);
	      }

	      void
	      ClientServiceClient::send_bulkImportFiles (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const int64_t tid, const std::string& tableId,
		  const std::vector<std::string> & files,
		  const std::string& errorDir, const bool setTime)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("bulkImportFiles",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_bulkImportFiles_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.tid = &tid;
		args.tableId = &tableId;
		args.files = &files;
		args.errorDir = &errorDir;
		args.setTime = &setTime;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_bulkImportFiles (
		  std::vector<std::string> & _return)
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
		if (fname.compare ("bulkImportFiles") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_bulkImportFiles_presult result;
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
		    "bulkImportFiles failed: unknown result");
	      }

	      bool
	      ClientServiceClient::isActive (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const int64_t tid)
	      {
		send_isActive (tinfo, tid);
		return recv_isActive ();
	      }

	      void
	      ClientServiceClient::send_isActive (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const int64_t tid)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("isActive",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_isActive_pargs args;
		args.tinfo = &tinfo;
		args.tid = &tid;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ClientServiceClient::recv_isActive ()
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
		if (fname.compare ("isActive") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ClientService_isActive_presult result;
		result.success = &_return;
		result.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();

		if (result.__isset.success)
		  {
		    return _return;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "isActive failed: unknown result");
	      }

	      void
	      ClientServiceClient::ping (
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	      {
		send_ping (credentials);
		recv_ping ();
	      }

	      void
	      ClientServiceClient::send_ping (
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("ping",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_ping_pargs args;
		args.credentials = &credentials;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_ping ()
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
		if (fname.compare ("ping") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_ping_presult result;
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
	      ClientServiceClient::getDiskUsage (
		  std::vector<TDiskUsage> & _return,
		  const std::set<std::string> & tables,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	      {
		send_getDiskUsage (tables, credentials);
		recv_getDiskUsage (_return);
	      }

	      void
	      ClientServiceClient::send_getDiskUsage (
		  const std::set<std::string> & tables,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("getDiskUsage",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_getDiskUsage_pargs args;
		args.tables = &tables;
		args.credentials = &credentials;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_getDiskUsage (
		  std::vector<TDiskUsage> & _return)
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
		if (fname.compare ("getDiskUsage") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_getDiskUsage_presult result;
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
		if (result.__isset.toe)
		  {
		    throw result.toe;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "getDiskUsage failed: unknown result");
	      }

	      void
	      ClientServiceClient::listLocalUsers (
		  std::set<std::string> & _return,
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	      {
		send_listLocalUsers (tinfo, credentials);
		recv_listLocalUsers (_return);
	      }

	      void
	      ClientServiceClient::send_listLocalUsers (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("listLocalUsers",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_listLocalUsers_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_listLocalUsers (
		  std::set<std::string> & _return)
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
		if (fname.compare ("listLocalUsers") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_listLocalUsers_presult result;
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
		    "listLocalUsers failed: unknown result");
	      }

	      void
	      ClientServiceClient::createLocalUser (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& password)
	      {
		send_createLocalUser (tinfo, credentials, principal, password);
		recv_createLocalUser ();
	      }

	      void
	      ClientServiceClient::send_createLocalUser (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& password)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("createLocalUser",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_createLocalUser_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.password = &password;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_createLocalUser ()
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
		if (fname.compare ("createLocalUser") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_createLocalUser_presult result;
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
	      ClientServiceClient::dropLocalUser (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal)
	      {
		send_dropLocalUser (tinfo, credentials, principal);
		recv_dropLocalUser ();
	      }

	      void
	      ClientServiceClient::send_dropLocalUser (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("dropLocalUser",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_dropLocalUser_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_dropLocalUser ()
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
		if (fname.compare ("dropLocalUser") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_dropLocalUser_presult result;
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
	      ClientServiceClient::changeLocalUserPassword (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& password)
	      {
		send_changeLocalUserPassword (tinfo, credentials, principal,
					      password);
		recv_changeLocalUserPassword ();
	      }

	      void
	      ClientServiceClient::send_changeLocalUserPassword (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& password)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("changeLocalUserPassword",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_changeLocalUserPassword_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.password = &password;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_changeLocalUserPassword ()
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
		if (fname.compare ("changeLocalUserPassword") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_changeLocalUserPassword_presult result;
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
	      ClientServiceClient::authenticate (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	      {
		send_authenticate (tinfo, credentials);
		return recv_authenticate ();
	      }

	      void
	      ClientServiceClient::send_authenticate (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("authenticate",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_authenticate_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ClientServiceClient::recv_authenticate ()
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
		if (fname.compare ("authenticate") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ClientService_authenticate_presult result;
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
		    "authenticate failed: unknown result");
	      }

	      bool
	      ClientServiceClient::authenticateUser (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& toAuth)
	      {
		send_authenticateUser (tinfo, credentials, toAuth);
		return recv_authenticateUser ();
	      }

	      void
	      ClientServiceClient::send_authenticateUser (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& toAuth)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("authenticateUser",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_authenticateUser_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.toAuth = &toAuth;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ClientServiceClient::recv_authenticateUser ()
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
		if (fname.compare ("authenticateUser") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ClientService_authenticateUser_presult result;
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
		    "authenticateUser failed: unknown result");
	      }

	      void
	      ClientServiceClient::changeAuthorizations (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal,
		  const std::vector<std::string> & authorizations)
	      {
		send_changeAuthorizations (tinfo, credentials, principal,
					   authorizations);
		recv_changeAuthorizations ();
	      }

	      void
	      ClientServiceClient::send_changeAuthorizations (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal,
		  const std::vector<std::string> & authorizations)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("changeAuthorizations",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_changeAuthorizations_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.authorizations = &authorizations;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_changeAuthorizations ()
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
		if (fname.compare ("changeAuthorizations") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_changeAuthorizations_presult result;
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
	      ClientServiceClient::getUserAuthorizations (
		  std::vector<std::string> & _return,
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal)
	      {
		send_getUserAuthorizations (tinfo, credentials, principal);
		recv_getUserAuthorizations (_return);
	      }

	      void
	      ClientServiceClient::send_getUserAuthorizations (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("getUserAuthorizations",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_getUserAuthorizations_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_getUserAuthorizations (
		  std::vector<std::string> & _return)
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
		if (fname.compare ("getUserAuthorizations") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_getUserAuthorizations_presult result;
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
		    "getUserAuthorizations failed: unknown result");
	      }

	      bool
	      ClientServiceClient::hasSystemPermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const int8_t sysPerm)
	      {
		send_hasSystemPermission (tinfo, credentials, principal,
					  sysPerm);
		return recv_hasSystemPermission ();
	      }

	      void
	      ClientServiceClient::send_hasSystemPermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const int8_t sysPerm)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("hasSystemPermission",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_hasSystemPermission_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.sysPerm = &sysPerm;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ClientServiceClient::recv_hasSystemPermission ()
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
		if (fname.compare ("hasSystemPermission") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ClientService_hasSystemPermission_presult result;
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
		    "hasSystemPermission failed: unknown result");
	      }

	      bool
	      ClientServiceClient::hasTablePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& tableName,
		  const int8_t tblPerm)
	      {
		send_hasTablePermission (tinfo, credentials, principal,
					 tableName, tblPerm);
		return recv_hasTablePermission ();
	      }

	      void
	      ClientServiceClient::send_hasTablePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& tableName,
		  const int8_t tblPerm)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("hasTablePermission",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_hasTablePermission_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.tableName = &tableName;
		args.tblPerm = &tblPerm;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ClientServiceClient::recv_hasTablePermission ()
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
		if (fname.compare ("hasTablePermission") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ClientService_hasTablePermission_presult result;
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
		    "hasTablePermission failed: unknown result");
	      }

	      bool
	      ClientServiceClient::hasNamespacePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& ns,
		  const int8_t tblNspcPerm)
	      {
		send_hasNamespacePermission (tinfo, credentials, principal, ns,
					     tblNspcPerm);
		return recv_hasNamespacePermission ();
	      }

	      void
	      ClientServiceClient::send_hasNamespacePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& ns,
		  const int8_t tblNspcPerm)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("hasNamespacePermission",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_hasNamespacePermission_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.ns = &ns;
		args.tblNspcPerm = &tblNspcPerm;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ClientServiceClient::recv_hasNamespacePermission ()
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
		if (fname.compare ("hasNamespacePermission") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ClientService_hasNamespacePermission_presult result;
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
		    "hasNamespacePermission failed: unknown result");
	      }

	      void
	      ClientServiceClient::grantSystemPermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const int8_t permission)
	      {
		send_grantSystemPermission (tinfo, credentials, principal,
					    permission);
		recv_grantSystemPermission ();
	      }

	      void
	      ClientServiceClient::send_grantSystemPermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const int8_t permission)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("grantSystemPermission",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_grantSystemPermission_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.permission = &permission;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_grantSystemPermission ()
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
		if (fname.compare ("grantSystemPermission") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_grantSystemPermission_presult result;
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
	      ClientServiceClient::revokeSystemPermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const int8_t permission)
	      {
		send_revokeSystemPermission (tinfo, credentials, principal,
					     permission);
		recv_revokeSystemPermission ();
	      }

	      void
	      ClientServiceClient::send_revokeSystemPermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const int8_t permission)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("revokeSystemPermission",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_revokeSystemPermission_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.permission = &permission;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_revokeSystemPermission ()
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
		if (fname.compare ("revokeSystemPermission") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_revokeSystemPermission_presult result;
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
	      ClientServiceClient::grantTablePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& tableName,
		  const int8_t permission)
	      {
		send_grantTablePermission (tinfo, credentials, principal,
					   tableName, permission);
		recv_grantTablePermission ();
	      }

	      void
	      ClientServiceClient::send_grantTablePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& tableName,
		  const int8_t permission)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("grantTablePermission",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_grantTablePermission_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.tableName = &tableName;
		args.permission = &permission;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_grantTablePermission ()
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
		if (fname.compare ("grantTablePermission") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_grantTablePermission_presult result;
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
	      ClientServiceClient::revokeTablePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& tableName,
		  const int8_t permission)
	      {
		send_revokeTablePermission (tinfo, credentials, principal,
					    tableName, permission);
		recv_revokeTablePermission ();
	      }

	      void
	      ClientServiceClient::send_revokeTablePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& tableName,
		  const int8_t permission)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("revokeTablePermission",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_revokeTablePermission_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.tableName = &tableName;
		args.permission = &permission;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_revokeTablePermission ()
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
		if (fname.compare ("revokeTablePermission") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_revokeTablePermission_presult result;
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
	      ClientServiceClient::grantNamespacePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& ns,
		  const int8_t permission)
	      {
		send_grantNamespacePermission (tinfo, credentials, principal,
					       ns, permission);
		recv_grantNamespacePermission ();
	      }

	      void
	      ClientServiceClient::send_grantNamespacePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& ns,
		  const int8_t permission)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("grantNamespacePermission",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_grantNamespacePermission_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.ns = &ns;
		args.permission = &permission;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_grantNamespacePermission ()
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
		if (fname.compare ("grantNamespacePermission") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_grantNamespacePermission_presult result;
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
	      ClientServiceClient::revokeNamespacePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& ns,
		  const int8_t permission)
	      {
		send_revokeNamespacePermission (tinfo, credentials, principal,
						ns, permission);
		recv_revokeNamespacePermission ();
	      }

	      void
	      ClientServiceClient::send_revokeNamespacePermission (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& principal, const std::string& ns,
		  const int8_t permission)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("revokeNamespacePermission",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_revokeNamespacePermission_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.principal = &principal;
		args.ns = &ns;
		args.permission = &permission;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_revokeNamespacePermission ()
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
		if (fname.compare ("revokeNamespacePermission") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_revokeNamespacePermission_presult result;
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
	      ClientServiceClient::getConfiguration (
		  std::map<std::string, std::string> & _return,
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const ConfigurationType::type type)
	      {
		send_getConfiguration (tinfo, credentials, type);
		recv_getConfiguration (_return);
	      }

	      void
	      ClientServiceClient::send_getConfiguration (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const ConfigurationType::type type)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("getConfiguration",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_getConfiguration_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.type = &type;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_getConfiguration (
		  std::map<std::string, std::string> & _return)
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
		if (fname.compare ("getConfiguration") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_getConfiguration_presult result;
		result.success = &_return;
		result.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();

		if (result.__isset.success)
		  {
		    // _return pointer has now been filled
		    return;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "getConfiguration failed: unknown result");
	      }

	      void
	      ClientServiceClient::getTableConfiguration (
		  std::map<std::string, std::string> & _return,
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& tableName)
	      {
		send_getTableConfiguration (tinfo, credentials, tableName);
		recv_getTableConfiguration (_return);
	      }

	      void
	      ClientServiceClient::send_getTableConfiguration (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& tableName)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("getTableConfiguration",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_getTableConfiguration_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.tableName = &tableName;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_getTableConfiguration (
		  std::map<std::string, std::string> & _return)
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
		if (fname.compare ("getTableConfiguration") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_getTableConfiguration_presult result;
		result.success = &_return;
		result.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();

		if (result.__isset.success)
		  {
		    // _return pointer has now been filled
		    return;
		  }
		if (result.__isset.tope)
		  {
		    throw result.tope;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "getTableConfiguration failed: unknown result");
	      }

	      void
	      ClientServiceClient::getNamespaceConfiguration (
		  std::map<std::string, std::string> & _return,
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& ns)
	      {
		send_getNamespaceConfiguration (tinfo, credentials, ns);
		recv_getNamespaceConfiguration (_return);
	      }

	      void
	      ClientServiceClient::send_getNamespaceConfiguration (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& ns)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("getNamespaceConfiguration",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_getNamespaceConfiguration_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.ns = &ns;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      void
	      ClientServiceClient::recv_getNamespaceConfiguration (
		  std::map<std::string, std::string> & _return)
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
		if (fname.compare ("getNamespaceConfiguration") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		ClientService_getNamespaceConfiguration_presult result;
		result.success = &_return;
		result.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();

		if (result.__isset.success)
		  {
		    // _return pointer has now been filled
		    return;
		  }
		if (result.__isset.tope)
		  {
		    throw result.tope;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "getNamespaceConfiguration failed: unknown result");
	      }

	      bool
	      ClientServiceClient::checkClass (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& className,
		  const std::string& interfaceMatch)
	      {
		send_checkClass (tinfo, credentials, className, interfaceMatch);
		return recv_checkClass ();
	      }

	      void
	      ClientServiceClient::send_checkClass (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& className,
		  const std::string& interfaceMatch)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("checkClass",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_checkClass_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.className = &className;
		args.interfaceMatch = &interfaceMatch;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ClientServiceClient::recv_checkClass ()
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
		if (fname.compare ("checkClass") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ClientService_checkClass_presult result;
		result.success = &_return;
		result.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();

		if (result.__isset.success)
		  {
		    return _return;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "checkClass failed: unknown result");
	      }

	      bool
	      ClientServiceClient::checkTableClass (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& tableId, const std::string& className,
		  const std::string& interfaceMatch)
	      {
		send_checkTableClass (tinfo, credentials, tableId, className,
				      interfaceMatch);
		return recv_checkTableClass ();
	      }

	      void
	      ClientServiceClient::send_checkTableClass (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& tableId, const std::string& className,
		  const std::string& interfaceMatch)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("checkTableClass",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_checkTableClass_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.tableId = &tableId;
		args.className = &className;
		args.interfaceMatch = &interfaceMatch;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ClientServiceClient::recv_checkTableClass ()
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
		if (fname.compare ("checkTableClass") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ClientService_checkTableClass_presult result;
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
		    "checkTableClass failed: unknown result");
	      }

	      bool
	      ClientServiceClient::checkNamespaceClass (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& namespaceId, const std::string& className,
		  const std::string& interfaceMatch)
	      {
		send_checkNamespaceClass (tinfo, credentials, namespaceId,
					  className, interfaceMatch);
		return recv_checkNamespaceClass ();
	      }

	      void
	      ClientServiceClient::send_checkNamespaceClass (
		  const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		  const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		  const std::string& namespaceId, const std::string& className,
		  const std::string& interfaceMatch)
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("checkNamespaceClass",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ClientService_checkNamespaceClass_pargs args;
		args.tinfo = &tinfo;
		args.credentials = &credentials;
		args.namespaceId = &namespaceId;
		args.className = &className;
		args.interfaceMatch = &interfaceMatch;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ClientServiceClient::recv_checkNamespaceClass ()
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
		if (fname.compare ("checkNamespaceClass") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ClientService_checkNamespaceClass_presult result;
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
		    "checkNamespaceClass failed: unknown result");
	      }

	      bool
	      ClientServiceProcessor::dispatchCall (
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
	      ClientServiceProcessor::process_getRootTabletLocation (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.getRootTabletLocation", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.getRootTabletLocation");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.getRootTabletLocation");
		  }

		ClientService_getRootTabletLocation_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.getRootTabletLocation", bytes);
		  }

		ClientService_getRootTabletLocation_result result;
		try
		  {
		    iface_->getRootTabletLocation (result.success);
		    result.__isset.success = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.getRootTabletLocation");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"getRootTabletLocation",
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
			ctx, "ClientService.getRootTabletLocation");
		  }

		oprot->writeMessageBegin ("getRootTabletLocation",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.getRootTabletLocation", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_getInstanceId (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.getInstanceId", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.getInstanceId");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.getInstanceId");
		  }

		ClientService_getInstanceId_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.getInstanceId", bytes);
		  }

		ClientService_getInstanceId_result result;
		try
		  {
		    iface_->getInstanceId (result.success);
		    result.__isset.success = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.getInstanceId");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"getInstanceId",
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
			ctx, "ClientService.getInstanceId");
		  }

		oprot->writeMessageBegin ("getInstanceId",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.getInstanceId", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_getZooKeepers (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.getZooKeepers", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.getZooKeepers");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.getZooKeepers");
		  }

		ClientService_getZooKeepers_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.getZooKeepers", bytes);
		  }

		ClientService_getZooKeepers_result result;
		try
		  {
		    iface_->getZooKeepers (result.success);
		    result.__isset.success = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.getZooKeepers");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"getZooKeepers",
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
			ctx, "ClientService.getZooKeepers");
		  }

		oprot->writeMessageBegin ("getZooKeepers",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.getZooKeepers", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_bulkImportFiles (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.bulkImportFiles", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.bulkImportFiles");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.bulkImportFiles");
		  }

		ClientService_bulkImportFiles_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.bulkImportFiles", bytes);
		  }

		ClientService_bulkImportFiles_result result;
		try
		  {
		    iface_->bulkImportFiles (result.success, args.tinfo,
					     args.credentials, args.tid,
					     args.tableId, args.files,
					     args.errorDir, args.setTime);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.bulkImportFiles");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"bulkImportFiles",
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
			ctx, "ClientService.bulkImportFiles");
		  }

		oprot->writeMessageBegin ("bulkImportFiles",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.bulkImportFiles", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_isActive (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.isActive", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx, "ClientService.isActive");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (ctx,
						  "ClientService.isActive");
		  }

		ClientService_isActive_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (ctx,
						   "ClientService.isActive",
						   bytes);
		  }

		ClientService_isActive_result result;
		try
		  {
		    result.success = iface_->isActive (args.tinfo, args.tid);
		    result.__isset.success = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.isActive");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"isActive", ::apache::thrift::protocol::T_EXCEPTION,
			seqid);
		    x.write (oprot);
		    oprot->writeMessageEnd ();
		    oprot->getTransport ()->writeEnd ();
		    oprot->getTransport ()->flush ();
		    return;
		  }

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preWrite (ctx,
						   "ClientService.isActive");
		  }

		oprot->writeMessageBegin ("isActive",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (ctx,
						    "ClientService.isActive",
						    bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_ping (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext ("ClientService.ping",
							   callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx, "ClientService.ping");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (ctx, "ClientService.ping");
		  }

		ClientService_ping_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (ctx, "ClientService.ping",
						   bytes);
		  }

		ClientService_ping_result result;
		try
		  {
		    iface_->ping (args.credentials);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.ping");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"ping", ::apache::thrift::protocol::T_EXCEPTION, seqid);
		    x.write (oprot);
		    oprot->writeMessageEnd ();
		    oprot->getTransport ()->writeEnd ();
		    oprot->getTransport ()->flush ();
		    return;
		  }

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preWrite (ctx, "ClientService.ping");
		  }

		oprot->writeMessageBegin ("ping",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (ctx, "ClientService.ping",
						    bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_getDiskUsage (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.getDiskUsage", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.getDiskUsage");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (ctx,
						  "ClientService.getDiskUsage");
		  }

		ClientService_getDiskUsage_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (ctx,
						   "ClientService.getDiskUsage",
						   bytes);
		  }

		ClientService_getDiskUsage_result result;
		try
		  {
		    iface_->getDiskUsage (result.success, args.tables,
					  args.credentials);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &toe)
		  {
		    result.toe = toe;
		    result.__isset.toe = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.getDiskUsage");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"getDiskUsage", ::apache::thrift::protocol::T_EXCEPTION,
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
			ctx, "ClientService.getDiskUsage");
		  }

		oprot->writeMessageBegin ("getDiskUsage",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.getDiskUsage", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_listLocalUsers (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.listLocalUsers", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.listLocalUsers");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.listLocalUsers");
		  }

		ClientService_listLocalUsers_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.listLocalUsers", bytes);
		  }

		ClientService_listLocalUsers_result result;
		try
		  {
		    iface_->listLocalUsers (result.success, args.tinfo,
					    args.credentials);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.listLocalUsers");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"listLocalUsers",
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
			ctx, "ClientService.listLocalUsers");
		  }

		oprot->writeMessageBegin ("listLocalUsers",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.listLocalUsers", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_createLocalUser (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.createLocalUser", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.createLocalUser");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.createLocalUser");
		  }

		ClientService_createLocalUser_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.createLocalUser", bytes);
		  }

		ClientService_createLocalUser_result result;
		try
		  {
		    iface_->createLocalUser (args.tinfo, args.credentials,
					     args.principal, args.password);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.createLocalUser");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"createLocalUser",
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
			ctx, "ClientService.createLocalUser");
		  }

		oprot->writeMessageBegin ("createLocalUser",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.createLocalUser", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_dropLocalUser (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.dropLocalUser", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.dropLocalUser");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.dropLocalUser");
		  }

		ClientService_dropLocalUser_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.dropLocalUser", bytes);
		  }

		ClientService_dropLocalUser_result result;
		try
		  {
		    iface_->dropLocalUser (args.tinfo, args.credentials,
					   args.principal);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.dropLocalUser");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"dropLocalUser",
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
			ctx, "ClientService.dropLocalUser");
		  }

		oprot->writeMessageBegin ("dropLocalUser",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.dropLocalUser", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_changeLocalUserPassword (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.changeLocalUserPassword", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.changeLocalUserPassword");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.changeLocalUserPassword");
		  }

		ClientService_changeLocalUserPassword_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.changeLocalUserPassword", bytes);
		  }

		ClientService_changeLocalUserPassword_result result;
		try
		  {
		    iface_->changeLocalUserPassword (args.tinfo,
						     args.credentials,
						     args.principal,
						     args.password);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.changeLocalUserPassword");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"changeLocalUserPassword",
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
			ctx, "ClientService.changeLocalUserPassword");
		  }

		oprot->writeMessageBegin ("changeLocalUserPassword",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.changeLocalUserPassword", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_authenticate (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.authenticate", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.authenticate");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (ctx,
						  "ClientService.authenticate");
		  }

		ClientService_authenticate_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (ctx,
						   "ClientService.authenticate",
						   bytes);
		  }

		ClientService_authenticate_result result;
		try
		  {
		    result.success = iface_->authenticate (args.tinfo,
							   args.credentials);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.authenticate");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"authenticate", ::apache::thrift::protocol::T_EXCEPTION,
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
			ctx, "ClientService.authenticate");
		  }

		oprot->writeMessageBegin ("authenticate",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.authenticate", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_authenticateUser (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.authenticateUser", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.authenticateUser");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.authenticateUser");
		  }

		ClientService_authenticateUser_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.authenticateUser", bytes);
		  }

		ClientService_authenticateUser_result result;
		try
		  {
		    result.success = iface_->authenticateUser (args.tinfo,
							       args.credentials,
							       args.toAuth);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.authenticateUser");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"authenticateUser",
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
			ctx, "ClientService.authenticateUser");
		  }

		oprot->writeMessageBegin ("authenticateUser",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.authenticateUser", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_changeAuthorizations (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.changeAuthorizations", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.changeAuthorizations");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.changeAuthorizations");
		  }

		ClientService_changeAuthorizations_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.changeAuthorizations", bytes);
		  }

		ClientService_changeAuthorizations_result result;
		try
		  {
		    iface_->changeAuthorizations (args.tinfo, args.credentials,
						  args.principal,
						  args.authorizations);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.changeAuthorizations");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"changeAuthorizations",
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
			ctx, "ClientService.changeAuthorizations");
		  }

		oprot->writeMessageBegin ("changeAuthorizations",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.changeAuthorizations", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_getUserAuthorizations (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.getUserAuthorizations", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.getUserAuthorizations");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.getUserAuthorizations");
		  }

		ClientService_getUserAuthorizations_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.getUserAuthorizations", bytes);
		  }

		ClientService_getUserAuthorizations_result result;
		try
		  {
		    iface_->getUserAuthorizations (result.success, args.tinfo,
						   args.credentials,
						   args.principal);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.getUserAuthorizations");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"getUserAuthorizations",
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
			ctx, "ClientService.getUserAuthorizations");
		  }

		oprot->writeMessageBegin ("getUserAuthorizations",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.getUserAuthorizations", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_hasSystemPermission (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.hasSystemPermission", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.hasSystemPermission");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.hasSystemPermission");
		  }

		ClientService_hasSystemPermission_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.hasSystemPermission", bytes);
		  }

		ClientService_hasSystemPermission_result result;
		try
		  {
		    result.success = iface_->hasSystemPermission (
			args.tinfo, args.credentials, args.principal,
			args.sysPerm);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.hasSystemPermission");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"hasSystemPermission",
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
			ctx, "ClientService.hasSystemPermission");
		  }

		oprot->writeMessageBegin ("hasSystemPermission",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.hasSystemPermission", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_hasTablePermission (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.hasTablePermission", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.hasTablePermission");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.hasTablePermission");
		  }

		ClientService_hasTablePermission_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.hasTablePermission", bytes);
		  }

		ClientService_hasTablePermission_result result;
		try
		  {
		    result.success = iface_->hasTablePermission (
			args.tinfo, args.credentials, args.principal,
			args.tableName, args.tblPerm);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.hasTablePermission");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"hasTablePermission",
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
			ctx, "ClientService.hasTablePermission");
		  }

		oprot->writeMessageBegin ("hasTablePermission",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.hasTablePermission", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_hasNamespacePermission (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.hasNamespacePermission", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.hasNamespacePermission");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.hasNamespacePermission");
		  }

		ClientService_hasNamespacePermission_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.hasNamespacePermission", bytes);
		  }

		ClientService_hasNamespacePermission_result result;
		try
		  {
		    result.success = iface_->hasNamespacePermission (
			args.tinfo, args.credentials, args.principal, args.ns,
			args.tblNspcPerm);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.hasNamespacePermission");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"hasNamespacePermission",
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
			ctx, "ClientService.hasNamespacePermission");
		  }

		oprot->writeMessageBegin ("hasNamespacePermission",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.hasNamespacePermission", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_grantSystemPermission (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.grantSystemPermission", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.grantSystemPermission");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.grantSystemPermission");
		  }

		ClientService_grantSystemPermission_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.grantSystemPermission", bytes);
		  }

		ClientService_grantSystemPermission_result result;
		try
		  {
		    iface_->grantSystemPermission (args.tinfo, args.credentials,
						   args.principal,
						   args.permission);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.grantSystemPermission");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"grantSystemPermission",
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
			ctx, "ClientService.grantSystemPermission");
		  }

		oprot->writeMessageBegin ("grantSystemPermission",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.grantSystemPermission", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_revokeSystemPermission (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.revokeSystemPermission", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.revokeSystemPermission");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.revokeSystemPermission");
		  }

		ClientService_revokeSystemPermission_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.revokeSystemPermission", bytes);
		  }

		ClientService_revokeSystemPermission_result result;
		try
		  {
		    iface_->revokeSystemPermission (args.tinfo,
						    args.credentials,
						    args.principal,
						    args.permission);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.revokeSystemPermission");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"revokeSystemPermission",
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
			ctx, "ClientService.revokeSystemPermission");
		  }

		oprot->writeMessageBegin ("revokeSystemPermission",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.revokeSystemPermission", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_grantTablePermission (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.grantTablePermission", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.grantTablePermission");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.grantTablePermission");
		  }

		ClientService_grantTablePermission_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.grantTablePermission", bytes);
		  }

		ClientService_grantTablePermission_result result;
		try
		  {
		    iface_->grantTablePermission (args.tinfo, args.credentials,
						  args.principal,
						  args.tableName,
						  args.permission);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.grantTablePermission");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"grantTablePermission",
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
			ctx, "ClientService.grantTablePermission");
		  }

		oprot->writeMessageBegin ("grantTablePermission",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.grantTablePermission", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_revokeTablePermission (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.revokeTablePermission", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.revokeTablePermission");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.revokeTablePermission");
		  }

		ClientService_revokeTablePermission_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.revokeTablePermission", bytes);
		  }

		ClientService_revokeTablePermission_result result;
		try
		  {
		    iface_->revokeTablePermission (args.tinfo, args.credentials,
						   args.principal,
						   args.tableName,
						   args.permission);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.revokeTablePermission");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"revokeTablePermission",
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
			ctx, "ClientService.revokeTablePermission");
		  }

		oprot->writeMessageBegin ("revokeTablePermission",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.revokeTablePermission", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_grantNamespacePermission (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.grantNamespacePermission", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.grantNamespacePermission");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.grantNamespacePermission");
		  }

		ClientService_grantNamespacePermission_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.grantNamespacePermission", bytes);
		  }

		ClientService_grantNamespacePermission_result result;
		try
		  {
		    iface_->grantNamespacePermission (args.tinfo,
						      args.credentials,
						      args.principal, args.ns,
						      args.permission);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.grantNamespacePermission");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"grantNamespacePermission",
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
			ctx, "ClientService.grantNamespacePermission");
		  }

		oprot->writeMessageBegin ("grantNamespacePermission",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.grantNamespacePermission", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_revokeNamespacePermission (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.revokeNamespacePermission", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.revokeNamespacePermission");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.revokeNamespacePermission");
		  }

		ClientService_revokeNamespacePermission_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.revokeNamespacePermission", bytes);
		  }

		ClientService_revokeNamespacePermission_result result;
		try
		  {
		    iface_->revokeNamespacePermission (args.tinfo,
						       args.credentials,
						       args.principal, args.ns,
						       args.permission);
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.revokeNamespacePermission");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"revokeNamespacePermission",
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
			ctx, "ClientService.revokeNamespacePermission");
		  }

		oprot->writeMessageBegin ("revokeNamespacePermission",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.revokeNamespacePermission", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_getConfiguration (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.getConfiguration", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.getConfiguration");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.getConfiguration");
		  }

		ClientService_getConfiguration_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.getConfiguration", bytes);
		  }

		ClientService_getConfiguration_result result;
		try
		  {
		    iface_->getConfiguration (result.success, args.tinfo,
					      args.credentials, args.type);
		    result.__isset.success = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.getConfiguration");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"getConfiguration",
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
			ctx, "ClientService.getConfiguration");
		  }

		oprot->writeMessageBegin ("getConfiguration",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.getConfiguration", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_getTableConfiguration (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.getTableConfiguration", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.getTableConfiguration");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.getTableConfiguration");
		  }

		ClientService_getTableConfiguration_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.getTableConfiguration", bytes);
		  }

		ClientService_getTableConfiguration_result result;
		try
		  {
		    iface_->getTableConfiguration (result.success, args.tinfo,
						   args.credentials,
						   args.tableName);
		    result.__isset.success = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.getTableConfiguration");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"getTableConfiguration",
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
			ctx, "ClientService.getTableConfiguration");
		  }

		oprot->writeMessageBegin ("getTableConfiguration",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.getTableConfiguration", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_getNamespaceConfiguration (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.getNamespaceConfiguration", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.getNamespaceConfiguration");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.getNamespaceConfiguration");
		  }

		ClientService_getNamespaceConfiguration_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.getNamespaceConfiguration", bytes);
		  }

		ClientService_getNamespaceConfiguration_result result;
		try
		  {
		    iface_->getNamespaceConfiguration (result.success,
						       args.tinfo,
						       args.credentials,
						       args.ns);
		    result.__isset.success = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.getNamespaceConfiguration");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"getNamespaceConfiguration",
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
			ctx, "ClientService.getNamespaceConfiguration");
		  }

		oprot->writeMessageBegin ("getNamespaceConfiguration",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.getNamespaceConfiguration", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_checkClass (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.checkClass", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.checkClass");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (ctx,
						  "ClientService.checkClass");
		  }

		ClientService_checkClass_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (ctx,
						   "ClientService.checkClass",
						   bytes);
		  }

		ClientService_checkClass_result result;
		try
		  {
		    result.success = iface_->checkClass (args.tinfo,
							 args.credentials,
							 args.className,
							 args.interfaceMatch);
		    result.__isset.success = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.checkClass");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"checkClass", ::apache::thrift::protocol::T_EXCEPTION,
			seqid);
		    x.write (oprot);
		    oprot->writeMessageEnd ();
		    oprot->getTransport ()->writeEnd ();
		    oprot->getTransport ()->flush ();
		    return;
		  }

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preWrite (ctx,
						   "ClientService.checkClass");
		  }

		oprot->writeMessageBegin ("checkClass",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (ctx,
						    "ClientService.checkClass",
						    bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_checkTableClass (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.checkTableClass", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.checkTableClass");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.checkTableClass");
		  }

		ClientService_checkTableClass_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.checkTableClass", bytes);
		  }

		ClientService_checkTableClass_result result;
		try
		  {
		    result.success = iface_->checkTableClass (
			args.tinfo, args.credentials, args.tableId,
			args.className, args.interfaceMatch);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.checkTableClass");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"checkTableClass",
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
			ctx, "ClientService.checkTableClass");
		  }

		oprot->writeMessageBegin ("checkTableClass",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.checkTableClass", bytes);
		  }
	      }

	      void
	      ClientServiceProcessor::process_checkNamespaceClass (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ClientService.checkNamespaceClass", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx,
		    "ClientService.checkNamespaceClass");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (
			ctx, "ClientService.checkNamespaceClass");
		  }

		ClientService_checkNamespaceClass_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (
			ctx, "ClientService.checkNamespaceClass", bytes);
		  }

		ClientService_checkNamespaceClass_result result;
		try
		  {
		    result.success = iface_->checkNamespaceClass (
			args.tinfo, args.credentials, args.namespaceId,
			args.className, args.interfaceMatch);
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &sec)
		  {
		    result.sec = sec;
		    result.__isset.sec = true;
		  }
		catch (ThriftTableOperationException &tope)
		  {
		    result.tope = tope;
		    result.__isset.tope = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ClientService.checkNamespaceClass");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"checkNamespaceClass",
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
			ctx, "ClientService.checkNamespaceClass");
		  }

		oprot->writeMessageBegin ("checkNamespaceClass",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (
			ctx, "ClientService.checkNamespaceClass", bytes);
		  }
	      }

	      ::boost::shared_ptr<::apache::thrift::TProcessor>
	      ClientServiceProcessorFactory::getProcessor (
		  const ::apache::thrift::TConnectionInfo& connInfo)
	      {
		::apache::thrift::ReleaseHandler<ClientServiceIfFactory> cleanup (
		    handlerFactory_);
		::boost::shared_ptr<ClientServiceIf> handler (
		    handlerFactory_->getHandler (connInfo), cleanup);
		::boost::shared_ptr<::apache::thrift::TProcessor> processor (
		    new ClientServiceProcessor (handler));
		return processor;
	      }
	    }
	  }
	}
      }
    }
  }
} // namespace

