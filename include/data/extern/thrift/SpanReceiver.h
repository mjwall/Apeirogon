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
#ifndef SpanReceiver_H
#define SpanReceiver_H

#include <thrift/TDispatchProcessor.h>
#include "trace_types.h"

namespace org { namespace apache { namespace accumulo { namespace trace { namespace thrift {

class SpanReceiverIf {
 public:
  virtual ~SpanReceiverIf() {}
  virtual void span(const RemoteSpan& span) = 0;
};

class SpanReceiverIfFactory {
 public:
  typedef SpanReceiverIf Handler;

  virtual ~SpanReceiverIfFactory() {}

  virtual SpanReceiverIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(SpanReceiverIf* /* handler */) = 0;
};

class SpanReceiverIfSingletonFactory : virtual public SpanReceiverIfFactory {
 public:
  SpanReceiverIfSingletonFactory(const boost::shared_ptr<SpanReceiverIf>& iface) : iface_(iface) {}
  virtual ~SpanReceiverIfSingletonFactory() {}

  virtual SpanReceiverIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(SpanReceiverIf* /* handler */) {}

 protected:
  boost::shared_ptr<SpanReceiverIf> iface_;
};

class SpanReceiverNull : virtual public SpanReceiverIf {
 public:
  virtual ~SpanReceiverNull() {}
  void span(const RemoteSpan& /* span */) {
    return;
  }
};

typedef struct _SpanReceiver_span_args__isset {
  _SpanReceiver_span_args__isset() : span(false) {}
  bool span :1;
} _SpanReceiver_span_args__isset;

class SpanReceiver_span_args {
 public:

  static const char* ascii_fingerprint; // = "3BB066FB2F11325A4E08B2B862DA3C44";
  static const uint8_t binary_fingerprint[16]; // = {0x3B,0xB0,0x66,0xFB,0x2F,0x11,0x32,0x5A,0x4E,0x08,0xB2,0xB8,0x62,0xDA,0x3C,0x44};

  SpanReceiver_span_args(const SpanReceiver_span_args&);
  SpanReceiver_span_args& operator=(const SpanReceiver_span_args&);
  SpanReceiver_span_args() {
  }

  virtual ~SpanReceiver_span_args() throw();
  RemoteSpan span;

  _SpanReceiver_span_args__isset __isset;

  void __set_span(const RemoteSpan& val);

  bool operator == (const SpanReceiver_span_args & rhs) const
  {
    if (!(span == rhs.span))
      return false;
    return true;
  }
  bool operator != (const SpanReceiver_span_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SpanReceiver_span_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const SpanReceiver_span_args& obj);
};


class SpanReceiver_span_pargs {
 public:

  static const char* ascii_fingerprint; // = "3BB066FB2F11325A4E08B2B862DA3C44";
  static const uint8_t binary_fingerprint[16]; // = {0x3B,0xB0,0x66,0xFB,0x2F,0x11,0x32,0x5A,0x4E,0x08,0xB2,0xB8,0x62,0xDA,0x3C,0x44};


  virtual ~SpanReceiver_span_pargs() throw();
  const RemoteSpan* span;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const SpanReceiver_span_pargs& obj);
};

class SpanReceiverClient : virtual public SpanReceiverIf {
 public:
  SpanReceiverClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SpanReceiverClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void span(const RemoteSpan& span);
  void send_span(const RemoteSpan& span);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class SpanReceiverProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<SpanReceiverIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (SpanReceiverProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_span(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  SpanReceiverProcessor(boost::shared_ptr<SpanReceiverIf> iface) :
    iface_(iface) {
    processMap_["span"] = &SpanReceiverProcessor::process_span;
  }

  virtual ~SpanReceiverProcessor() {}
};

class SpanReceiverProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  SpanReceiverProcessorFactory(const ::boost::shared_ptr< SpanReceiverIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< SpanReceiverIfFactory > handlerFactory_;
};

class SpanReceiverMultiface : virtual public SpanReceiverIf {
 public:
  SpanReceiverMultiface(std::vector<boost::shared_ptr<SpanReceiverIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SpanReceiverMultiface() {}
 protected:
  std::vector<boost::shared_ptr<SpanReceiverIf> > ifaces_;
  SpanReceiverMultiface() {}
  void add(boost::shared_ptr<SpanReceiverIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void span(const RemoteSpan& span) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->span(span);
    }
    ifaces_[i]->span(span);
  }

};

}}}}} // namespace

#endif
