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
#include "../../../../include/data/extern/thrift/client_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

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

	      int _kTableOperationValues[] =
		{ TableOperation::CREATE, TableOperation::DELETE,
		    TableOperation::RENAME, TableOperation::SET_PROPERTY,
		    TableOperation::REMOVE_PROPERTY, TableOperation::OFFLINE,
		    TableOperation::ONLINE, TableOperation::FLUSH,
		    TableOperation::PERMISSION, TableOperation::CLONE,
		    TableOperation::MERGE, TableOperation::DELETE_RANGE,
		    TableOperation::BULK_IMPORT, TableOperation::COMPACT,
		    TableOperation::IMPORT, TableOperation::EXPORT,
		    TableOperation::COMPACT_CANCEL };
	      const char* _kTableOperationNames[] =
		{ "CREATE", "DELETE", "RENAME", "SET_PROPERTY",
		    "REMOVE_PROPERTY", "OFFLINE", "ONLINE", "FLUSH",
		    "PERMISSION", "CLONE", "MERGE", "DELETE_RANGE",
		    "BULK_IMPORT", "COMPACT", "IMPORT", "EXPORT",
		    "COMPACT_CANCEL" };
	      const std::map<int, const char*> _TableOperation_VALUES_TO_NAMES (
		  ::apache::thrift::TEnumIterator (17, _kTableOperationValues,
						   _kTableOperationNames),
		  ::apache::thrift::TEnumIterator (-1, NULL, NULL));

	      int _kTableOperationExceptionTypeValues[] =
		{ TableOperationExceptionType::EXISTS,
		    TableOperationExceptionType::NOTFOUND,
		    TableOperationExceptionType::OFFLINE,
		    TableOperationExceptionType::BULK_BAD_INPUT_DIRECTORY,
		    TableOperationExceptionType::BULK_BAD_ERROR_DIRECTORY,
		    TableOperationExceptionType::BAD_RANGE,
		    TableOperationExceptionType::OTHER,
		    TableOperationExceptionType::NAMESPACE_EXISTS,
		    TableOperationExceptionType::NAMESPACE_NOTFOUND,
		    TableOperationExceptionType::INVALID_NAME };
	      const char* _kTableOperationExceptionTypeNames[] =
		{ "EXISTS", "NOTFOUND", "OFFLINE", "BULK_BAD_INPUT_DIRECTORY",
		    "BULK_BAD_ERROR_DIRECTORY", "BAD_RANGE", "OTHER",
		    "NAMESPACE_EXISTS", "NAMESPACE_NOTFOUND", "INVALID_NAME" };
	      const std::map<int, const char*> _TableOperationExceptionType_VALUES_TO_NAMES (
		  ::apache::thrift::TEnumIterator (
		      10, _kTableOperationExceptionTypeValues,
		      _kTableOperationExceptionTypeNames),
		  ::apache::thrift::TEnumIterator (-1, NULL, NULL));

	      int _kConfigurationTypeValues[] =
		{ ConfigurationType::CURRENT, ConfigurationType::SITE,
		    ConfigurationType::DEFAULT };
	      const char* _kConfigurationTypeNames[] =
		{ "CURRENT", "SITE", "DEFAULT" };
	      const std::map<int, const char*> _ConfigurationType_VALUES_TO_NAMES (
		  ::apache::thrift::TEnumIterator (3, _kConfigurationTypeValues,
						   _kConfigurationTypeNames),
		  ::apache::thrift::TEnumIterator (-1, NULL, NULL));

	      int _kSecurityErrorCodeValues[] =
		{ SecurityErrorCode::DEFAULT_SECURITY_ERROR,
		    SecurityErrorCode::BAD_CREDENTIALS,
		    SecurityErrorCode::PERMISSION_DENIED,
		    SecurityErrorCode::USER_DOESNT_EXIST,
		    SecurityErrorCode::CONNECTION_ERROR,
		    SecurityErrorCode::USER_EXISTS,
		    SecurityErrorCode::GRANT_INVALID,
		    SecurityErrorCode::BAD_AUTHORIZATIONS,
		    SecurityErrorCode::INVALID_INSTANCEID,
		    SecurityErrorCode::TABLE_DOESNT_EXIST,
		    SecurityErrorCode::UNSUPPORTED_OPERATION,
		    SecurityErrorCode::INVALID_TOKEN,
		    SecurityErrorCode::AUTHENTICATOR_FAILED,
		    SecurityErrorCode::AUTHORIZOR_FAILED,
		    SecurityErrorCode::PERMISSIONHANDLER_FAILED,
		    SecurityErrorCode::TOKEN_EXPIRED,
		    SecurityErrorCode::SERIALIZATION_ERROR,
		    SecurityErrorCode::INSUFFICIENT_PROPERTIES,
		    SecurityErrorCode::NAMESPACE_DOESNT_EXIST };
	      const char* _kSecurityErrorCodeNames[] =
		{ "DEFAULT_SECURITY_ERROR", "BAD_CREDENTIALS",
		    "PERMISSION_DENIED", "USER_DOESNT_EXIST",
		    "CONNECTION_ERROR", "USER_EXISTS", "GRANT_INVALID",
		    "BAD_AUTHORIZATIONS", "INVALID_INSTANCEID",
		    "TABLE_DOESNT_EXIST", "UNSUPPORTED_OPERATION",
		    "INVALID_TOKEN", "AUTHENTICATOR_FAILED",
		    "AUTHORIZOR_FAILED", "PERMISSIONHANDLER_FAILED",
		    "TOKEN_EXPIRED", "SERIALIZATION_ERROR",
		    "INSUFFICIENT_PROPERTIES", "NAMESPACE_DOESNT_EXIST" };
	      const std::map<int, const char*> _SecurityErrorCode_VALUES_TO_NAMES (
		  ::apache::thrift::TEnumIterator (19,
						   _kSecurityErrorCodeValues,
						   _kSecurityErrorCodeNames),
		  ::apache::thrift::TEnumIterator (-1, NULL, NULL));

	      ThriftSecurityException::~ThriftSecurityException () throw ()
	      {
	      }

	      void
	      ThriftSecurityException::__set_user (const std::string& val)
	      {
		this->user = val;
	      }

	      void
	      ThriftSecurityException::__set_code (
		  const SecurityErrorCode::type val)
	      {
		this->code = val;
	      }

	      const char* ThriftSecurityException::ascii_fingerprint =
		  "D6FD826D949221396F4FFC3ECCD3D192";
	      const uint8_t ThriftSecurityException::binary_fingerprint[16] =
		{ 0xD6, 0xFD, 0x82, 0x6D, 0x94, 0x92, 0x21, 0x39, 0x6F, 0x4F,
		    0xFC, 0x3E, 0xCC, 0xD3, 0xD1, 0x92 };

	      uint32_t
	      ThriftSecurityException::read (
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
			if (ftype == ::apache::thrift::protocol::T_STRING)
			  {
			    xfer += iprot->readString (this->user);
			    this->__isset.user = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
			if (ftype == ::apache::thrift::protocol::T_I32)
			  {
			    int32_t ecast0;
			    xfer += iprot->readI32 (ecast0);
			    this->code = (SecurityErrorCode::type) ecast0;
			    this->__isset.code = true;
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
	      ThriftSecurityException::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("ThriftSecurityException");

		xfer += oprot->writeFieldBegin (
		    "user", ::apache::thrift::protocol::T_STRING, 1);
		xfer += oprot->writeString (this->user);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "code", ::apache::thrift::protocol::T_I32, 2);
		xfer += oprot->writeI32 ((int32_t) this->code);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      void
	      swap (ThriftSecurityException &a, ThriftSecurityException &b)
	      {
		using ::std::swap;
		swap (a.user, b.user);
		swap (a.code, b.code);
		swap (a.__isset, b.__isset);
	      }

	      ThriftSecurityException::ThriftSecurityException (
		  const ThriftSecurityException& other1) :
		  TException ()
	      {
		user = other1.user;
		code = other1.code;
		__isset = other1.__isset;
	      }
	      ThriftSecurityException&
	      ThriftSecurityException::operator= (
		  const ThriftSecurityException& other2)
	      {
		user = other2.user;
		code = other2.code;
		__isset = other2.__isset;
		return *this;
	      }
	      std::ostream&
	      operator<< (std::ostream& out, const ThriftSecurityException& obj)
	      {
		using ::apache::thrift::to_string;
		out << "ThriftSecurityException(";
		out << "user=" << to_string (obj.user);
		out << ", " << "code=" << to_string (obj.code);
		out << ")";
		return out;
	      }

	      ThriftTableOperationException::~ThriftTableOperationException () throw ()
	      {
	      }

	      void
	      ThriftTableOperationException::__set_tableId (
		  const std::string& val)
	      {
		this->tableId = val;
	      }

	      void
	      ThriftTableOperationException::__set_tableName (
		  const std::string& val)
	      {
		this->tableName = val;
	      }

	      void
	      ThriftTableOperationException::__set_op (
		  const TableOperation::type val)
	      {
		this->op = val;
	      }

	      void
	      ThriftTableOperationException::__set_type (
		  const TableOperationExceptionType::type val)
	      {
		this->type = val;
	      }

	      void
	      ThriftTableOperationException::__set_description (
		  const std::string& val)
	      {
		this->description = val;
	      }

	      const char* ThriftTableOperationException::ascii_fingerprint =
		  "25ADB6C99E620F729A978F0716AE3156";
	      const uint8_t ThriftTableOperationException::binary_fingerprint[16] =
		{ 0x25, 0xAD, 0xB6, 0xC9, 0x9E, 0x62, 0x0F, 0x72, 0x9A, 0x97,
		    0x8F, 0x07, 0x16, 0xAE, 0x31, 0x56 };

	      uint32_t
	      ThriftTableOperationException::read (
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
			if (ftype == ::apache::thrift::protocol::T_I32)
			  {
			    int32_t ecast3;
			    xfer += iprot->readI32 (ecast3);
			    this->op = (TableOperation::type) ecast3;
			    this->__isset.op = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 4:
			if (ftype == ::apache::thrift::protocol::T_I32)
			  {
			    int32_t ecast4;
			    xfer += iprot->readI32 (ecast4);
			    this->type =
				(TableOperationExceptionType::type) ecast4;
			    this->__isset.type = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 5:
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
	      ThriftTableOperationException::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ThriftTableOperationException");

		xfer += oprot->writeFieldBegin (
		    "tableId", ::apache::thrift::protocol::T_STRING, 1);
		xfer += oprot->writeString (this->tableId);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "tableName", ::apache::thrift::protocol::T_STRING, 2);
		xfer += oprot->writeString (this->tableName);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "op", ::apache::thrift::protocol::T_I32, 3);
		xfer += oprot->writeI32 ((int32_t) this->op);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "type", ::apache::thrift::protocol::T_I32, 4);
		xfer += oprot->writeI32 ((int32_t) this->type);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "description", ::apache::thrift::protocol::T_STRING, 5);
		xfer += oprot->writeString (this->description);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      void
	      swap (ThriftTableOperationException &a,
		    ThriftTableOperationException &b)
	      {
		using ::std::swap;
		swap (a.tableId, b.tableId);
		swap (a.tableName, b.tableName);
		swap (a.op, b.op);
		swap (a.type, b.type);
		swap (a.description, b.description);
		swap (a.__isset, b.__isset);
	      }

	      ThriftTableOperationException::ThriftTableOperationException (
		  const ThriftTableOperationException& other5) :
		  TException ()
	      {
		tableId = other5.tableId;
		tableName = other5.tableName;
		op = other5.op;
		type = other5.type;
		description = other5.description;
		__isset = other5.__isset;
	      }
	      ThriftTableOperationException&
	      ThriftTableOperationException::operator= (
		  const ThriftTableOperationException& other6)
	      {
		tableId = other6.tableId;
		tableName = other6.tableName;
		op = other6.op;
		type = other6.type;
		description = other6.description;
		__isset = other6.__isset;
		return *this;
	      }
	      std::ostream&
	      operator<< (std::ostream& out,
			  const ThriftTableOperationException& obj)
	      {
		using ::apache::thrift::to_string;
		out << "ThriftTableOperationException(";
		out << "tableId=" << to_string (obj.tableId);
		out << ", " << "tableName=" << to_string (obj.tableName);
		out << ", " << "op=" << to_string (obj.op);
		out << ", " << "type=" << to_string (obj.type);
		out << ", " << "description=" << to_string (obj.description);
		out << ")";
		return out;
	      }

	      TDiskUsage::~TDiskUsage () throw ()
	      {
	      }

	      void
	      TDiskUsage::__set_tables (const std::vector<std::string> & val)
	      {
		this->tables = val;
	      }

	      void
	      TDiskUsage::__set_usage (const int64_t val)
	      {
		this->usage = val;
	      }

	      const char* TDiskUsage::ascii_fingerprint =
		  "D26F4F5E2867D41CF7E0391263932D6B";
	      const uint8_t TDiskUsage::binary_fingerprint[16] =
		{ 0xD2, 0x6F, 0x4F, 0x5E, 0x28, 0x67, 0xD4, 0x1C, 0xF7, 0xE0,
		    0x39, 0x12, 0x63, 0x93, 0x2D, 0x6B };

	      uint32_t
	      TDiskUsage::read (::apache::thrift::protocol::TProtocol* iprot)
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
			if (ftype == ::apache::thrift::protocol::T_LIST)
			  {
			      {
				this->tables.clear ();
				uint32_t _size7;
				::apache::thrift::protocol::TType _etype10;
				xfer += iprot->readListBegin (_etype10, _size7);
				this->tables.resize (_size7);
				uint32_t _i11;
				for (_i11 = 0; _i11 < _size7; ++_i11)
				  {
				    xfer += iprot->readString (
					this->tables[_i11]);
				  }
				xfer += iprot->readListEnd ();
			      }
			    this->__isset.tables = true;
			  }
			else
			  {
			    xfer += iprot->skip (ftype);
			  }
			break;
		      case 2:
			if (ftype == ::apache::thrift::protocol::T_I64)
			  {
			    xfer += iprot->readI64 (this->usage);
			    this->__isset.usage = true;
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
	      TDiskUsage::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("TDiskUsage");

		xfer += oprot->writeFieldBegin (
		    "tables", ::apache::thrift::protocol::T_LIST, 1);
		  {
		    xfer += oprot->writeListBegin (
			::apache::thrift::protocol::T_STRING,
			static_cast<uint32_t> (this->tables.size ()));
		    std::vector<std::string>::const_iterator _iter12;
		    for (_iter12 = this->tables.begin ();
			_iter12 != this->tables.end (); ++_iter12)
		      {
			xfer += oprot->writeString ((*_iter12));
		      }
		    xfer += oprot->writeListEnd ();
		  }
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldBegin (
		    "usage", ::apache::thrift::protocol::T_I64, 2);
		xfer += oprot->writeI64 (this->usage);
		xfer += oprot->writeFieldEnd ();

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      void
	      swap (TDiskUsage &a, TDiskUsage &b)
	      {
		using ::std::swap;
		swap (a.tables, b.tables);
		swap (a.usage, b.usage);
		swap (a.__isset, b.__isset);
	      }

	      TDiskUsage::TDiskUsage (const TDiskUsage& other13)
	      {
		tables = other13.tables;
		usage = other13.usage;
		__isset = other13.__isset;
	      }
	      TDiskUsage&
	      TDiskUsage::operator= (const TDiskUsage& other14)
	      {
		tables = other14.tables;
		usage = other14.usage;
		__isset = other14.__isset;
		return *this;
	      }
	      std::ostream&
	      operator<< (std::ostream& out, const TDiskUsage& obj)
	      {
		using ::apache::thrift::to_string;
		out << "TDiskUsage(";
		out << "tables=" << to_string (obj.tables);
		out << ", " << "usage=" << to_string (obj.usage);
		out << ")";
		return out;
	      }

	    }
	  }
	}
      }
    }
  }
} // namespace
