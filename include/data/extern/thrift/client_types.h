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
#ifndef client_TYPES_H
#define client_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "security_types.h"
#include "trace_types.h"


namespace org { namespace apache { namespace accumulo { namespace core { namespace client { namespace impl { namespace thrift {

struct TableOperation {
  enum type {
    CREATE = 0,
    DELETE = 1,
    RENAME = 2,
    SET_PROPERTY = 3,
    REMOVE_PROPERTY = 4,
    OFFLINE = 5,
    ONLINE = 6,
    FLUSH = 7,
    PERMISSION = 8,
    CLONE = 9,
    MERGE = 10,
    DELETE_RANGE = 11,
    BULK_IMPORT = 12,
    COMPACT = 13,
    IMPORT = 14,
    EXPORT = 15,
    COMPACT_CANCEL = 16
  };
};

extern const std::map<int, const char*> _TableOperation_VALUES_TO_NAMES;

struct TableOperationExceptionType {
  enum type {
    EXISTS = 0,
    NOTFOUND = 1,
    OFFLINE = 2,
    BULK_BAD_INPUT_DIRECTORY = 3,
    BULK_BAD_ERROR_DIRECTORY = 4,
    BAD_RANGE = 5,
    OTHER = 6,
    NAMESPACE_EXISTS = 7,
    NAMESPACE_NOTFOUND = 8,
    INVALID_NAME = 9
  };
};

extern const std::map<int, const char*> _TableOperationExceptionType_VALUES_TO_NAMES;

struct ConfigurationType {
  enum type {
    CURRENT = 0,
    SITE = 1,
    DEFAULT = 2
  };
};

extern const std::map<int, const char*> _ConfigurationType_VALUES_TO_NAMES;

struct SecurityErrorCode {
  enum type {
    DEFAULT_SECURITY_ERROR = 0,
    BAD_CREDENTIALS = 1,
    PERMISSION_DENIED = 2,
    USER_DOESNT_EXIST = 3,
    CONNECTION_ERROR = 4,
    USER_EXISTS = 5,
    GRANT_INVALID = 6,
    BAD_AUTHORIZATIONS = 7,
    INVALID_INSTANCEID = 8,
    TABLE_DOESNT_EXIST = 9,
    UNSUPPORTED_OPERATION = 10,
    INVALID_TOKEN = 11,
    AUTHENTICATOR_FAILED = 12,
    AUTHORIZOR_FAILED = 13,
    PERMISSIONHANDLER_FAILED = 14,
    TOKEN_EXPIRED = 15,
    SERIALIZATION_ERROR = 16,
    INSUFFICIENT_PROPERTIES = 17,
    NAMESPACE_DOESNT_EXIST = 18
  };
};

extern const std::map<int, const char*> _SecurityErrorCode_VALUES_TO_NAMES;

class ThriftSecurityException;

class ThriftTableOperationException;

class TDiskUsage;

typedef struct _ThriftSecurityException__isset {
  _ThriftSecurityException__isset() : user(false), code(false) {}
  bool user :1;
  bool code :1;
} _ThriftSecurityException__isset;

class ThriftSecurityException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "D6FD826D949221396F4FFC3ECCD3D192";
  static const uint8_t binary_fingerprint[16]; // = {0xD6,0xFD,0x82,0x6D,0x94,0x92,0x21,0x39,0x6F,0x4F,0xFC,0x3E,0xCC,0xD3,0xD1,0x92};

  ThriftSecurityException(const ThriftSecurityException&);
  ThriftSecurityException& operator=(const ThriftSecurityException&);
  ThriftSecurityException() : user(), code((SecurityErrorCode::type)0) {
  }

  virtual ~ThriftSecurityException() throw();
  std::string user;
  SecurityErrorCode::type code;

  _ThriftSecurityException__isset __isset;

  void __set_user(const std::string& val);

  void __set_code(const SecurityErrorCode::type val);

  bool operator == (const ThriftSecurityException & rhs) const
  {
    if (!(user == rhs.user))
      return false;
    if (!(code == rhs.code))
      return false;
    return true;
  }
  bool operator != (const ThriftSecurityException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftSecurityException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftSecurityException& obj);
};

void swap(ThriftSecurityException &a, ThriftSecurityException &b);

typedef struct _ThriftTableOperationException__isset {
  _ThriftTableOperationException__isset() : tableId(false), tableName(false), op(false), type(false), description(false) {}
  bool tableId :1;
  bool tableName :1;
  bool op :1;
  bool type :1;
  bool description :1;
} _ThriftTableOperationException__isset;

class ThriftTableOperationException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "25ADB6C99E620F729A978F0716AE3156";
  static const uint8_t binary_fingerprint[16]; // = {0x25,0xAD,0xB6,0xC9,0x9E,0x62,0x0F,0x72,0x9A,0x97,0x8F,0x07,0x16,0xAE,0x31,0x56};

  ThriftTableOperationException(const ThriftTableOperationException&);
  ThriftTableOperationException& operator=(const ThriftTableOperationException&);
  ThriftTableOperationException() : tableId(), tableName(), op((TableOperation::type)0), type((TableOperationExceptionType::type)0), description() {
  }

  virtual ~ThriftTableOperationException() throw();
  std::string tableId;
  std::string tableName;
  TableOperation::type op;
  TableOperationExceptionType::type type;
  std::string description;

  _ThriftTableOperationException__isset __isset;

  void __set_tableId(const std::string& val);

  void __set_tableName(const std::string& val);

  void __set_op(const TableOperation::type val);

  void __set_type(const TableOperationExceptionType::type val);

  void __set_description(const std::string& val);

  bool operator == (const ThriftTableOperationException & rhs) const
  {
    if (!(tableId == rhs.tableId))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    if (!(op == rhs.op))
      return false;
    if (!(type == rhs.type))
      return false;
    if (!(description == rhs.description))
      return false;
    return true;
  }
  bool operator != (const ThriftTableOperationException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftTableOperationException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTableOperationException& obj);
};

void swap(ThriftTableOperationException &a, ThriftTableOperationException &b);

typedef struct _TDiskUsage__isset {
  _TDiskUsage__isset() : tables(false), usage(false) {}
  bool tables :1;
  bool usage :1;
} _TDiskUsage__isset;

class TDiskUsage {
 public:

  static const char* ascii_fingerprint; // = "D26F4F5E2867D41CF7E0391263932D6B";
  static const uint8_t binary_fingerprint[16]; // = {0xD2,0x6F,0x4F,0x5E,0x28,0x67,0xD4,0x1C,0xF7,0xE0,0x39,0x12,0x63,0x93,0x2D,0x6B};

  TDiskUsage(const TDiskUsage&);
  TDiskUsage& operator=(const TDiskUsage&);
  TDiskUsage() : usage(0) {
  }

  virtual ~TDiskUsage() throw();
  std::vector<std::string>  tables;
  int64_t usage;

  _TDiskUsage__isset __isset;

  void __set_tables(const std::vector<std::string> & val);

  void __set_usage(const int64_t val);

  bool operator == (const TDiskUsage & rhs) const
  {
    if (!(tables == rhs.tables))
      return false;
    if (!(usage == rhs.usage))
      return false;
    return true;
  }
  bool operator != (const TDiskUsage &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDiskUsage & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TDiskUsage& obj);
};

void swap(TDiskUsage &a, TDiskUsage &b);

}}}}}}} // namespace

#endif
