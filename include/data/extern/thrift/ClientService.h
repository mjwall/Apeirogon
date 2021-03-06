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
#ifndef ClientService_H
#define ClientService_H

#include <thrift/TDispatchProcessor.h>
#include "client_types.h"

namespace org { namespace apache { namespace accumulo { namespace core { namespace client { namespace impl { namespace thrift {

class ClientServiceIf {
 public:
  virtual ~ClientServiceIf() {}
  virtual void getRootTabletLocation(std::string& _return) = 0;
  virtual void getInstanceId(std::string& _return) = 0;
  virtual void getZooKeepers(std::string& _return) = 0;
  virtual void bulkImportFiles(std::vector<std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t tid, const std::string& tableId, const std::vector<std::string> & files, const std::string& errorDir, const bool setTime) = 0;
  virtual bool isActive(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const int64_t tid) = 0;
  virtual void ping(const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void getDiskUsage(std::vector<TDiskUsage> & _return, const std::set<std::string> & tables, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void listLocalUsers(std::set<std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void createLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& password) = 0;
  virtual void dropLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal) = 0;
  virtual void changeLocalUserPassword(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& password) = 0;
  virtual bool authenticate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual bool authenticateUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::security::thrift::TCredentials& toAuth) = 0;
  virtual void changeAuthorizations(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::vector<std::string> & authorizations) = 0;
  virtual void getUserAuthorizations(std::vector<std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal) = 0;
  virtual bool hasSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t sysPerm) = 0;
  virtual bool hasTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t tblPerm) = 0;
  virtual bool hasNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t tblNspcPerm) = 0;
  virtual void grantSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t permission) = 0;
  virtual void revokeSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t permission) = 0;
  virtual void grantTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t permission) = 0;
  virtual void revokeTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t permission) = 0;
  virtual void grantNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t permission) = 0;
  virtual void revokeNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t permission) = 0;
  virtual void getConfiguration(std::map<std::string, std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const ConfigurationType::type type) = 0;
  virtual void getTableConfiguration(std::map<std::string, std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName) = 0;
  virtual void getNamespaceConfiguration(std::map<std::string, std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns) = 0;
  virtual bool checkClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& className, const std::string& interfaceMatch) = 0;
  virtual bool checkTableClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableId, const std::string& className, const std::string& interfaceMatch) = 0;
  virtual bool checkNamespaceClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& namespaceId, const std::string& className, const std::string& interfaceMatch) = 0;
};

class ClientServiceIfFactory {
 public:
  typedef ClientServiceIf Handler;

  virtual ~ClientServiceIfFactory() {}

  virtual ClientServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ClientServiceIf* /* handler */) = 0;
};

class ClientServiceIfSingletonFactory : virtual public ClientServiceIfFactory {
 public:
  ClientServiceIfSingletonFactory(const boost::shared_ptr<ClientServiceIf>& iface) : iface_(iface) {}
  virtual ~ClientServiceIfSingletonFactory() {}

  virtual ClientServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ClientServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<ClientServiceIf> iface_;
};

class ClientServiceNull : virtual public ClientServiceIf {
 public:
  virtual ~ClientServiceNull() {}
  void getRootTabletLocation(std::string& /* _return */) {
    return;
  }
  void getInstanceId(std::string& /* _return */) {
    return;
  }
  void getZooKeepers(std::string& /* _return */) {
    return;
  }
  void bulkImportFiles(std::vector<std::string> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const int64_t /* tid */, const std::string& /* tableId */, const std::vector<std::string> & /* files */, const std::string& /* errorDir */, const bool /* setTime */) {
    return;
  }
  bool isActive(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const int64_t /* tid */) {
    bool _return = false;
    return _return;
  }
  void ping(const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    return;
  }
  void getDiskUsage(std::vector<TDiskUsage> & /* _return */, const std::set<std::string> & /* tables */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    return;
  }
  void listLocalUsers(std::set<std::string> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    return;
  }
  void createLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const std::string& /* password */) {
    return;
  }
  void dropLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */) {
    return;
  }
  void changeLocalUserPassword(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const std::string& /* password */) {
    return;
  }
  bool authenticate(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    bool _return = false;
    return _return;
  }
  bool authenticateUser(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* toAuth */) {
    bool _return = false;
    return _return;
  }
  void changeAuthorizations(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const std::vector<std::string> & /* authorizations */) {
    return;
  }
  void getUserAuthorizations(std::vector<std::string> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */) {
    return;
  }
  bool hasSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const int8_t /* sysPerm */) {
    bool _return = false;
    return _return;
  }
  bool hasTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const std::string& /* tableName */, const int8_t /* tblPerm */) {
    bool _return = false;
    return _return;
  }
  bool hasNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const std::string& /* ns */, const int8_t /* tblNspcPerm */) {
    bool _return = false;
    return _return;
  }
  void grantSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const int8_t /* permission */) {
    return;
  }
  void revokeSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const int8_t /* permission */) {
    return;
  }
  void grantTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const std::string& /* tableName */, const int8_t /* permission */) {
    return;
  }
  void revokeTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const std::string& /* tableName */, const int8_t /* permission */) {
    return;
  }
  void grantNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const std::string& /* ns */, const int8_t /* permission */) {
    return;
  }
  void revokeNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* principal */, const std::string& /* ns */, const int8_t /* permission */) {
    return;
  }
  void getConfiguration(std::map<std::string, std::string> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const ConfigurationType::type /* type */) {
    return;
  }
  void getTableConfiguration(std::map<std::string, std::string> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* tableName */) {
    return;
  }
  void getNamespaceConfiguration(std::map<std::string, std::string> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* ns */) {
    return;
  }
  bool checkClass(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* className */, const std::string& /* interfaceMatch */) {
    bool _return = false;
    return _return;
  }
  bool checkTableClass(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* tableId */, const std::string& /* className */, const std::string& /* interfaceMatch */) {
    bool _return = false;
    return _return;
  }
  bool checkNamespaceClass(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* namespaceId */, const std::string& /* className */, const std::string& /* interfaceMatch */) {
    bool _return = false;
    return _return;
  }
};


class ClientService_getRootTabletLocation_args {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  ClientService_getRootTabletLocation_args(const ClientService_getRootTabletLocation_args&);
  ClientService_getRootTabletLocation_args& operator=(const ClientService_getRootTabletLocation_args&);
  ClientService_getRootTabletLocation_args() {
  }

  virtual ~ClientService_getRootTabletLocation_args() throw();

  bool operator == (const ClientService_getRootTabletLocation_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ClientService_getRootTabletLocation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getRootTabletLocation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getRootTabletLocation_args& obj);
};


class ClientService_getRootTabletLocation_pargs {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~ClientService_getRootTabletLocation_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getRootTabletLocation_pargs& obj);
};

typedef struct _ClientService_getRootTabletLocation_result__isset {
  _ClientService_getRootTabletLocation_result__isset() : success(false) {}
  bool success :1;
} _ClientService_getRootTabletLocation_result__isset;

class ClientService_getRootTabletLocation_result {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};

  ClientService_getRootTabletLocation_result(const ClientService_getRootTabletLocation_result&);
  ClientService_getRootTabletLocation_result& operator=(const ClientService_getRootTabletLocation_result&);
  ClientService_getRootTabletLocation_result() : success() {
  }

  virtual ~ClientService_getRootTabletLocation_result() throw();
  std::string success;

  _ClientService_getRootTabletLocation_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const ClientService_getRootTabletLocation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ClientService_getRootTabletLocation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getRootTabletLocation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getRootTabletLocation_result& obj);
};

typedef struct _ClientService_getRootTabletLocation_presult__isset {
  _ClientService_getRootTabletLocation_presult__isset() : success(false) {}
  bool success :1;
} _ClientService_getRootTabletLocation_presult__isset;

class ClientService_getRootTabletLocation_presult {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};


  virtual ~ClientService_getRootTabletLocation_presult() throw();
  std::string* success;

  _ClientService_getRootTabletLocation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getRootTabletLocation_presult& obj);
};


class ClientService_getInstanceId_args {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  ClientService_getInstanceId_args(const ClientService_getInstanceId_args&);
  ClientService_getInstanceId_args& operator=(const ClientService_getInstanceId_args&);
  ClientService_getInstanceId_args() {
  }

  virtual ~ClientService_getInstanceId_args() throw();

  bool operator == (const ClientService_getInstanceId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ClientService_getInstanceId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getInstanceId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getInstanceId_args& obj);
};


class ClientService_getInstanceId_pargs {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~ClientService_getInstanceId_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getInstanceId_pargs& obj);
};

typedef struct _ClientService_getInstanceId_result__isset {
  _ClientService_getInstanceId_result__isset() : success(false) {}
  bool success :1;
} _ClientService_getInstanceId_result__isset;

class ClientService_getInstanceId_result {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};

  ClientService_getInstanceId_result(const ClientService_getInstanceId_result&);
  ClientService_getInstanceId_result& operator=(const ClientService_getInstanceId_result&);
  ClientService_getInstanceId_result() : success() {
  }

  virtual ~ClientService_getInstanceId_result() throw();
  std::string success;

  _ClientService_getInstanceId_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const ClientService_getInstanceId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ClientService_getInstanceId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getInstanceId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getInstanceId_result& obj);
};

typedef struct _ClientService_getInstanceId_presult__isset {
  _ClientService_getInstanceId_presult__isset() : success(false) {}
  bool success :1;
} _ClientService_getInstanceId_presult__isset;

class ClientService_getInstanceId_presult {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};


  virtual ~ClientService_getInstanceId_presult() throw();
  std::string* success;

  _ClientService_getInstanceId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getInstanceId_presult& obj);
};


class ClientService_getZooKeepers_args {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  ClientService_getZooKeepers_args(const ClientService_getZooKeepers_args&);
  ClientService_getZooKeepers_args& operator=(const ClientService_getZooKeepers_args&);
  ClientService_getZooKeepers_args() {
  }

  virtual ~ClientService_getZooKeepers_args() throw();

  bool operator == (const ClientService_getZooKeepers_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ClientService_getZooKeepers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getZooKeepers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getZooKeepers_args& obj);
};


class ClientService_getZooKeepers_pargs {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~ClientService_getZooKeepers_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getZooKeepers_pargs& obj);
};

typedef struct _ClientService_getZooKeepers_result__isset {
  _ClientService_getZooKeepers_result__isset() : success(false) {}
  bool success :1;
} _ClientService_getZooKeepers_result__isset;

class ClientService_getZooKeepers_result {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};

  ClientService_getZooKeepers_result(const ClientService_getZooKeepers_result&);
  ClientService_getZooKeepers_result& operator=(const ClientService_getZooKeepers_result&);
  ClientService_getZooKeepers_result() : success() {
  }

  virtual ~ClientService_getZooKeepers_result() throw();
  std::string success;

  _ClientService_getZooKeepers_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const ClientService_getZooKeepers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ClientService_getZooKeepers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getZooKeepers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getZooKeepers_result& obj);
};

typedef struct _ClientService_getZooKeepers_presult__isset {
  _ClientService_getZooKeepers_presult__isset() : success(false) {}
  bool success :1;
} _ClientService_getZooKeepers_presult__isset;

class ClientService_getZooKeepers_presult {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};


  virtual ~ClientService_getZooKeepers_presult() throw();
  std::string* success;

  _ClientService_getZooKeepers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getZooKeepers_presult& obj);
};

typedef struct _ClientService_bulkImportFiles_args__isset {
  _ClientService_bulkImportFiles_args__isset() : tinfo(false), credentials(false), tid(false), tableId(false), files(false), errorDir(false), setTime(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tid :1;
  bool tableId :1;
  bool files :1;
  bool errorDir :1;
  bool setTime :1;
} _ClientService_bulkImportFiles_args__isset;

class ClientService_bulkImportFiles_args {
 public:

  static const char* ascii_fingerprint; // = "31BB9CE5BCAC6C7DEE5737B4473595A9";
  static const uint8_t binary_fingerprint[16]; // = {0x31,0xBB,0x9C,0xE5,0xBC,0xAC,0x6C,0x7D,0xEE,0x57,0x37,0xB4,0x47,0x35,0x95,0xA9};

  ClientService_bulkImportFiles_args(const ClientService_bulkImportFiles_args&);
  ClientService_bulkImportFiles_args& operator=(const ClientService_bulkImportFiles_args&);
  ClientService_bulkImportFiles_args() : tid(0), tableId(), errorDir(), setTime(0) {
  }

  virtual ~ClientService_bulkImportFiles_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  int64_t tid;
  std::string tableId;
  std::vector<std::string>  files;
  std::string errorDir;
  bool setTime;

  _ClientService_bulkImportFiles_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tid(const int64_t val);

  void __set_tableId(const std::string& val);

  void __set_files(const std::vector<std::string> & val);

  void __set_errorDir(const std::string& val);

  void __set_setTime(const bool val);

  bool operator == (const ClientService_bulkImportFiles_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tid == rhs.tid))
      return false;
    if (!(tableId == rhs.tableId))
      return false;
    if (!(files == rhs.files))
      return false;
    if (!(errorDir == rhs.errorDir))
      return false;
    if (!(setTime == rhs.setTime))
      return false;
    return true;
  }
  bool operator != (const ClientService_bulkImportFiles_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_bulkImportFiles_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_bulkImportFiles_args& obj);
};


class ClientService_bulkImportFiles_pargs {
 public:

  static const char* ascii_fingerprint; // = "31BB9CE5BCAC6C7DEE5737B4473595A9";
  static const uint8_t binary_fingerprint[16]; // = {0x31,0xBB,0x9C,0xE5,0xBC,0xAC,0x6C,0x7D,0xEE,0x57,0x37,0xB4,0x47,0x35,0x95,0xA9};


  virtual ~ClientService_bulkImportFiles_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const int64_t* tid;
  const std::string* tableId;
  const std::vector<std::string> * files;
  const std::string* errorDir;
  const bool* setTime;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_bulkImportFiles_pargs& obj);
};

typedef struct _ClientService_bulkImportFiles_result__isset {
  _ClientService_bulkImportFiles_result__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_bulkImportFiles_result__isset;

class ClientService_bulkImportFiles_result {
 public:

  static const char* ascii_fingerprint; // = "F86C394E3409EEDEDAFA63436C65D894";
  static const uint8_t binary_fingerprint[16]; // = {0xF8,0x6C,0x39,0x4E,0x34,0x09,0xEE,0xDE,0xDA,0xFA,0x63,0x43,0x6C,0x65,0xD8,0x94};

  ClientService_bulkImportFiles_result(const ClientService_bulkImportFiles_result&);
  ClientService_bulkImportFiles_result& operator=(const ClientService_bulkImportFiles_result&);
  ClientService_bulkImportFiles_result() {
  }

  virtual ~ClientService_bulkImportFiles_result() throw();
  std::vector<std::string>  success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_bulkImportFiles_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  void __set_sec(const ThriftSecurityException& val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_bulkImportFiles_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_bulkImportFiles_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_bulkImportFiles_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_bulkImportFiles_result& obj);
};

typedef struct _ClientService_bulkImportFiles_presult__isset {
  _ClientService_bulkImportFiles_presult__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_bulkImportFiles_presult__isset;

class ClientService_bulkImportFiles_presult {
 public:

  static const char* ascii_fingerprint; // = "F86C394E3409EEDEDAFA63436C65D894";
  static const uint8_t binary_fingerprint[16]; // = {0xF8,0x6C,0x39,0x4E,0x34,0x09,0xEE,0xDE,0xDA,0xFA,0x63,0x43,0x6C,0x65,0xD8,0x94};


  virtual ~ClientService_bulkImportFiles_presult() throw();
  std::vector<std::string> * success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_bulkImportFiles_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_bulkImportFiles_presult& obj);
};

typedef struct _ClientService_isActive_args__isset {
  _ClientService_isActive_args__isset() : tinfo(false), tid(false) {}
  bool tinfo :1;
  bool tid :1;
} _ClientService_isActive_args__isset;

class ClientService_isActive_args {
 public:

  static const char* ascii_fingerprint; // = "91E7F93A0F3914A8D24DBAECBD84A0A6";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0xE7,0xF9,0x3A,0x0F,0x39,0x14,0xA8,0xD2,0x4D,0xBA,0xEC,0xBD,0x84,0xA0,0xA6};

  ClientService_isActive_args(const ClientService_isActive_args&);
  ClientService_isActive_args& operator=(const ClientService_isActive_args&);
  ClientService_isActive_args() : tid(0) {
  }

  virtual ~ClientService_isActive_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
  int64_t tid;

  _ClientService_isActive_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_tid(const int64_t val);

  bool operator == (const ClientService_isActive_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(tid == rhs.tid))
      return false;
    return true;
  }
  bool operator != (const ClientService_isActive_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_isActive_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_isActive_args& obj);
};


class ClientService_isActive_pargs {
 public:

  static const char* ascii_fingerprint; // = "91E7F93A0F3914A8D24DBAECBD84A0A6";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0xE7,0xF9,0x3A,0x0F,0x39,0x14,0xA8,0xD2,0x4D,0xBA,0xEC,0xBD,0x84,0xA0,0xA6};


  virtual ~ClientService_isActive_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const int64_t* tid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_isActive_pargs& obj);
};

typedef struct _ClientService_isActive_result__isset {
  _ClientService_isActive_result__isset() : success(false) {}
  bool success :1;
} _ClientService_isActive_result__isset;

class ClientService_isActive_result {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};

  ClientService_isActive_result(const ClientService_isActive_result&);
  ClientService_isActive_result& operator=(const ClientService_isActive_result&);
  ClientService_isActive_result() : success(0) {
  }

  virtual ~ClientService_isActive_result() throw();
  bool success;

  _ClientService_isActive_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const ClientService_isActive_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ClientService_isActive_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_isActive_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_isActive_result& obj);
};

typedef struct _ClientService_isActive_presult__isset {
  _ClientService_isActive_presult__isset() : success(false) {}
  bool success :1;
} _ClientService_isActive_presult__isset;

class ClientService_isActive_presult {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};


  virtual ~ClientService_isActive_presult() throw();
  bool* success;

  _ClientService_isActive_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_isActive_presult& obj);
};

typedef struct _ClientService_ping_args__isset {
  _ClientService_ping_args__isset() : credentials(false) {}
  bool credentials :1;
} _ClientService_ping_args__isset;

class ClientService_ping_args {
 public:

  static const char* ascii_fingerprint; // = "22FAE298BD3B380273611E2518F220C2";
  static const uint8_t binary_fingerprint[16]; // = {0x22,0xFA,0xE2,0x98,0xBD,0x3B,0x38,0x02,0x73,0x61,0x1E,0x25,0x18,0xF2,0x20,0xC2};

  ClientService_ping_args(const ClientService_ping_args&);
  ClientService_ping_args& operator=(const ClientService_ping_args&);
  ClientService_ping_args() {
  }

  virtual ~ClientService_ping_args() throw();
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _ClientService_ping_args__isset __isset;

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const ClientService_ping_args & rhs) const
  {
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const ClientService_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_ping_args& obj);
};


class ClientService_ping_pargs {
 public:

  static const char* ascii_fingerprint; // = "22FAE298BD3B380273611E2518F220C2";
  static const uint8_t binary_fingerprint[16]; // = {0x22,0xFA,0xE2,0x98,0xBD,0x3B,0x38,0x02,0x73,0x61,0x1E,0x25,0x18,0xF2,0x20,0xC2};


  virtual ~ClientService_ping_pargs() throw();
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_ping_pargs& obj);
};

typedef struct _ClientService_ping_result__isset {
  _ClientService_ping_result__isset() : sec(false) {}
  bool sec :1;
} _ClientService_ping_result__isset;

class ClientService_ping_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  ClientService_ping_result(const ClientService_ping_result&);
  ClientService_ping_result& operator=(const ClientService_ping_result&);
  ClientService_ping_result() {
  }

  virtual ~ClientService_ping_result() throw();
  ThriftSecurityException sec;

  _ClientService_ping_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_ping_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_ping_result& obj);
};

typedef struct _ClientService_ping_presult__isset {
  _ClientService_ping_presult__isset() : sec(false) {}
  bool sec :1;
} _ClientService_ping_presult__isset;

class ClientService_ping_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~ClientService_ping_presult() throw();
  ThriftSecurityException sec;

  _ClientService_ping_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_ping_presult& obj);
};

typedef struct _ClientService_getDiskUsage_args__isset {
  _ClientService_getDiskUsage_args__isset() : tables(false), credentials(false) {}
  bool tables :1;
  bool credentials :1;
} _ClientService_getDiskUsage_args__isset;

class ClientService_getDiskUsage_args {
 public:

  static const char* ascii_fingerprint; // = "9360EFB3BEC550FE4F8115B8EB8A168B";
  static const uint8_t binary_fingerprint[16]; // = {0x93,0x60,0xEF,0xB3,0xBE,0xC5,0x50,0xFE,0x4F,0x81,0x15,0xB8,0xEB,0x8A,0x16,0x8B};

  ClientService_getDiskUsage_args(const ClientService_getDiskUsage_args&);
  ClientService_getDiskUsage_args& operator=(const ClientService_getDiskUsage_args&);
  ClientService_getDiskUsage_args() {
  }

  virtual ~ClientService_getDiskUsage_args() throw();
  std::set<std::string>  tables;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _ClientService_getDiskUsage_args__isset __isset;

  void __set_tables(const std::set<std::string> & val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const ClientService_getDiskUsage_args & rhs) const
  {
    if (!(tables == rhs.tables))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const ClientService_getDiskUsage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getDiskUsage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getDiskUsage_args& obj);
};


class ClientService_getDiskUsage_pargs {
 public:

  static const char* ascii_fingerprint; // = "9360EFB3BEC550FE4F8115B8EB8A168B";
  static const uint8_t binary_fingerprint[16]; // = {0x93,0x60,0xEF,0xB3,0xBE,0xC5,0x50,0xFE,0x4F,0x81,0x15,0xB8,0xEB,0x8A,0x16,0x8B};


  virtual ~ClientService_getDiskUsage_pargs() throw();
  const std::set<std::string> * tables;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getDiskUsage_pargs& obj);
};

typedef struct _ClientService_getDiskUsage_result__isset {
  _ClientService_getDiskUsage_result__isset() : success(false), sec(false), toe(false) {}
  bool success :1;
  bool sec :1;
  bool toe :1;
} _ClientService_getDiskUsage_result__isset;

class ClientService_getDiskUsage_result {
 public:

  static const char* ascii_fingerprint; // = "79858018F5DBE451BE068DFE19992EF3";
  static const uint8_t binary_fingerprint[16]; // = {0x79,0x85,0x80,0x18,0xF5,0xDB,0xE4,0x51,0xBE,0x06,0x8D,0xFE,0x19,0x99,0x2E,0xF3};

  ClientService_getDiskUsage_result(const ClientService_getDiskUsage_result&);
  ClientService_getDiskUsage_result& operator=(const ClientService_getDiskUsage_result&);
  ClientService_getDiskUsage_result() {
  }

  virtual ~ClientService_getDiskUsage_result() throw();
  std::vector<TDiskUsage>  success;
  ThriftSecurityException sec;
  ThriftTableOperationException toe;

  _ClientService_getDiskUsage_result__isset __isset;

  void __set_success(const std::vector<TDiskUsage> & val);

  void __set_sec(const ThriftSecurityException& val);

  void __set_toe(const ThriftTableOperationException& val);

  bool operator == (const ClientService_getDiskUsage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    if (!(toe == rhs.toe))
      return false;
    return true;
  }
  bool operator != (const ClientService_getDiskUsage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getDiskUsage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getDiskUsage_result& obj);
};

typedef struct _ClientService_getDiskUsage_presult__isset {
  _ClientService_getDiskUsage_presult__isset() : success(false), sec(false), toe(false) {}
  bool success :1;
  bool sec :1;
  bool toe :1;
} _ClientService_getDiskUsage_presult__isset;

class ClientService_getDiskUsage_presult {
 public:

  static const char* ascii_fingerprint; // = "79858018F5DBE451BE068DFE19992EF3";
  static const uint8_t binary_fingerprint[16]; // = {0x79,0x85,0x80,0x18,0xF5,0xDB,0xE4,0x51,0xBE,0x06,0x8D,0xFE,0x19,0x99,0x2E,0xF3};


  virtual ~ClientService_getDiskUsage_presult() throw();
  std::vector<TDiskUsage> * success;
  ThriftSecurityException sec;
  ThriftTableOperationException toe;

  _ClientService_getDiskUsage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getDiskUsage_presult& obj);
};

typedef struct _ClientService_listLocalUsers_args__isset {
  _ClientService_listLocalUsers_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _ClientService_listLocalUsers_args__isset;

class ClientService_listLocalUsers_args {
 public:

  static const char* ascii_fingerprint; // = "50502B469929B5C0A070AF472E82BDB5";
  static const uint8_t binary_fingerprint[16]; // = {0x50,0x50,0x2B,0x46,0x99,0x29,0xB5,0xC0,0xA0,0x70,0xAF,0x47,0x2E,0x82,0xBD,0xB5};

  ClientService_listLocalUsers_args(const ClientService_listLocalUsers_args&);
  ClientService_listLocalUsers_args& operator=(const ClientService_listLocalUsers_args&);
  ClientService_listLocalUsers_args() {
  }

  virtual ~ClientService_listLocalUsers_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _ClientService_listLocalUsers_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const ClientService_listLocalUsers_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const ClientService_listLocalUsers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_listLocalUsers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_listLocalUsers_args& obj);
};


class ClientService_listLocalUsers_pargs {
 public:

  static const char* ascii_fingerprint; // = "50502B469929B5C0A070AF472E82BDB5";
  static const uint8_t binary_fingerprint[16]; // = {0x50,0x50,0x2B,0x46,0x99,0x29,0xB5,0xC0,0xA0,0x70,0xAF,0x47,0x2E,0x82,0xBD,0xB5};


  virtual ~ClientService_listLocalUsers_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_listLocalUsers_pargs& obj);
};

typedef struct _ClientService_listLocalUsers_result__isset {
  _ClientService_listLocalUsers_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_listLocalUsers_result__isset;

class ClientService_listLocalUsers_result {
 public:

  static const char* ascii_fingerprint; // = "3D9B17B871711B12884BF912E16CD3C3";
  static const uint8_t binary_fingerprint[16]; // = {0x3D,0x9B,0x17,0xB8,0x71,0x71,0x1B,0x12,0x88,0x4B,0xF9,0x12,0xE1,0x6C,0xD3,0xC3};

  ClientService_listLocalUsers_result(const ClientService_listLocalUsers_result&);
  ClientService_listLocalUsers_result& operator=(const ClientService_listLocalUsers_result&);
  ClientService_listLocalUsers_result() {
  }

  virtual ~ClientService_listLocalUsers_result() throw();
  std::set<std::string>  success;
  ThriftSecurityException sec;

  _ClientService_listLocalUsers_result__isset __isset;

  void __set_success(const std::set<std::string> & val);

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_listLocalUsers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_listLocalUsers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_listLocalUsers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_listLocalUsers_result& obj);
};

typedef struct _ClientService_listLocalUsers_presult__isset {
  _ClientService_listLocalUsers_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_listLocalUsers_presult__isset;

class ClientService_listLocalUsers_presult {
 public:

  static const char* ascii_fingerprint; // = "3D9B17B871711B12884BF912E16CD3C3";
  static const uint8_t binary_fingerprint[16]; // = {0x3D,0x9B,0x17,0xB8,0x71,0x71,0x1B,0x12,0x88,0x4B,0xF9,0x12,0xE1,0x6C,0xD3,0xC3};


  virtual ~ClientService_listLocalUsers_presult() throw();
  std::set<std::string> * success;
  ThriftSecurityException sec;

  _ClientService_listLocalUsers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_listLocalUsers_presult& obj);
};

typedef struct _ClientService_createLocalUser_args__isset {
  _ClientService_createLocalUser_args__isset() : tinfo(false), credentials(false), principal(false), password(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool password :1;
} _ClientService_createLocalUser_args__isset;

class ClientService_createLocalUser_args {
 public:

  static const char* ascii_fingerprint; // = "5130D91B494FB91F6140966D9EC8C5B2";
  static const uint8_t binary_fingerprint[16]; // = {0x51,0x30,0xD9,0x1B,0x49,0x4F,0xB9,0x1F,0x61,0x40,0x96,0x6D,0x9E,0xC8,0xC5,0xB2};

  ClientService_createLocalUser_args(const ClientService_createLocalUser_args&);
  ClientService_createLocalUser_args& operator=(const ClientService_createLocalUser_args&);
  ClientService_createLocalUser_args() : principal(), password() {
  }

  virtual ~ClientService_createLocalUser_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  std::string password;

  _ClientService_createLocalUser_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_password(const std::string& val);

  bool operator == (const ClientService_createLocalUser_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(password == rhs.password))
      return false;
    return true;
  }
  bool operator != (const ClientService_createLocalUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_createLocalUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_createLocalUser_args& obj);
};


class ClientService_createLocalUser_pargs {
 public:

  static const char* ascii_fingerprint; // = "5130D91B494FB91F6140966D9EC8C5B2";
  static const uint8_t binary_fingerprint[16]; // = {0x51,0x30,0xD9,0x1B,0x49,0x4F,0xB9,0x1F,0x61,0x40,0x96,0x6D,0x9E,0xC8,0xC5,0xB2};


  virtual ~ClientService_createLocalUser_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const std::string* password;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_createLocalUser_pargs& obj);
};

typedef struct _ClientService_createLocalUser_result__isset {
  _ClientService_createLocalUser_result__isset() : sec(false) {}
  bool sec :1;
} _ClientService_createLocalUser_result__isset;

class ClientService_createLocalUser_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  ClientService_createLocalUser_result(const ClientService_createLocalUser_result&);
  ClientService_createLocalUser_result& operator=(const ClientService_createLocalUser_result&);
  ClientService_createLocalUser_result() {
  }

  virtual ~ClientService_createLocalUser_result() throw();
  ThriftSecurityException sec;

  _ClientService_createLocalUser_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_createLocalUser_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_createLocalUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_createLocalUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_createLocalUser_result& obj);
};

typedef struct _ClientService_createLocalUser_presult__isset {
  _ClientService_createLocalUser_presult__isset() : sec(false) {}
  bool sec :1;
} _ClientService_createLocalUser_presult__isset;

class ClientService_createLocalUser_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~ClientService_createLocalUser_presult() throw();
  ThriftSecurityException sec;

  _ClientService_createLocalUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_createLocalUser_presult& obj);
};

typedef struct _ClientService_dropLocalUser_args__isset {
  _ClientService_dropLocalUser_args__isset() : tinfo(false), credentials(false), principal(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
} _ClientService_dropLocalUser_args__isset;

class ClientService_dropLocalUser_args {
 public:

  static const char* ascii_fingerprint; // = "918DE36A1439B6683B5FE058F3CB0E2D";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0x8D,0xE3,0x6A,0x14,0x39,0xB6,0x68,0x3B,0x5F,0xE0,0x58,0xF3,0xCB,0x0E,0x2D};

  ClientService_dropLocalUser_args(const ClientService_dropLocalUser_args&);
  ClientService_dropLocalUser_args& operator=(const ClientService_dropLocalUser_args&);
  ClientService_dropLocalUser_args() : principal() {
  }

  virtual ~ClientService_dropLocalUser_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;

  _ClientService_dropLocalUser_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  bool operator == (const ClientService_dropLocalUser_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    return true;
  }
  bool operator != (const ClientService_dropLocalUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_dropLocalUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_dropLocalUser_args& obj);
};


class ClientService_dropLocalUser_pargs {
 public:

  static const char* ascii_fingerprint; // = "918DE36A1439B6683B5FE058F3CB0E2D";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0x8D,0xE3,0x6A,0x14,0x39,0xB6,0x68,0x3B,0x5F,0xE0,0x58,0xF3,0xCB,0x0E,0x2D};


  virtual ~ClientService_dropLocalUser_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_dropLocalUser_pargs& obj);
};

typedef struct _ClientService_dropLocalUser_result__isset {
  _ClientService_dropLocalUser_result__isset() : sec(false) {}
  bool sec :1;
} _ClientService_dropLocalUser_result__isset;

class ClientService_dropLocalUser_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  ClientService_dropLocalUser_result(const ClientService_dropLocalUser_result&);
  ClientService_dropLocalUser_result& operator=(const ClientService_dropLocalUser_result&);
  ClientService_dropLocalUser_result() {
  }

  virtual ~ClientService_dropLocalUser_result() throw();
  ThriftSecurityException sec;

  _ClientService_dropLocalUser_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_dropLocalUser_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_dropLocalUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_dropLocalUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_dropLocalUser_result& obj);
};

typedef struct _ClientService_dropLocalUser_presult__isset {
  _ClientService_dropLocalUser_presult__isset() : sec(false) {}
  bool sec :1;
} _ClientService_dropLocalUser_presult__isset;

class ClientService_dropLocalUser_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~ClientService_dropLocalUser_presult() throw();
  ThriftSecurityException sec;

  _ClientService_dropLocalUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_dropLocalUser_presult& obj);
};

typedef struct _ClientService_changeLocalUserPassword_args__isset {
  _ClientService_changeLocalUserPassword_args__isset() : tinfo(false), credentials(false), principal(false), password(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool password :1;
} _ClientService_changeLocalUserPassword_args__isset;

class ClientService_changeLocalUserPassword_args {
 public:

  static const char* ascii_fingerprint; // = "26385AAA207086375CAA6432A04EF537";
  static const uint8_t binary_fingerprint[16]; // = {0x26,0x38,0x5A,0xAA,0x20,0x70,0x86,0x37,0x5C,0xAA,0x64,0x32,0xA0,0x4E,0xF5,0x37};

  ClientService_changeLocalUserPassword_args(const ClientService_changeLocalUserPassword_args&);
  ClientService_changeLocalUserPassword_args& operator=(const ClientService_changeLocalUserPassword_args&);
  ClientService_changeLocalUserPassword_args() : principal(), password() {
  }

  virtual ~ClientService_changeLocalUserPassword_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  std::string password;

  _ClientService_changeLocalUserPassword_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_password(const std::string& val);

  bool operator == (const ClientService_changeLocalUserPassword_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(password == rhs.password))
      return false;
    return true;
  }
  bool operator != (const ClientService_changeLocalUserPassword_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_changeLocalUserPassword_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_changeLocalUserPassword_args& obj);
};


class ClientService_changeLocalUserPassword_pargs {
 public:

  static const char* ascii_fingerprint; // = "26385AAA207086375CAA6432A04EF537";
  static const uint8_t binary_fingerprint[16]; // = {0x26,0x38,0x5A,0xAA,0x20,0x70,0x86,0x37,0x5C,0xAA,0x64,0x32,0xA0,0x4E,0xF5,0x37};


  virtual ~ClientService_changeLocalUserPassword_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const std::string* password;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_changeLocalUserPassword_pargs& obj);
};

typedef struct _ClientService_changeLocalUserPassword_result__isset {
  _ClientService_changeLocalUserPassword_result__isset() : sec(false) {}
  bool sec :1;
} _ClientService_changeLocalUserPassword_result__isset;

class ClientService_changeLocalUserPassword_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  ClientService_changeLocalUserPassword_result(const ClientService_changeLocalUserPassword_result&);
  ClientService_changeLocalUserPassword_result& operator=(const ClientService_changeLocalUserPassword_result&);
  ClientService_changeLocalUserPassword_result() {
  }

  virtual ~ClientService_changeLocalUserPassword_result() throw();
  ThriftSecurityException sec;

  _ClientService_changeLocalUserPassword_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_changeLocalUserPassword_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_changeLocalUserPassword_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_changeLocalUserPassword_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_changeLocalUserPassword_result& obj);
};

typedef struct _ClientService_changeLocalUserPassword_presult__isset {
  _ClientService_changeLocalUserPassword_presult__isset() : sec(false) {}
  bool sec :1;
} _ClientService_changeLocalUserPassword_presult__isset;

class ClientService_changeLocalUserPassword_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~ClientService_changeLocalUserPassword_presult() throw();
  ThriftSecurityException sec;

  _ClientService_changeLocalUserPassword_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_changeLocalUserPassword_presult& obj);
};

typedef struct _ClientService_authenticate_args__isset {
  _ClientService_authenticate_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _ClientService_authenticate_args__isset;

class ClientService_authenticate_args {
 public:

  static const char* ascii_fingerprint; // = "8628689DE9E0EE9EB0B156CA8D94C628";
  static const uint8_t binary_fingerprint[16]; // = {0x86,0x28,0x68,0x9D,0xE9,0xE0,0xEE,0x9E,0xB0,0xB1,0x56,0xCA,0x8D,0x94,0xC6,0x28};

  ClientService_authenticate_args(const ClientService_authenticate_args&);
  ClientService_authenticate_args& operator=(const ClientService_authenticate_args&);
  ClientService_authenticate_args() {
  }

  virtual ~ClientService_authenticate_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _ClientService_authenticate_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const ClientService_authenticate_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const ClientService_authenticate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_authenticate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_authenticate_args& obj);
};


class ClientService_authenticate_pargs {
 public:

  static const char* ascii_fingerprint; // = "8628689DE9E0EE9EB0B156CA8D94C628";
  static const uint8_t binary_fingerprint[16]; // = {0x86,0x28,0x68,0x9D,0xE9,0xE0,0xEE,0x9E,0xB0,0xB1,0x56,0xCA,0x8D,0x94,0xC6,0x28};


  virtual ~ClientService_authenticate_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_authenticate_pargs& obj);
};

typedef struct _ClientService_authenticate_result__isset {
  _ClientService_authenticate_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_authenticate_result__isset;

class ClientService_authenticate_result {
 public:

  static const char* ascii_fingerprint; // = "5EDC6F0B20DD5234A1A92CD963B01402";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0xDC,0x6F,0x0B,0x20,0xDD,0x52,0x34,0xA1,0xA9,0x2C,0xD9,0x63,0xB0,0x14,0x02};

  ClientService_authenticate_result(const ClientService_authenticate_result&);
  ClientService_authenticate_result& operator=(const ClientService_authenticate_result&);
  ClientService_authenticate_result() : success(0) {
  }

  virtual ~ClientService_authenticate_result() throw();
  bool success;
  ThriftSecurityException sec;

  _ClientService_authenticate_result__isset __isset;

  void __set_success(const bool val);

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_authenticate_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_authenticate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_authenticate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_authenticate_result& obj);
};

typedef struct _ClientService_authenticate_presult__isset {
  _ClientService_authenticate_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_authenticate_presult__isset;

class ClientService_authenticate_presult {
 public:

  static const char* ascii_fingerprint; // = "5EDC6F0B20DD5234A1A92CD963B01402";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0xDC,0x6F,0x0B,0x20,0xDD,0x52,0x34,0xA1,0xA9,0x2C,0xD9,0x63,0xB0,0x14,0x02};


  virtual ~ClientService_authenticate_presult() throw();
  bool* success;
  ThriftSecurityException sec;

  _ClientService_authenticate_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_authenticate_presult& obj);
};

typedef struct _ClientService_authenticateUser_args__isset {
  _ClientService_authenticateUser_args__isset() : tinfo(false), credentials(false), toAuth(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool toAuth :1;
} _ClientService_authenticateUser_args__isset;

class ClientService_authenticateUser_args {
 public:

  static const char* ascii_fingerprint; // = "6290ECBAB19491D2FD596A0174D3E612";
  static const uint8_t binary_fingerprint[16]; // = {0x62,0x90,0xEC,0xBA,0xB1,0x94,0x91,0xD2,0xFD,0x59,0x6A,0x01,0x74,0xD3,0xE6,0x12};

  ClientService_authenticateUser_args(const ClientService_authenticateUser_args&);
  ClientService_authenticateUser_args& operator=(const ClientService_authenticateUser_args&);
  ClientService_authenticateUser_args() {
  }

  virtual ~ClientService_authenticateUser_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
   ::org::apache::accumulo::core::security::thrift::TCredentials toAuth;

  _ClientService_authenticateUser_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_toAuth(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const ClientService_authenticateUser_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(toAuth == rhs.toAuth))
      return false;
    return true;
  }
  bool operator != (const ClientService_authenticateUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_authenticateUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_authenticateUser_args& obj);
};


class ClientService_authenticateUser_pargs {
 public:

  static const char* ascii_fingerprint; // = "6290ECBAB19491D2FD596A0174D3E612";
  static const uint8_t binary_fingerprint[16]; // = {0x62,0x90,0xEC,0xBA,0xB1,0x94,0x91,0xD2,0xFD,0x59,0x6A,0x01,0x74,0xD3,0xE6,0x12};


  virtual ~ClientService_authenticateUser_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* toAuth;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_authenticateUser_pargs& obj);
};

typedef struct _ClientService_authenticateUser_result__isset {
  _ClientService_authenticateUser_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_authenticateUser_result__isset;

class ClientService_authenticateUser_result {
 public:

  static const char* ascii_fingerprint; // = "5EDC6F0B20DD5234A1A92CD963B01402";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0xDC,0x6F,0x0B,0x20,0xDD,0x52,0x34,0xA1,0xA9,0x2C,0xD9,0x63,0xB0,0x14,0x02};

  ClientService_authenticateUser_result(const ClientService_authenticateUser_result&);
  ClientService_authenticateUser_result& operator=(const ClientService_authenticateUser_result&);
  ClientService_authenticateUser_result() : success(0) {
  }

  virtual ~ClientService_authenticateUser_result() throw();
  bool success;
  ThriftSecurityException sec;

  _ClientService_authenticateUser_result__isset __isset;

  void __set_success(const bool val);

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_authenticateUser_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_authenticateUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_authenticateUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_authenticateUser_result& obj);
};

typedef struct _ClientService_authenticateUser_presult__isset {
  _ClientService_authenticateUser_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_authenticateUser_presult__isset;

class ClientService_authenticateUser_presult {
 public:

  static const char* ascii_fingerprint; // = "5EDC6F0B20DD5234A1A92CD963B01402";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0xDC,0x6F,0x0B,0x20,0xDD,0x52,0x34,0xA1,0xA9,0x2C,0xD9,0x63,0xB0,0x14,0x02};


  virtual ~ClientService_authenticateUser_presult() throw();
  bool* success;
  ThriftSecurityException sec;

  _ClientService_authenticateUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_authenticateUser_presult& obj);
};

typedef struct _ClientService_changeAuthorizations_args__isset {
  _ClientService_changeAuthorizations_args__isset() : tinfo(false), credentials(false), principal(false), authorizations(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool authorizations :1;
} _ClientService_changeAuthorizations_args__isset;

class ClientService_changeAuthorizations_args {
 public:

  static const char* ascii_fingerprint; // = "8A800AB2328D6823F86893FE9D6F2B5B";
  static const uint8_t binary_fingerprint[16]; // = {0x8A,0x80,0x0A,0xB2,0x32,0x8D,0x68,0x23,0xF8,0x68,0x93,0xFE,0x9D,0x6F,0x2B,0x5B};

  ClientService_changeAuthorizations_args(const ClientService_changeAuthorizations_args&);
  ClientService_changeAuthorizations_args& operator=(const ClientService_changeAuthorizations_args&);
  ClientService_changeAuthorizations_args() : principal() {
  }

  virtual ~ClientService_changeAuthorizations_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  std::vector<std::string>  authorizations;

  _ClientService_changeAuthorizations_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_authorizations(const std::vector<std::string> & val);

  bool operator == (const ClientService_changeAuthorizations_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(authorizations == rhs.authorizations))
      return false;
    return true;
  }
  bool operator != (const ClientService_changeAuthorizations_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_changeAuthorizations_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_changeAuthorizations_args& obj);
};


class ClientService_changeAuthorizations_pargs {
 public:

  static const char* ascii_fingerprint; // = "8A800AB2328D6823F86893FE9D6F2B5B";
  static const uint8_t binary_fingerprint[16]; // = {0x8A,0x80,0x0A,0xB2,0x32,0x8D,0x68,0x23,0xF8,0x68,0x93,0xFE,0x9D,0x6F,0x2B,0x5B};


  virtual ~ClientService_changeAuthorizations_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const std::vector<std::string> * authorizations;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_changeAuthorizations_pargs& obj);
};

typedef struct _ClientService_changeAuthorizations_result__isset {
  _ClientService_changeAuthorizations_result__isset() : sec(false) {}
  bool sec :1;
} _ClientService_changeAuthorizations_result__isset;

class ClientService_changeAuthorizations_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  ClientService_changeAuthorizations_result(const ClientService_changeAuthorizations_result&);
  ClientService_changeAuthorizations_result& operator=(const ClientService_changeAuthorizations_result&);
  ClientService_changeAuthorizations_result() {
  }

  virtual ~ClientService_changeAuthorizations_result() throw();
  ThriftSecurityException sec;

  _ClientService_changeAuthorizations_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_changeAuthorizations_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_changeAuthorizations_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_changeAuthorizations_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_changeAuthorizations_result& obj);
};

typedef struct _ClientService_changeAuthorizations_presult__isset {
  _ClientService_changeAuthorizations_presult__isset() : sec(false) {}
  bool sec :1;
} _ClientService_changeAuthorizations_presult__isset;

class ClientService_changeAuthorizations_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~ClientService_changeAuthorizations_presult() throw();
  ThriftSecurityException sec;

  _ClientService_changeAuthorizations_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_changeAuthorizations_presult& obj);
};

typedef struct _ClientService_getUserAuthorizations_args__isset {
  _ClientService_getUserAuthorizations_args__isset() : tinfo(false), credentials(false), principal(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
} _ClientService_getUserAuthorizations_args__isset;

class ClientService_getUserAuthorizations_args {
 public:

  static const char* ascii_fingerprint; // = "918DE36A1439B6683B5FE058F3CB0E2D";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0x8D,0xE3,0x6A,0x14,0x39,0xB6,0x68,0x3B,0x5F,0xE0,0x58,0xF3,0xCB,0x0E,0x2D};

  ClientService_getUserAuthorizations_args(const ClientService_getUserAuthorizations_args&);
  ClientService_getUserAuthorizations_args& operator=(const ClientService_getUserAuthorizations_args&);
  ClientService_getUserAuthorizations_args() : principal() {
  }

  virtual ~ClientService_getUserAuthorizations_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;

  _ClientService_getUserAuthorizations_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  bool operator == (const ClientService_getUserAuthorizations_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    return true;
  }
  bool operator != (const ClientService_getUserAuthorizations_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getUserAuthorizations_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getUserAuthorizations_args& obj);
};


class ClientService_getUserAuthorizations_pargs {
 public:

  static const char* ascii_fingerprint; // = "918DE36A1439B6683B5FE058F3CB0E2D";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0x8D,0xE3,0x6A,0x14,0x39,0xB6,0x68,0x3B,0x5F,0xE0,0x58,0xF3,0xCB,0x0E,0x2D};


  virtual ~ClientService_getUserAuthorizations_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getUserAuthorizations_pargs& obj);
};

typedef struct _ClientService_getUserAuthorizations_result__isset {
  _ClientService_getUserAuthorizations_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_getUserAuthorizations_result__isset;

class ClientService_getUserAuthorizations_result {
 public:

  static const char* ascii_fingerprint; // = "CA2F809216F7BF7B7BCE5240804E6974";
  static const uint8_t binary_fingerprint[16]; // = {0xCA,0x2F,0x80,0x92,0x16,0xF7,0xBF,0x7B,0x7B,0xCE,0x52,0x40,0x80,0x4E,0x69,0x74};

  ClientService_getUserAuthorizations_result(const ClientService_getUserAuthorizations_result&);
  ClientService_getUserAuthorizations_result& operator=(const ClientService_getUserAuthorizations_result&);
  ClientService_getUserAuthorizations_result() {
  }

  virtual ~ClientService_getUserAuthorizations_result() throw();
  std::vector<std::string>  success;
  ThriftSecurityException sec;

  _ClientService_getUserAuthorizations_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_getUserAuthorizations_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_getUserAuthorizations_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getUserAuthorizations_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getUserAuthorizations_result& obj);
};

typedef struct _ClientService_getUserAuthorizations_presult__isset {
  _ClientService_getUserAuthorizations_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_getUserAuthorizations_presult__isset;

class ClientService_getUserAuthorizations_presult {
 public:

  static const char* ascii_fingerprint; // = "CA2F809216F7BF7B7BCE5240804E6974";
  static const uint8_t binary_fingerprint[16]; // = {0xCA,0x2F,0x80,0x92,0x16,0xF7,0xBF,0x7B,0x7B,0xCE,0x52,0x40,0x80,0x4E,0x69,0x74};


  virtual ~ClientService_getUserAuthorizations_presult() throw();
  std::vector<std::string> * success;
  ThriftSecurityException sec;

  _ClientService_getUserAuthorizations_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getUserAuthorizations_presult& obj);
};

typedef struct _ClientService_hasSystemPermission_args__isset {
  _ClientService_hasSystemPermission_args__isset() : tinfo(false), credentials(false), principal(false), sysPerm(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool sysPerm :1;
} _ClientService_hasSystemPermission_args__isset;

class ClientService_hasSystemPermission_args {
 public:

  static const char* ascii_fingerprint; // = "BCD446C1FA4E0BC30B88401C83BC711A";
  static const uint8_t binary_fingerprint[16]; // = {0xBC,0xD4,0x46,0xC1,0xFA,0x4E,0x0B,0xC3,0x0B,0x88,0x40,0x1C,0x83,0xBC,0x71,0x1A};

  ClientService_hasSystemPermission_args(const ClientService_hasSystemPermission_args&);
  ClientService_hasSystemPermission_args& operator=(const ClientService_hasSystemPermission_args&);
  ClientService_hasSystemPermission_args() : principal(), sysPerm(0) {
  }

  virtual ~ClientService_hasSystemPermission_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  int8_t sysPerm;

  _ClientService_hasSystemPermission_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_sysPerm(const int8_t val);

  bool operator == (const ClientService_hasSystemPermission_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(sysPerm == rhs.sysPerm))
      return false;
    return true;
  }
  bool operator != (const ClientService_hasSystemPermission_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_hasSystemPermission_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasSystemPermission_args& obj);
};


class ClientService_hasSystemPermission_pargs {
 public:

  static const char* ascii_fingerprint; // = "BCD446C1FA4E0BC30B88401C83BC711A";
  static const uint8_t binary_fingerprint[16]; // = {0xBC,0xD4,0x46,0xC1,0xFA,0x4E,0x0B,0xC3,0x0B,0x88,0x40,0x1C,0x83,0xBC,0x71,0x1A};


  virtual ~ClientService_hasSystemPermission_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const int8_t* sysPerm;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasSystemPermission_pargs& obj);
};

typedef struct _ClientService_hasSystemPermission_result__isset {
  _ClientService_hasSystemPermission_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_hasSystemPermission_result__isset;

class ClientService_hasSystemPermission_result {
 public:

  static const char* ascii_fingerprint; // = "5EDC6F0B20DD5234A1A92CD963B01402";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0xDC,0x6F,0x0B,0x20,0xDD,0x52,0x34,0xA1,0xA9,0x2C,0xD9,0x63,0xB0,0x14,0x02};

  ClientService_hasSystemPermission_result(const ClientService_hasSystemPermission_result&);
  ClientService_hasSystemPermission_result& operator=(const ClientService_hasSystemPermission_result&);
  ClientService_hasSystemPermission_result() : success(0) {
  }

  virtual ~ClientService_hasSystemPermission_result() throw();
  bool success;
  ThriftSecurityException sec;

  _ClientService_hasSystemPermission_result__isset __isset;

  void __set_success(const bool val);

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_hasSystemPermission_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_hasSystemPermission_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_hasSystemPermission_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasSystemPermission_result& obj);
};

typedef struct _ClientService_hasSystemPermission_presult__isset {
  _ClientService_hasSystemPermission_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _ClientService_hasSystemPermission_presult__isset;

class ClientService_hasSystemPermission_presult {
 public:

  static const char* ascii_fingerprint; // = "5EDC6F0B20DD5234A1A92CD963B01402";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0xDC,0x6F,0x0B,0x20,0xDD,0x52,0x34,0xA1,0xA9,0x2C,0xD9,0x63,0xB0,0x14,0x02};


  virtual ~ClientService_hasSystemPermission_presult() throw();
  bool* success;
  ThriftSecurityException sec;

  _ClientService_hasSystemPermission_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasSystemPermission_presult& obj);
};

typedef struct _ClientService_hasTablePermission_args__isset {
  _ClientService_hasTablePermission_args__isset() : tinfo(false), credentials(false), principal(false), tableName(false), tblPerm(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool tableName :1;
  bool tblPerm :1;
} _ClientService_hasTablePermission_args__isset;

class ClientService_hasTablePermission_args {
 public:

  static const char* ascii_fingerprint; // = "6C62CD8A29CFD268478CB62F7BAD03F6";
  static const uint8_t binary_fingerprint[16]; // = {0x6C,0x62,0xCD,0x8A,0x29,0xCF,0xD2,0x68,0x47,0x8C,0xB6,0x2F,0x7B,0xAD,0x03,0xF6};

  ClientService_hasTablePermission_args(const ClientService_hasTablePermission_args&);
  ClientService_hasTablePermission_args& operator=(const ClientService_hasTablePermission_args&);
  ClientService_hasTablePermission_args() : principal(), tableName(), tblPerm(0) {
  }

  virtual ~ClientService_hasTablePermission_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  std::string tableName;
  int8_t tblPerm;

  _ClientService_hasTablePermission_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_tableName(const std::string& val);

  void __set_tblPerm(const int8_t val);

  bool operator == (const ClientService_hasTablePermission_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    if (!(tblPerm == rhs.tblPerm))
      return false;
    return true;
  }
  bool operator != (const ClientService_hasTablePermission_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_hasTablePermission_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasTablePermission_args& obj);
};


class ClientService_hasTablePermission_pargs {
 public:

  static const char* ascii_fingerprint; // = "6C62CD8A29CFD268478CB62F7BAD03F6";
  static const uint8_t binary_fingerprint[16]; // = {0x6C,0x62,0xCD,0x8A,0x29,0xCF,0xD2,0x68,0x47,0x8C,0xB6,0x2F,0x7B,0xAD,0x03,0xF6};


  virtual ~ClientService_hasTablePermission_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const std::string* tableName;
  const int8_t* tblPerm;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasTablePermission_pargs& obj);
};

typedef struct _ClientService_hasTablePermission_result__isset {
  _ClientService_hasTablePermission_result__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_hasTablePermission_result__isset;

class ClientService_hasTablePermission_result {
 public:

  static const char* ascii_fingerprint; // = "B6D3A05943954654C738C4EDE5DDBC7F";
  static const uint8_t binary_fingerprint[16]; // = {0xB6,0xD3,0xA0,0x59,0x43,0x95,0x46,0x54,0xC7,0x38,0xC4,0xED,0xE5,0xDD,0xBC,0x7F};

  ClientService_hasTablePermission_result(const ClientService_hasTablePermission_result&);
  ClientService_hasTablePermission_result& operator=(const ClientService_hasTablePermission_result&);
  ClientService_hasTablePermission_result() : success(0) {
  }

  virtual ~ClientService_hasTablePermission_result() throw();
  bool success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_hasTablePermission_result__isset __isset;

  void __set_success(const bool val);

  void __set_sec(const ThriftSecurityException& val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_hasTablePermission_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_hasTablePermission_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_hasTablePermission_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasTablePermission_result& obj);
};

typedef struct _ClientService_hasTablePermission_presult__isset {
  _ClientService_hasTablePermission_presult__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_hasTablePermission_presult__isset;

class ClientService_hasTablePermission_presult {
 public:

  static const char* ascii_fingerprint; // = "B6D3A05943954654C738C4EDE5DDBC7F";
  static const uint8_t binary_fingerprint[16]; // = {0xB6,0xD3,0xA0,0x59,0x43,0x95,0x46,0x54,0xC7,0x38,0xC4,0xED,0xE5,0xDD,0xBC,0x7F};


  virtual ~ClientService_hasTablePermission_presult() throw();
  bool* success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_hasTablePermission_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasTablePermission_presult& obj);
};

typedef struct _ClientService_hasNamespacePermission_args__isset {
  _ClientService_hasNamespacePermission_args__isset() : tinfo(false), credentials(false), principal(false), ns(false), tblNspcPerm(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool ns :1;
  bool tblNspcPerm :1;
} _ClientService_hasNamespacePermission_args__isset;

class ClientService_hasNamespacePermission_args {
 public:

  static const char* ascii_fingerprint; // = "6D2437748D29400F2B54CB811F67C8B0";
  static const uint8_t binary_fingerprint[16]; // = {0x6D,0x24,0x37,0x74,0x8D,0x29,0x40,0x0F,0x2B,0x54,0xCB,0x81,0x1F,0x67,0xC8,0xB0};

  ClientService_hasNamespacePermission_args(const ClientService_hasNamespacePermission_args&);
  ClientService_hasNamespacePermission_args& operator=(const ClientService_hasNamespacePermission_args&);
  ClientService_hasNamespacePermission_args() : principal(), ns(), tblNspcPerm(0) {
  }

  virtual ~ClientService_hasNamespacePermission_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  std::string ns;
  int8_t tblNspcPerm;

  _ClientService_hasNamespacePermission_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_ns(const std::string& val);

  void __set_tblNspcPerm(const int8_t val);

  bool operator == (const ClientService_hasNamespacePermission_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(ns == rhs.ns))
      return false;
    if (!(tblNspcPerm == rhs.tblNspcPerm))
      return false;
    return true;
  }
  bool operator != (const ClientService_hasNamespacePermission_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_hasNamespacePermission_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasNamespacePermission_args& obj);
};


class ClientService_hasNamespacePermission_pargs {
 public:

  static const char* ascii_fingerprint; // = "6D2437748D29400F2B54CB811F67C8B0";
  static const uint8_t binary_fingerprint[16]; // = {0x6D,0x24,0x37,0x74,0x8D,0x29,0x40,0x0F,0x2B,0x54,0xCB,0x81,0x1F,0x67,0xC8,0xB0};


  virtual ~ClientService_hasNamespacePermission_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const std::string* ns;
  const int8_t* tblNspcPerm;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasNamespacePermission_pargs& obj);
};

typedef struct _ClientService_hasNamespacePermission_result__isset {
  _ClientService_hasNamespacePermission_result__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_hasNamespacePermission_result__isset;

class ClientService_hasNamespacePermission_result {
 public:

  static const char* ascii_fingerprint; // = "B6D3A05943954654C738C4EDE5DDBC7F";
  static const uint8_t binary_fingerprint[16]; // = {0xB6,0xD3,0xA0,0x59,0x43,0x95,0x46,0x54,0xC7,0x38,0xC4,0xED,0xE5,0xDD,0xBC,0x7F};

  ClientService_hasNamespacePermission_result(const ClientService_hasNamespacePermission_result&);
  ClientService_hasNamespacePermission_result& operator=(const ClientService_hasNamespacePermission_result&);
  ClientService_hasNamespacePermission_result() : success(0) {
  }

  virtual ~ClientService_hasNamespacePermission_result() throw();
  bool success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_hasNamespacePermission_result__isset __isset;

  void __set_success(const bool val);

  void __set_sec(const ThriftSecurityException& val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_hasNamespacePermission_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_hasNamespacePermission_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_hasNamespacePermission_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasNamespacePermission_result& obj);
};

typedef struct _ClientService_hasNamespacePermission_presult__isset {
  _ClientService_hasNamespacePermission_presult__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_hasNamespacePermission_presult__isset;

class ClientService_hasNamespacePermission_presult {
 public:

  static const char* ascii_fingerprint; // = "B6D3A05943954654C738C4EDE5DDBC7F";
  static const uint8_t binary_fingerprint[16]; // = {0xB6,0xD3,0xA0,0x59,0x43,0x95,0x46,0x54,0xC7,0x38,0xC4,0xED,0xE5,0xDD,0xBC,0x7F};


  virtual ~ClientService_hasNamespacePermission_presult() throw();
  bool* success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_hasNamespacePermission_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_hasNamespacePermission_presult& obj);
};

typedef struct _ClientService_grantSystemPermission_args__isset {
  _ClientService_grantSystemPermission_args__isset() : tinfo(false), credentials(false), principal(false), permission(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool permission :1;
} _ClientService_grantSystemPermission_args__isset;

class ClientService_grantSystemPermission_args {
 public:

  static const char* ascii_fingerprint; // = "BCD446C1FA4E0BC30B88401C83BC711A";
  static const uint8_t binary_fingerprint[16]; // = {0xBC,0xD4,0x46,0xC1,0xFA,0x4E,0x0B,0xC3,0x0B,0x88,0x40,0x1C,0x83,0xBC,0x71,0x1A};

  ClientService_grantSystemPermission_args(const ClientService_grantSystemPermission_args&);
  ClientService_grantSystemPermission_args& operator=(const ClientService_grantSystemPermission_args&);
  ClientService_grantSystemPermission_args() : principal(), permission(0) {
  }

  virtual ~ClientService_grantSystemPermission_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  int8_t permission;

  _ClientService_grantSystemPermission_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_permission(const int8_t val);

  bool operator == (const ClientService_grantSystemPermission_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(permission == rhs.permission))
      return false;
    return true;
  }
  bool operator != (const ClientService_grantSystemPermission_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_grantSystemPermission_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantSystemPermission_args& obj);
};


class ClientService_grantSystemPermission_pargs {
 public:

  static const char* ascii_fingerprint; // = "BCD446C1FA4E0BC30B88401C83BC711A";
  static const uint8_t binary_fingerprint[16]; // = {0xBC,0xD4,0x46,0xC1,0xFA,0x4E,0x0B,0xC3,0x0B,0x88,0x40,0x1C,0x83,0xBC,0x71,0x1A};


  virtual ~ClientService_grantSystemPermission_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const int8_t* permission;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantSystemPermission_pargs& obj);
};

typedef struct _ClientService_grantSystemPermission_result__isset {
  _ClientService_grantSystemPermission_result__isset() : sec(false) {}
  bool sec :1;
} _ClientService_grantSystemPermission_result__isset;

class ClientService_grantSystemPermission_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  ClientService_grantSystemPermission_result(const ClientService_grantSystemPermission_result&);
  ClientService_grantSystemPermission_result& operator=(const ClientService_grantSystemPermission_result&);
  ClientService_grantSystemPermission_result() {
  }

  virtual ~ClientService_grantSystemPermission_result() throw();
  ThriftSecurityException sec;

  _ClientService_grantSystemPermission_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_grantSystemPermission_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_grantSystemPermission_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_grantSystemPermission_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantSystemPermission_result& obj);
};

typedef struct _ClientService_grantSystemPermission_presult__isset {
  _ClientService_grantSystemPermission_presult__isset() : sec(false) {}
  bool sec :1;
} _ClientService_grantSystemPermission_presult__isset;

class ClientService_grantSystemPermission_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~ClientService_grantSystemPermission_presult() throw();
  ThriftSecurityException sec;

  _ClientService_grantSystemPermission_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantSystemPermission_presult& obj);
};

typedef struct _ClientService_revokeSystemPermission_args__isset {
  _ClientService_revokeSystemPermission_args__isset() : tinfo(false), credentials(false), principal(false), permission(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool permission :1;
} _ClientService_revokeSystemPermission_args__isset;

class ClientService_revokeSystemPermission_args {
 public:

  static const char* ascii_fingerprint; // = "BCD446C1FA4E0BC30B88401C83BC711A";
  static const uint8_t binary_fingerprint[16]; // = {0xBC,0xD4,0x46,0xC1,0xFA,0x4E,0x0B,0xC3,0x0B,0x88,0x40,0x1C,0x83,0xBC,0x71,0x1A};

  ClientService_revokeSystemPermission_args(const ClientService_revokeSystemPermission_args&);
  ClientService_revokeSystemPermission_args& operator=(const ClientService_revokeSystemPermission_args&);
  ClientService_revokeSystemPermission_args() : principal(), permission(0) {
  }

  virtual ~ClientService_revokeSystemPermission_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  int8_t permission;

  _ClientService_revokeSystemPermission_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_permission(const int8_t val);

  bool operator == (const ClientService_revokeSystemPermission_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(permission == rhs.permission))
      return false;
    return true;
  }
  bool operator != (const ClientService_revokeSystemPermission_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_revokeSystemPermission_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeSystemPermission_args& obj);
};


class ClientService_revokeSystemPermission_pargs {
 public:

  static const char* ascii_fingerprint; // = "BCD446C1FA4E0BC30B88401C83BC711A";
  static const uint8_t binary_fingerprint[16]; // = {0xBC,0xD4,0x46,0xC1,0xFA,0x4E,0x0B,0xC3,0x0B,0x88,0x40,0x1C,0x83,0xBC,0x71,0x1A};


  virtual ~ClientService_revokeSystemPermission_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const int8_t* permission;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeSystemPermission_pargs& obj);
};

typedef struct _ClientService_revokeSystemPermission_result__isset {
  _ClientService_revokeSystemPermission_result__isset() : sec(false) {}
  bool sec :1;
} _ClientService_revokeSystemPermission_result__isset;

class ClientService_revokeSystemPermission_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  ClientService_revokeSystemPermission_result(const ClientService_revokeSystemPermission_result&);
  ClientService_revokeSystemPermission_result& operator=(const ClientService_revokeSystemPermission_result&);
  ClientService_revokeSystemPermission_result() {
  }

  virtual ~ClientService_revokeSystemPermission_result() throw();
  ThriftSecurityException sec;

  _ClientService_revokeSystemPermission_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  bool operator == (const ClientService_revokeSystemPermission_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const ClientService_revokeSystemPermission_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_revokeSystemPermission_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeSystemPermission_result& obj);
};

typedef struct _ClientService_revokeSystemPermission_presult__isset {
  _ClientService_revokeSystemPermission_presult__isset() : sec(false) {}
  bool sec :1;
} _ClientService_revokeSystemPermission_presult__isset;

class ClientService_revokeSystemPermission_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~ClientService_revokeSystemPermission_presult() throw();
  ThriftSecurityException sec;

  _ClientService_revokeSystemPermission_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeSystemPermission_presult& obj);
};

typedef struct _ClientService_grantTablePermission_args__isset {
  _ClientService_grantTablePermission_args__isset() : tinfo(false), credentials(false), principal(false), tableName(false), permission(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool tableName :1;
  bool permission :1;
} _ClientService_grantTablePermission_args__isset;

class ClientService_grantTablePermission_args {
 public:

  static const char* ascii_fingerprint; // = "6C62CD8A29CFD268478CB62F7BAD03F6";
  static const uint8_t binary_fingerprint[16]; // = {0x6C,0x62,0xCD,0x8A,0x29,0xCF,0xD2,0x68,0x47,0x8C,0xB6,0x2F,0x7B,0xAD,0x03,0xF6};

  ClientService_grantTablePermission_args(const ClientService_grantTablePermission_args&);
  ClientService_grantTablePermission_args& operator=(const ClientService_grantTablePermission_args&);
  ClientService_grantTablePermission_args() : principal(), tableName(), permission(0) {
  }

  virtual ~ClientService_grantTablePermission_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  std::string tableName;
  int8_t permission;

  _ClientService_grantTablePermission_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_tableName(const std::string& val);

  void __set_permission(const int8_t val);

  bool operator == (const ClientService_grantTablePermission_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    if (!(permission == rhs.permission))
      return false;
    return true;
  }
  bool operator != (const ClientService_grantTablePermission_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_grantTablePermission_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantTablePermission_args& obj);
};


class ClientService_grantTablePermission_pargs {
 public:

  static const char* ascii_fingerprint; // = "6C62CD8A29CFD268478CB62F7BAD03F6";
  static const uint8_t binary_fingerprint[16]; // = {0x6C,0x62,0xCD,0x8A,0x29,0xCF,0xD2,0x68,0x47,0x8C,0xB6,0x2F,0x7B,0xAD,0x03,0xF6};


  virtual ~ClientService_grantTablePermission_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const std::string* tableName;
  const int8_t* permission;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantTablePermission_pargs& obj);
};

typedef struct _ClientService_grantTablePermission_result__isset {
  _ClientService_grantTablePermission_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _ClientService_grantTablePermission_result__isset;

class ClientService_grantTablePermission_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  ClientService_grantTablePermission_result(const ClientService_grantTablePermission_result&);
  ClientService_grantTablePermission_result& operator=(const ClientService_grantTablePermission_result&);
  ClientService_grantTablePermission_result() {
  }

  virtual ~ClientService_grantTablePermission_result() throw();
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_grantTablePermission_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_grantTablePermission_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_grantTablePermission_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_grantTablePermission_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantTablePermission_result& obj);
};

typedef struct _ClientService_grantTablePermission_presult__isset {
  _ClientService_grantTablePermission_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _ClientService_grantTablePermission_presult__isset;

class ClientService_grantTablePermission_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~ClientService_grantTablePermission_presult() throw();
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_grantTablePermission_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantTablePermission_presult& obj);
};

typedef struct _ClientService_revokeTablePermission_args__isset {
  _ClientService_revokeTablePermission_args__isset() : tinfo(false), credentials(false), principal(false), tableName(false), permission(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool tableName :1;
  bool permission :1;
} _ClientService_revokeTablePermission_args__isset;

class ClientService_revokeTablePermission_args {
 public:

  static const char* ascii_fingerprint; // = "6C62CD8A29CFD268478CB62F7BAD03F6";
  static const uint8_t binary_fingerprint[16]; // = {0x6C,0x62,0xCD,0x8A,0x29,0xCF,0xD2,0x68,0x47,0x8C,0xB6,0x2F,0x7B,0xAD,0x03,0xF6};

  ClientService_revokeTablePermission_args(const ClientService_revokeTablePermission_args&);
  ClientService_revokeTablePermission_args& operator=(const ClientService_revokeTablePermission_args&);
  ClientService_revokeTablePermission_args() : principal(), tableName(), permission(0) {
  }

  virtual ~ClientService_revokeTablePermission_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  std::string tableName;
  int8_t permission;

  _ClientService_revokeTablePermission_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_tableName(const std::string& val);

  void __set_permission(const int8_t val);

  bool operator == (const ClientService_revokeTablePermission_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    if (!(permission == rhs.permission))
      return false;
    return true;
  }
  bool operator != (const ClientService_revokeTablePermission_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_revokeTablePermission_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeTablePermission_args& obj);
};


class ClientService_revokeTablePermission_pargs {
 public:

  static const char* ascii_fingerprint; // = "6C62CD8A29CFD268478CB62F7BAD03F6";
  static const uint8_t binary_fingerprint[16]; // = {0x6C,0x62,0xCD,0x8A,0x29,0xCF,0xD2,0x68,0x47,0x8C,0xB6,0x2F,0x7B,0xAD,0x03,0xF6};


  virtual ~ClientService_revokeTablePermission_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const std::string* tableName;
  const int8_t* permission;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeTablePermission_pargs& obj);
};

typedef struct _ClientService_revokeTablePermission_result__isset {
  _ClientService_revokeTablePermission_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _ClientService_revokeTablePermission_result__isset;

class ClientService_revokeTablePermission_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  ClientService_revokeTablePermission_result(const ClientService_revokeTablePermission_result&);
  ClientService_revokeTablePermission_result& operator=(const ClientService_revokeTablePermission_result&);
  ClientService_revokeTablePermission_result() {
  }

  virtual ~ClientService_revokeTablePermission_result() throw();
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_revokeTablePermission_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_revokeTablePermission_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_revokeTablePermission_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_revokeTablePermission_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeTablePermission_result& obj);
};

typedef struct _ClientService_revokeTablePermission_presult__isset {
  _ClientService_revokeTablePermission_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _ClientService_revokeTablePermission_presult__isset;

class ClientService_revokeTablePermission_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~ClientService_revokeTablePermission_presult() throw();
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_revokeTablePermission_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeTablePermission_presult& obj);
};

typedef struct _ClientService_grantNamespacePermission_args__isset {
  _ClientService_grantNamespacePermission_args__isset() : tinfo(false), credentials(false), principal(false), ns(false), permission(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool ns :1;
  bool permission :1;
} _ClientService_grantNamespacePermission_args__isset;

class ClientService_grantNamespacePermission_args {
 public:

  static const char* ascii_fingerprint; // = "6D2437748D29400F2B54CB811F67C8B0";
  static const uint8_t binary_fingerprint[16]; // = {0x6D,0x24,0x37,0x74,0x8D,0x29,0x40,0x0F,0x2B,0x54,0xCB,0x81,0x1F,0x67,0xC8,0xB0};

  ClientService_grantNamespacePermission_args(const ClientService_grantNamespacePermission_args&);
  ClientService_grantNamespacePermission_args& operator=(const ClientService_grantNamespacePermission_args&);
  ClientService_grantNamespacePermission_args() : principal(), ns(), permission(0) {
  }

  virtual ~ClientService_grantNamespacePermission_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  std::string ns;
  int8_t permission;

  _ClientService_grantNamespacePermission_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_ns(const std::string& val);

  void __set_permission(const int8_t val);

  bool operator == (const ClientService_grantNamespacePermission_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(ns == rhs.ns))
      return false;
    if (!(permission == rhs.permission))
      return false;
    return true;
  }
  bool operator != (const ClientService_grantNamespacePermission_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_grantNamespacePermission_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantNamespacePermission_args& obj);
};


class ClientService_grantNamespacePermission_pargs {
 public:

  static const char* ascii_fingerprint; // = "6D2437748D29400F2B54CB811F67C8B0";
  static const uint8_t binary_fingerprint[16]; // = {0x6D,0x24,0x37,0x74,0x8D,0x29,0x40,0x0F,0x2B,0x54,0xCB,0x81,0x1F,0x67,0xC8,0xB0};


  virtual ~ClientService_grantNamespacePermission_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const std::string* ns;
  const int8_t* permission;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantNamespacePermission_pargs& obj);
};

typedef struct _ClientService_grantNamespacePermission_result__isset {
  _ClientService_grantNamespacePermission_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _ClientService_grantNamespacePermission_result__isset;

class ClientService_grantNamespacePermission_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  ClientService_grantNamespacePermission_result(const ClientService_grantNamespacePermission_result&);
  ClientService_grantNamespacePermission_result& operator=(const ClientService_grantNamespacePermission_result&);
  ClientService_grantNamespacePermission_result() {
  }

  virtual ~ClientService_grantNamespacePermission_result() throw();
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_grantNamespacePermission_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_grantNamespacePermission_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_grantNamespacePermission_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_grantNamespacePermission_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantNamespacePermission_result& obj);
};

typedef struct _ClientService_grantNamespacePermission_presult__isset {
  _ClientService_grantNamespacePermission_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _ClientService_grantNamespacePermission_presult__isset;

class ClientService_grantNamespacePermission_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~ClientService_grantNamespacePermission_presult() throw();
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_grantNamespacePermission_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_grantNamespacePermission_presult& obj);
};

typedef struct _ClientService_revokeNamespacePermission_args__isset {
  _ClientService_revokeNamespacePermission_args__isset() : tinfo(false), credentials(false), principal(false), ns(false), permission(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool principal :1;
  bool ns :1;
  bool permission :1;
} _ClientService_revokeNamespacePermission_args__isset;

class ClientService_revokeNamespacePermission_args {
 public:

  static const char* ascii_fingerprint; // = "6D2437748D29400F2B54CB811F67C8B0";
  static const uint8_t binary_fingerprint[16]; // = {0x6D,0x24,0x37,0x74,0x8D,0x29,0x40,0x0F,0x2B,0x54,0xCB,0x81,0x1F,0x67,0xC8,0xB0};

  ClientService_revokeNamespacePermission_args(const ClientService_revokeNamespacePermission_args&);
  ClientService_revokeNamespacePermission_args& operator=(const ClientService_revokeNamespacePermission_args&);
  ClientService_revokeNamespacePermission_args() : principal(), ns(), permission(0) {
  }

  virtual ~ClientService_revokeNamespacePermission_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string principal;
  std::string ns;
  int8_t permission;

  _ClientService_revokeNamespacePermission_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_principal(const std::string& val);

  void __set_ns(const std::string& val);

  void __set_permission(const int8_t val);

  bool operator == (const ClientService_revokeNamespacePermission_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(principal == rhs.principal))
      return false;
    if (!(ns == rhs.ns))
      return false;
    if (!(permission == rhs.permission))
      return false;
    return true;
  }
  bool operator != (const ClientService_revokeNamespacePermission_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_revokeNamespacePermission_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeNamespacePermission_args& obj);
};


class ClientService_revokeNamespacePermission_pargs {
 public:

  static const char* ascii_fingerprint; // = "6D2437748D29400F2B54CB811F67C8B0";
  static const uint8_t binary_fingerprint[16]; // = {0x6D,0x24,0x37,0x74,0x8D,0x29,0x40,0x0F,0x2B,0x54,0xCB,0x81,0x1F,0x67,0xC8,0xB0};


  virtual ~ClientService_revokeNamespacePermission_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* principal;
  const std::string* ns;
  const int8_t* permission;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeNamespacePermission_pargs& obj);
};

typedef struct _ClientService_revokeNamespacePermission_result__isset {
  _ClientService_revokeNamespacePermission_result__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _ClientService_revokeNamespacePermission_result__isset;

class ClientService_revokeNamespacePermission_result {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};

  ClientService_revokeNamespacePermission_result(const ClientService_revokeNamespacePermission_result&);
  ClientService_revokeNamespacePermission_result& operator=(const ClientService_revokeNamespacePermission_result&);
  ClientService_revokeNamespacePermission_result() {
  }

  virtual ~ClientService_revokeNamespacePermission_result() throw();
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_revokeNamespacePermission_result__isset __isset;

  void __set_sec(const ThriftSecurityException& val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_revokeNamespacePermission_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_revokeNamespacePermission_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_revokeNamespacePermission_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeNamespacePermission_result& obj);
};

typedef struct _ClientService_revokeNamespacePermission_presult__isset {
  _ClientService_revokeNamespacePermission_presult__isset() : sec(false), tope(false) {}
  bool sec :1;
  bool tope :1;
} _ClientService_revokeNamespacePermission_presult__isset;

class ClientService_revokeNamespacePermission_presult {
 public:

  static const char* ascii_fingerprint; // = "4D27D81C231C927DC5A8A3697BB71F0A";
  static const uint8_t binary_fingerprint[16]; // = {0x4D,0x27,0xD8,0x1C,0x23,0x1C,0x92,0x7D,0xC5,0xA8,0xA3,0x69,0x7B,0xB7,0x1F,0x0A};


  virtual ~ClientService_revokeNamespacePermission_presult() throw();
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_revokeNamespacePermission_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_revokeNamespacePermission_presult& obj);
};

typedef struct _ClientService_getConfiguration_args__isset {
  _ClientService_getConfiguration_args__isset() : tinfo(false), credentials(false), type(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool type :1;
} _ClientService_getConfiguration_args__isset;

class ClientService_getConfiguration_args {
 public:

  static const char* ascii_fingerprint; // = "122F48863927D7C102E74D529BB82C4A";
  static const uint8_t binary_fingerprint[16]; // = {0x12,0x2F,0x48,0x86,0x39,0x27,0xD7,0xC1,0x02,0xE7,0x4D,0x52,0x9B,0xB8,0x2C,0x4A};

  ClientService_getConfiguration_args(const ClientService_getConfiguration_args&);
  ClientService_getConfiguration_args& operator=(const ClientService_getConfiguration_args&);
  ClientService_getConfiguration_args() : type((ConfigurationType::type)0) {
  }

  virtual ~ClientService_getConfiguration_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  ConfigurationType::type type;

  _ClientService_getConfiguration_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_type(const ConfigurationType::type val);

  bool operator == (const ClientService_getConfiguration_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(type == rhs.type))
      return false;
    return true;
  }
  bool operator != (const ClientService_getConfiguration_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getConfiguration_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getConfiguration_args& obj);
};


class ClientService_getConfiguration_pargs {
 public:

  static const char* ascii_fingerprint; // = "122F48863927D7C102E74D529BB82C4A";
  static const uint8_t binary_fingerprint[16]; // = {0x12,0x2F,0x48,0x86,0x39,0x27,0xD7,0xC1,0x02,0xE7,0x4D,0x52,0x9B,0xB8,0x2C,0x4A};


  virtual ~ClientService_getConfiguration_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const ConfigurationType::type* type;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getConfiguration_pargs& obj);
};

typedef struct _ClientService_getConfiguration_result__isset {
  _ClientService_getConfiguration_result__isset() : success(false) {}
  bool success :1;
} _ClientService_getConfiguration_result__isset;

class ClientService_getConfiguration_result {
 public:

  static const char* ascii_fingerprint; // = "7722CAB26D5D8252F8DAEA54B25BC179";
  static const uint8_t binary_fingerprint[16]; // = {0x77,0x22,0xCA,0xB2,0x6D,0x5D,0x82,0x52,0xF8,0xDA,0xEA,0x54,0xB2,0x5B,0xC1,0x79};

  ClientService_getConfiguration_result(const ClientService_getConfiguration_result&);
  ClientService_getConfiguration_result& operator=(const ClientService_getConfiguration_result&);
  ClientService_getConfiguration_result() {
  }

  virtual ~ClientService_getConfiguration_result() throw();
  std::map<std::string, std::string>  success;

  _ClientService_getConfiguration_result__isset __isset;

  void __set_success(const std::map<std::string, std::string> & val);

  bool operator == (const ClientService_getConfiguration_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ClientService_getConfiguration_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getConfiguration_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getConfiguration_result& obj);
};

typedef struct _ClientService_getConfiguration_presult__isset {
  _ClientService_getConfiguration_presult__isset() : success(false) {}
  bool success :1;
} _ClientService_getConfiguration_presult__isset;

class ClientService_getConfiguration_presult {
 public:

  static const char* ascii_fingerprint; // = "7722CAB26D5D8252F8DAEA54B25BC179";
  static const uint8_t binary_fingerprint[16]; // = {0x77,0x22,0xCA,0xB2,0x6D,0x5D,0x82,0x52,0xF8,0xDA,0xEA,0x54,0xB2,0x5B,0xC1,0x79};


  virtual ~ClientService_getConfiguration_presult() throw();
  std::map<std::string, std::string> * success;

  _ClientService_getConfiguration_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getConfiguration_presult& obj);
};

typedef struct _ClientService_getTableConfiguration_args__isset {
  _ClientService_getTableConfiguration_args__isset() : tinfo(false), credentials(false), tableName(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tableName :1;
} _ClientService_getTableConfiguration_args__isset;

class ClientService_getTableConfiguration_args {
 public:

  static const char* ascii_fingerprint; // = "B988CC8A1111E37A64F5AA18FE8CE7BB";
  static const uint8_t binary_fingerprint[16]; // = {0xB9,0x88,0xCC,0x8A,0x11,0x11,0xE3,0x7A,0x64,0xF5,0xAA,0x18,0xFE,0x8C,0xE7,0xBB};

  ClientService_getTableConfiguration_args(const ClientService_getTableConfiguration_args&);
  ClientService_getTableConfiguration_args& operator=(const ClientService_getTableConfiguration_args&);
  ClientService_getTableConfiguration_args() : tableName() {
  }

  virtual ~ClientService_getTableConfiguration_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string tableName;

  _ClientService_getTableConfiguration_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tableName(const std::string& val);

  bool operator == (const ClientService_getTableConfiguration_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    return true;
  }
  bool operator != (const ClientService_getTableConfiguration_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getTableConfiguration_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getTableConfiguration_args& obj);
};


class ClientService_getTableConfiguration_pargs {
 public:

  static const char* ascii_fingerprint; // = "B988CC8A1111E37A64F5AA18FE8CE7BB";
  static const uint8_t binary_fingerprint[16]; // = {0xB9,0x88,0xCC,0x8A,0x11,0x11,0xE3,0x7A,0x64,0xF5,0xAA,0x18,0xFE,0x8C,0xE7,0xBB};


  virtual ~ClientService_getTableConfiguration_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* tableName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getTableConfiguration_pargs& obj);
};

typedef struct _ClientService_getTableConfiguration_result__isset {
  _ClientService_getTableConfiguration_result__isset() : success(false), tope(false) {}
  bool success :1;
  bool tope :1;
} _ClientService_getTableConfiguration_result__isset;

class ClientService_getTableConfiguration_result {
 public:

  static const char* ascii_fingerprint; // = "070E472CA711045051A907A530598B3F";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0x0E,0x47,0x2C,0xA7,0x11,0x04,0x50,0x51,0xA9,0x07,0xA5,0x30,0x59,0x8B,0x3F};

  ClientService_getTableConfiguration_result(const ClientService_getTableConfiguration_result&);
  ClientService_getTableConfiguration_result& operator=(const ClientService_getTableConfiguration_result&);
  ClientService_getTableConfiguration_result() {
  }

  virtual ~ClientService_getTableConfiguration_result() throw();
  std::map<std::string, std::string>  success;
  ThriftTableOperationException tope;

  _ClientService_getTableConfiguration_result__isset __isset;

  void __set_success(const std::map<std::string, std::string> & val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_getTableConfiguration_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_getTableConfiguration_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getTableConfiguration_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getTableConfiguration_result& obj);
};

typedef struct _ClientService_getTableConfiguration_presult__isset {
  _ClientService_getTableConfiguration_presult__isset() : success(false), tope(false) {}
  bool success :1;
  bool tope :1;
} _ClientService_getTableConfiguration_presult__isset;

class ClientService_getTableConfiguration_presult {
 public:

  static const char* ascii_fingerprint; // = "070E472CA711045051A907A530598B3F";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0x0E,0x47,0x2C,0xA7,0x11,0x04,0x50,0x51,0xA9,0x07,0xA5,0x30,0x59,0x8B,0x3F};


  virtual ~ClientService_getTableConfiguration_presult() throw();
  std::map<std::string, std::string> * success;
  ThriftTableOperationException tope;

  _ClientService_getTableConfiguration_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getTableConfiguration_presult& obj);
};

typedef struct _ClientService_getNamespaceConfiguration_args__isset {
  _ClientService_getNamespaceConfiguration_args__isset() : tinfo(false), credentials(false), ns(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool ns :1;
} _ClientService_getNamespaceConfiguration_args__isset;

class ClientService_getNamespaceConfiguration_args {
 public:

  static const char* ascii_fingerprint; // = "21494A6C5B9DC45B3298B9129250D167";
  static const uint8_t binary_fingerprint[16]; // = {0x21,0x49,0x4A,0x6C,0x5B,0x9D,0xC4,0x5B,0x32,0x98,0xB9,0x12,0x92,0x50,0xD1,0x67};

  ClientService_getNamespaceConfiguration_args(const ClientService_getNamespaceConfiguration_args&);
  ClientService_getNamespaceConfiguration_args& operator=(const ClientService_getNamespaceConfiguration_args&);
  ClientService_getNamespaceConfiguration_args() : ns() {
  }

  virtual ~ClientService_getNamespaceConfiguration_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string ns;

  _ClientService_getNamespaceConfiguration_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_ns(const std::string& val);

  bool operator == (const ClientService_getNamespaceConfiguration_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(ns == rhs.ns))
      return false;
    return true;
  }
  bool operator != (const ClientService_getNamespaceConfiguration_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getNamespaceConfiguration_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getNamespaceConfiguration_args& obj);
};


class ClientService_getNamespaceConfiguration_pargs {
 public:

  static const char* ascii_fingerprint; // = "21494A6C5B9DC45B3298B9129250D167";
  static const uint8_t binary_fingerprint[16]; // = {0x21,0x49,0x4A,0x6C,0x5B,0x9D,0xC4,0x5B,0x32,0x98,0xB9,0x12,0x92,0x50,0xD1,0x67};


  virtual ~ClientService_getNamespaceConfiguration_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* ns;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getNamespaceConfiguration_pargs& obj);
};

typedef struct _ClientService_getNamespaceConfiguration_result__isset {
  _ClientService_getNamespaceConfiguration_result__isset() : success(false), tope(false) {}
  bool success :1;
  bool tope :1;
} _ClientService_getNamespaceConfiguration_result__isset;

class ClientService_getNamespaceConfiguration_result {
 public:

  static const char* ascii_fingerprint; // = "070E472CA711045051A907A530598B3F";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0x0E,0x47,0x2C,0xA7,0x11,0x04,0x50,0x51,0xA9,0x07,0xA5,0x30,0x59,0x8B,0x3F};

  ClientService_getNamespaceConfiguration_result(const ClientService_getNamespaceConfiguration_result&);
  ClientService_getNamespaceConfiguration_result& operator=(const ClientService_getNamespaceConfiguration_result&);
  ClientService_getNamespaceConfiguration_result() {
  }

  virtual ~ClientService_getNamespaceConfiguration_result() throw();
  std::map<std::string, std::string>  success;
  ThriftTableOperationException tope;

  _ClientService_getNamespaceConfiguration_result__isset __isset;

  void __set_success(const std::map<std::string, std::string> & val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_getNamespaceConfiguration_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_getNamespaceConfiguration_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_getNamespaceConfiguration_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getNamespaceConfiguration_result& obj);
};

typedef struct _ClientService_getNamespaceConfiguration_presult__isset {
  _ClientService_getNamespaceConfiguration_presult__isset() : success(false), tope(false) {}
  bool success :1;
  bool tope :1;
} _ClientService_getNamespaceConfiguration_presult__isset;

class ClientService_getNamespaceConfiguration_presult {
 public:

  static const char* ascii_fingerprint; // = "070E472CA711045051A907A530598B3F";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0x0E,0x47,0x2C,0xA7,0x11,0x04,0x50,0x51,0xA9,0x07,0xA5,0x30,0x59,0x8B,0x3F};


  virtual ~ClientService_getNamespaceConfiguration_presult() throw();
  std::map<std::string, std::string> * success;
  ThriftTableOperationException tope;

  _ClientService_getNamespaceConfiguration_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_getNamespaceConfiguration_presult& obj);
};

typedef struct _ClientService_checkClass_args__isset {
  _ClientService_checkClass_args__isset() : tinfo(false), credentials(false), className(false), interfaceMatch(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool className :1;
  bool interfaceMatch :1;
} _ClientService_checkClass_args__isset;

class ClientService_checkClass_args {
 public:

  static const char* ascii_fingerprint; // = "0F91905C73735CC4623F09E9432E8475";
  static const uint8_t binary_fingerprint[16]; // = {0x0F,0x91,0x90,0x5C,0x73,0x73,0x5C,0xC4,0x62,0x3F,0x09,0xE9,0x43,0x2E,0x84,0x75};

  ClientService_checkClass_args(const ClientService_checkClass_args&);
  ClientService_checkClass_args& operator=(const ClientService_checkClass_args&);
  ClientService_checkClass_args() : className(), interfaceMatch() {
  }

  virtual ~ClientService_checkClass_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string className;
  std::string interfaceMatch;

  _ClientService_checkClass_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_className(const std::string& val);

  void __set_interfaceMatch(const std::string& val);

  bool operator == (const ClientService_checkClass_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(className == rhs.className))
      return false;
    if (!(interfaceMatch == rhs.interfaceMatch))
      return false;
    return true;
  }
  bool operator != (const ClientService_checkClass_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_checkClass_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkClass_args& obj);
};


class ClientService_checkClass_pargs {
 public:

  static const char* ascii_fingerprint; // = "0F91905C73735CC4623F09E9432E8475";
  static const uint8_t binary_fingerprint[16]; // = {0x0F,0x91,0x90,0x5C,0x73,0x73,0x5C,0xC4,0x62,0x3F,0x09,0xE9,0x43,0x2E,0x84,0x75};


  virtual ~ClientService_checkClass_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* className;
  const std::string* interfaceMatch;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkClass_pargs& obj);
};

typedef struct _ClientService_checkClass_result__isset {
  _ClientService_checkClass_result__isset() : success(false) {}
  bool success :1;
} _ClientService_checkClass_result__isset;

class ClientService_checkClass_result {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};

  ClientService_checkClass_result(const ClientService_checkClass_result&);
  ClientService_checkClass_result& operator=(const ClientService_checkClass_result&);
  ClientService_checkClass_result() : success(0) {
  }

  virtual ~ClientService_checkClass_result() throw();
  bool success;

  _ClientService_checkClass_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const ClientService_checkClass_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ClientService_checkClass_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_checkClass_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkClass_result& obj);
};

typedef struct _ClientService_checkClass_presult__isset {
  _ClientService_checkClass_presult__isset() : success(false) {}
  bool success :1;
} _ClientService_checkClass_presult__isset;

class ClientService_checkClass_presult {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};


  virtual ~ClientService_checkClass_presult() throw();
  bool* success;

  _ClientService_checkClass_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkClass_presult& obj);
};

typedef struct _ClientService_checkTableClass_args__isset {
  _ClientService_checkTableClass_args__isset() : tinfo(false), credentials(false), tableId(false), className(false), interfaceMatch(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tableId :1;
  bool className :1;
  bool interfaceMatch :1;
} _ClientService_checkTableClass_args__isset;

class ClientService_checkTableClass_args {
 public:

  static const char* ascii_fingerprint; // = "37F1D69186381B01B5AD2519B82EA479";
  static const uint8_t binary_fingerprint[16]; // = {0x37,0xF1,0xD6,0x91,0x86,0x38,0x1B,0x01,0xB5,0xAD,0x25,0x19,0xB8,0x2E,0xA4,0x79};

  ClientService_checkTableClass_args(const ClientService_checkTableClass_args&);
  ClientService_checkTableClass_args& operator=(const ClientService_checkTableClass_args&);
  ClientService_checkTableClass_args() : tableId(), className(), interfaceMatch() {
  }

  virtual ~ClientService_checkTableClass_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string tableId;
  std::string className;
  std::string interfaceMatch;

  _ClientService_checkTableClass_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tableId(const std::string& val);

  void __set_className(const std::string& val);

  void __set_interfaceMatch(const std::string& val);

  bool operator == (const ClientService_checkTableClass_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tableId == rhs.tableId))
      return false;
    if (!(className == rhs.className))
      return false;
    if (!(interfaceMatch == rhs.interfaceMatch))
      return false;
    return true;
  }
  bool operator != (const ClientService_checkTableClass_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_checkTableClass_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkTableClass_args& obj);
};


class ClientService_checkTableClass_pargs {
 public:

  static const char* ascii_fingerprint; // = "37F1D69186381B01B5AD2519B82EA479";
  static const uint8_t binary_fingerprint[16]; // = {0x37,0xF1,0xD6,0x91,0x86,0x38,0x1B,0x01,0xB5,0xAD,0x25,0x19,0xB8,0x2E,0xA4,0x79};


  virtual ~ClientService_checkTableClass_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* tableId;
  const std::string* className;
  const std::string* interfaceMatch;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkTableClass_pargs& obj);
};

typedef struct _ClientService_checkTableClass_result__isset {
  _ClientService_checkTableClass_result__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_checkTableClass_result__isset;

class ClientService_checkTableClass_result {
 public:

  static const char* ascii_fingerprint; // = "B6D3A05943954654C738C4EDE5DDBC7F";
  static const uint8_t binary_fingerprint[16]; // = {0xB6,0xD3,0xA0,0x59,0x43,0x95,0x46,0x54,0xC7,0x38,0xC4,0xED,0xE5,0xDD,0xBC,0x7F};

  ClientService_checkTableClass_result(const ClientService_checkTableClass_result&);
  ClientService_checkTableClass_result& operator=(const ClientService_checkTableClass_result&);
  ClientService_checkTableClass_result() : success(0) {
  }

  virtual ~ClientService_checkTableClass_result() throw();
  bool success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_checkTableClass_result__isset __isset;

  void __set_success(const bool val);

  void __set_sec(const ThriftSecurityException& val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_checkTableClass_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_checkTableClass_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_checkTableClass_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkTableClass_result& obj);
};

typedef struct _ClientService_checkTableClass_presult__isset {
  _ClientService_checkTableClass_presult__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_checkTableClass_presult__isset;

class ClientService_checkTableClass_presult {
 public:

  static const char* ascii_fingerprint; // = "B6D3A05943954654C738C4EDE5DDBC7F";
  static const uint8_t binary_fingerprint[16]; // = {0xB6,0xD3,0xA0,0x59,0x43,0x95,0x46,0x54,0xC7,0x38,0xC4,0xED,0xE5,0xDD,0xBC,0x7F};


  virtual ~ClientService_checkTableClass_presult() throw();
  bool* success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_checkTableClass_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkTableClass_presult& obj);
};

typedef struct _ClientService_checkNamespaceClass_args__isset {
  _ClientService_checkNamespaceClass_args__isset() : tinfo(false), credentials(false), namespaceId(false), className(false), interfaceMatch(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool namespaceId :1;
  bool className :1;
  bool interfaceMatch :1;
} _ClientService_checkNamespaceClass_args__isset;

class ClientService_checkNamespaceClass_args {
 public:

  static const char* ascii_fingerprint; // = "51DD702C1B087E295681F596C52674C1";
  static const uint8_t binary_fingerprint[16]; // = {0x51,0xDD,0x70,0x2C,0x1B,0x08,0x7E,0x29,0x56,0x81,0xF5,0x96,0xC5,0x26,0x74,0xC1};

  ClientService_checkNamespaceClass_args(const ClientService_checkNamespaceClass_args&);
  ClientService_checkNamespaceClass_args& operator=(const ClientService_checkNamespaceClass_args&);
  ClientService_checkNamespaceClass_args() : namespaceId(), className(), interfaceMatch() {
  }

  virtual ~ClientService_checkNamespaceClass_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string namespaceId;
  std::string className;
  std::string interfaceMatch;

  _ClientService_checkNamespaceClass_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_namespaceId(const std::string& val);

  void __set_className(const std::string& val);

  void __set_interfaceMatch(const std::string& val);

  bool operator == (const ClientService_checkNamespaceClass_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(namespaceId == rhs.namespaceId))
      return false;
    if (!(className == rhs.className))
      return false;
    if (!(interfaceMatch == rhs.interfaceMatch))
      return false;
    return true;
  }
  bool operator != (const ClientService_checkNamespaceClass_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_checkNamespaceClass_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkNamespaceClass_args& obj);
};


class ClientService_checkNamespaceClass_pargs {
 public:

  static const char* ascii_fingerprint; // = "51DD702C1B087E295681F596C52674C1";
  static const uint8_t binary_fingerprint[16]; // = {0x51,0xDD,0x70,0x2C,0x1B,0x08,0x7E,0x29,0x56,0x81,0xF5,0x96,0xC5,0x26,0x74,0xC1};


  virtual ~ClientService_checkNamespaceClass_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* namespaceId;
  const std::string* className;
  const std::string* interfaceMatch;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkNamespaceClass_pargs& obj);
};

typedef struct _ClientService_checkNamespaceClass_result__isset {
  _ClientService_checkNamespaceClass_result__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_checkNamespaceClass_result__isset;

class ClientService_checkNamespaceClass_result {
 public:

  static const char* ascii_fingerprint; // = "B6D3A05943954654C738C4EDE5DDBC7F";
  static const uint8_t binary_fingerprint[16]; // = {0xB6,0xD3,0xA0,0x59,0x43,0x95,0x46,0x54,0xC7,0x38,0xC4,0xED,0xE5,0xDD,0xBC,0x7F};

  ClientService_checkNamespaceClass_result(const ClientService_checkNamespaceClass_result&);
  ClientService_checkNamespaceClass_result& operator=(const ClientService_checkNamespaceClass_result&);
  ClientService_checkNamespaceClass_result() : success(0) {
  }

  virtual ~ClientService_checkNamespaceClass_result() throw();
  bool success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_checkNamespaceClass_result__isset __isset;

  void __set_success(const bool val);

  void __set_sec(const ThriftSecurityException& val);

  void __set_tope(const ThriftTableOperationException& val);

  bool operator == (const ClientService_checkNamespaceClass_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    if (!(tope == rhs.tope))
      return false;
    return true;
  }
  bool operator != (const ClientService_checkNamespaceClass_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientService_checkNamespaceClass_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkNamespaceClass_result& obj);
};

typedef struct _ClientService_checkNamespaceClass_presult__isset {
  _ClientService_checkNamespaceClass_presult__isset() : success(false), sec(false), tope(false) {}
  bool success :1;
  bool sec :1;
  bool tope :1;
} _ClientService_checkNamespaceClass_presult__isset;

class ClientService_checkNamespaceClass_presult {
 public:

  static const char* ascii_fingerprint; // = "B6D3A05943954654C738C4EDE5DDBC7F";
  static const uint8_t binary_fingerprint[16]; // = {0xB6,0xD3,0xA0,0x59,0x43,0x95,0x46,0x54,0xC7,0x38,0xC4,0xED,0xE5,0xDD,0xBC,0x7F};


  virtual ~ClientService_checkNamespaceClass_presult() throw();
  bool* success;
  ThriftSecurityException sec;
  ThriftTableOperationException tope;

  _ClientService_checkNamespaceClass_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ClientService_checkNamespaceClass_presult& obj);
};

class ClientServiceClient : virtual public ClientServiceIf {
 public:
  ClientServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ClientServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void getRootTabletLocation(std::string& _return);
  void send_getRootTabletLocation();
  void recv_getRootTabletLocation(std::string& _return);
  void getInstanceId(std::string& _return);
  void send_getInstanceId();
  void recv_getInstanceId(std::string& _return);
  void getZooKeepers(std::string& _return);
  void send_getZooKeepers();
  void recv_getZooKeepers(std::string& _return);
  void bulkImportFiles(std::vector<std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t tid, const std::string& tableId, const std::vector<std::string> & files, const std::string& errorDir, const bool setTime);
  void send_bulkImportFiles(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t tid, const std::string& tableId, const std::vector<std::string> & files, const std::string& errorDir, const bool setTime);
  void recv_bulkImportFiles(std::vector<std::string> & _return);
  bool isActive(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const int64_t tid);
  void send_isActive(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const int64_t tid);
  bool recv_isActive();
  void ping(const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_ping(const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void recv_ping();
  void getDiskUsage(std::vector<TDiskUsage> & _return, const std::set<std::string> & tables, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_getDiskUsage(const std::set<std::string> & tables, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void recv_getDiskUsage(std::vector<TDiskUsage> & _return);
  void listLocalUsers(std::set<std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_listLocalUsers(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void recv_listLocalUsers(std::set<std::string> & _return);
  void createLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& password);
  void send_createLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& password);
  void recv_createLocalUser();
  void dropLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal);
  void send_dropLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal);
  void recv_dropLocalUser();
  void changeLocalUserPassword(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& password);
  void send_changeLocalUserPassword(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& password);
  void recv_changeLocalUserPassword();
  bool authenticate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_authenticate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  bool recv_authenticate();
  bool authenticateUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::security::thrift::TCredentials& toAuth);
  void send_authenticateUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::security::thrift::TCredentials& toAuth);
  bool recv_authenticateUser();
  void changeAuthorizations(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::vector<std::string> & authorizations);
  void send_changeAuthorizations(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::vector<std::string> & authorizations);
  void recv_changeAuthorizations();
  void getUserAuthorizations(std::vector<std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal);
  void send_getUserAuthorizations(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal);
  void recv_getUserAuthorizations(std::vector<std::string> & _return);
  bool hasSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t sysPerm);
  void send_hasSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t sysPerm);
  bool recv_hasSystemPermission();
  bool hasTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t tblPerm);
  void send_hasTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t tblPerm);
  bool recv_hasTablePermission();
  bool hasNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t tblNspcPerm);
  void send_hasNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t tblNspcPerm);
  bool recv_hasNamespacePermission();
  void grantSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t permission);
  void send_grantSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t permission);
  void recv_grantSystemPermission();
  void revokeSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t permission);
  void send_revokeSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t permission);
  void recv_revokeSystemPermission();
  void grantTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t permission);
  void send_grantTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t permission);
  void recv_grantTablePermission();
  void revokeTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t permission);
  void send_revokeTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t permission);
  void recv_revokeTablePermission();
  void grantNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t permission);
  void send_grantNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t permission);
  void recv_grantNamespacePermission();
  void revokeNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t permission);
  void send_revokeNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t permission);
  void recv_revokeNamespacePermission();
  void getConfiguration(std::map<std::string, std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const ConfigurationType::type type);
  void send_getConfiguration(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const ConfigurationType::type type);
  void recv_getConfiguration(std::map<std::string, std::string> & _return);
  void getTableConfiguration(std::map<std::string, std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName);
  void send_getTableConfiguration(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName);
  void recv_getTableConfiguration(std::map<std::string, std::string> & _return);
  void getNamespaceConfiguration(std::map<std::string, std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns);
  void send_getNamespaceConfiguration(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns);
  void recv_getNamespaceConfiguration(std::map<std::string, std::string> & _return);
  bool checkClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& className, const std::string& interfaceMatch);
  void send_checkClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& className, const std::string& interfaceMatch);
  bool recv_checkClass();
  bool checkTableClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableId, const std::string& className, const std::string& interfaceMatch);
  void send_checkTableClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableId, const std::string& className, const std::string& interfaceMatch);
  bool recv_checkTableClass();
  bool checkNamespaceClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& namespaceId, const std::string& className, const std::string& interfaceMatch);
  void send_checkNamespaceClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& namespaceId, const std::string& className, const std::string& interfaceMatch);
  bool recv_checkNamespaceClass();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ClientServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ClientServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ClientServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getRootTabletLocation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getInstanceId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getZooKeepers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_bulkImportFiles(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_isActive(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDiskUsage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_listLocalUsers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createLocalUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_dropLocalUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_changeLocalUserPassword(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_authenticate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_authenticateUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_changeAuthorizations(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getUserAuthorizations(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_hasSystemPermission(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_hasTablePermission(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_hasNamespacePermission(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_grantSystemPermission(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_revokeSystemPermission(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_grantTablePermission(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_revokeTablePermission(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_grantNamespacePermission(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_revokeNamespacePermission(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getConfiguration(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getTableConfiguration(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getNamespaceConfiguration(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_checkClass(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_checkTableClass(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_checkNamespaceClass(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ClientServiceProcessor(boost::shared_ptr<ClientServiceIf> iface) :
    iface_(iface) {
    processMap_["getRootTabletLocation"] = &ClientServiceProcessor::process_getRootTabletLocation;
    processMap_["getInstanceId"] = &ClientServiceProcessor::process_getInstanceId;
    processMap_["getZooKeepers"] = &ClientServiceProcessor::process_getZooKeepers;
    processMap_["bulkImportFiles"] = &ClientServiceProcessor::process_bulkImportFiles;
    processMap_["isActive"] = &ClientServiceProcessor::process_isActive;
    processMap_["ping"] = &ClientServiceProcessor::process_ping;
    processMap_["getDiskUsage"] = &ClientServiceProcessor::process_getDiskUsage;
    processMap_["listLocalUsers"] = &ClientServiceProcessor::process_listLocalUsers;
    processMap_["createLocalUser"] = &ClientServiceProcessor::process_createLocalUser;
    processMap_["dropLocalUser"] = &ClientServiceProcessor::process_dropLocalUser;
    processMap_["changeLocalUserPassword"] = &ClientServiceProcessor::process_changeLocalUserPassword;
    processMap_["authenticate"] = &ClientServiceProcessor::process_authenticate;
    processMap_["authenticateUser"] = &ClientServiceProcessor::process_authenticateUser;
    processMap_["changeAuthorizations"] = &ClientServiceProcessor::process_changeAuthorizations;
    processMap_["getUserAuthorizations"] = &ClientServiceProcessor::process_getUserAuthorizations;
    processMap_["hasSystemPermission"] = &ClientServiceProcessor::process_hasSystemPermission;
    processMap_["hasTablePermission"] = &ClientServiceProcessor::process_hasTablePermission;
    processMap_["hasNamespacePermission"] = &ClientServiceProcessor::process_hasNamespacePermission;
    processMap_["grantSystemPermission"] = &ClientServiceProcessor::process_grantSystemPermission;
    processMap_["revokeSystemPermission"] = &ClientServiceProcessor::process_revokeSystemPermission;
    processMap_["grantTablePermission"] = &ClientServiceProcessor::process_grantTablePermission;
    processMap_["revokeTablePermission"] = &ClientServiceProcessor::process_revokeTablePermission;
    processMap_["grantNamespacePermission"] = &ClientServiceProcessor::process_grantNamespacePermission;
    processMap_["revokeNamespacePermission"] = &ClientServiceProcessor::process_revokeNamespacePermission;
    processMap_["getConfiguration"] = &ClientServiceProcessor::process_getConfiguration;
    processMap_["getTableConfiguration"] = &ClientServiceProcessor::process_getTableConfiguration;
    processMap_["getNamespaceConfiguration"] = &ClientServiceProcessor::process_getNamespaceConfiguration;
    processMap_["checkClass"] = &ClientServiceProcessor::process_checkClass;
    processMap_["checkTableClass"] = &ClientServiceProcessor::process_checkTableClass;
    processMap_["checkNamespaceClass"] = &ClientServiceProcessor::process_checkNamespaceClass;
  }

  virtual ~ClientServiceProcessor() {}
};

class ClientServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ClientServiceProcessorFactory(const ::boost::shared_ptr< ClientServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ClientServiceIfFactory > handlerFactory_;
};

class ClientServiceMultiface : virtual public ClientServiceIf {
 public:
  ClientServiceMultiface(std::vector<boost::shared_ptr<ClientServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ClientServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ClientServiceIf> > ifaces_;
  ClientServiceMultiface() {}
  void add(boost::shared_ptr<ClientServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getRootTabletLocation(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getRootTabletLocation(_return);
    }
    ifaces_[i]->getRootTabletLocation(_return);
    return;
  }

  void getInstanceId(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getInstanceId(_return);
    }
    ifaces_[i]->getInstanceId(_return);
    return;
  }

  void getZooKeepers(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getZooKeepers(_return);
    }
    ifaces_[i]->getZooKeepers(_return);
    return;
  }

  void bulkImportFiles(std::vector<std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t tid, const std::string& tableId, const std::vector<std::string> & files, const std::string& errorDir, const bool setTime) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->bulkImportFiles(_return, tinfo, credentials, tid, tableId, files, errorDir, setTime);
    }
    ifaces_[i]->bulkImportFiles(_return, tinfo, credentials, tid, tableId, files, errorDir, setTime);
    return;
  }

  bool isActive(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const int64_t tid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->isActive(tinfo, tid);
    }
    return ifaces_[i]->isActive(tinfo, tid);
  }

  void ping(const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ping(credentials);
    }
    ifaces_[i]->ping(credentials);
  }

  void getDiskUsage(std::vector<TDiskUsage> & _return, const std::set<std::string> & tables, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDiskUsage(_return, tables, credentials);
    }
    ifaces_[i]->getDiskUsage(_return, tables, credentials);
    return;
  }

  void listLocalUsers(std::set<std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->listLocalUsers(_return, tinfo, credentials);
    }
    ifaces_[i]->listLocalUsers(_return, tinfo, credentials);
    return;
  }

  void createLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& password) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createLocalUser(tinfo, credentials, principal, password);
    }
    ifaces_[i]->createLocalUser(tinfo, credentials, principal, password);
  }

  void dropLocalUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->dropLocalUser(tinfo, credentials, principal);
    }
    ifaces_[i]->dropLocalUser(tinfo, credentials, principal);
  }

  void changeLocalUserPassword(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& password) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->changeLocalUserPassword(tinfo, credentials, principal, password);
    }
    ifaces_[i]->changeLocalUserPassword(tinfo, credentials, principal, password);
  }

  bool authenticate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->authenticate(tinfo, credentials);
    }
    return ifaces_[i]->authenticate(tinfo, credentials);
  }

  bool authenticateUser(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::security::thrift::TCredentials& toAuth) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->authenticateUser(tinfo, credentials, toAuth);
    }
    return ifaces_[i]->authenticateUser(tinfo, credentials, toAuth);
  }

  void changeAuthorizations(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::vector<std::string> & authorizations) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->changeAuthorizations(tinfo, credentials, principal, authorizations);
    }
    ifaces_[i]->changeAuthorizations(tinfo, credentials, principal, authorizations);
  }

  void getUserAuthorizations(std::vector<std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getUserAuthorizations(_return, tinfo, credentials, principal);
    }
    ifaces_[i]->getUserAuthorizations(_return, tinfo, credentials, principal);
    return;
  }

  bool hasSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t sysPerm) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->hasSystemPermission(tinfo, credentials, principal, sysPerm);
    }
    return ifaces_[i]->hasSystemPermission(tinfo, credentials, principal, sysPerm);
  }

  bool hasTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t tblPerm) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->hasTablePermission(tinfo, credentials, principal, tableName, tblPerm);
    }
    return ifaces_[i]->hasTablePermission(tinfo, credentials, principal, tableName, tblPerm);
  }

  bool hasNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t tblNspcPerm) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->hasNamespacePermission(tinfo, credentials, principal, ns, tblNspcPerm);
    }
    return ifaces_[i]->hasNamespacePermission(tinfo, credentials, principal, ns, tblNspcPerm);
  }

  void grantSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t permission) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->grantSystemPermission(tinfo, credentials, principal, permission);
    }
    ifaces_[i]->grantSystemPermission(tinfo, credentials, principal, permission);
  }

  void revokeSystemPermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const int8_t permission) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->revokeSystemPermission(tinfo, credentials, principal, permission);
    }
    ifaces_[i]->revokeSystemPermission(tinfo, credentials, principal, permission);
  }

  void grantTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t permission) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->grantTablePermission(tinfo, credentials, principal, tableName, permission);
    }
    ifaces_[i]->grantTablePermission(tinfo, credentials, principal, tableName, permission);
  }

  void revokeTablePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& tableName, const int8_t permission) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->revokeTablePermission(tinfo, credentials, principal, tableName, permission);
    }
    ifaces_[i]->revokeTablePermission(tinfo, credentials, principal, tableName, permission);
  }

  void grantNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t permission) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->grantNamespacePermission(tinfo, credentials, principal, ns, permission);
    }
    ifaces_[i]->grantNamespacePermission(tinfo, credentials, principal, ns, permission);
  }

  void revokeNamespacePermission(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& principal, const std::string& ns, const int8_t permission) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->revokeNamespacePermission(tinfo, credentials, principal, ns, permission);
    }
    ifaces_[i]->revokeNamespacePermission(tinfo, credentials, principal, ns, permission);
  }

  void getConfiguration(std::map<std::string, std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const ConfigurationType::type type) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getConfiguration(_return, tinfo, credentials, type);
    }
    ifaces_[i]->getConfiguration(_return, tinfo, credentials, type);
    return;
  }

  void getTableConfiguration(std::map<std::string, std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getTableConfiguration(_return, tinfo, credentials, tableName);
    }
    ifaces_[i]->getTableConfiguration(_return, tinfo, credentials, tableName);
    return;
  }

  void getNamespaceConfiguration(std::map<std::string, std::string> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& ns) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getNamespaceConfiguration(_return, tinfo, credentials, ns);
    }
    ifaces_[i]->getNamespaceConfiguration(_return, tinfo, credentials, ns);
    return;
  }

  bool checkClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& className, const std::string& interfaceMatch) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->checkClass(tinfo, credentials, className, interfaceMatch);
    }
    return ifaces_[i]->checkClass(tinfo, credentials, className, interfaceMatch);
  }

  bool checkTableClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableId, const std::string& className, const std::string& interfaceMatch) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->checkTableClass(tinfo, credentials, tableId, className, interfaceMatch);
    }
    return ifaces_[i]->checkTableClass(tinfo, credentials, tableId, className, interfaceMatch);
  }

  bool checkNamespaceClass(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& namespaceId, const std::string& className, const std::string& interfaceMatch) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->checkNamespaceClass(tinfo, credentials, namespaceId, className, interfaceMatch);
    }
    return ifaces_[i]->checkNamespaceClass(tinfo, credentials, namespaceId, className, interfaceMatch);
  }

};

}}}}}}} // namespace

#endif
