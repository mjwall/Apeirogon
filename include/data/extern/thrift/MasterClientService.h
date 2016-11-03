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
#ifndef MasterClientService_H
#define MasterClientService_H

#include <thrift/TDispatchProcessor.h>
#include "master_types.h"
#include "FateService.h"

namespace org { namespace apache { namespace accumulo { namespace core { namespace master { namespace thrift {

class MasterClientServiceIf : virtual public FateServiceIf {
 public:
  virtual ~MasterClientServiceIf() {}
  virtual int64_t initiateFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName) = 0;
  virtual void waitForFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& startRow, const std::string& endRow, const int64_t flushID, const int64_t maxLoops) = 0;
  virtual void setTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& property, const std::string& value) = 0;
  virtual void removeTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& property) = 0;
  virtual void setNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns, const std::string& property, const std::string& value) = 0;
  virtual void removeNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns, const std::string& property) = 0;
  virtual void setMasterGoalState(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const MasterGoalState::type state) = 0;
  virtual void shutdown(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const bool stopTabletServers) = 0;
  virtual void shutdownTabletServer(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tabletServer, const bool force) = 0;
  virtual void setSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& property, const std::string& value) = 0;
  virtual void removeSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& property) = 0;
  virtual void getMasterStats(MasterMonitorInfo& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void reportSplitExtent(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& serverName, const TabletSplit& split) = 0;
  virtual void reportTabletStatus(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& serverName, const TabletLoadState::type status, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& tablet) = 0;
};

class MasterClientServiceIfFactory : virtual public FateServiceIfFactory {
 public:
  typedef MasterClientServiceIf Handler;

  virtual ~MasterClientServiceIfFactory() {}

  virtual MasterClientServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(FateServiceIf* /* handler */) = 0;
};

class MasterClientServiceIfSingletonFactory : virtual public MasterClientServiceIfFactory {
 public:
  MasterClientServiceIfSingletonFactory(const boost::shared_ptr<MasterClientServiceIf>& iface) : iface_(iface) {}
  virtual ~MasterClientServiceIfSingletonFactory() {}

  virtual MasterClientServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(FateServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<MasterClientServiceIf> iface_;
};

class MasterClientServiceNull : virtual public MasterClientServiceIf , virtual public FateServiceNull {
 public:
  virtual ~MasterClientServiceNull() {}
  int64_t initiateFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* tableName */) {
    int64_t _return = 0;
    return _return;
  }
  void waitForFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* tableName */, const std::string& /* startRow */, const std::string& /* endRow */, const int64_t /* flushID */, const int64_t /* maxLoops */) {
    return;
  }
  void setTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* tableName */, const std::string& /* property */, const std::string& /* value */) {
    return;
  }
  void removeTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* tableName */, const std::string& /* property */) {
    return;
  }
  void setNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* ns */, const std::string& /* property */, const std::string& /* value */) {
    return;
  }
  void removeNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* ns */, const std::string& /* property */) {
    return;
  }
  void setMasterGoalState(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const MasterGoalState::type /* state */) {
    return;
  }
  void shutdown(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const bool /* stopTabletServers */) {
    return;
  }
  void shutdownTabletServer(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* tabletServer */, const bool /* force */) {
    return;
  }
  void setSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* property */, const std::string& /* value */) {
    return;
  }
  void removeSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* property */) {
    return;
  }
  void getMasterStats(MasterMonitorInfo& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    return;
  }
  void reportSplitExtent(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* serverName */, const TabletSplit& /* split */) {
    return;
  }
  void reportTabletStatus(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* serverName */, const TabletLoadState::type /* status */, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& /* tablet */) {
    return;
  }
};

typedef struct _MasterClientService_initiateFlush_args__isset {
  _MasterClientService_initiateFlush_args__isset() : tinfo(false), credentials(false), tableName(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tableName :1;
} _MasterClientService_initiateFlush_args__isset;

class MasterClientService_initiateFlush_args {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};

  MasterClientService_initiateFlush_args(const MasterClientService_initiateFlush_args&);
  MasterClientService_initiateFlush_args& operator=(const MasterClientService_initiateFlush_args&);
  MasterClientService_initiateFlush_args() : tableName() {
  }

  virtual ~MasterClientService_initiateFlush_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string tableName;

  _MasterClientService_initiateFlush_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tableName(const std::string& val);

  bool operator == (const MasterClientService_initiateFlush_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_initiateFlush_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_initiateFlush_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_initiateFlush_args& obj);
};


class MasterClientService_initiateFlush_pargs {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};


  virtual ~MasterClientService_initiateFlush_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* tableName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_initiateFlush_pargs& obj);
};

typedef struct _MasterClientService_initiateFlush_result__isset {
  _MasterClientService_initiateFlush_result__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _MasterClientService_initiateFlush_result__isset;

class MasterClientService_initiateFlush_result {
 public:

  static const char* ascii_fingerprint; // = "CF521E6BC70B8F0659835F64408D5A55";
  static const uint8_t binary_fingerprint[16]; // = {0xCF,0x52,0x1E,0x6B,0xC7,0x0B,0x8F,0x06,0x59,0x83,0x5F,0x64,0x40,0x8D,0x5A,0x55};

  MasterClientService_initiateFlush_result(const MasterClientService_initiateFlush_result&);
  MasterClientService_initiateFlush_result& operator=(const MasterClientService_initiateFlush_result&);
  MasterClientService_initiateFlush_result() : success(0) {
  }

  virtual ~MasterClientService_initiateFlush_result() throw();
  int64_t success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_initiateFlush_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_tope(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException& val);

  bool operator == (const MasterClientService_initiateFlush_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_initiateFlush_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_initiateFlush_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_initiateFlush_result& obj);
};

typedef struct _MasterClientService_initiateFlush_presult__isset {
  _MasterClientService_initiateFlush_presult__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _MasterClientService_initiateFlush_presult__isset;

class MasterClientService_initiateFlush_presult {
 public:

  static const char* ascii_fingerprint; // = "CF521E6BC70B8F0659835F64408D5A55";
  static const uint8_t binary_fingerprint[16]; // = {0xCF,0x52,0x1E,0x6B,0xC7,0x0B,0x8F,0x06,0x59,0x83,0x5F,0x64,0x40,0x8D,0x5A,0x55};


  virtual ~MasterClientService_initiateFlush_presult() throw();
  int64_t* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_initiateFlush_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_initiateFlush_presult& obj);
};

typedef struct _MasterClientService_waitForFlush_args__isset {
  _MasterClientService_waitForFlush_args__isset() : tinfo(false), credentials(false), tableName(false), startRow(false), endRow(false), flushID(false), maxLoops(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tableName :1;
  bool startRow :1;
  bool endRow :1;
  bool flushID :1;
  bool maxLoops :1;
} _MasterClientService_waitForFlush_args__isset;

class MasterClientService_waitForFlush_args {
 public:

  static const char* ascii_fingerprint; // = "956F6826A87169936AF35805E489A6F6";
  static const uint8_t binary_fingerprint[16]; // = {0x95,0x6F,0x68,0x26,0xA8,0x71,0x69,0x93,0x6A,0xF3,0x58,0x05,0xE4,0x89,0xA6,0xF6};

  MasterClientService_waitForFlush_args(const MasterClientService_waitForFlush_args&);
  MasterClientService_waitForFlush_args& operator=(const MasterClientService_waitForFlush_args&);
  MasterClientService_waitForFlush_args() : tableName(), startRow(), endRow(), flushID(0), maxLoops(0) {
  }

  virtual ~MasterClientService_waitForFlush_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string tableName;
  std::string startRow;
  std::string endRow;
  int64_t flushID;
  int64_t maxLoops;

  _MasterClientService_waitForFlush_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tableName(const std::string& val);

  void __set_startRow(const std::string& val);

  void __set_endRow(const std::string& val);

  void __set_flushID(const int64_t val);

  void __set_maxLoops(const int64_t val);

  bool operator == (const MasterClientService_waitForFlush_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    if (!(startRow == rhs.startRow))
      return false;
    if (!(endRow == rhs.endRow))
      return false;
    if (!(flushID == rhs.flushID))
      return false;
    if (!(maxLoops == rhs.maxLoops))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_waitForFlush_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_waitForFlush_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_waitForFlush_args& obj);
};


class MasterClientService_waitForFlush_pargs {
 public:

  static const char* ascii_fingerprint; // = "956F6826A87169936AF35805E489A6F6";
  static const uint8_t binary_fingerprint[16]; // = {0x95,0x6F,0x68,0x26,0xA8,0x71,0x69,0x93,0x6A,0xF3,0x58,0x05,0xE4,0x89,0xA6,0xF6};


  virtual ~MasterClientService_waitForFlush_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* tableName;
  const std::string* startRow;
  const std::string* endRow;
  const int64_t* flushID;
  const int64_t* maxLoops;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_waitForFlush_pargs& obj);
};

typedef struct _MasterClientService_waitForFlush_result__isset {
  _MasterClientService_waitForFlush_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_waitForFlush_result__isset;

class MasterClientService_waitForFlush_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  MasterClientService_waitForFlush_result(const MasterClientService_waitForFlush_result&);
  MasterClientService_waitForFlush_result& operator=(const MasterClientService_waitForFlush_result&);
  MasterClientService_waitForFlush_result() {
  }

  virtual ~MasterClientService_waitForFlush_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_waitForFlush_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_tope(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException& val);

  bool operator == (const MasterClientService_waitForFlush_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_waitForFlush_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_waitForFlush_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_waitForFlush_result& obj);
};

typedef struct _MasterClientService_waitForFlush_presult__isset {
  _MasterClientService_waitForFlush_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_waitForFlush_presult__isset;

class MasterClientService_waitForFlush_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~MasterClientService_waitForFlush_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_waitForFlush_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_waitForFlush_presult& obj);
};

typedef struct _MasterClientService_setTableProperty_args__isset {
  _MasterClientService_setTableProperty_args__isset() : tinfo(false), credentials(false), tableName(false), property(false), value(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tableName :1;
  bool property :1;
  bool value :1;
} _MasterClientService_setTableProperty_args__isset;

class MasterClientService_setTableProperty_args {
 public:

  static const char* ascii_fingerprint; // = "71818B86258E7C92B04CBD7B8CCDADB8";
  static const uint8_t binary_fingerprint[16]; // = {0x71,0x81,0x8B,0x86,0x25,0x8E,0x7C,0x92,0xB0,0x4C,0xBD,0x7B,0x8C,0xCD,0xAD,0xB8};

  MasterClientService_setTableProperty_args(const MasterClientService_setTableProperty_args&);
  MasterClientService_setTableProperty_args& operator=(const MasterClientService_setTableProperty_args&);
  MasterClientService_setTableProperty_args() : tableName(), property(), value() {
  }

  virtual ~MasterClientService_setTableProperty_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string tableName;
  std::string property;
  std::string value;

  _MasterClientService_setTableProperty_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tableName(const std::string& val);

  void __set_property(const std::string& val);

  void __set_value(const std::string& val);

  bool operator == (const MasterClientService_setTableProperty_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    if (!(property == rhs.property))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_setTableProperty_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_setTableProperty_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setTableProperty_args& obj);
};


class MasterClientService_setTableProperty_pargs {
 public:

  static const char* ascii_fingerprint; // = "71818B86258E7C92B04CBD7B8CCDADB8";
  static const uint8_t binary_fingerprint[16]; // = {0x71,0x81,0x8B,0x86,0x25,0x8E,0x7C,0x92,0xB0,0x4C,0xBD,0x7B,0x8C,0xCD,0xAD,0xB8};


  virtual ~MasterClientService_setTableProperty_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* tableName;
  const std::string* property;
  const std::string* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setTableProperty_pargs& obj);
};

typedef struct _MasterClientService_setTableProperty_result__isset {
  _MasterClientService_setTableProperty_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_setTableProperty_result__isset;

class MasterClientService_setTableProperty_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  MasterClientService_setTableProperty_result(const MasterClientService_setTableProperty_result&);
  MasterClientService_setTableProperty_result& operator=(const MasterClientService_setTableProperty_result&);
  MasterClientService_setTableProperty_result() {
  }

  virtual ~MasterClientService_setTableProperty_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_setTableProperty_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_tope(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException& val);

  bool operator == (const MasterClientService_setTableProperty_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_setTableProperty_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_setTableProperty_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setTableProperty_result& obj);
};

typedef struct _MasterClientService_setTableProperty_presult__isset {
  _MasterClientService_setTableProperty_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_setTableProperty_presult__isset;

class MasterClientService_setTableProperty_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~MasterClientService_setTableProperty_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_setTableProperty_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setTableProperty_presult& obj);
};

typedef struct _MasterClientService_removeTableProperty_args__isset {
  _MasterClientService_removeTableProperty_args__isset() : tinfo(false), credentials(false), tableName(false), property(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tableName :1;
  bool property :1;
} _MasterClientService_removeTableProperty_args__isset;

class MasterClientService_removeTableProperty_args {
 public:

  static const char* ascii_fingerprint; // = "82C9424B26344B1CF04C9CE4CC4B25FB";
  static const uint8_t binary_fingerprint[16]; // = {0x82,0xC9,0x42,0x4B,0x26,0x34,0x4B,0x1C,0xF0,0x4C,0x9C,0xE4,0xCC,0x4B,0x25,0xFB};

  MasterClientService_removeTableProperty_args(const MasterClientService_removeTableProperty_args&);
  MasterClientService_removeTableProperty_args& operator=(const MasterClientService_removeTableProperty_args&);
  MasterClientService_removeTableProperty_args() : tableName(), property() {
  }

  virtual ~MasterClientService_removeTableProperty_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string tableName;
  std::string property;

  _MasterClientService_removeTableProperty_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tableName(const std::string& val);

  void __set_property(const std::string& val);

  bool operator == (const MasterClientService_removeTableProperty_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    if (!(property == rhs.property))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_removeTableProperty_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_removeTableProperty_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeTableProperty_args& obj);
};


class MasterClientService_removeTableProperty_pargs {
 public:

  static const char* ascii_fingerprint; // = "82C9424B26344B1CF04C9CE4CC4B25FB";
  static const uint8_t binary_fingerprint[16]; // = {0x82,0xC9,0x42,0x4B,0x26,0x34,0x4B,0x1C,0xF0,0x4C,0x9C,0xE4,0xCC,0x4B,0x25,0xFB};


  virtual ~MasterClientService_removeTableProperty_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* tableName;
  const std::string* property;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeTableProperty_pargs& obj);
};

typedef struct _MasterClientService_removeTableProperty_result__isset {
  _MasterClientService_removeTableProperty_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_removeTableProperty_result__isset;

class MasterClientService_removeTableProperty_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  MasterClientService_removeTableProperty_result(const MasterClientService_removeTableProperty_result&);
  MasterClientService_removeTableProperty_result& operator=(const MasterClientService_removeTableProperty_result&);
  MasterClientService_removeTableProperty_result() {
  }

  virtual ~MasterClientService_removeTableProperty_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_removeTableProperty_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_tope(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException& val);

  bool operator == (const MasterClientService_removeTableProperty_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_removeTableProperty_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_removeTableProperty_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeTableProperty_result& obj);
};

typedef struct _MasterClientService_removeTableProperty_presult__isset {
  _MasterClientService_removeTableProperty_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_removeTableProperty_presult__isset;

class MasterClientService_removeTableProperty_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~MasterClientService_removeTableProperty_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_removeTableProperty_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeTableProperty_presult& obj);
};

typedef struct _MasterClientService_setNamespaceProperty_args__isset {
  _MasterClientService_setNamespaceProperty_args__isset() : tinfo(false), credentials(false), ns(false), property(false), value(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool ns :1;
  bool property :1;
  bool value :1;
} _MasterClientService_setNamespaceProperty_args__isset;

class MasterClientService_setNamespaceProperty_args {
 public:

  static const char* ascii_fingerprint; // = "71818B86258E7C92B04CBD7B8CCDADB8";
  static const uint8_t binary_fingerprint[16]; // = {0x71,0x81,0x8B,0x86,0x25,0x8E,0x7C,0x92,0xB0,0x4C,0xBD,0x7B,0x8C,0xCD,0xAD,0xB8};

  MasterClientService_setNamespaceProperty_args(const MasterClientService_setNamespaceProperty_args&);
  MasterClientService_setNamespaceProperty_args& operator=(const MasterClientService_setNamespaceProperty_args&);
  MasterClientService_setNamespaceProperty_args() : ns(), property(), value() {
  }

  virtual ~MasterClientService_setNamespaceProperty_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string ns;
  std::string property;
  std::string value;

  _MasterClientService_setNamespaceProperty_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_ns(const std::string& val);

  void __set_property(const std::string& val);

  void __set_value(const std::string& val);

  bool operator == (const MasterClientService_setNamespaceProperty_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(ns == rhs.ns))
      return false;
    if (!(property == rhs.property))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_setNamespaceProperty_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_setNamespaceProperty_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setNamespaceProperty_args& obj);
};


class MasterClientService_setNamespaceProperty_pargs {
 public:

  static const char* ascii_fingerprint; // = "71818B86258E7C92B04CBD7B8CCDADB8";
  static const uint8_t binary_fingerprint[16]; // = {0x71,0x81,0x8B,0x86,0x25,0x8E,0x7C,0x92,0xB0,0x4C,0xBD,0x7B,0x8C,0xCD,0xAD,0xB8};


  virtual ~MasterClientService_setNamespaceProperty_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* ns;
  const std::string* property;
  const std::string* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setNamespaceProperty_pargs& obj);
};

typedef struct _MasterClientService_setNamespaceProperty_result__isset {
  _MasterClientService_setNamespaceProperty_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_setNamespaceProperty_result__isset;

class MasterClientService_setNamespaceProperty_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  MasterClientService_setNamespaceProperty_result(const MasterClientService_setNamespaceProperty_result&);
  MasterClientService_setNamespaceProperty_result& operator=(const MasterClientService_setNamespaceProperty_result&);
  MasterClientService_setNamespaceProperty_result() {
  }

  virtual ~MasterClientService_setNamespaceProperty_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_setNamespaceProperty_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_tope(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException& val);

  bool operator == (const MasterClientService_setNamespaceProperty_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_setNamespaceProperty_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_setNamespaceProperty_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setNamespaceProperty_result& obj);
};

typedef struct _MasterClientService_setNamespaceProperty_presult__isset {
  _MasterClientService_setNamespaceProperty_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_setNamespaceProperty_presult__isset;

class MasterClientService_setNamespaceProperty_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~MasterClientService_setNamespaceProperty_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_setNamespaceProperty_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setNamespaceProperty_presult& obj);
};

typedef struct _MasterClientService_removeNamespaceProperty_args__isset {
  _MasterClientService_removeNamespaceProperty_args__isset() : tinfo(false), credentials(false), ns(false), property(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool ns :1;
  bool property :1;
} _MasterClientService_removeNamespaceProperty_args__isset;

class MasterClientService_removeNamespaceProperty_args {
 public:

  static const char* ascii_fingerprint; // = "82C9424B26344B1CF04C9CE4CC4B25FB";
  static const uint8_t binary_fingerprint[16]; // = {0x82,0xC9,0x42,0x4B,0x26,0x34,0x4B,0x1C,0xF0,0x4C,0x9C,0xE4,0xCC,0x4B,0x25,0xFB};

  MasterClientService_removeNamespaceProperty_args(const MasterClientService_removeNamespaceProperty_args&);
  MasterClientService_removeNamespaceProperty_args& operator=(const MasterClientService_removeNamespaceProperty_args&);
  MasterClientService_removeNamespaceProperty_args() : ns(), property() {
  }

  virtual ~MasterClientService_removeNamespaceProperty_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string ns;
  std::string property;

  _MasterClientService_removeNamespaceProperty_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_ns(const std::string& val);

  void __set_property(const std::string& val);

  bool operator == (const MasterClientService_removeNamespaceProperty_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(ns == rhs.ns))
      return false;
    if (!(property == rhs.property))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_removeNamespaceProperty_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_removeNamespaceProperty_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeNamespaceProperty_args& obj);
};


class MasterClientService_removeNamespaceProperty_pargs {
 public:

  static const char* ascii_fingerprint; // = "82C9424B26344B1CF04C9CE4CC4B25FB";
  static const uint8_t binary_fingerprint[16]; // = {0x82,0xC9,0x42,0x4B,0x26,0x34,0x4B,0x1C,0xF0,0x4C,0x9C,0xE4,0xCC,0x4B,0x25,0xFB};


  virtual ~MasterClientService_removeNamespaceProperty_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* ns;
  const std::string* property;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeNamespaceProperty_pargs& obj);
};

typedef struct _MasterClientService_removeNamespaceProperty_result__isset {
  _MasterClientService_removeNamespaceProperty_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_removeNamespaceProperty_result__isset;

class MasterClientService_removeNamespaceProperty_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  MasterClientService_removeNamespaceProperty_result(const MasterClientService_removeNamespaceProperty_result&);
  MasterClientService_removeNamespaceProperty_result& operator=(const MasterClientService_removeNamespaceProperty_result&);
  MasterClientService_removeNamespaceProperty_result() {
  }

  virtual ~MasterClientService_removeNamespaceProperty_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_removeNamespaceProperty_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_tope(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException& val);

  bool operator == (const MasterClientService_removeNamespaceProperty_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_removeNamespaceProperty_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_removeNamespaceProperty_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeNamespaceProperty_result& obj);
};

typedef struct _MasterClientService_removeNamespaceProperty_presult__isset {
  _MasterClientService_removeNamespaceProperty_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _MasterClientService_removeNamespaceProperty_presult__isset;

class MasterClientService_removeNamespaceProperty_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~MasterClientService_removeNamespaceProperty_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftTableOperationException tope;

  _MasterClientService_removeNamespaceProperty_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeNamespaceProperty_presult& obj);
};

typedef struct _MasterClientService_setMasterGoalState_args__isset {
  _MasterClientService_setMasterGoalState_args__isset() : tinfo(false), credentials(false), state(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool state :1;
} _MasterClientService_setMasterGoalState_args__isset;

class MasterClientService_setMasterGoalState_args {
 public:

  static const char* ascii_fingerprint; // = "300F6C0EDC2EAA93985E1C90600C8812";
  static const uint8_t binary_fingerprint[16]; // = {0x30,0x0F,0x6C,0x0E,0xDC,0x2E,0xAA,0x93,0x98,0x5E,0x1C,0x90,0x60,0x0C,0x88,0x12};

  MasterClientService_setMasterGoalState_args(const MasterClientService_setMasterGoalState_args&);
  MasterClientService_setMasterGoalState_args& operator=(const MasterClientService_setMasterGoalState_args&);
  MasterClientService_setMasterGoalState_args() : state((MasterGoalState::type)0) {
  }

  virtual ~MasterClientService_setMasterGoalState_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  MasterGoalState::type state;

  _MasterClientService_setMasterGoalState_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_state(const MasterGoalState::type val);

  bool operator == (const MasterClientService_setMasterGoalState_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(state == rhs.state))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_setMasterGoalState_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_setMasterGoalState_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setMasterGoalState_args& obj);
};


class MasterClientService_setMasterGoalState_pargs {
 public:

  static const char* ascii_fingerprint; // = "300F6C0EDC2EAA93985E1C90600C8812";
  static const uint8_t binary_fingerprint[16]; // = {0x30,0x0F,0x6C,0x0E,0xDC,0x2E,0xAA,0x93,0x98,0x5E,0x1C,0x90,0x60,0x0C,0x88,0x12};


  virtual ~MasterClientService_setMasterGoalState_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const MasterGoalState::type* state;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setMasterGoalState_pargs& obj);
};

typedef struct _MasterClientService_setMasterGoalState_result__isset {
  _MasterClientService_setMasterGoalState_result__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_setMasterGoalState_result__isset;

class MasterClientService_setMasterGoalState_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  MasterClientService_setMasterGoalState_result(const MasterClientService_setMasterGoalState_result&);
  MasterClientService_setMasterGoalState_result& operator=(const MasterClientService_setMasterGoalState_result&);
  MasterClientService_setMasterGoalState_result() {
  }

  virtual ~MasterClientService_setMasterGoalState_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_setMasterGoalState_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const MasterClientService_setMasterGoalState_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_setMasterGoalState_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_setMasterGoalState_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setMasterGoalState_result& obj);
};

typedef struct _MasterClientService_setMasterGoalState_presult__isset {
  _MasterClientService_setMasterGoalState_presult__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_setMasterGoalState_presult__isset;

class MasterClientService_setMasterGoalState_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~MasterClientService_setMasterGoalState_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_setMasterGoalState_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setMasterGoalState_presult& obj);
};

typedef struct _MasterClientService_shutdown_args__isset {
  _MasterClientService_shutdown_args__isset() : tinfo(false), credentials(false), stopTabletServers(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool stopTabletServers :1;
} _MasterClientService_shutdown_args__isset;

class MasterClientService_shutdown_args {
 public:

  static const char* ascii_fingerprint; // = "8B608B6568E00E2E773DCA6B90206416";
  static const uint8_t binary_fingerprint[16]; // = {0x8B,0x60,0x8B,0x65,0x68,0xE0,0x0E,0x2E,0x77,0x3D,0xCA,0x6B,0x90,0x20,0x64,0x16};

  MasterClientService_shutdown_args(const MasterClientService_shutdown_args&);
  MasterClientService_shutdown_args& operator=(const MasterClientService_shutdown_args&);
  MasterClientService_shutdown_args() : stopTabletServers(0) {
  }

  virtual ~MasterClientService_shutdown_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  bool stopTabletServers;

  _MasterClientService_shutdown_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_stopTabletServers(const bool val);

  bool operator == (const MasterClientService_shutdown_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(stopTabletServers == rhs.stopTabletServers))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_shutdown_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_shutdown_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_shutdown_args& obj);
};


class MasterClientService_shutdown_pargs {
 public:

  static const char* ascii_fingerprint; // = "8B608B6568E00E2E773DCA6B90206416";
  static const uint8_t binary_fingerprint[16]; // = {0x8B,0x60,0x8B,0x65,0x68,0xE0,0x0E,0x2E,0x77,0x3D,0xCA,0x6B,0x90,0x20,0x64,0x16};


  virtual ~MasterClientService_shutdown_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const bool* stopTabletServers;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_shutdown_pargs& obj);
};

typedef struct _MasterClientService_shutdown_result__isset {
  _MasterClientService_shutdown_result__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_shutdown_result__isset;

class MasterClientService_shutdown_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  MasterClientService_shutdown_result(const MasterClientService_shutdown_result&);
  MasterClientService_shutdown_result& operator=(const MasterClientService_shutdown_result&);
  MasterClientService_shutdown_result() {
  }

  virtual ~MasterClientService_shutdown_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_shutdown_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const MasterClientService_shutdown_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_shutdown_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_shutdown_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_shutdown_result& obj);
};

typedef struct _MasterClientService_shutdown_presult__isset {
  _MasterClientService_shutdown_presult__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_shutdown_presult__isset;

class MasterClientService_shutdown_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~MasterClientService_shutdown_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_shutdown_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_shutdown_presult& obj);
};

typedef struct _MasterClientService_shutdownTabletServer_args__isset {
  _MasterClientService_shutdownTabletServer_args__isset() : tinfo(false), credentials(false), tabletServer(false), force(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tabletServer :1;
  bool force :1;
} _MasterClientService_shutdownTabletServer_args__isset;

class MasterClientService_shutdownTabletServer_args {
 public:

  static const char* ascii_fingerprint; // = "B353174E0D87552EBDBAC73E7103D52D";
  static const uint8_t binary_fingerprint[16]; // = {0xB3,0x53,0x17,0x4E,0x0D,0x87,0x55,0x2E,0xBD,0xBA,0xC7,0x3E,0x71,0x03,0xD5,0x2D};

  MasterClientService_shutdownTabletServer_args(const MasterClientService_shutdownTabletServer_args&);
  MasterClientService_shutdownTabletServer_args& operator=(const MasterClientService_shutdownTabletServer_args&);
  MasterClientService_shutdownTabletServer_args() : tabletServer(), force(0) {
  }

  virtual ~MasterClientService_shutdownTabletServer_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string tabletServer;
  bool force;

  _MasterClientService_shutdownTabletServer_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tabletServer(const std::string& val);

  void __set_force(const bool val);

  bool operator == (const MasterClientService_shutdownTabletServer_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tabletServer == rhs.tabletServer))
      return false;
    if (!(force == rhs.force))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_shutdownTabletServer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_shutdownTabletServer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_shutdownTabletServer_args& obj);
};


class MasterClientService_shutdownTabletServer_pargs {
 public:

  static const char* ascii_fingerprint; // = "B353174E0D87552EBDBAC73E7103D52D";
  static const uint8_t binary_fingerprint[16]; // = {0xB3,0x53,0x17,0x4E,0x0D,0x87,0x55,0x2E,0xBD,0xBA,0xC7,0x3E,0x71,0x03,0xD5,0x2D};


  virtual ~MasterClientService_shutdownTabletServer_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* tabletServer;
  const bool* force;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_shutdownTabletServer_pargs& obj);
};

typedef struct _MasterClientService_shutdownTabletServer_result__isset {
  _MasterClientService_shutdownTabletServer_result__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_shutdownTabletServer_result__isset;

class MasterClientService_shutdownTabletServer_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  MasterClientService_shutdownTabletServer_result(const MasterClientService_shutdownTabletServer_result&);
  MasterClientService_shutdownTabletServer_result& operator=(const MasterClientService_shutdownTabletServer_result&);
  MasterClientService_shutdownTabletServer_result() {
  }

  virtual ~MasterClientService_shutdownTabletServer_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_shutdownTabletServer_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const MasterClientService_shutdownTabletServer_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_shutdownTabletServer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_shutdownTabletServer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_shutdownTabletServer_result& obj);
};

typedef struct _MasterClientService_shutdownTabletServer_presult__isset {
  _MasterClientService_shutdownTabletServer_presult__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_shutdownTabletServer_presult__isset;

class MasterClientService_shutdownTabletServer_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~MasterClientService_shutdownTabletServer_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_shutdownTabletServer_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_shutdownTabletServer_presult& obj);
};

typedef struct _MasterClientService_setSystemProperty_args__isset {
  _MasterClientService_setSystemProperty_args__isset() : tinfo(false), credentials(false), property(false), value(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool property :1;
  bool value :1;
} _MasterClientService_setSystemProperty_args__isset;

class MasterClientService_setSystemProperty_args {
 public:

  static const char* ascii_fingerprint; // = "82C9424B26344B1CF04C9CE4CC4B25FB";
  static const uint8_t binary_fingerprint[16]; // = {0x82,0xC9,0x42,0x4B,0x26,0x34,0x4B,0x1C,0xF0,0x4C,0x9C,0xE4,0xCC,0x4B,0x25,0xFB};

  MasterClientService_setSystemProperty_args(const MasterClientService_setSystemProperty_args&);
  MasterClientService_setSystemProperty_args& operator=(const MasterClientService_setSystemProperty_args&);
  MasterClientService_setSystemProperty_args() : property(), value() {
  }

  virtual ~MasterClientService_setSystemProperty_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string property;
  std::string value;

  _MasterClientService_setSystemProperty_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_property(const std::string& val);

  void __set_value(const std::string& val);

  bool operator == (const MasterClientService_setSystemProperty_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(property == rhs.property))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_setSystemProperty_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_setSystemProperty_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setSystemProperty_args& obj);
};


class MasterClientService_setSystemProperty_pargs {
 public:

  static const char* ascii_fingerprint; // = "82C9424B26344B1CF04C9CE4CC4B25FB";
  static const uint8_t binary_fingerprint[16]; // = {0x82,0xC9,0x42,0x4B,0x26,0x34,0x4B,0x1C,0xF0,0x4C,0x9C,0xE4,0xCC,0x4B,0x25,0xFB};


  virtual ~MasterClientService_setSystemProperty_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* property;
  const std::string* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setSystemProperty_pargs& obj);
};

typedef struct _MasterClientService_setSystemProperty_result__isset {
  _MasterClientService_setSystemProperty_result__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_setSystemProperty_result__isset;

class MasterClientService_setSystemProperty_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  MasterClientService_setSystemProperty_result(const MasterClientService_setSystemProperty_result&);
  MasterClientService_setSystemProperty_result& operator=(const MasterClientService_setSystemProperty_result&);
  MasterClientService_setSystemProperty_result() {
  }

  virtual ~MasterClientService_setSystemProperty_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_setSystemProperty_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const MasterClientService_setSystemProperty_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_setSystemProperty_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_setSystemProperty_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setSystemProperty_result& obj);
};

typedef struct _MasterClientService_setSystemProperty_presult__isset {
  _MasterClientService_setSystemProperty_presult__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_setSystemProperty_presult__isset;

class MasterClientService_setSystemProperty_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~MasterClientService_setSystemProperty_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_setSystemProperty_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_setSystemProperty_presult& obj);
};

typedef struct _MasterClientService_removeSystemProperty_args__isset {
  _MasterClientService_removeSystemProperty_args__isset() : tinfo(false), credentials(false), property(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool property :1;
} _MasterClientService_removeSystemProperty_args__isset;

class MasterClientService_removeSystemProperty_args {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};

  MasterClientService_removeSystemProperty_args(const MasterClientService_removeSystemProperty_args&);
  MasterClientService_removeSystemProperty_args& operator=(const MasterClientService_removeSystemProperty_args&);
  MasterClientService_removeSystemProperty_args() : property() {
  }

  virtual ~MasterClientService_removeSystemProperty_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string property;

  _MasterClientService_removeSystemProperty_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_property(const std::string& val);

  bool operator == (const MasterClientService_removeSystemProperty_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(property == rhs.property))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_removeSystemProperty_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_removeSystemProperty_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeSystemProperty_args& obj);
};


class MasterClientService_removeSystemProperty_pargs {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};


  virtual ~MasterClientService_removeSystemProperty_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* property;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeSystemProperty_pargs& obj);
};

typedef struct _MasterClientService_removeSystemProperty_result__isset {
  _MasterClientService_removeSystemProperty_result__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_removeSystemProperty_result__isset;

class MasterClientService_removeSystemProperty_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  MasterClientService_removeSystemProperty_result(const MasterClientService_removeSystemProperty_result&);
  MasterClientService_removeSystemProperty_result& operator=(const MasterClientService_removeSystemProperty_result&);
  MasterClientService_removeSystemProperty_result() {
  }

  virtual ~MasterClientService_removeSystemProperty_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_removeSystemProperty_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const MasterClientService_removeSystemProperty_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_removeSystemProperty_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_removeSystemProperty_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeSystemProperty_result& obj);
};

typedef struct _MasterClientService_removeSystemProperty_presult__isset {
  _MasterClientService_removeSystemProperty_presult__isset() : sec(false) {}
  bool sec :1;
} _MasterClientService_removeSystemProperty_presult__isset;

class MasterClientService_removeSystemProperty_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~MasterClientService_removeSystemProperty_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_removeSystemProperty_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_removeSystemProperty_presult& obj);
};

typedef struct _MasterClientService_getMasterStats_args__isset {
  _MasterClientService_getMasterStats_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _MasterClientService_getMasterStats_args__isset;

class MasterClientService_getMasterStats_args {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};

  MasterClientService_getMasterStats_args(const MasterClientService_getMasterStats_args&);
  MasterClientService_getMasterStats_args& operator=(const MasterClientService_getMasterStats_args&);
  MasterClientService_getMasterStats_args() {
  }

  virtual ~MasterClientService_getMasterStats_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _MasterClientService_getMasterStats_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const MasterClientService_getMasterStats_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_getMasterStats_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_getMasterStats_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_getMasterStats_args& obj);
};


class MasterClientService_getMasterStats_pargs {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};


  virtual ~MasterClientService_getMasterStats_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_getMasterStats_pargs& obj);
};

typedef struct _MasterClientService_getMasterStats_result__isset {
  _MasterClientService_getMasterStats_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _MasterClientService_getMasterStats_result__isset;

class MasterClientService_getMasterStats_result {
 public:

  static const char* ascii_fingerprint; // = "38261913D0A8832E854DE428ED2565CE";
  static const uint8_t binary_fingerprint[16]; // = {0x38,0x26,0x19,0x13,0xD0,0xA8,0x83,0x2E,0x85,0x4D,0xE4,0x28,0xED,0x25,0x65,0xCE};

  MasterClientService_getMasterStats_result(const MasterClientService_getMasterStats_result&);
  MasterClientService_getMasterStats_result& operator=(const MasterClientService_getMasterStats_result&);
  MasterClientService_getMasterStats_result() {
  }

  virtual ~MasterClientService_getMasterStats_result() throw();
  MasterMonitorInfo success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_getMasterStats_result__isset __isset;

  void __set_success(const MasterMonitorInfo& val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const MasterClientService_getMasterStats_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_getMasterStats_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_getMasterStats_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_getMasterStats_result& obj);
};

typedef struct _MasterClientService_getMasterStats_presult__isset {
  _MasterClientService_getMasterStats_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _MasterClientService_getMasterStats_presult__isset;

class MasterClientService_getMasterStats_presult {
 public:

  static const char* ascii_fingerprint; // = "38261913D0A8832E854DE428ED2565CE";
  static const uint8_t binary_fingerprint[16]; // = {0x38,0x26,0x19,0x13,0xD0,0xA8,0x83,0x2E,0x85,0x4D,0xE4,0x28,0xED,0x25,0x65,0xCE};


  virtual ~MasterClientService_getMasterStats_presult() throw();
  MasterMonitorInfo* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _MasterClientService_getMasterStats_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_getMasterStats_presult& obj);
};

typedef struct _MasterClientService_reportSplitExtent_args__isset {
  _MasterClientService_reportSplitExtent_args__isset() : tinfo(false), credentials(false), serverName(false), split(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool serverName :1;
  bool split :1;
} _MasterClientService_reportSplitExtent_args__isset;

class MasterClientService_reportSplitExtent_args {
 public:

  static const char* ascii_fingerprint; // = "DFDFFE3C4638494C48346609D04C093C";
  static const uint8_t binary_fingerprint[16]; // = {0xDF,0xDF,0xFE,0x3C,0x46,0x38,0x49,0x4C,0x48,0x34,0x66,0x09,0xD0,0x4C,0x09,0x3C};

  MasterClientService_reportSplitExtent_args(const MasterClientService_reportSplitExtent_args&);
  MasterClientService_reportSplitExtent_args& operator=(const MasterClientService_reportSplitExtent_args&);
  MasterClientService_reportSplitExtent_args() : serverName() {
  }

  virtual ~MasterClientService_reportSplitExtent_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string serverName;
  TabletSplit split;

  _MasterClientService_reportSplitExtent_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_serverName(const std::string& val);

  void __set_split(const TabletSplit& val);

  bool operator == (const MasterClientService_reportSplitExtent_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(serverName == rhs.serverName))
      return false;
    if (!(split == rhs.split))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_reportSplitExtent_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_reportSplitExtent_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_reportSplitExtent_args& obj);
};


class MasterClientService_reportSplitExtent_pargs {
 public:

  static const char* ascii_fingerprint; // = "DFDFFE3C4638494C48346609D04C093C";
  static const uint8_t binary_fingerprint[16]; // = {0xDF,0xDF,0xFE,0x3C,0x46,0x38,0x49,0x4C,0x48,0x34,0x66,0x09,0xD0,0x4C,0x09,0x3C};


  virtual ~MasterClientService_reportSplitExtent_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* serverName;
  const TabletSplit* split;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_reportSplitExtent_pargs& obj);
};

typedef struct _MasterClientService_reportTabletStatus_args__isset {
  _MasterClientService_reportTabletStatus_args__isset() : tinfo(false), credentials(false), serverName(false), status(false), tablet(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool serverName :1;
  bool status :1;
  bool tablet :1;
} _MasterClientService_reportTabletStatus_args__isset;

class MasterClientService_reportTabletStatus_args {
 public:

  static const char* ascii_fingerprint; // = "72F661B04557E690CE151FA482CEBD13";
  static const uint8_t binary_fingerprint[16]; // = {0x72,0xF6,0x61,0xB0,0x45,0x57,0xE6,0x90,0xCE,0x15,0x1F,0xA4,0x82,0xCE,0xBD,0x13};

  MasterClientService_reportTabletStatus_args(const MasterClientService_reportTabletStatus_args&);
  MasterClientService_reportTabletStatus_args& operator=(const MasterClientService_reportTabletStatus_args&);
  MasterClientService_reportTabletStatus_args() : serverName(), status((TabletLoadState::type)0) {
  }

  virtual ~MasterClientService_reportTabletStatus_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string serverName;
  TabletLoadState::type status;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent tablet;

  _MasterClientService_reportTabletStatus_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_serverName(const std::string& val);

  void __set_status(const TabletLoadState::type val);

  void __set_tablet(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  bool operator == (const MasterClientService_reportTabletStatus_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(serverName == rhs.serverName))
      return false;
    if (!(status == rhs.status))
      return false;
    if (!(tablet == rhs.tablet))
      return false;
    return true;
  }
  bool operator != (const MasterClientService_reportTabletStatus_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterClientService_reportTabletStatus_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_reportTabletStatus_args& obj);
};


class MasterClientService_reportTabletStatus_pargs {
 public:

  static const char* ascii_fingerprint; // = "72F661B04557E690CE151FA482CEBD13";
  static const uint8_t binary_fingerprint[16]; // = {0x72,0xF6,0x61,0xB0,0x45,0x57,0xE6,0x90,0xCE,0x15,0x1F,0xA4,0x82,0xCE,0xBD,0x13};


  virtual ~MasterClientService_reportTabletStatus_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* serverName;
  const TabletLoadState::type* status;
  const  ::org::apache::accumulo::core::data::thrift::TKeyExtent* tablet;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterClientService_reportTabletStatus_pargs& obj);
};

class MasterClientServiceClient : virtual public MasterClientServiceIf, public FateServiceClient {
 public:
  MasterClientServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    FateServiceClient(prot, prot) {}
  MasterClientServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :    FateServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int64_t initiateFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName);
  void send_initiateFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName);
  int64_t recv_initiateFlush();
  void waitForFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& startRow, const std::string& endRow, const int64_t flushID, const int64_t maxLoops);
  void send_waitForFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& startRow, const std::string& endRow, const int64_t flushID, const int64_t maxLoops);
  void recv_waitForFlush();
  void setTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& property, const std::string& value);
  void send_setTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& property, const std::string& value);
  void recv_setTableProperty();
  void removeTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& property);
  void send_removeTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& property);
  void recv_removeTableProperty();
  void setNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns, const std::string& property, const std::string& value);
  void send_setNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns, const std::string& property, const std::string& value);
  void recv_setNamespaceProperty();
  void removeNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns, const std::string& property);
  void send_removeNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns, const std::string& property);
  void recv_removeNamespaceProperty();
  void setMasterGoalState(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const MasterGoalState::type state);
  void send_setMasterGoalState(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const MasterGoalState::type state);
  void recv_setMasterGoalState();
  void shutdown(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const bool stopTabletServers);
  void send_shutdown(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const bool stopTabletServers);
  void recv_shutdown();
  void shutdownTabletServer(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tabletServer, const bool force);
  void send_shutdownTabletServer(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tabletServer, const bool force);
  void recv_shutdownTabletServer();
  void setSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& property, const std::string& value);
  void send_setSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& property, const std::string& value);
  void recv_setSystemProperty();
  void removeSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& property);
  void send_removeSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& property);
  void recv_removeSystemProperty();
  void getMasterStats(MasterMonitorInfo& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_getMasterStats(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void recv_getMasterStats(MasterMonitorInfo& _return);
  void reportSplitExtent(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& serverName, const TabletSplit& split);
  void send_reportSplitExtent(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& serverName, const TabletSplit& split);
  void reportTabletStatus(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& serverName, const TabletLoadState::type status, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& tablet);
  void send_reportTabletStatus(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& serverName, const TabletLoadState::type status, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& tablet);
};

class MasterClientServiceProcessor : public FateServiceProcessor {
 protected:
  boost::shared_ptr<MasterClientServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (MasterClientServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_initiateFlush(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_waitForFlush(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setTableProperty(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeTableProperty(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setNamespaceProperty(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeNamespaceProperty(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setMasterGoalState(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_shutdown(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_shutdownTabletServer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setSystemProperty(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeSystemProperty(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getMasterStats(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_reportSplitExtent(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_reportTabletStatus(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  MasterClientServiceProcessor(boost::shared_ptr<MasterClientServiceIf> iface) :
    FateServiceProcessor(iface),
    iface_(iface) {
    processMap_["initiateFlush"] = &MasterClientServiceProcessor::process_initiateFlush;
    processMap_["waitForFlush"] = &MasterClientServiceProcessor::process_waitForFlush;
    processMap_["setTableProperty"] = &MasterClientServiceProcessor::process_setTableProperty;
    processMap_["removeTableProperty"] = &MasterClientServiceProcessor::process_removeTableProperty;
    processMap_["setNamespaceProperty"] = &MasterClientServiceProcessor::process_setNamespaceProperty;
    processMap_["removeNamespaceProperty"] = &MasterClientServiceProcessor::process_removeNamespaceProperty;
    processMap_["setMasterGoalState"] = &MasterClientServiceProcessor::process_setMasterGoalState;
    processMap_["shutdown"] = &MasterClientServiceProcessor::process_shutdown;
    processMap_["shutdownTabletServer"] = &MasterClientServiceProcessor::process_shutdownTabletServer;
    processMap_["setSystemProperty"] = &MasterClientServiceProcessor::process_setSystemProperty;
    processMap_["removeSystemProperty"] = &MasterClientServiceProcessor::process_removeSystemProperty;
    processMap_["getMasterStats"] = &MasterClientServiceProcessor::process_getMasterStats;
    processMap_["reportSplitExtent"] = &MasterClientServiceProcessor::process_reportSplitExtent;
    processMap_["reportTabletStatus"] = &MasterClientServiceProcessor::process_reportTabletStatus;
  }

  virtual ~MasterClientServiceProcessor() {}
};

class MasterClientServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  MasterClientServiceProcessorFactory(const ::boost::shared_ptr< MasterClientServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< MasterClientServiceIfFactory > handlerFactory_;
};

class MasterClientServiceMultiface : virtual public MasterClientServiceIf, public FateServiceMultiface {
 public:
  MasterClientServiceMultiface(std::vector<boost::shared_ptr<MasterClientServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<MasterClientServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      FateServiceMultiface::add(*iter);
    }
  }
  virtual ~MasterClientServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<MasterClientServiceIf> > ifaces_;
  MasterClientServiceMultiface() {}
  void add(boost::shared_ptr<MasterClientServiceIf> iface) {
    FateServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  int64_t initiateFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->initiateFlush(tinfo, credentials, tableName);
    }
    return ifaces_[i]->initiateFlush(tinfo, credentials, tableName);
  }

  void waitForFlush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& startRow, const std::string& endRow, const int64_t flushID, const int64_t maxLoops) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->waitForFlush(tinfo, credentials, tableName, startRow, endRow, flushID, maxLoops);
    }
    ifaces_[i]->waitForFlush(tinfo, credentials, tableName, startRow, endRow, flushID, maxLoops);
  }

  void setTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& property, const std::string& value) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setTableProperty(tinfo, credentials, tableName, property, value);
    }
    ifaces_[i]->setTableProperty(tinfo, credentials, tableName, property, value);
  }

  void removeTableProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName, const std::string& property) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeTableProperty(tinfo, credentials, tableName, property);
    }
    ifaces_[i]->removeTableProperty(tinfo, credentials, tableName, property);
  }

  void setNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns, const std::string& property, const std::string& value) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setNamespaceProperty(tinfo, credentials, ns, property, value);
    }
    ifaces_[i]->setNamespaceProperty(tinfo, credentials, ns, property, value);
  }

  void removeNamespaceProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns, const std::string& property) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeNamespaceProperty(tinfo, credentials, ns, property);
    }
    ifaces_[i]->removeNamespaceProperty(tinfo, credentials, ns, property);
  }

  void setMasterGoalState(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const MasterGoalState::type state) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setMasterGoalState(tinfo, credentials, state);
    }
    ifaces_[i]->setMasterGoalState(tinfo, credentials, state);
  }

  void shutdown(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const bool stopTabletServers) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->shutdown(tinfo, credentials, stopTabletServers);
    }
    ifaces_[i]->shutdown(tinfo, credentials, stopTabletServers);
  }

  void shutdownTabletServer(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tabletServer, const bool force) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->shutdownTabletServer(tinfo, credentials, tabletServer, force);
    }
    ifaces_[i]->shutdownTabletServer(tinfo, credentials, tabletServer, force);
  }

  void setSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& property, const std::string& value) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setSystemProperty(tinfo, credentials, property, value);
    }
    ifaces_[i]->setSystemProperty(tinfo, credentials, property, value);
  }

  void removeSystemProperty(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& property) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeSystemProperty(tinfo, credentials, property);
    }
    ifaces_[i]->removeSystemProperty(tinfo, credentials, property);
  }

  void getMasterStats(MasterMonitorInfo& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getMasterStats(_return, tinfo, credentials);
    }
    ifaces_[i]->getMasterStats(_return, tinfo, credentials);
    return;
  }

  void reportSplitExtent(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& serverName, const TabletSplit& split) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->reportSplitExtent(tinfo, credentials, serverName, split);
    }
    ifaces_[i]->reportSplitExtent(tinfo, credentials, serverName, split);
  }

  void reportTabletStatus(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& serverName, const TabletLoadState::type status, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& tablet) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->reportTabletStatus(tinfo, credentials, serverName, status, tablet);
    }
    ifaces_[i]->reportTabletStatus(tinfo, credentials, serverName, status, tablet);
  }

};

}}}}}} // namespace

#endif
