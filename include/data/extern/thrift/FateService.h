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
#ifndef FateService_H
#define FateService_H

#include <thrift/TDispatchProcessor.h>
#include "master_types.h"

namespace org { namespace apache { namespace accumulo { namespace core { namespace master { namespace thrift {

class FateServiceIf {
 public:
  virtual ~FateServiceIf() {}
  virtual int64_t beginFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void executeFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid, const FateOperation::type op, const std::vector<std::string> & arguments, const std::map<std::string, std::string> & options, const bool autoClean) = 0;
  virtual void waitForFateOperation(std::string& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid) = 0;
  virtual void finishFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid) = 0;
};

class FateServiceIfFactory {
 public:
  typedef FateServiceIf Handler;

  virtual ~FateServiceIfFactory() {}

  virtual FateServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(FateServiceIf* /* handler */) = 0;
};

class FateServiceIfSingletonFactory : virtual public FateServiceIfFactory {
 public:
  FateServiceIfSingletonFactory(const boost::shared_ptr<FateServiceIf>& iface) : iface_(iface) {}
  virtual ~FateServiceIfSingletonFactory() {}

  virtual FateServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(FateServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<FateServiceIf> iface_;
};

class FateServiceNull : virtual public FateServiceIf {
 public:
  virtual ~FateServiceNull() {}
  int64_t beginFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    int64_t _return = 0;
    return _return;
  }
  void executeFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const int64_t /* opid */, const FateOperation::type /* op */, const std::vector<std::string> & /* arguments */, const std::map<std::string, std::string> & /* options */, const bool /* autoClean */) {
    return;
  }
  void waitForFateOperation(std::string& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const int64_t /* opid */) {
    return;
  }
  void finishFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const int64_t /* opid */) {
    return;
  }
};

typedef struct _FateService_beginFateOperation_args__isset {
  _FateService_beginFateOperation_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _FateService_beginFateOperation_args__isset;

class FateService_beginFateOperation_args {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};

  FateService_beginFateOperation_args(const FateService_beginFateOperation_args&);
  FateService_beginFateOperation_args& operator=(const FateService_beginFateOperation_args&);
  FateService_beginFateOperation_args() {
  }

  virtual ~FateService_beginFateOperation_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _FateService_beginFateOperation_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const FateService_beginFateOperation_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const FateService_beginFateOperation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FateService_beginFateOperation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_beginFateOperation_args& obj);
};


class FateService_beginFateOperation_pargs {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};


  virtual ~FateService_beginFateOperation_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_beginFateOperation_pargs& obj);
};

typedef struct _FateService_beginFateOperation_result__isset {
  _FateService_beginFateOperation_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _FateService_beginFateOperation_result__isset;

class FateService_beginFateOperation_result {
 public:

  static const char* ascii_fingerprint; // = "818A97934A3C4E258585F1C39CCD5F56";
  static const uint8_t binary_fingerprint[16]; // = {0x81,0x8A,0x97,0x93,0x4A,0x3C,0x4E,0x25,0x85,0x85,0xF1,0xC3,0x9C,0xCD,0x5F,0x56};

  FateService_beginFateOperation_result(const FateService_beginFateOperation_result&);
  FateService_beginFateOperation_result& operator=(const FateService_beginFateOperation_result&);
  FateService_beginFateOperation_result() : success(0) {
  }

  virtual ~FateService_beginFateOperation_result() throw();
  int64_t success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _FateService_beginFateOperation_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const FateService_beginFateOperation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const FateService_beginFateOperation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FateService_beginFateOperation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_beginFateOperation_result& obj);
};

typedef struct _FateService_beginFateOperation_presult__isset {
  _FateService_beginFateOperation_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _FateService_beginFateOperation_presult__isset;

class FateService_beginFateOperation_presult {
 public:

  static const char* ascii_fingerprint; // = "818A97934A3C4E258585F1C39CCD5F56";
  static const uint8_t binary_fingerprint[16]; // = {0x81,0x8A,0x97,0x93,0x4A,0x3C,0x4E,0x25,0x85,0x85,0xF1,0xC3,0x9C,0xCD,0x5F,0x56};


  virtual ~FateService_beginFateOperation_presult() throw();
  int64_t* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _FateService_beginFateOperation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const FateService_beginFateOperation_presult& obj);
};

typedef struct _FateService_executeFateOperation_args__isset {
  _FateService_executeFateOperation_args__isset() : tinfo(false), credentials(false), opid(false), op(false), arguments(false), options(false), autoClean(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool opid :1;
  bool op :1;
  bool arguments :1;
  bool options :1;
  bool autoClean :1;
} _FateService_executeFateOperation_args__isset;

class FateService_executeFateOperation_args {
 public:

  static const char* ascii_fingerprint; // = "C5E83F05C192CE192A23C9E51DBD957A";
  static const uint8_t binary_fingerprint[16]; // = {0xC5,0xE8,0x3F,0x05,0xC1,0x92,0xCE,0x19,0x2A,0x23,0xC9,0xE5,0x1D,0xBD,0x95,0x7A};

  FateService_executeFateOperation_args(const FateService_executeFateOperation_args&);
  FateService_executeFateOperation_args& operator=(const FateService_executeFateOperation_args&);
  FateService_executeFateOperation_args() : opid(0), op((FateOperation::type)0), autoClean(0) {
  }

  virtual ~FateService_executeFateOperation_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  int64_t opid;
  FateOperation::type op;
  std::vector<std::string>  arguments;
  std::map<std::string, std::string>  options;
  bool autoClean;

  _FateService_executeFateOperation_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_opid(const int64_t val);

  void __set_op(const FateOperation::type val);

  void __set_arguments(const std::vector<std::string> & val);

  void __set_options(const std::map<std::string, std::string> & val);

  void __set_autoClean(const bool val);

  bool operator == (const FateService_executeFateOperation_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(opid == rhs.opid))
      return false;
    if (!(op == rhs.op))
      return false;
    if (!(arguments == rhs.arguments))
      return false;
    if (!(options == rhs.options))
      return false;
    if (!(autoClean == rhs.autoClean))
      return false;
    return true;
  }
  bool operator != (const FateService_executeFateOperation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FateService_executeFateOperation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_executeFateOperation_args& obj);
};


class FateService_executeFateOperation_pargs {
 public:

  static const char* ascii_fingerprint; // = "C5E83F05C192CE192A23C9E51DBD957A";
  static const uint8_t binary_fingerprint[16]; // = {0xC5,0xE8,0x3F,0x05,0xC1,0x92,0xCE,0x19,0x2A,0x23,0xC9,0xE5,0x1D,0xBD,0x95,0x7A};


  virtual ~FateService_executeFateOperation_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const int64_t* opid;
  const FateOperation::type* op;
  const std::vector<std::string> * arguments;
  const std::map<std::string, std::string> * options;
  const bool* autoClean;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_executeFateOperation_pargs& obj);
};

typedef struct _FateService_executeFateOperation_result__isset {
  _FateService_executeFateOperation_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _FateService_executeFateOperation_result__isset;

class FateService_executeFateOperation_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  FateService_executeFateOperation_result(const FateService_executeFateOperation_result&);
  FateService_executeFateOperation_result& operator=(const FateService_executeFateOperation_result&);
  FateService_executeFateOperation_result() {
  }

  virtual ~FateService_executeFateOperation_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _FateService_executeFateOperation_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_tope(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException& val);

  bool operator == (const FateService_executeFateOperation_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const FateService_executeFateOperation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FateService_executeFateOperation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_executeFateOperation_result& obj);
};

typedef struct _FateService_executeFateOperation_presult__isset {
  _FateService_executeFateOperation_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _FateService_executeFateOperation_presult__isset;

class FateService_executeFateOperation_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~FateService_executeFateOperation_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _FateService_executeFateOperation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const FateService_executeFateOperation_presult& obj);
};

typedef struct _FateService_waitForFateOperation_args__isset {
  _FateService_waitForFateOperation_args__isset() : tinfo(false), credentials(false), opid(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool opid :1;
} _FateService_waitForFateOperation_args__isset;

class FateService_waitForFateOperation_args {
 public:

  static const char* ascii_fingerprint; // = "CB154198EF5BD9D1A82E969DE8C6A0C9";
  static const uint8_t binary_fingerprint[16]; // = {0xCB,0x15,0x41,0x98,0xEF,0x5B,0xD9,0xD1,0xA8,0x2E,0x96,0x9D,0xE8,0xC6,0xA0,0xC9};

  FateService_waitForFateOperation_args(const FateService_waitForFateOperation_args&);
  FateService_waitForFateOperation_args& operator=(const FateService_waitForFateOperation_args&);
  FateService_waitForFateOperation_args() : opid(0) {
  }

  virtual ~FateService_waitForFateOperation_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  int64_t opid;

  _FateService_waitForFateOperation_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_opid(const int64_t val);

  bool operator == (const FateService_waitForFateOperation_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(opid == rhs.opid))
      return false;
    return true;
  }
  bool operator != (const FateService_waitForFateOperation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FateService_waitForFateOperation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_waitForFateOperation_args& obj);
};


class FateService_waitForFateOperation_pargs {
 public:

  static const char* ascii_fingerprint; // = "CB154198EF5BD9D1A82E969DE8C6A0C9";
  static const uint8_t binary_fingerprint[16]; // = {0xCB,0x15,0x41,0x98,0xEF,0x5B,0xD9,0xD1,0xA8,0x2E,0x96,0x9D,0xE8,0xC6,0xA0,0xC9};


  virtual ~FateService_waitForFateOperation_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const int64_t* opid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_waitForFateOperation_pargs& obj);
};

typedef struct _FateService_waitForFateOperation_result__isset {
  _FateService_waitForFateOperation_result__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _FateService_waitForFateOperation_result__isset;

class FateService_waitForFateOperation_result {
 public:

  static const char* ascii_fingerprint; // = "9EC05D2EB199D41A437108DCE7DC6C30";
  static const uint8_t binary_fingerprint[16]; // = {0x9E,0xC0,0x5D,0x2E,0xB1,0x99,0xD4,0x1A,0x43,0x71,0x08,0xDC,0xE7,0xDC,0x6C,0x30};

  FateService_waitForFateOperation_result(const FateService_waitForFateOperation_result&);
  FateService_waitForFateOperation_result& operator=(const FateService_waitForFateOperation_result&);
  FateService_waitForFateOperation_result() : success() {
  }

  virtual ~FateService_waitForFateOperation_result() throw();
  std::string success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _FateService_waitForFateOperation_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_tope(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException& val);

  bool operator == (const FateService_waitForFateOperation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const FateService_waitForFateOperation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FateService_waitForFateOperation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_waitForFateOperation_result& obj);
};

typedef struct _FateService_waitForFateOperation_presult__isset {
  _FateService_waitForFateOperation_presult__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _FateService_waitForFateOperation_presult__isset;

class FateService_waitForFateOperation_presult {
 public:

  static const char* ascii_fingerprint; // = "9EC05D2EB199D41A437108DCE7DC6C30";
  static const uint8_t binary_fingerprint[16]; // = {0x9E,0xC0,0x5D,0x2E,0xB1,0x99,0xD4,0x1A,0x43,0x71,0x08,0xDC,0xE7,0xDC,0x6C,0x30};


  virtual ~FateService_waitForFateOperation_presult() throw();
  std::string* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _FateService_waitForFateOperation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const FateService_waitForFateOperation_presult& obj);
};

typedef struct _FateService_finishFateOperation_args__isset {
  _FateService_finishFateOperation_args__isset() : tinfo(false), credentials(false), opid(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool opid :1;
} _FateService_finishFateOperation_args__isset;

class FateService_finishFateOperation_args {
 public:

  static const char* ascii_fingerprint; // = "CB154198EF5BD9D1A82E969DE8C6A0C9";
  static const uint8_t binary_fingerprint[16]; // = {0xCB,0x15,0x41,0x98,0xEF,0x5B,0xD9,0xD1,0xA8,0x2E,0x96,0x9D,0xE8,0xC6,0xA0,0xC9};

  FateService_finishFateOperation_args(const FateService_finishFateOperation_args&);
  FateService_finishFateOperation_args& operator=(const FateService_finishFateOperation_args&);
  FateService_finishFateOperation_args() : opid(0) {
  }

  virtual ~FateService_finishFateOperation_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  int64_t opid;

  _FateService_finishFateOperation_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_opid(const int64_t val);

  bool operator == (const FateService_finishFateOperation_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(opid == rhs.opid))
      return false;
    return true;
  }
  bool operator != (const FateService_finishFateOperation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FateService_finishFateOperation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_finishFateOperation_args& obj);
};


class FateService_finishFateOperation_pargs {
 public:

  static const char* ascii_fingerprint; // = "CB154198EF5BD9D1A82E969DE8C6A0C9";
  static const uint8_t binary_fingerprint[16]; // = {0xCB,0x15,0x41,0x98,0xEF,0x5B,0xD9,0xD1,0xA8,0x2E,0x96,0x9D,0xE8,0xC6,0xA0,0xC9};


  virtual ~FateService_finishFateOperation_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const int64_t* opid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_finishFateOperation_pargs& obj);
};

typedef struct _FateService_finishFateOperation_result__isset {
  _FateService_finishFateOperation_result__isset() : sec(false) {}
  bool sec :1;
} _FateService_finishFateOperation_result__isset;

class FateService_finishFateOperation_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  FateService_finishFateOperation_result(const FateService_finishFateOperation_result&);
  FateService_finishFateOperation_result& operator=(const FateService_finishFateOperation_result&);
  FateService_finishFateOperation_result() {
  }

  virtual ~FateService_finishFateOperation_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _FateService_finishFateOperation_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const FateService_finishFateOperation_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const FateService_finishFateOperation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FateService_finishFateOperation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const FateService_finishFateOperation_result& obj);
};

typedef struct _FateService_finishFateOperation_presult__isset {
  _FateService_finishFateOperation_presult__isset() : sec(false) {}
  bool sec :1;
} _FateService_finishFateOperation_presult__isset;

class FateService_finishFateOperation_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~FateService_finishFateOperation_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _FateService_finishFateOperation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const FateService_finishFateOperation_presult& obj);
};

class FateServiceClient : virtual public FateServiceIf {
 public:
  FateServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  FateServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int64_t beginFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_beginFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  int64_t recv_beginFateOperation();
  void executeFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid, const FateOperation::type op, const std::vector<std::string> & arguments, const std::map<std::string, std::string> & options, const bool autoClean);
  void send_executeFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid, const FateOperation::type op, const std::vector<std::string> & arguments, const std::map<std::string, std::string> & options, const bool autoClean);
  void recv_executeFateOperation();
  void waitForFateOperation(std::string& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid);
  void send_waitForFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid);
  void recv_waitForFateOperation(std::string& _return);
  void finishFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid);
  void send_finishFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid);
  void recv_finishFateOperation();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class FateServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<FateServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (FateServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_beginFateOperation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_executeFateOperation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_waitForFateOperation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_finishFateOperation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  FateServiceProcessor(boost::shared_ptr<FateServiceIf> iface) :
    iface_(iface) {
    processMap_["beginFateOperation"] = &FateServiceProcessor::process_beginFateOperation;
    processMap_["executeFateOperation"] = &FateServiceProcessor::process_executeFateOperation;
    processMap_["waitForFateOperation"] = &FateServiceProcessor::process_waitForFateOperation;
    processMap_["finishFateOperation"] = &FateServiceProcessor::process_finishFateOperation;
  }

  virtual ~FateServiceProcessor() {}
};

class FateServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  FateServiceProcessorFactory(const ::boost::shared_ptr< FateServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< FateServiceIfFactory > handlerFactory_;
};

class FateServiceMultiface : virtual public FateServiceIf {
 public:
  FateServiceMultiface(std::vector<boost::shared_ptr<FateServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~FateServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<FateServiceIf> > ifaces_;
  FateServiceMultiface() {}
  void add(boost::shared_ptr<FateServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int64_t beginFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->beginFateOperation(tinfo, credentials);
    }
    return ifaces_[i]->beginFateOperation(tinfo, credentials);
  }

  void executeFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid, const FateOperation::type op, const std::vector<std::string> & arguments, const std::map<std::string, std::string> & options, const bool autoClean) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->executeFateOperation(tinfo, credentials, opid, op, arguments, options, autoClean);
    }
    ifaces_[i]->executeFateOperation(tinfo, credentials, opid, op, arguments, options, autoClean);
  }

  void waitForFateOperation(std::string& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->waitForFateOperation(_return, tinfo, credentials, opid);
    }
    ifaces_[i]->waitForFateOperation(_return, tinfo, credentials, opid);
    return;
  }

  void finishFateOperation(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t opid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->finishFateOperation(tinfo, credentials, opid);
    }
    ifaces_[i]->finishFateOperation(tinfo, credentials, opid);
  }

};

}}}}}} // namespace

#endif
