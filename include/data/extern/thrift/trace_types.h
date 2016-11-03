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
#ifndef trace_TYPES_H
#define trace_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace org { namespace apache { namespace accumulo { namespace trace { namespace thrift {

class RemoteSpan;

class TInfo;

typedef struct _RemoteSpan__isset {
  _RemoteSpan__isset() : sender(false), svc(false), traceId(false), spanId(false), parentId(false), start(false), stop(false), description(false), data(false) {}
  bool sender :1;
  bool svc :1;
  bool traceId :1;
  bool spanId :1;
  bool parentId :1;
  bool start :1;
  bool stop :1;
  bool description :1;
  bool data :1;
} _RemoteSpan__isset;

class RemoteSpan {
 public:

  static const char* ascii_fingerprint; // = "22EA46E738FDCE7962363D25AEC46FDF";
  static const uint8_t binary_fingerprint[16]; // = {0x22,0xEA,0x46,0xE7,0x38,0xFD,0xCE,0x79,0x62,0x36,0x3D,0x25,0xAE,0xC4,0x6F,0xDF};

  RemoteSpan(const RemoteSpan&);
  RemoteSpan& operator=(const RemoteSpan&);
  RemoteSpan() : sender(), svc(), traceId(0), spanId(0), parentId(0), start(0), stop(0), description() {
  }

  virtual ~RemoteSpan() throw();
  std::string sender;
  std::string svc;
  int64_t traceId;
  int64_t spanId;
  int64_t parentId;
  int64_t start;
  int64_t stop;
  std::string description;
  std::map<std::string, std::string>  data;

  _RemoteSpan__isset __isset;

  void __set_sender(const std::string& val);

  void __set_svc(const std::string& val);

  void __set_traceId(const int64_t val);

  void __set_spanId(const int64_t val);

  void __set_parentId(const int64_t val);

  void __set_start(const int64_t val);

  void __set_stop(const int64_t val);

  void __set_description(const std::string& val);

  void __set_data(const std::map<std::string, std::string> & val);

  bool operator == (const RemoteSpan & rhs) const
  {
    if (!(sender == rhs.sender))
      return false;
    if (!(svc == rhs.svc))
      return false;
    if (!(traceId == rhs.traceId))
      return false;
    if (!(spanId == rhs.spanId))
      return false;
    if (!(parentId == rhs.parentId))
      return false;
    if (!(start == rhs.start))
      return false;
    if (!(stop == rhs.stop))
      return false;
    if (!(description == rhs.description))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const RemoteSpan &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RemoteSpan & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const RemoteSpan& obj);
};

void swap(RemoteSpan &a, RemoteSpan &b);

typedef struct _TInfo__isset {
  _TInfo__isset() : traceId(false), parentId(false) {}
  bool traceId :1;
  bool parentId :1;
} _TInfo__isset;

class TInfo {
 public:

  static const char* ascii_fingerprint; // = "F33135321253DAEB67B0E79E416CA831";
  static const uint8_t binary_fingerprint[16]; // = {0xF3,0x31,0x35,0x32,0x12,0x53,0xDA,0xEB,0x67,0xB0,0xE7,0x9E,0x41,0x6C,0xA8,0x31};

  TInfo(const TInfo&);
  TInfo& operator=(const TInfo&);
  TInfo() : traceId(0), parentId(0) {
  }

  virtual ~TInfo() throw();
  int64_t traceId;
  int64_t parentId;

  _TInfo__isset __isset;

  void __set_traceId(const int64_t val);

  void __set_parentId(const int64_t val);

  bool operator == (const TInfo & rhs) const
  {
    if (!(traceId == rhs.traceId))
      return false;
    if (!(parentId == rhs.parentId))
      return false;
    return true;
  }
  bool operator != (const TInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TInfo& obj);
};

void swap(TInfo &a, TInfo &b);

}}}}} // namespace

#endif
