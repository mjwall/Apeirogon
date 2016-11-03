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
#ifndef security_TYPES_H
#define security_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace org { namespace apache { namespace accumulo { namespace core { namespace security { namespace thrift {

class TCredentials;

typedef struct _TCredentials__isset {
  _TCredentials__isset() : principal(false), tokenClassName(false), token(false), instanceId(false) {}
  bool principal :1;
  bool tokenClassName :1;
  bool token :1;
  bool instanceId :1;
} _TCredentials__isset;

class TCredentials {
 public:

  static const char* ascii_fingerprint; // = "C93D890311F28844166CF6E571EB3AC2";
  static const uint8_t binary_fingerprint[16]; // = {0xC9,0x3D,0x89,0x03,0x11,0xF2,0x88,0x44,0x16,0x6C,0xF6,0xE5,0x71,0xEB,0x3A,0xC2};

  TCredentials(const TCredentials&);
  TCredentials& operator=(const TCredentials&);
  TCredentials() : principal(), tokenClassName(), token(), instanceId() {
  }

  virtual ~TCredentials() throw();
  std::string principal;
  std::string tokenClassName;
  std::string token;
  std::string instanceId;

  _TCredentials__isset __isset;

  void __set_principal(const std::string& val);

  void __set_tokenClassName(const std::string& val);

  void __set_token(const std::string& val);

  void __set_instanceId(const std::string& val);

  bool operator == (const TCredentials & rhs) const
  {
    if (!(principal == rhs.principal))
      return false;
    if (!(tokenClassName == rhs.tokenClassName))
      return false;
    if (!(token == rhs.token))
      return false;
    if (!(instanceId == rhs.instanceId))
      return false;
    return true;
  }
  bool operator != (const TCredentials &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TCredentials & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TCredentials& obj);
};

void swap(TCredentials &a, TCredentials &b);

}}}}}} // namespace

#endif
