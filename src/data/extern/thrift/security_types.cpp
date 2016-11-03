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
#include "../../../../include/data/extern/thrift/security_types.h"

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
	namespace security
	{
	  namespace thrift
	  {

	    TCredentials::~TCredentials () throw ()
	    {
	    }

	    void
	    TCredentials::__set_principal (const std::string& val)
	    {
	      this->principal = val;
	    }

	    void
	    TCredentials::__set_tokenClassName (const std::string& val)
	    {
	      this->tokenClassName = val;
	    }

	    void
	    TCredentials::__set_token (const std::string& val)
	    {
	      this->token = val;
	    }

	    void
	    TCredentials::__set_instanceId (const std::string& val)
	    {
	      this->instanceId = val;
	    }

	    const char* TCredentials::ascii_fingerprint =
		"C93D890311F28844166CF6E571EB3AC2";
	    const uint8_t TCredentials::binary_fingerprint[16] =
	      { 0xC9, 0x3D, 0x89, 0x03, 0x11, 0xF2, 0x88, 0x44, 0x16, 0x6C,
		  0xF6, 0xE5, 0x71, 0xEB, 0x3A, 0xC2 };

	    uint32_t
	    TCredentials::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readString (this->principal);
			  this->__isset.principal = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tokenClassName);
			  this->__isset.tokenClassName = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->token);
			  this->__isset.token = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->instanceId);
			  this->__isset.instanceId = true;
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
	    TCredentials::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TCredentials");

	      xfer += oprot->writeFieldBegin (
		  "principal", ::apache::thrift::protocol::T_STRING, 1);
	      xfer += oprot->writeString (this->principal);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tokenClassName", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->tokenClassName);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "token", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeBinary (this->token);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "instanceId", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString (this->instanceId);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TCredentials &a, TCredentials &b)
	    {
	      using ::std::swap;
	      swap (a.principal, b.principal);
	      swap (a.tokenClassName, b.tokenClassName);
	      swap (a.token, b.token);
	      swap (a.instanceId, b.instanceId);
	      swap (a.__isset, b.__isset);
	    }

	    TCredentials::TCredentials (const TCredentials& other0)
	    {
	      principal = other0.principal;
	      tokenClassName = other0.tokenClassName;
	      token = other0.token;
	      instanceId = other0.instanceId;
	      __isset = other0.__isset;
	    }
	    TCredentials&
	    TCredentials::operator= (const TCredentials& other1)
	    {
	      principal = other1.principal;
	      tokenClassName = other1.tokenClassName;
	      token = other1.token;
	      instanceId = other1.instanceId;
	      __isset = other1.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TCredentials& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TCredentials(";
	      out << "principal=" << to_string (obj.principal);
	      out << ", " << "tokenClassName="
		  << to_string (obj.tokenClassName);
	      out << ", " << "token=" << to_string (obj.token);
	      out << ", " << "instanceId=" << to_string (obj.instanceId);
	      out << ")";
	      return out;
	    }

	  }
	}
      }
    }
  }
} // namespace
