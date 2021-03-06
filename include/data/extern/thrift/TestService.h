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
#ifndef TestService_H
#define TestService_H

#include <thrift/TDispatchProcessor.h>
#include "trace_types.h"

namespace org { namespace apache { namespace accumulo { namespace trace { namespace thrift {

class TestServiceIf {
 public:
  virtual ~TestServiceIf() {}
  virtual bool checkTrace(const TInfo& tinfo, const std::string& message) = 0;
};

class TestServiceIfFactory {
 public:
  typedef TestServiceIf Handler;

  virtual ~TestServiceIfFactory() {}

  virtual TestServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(TestServiceIf* /* handler */) = 0;
};

class TestServiceIfSingletonFactory : virtual public TestServiceIfFactory {
 public:
  TestServiceIfSingletonFactory(const boost::shared_ptr<TestServiceIf>& iface) : iface_(iface) {}
  virtual ~TestServiceIfSingletonFactory() {}

  virtual TestServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(TestServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<TestServiceIf> iface_;
};

class TestServiceNull : virtual public TestServiceIf {
 public:
  virtual ~TestServiceNull() {}
  bool checkTrace(const TInfo& /* tinfo */, const std::string& /* message */) {
    bool _return = false;
    return _return;
  }
};

typedef struct _TestService_checkTrace_args__isset {
  _TestService_checkTrace_args__isset() : tinfo(false), message(false) {}
  bool tinfo :1;
  bool message :1;
} _TestService_checkTrace_args__isset;

class TestService_checkTrace_args {
 public:

  static const char* ascii_fingerprint; // = "1D564333962EFF033097D9C483012CF2";
  static const uint8_t binary_fingerprint[16]; // = {0x1D,0x56,0x43,0x33,0x96,0x2E,0xFF,0x03,0x30,0x97,0xD9,0xC4,0x83,0x01,0x2C,0xF2};

  TestService_checkTrace_args(const TestService_checkTrace_args&);
  TestService_checkTrace_args& operator=(const TestService_checkTrace_args&);
  TestService_checkTrace_args() : message() {
  }

  virtual ~TestService_checkTrace_args() throw();
  TInfo tinfo;
  std::string message;

  _TestService_checkTrace_args__isset __isset;

  void __set_tinfo(const TInfo& val);

  void __set_message(const std::string& val);

  bool operator == (const TestService_checkTrace_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const TestService_checkTrace_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TestService_checkTrace_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TestService_checkTrace_args& obj);
};


class TestService_checkTrace_pargs {
 public:

  static const char* ascii_fingerprint; // = "1D564333962EFF033097D9C483012CF2";
  static const uint8_t binary_fingerprint[16]; // = {0x1D,0x56,0x43,0x33,0x96,0x2E,0xFF,0x03,0x30,0x97,0xD9,0xC4,0x83,0x01,0x2C,0xF2};


  virtual ~TestService_checkTrace_pargs() throw();
  const TInfo* tinfo;
  const std::string* message;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TestService_checkTrace_pargs& obj);
};

typedef struct _TestService_checkTrace_result__isset {
  _TestService_checkTrace_result__isset() : success(false) {}
  bool success :1;
} _TestService_checkTrace_result__isset;

class TestService_checkTrace_result {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};

  TestService_checkTrace_result(const TestService_checkTrace_result&);
  TestService_checkTrace_result& operator=(const TestService_checkTrace_result&);
  TestService_checkTrace_result() : success(0) {
  }

  virtual ~TestService_checkTrace_result() throw();
  bool success;

  _TestService_checkTrace_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const TestService_checkTrace_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TestService_checkTrace_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TestService_checkTrace_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TestService_checkTrace_result& obj);
};

typedef struct _TestService_checkTrace_presult__isset {
  _TestService_checkTrace_presult__isset() : success(false) {}
  bool success :1;
} _TestService_checkTrace_presult__isset;

class TestService_checkTrace_presult {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};


  virtual ~TestService_checkTrace_presult() throw();
  bool* success;

  _TestService_checkTrace_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TestService_checkTrace_presult& obj);
};

class TestServiceClient : virtual public TestServiceIf {
 public:
  TestServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  TestServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  bool checkTrace(const TInfo& tinfo, const std::string& message);
  void send_checkTrace(const TInfo& tinfo, const std::string& message);
  bool recv_checkTrace();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class TestServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<TestServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TestServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_checkTrace(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  TestServiceProcessor(boost::shared_ptr<TestServiceIf> iface) :
    iface_(iface) {
    processMap_["checkTrace"] = &TestServiceProcessor::process_checkTrace;
  }

  virtual ~TestServiceProcessor() {}
};

class TestServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TestServiceProcessorFactory(const ::boost::shared_ptr< TestServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< TestServiceIfFactory > handlerFactory_;
};

class TestServiceMultiface : virtual public TestServiceIf {
 public:
  TestServiceMultiface(std::vector<boost::shared_ptr<TestServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~TestServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<TestServiceIf> > ifaces_;
  TestServiceMultiface() {}
  void add(boost::shared_ptr<TestServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  bool checkTrace(const TInfo& tinfo, const std::string& message) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->checkTrace(tinfo, message);
    }
    return ifaces_[i]->checkTrace(tinfo, message);
  }

};

}}}}} // namespace

#endif
