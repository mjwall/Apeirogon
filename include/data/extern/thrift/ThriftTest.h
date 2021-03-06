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
#ifndef ThriftTest_H
#define ThriftTest_H

#include <thrift/TDispatchProcessor.h>
#include "client_types.h"

namespace org { namespace apache { namespace accumulo { namespace core { namespace client { namespace impl { namespace thrift {

class ThriftTestIf {
 public:
  virtual ~ThriftTestIf() {}
  virtual bool success() = 0;
  virtual bool fails() = 0;
  virtual bool throwsError() = 0;
};

class ThriftTestIfFactory {
 public:
  typedef ThriftTestIf Handler;

  virtual ~ThriftTestIfFactory() {}

  virtual ThriftTestIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ThriftTestIf* /* handler */) = 0;
};

class ThriftTestIfSingletonFactory : virtual public ThriftTestIfFactory {
 public:
  ThriftTestIfSingletonFactory(const boost::shared_ptr<ThriftTestIf>& iface) : iface_(iface) {}
  virtual ~ThriftTestIfSingletonFactory() {}

  virtual ThriftTestIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ThriftTestIf* /* handler */) {}

 protected:
  boost::shared_ptr<ThriftTestIf> iface_;
};

class ThriftTestNull : virtual public ThriftTestIf {
 public:
  virtual ~ThriftTestNull() {}
  bool success() {
    bool _return = false;
    return _return;
  }
  bool fails() {
    bool _return = false;
    return _return;
  }
  bool throwsError() {
    bool _return = false;
    return _return;
  }
};


class ThriftTest_success_args {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  ThriftTest_success_args(const ThriftTest_success_args&);
  ThriftTest_success_args& operator=(const ThriftTest_success_args&);
  ThriftTest_success_args() {
  }

  virtual ~ThriftTest_success_args() throw();

  bool operator == (const ThriftTest_success_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ThriftTest_success_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftTest_success_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_success_args& obj);
};


class ThriftTest_success_pargs {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~ThriftTest_success_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_success_pargs& obj);
};

typedef struct _ThriftTest_success_result__isset {
  _ThriftTest_success_result__isset() : success(false) {}
  bool success :1;
} _ThriftTest_success_result__isset;

class ThriftTest_success_result {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};

  ThriftTest_success_result(const ThriftTest_success_result&);
  ThriftTest_success_result& operator=(const ThriftTest_success_result&);
  ThriftTest_success_result() : success(0) {
  }

  virtual ~ThriftTest_success_result() throw();
  bool success;

  _ThriftTest_success_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const ThriftTest_success_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ThriftTest_success_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftTest_success_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_success_result& obj);
};

typedef struct _ThriftTest_success_presult__isset {
  _ThriftTest_success_presult__isset() : success(false) {}
  bool success :1;
} _ThriftTest_success_presult__isset;

class ThriftTest_success_presult {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};


  virtual ~ThriftTest_success_presult() throw();
  bool* success;

  _ThriftTest_success_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_success_presult& obj);
};


class ThriftTest_fails_args {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  ThriftTest_fails_args(const ThriftTest_fails_args&);
  ThriftTest_fails_args& operator=(const ThriftTest_fails_args&);
  ThriftTest_fails_args() {
  }

  virtual ~ThriftTest_fails_args() throw();

  bool operator == (const ThriftTest_fails_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ThriftTest_fails_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftTest_fails_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_fails_args& obj);
};


class ThriftTest_fails_pargs {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~ThriftTest_fails_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_fails_pargs& obj);
};

typedef struct _ThriftTest_fails_result__isset {
  _ThriftTest_fails_result__isset() : success(false) {}
  bool success :1;
} _ThriftTest_fails_result__isset;

class ThriftTest_fails_result {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};

  ThriftTest_fails_result(const ThriftTest_fails_result&);
  ThriftTest_fails_result& operator=(const ThriftTest_fails_result&);
  ThriftTest_fails_result() : success(0) {
  }

  virtual ~ThriftTest_fails_result() throw();
  bool success;

  _ThriftTest_fails_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const ThriftTest_fails_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ThriftTest_fails_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftTest_fails_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_fails_result& obj);
};

typedef struct _ThriftTest_fails_presult__isset {
  _ThriftTest_fails_presult__isset() : success(false) {}
  bool success :1;
} _ThriftTest_fails_presult__isset;

class ThriftTest_fails_presult {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};


  virtual ~ThriftTest_fails_presult() throw();
  bool* success;

  _ThriftTest_fails_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_fails_presult& obj);
};


class ThriftTest_throwsError_args {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  ThriftTest_throwsError_args(const ThriftTest_throwsError_args&);
  ThriftTest_throwsError_args& operator=(const ThriftTest_throwsError_args&);
  ThriftTest_throwsError_args() {
  }

  virtual ~ThriftTest_throwsError_args() throw();

  bool operator == (const ThriftTest_throwsError_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ThriftTest_throwsError_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftTest_throwsError_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_throwsError_args& obj);
};


class ThriftTest_throwsError_pargs {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~ThriftTest_throwsError_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_throwsError_pargs& obj);
};

typedef struct _ThriftTest_throwsError_result__isset {
  _ThriftTest_throwsError_result__isset() : success(false), ex(false) {}
  bool success :1;
  bool ex :1;
} _ThriftTest_throwsError_result__isset;

class ThriftTest_throwsError_result {
 public:

  static const char* ascii_fingerprint; // = "5EDC6F0B20DD5234A1A92CD963B01402";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0xDC,0x6F,0x0B,0x20,0xDD,0x52,0x34,0xA1,0xA9,0x2C,0xD9,0x63,0xB0,0x14,0x02};

  ThriftTest_throwsError_result(const ThriftTest_throwsError_result&);
  ThriftTest_throwsError_result& operator=(const ThriftTest_throwsError_result&);
  ThriftTest_throwsError_result() : success(0) {
  }

  virtual ~ThriftTest_throwsError_result() throw();
  bool success;
  ThriftSecurityException ex;

  _ThriftTest_throwsError_result__isset __isset;

  void __set_success(const bool val);

  void __set_ex(const ThriftSecurityException& val);

  bool operator == (const ThriftTest_throwsError_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ex == rhs.ex))
      return false;
    return true;
  }
  bool operator != (const ThriftTest_throwsError_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftTest_throwsError_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_throwsError_result& obj);
};

typedef struct _ThriftTest_throwsError_presult__isset {
  _ThriftTest_throwsError_presult__isset() : success(false), ex(false) {}
  bool success :1;
  bool ex :1;
} _ThriftTest_throwsError_presult__isset;

class ThriftTest_throwsError_presult {
 public:

  static const char* ascii_fingerprint; // = "5EDC6F0B20DD5234A1A92CD963B01402";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0xDC,0x6F,0x0B,0x20,0xDD,0x52,0x34,0xA1,0xA9,0x2C,0xD9,0x63,0xB0,0x14,0x02};


  virtual ~ThriftTest_throwsError_presult() throw();
  bool* success;
  ThriftSecurityException ex;

  _ThriftTest_throwsError_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const ThriftTest_throwsError_presult& obj);
};

class ThriftTestClient : virtual public ThriftTestIf {
 public:
  ThriftTestClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ThriftTestClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  bool success();
  void send_success();
  bool recv_success();
  bool fails();
  void send_fails();
  bool recv_fails();
  bool throwsError();
  void send_throwsError();
  bool recv_throwsError();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ThriftTestProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ThriftTestIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ThriftTestProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_success(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_fails(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_throwsError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ThriftTestProcessor(boost::shared_ptr<ThriftTestIf> iface) :
    iface_(iface) {
    processMap_["success"] = &ThriftTestProcessor::process_success;
    processMap_["fails"] = &ThriftTestProcessor::process_fails;
    processMap_["throwsError"] = &ThriftTestProcessor::process_throwsError;
  }

  virtual ~ThriftTestProcessor() {}
};

class ThriftTestProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ThriftTestProcessorFactory(const ::boost::shared_ptr< ThriftTestIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ThriftTestIfFactory > handlerFactory_;
};

class ThriftTestMultiface : virtual public ThriftTestIf {
 public:
  ThriftTestMultiface(std::vector<boost::shared_ptr<ThriftTestIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ThriftTestMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ThriftTestIf> > ifaces_;
  ThriftTestMultiface() {}
  void add(boost::shared_ptr<ThriftTestIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  bool success() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->success();
    }
    return ifaces_[i]->success();
  }

  bool fails() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->fails();
    }
    return ifaces_[i]->fails();
  }

  bool throwsError() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->throwsError();
    }
    return ifaces_[i]->throwsError();
  }

};

}}}}}}} // namespace

#endif
