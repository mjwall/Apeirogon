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
#include "../../../../include/data/extern/thrift/TabletClientService.h"

namespace org
{
  namespace apache
  {
    namespace accumulo
    {
      namespace core
      {
	namespace tabletserver
	{
	  namespace thrift
	  {

	    TabletClientService_startScan_args::~TabletClientService_startScan_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startScan_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 11:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->extent.read (iprot);
			  this->__isset.extent = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->range.read (iprot);
			  this->__isset.range = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->columns.clear ();
			      uint32_t _size106;
			      ::apache::thrift::protocol::TType _etype109;
			      xfer += iprot->readListBegin (_etype109,
							    _size106);
			      this->columns.resize (_size106);
			      uint32_t _i110;
			      for (_i110 = 0; _i110 < _size106; ++_i110)
				{
				  xfer += this->columns[_i110].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.columns = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->batchSize);
			  this->__isset.batchSize = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->ssiList.clear ();
			      uint32_t _size111;
			      ::apache::thrift::protocol::TType _etype114;
			      xfer += iprot->readListBegin (_etype114,
							    _size111);
			      this->ssiList.resize (_size111);
			      uint32_t _i115;
			      for (_i115 = 0; _i115 < _size111; ++_i115)
				{
				  xfer += this->ssiList[_i115].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.ssiList = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->ssio.clear ();
			      uint32_t _size116;
			      ::apache::thrift::protocol::TType _ktype117;
			      ::apache::thrift::protocol::TType _vtype118;
			      xfer += iprot->readMapBegin (_ktype117, _vtype118,
							   _size116);
			      uint32_t _i120;
			      for (_i120 = 0; _i120 < _size116; ++_i120)
				{
				  std::string _key121;
				  xfer += iprot->readString (_key121);
				  std::map<std::string, std::string> & _val122 =
				      this->ssio[_key121];
				    {
				      _val122.clear ();
				      uint32_t _size123;
				      ::apache::thrift::protocol::TType _ktype124;
				      ::apache::thrift::protocol::TType _vtype125;
				      xfer += iprot->readMapBegin (_ktype124,
								   _vtype125,
								   _size123);
				      uint32_t _i127;
				      for (_i127 = 0; _i127 < _size123; ++_i127)
					{
					  std::string _key128;
					  xfer += iprot->readString (_key128);
					  std::string& _val129 =
					      _val122[_key128];
					  xfer += iprot->readString (_val129);
					}
				      xfer += iprot->readMapEnd ();
				    }
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.ssio = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 8:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->authorizations.clear ();
			      uint32_t _size130;
			      ::apache::thrift::protocol::TType _etype133;
			      xfer += iprot->readListBegin (_etype133,
							    _size130);
			      this->authorizations.resize (_size130);
			      uint32_t _i134;
			      for (_i134 = 0; _i134 < _size130; ++_i134)
				{
				  xfer += iprot->readBinary (
				      this->authorizations[_i134]);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.authorizations = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 9:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->waitForWrites);
			  this->__isset.waitForWrites = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 10:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->isolated);
			  this->__isset.isolated = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 12:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->readaheadThreshold);
			  this->__isset.readaheadThreshold = true;
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
	    TabletClientService_startScan_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startScan_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "range", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->range.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "columns", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->columns.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::TColumn>::const_iterator _iter135;
		  for (_iter135 = this->columns.begin ();
		      _iter135 != this->columns.end (); ++_iter135)
		    {
		      xfer += (*_iter135).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("batchSize",
					      ::apache::thrift::protocol::T_I32,
					      5);
	      xfer += oprot->writeI32 (this->batchSize);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ssiList", ::apache::thrift::protocol::T_LIST, 6);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->ssiList.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::IterInfo>::const_iterator _iter136;
		  for (_iter136 = this->ssiList.begin ();
		      _iter136 != this->ssiList.end (); ++_iter136)
		    {
		      xfer += (*_iter136).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("ssio",
					      ::apache::thrift::protocol::T_MAP,
					      7);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_MAP,
		      static_cast<uint32_t> (this->ssio.size ()));
		  std::map<std::string, std::map<std::string, std::string> >::const_iterator _iter137;
		  for (_iter137 = this->ssio.begin ();
		      _iter137 != this->ssio.end (); ++_iter137)
		    {
		      xfer += oprot->writeString (_iter137->first);
			{
			  xfer += oprot->writeMapBegin (
			      ::apache::thrift::protocol::T_STRING,
			      ::apache::thrift::protocol::T_STRING,
			      static_cast<uint32_t> (_iter137->second.size ()));
			  std::map<std::string, std::string>::const_iterator _iter138;
			  for (_iter138 = _iter137->second.begin ();
			      _iter138 != _iter137->second.end (); ++_iter138)
			    {
			      xfer += oprot->writeString (_iter138->first);
			      xfer += oprot->writeString (_iter138->second);
			    }
			  xfer += oprot->writeMapEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "authorizations", ::apache::thrift::protocol::T_LIST, 8);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->authorizations.size ()));
		  std::vector<std::string>::const_iterator _iter139;
		  for (_iter139 = this->authorizations.begin ();
		      _iter139 != this->authorizations.end (); ++_iter139)
		    {
		      xfer += oprot->writeBinary ((*_iter139));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "waitForWrites", ::apache::thrift::protocol::T_BOOL, 9);
	      xfer += oprot->writeBool (this->waitForWrites);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "isolated", ::apache::thrift::protocol::T_BOOL, 10);
	      xfer += oprot->writeBool (this->isolated);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 11);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("readaheadThreshold",
					      ::apache::thrift::protocol::T_I64,
					      12);
	      xfer += oprot->writeI64 (this->readaheadThreshold);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_startScan_pargs::~TabletClientService_startScan_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startScan_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startScan_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->extent)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "range", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->range)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "columns", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> ((*(this->columns)).size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::TColumn>::const_iterator _iter140;
		  for (_iter140 = (*(this->columns)).begin ();
		      _iter140 != (*(this->columns)).end (); ++_iter140)
		    {
		      xfer += (*_iter140).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("batchSize",
					      ::apache::thrift::protocol::T_I32,
					      5);
	      xfer += oprot->writeI32 ((*(this->batchSize)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ssiList", ::apache::thrift::protocol::T_LIST, 6);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> ((*(this->ssiList)).size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::IterInfo>::const_iterator _iter141;
		  for (_iter141 = (*(this->ssiList)).begin ();
		      _iter141 != (*(this->ssiList)).end (); ++_iter141)
		    {
		      xfer += (*_iter141).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("ssio",
					      ::apache::thrift::protocol::T_MAP,
					      7);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_MAP,
		      static_cast<uint32_t> ((*(this->ssio)).size ()));
		  std::map<std::string, std::map<std::string, std::string> >::const_iterator _iter142;
		  for (_iter142 = (*(this->ssio)).begin ();
		      _iter142 != (*(this->ssio)).end (); ++_iter142)
		    {
		      xfer += oprot->writeString (_iter142->first);
			{
			  xfer += oprot->writeMapBegin (
			      ::apache::thrift::protocol::T_STRING,
			      ::apache::thrift::protocol::T_STRING,
			      static_cast<uint32_t> (_iter142->second.size ()));
			  std::map<std::string, std::string>::const_iterator _iter143;
			  for (_iter143 = _iter142->second.begin ();
			      _iter143 != _iter142->second.end (); ++_iter143)
			    {
			      xfer += oprot->writeString (_iter143->first);
			      xfer += oprot->writeString (_iter143->second);
			    }
			  xfer += oprot->writeMapEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "authorizations", ::apache::thrift::protocol::T_LIST, 8);
		{
		  xfer +=
		      oprot->writeListBegin (
			  ::apache::thrift::protocol::T_STRING,
			  static_cast<uint32_t> ((*(this->authorizations)).size ()));
		  std::vector<std::string>::const_iterator _iter144;
		  for (_iter144 = (*(this->authorizations)).begin ();
		      _iter144 != (*(this->authorizations)).end (); ++_iter144)
		    {
		      xfer += oprot->writeBinary ((*_iter144));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "waitForWrites", ::apache::thrift::protocol::T_BOOL, 9);
	      xfer += oprot->writeBool ((*(this->waitForWrites)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "isolated", ::apache::thrift::protocol::T_BOOL, 10);
	      xfer += oprot->writeBool ((*(this->isolated)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 11);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("readaheadThreshold",
					      ::apache::thrift::protocol::T_I64,
					      12);
	      xfer += oprot->writeI64 ((*(this->readaheadThreshold)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_startScan_result::~TabletClientService_startScan_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startScan_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->success.read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nste.read (iprot);
			  this->__isset.nste = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tmfe.read (iprot);
			  this->__isset.tmfe = true;
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
	    TabletClientService_startScan_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startScan_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRUCT, 0);
		  xfer += this->success.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.nste)
		{
		  xfer += oprot->writeFieldBegin (
		      "nste", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->nste.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.tmfe)
		{
		  xfer += oprot->writeFieldBegin (
		      "tmfe", ::apache::thrift::protocol::T_STRUCT, 3);
		  xfer += this->tmfe.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_startScan_presult::~TabletClientService_startScan_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startScan_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += (*(this->success)).read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nste.read (iprot);
			  this->__isset.nste = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tmfe.read (iprot);
			  this->__isset.tmfe = true;
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

	    TabletClientService_continueScan_args::~TabletClientService_continueScan_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_continueScan_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->scanID);
			  this->__isset.scanID = true;
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
	    TabletClientService_continueScan_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_continueScan_args");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->scanID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_continueScan_pargs::~TabletClientService_continueScan_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_continueScan_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_continueScan_pargs");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 ((*(this->scanID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_continueScan_result::~TabletClientService_continueScan_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_continueScan_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->success.read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nste.read (iprot);
			  this->__isset.nste = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tmfe.read (iprot);
			  this->__isset.tmfe = true;
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
	    TabletClientService_continueScan_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_continueScan_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRUCT, 0);
		  xfer += this->success.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.nssi)
		{
		  xfer += oprot->writeFieldBegin (
		      "nssi", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->nssi.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.nste)
		{
		  xfer += oprot->writeFieldBegin (
		      "nste", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->nste.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.tmfe)
		{
		  xfer += oprot->writeFieldBegin (
		      "tmfe", ::apache::thrift::protocol::T_STRUCT, 3);
		  xfer += this->tmfe.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_continueScan_presult::~TabletClientService_continueScan_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_continueScan_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += (*(this->success)).read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nste.read (iprot);
			  this->__isset.nste = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tmfe.read (iprot);
			  this->__isset.tmfe = true;
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

	    TabletClientService_closeScan_args::~TabletClientService_closeScan_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeScan_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->scanID);
			  this->__isset.scanID = true;
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
	    TabletClientService_closeScan_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeScan_args");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->scanID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_closeScan_pargs::~TabletClientService_closeScan_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeScan_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeScan_pargs");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 ((*(this->scanID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_startMultiScan_args::~TabletClientService_startMultiScan_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startMultiScan_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 8:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->batch.clear ();
			      uint32_t _size145;
			      ::apache::thrift::protocol::TType _ktype146;
			      ::apache::thrift::protocol::TType _vtype147;
			      xfer += iprot->readMapBegin (_ktype146, _vtype147,
							   _size145);
			      uint32_t _i149;
			      for (_i149 = 0; _i149 < _size145; ++_i149)
				{
				  ::org::apache::accumulo::core::data::thrift::TKeyExtent _key150;
				  xfer += _key150.read (iprot);
				  std::vector<
				      ::org::apache::accumulo::core::data::thrift::TRange> & _val151 =
				      this->batch[_key150];
				    {
				      _val151.clear ();
				      uint32_t _size152;
				      ::apache::thrift::protocol::TType _etype155;
				      xfer += iprot->readListBegin (_etype155,
								    _size152);
				      _val151.resize (_size152);
				      uint32_t _i156;
				      for (_i156 = 0; _i156 < _size152; ++_i156)
					{
					  xfer += _val151[_i156].read (iprot);
					}
				      xfer += iprot->readListEnd ();
				    }
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.batch = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->columns.clear ();
			      uint32_t _size157;
			      ::apache::thrift::protocol::TType _etype160;
			      xfer += iprot->readListBegin (_etype160,
							    _size157);
			      this->columns.resize (_size157);
			      uint32_t _i161;
			      for (_i161 = 0; _i161 < _size157; ++_i161)
				{
				  xfer += this->columns[_i161].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.columns = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->ssiList.clear ();
			      uint32_t _size162;
			      ::apache::thrift::protocol::TType _etype165;
			      xfer += iprot->readListBegin (_etype165,
							    _size162);
			      this->ssiList.resize (_size162);
			      uint32_t _i166;
			      for (_i166 = 0; _i166 < _size162; ++_i166)
				{
				  xfer += this->ssiList[_i166].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.ssiList = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->ssio.clear ();
			      uint32_t _size167;
			      ::apache::thrift::protocol::TType _ktype168;
			      ::apache::thrift::protocol::TType _vtype169;
			      xfer += iprot->readMapBegin (_ktype168, _vtype169,
							   _size167);
			      uint32_t _i171;
			      for (_i171 = 0; _i171 < _size167; ++_i171)
				{
				  std::string _key172;
				  xfer += iprot->readString (_key172);
				  std::map<std::string, std::string> & _val173 =
				      this->ssio[_key172];
				    {
				      _val173.clear ();
				      uint32_t _size174;
				      ::apache::thrift::protocol::TType _ktype175;
				      ::apache::thrift::protocol::TType _vtype176;
				      xfer += iprot->readMapBegin (_ktype175,
								   _vtype176,
								   _size174);
				      uint32_t _i178;
				      for (_i178 = 0; _i178 < _size174; ++_i178)
					{
					  std::string _key179;
					  xfer += iprot->readString (_key179);
					  std::string& _val180 =
					      _val173[_key179];
					  xfer += iprot->readString (_val180);
					}
				      xfer += iprot->readMapEnd ();
				    }
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.ssio = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->authorizations.clear ();
			      uint32_t _size181;
			      ::apache::thrift::protocol::TType _etype184;
			      xfer += iprot->readListBegin (_etype184,
							    _size181);
			      this->authorizations.resize (_size181);
			      uint32_t _i185;
			      for (_i185 = 0; _i185 < _size181; ++_i185)
				{
				  xfer += iprot->readBinary (
				      this->authorizations[_i185]);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.authorizations = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->waitForWrites);
			  this->__isset.waitForWrites = true;
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
	    TabletClientService_startMultiScan_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startMultiScan_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("batch",
					      ::apache::thrift::protocol::T_MAP,
					      2);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      ::apache::thrift::protocol::T_LIST,
		      static_cast<uint32_t> (this->batch.size ()));
		  std::map<
		      ::org::apache::accumulo::core::data::thrift::TKeyExtent,
		      std::vector<
			  ::org::apache::accumulo::core::data::thrift::TRange> >::const_iterator _iter186;
		  for (_iter186 = this->batch.begin ();
		      _iter186 != this->batch.end (); ++_iter186)
		    {
		      xfer += _iter186->first.write (oprot);
			{
			  xfer += oprot->writeListBegin (
			      ::apache::thrift::protocol::T_STRUCT,
			      static_cast<uint32_t> (_iter186->second.size ()));
			  std::vector<
			      ::org::apache::accumulo::core::data::thrift::TRange>::const_iterator _iter187;
			  for (_iter187 = _iter186->second.begin ();
			      _iter187 != _iter186->second.end (); ++_iter187)
			    {
			      xfer += (*_iter187).write (oprot);
			    }
			  xfer += oprot->writeListEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "columns", ::apache::thrift::protocol::T_LIST, 3);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->columns.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::TColumn>::const_iterator _iter188;
		  for (_iter188 = this->columns.begin ();
		      _iter188 != this->columns.end (); ++_iter188)
		    {
		      xfer += (*_iter188).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ssiList", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->ssiList.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::IterInfo>::const_iterator _iter189;
		  for (_iter189 = this->ssiList.begin ();
		      _iter189 != this->ssiList.end (); ++_iter189)
		    {
		      xfer += (*_iter189).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("ssio",
					      ::apache::thrift::protocol::T_MAP,
					      5);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_MAP,
		      static_cast<uint32_t> (this->ssio.size ()));
		  std::map<std::string, std::map<std::string, std::string> >::const_iterator _iter190;
		  for (_iter190 = this->ssio.begin ();
		      _iter190 != this->ssio.end (); ++_iter190)
		    {
		      xfer += oprot->writeString (_iter190->first);
			{
			  xfer += oprot->writeMapBegin (
			      ::apache::thrift::protocol::T_STRING,
			      ::apache::thrift::protocol::T_STRING,
			      static_cast<uint32_t> (_iter190->second.size ()));
			  std::map<std::string, std::string>::const_iterator _iter191;
			  for (_iter191 = _iter190->second.begin ();
			      _iter191 != _iter190->second.end (); ++_iter191)
			    {
			      xfer += oprot->writeString (_iter191->first);
			      xfer += oprot->writeString (_iter191->second);
			    }
			  xfer += oprot->writeMapEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "authorizations", ::apache::thrift::protocol::T_LIST, 6);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->authorizations.size ()));
		  std::vector<std::string>::const_iterator _iter192;
		  for (_iter192 = this->authorizations.begin ();
		      _iter192 != this->authorizations.end (); ++_iter192)
		    {
		      xfer += oprot->writeBinary ((*_iter192));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "waitForWrites", ::apache::thrift::protocol::T_BOOL, 7);
	      xfer += oprot->writeBool (this->waitForWrites);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 8);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_startMultiScan_pargs::~TabletClientService_startMultiScan_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startMultiScan_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startMultiScan_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("batch",
					      ::apache::thrift::protocol::T_MAP,
					      2);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      ::apache::thrift::protocol::T_LIST,
		      static_cast<uint32_t> ((*(this->batch)).size ()));
		  std::map<
		      ::org::apache::accumulo::core::data::thrift::TKeyExtent,
		      std::vector<
			  ::org::apache::accumulo::core::data::thrift::TRange> >::const_iterator _iter193;
		  for (_iter193 = (*(this->batch)).begin ();
		      _iter193 != (*(this->batch)).end (); ++_iter193)
		    {
		      xfer += _iter193->first.write (oprot);
			{
			  xfer += oprot->writeListBegin (
			      ::apache::thrift::protocol::T_STRUCT,
			      static_cast<uint32_t> (_iter193->second.size ()));
			  std::vector<
			      ::org::apache::accumulo::core::data::thrift::TRange>::const_iterator _iter194;
			  for (_iter194 = _iter193->second.begin ();
			      _iter194 != _iter193->second.end (); ++_iter194)
			    {
			      xfer += (*_iter194).write (oprot);
			    }
			  xfer += oprot->writeListEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "columns", ::apache::thrift::protocol::T_LIST, 3);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> ((*(this->columns)).size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::TColumn>::const_iterator _iter195;
		  for (_iter195 = (*(this->columns)).begin ();
		      _iter195 != (*(this->columns)).end (); ++_iter195)
		    {
		      xfer += (*_iter195).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ssiList", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> ((*(this->ssiList)).size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::IterInfo>::const_iterator _iter196;
		  for (_iter196 = (*(this->ssiList)).begin ();
		      _iter196 != (*(this->ssiList)).end (); ++_iter196)
		    {
		      xfer += (*_iter196).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("ssio",
					      ::apache::thrift::protocol::T_MAP,
					      5);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_MAP,
		      static_cast<uint32_t> ((*(this->ssio)).size ()));
		  std::map<std::string, std::map<std::string, std::string> >::const_iterator _iter197;
		  for (_iter197 = (*(this->ssio)).begin ();
		      _iter197 != (*(this->ssio)).end (); ++_iter197)
		    {
		      xfer += oprot->writeString (_iter197->first);
			{
			  xfer += oprot->writeMapBegin (
			      ::apache::thrift::protocol::T_STRING,
			      ::apache::thrift::protocol::T_STRING,
			      static_cast<uint32_t> (_iter197->second.size ()));
			  std::map<std::string, std::string>::const_iterator _iter198;
			  for (_iter198 = _iter197->second.begin ();
			      _iter198 != _iter197->second.end (); ++_iter198)
			    {
			      xfer += oprot->writeString (_iter198->first);
			      xfer += oprot->writeString (_iter198->second);
			    }
			  xfer += oprot->writeMapEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "authorizations", ::apache::thrift::protocol::T_LIST, 6);
		{
		  xfer +=
		      oprot->writeListBegin (
			  ::apache::thrift::protocol::T_STRING,
			  static_cast<uint32_t> ((*(this->authorizations)).size ()));
		  std::vector<std::string>::const_iterator _iter199;
		  for (_iter199 = (*(this->authorizations)).begin ();
		      _iter199 != (*(this->authorizations)).end (); ++_iter199)
		    {
		      xfer += oprot->writeBinary ((*_iter199));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "waitForWrites", ::apache::thrift::protocol::T_BOOL, 7);
	      xfer += oprot->writeBool ((*(this->waitForWrites)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 8);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_startMultiScan_result::~TabletClientService_startMultiScan_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startMultiScan_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->success.read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_startMultiScan_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startMultiScan_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRUCT, 0);
		  xfer += this->success.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_startMultiScan_presult::~TabletClientService_startMultiScan_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startMultiScan_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += (*(this->success)).read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_continueMultiScan_args::~TabletClientService_continueMultiScan_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_continueMultiScan_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->scanID);
			  this->__isset.scanID = true;
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
	    TabletClientService_continueMultiScan_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_continueMultiScan_args");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->scanID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_continueMultiScan_pargs::~TabletClientService_continueMultiScan_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_continueMultiScan_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_continueMultiScan_pargs");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 ((*(this->scanID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_continueMultiScan_result::~TabletClientService_continueMultiScan_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_continueMultiScan_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->success.read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
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
	    TabletClientService_continueMultiScan_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_continueMultiScan_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRUCT, 0);
		  xfer += this->success.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.nssi)
		{
		  xfer += oprot->writeFieldBegin (
		      "nssi", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->nssi.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_continueMultiScan_presult::~TabletClientService_continueMultiScan_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_continueMultiScan_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += (*(this->success)).read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
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

	    TabletClientService_closeMultiScan_args::~TabletClientService_closeMultiScan_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeMultiScan_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->scanID);
			  this->__isset.scanID = true;
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
	    TabletClientService_closeMultiScan_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeMultiScan_args");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->scanID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_closeMultiScan_pargs::~TabletClientService_closeMultiScan_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeMultiScan_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeMultiScan_pargs");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 ((*(this->scanID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_closeMultiScan_result::~TabletClientService_closeMultiScan_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeMultiScan_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
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
	    TabletClientService_closeMultiScan_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeMultiScan_result");

	      if (this->__isset.nssi)
		{
		  xfer += oprot->writeFieldBegin (
		      "nssi", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->nssi.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_closeMultiScan_presult::~TabletClientService_closeMultiScan_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeMultiScan_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
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

	    TabletClientService_startUpdate_args::~TabletClientService_startUpdate_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startUpdate_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
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
	    TabletClientService_startUpdate_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startUpdate_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_startUpdate_pargs::~TabletClientService_startUpdate_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startUpdate_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startUpdate_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_startUpdate_result::~TabletClientService_startUpdate_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startUpdate_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->success);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_startUpdate_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startUpdate_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_I64, 0);
		  xfer += oprot->writeI64 (this->success);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_startUpdate_presult::~TabletClientService_startUpdate_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startUpdate_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 ((*(this->success)));
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_applyUpdates_args::~TabletClientService_applyUpdates_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_applyUpdates_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->updateID);
			  this->__isset.updateID = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->keyExtent.read (iprot);
			  this->__isset.keyExtent = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->mutations.clear ();
			      uint32_t _size200;
			      ::apache::thrift::protocol::TType _etype203;
			      xfer += iprot->readListBegin (_etype203,
							    _size200);
			      this->mutations.resize (_size200);
			      uint32_t _i204;
			      for (_i204 = 0; _i204 < _size200; ++_i204)
				{
				  xfer += this->mutations[_i204].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.mutations = true;
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
	    TabletClientService_applyUpdates_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_applyUpdates_args");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("updateID",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->updateID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "keyExtent", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->keyExtent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "mutations", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->mutations.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::TMutation>::const_iterator _iter205;
		  for (_iter205 = this->mutations.begin ();
		      _iter205 != this->mutations.end (); ++_iter205)
		    {
		      xfer += (*_iter205).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_applyUpdates_pargs::~TabletClientService_applyUpdates_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_applyUpdates_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_applyUpdates_pargs");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("updateID",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 ((*(this->updateID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "keyExtent", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->keyExtent)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "mutations", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> ((*(this->mutations)).size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::TMutation>::const_iterator _iter206;
		  for (_iter206 = (*(this->mutations)).begin ();
		      _iter206 != (*(this->mutations)).end (); ++_iter206)
		    {
		      xfer += (*_iter206).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_closeUpdate_args::~TabletClientService_closeUpdate_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeUpdate_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->updateID);
			  this->__isset.updateID = true;
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
	    TabletClientService_closeUpdate_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeUpdate_args");

	      xfer += oprot->writeFieldBegin ("updateID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->updateID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_closeUpdate_pargs::~TabletClientService_closeUpdate_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeUpdate_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeUpdate_pargs");

	      xfer += oprot->writeFieldBegin ("updateID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 ((*(this->updateID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_closeUpdate_result::~TabletClientService_closeUpdate_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeUpdate_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->success.read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
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
	    TabletClientService_closeUpdate_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeUpdate_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRUCT, 0);
		  xfer += this->success.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.nssi)
		{
		  xfer += oprot->writeFieldBegin (
		      "nssi", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->nssi.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_closeUpdate_presult::~TabletClientService_closeUpdate_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeUpdate_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += (*(this->success)).read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
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

	    TabletClientService_update_args::~TabletClientService_update_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_update_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->keyExtent.read (iprot);
			  this->__isset.keyExtent = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->mutation.read (iprot);
			  this->__isset.mutation = true;
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
	    TabletClientService_update_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_update_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "keyExtent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->keyExtent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "mutation", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->mutation.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_update_pargs::~TabletClientService_update_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_update_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_update_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "keyExtent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->keyExtent)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "mutation", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->mutation)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_update_result::~TabletClientService_update_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_update_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nste.read (iprot);
			  this->__isset.nste = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->cve.read (iprot);
			  this->__isset.cve = true;
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
	    TabletClientService_update_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_update_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.nste)
		{
		  xfer += oprot->writeFieldBegin (
		      "nste", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->nste.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.cve)
		{
		  xfer += oprot->writeFieldBegin (
		      "cve", ::apache::thrift::protocol::T_STRUCT, 3);
		  xfer += this->cve.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_update_presult::~TabletClientService_update_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_update_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nste.read (iprot);
			  this->__isset.nste = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->cve.read (iprot);
			  this->__isset.cve = true;
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

	    TabletClientService_startConditionalUpdate_args::~TabletClientService_startConditionalUpdate_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startConditionalUpdate_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->authorizations.clear ();
			      uint32_t _size207;
			      ::apache::thrift::protocol::TType _etype210;
			      xfer += iprot->readListBegin (_etype210,
							    _size207);
			      this->authorizations.resize (_size207);
			      uint32_t _i211;
			      for (_i211 = 0; _i211 < _size207; ++_i211)
				{
				  xfer += iprot->readBinary (
				      this->authorizations[_i211]);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.authorizations = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tableID);
			  this->__isset.tableID = true;
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
	    TabletClientService_startConditionalUpdate_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startConditionalUpdate_args");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "authorizations", ::apache::thrift::protocol::T_LIST, 3);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->authorizations.size ()));
		  std::vector<std::string>::const_iterator _iter212;
		  for (_iter212 = this->authorizations.begin ();
		      _iter212 != this->authorizations.end (); ++_iter212)
		    {
		      xfer += oprot->writeBinary ((*_iter212));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableID", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString (this->tableID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_startConditionalUpdate_pargs::~TabletClientService_startConditionalUpdate_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startConditionalUpdate_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startConditionalUpdate_pargs");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "authorizations", ::apache::thrift::protocol::T_LIST, 3);
		{
		  xfer +=
		      oprot->writeListBegin (
			  ::apache::thrift::protocol::T_STRING,
			  static_cast<uint32_t> ((*(this->authorizations)).size ()));
		  std::vector<std::string>::const_iterator _iter213;
		  for (_iter213 = (*(this->authorizations)).begin ();
		      _iter213 != (*(this->authorizations)).end (); ++_iter213)
		    {
		      xfer += oprot->writeBinary ((*_iter213));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableID", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString ((*(this->tableID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_startConditionalUpdate_result::~TabletClientService_startConditionalUpdate_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startConditionalUpdate_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->success.read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_startConditionalUpdate_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_startConditionalUpdate_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRUCT, 0);
		  xfer += this->success.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_startConditionalUpdate_presult::~TabletClientService_startConditionalUpdate_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_startConditionalUpdate_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += (*(this->success)).read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_conditionalUpdate_args::~TabletClientService_conditionalUpdate_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_conditionalUpdate_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->sessID);
			  this->__isset.sessID = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->mutations.clear ();
			      uint32_t _size214;
			      ::apache::thrift::protocol::TType _ktype215;
			      ::apache::thrift::protocol::TType _vtype216;
			      xfer += iprot->readMapBegin (_ktype215, _vtype216,
							   _size214);
			      uint32_t _i218;
			      for (_i218 = 0; _i218 < _size214; ++_i218)
				{
				  ::org::apache::accumulo::core::data::thrift::TKeyExtent _key219;
				  xfer += _key219.read (iprot);
				  std::vector<
				      ::org::apache::accumulo::core::data::thrift::TConditionalMutation> & _val220 =
				      this->mutations[_key219];
				    {
				      _val220.clear ();
				      uint32_t _size221;
				      ::apache::thrift::protocol::TType _etype224;
				      xfer += iprot->readListBegin (_etype224,
								    _size221);
				      _val220.resize (_size221);
				      uint32_t _i225;
				      for (_i225 = 0; _i225 < _size221; ++_i225)
					{
					  xfer += _val220[_i225].read (iprot);
					}
				      xfer += iprot->readListEnd ();
				    }
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.mutations = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->symbols.clear ();
			      uint32_t _size226;
			      ::apache::thrift::protocol::TType _etype229;
			      xfer += iprot->readListBegin (_etype229,
							    _size226);
			      this->symbols.resize (_size226);
			      uint32_t _i230;
			      for (_i230 = 0; _i230 < _size226; ++_i230)
				{
				  xfer += iprot->readString (
				      this->symbols[_i230]);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.symbols = true;
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
	    TabletClientService_conditionalUpdate_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_conditionalUpdate_args");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("sessID",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->sessID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("mutations",
					      ::apache::thrift::protocol::T_MAP,
					      3);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      ::apache::thrift::protocol::T_LIST,
		      static_cast<uint32_t> (this->mutations.size ()));
		  std::map<
		      ::org::apache::accumulo::core::data::thrift::TKeyExtent,
		      std::vector<
			  ::org::apache::accumulo::core::data::thrift::TConditionalMutation> >::const_iterator _iter231;
		  for (_iter231 = this->mutations.begin ();
		      _iter231 != this->mutations.end (); ++_iter231)
		    {
		      xfer += _iter231->first.write (oprot);
			{
			  xfer += oprot->writeListBegin (
			      ::apache::thrift::protocol::T_STRUCT,
			      static_cast<uint32_t> (_iter231->second.size ()));
			  std::vector<
			      ::org::apache::accumulo::core::data::thrift::TConditionalMutation>::const_iterator _iter232;
			  for (_iter232 = _iter231->second.begin ();
			      _iter232 != _iter231->second.end (); ++_iter232)
			    {
			      xfer += (*_iter232).write (oprot);
			    }
			  xfer += oprot->writeListEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "symbols", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->symbols.size ()));
		  std::vector<std::string>::const_iterator _iter233;
		  for (_iter233 = this->symbols.begin ();
		      _iter233 != this->symbols.end (); ++_iter233)
		    {
		      xfer += oprot->writeString ((*_iter233));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_conditionalUpdate_pargs::~TabletClientService_conditionalUpdate_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_conditionalUpdate_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_conditionalUpdate_pargs");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("sessID",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 ((*(this->sessID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("mutations",
					      ::apache::thrift::protocol::T_MAP,
					      3);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      ::apache::thrift::protocol::T_LIST,
		      static_cast<uint32_t> ((*(this->mutations)).size ()));
		  std::map<
		      ::org::apache::accumulo::core::data::thrift::TKeyExtent,
		      std::vector<
			  ::org::apache::accumulo::core::data::thrift::TConditionalMutation> >::const_iterator _iter234;
		  for (_iter234 = (*(this->mutations)).begin ();
		      _iter234 != (*(this->mutations)).end (); ++_iter234)
		    {
		      xfer += _iter234->first.write (oprot);
			{
			  xfer += oprot->writeListBegin (
			      ::apache::thrift::protocol::T_STRUCT,
			      static_cast<uint32_t> (_iter234->second.size ()));
			  std::vector<
			      ::org::apache::accumulo::core::data::thrift::TConditionalMutation>::const_iterator _iter235;
			  for (_iter235 = _iter234->second.begin ();
			      _iter235 != _iter234->second.end (); ++_iter235)
			    {
			      xfer += (*_iter235).write (oprot);
			    }
			  xfer += oprot->writeListEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "symbols", ::apache::thrift::protocol::T_LIST, 4);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> ((*(this->symbols)).size ()));
		  std::vector<std::string>::const_iterator _iter236;
		  for (_iter236 = (*(this->symbols)).begin ();
		      _iter236 != (*(this->symbols)).end (); ++_iter236)
		    {
		      xfer += oprot->writeString ((*_iter236));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_conditionalUpdate_result::~TabletClientService_conditionalUpdate_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_conditionalUpdate_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->success.clear ();
			      uint32_t _size237;
			      ::apache::thrift::protocol::TType _etype240;
			      xfer += iprot->readListBegin (_etype240,
							    _size237);
			      this->success.resize (_size237);
			      uint32_t _i241;
			      for (_i241 = 0; _i241 < _size237; ++_i241)
				{
				  xfer += this->success[_i241].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
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
	    TabletClientService_conditionalUpdate_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_conditionalUpdate_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_LIST, 0);
		    {
		      xfer += oprot->writeListBegin (
			  ::apache::thrift::protocol::T_STRUCT,
			  static_cast<uint32_t> (this->success.size ()));
		      std::vector<
			  ::org::apache::accumulo::core::data::thrift::TCMResult>::const_iterator _iter242;
		      for (_iter242 = this->success.begin ();
			  _iter242 != this->success.end (); ++_iter242)
			{
			  xfer += (*_iter242).write (oprot);
			}
		      xfer += oprot->writeListEnd ();
		    }
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.nssi)
		{
		  xfer += oprot->writeFieldBegin (
		      "nssi", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->nssi.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_conditionalUpdate_presult::~TabletClientService_conditionalUpdate_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_conditionalUpdate_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      (*(this->success)).clear ();
			      uint32_t _size243;
			      ::apache::thrift::protocol::TType _etype246;
			      xfer += iprot->readListBegin (_etype246,
							    _size243);
			      (*(this->success)).resize (_size243);
			      uint32_t _i247;
			      for (_i247 = 0; _i247 < _size243; ++_i247)
				{
				  xfer += (*(this->success))[_i247].read (
				      iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nssi.read (iprot);
			  this->__isset.nssi = true;
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

	    TabletClientService_invalidateConditionalUpdate_args::~TabletClientService_invalidateConditionalUpdate_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_invalidateConditionalUpdate_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->sessID);
			  this->__isset.sessID = true;
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
	    TabletClientService_invalidateConditionalUpdate_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_invalidateConditionalUpdate_args");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("sessID",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->sessID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_invalidateConditionalUpdate_pargs::~TabletClientService_invalidateConditionalUpdate_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_invalidateConditionalUpdate_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_invalidateConditionalUpdate_pargs");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("sessID",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 ((*(this->sessID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_invalidateConditionalUpdate_result::~TabletClientService_invalidateConditionalUpdate_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_invalidateConditionalUpdate_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		  xfer += iprot->skip (ftype);
		  xfer += iprot->readFieldEnd ();
		}

	      xfer += iprot->readStructEnd ();

	      return xfer;
	    }

	    uint32_t
	    TabletClientService_invalidateConditionalUpdate_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_invalidateConditionalUpdate_result");

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_invalidateConditionalUpdate_presult::~TabletClientService_invalidateConditionalUpdate_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_invalidateConditionalUpdate_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		  xfer += iprot->skip (ftype);
		  xfer += iprot->readFieldEnd ();
		}

	      xfer += iprot->readStructEnd ();

	      return xfer;
	    }

	    TabletClientService_closeConditionalUpdate_args::~TabletClientService_closeConditionalUpdate_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeConditionalUpdate_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->sessID);
			  this->__isset.sessID = true;
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
	    TabletClientService_closeConditionalUpdate_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeConditionalUpdate_args");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("sessID",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->sessID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_closeConditionalUpdate_pargs::~TabletClientService_closeConditionalUpdate_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_closeConditionalUpdate_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_closeConditionalUpdate_pargs");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("sessID",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 ((*(this->sessID)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_bulkImport_args::~TabletClientService_bulkImport_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_bulkImport_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->tid);
			  this->__isset.tid = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->files.clear ();
			      uint32_t _size248;
			      ::apache::thrift::protocol::TType _ktype249;
			      ::apache::thrift::protocol::TType _vtype250;
			      xfer += iprot->readMapBegin (_ktype249, _vtype250,
							   _size248);
			      uint32_t _i252;
			      for (_i252 = 0; _i252 < _size248; ++_i252)
				{
				  ::org::apache::accumulo::core::data::thrift::TKeyExtent _key253;
				  xfer += _key253.read (iprot);
				  std::map<std::string,
				      ::org::apache::accumulo::core::data::thrift::MapFileInfo> & _val254 =
				      this->files[_key253];
				    {
				      _val254.clear ();
				      uint32_t _size255;
				      ::apache::thrift::protocol::TType _ktype256;
				      ::apache::thrift::protocol::TType _vtype257;
				      xfer += iprot->readMapBegin (_ktype256,
								   _vtype257,
								   _size255);
				      uint32_t _i259;
				      for (_i259 = 0; _i259 < _size255; ++_i259)
					{
					  std::string _key260;
					  xfer += iprot->readString (_key260);
					  ::org::apache::accumulo::core::data::thrift::MapFileInfo& _val261 =
					      _val254[_key260];
					  xfer += _val261.read (iprot);
					}
				      xfer += iprot->readMapEnd ();
				    }
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.files = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->setTime);
			  this->__isset.setTime = true;
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
	    TabletClientService_bulkImport_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_bulkImport_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("files",
					      ::apache::thrift::protocol::T_MAP,
					      2);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      ::apache::thrift::protocol::T_MAP,
		      static_cast<uint32_t> (this->files.size ()));
		  std::map<
		      ::org::apache::accumulo::core::data::thrift::TKeyExtent,
		      std::map<std::string,
			  ::org::apache::accumulo::core::data::thrift::MapFileInfo> >::const_iterator _iter262;
		  for (_iter262 = this->files.begin ();
		      _iter262 != this->files.end (); ++_iter262)
		    {
		      xfer += _iter262->first.write (oprot);
			{
			  xfer += oprot->writeMapBegin (
			      ::apache::thrift::protocol::T_STRING,
			      ::apache::thrift::protocol::T_STRUCT,
			      static_cast<uint32_t> (_iter262->second.size ()));
			  std::map<std::string,
			      ::org::apache::accumulo::core::data::thrift::MapFileInfo>::const_iterator _iter263;
			  for (_iter263 = _iter262->second.begin ();
			      _iter263 != _iter262->second.end (); ++_iter263)
			    {
			      xfer += oprot->writeString (_iter263->first);
			      xfer += _iter263->second.write (oprot);
			    }
			  xfer += oprot->writeMapEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("tid",
					      ::apache::thrift::protocol::T_I64,
					      4);
	      xfer += oprot->writeI64 (this->tid);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "setTime", ::apache::thrift::protocol::T_BOOL, 5);
	      xfer += oprot->writeBool (this->setTime);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_bulkImport_pargs::~TabletClientService_bulkImport_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_bulkImport_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_bulkImport_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("files",
					      ::apache::thrift::protocol::T_MAP,
					      2);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      ::apache::thrift::protocol::T_MAP,
		      static_cast<uint32_t> ((*(this->files)).size ()));
		  std::map<
		      ::org::apache::accumulo::core::data::thrift::TKeyExtent,
		      std::map<std::string,
			  ::org::apache::accumulo::core::data::thrift::MapFileInfo> >::const_iterator _iter264;
		  for (_iter264 = (*(this->files)).begin ();
		      _iter264 != (*(this->files)).end (); ++_iter264)
		    {
		      xfer += _iter264->first.write (oprot);
			{
			  xfer += oprot->writeMapBegin (
			      ::apache::thrift::protocol::T_STRING,
			      ::apache::thrift::protocol::T_STRUCT,
			      static_cast<uint32_t> (_iter264->second.size ()));
			  std::map<std::string,
			      ::org::apache::accumulo::core::data::thrift::MapFileInfo>::const_iterator _iter265;
			  for (_iter265 = _iter264->second.begin ();
			      _iter265 != _iter264->second.end (); ++_iter265)
			    {
			      xfer += oprot->writeString (_iter265->first);
			      xfer += _iter265->second.write (oprot);
			    }
			  xfer += oprot->writeMapEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("tid",
					      ::apache::thrift::protocol::T_I64,
					      4);
	      xfer += oprot->writeI64 ((*(this->tid)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "setTime", ::apache::thrift::protocol::T_BOOL, 5);
	      xfer += oprot->writeBool ((*(this->setTime)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_bulkImport_result::~TabletClientService_bulkImport_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_bulkImport_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->success.clear ();
			      uint32_t _size266;
			      ::apache::thrift::protocol::TType _etype269;
			      xfer += iprot->readListBegin (_etype269,
							    _size266);
			      this->success.resize (_size266);
			      uint32_t _i270;
			      for (_i270 = 0; _i270 < _size266; ++_i270)
				{
				  xfer += this->success[_i270].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_bulkImport_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_bulkImport_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_LIST, 0);
		    {
		      xfer += oprot->writeListBegin (
			  ::apache::thrift::protocol::T_STRUCT,
			  static_cast<uint32_t> (this->success.size ()));
		      std::vector<
			  ::org::apache::accumulo::core::data::thrift::TKeyExtent>::const_iterator _iter271;
		      for (_iter271 = this->success.begin ();
			  _iter271 != this->success.end (); ++_iter271)
			{
			  xfer += (*_iter271).write (oprot);
			}
		      xfer += oprot->writeListEnd ();
		    }
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_bulkImport_presult::~TabletClientService_bulkImport_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_bulkImport_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      (*(this->success)).clear ();
			      uint32_t _size272;
			      ::apache::thrift::protocol::TType _etype275;
			      xfer += iprot->readListBegin (_etype275,
							    _size272);
			      (*(this->success)).resize (_size272);
			      uint32_t _i276;
			      for (_i276 = 0; _i276 < _size272; ++_i276)
				{
				  xfer += (*(this->success))[_i276].read (
				      iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_splitTablet_args::~TabletClientService_splitTablet_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_splitTablet_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->extent.read (iprot);
			  this->__isset.extent = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->splitPoint);
			  this->__isset.splitPoint = true;
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
	    TabletClientService_splitTablet_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_splitTablet_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "splitPoint", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeBinary (this->splitPoint);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_splitTablet_pargs::~TabletClientService_splitTablet_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_splitTablet_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_splitTablet_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->extent)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "splitPoint", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeBinary ((*(this->splitPoint)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_splitTablet_result::~TabletClientService_splitTablet_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_splitTablet_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nste.read (iprot);
			  this->__isset.nste = true;
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
	    TabletClientService_splitTablet_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_splitTablet_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.nste)
		{
		  xfer += oprot->writeFieldBegin (
		      "nste", ::apache::thrift::protocol::T_STRUCT, 2);
		  xfer += this->nste.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_splitTablet_presult::~TabletClientService_splitTablet_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_splitTablet_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->nste.read (iprot);
			  this->__isset.nste = true;
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

	    TabletClientService_loadTablet_args::~TabletClientService_loadTablet_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_loadTablet_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->lock);
			  this->__isset.lock = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->extent.read (iprot);
			  this->__isset.extent = true;
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
	    TabletClientService_loadTablet_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_loadTablet_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString (this->lock);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_loadTablet_pargs::~TabletClientService_loadTablet_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_loadTablet_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_loadTablet_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->extent)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString ((*(this->lock)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_unloadTablet_args::~TabletClientService_unloadTablet_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_unloadTablet_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->lock);
			  this->__isset.lock = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->extent.read (iprot);
			  this->__isset.extent = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->save);
			  this->__isset.save = true;
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
	    TabletClientService_unloadTablet_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_unloadTablet_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "save", ::apache::thrift::protocol::T_BOOL, 3);
	      xfer += oprot->writeBool (this->save);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString (this->lock);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_unloadTablet_pargs::~TabletClientService_unloadTablet_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_unloadTablet_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_unloadTablet_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->extent)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "save", ::apache::thrift::protocol::T_BOOL, 3);
	      xfer += oprot->writeBool ((*(this->save)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString ((*(this->lock)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_flush_args::~TabletClientService_flush_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_flush_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->lock);
			  this->__isset.lock = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tableId);
			  this->__isset.tableId = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->startRow);
			  this->__isset.startRow = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->endRow);
			  this->__isset.endRow = true;
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
	    TabletClientService_flush_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_flush_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableId", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->tableId);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->lock);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "startRow", ::apache::thrift::protocol::T_STRING, 5);
	      xfer += oprot->writeBinary (this->startRow);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "endRow", ::apache::thrift::protocol::T_STRING, 6);
	      xfer += oprot->writeBinary (this->endRow);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_flush_pargs::~TabletClientService_flush_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_flush_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_flush_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableId", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->tableId)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString ((*(this->lock)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "startRow", ::apache::thrift::protocol::T_STRING, 5);
	      xfer += oprot->writeBinary ((*(this->startRow)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "endRow", ::apache::thrift::protocol::T_STRING, 6);
	      xfer += oprot->writeBinary ((*(this->endRow)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_flushTablet_args::~TabletClientService_flushTablet_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_flushTablet_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->lock);
			  this->__isset.lock = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->extent.read (iprot);
			  this->__isset.extent = true;
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
	    TabletClientService_flushTablet_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_flushTablet_args");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->lock);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_flushTablet_pargs::~TabletClientService_flushTablet_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_flushTablet_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_flushTablet_pargs");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString ((*(this->lock)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->extent)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_chop_args::~TabletClientService_chop_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_chop_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->lock);
			  this->__isset.lock = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->extent.read (iprot);
			  this->__isset.extent = true;
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
	    TabletClientService_chop_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TabletClientService_chop_args");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->lock);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_chop_pargs::~TabletClientService_chop_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_chop_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_chop_pargs");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString ((*(this->lock)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += (*(this->extent)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_compact_args::~TabletClientService_compact_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_compact_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->lock);
			  this->__isset.lock = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tableId);
			  this->__isset.tableId = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->startRow);
			  this->__isset.startRow = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->endRow);
			  this->__isset.endRow = true;
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
	    TabletClientService_compact_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_compact_args");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->lock);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableId", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString (this->tableId);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "startRow", ::apache::thrift::protocol::T_STRING, 5);
	      xfer += oprot->writeBinary (this->startRow);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "endRow", ::apache::thrift::protocol::T_STRING, 6);
	      xfer += oprot->writeBinary (this->endRow);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_compact_pargs::~TabletClientService_compact_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_compact_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_compact_pargs");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString ((*(this->lock)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableId", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString ((*(this->tableId)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "startRow", ::apache::thrift::protocol::T_STRING, 5);
	      xfer += oprot->writeBinary ((*(this->startRow)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "endRow", ::apache::thrift::protocol::T_STRING, 6);
	      xfer += oprot->writeBinary ((*(this->endRow)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getTabletServerStatus_args::~TabletClientService_getTabletServerStatus_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getTabletServerStatus_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
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
	    TabletClientService_getTabletServerStatus_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getTabletServerStatus_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getTabletServerStatus_pargs::~TabletClientService_getTabletServerStatus_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getTabletServerStatus_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getTabletServerStatus_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getTabletServerStatus_result::~TabletClientService_getTabletServerStatus_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getTabletServerStatus_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->success.read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_getTabletServerStatus_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getTabletServerStatus_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRUCT, 0);
		  xfer += this->success.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_getTabletServerStatus_presult::~TabletClientService_getTabletServerStatus_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getTabletServerStatus_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += (*(this->success)).read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_getTabletStats_args::~TabletClientService_getTabletStats_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getTabletStats_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tableId);
			  this->__isset.tableId = true;
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
	    TabletClientService_getTabletStats_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getTabletStats_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableId", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->tableId);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getTabletStats_pargs::~TabletClientService_getTabletStats_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getTabletStats_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getTabletStats_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableId", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->tableId)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getTabletStats_result::~TabletClientService_getTabletStats_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getTabletStats_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->success.clear ();
			      uint32_t _size277;
			      ::apache::thrift::protocol::TType _etype280;
			      xfer += iprot->readListBegin (_etype280,
							    _size277);
			      this->success.resize (_size277);
			      uint32_t _i281;
			      for (_i281 = 0; _i281 < _size277; ++_i281)
				{
				  xfer += this->success[_i281].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_getTabletStats_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getTabletStats_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_LIST, 0);
		    {
		      xfer += oprot->writeListBegin (
			  ::apache::thrift::protocol::T_STRUCT,
			  static_cast<uint32_t> (this->success.size ()));
		      std::vector<TabletStats>::const_iterator _iter282;
		      for (_iter282 = this->success.begin ();
			  _iter282 != this->success.end (); ++_iter282)
			{
			  xfer += (*_iter282).write (oprot);
			}
		      xfer += oprot->writeListEnd ();
		    }
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_getTabletStats_presult::~TabletClientService_getTabletStats_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getTabletStats_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      (*(this->success)).clear ();
			      uint32_t _size283;
			      ::apache::thrift::protocol::TType _etype286;
			      xfer += iprot->readListBegin (_etype286,
							    _size283);
			      (*(this->success)).resize (_size283);
			      uint32_t _i287;
			      for (_i287 = 0; _i287 < _size283; ++_i287)
				{
				  xfer += (*(this->success))[_i287].read (
				      iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_getHistoricalStats_args::~TabletClientService_getHistoricalStats_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getHistoricalStats_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
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
	    TabletClientService_getHistoricalStats_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getHistoricalStats_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getHistoricalStats_pargs::~TabletClientService_getHistoricalStats_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getHistoricalStats_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getHistoricalStats_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getHistoricalStats_result::~TabletClientService_getHistoricalStats_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getHistoricalStats_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->success.read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_getHistoricalStats_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getHistoricalStats_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_STRUCT, 0);
		  xfer += this->success.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_getHistoricalStats_presult::~TabletClientService_getHistoricalStats_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getHistoricalStats_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += (*(this->success)).read (iprot);
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_halt_args::~TabletClientService_halt_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_halt_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->lock);
			  this->__isset.lock = true;
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
	    TabletClientService_halt_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TabletClientService_halt_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->lock);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_halt_pargs::~TabletClientService_halt_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_halt_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_halt_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->lock)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_halt_result::~TabletClientService_halt_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_halt_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_halt_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_halt_result");

	      if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_halt_presult::~TabletClientService_halt_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_halt_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_fastHalt_args::~TabletClientService_fastHalt_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_fastHalt_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->lock);
			  this->__isset.lock = true;
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
	    TabletClientService_fastHalt_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_fastHalt_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->lock);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_fastHalt_pargs::~TabletClientService_fastHalt_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_fastHalt_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_fastHalt_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "lock", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString ((*(this->lock)));
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getActiveScans_args::~TabletClientService_getActiveScans_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getActiveScans_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
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
	    TabletClientService_getActiveScans_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getActiveScans_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getActiveScans_pargs::~TabletClientService_getActiveScans_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getActiveScans_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getActiveScans_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getActiveScans_result::~TabletClientService_getActiveScans_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getActiveScans_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->success.clear ();
			      uint32_t _size288;
			      ::apache::thrift::protocol::TType _etype291;
			      xfer += iprot->readListBegin (_etype291,
							    _size288);
			      this->success.resize (_size288);
			      uint32_t _i292;
			      for (_i292 = 0; _i292 < _size288; ++_i292)
				{
				  xfer += this->success[_i292].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_getActiveScans_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getActiveScans_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_LIST, 0);
		    {
		      xfer += oprot->writeListBegin (
			  ::apache::thrift::protocol::T_STRUCT,
			  static_cast<uint32_t> (this->success.size ()));
		      std::vector<ActiveScan>::const_iterator _iter293;
		      for (_iter293 = this->success.begin ();
			  _iter293 != this->success.end (); ++_iter293)
			{
			  xfer += (*_iter293).write (oprot);
			}
		      xfer += oprot->writeListEnd ();
		    }
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_getActiveScans_presult::~TabletClientService_getActiveScans_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getActiveScans_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      (*(this->success)).clear ();
			      uint32_t _size294;
			      ::apache::thrift::protocol::TType _etype297;
			      xfer += iprot->readListBegin (_etype297,
							    _size294);
			      (*(this->success)).resize (_size294);
			      uint32_t _i298;
			      for (_i298 = 0; _i298 < _size294; ++_i298)
				{
				  xfer += (*(this->success))[_i298].read (
				      iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_getActiveCompactions_args::~TabletClientService_getActiveCompactions_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getActiveCompactions_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
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
	    TabletClientService_getActiveCompactions_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getActiveCompactions_args");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getActiveCompactions_pargs::~TabletClientService_getActiveCompactions_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getActiveCompactions_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getActiveCompactions_pargs");

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_getActiveCompactions_result::~TabletClientService_getActiveCompactions_result () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getActiveCompactions_result::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->success.clear ();
			      uint32_t _size299;
			      ::apache::thrift::protocol::TType _etype302;
			      xfer += iprot->readListBegin (_etype302,
							    _size299);
			      this->success.resize (_size299);
			      uint32_t _i303;
			      for (_i303 = 0; _i303 < _size299; ++_i303)
				{
				  xfer += this->success[_i303].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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
	    TabletClientService_getActiveCompactions_result::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {

	      uint32_t xfer = 0;

	      xfer += oprot->writeStructBegin (
		  "TabletClientService_getActiveCompactions_result");

	      if (this->__isset.success)
		{
		  xfer += oprot->writeFieldBegin (
		      "success", ::apache::thrift::protocol::T_LIST, 0);
		    {
		      xfer += oprot->writeListBegin (
			  ::apache::thrift::protocol::T_STRUCT,
			  static_cast<uint32_t> (this->success.size ()));
		      std::vector<ActiveCompaction>::const_iterator _iter304;
		      for (_iter304 = this->success.begin ();
			  _iter304 != this->success.end (); ++_iter304)
			{
			  xfer += (*_iter304).write (oprot);
			}
		      xfer += oprot->writeListEnd ();
		    }
		  xfer += oprot->writeFieldEnd ();
		}
	      else if (this->__isset.sec)
		{
		  xfer += oprot->writeFieldBegin (
		      "sec", ::apache::thrift::protocol::T_STRUCT, 1);
		  xfer += this->sec.write (oprot);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      return xfer;
	    }

	    TabletClientService_getActiveCompactions_presult::~TabletClientService_getActiveCompactions_presult () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_getActiveCompactions_presult::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		    case 0:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      (*(this->success)).clear ();
			      uint32_t _size305;
			      ::apache::thrift::protocol::TType _etype308;
			      xfer += iprot->readListBegin (_etype308,
							    _size305);
			      (*(this->success)).resize (_size305);
			      uint32_t _i309;
			      for (_i309 = 0; _i309 < _size305; ++_i309)
				{
				  xfer += (*(this->success))[_i309].read (
				      iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.success = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 1:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->sec.read (iprot);
			  this->__isset.sec = true;
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

	    TabletClientService_removeLogs_args::~TabletClientService_removeLogs_args () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_removeLogs_args::read (
		::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->tinfo.read (iprot);
			  this->__isset.tinfo = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->credentials.read (iprot);
			  this->__isset.credentials = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->filenames.clear ();
			      uint32_t _size310;
			      ::apache::thrift::protocol::TType _etype313;
			      xfer += iprot->readListBegin (_etype313,
							    _size310);
			      this->filenames.resize (_size310);
			      uint32_t _i314;
			      for (_i314 = 0; _i314 < _size310; ++_i314)
				{
				  xfer += iprot->readString (
				      this->filenames[_i314]);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.filenames = true;
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
	    TabletClientService_removeLogs_args::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_removeLogs_args");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->tinfo.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->credentials.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "filenames", ::apache::thrift::protocol::T_LIST, 3);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->filenames.size ()));
		  std::vector<std::string>::const_iterator _iter315;
		  for (_iter315 = this->filenames.begin ();
		      _iter315 != this->filenames.end (); ++_iter315)
		    {
		      xfer += oprot->writeString ((*_iter315));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    TabletClientService_removeLogs_pargs::~TabletClientService_removeLogs_pargs () throw ()
	    {
	    }

	    uint32_t
	    TabletClientService_removeLogs_pargs::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin (
		  "TabletClientService_removeLogs_pargs");

	      xfer += oprot->writeFieldBegin (
		  "tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += (*(this->tinfo)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "credentials", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += (*(this->credentials)).write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "filenames", ::apache::thrift::protocol::T_LIST, 3);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> ((*(this->filenames)).size ()));
		  std::vector<std::string>::const_iterator _iter316;
		  for (_iter316 = (*(this->filenames)).begin ();
		      _iter316 != (*(this->filenames)).end (); ++_iter316)
		    {
		      xfer += oprot->writeString ((*_iter316));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    TabletClientServiceClient::startScan (
		::org::apache::accumulo::core::data::thrift::InitialScan& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent,
		const ::org::apache::accumulo::core::data::thrift::TRange& range,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::TColumn> & columns,
		const int32_t batchSize,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList,
		const std::map<std::string, std::map<std::string, std::string> > & ssio,
		const std::vector<std::string> & authorizations,
		const bool waitForWrites, const bool isolated,
		const int64_t readaheadThreshold)
	    {
	      send_startScan (tinfo, credentials, extent, range, columns,
			      batchSize, ssiList, ssio, authorizations,
			      waitForWrites, isolated, readaheadThreshold);
	      recv_startScan (_return);
	    }

	    void
	    TabletClientServiceClient::send_startScan (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent,
		const ::org::apache::accumulo::core::data::thrift::TRange& range,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::TColumn> & columns,
		const int32_t batchSize,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList,
		const std::map<std::string, std::map<std::string, std::string> > & ssio,
		const std::vector<std::string> & authorizations,
		const bool waitForWrites, const bool isolated,
		const int64_t readaheadThreshold)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("startScan",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_startScan_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.extent = &extent;
	      args.range = &range;
	      args.columns = &columns;
	      args.batchSize = &batchSize;
	      args.ssiList = &ssiList;
	      args.ssio = &ssio;
	      args.authorizations = &authorizations;
	      args.waitForWrites = &waitForWrites;
	      args.isolated = &isolated;
	      args.readaheadThreshold = &readaheadThreshold;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_startScan (
		::org::apache::accumulo::core::data::thrift::InitialScan& _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("startScan") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_startScan_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      if (result.__isset.nste)
		{
		  throw result.nste;
		}
	      if (result.__isset.tmfe)
		{
		  throw result.tmfe;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "startScan failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::continueScan (
		::org::apache::accumulo::core::data::thrift::ScanResult& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::ScanID scanID)
	    {
	      send_continueScan (tinfo, scanID);
	      recv_continueScan (_return);
	    }

	    void
	    TabletClientServiceClient::send_continueScan (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::ScanID scanID)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("continueScan",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_continueScan_pargs args;
	      args.tinfo = &tinfo;
	      args.scanID = &scanID;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_continueScan (
		::org::apache::accumulo::core::data::thrift::ScanResult& _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("continueScan") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_continueScan_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.nssi)
		{
		  throw result.nssi;
		}
	      if (result.__isset.nste)
		{
		  throw result.nste;
		}
	      if (result.__isset.tmfe)
		{
		  throw result.tmfe;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "continueScan failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::closeScan (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::ScanID scanID)
	    {
	      send_closeScan (tinfo, scanID);
	    }

	    void
	    TabletClientServiceClient::send_closeScan (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::ScanID scanID)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("closeScan",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_closeScan_pargs args;
	      args.tinfo = &tinfo;
	      args.scanID = &scanID;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::startMultiScan (
		::org::apache::accumulo::core::data::thrift::InitialMultiScan& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const ::org::apache::accumulo::core::data::thrift::ScanBatch& batch,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::TColumn> & columns,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList,
		const std::map<std::string, std::map<std::string, std::string> > & ssio,
		const std::vector<std::string> & authorizations,
		const bool waitForWrites)
	    {
	      send_startMultiScan (tinfo, credentials, batch, columns, ssiList,
				   ssio, authorizations, waitForWrites);
	      recv_startMultiScan (_return);
	    }

	    void
	    TabletClientServiceClient::send_startMultiScan (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const ::org::apache::accumulo::core::data::thrift::ScanBatch& batch,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::TColumn> & columns,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList,
		const std::map<std::string, std::map<std::string, std::string> > & ssio,
		const std::vector<std::string> & authorizations,
		const bool waitForWrites)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("startMultiScan",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_startMultiScan_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.batch = &batch;
	      args.columns = &columns;
	      args.ssiList = &ssiList;
	      args.ssio = &ssio;
	      args.authorizations = &authorizations;
	      args.waitForWrites = &waitForWrites;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_startMultiScan (
		::org::apache::accumulo::core::data::thrift::InitialMultiScan& _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("startMultiScan") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_startMultiScan_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "startMultiScan failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::continueMultiScan (
		::org::apache::accumulo::core::data::thrift::MultiScanResult& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::ScanID scanID)
	    {
	      send_continueMultiScan (tinfo, scanID);
	      recv_continueMultiScan (_return);
	    }

	    void
	    TabletClientServiceClient::send_continueMultiScan (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::ScanID scanID)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("continueMultiScan",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_continueMultiScan_pargs args;
	      args.tinfo = &tinfo;
	      args.scanID = &scanID;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_continueMultiScan (
		::org::apache::accumulo::core::data::thrift::MultiScanResult& _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("continueMultiScan") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_continueMultiScan_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.nssi)
		{
		  throw result.nssi;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "continueMultiScan failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::closeMultiScan (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::ScanID scanID)
	    {
	      send_closeMultiScan (tinfo, scanID);
	      recv_closeMultiScan ();
	    }

	    void
	    TabletClientServiceClient::send_closeMultiScan (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::ScanID scanID)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("closeMultiScan",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_closeMultiScan_pargs args;
	      args.tinfo = &tinfo;
	      args.scanID = &scanID;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_closeMultiScan ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("closeMultiScan") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_closeMultiScan_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.nssi)
		{
		  throw result.nssi;
		}
	      return;
	    }

	    ::org::apache::accumulo::core::data::thrift::UpdateID
	    TabletClientServiceClient::startUpdate (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      send_startUpdate (tinfo, credentials);
	      return recv_startUpdate ();
	    }

	    void
	    TabletClientServiceClient::send_startUpdate (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("startUpdate",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_startUpdate_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    ::org::apache::accumulo::core::data::thrift::UpdateID
	    TabletClientServiceClient::recv_startUpdate ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("startUpdate") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      ::org::apache::accumulo::core::data::thrift::UpdateID _return;
	      TabletClientService_startUpdate_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  return _return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "startUpdate failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::applyUpdates (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID updateID,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::TMutation> & mutations)
	    {
	      send_applyUpdates (tinfo, updateID, keyExtent, mutations);
	    }

	    void
	    TabletClientServiceClient::send_applyUpdates (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID updateID,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent,
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::TMutation> & mutations)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("applyUpdates",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_applyUpdates_pargs args;
	      args.tinfo = &tinfo;
	      args.updateID = &updateID;
	      args.keyExtent = &keyExtent;
	      args.mutations = &mutations;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::closeUpdate (
		::org::apache::accumulo::core::data::thrift::UpdateErrors& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID updateID)
	    {
	      send_closeUpdate (tinfo, updateID);
	      recv_closeUpdate (_return);
	    }

	    void
	    TabletClientServiceClient::send_closeUpdate (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID updateID)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("closeUpdate",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_closeUpdate_pargs args;
	      args.tinfo = &tinfo;
	      args.updateID = &updateID;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_closeUpdate (
		::org::apache::accumulo::core::data::thrift::UpdateErrors& _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("closeUpdate") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_closeUpdate_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.nssi)
		{
		  throw result.nssi;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "closeUpdate failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::update (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent,
		const ::org::apache::accumulo::core::data::thrift::TMutation& mutation)
	    {
	      send_update (tinfo, credentials, keyExtent, mutation);
	      recv_update ();
	    }

	    void
	    TabletClientServiceClient::send_update (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent,
		const ::org::apache::accumulo::core::data::thrift::TMutation& mutation)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("update",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_update_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.keyExtent = &keyExtent;
	      args.mutation = &mutation;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_update ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("update") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_update_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      if (result.__isset.nste)
		{
		  throw result.nste;
		}
	      if (result.__isset.cve)
		{
		  throw result.cve;
		}
	      return;
	    }

	    void
	    TabletClientServiceClient::startConditionalUpdate (
		::org::apache::accumulo::core::data::thrift::TConditionalSession& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::vector<std::string> & authorizations,
		const std::string& tableID)
	    {
	      send_startConditionalUpdate (tinfo, credentials, authorizations,
					   tableID);
	      recv_startConditionalUpdate (_return);
	    }

	    void
	    TabletClientServiceClient::send_startConditionalUpdate (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::vector<std::string> & authorizations,
		const std::string& tableID)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("startConditionalUpdate",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_startConditionalUpdate_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.authorizations = &authorizations;
	      args.tableID = &tableID;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_startConditionalUpdate (
		::org::apache::accumulo::core::data::thrift::TConditionalSession& _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("startConditionalUpdate") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_startConditionalUpdate_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "startConditionalUpdate failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::conditionalUpdate (
		std::vector<
		    ::org::apache::accumulo::core::data::thrift::TCMResult> & _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID sessID,
		const ::org::apache::accumulo::core::data::thrift::CMBatch& mutations,
		const std::vector<std::string> & symbols)
	    {
	      send_conditionalUpdate (tinfo, sessID, mutations, symbols);
	      recv_conditionalUpdate (_return);
	    }

	    void
	    TabletClientServiceClient::send_conditionalUpdate (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID sessID,
		const ::org::apache::accumulo::core::data::thrift::CMBatch& mutations,
		const std::vector<std::string> & symbols)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("conditionalUpdate",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_conditionalUpdate_pargs args;
	      args.tinfo = &tinfo;
	      args.sessID = &sessID;
	      args.mutations = &mutations;
	      args.symbols = &symbols;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_conditionalUpdate (
		std::vector<
		    ::org::apache::accumulo::core::data::thrift::TCMResult> & _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("conditionalUpdate") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_conditionalUpdate_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.nssi)
		{
		  throw result.nssi;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "conditionalUpdate failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::invalidateConditionalUpdate (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID sessID)
	    {
	      send_invalidateConditionalUpdate (tinfo, sessID);
	      recv_invalidateConditionalUpdate ();
	    }

	    void
	    TabletClientServiceClient::send_invalidateConditionalUpdate (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID sessID)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("invalidateConditionalUpdate",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_invalidateConditionalUpdate_pargs args;
	      args.tinfo = &tinfo;
	      args.sessID = &sessID;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_invalidateConditionalUpdate ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("invalidateConditionalUpdate") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_invalidateConditionalUpdate_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      return;
	    }

	    void
	    TabletClientServiceClient::closeConditionalUpdate (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID sessID)
	    {
	      send_closeConditionalUpdate (tinfo, sessID);
	    }

	    void
	    TabletClientServiceClient::send_closeConditionalUpdate (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::data::thrift::UpdateID sessID)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("closeConditionalUpdate",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_closeConditionalUpdate_pargs args;
	      args.tinfo = &tinfo;
	      args.sessID = &sessID;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::bulkImport (
		std::vector<
		    ::org::apache::accumulo::core::data::thrift::TKeyExtent> & _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const int64_t tid,
		const ::org::apache::accumulo::core::data::thrift::TabletFiles& files,
		const bool setTime)
	    {
	      send_bulkImport (tinfo, credentials, tid, files, setTime);
	      recv_bulkImport (_return);
	    }

	    void
	    TabletClientServiceClient::send_bulkImport (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const int64_t tid,
		const ::org::apache::accumulo::core::data::thrift::TabletFiles& files,
		const bool setTime)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("bulkImport",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_bulkImport_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.tid = &tid;
	      args.files = &files;
	      args.setTime = &setTime;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_bulkImport (
		std::vector<
		    ::org::apache::accumulo::core::data::thrift::TKeyExtent> & _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("bulkImport") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_bulkImport_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "bulkImport failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::splitTablet (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent,
		const std::string& splitPoint)
	    {
	      send_splitTablet (tinfo, credentials, extent, splitPoint);
	      recv_splitTablet ();
	    }

	    void
	    TabletClientServiceClient::send_splitTablet (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent,
		const std::string& splitPoint)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("splitTablet",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_splitTablet_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.extent = &extent;
	      args.splitPoint = &splitPoint;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_splitTablet ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("splitTablet") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_splitTablet_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      if (result.__isset.nste)
		{
		  throw result.nste;
		}
	      return;
	    }

	    void
	    TabletClientServiceClient::loadTablet (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent)
	    {
	      send_loadTablet (tinfo, credentials, lock, extent);
	    }

	    void
	    TabletClientServiceClient::send_loadTablet (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("loadTablet",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_loadTablet_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.lock = &lock;
	      args.extent = &extent;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::unloadTablet (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent,
		const bool save)
	    {
	      send_unloadTablet (tinfo, credentials, lock, extent, save);
	    }

	    void
	    TabletClientServiceClient::send_unloadTablet (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent,
		const bool save)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("unloadTablet",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_unloadTablet_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.lock = &lock;
	      args.extent = &extent;
	      args.save = &save;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::flush (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock, const std::string& tableId,
		const std::string& startRow, const std::string& endRow)
	    {
	      send_flush (tinfo, credentials, lock, tableId, startRow, endRow);
	    }

	    void
	    TabletClientServiceClient::send_flush (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock, const std::string& tableId,
		const std::string& startRow, const std::string& endRow)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("flush",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_flush_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.lock = &lock;
	      args.tableId = &tableId;
	      args.startRow = &startRow;
	      args.endRow = &endRow;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::flushTablet (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent)
	    {
	      send_flushTablet (tinfo, credentials, lock, extent);
	    }

	    void
	    TabletClientServiceClient::send_flushTablet (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("flushTablet",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_flushTablet_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.lock = &lock;
	      args.extent = &extent;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::chop (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent)
	    {
	      send_chop (tinfo, credentials, lock, extent);
	    }

	    void
	    TabletClientServiceClient::send_chop (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock,
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("chop",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_chop_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.lock = &lock;
	      args.extent = &extent;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::compact (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock, const std::string& tableId,
		const std::string& startRow, const std::string& endRow)
	    {
	      send_compact (tinfo, credentials, lock, tableId, startRow,
			    endRow);
	    }

	    void
	    TabletClientServiceClient::send_compact (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock, const std::string& tableId,
		const std::string& startRow, const std::string& endRow)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("compact",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_compact_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.lock = &lock;
	      args.tableId = &tableId;
	      args.startRow = &startRow;
	      args.endRow = &endRow;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::getTabletServerStatus (
		::org::apache::accumulo::core::master::thrift::TabletServerStatus& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      send_getTabletServerStatus (tinfo, credentials);
	      recv_getTabletServerStatus (_return);
	    }

	    void
	    TabletClientServiceClient::send_getTabletServerStatus (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("getTabletServerStatus",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_getTabletServerStatus_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_getTabletServerStatus (
		::org::apache::accumulo::core::master::thrift::TabletServerStatus& _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("getTabletServerStatus") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_getTabletServerStatus_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "getTabletServerStatus failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::getTabletStats (
		std::vector<TabletStats> & _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableId)
	    {
	      send_getTabletStats (tinfo, credentials, tableId);
	      recv_getTabletStats (_return);
	    }

	    void
	    TabletClientServiceClient::send_getTabletStats (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& tableId)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("getTabletStats",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_getTabletStats_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.tableId = &tableId;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_getTabletStats (
		std::vector<TabletStats> & _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("getTabletStats") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_getTabletStats_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "getTabletStats failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::getHistoricalStats (
		TabletStats& _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      send_getHistoricalStats (tinfo, credentials);
	      recv_getHistoricalStats (_return);
	    }

	    void
	    TabletClientServiceClient::send_getHistoricalStats (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("getHistoricalStats",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_getHistoricalStats_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_getHistoricalStats (
		TabletStats& _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("getHistoricalStats") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_getHistoricalStats_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "getHistoricalStats failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::halt (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock)
	    {
	      send_halt (tinfo, credentials, lock);
	      recv_halt ();
	    }

	    void
	    TabletClientServiceClient::send_halt (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("halt",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_halt_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.lock = &lock;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_halt ()
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("halt") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_halt_presult result;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      return;
	    }

	    void
	    TabletClientServiceClient::fastHalt (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock)
	    {
	      send_fastHalt (tinfo, credentials, lock);
	    }

	    void
	    TabletClientServiceClient::send_fastHalt (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::string& lock)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("fastHalt",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_fastHalt_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.lock = &lock;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::getActiveScans (
		std::vector<ActiveScan> & _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      send_getActiveScans (tinfo, credentials);
	      recv_getActiveScans (_return);
	    }

	    void
	    TabletClientServiceClient::send_getActiveScans (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("getActiveScans",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_getActiveScans_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_getActiveScans (
		std::vector<ActiveScan> & _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("getActiveScans") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_getActiveScans_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "getActiveScans failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::getActiveCompactions (
		std::vector<ActiveCompaction> & _return,
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      send_getActiveCompactions (tinfo, credentials);
	      recv_getActiveCompactions (_return);
	    }

	    void
	    TabletClientServiceClient::send_getActiveCompactions (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("getActiveCompactions",
					 ::apache::thrift::protocol::T_CALL,
					 cseqid);

	      TabletClientService_getActiveCompactions_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    void
	    TabletClientServiceClient::recv_getActiveCompactions (
		std::vector<ActiveCompaction> & _return)
	    {

	      int32_t rseqid = 0;
	      std::string fname;
	      ::apache::thrift::protocol::TMessageType mtype;

	      iprot_->readMessageBegin (fname, mtype, rseqid);
	      if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
		{
		  ::apache::thrift::TApplicationException x;
		  x.read (iprot_);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		  throw x;
		}
	      if (mtype != ::apache::thrift::protocol::T_REPLY)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      if (fname.compare ("getActiveCompactions") != 0)
		{
		  iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		  iprot_->readMessageEnd ();
		  iprot_->getTransport ()->readEnd ();
		}
	      TabletClientService_getActiveCompactions_presult result;
	      result.success = &_return;
	      result.read (iprot_);
	      iprot_->readMessageEnd ();
	      iprot_->getTransport ()->readEnd ();

	      if (result.__isset.success)
		{
		  // _return pointer has now been filled
		  return;
		}
	      if (result.__isset.sec)
		{
		  throw result.sec;
		}
	      throw ::apache::thrift::TApplicationException (
		  ::apache::thrift::TApplicationException::MISSING_RESULT,
		  "getActiveCompactions failed: unknown result");
	    }

	    void
	    TabletClientServiceClient::removeLogs (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::vector<std::string> & filenames)
	    {
	      send_removeLogs (tinfo, credentials, filenames);
	    }

	    void
	    TabletClientServiceClient::send_removeLogs (
		const ::org::apache::accumulo::trace::thrift::TInfo& tinfo,
		const ::org::apache::accumulo::core::security::thrift::TCredentials& credentials,
		const std::vector<std::string> & filenames)
	    {
	      int32_t cseqid = 0;
	      oprot_->writeMessageBegin ("removeLogs",
					 ::apache::thrift::protocol::T_ONEWAY,
					 cseqid);

	      TabletClientService_removeLogs_pargs args;
	      args.tinfo = &tinfo;
	      args.credentials = &credentials;
	      args.filenames = &filenames;
	      args.write (oprot_);

	      oprot_->writeMessageEnd ();
	      oprot_->getTransport ()->writeEnd ();
	      oprot_->getTransport ()->flush ();
	    }

	    bool
	    TabletClientServiceProcessor::dispatchCall (
		::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot,
		const std::string& fname, int32_t seqid, void* callContext)
	    {
	      ProcessMap::iterator pfn;
	      pfn = processMap_.find (fname);
	      if (pfn == processMap_.end ())
		{
		  return ::org::apache::accumulo::core::client::impl::thrift::ClientServiceProcessor::dispatchCall (
		      iprot, oprot, fname, seqid, callContext);
		}
	      (this->*(pfn->second)) (seqid, iprot, oprot, callContext);
	      return true;
	    }

	    void
	    TabletClientServiceProcessor::process_startScan (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.startScan", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.startScan");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.startScan");
		}

	      TabletClientService_startScan_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.startScan", bytes);
		}

	      TabletClientService_startScan_result result;
	      try
		{
		  iface_->startScan (result.success, args.tinfo,
				     args.credentials, args.extent, args.range,
				     args.columns, args.batchSize, args.ssiList,
				     args.ssio, args.authorizations,
				     args.waitForWrites, args.isolated,
				     args.readaheadThreshold);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (NotServingTabletException &nste)
		{
		  result.nste = nste;
		  result.__isset.nste = true;
		}
	      catch (TooManyFilesException &tmfe)
		{
		  result.tmfe = tmfe;
		  result.__isset.tmfe = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.startScan");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "startScan", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.startScan");
		}

	      oprot->writeMessageBegin ("startScan",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.startScan", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_continueScan (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.continueScan", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.continueScan");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.continueScan");
		}

	      TabletClientService_continueScan_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.continueScan", bytes);
		}

	      TabletClientService_continueScan_result result;
	      try
		{
		  iface_->continueScan (result.success, args.tinfo,
					args.scanID);
		  result.__isset.success = true;
		}
	      catch (NoSuchScanIDException &nssi)
		{
		  result.nssi = nssi;
		  result.__isset.nssi = true;
		}
	      catch (NotServingTabletException &nste)
		{
		  result.nste = nste;
		  result.__isset.nste = true;
		}
	      catch (TooManyFilesException &tmfe)
		{
		  result.tmfe = tmfe;
		  result.__isset.tmfe = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.continueScan");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "continueScan", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.continueScan");
		}

	      oprot->writeMessageBegin ("continueScan",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.continueScan", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_closeScan (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.closeScan", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.closeScan");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.closeScan");
		}

	      TabletClientService_closeScan_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.closeScan", bytes);
		}

	      try
		{
		  iface_->closeScan (args.tinfo, args.scanID);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.closeScan");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.closeScan");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_startMultiScan (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.startMultiScan", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.startMultiScan");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.startMultiScan");
		}

	      TabletClientService_startMultiScan_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.startMultiScan", bytes);
		}

	      TabletClientService_startMultiScan_result result;
	      try
		{
		  iface_->startMultiScan (result.success, args.tinfo,
					  args.credentials, args.batch,
					  args.columns, args.ssiList, args.ssio,
					  args.authorizations,
					  args.waitForWrites);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.startMultiScan");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "startMultiScan", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.startMultiScan");
		}

	      oprot->writeMessageBegin ("startMultiScan",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.startMultiScan", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_continueMultiScan (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.continueMultiScan", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.continueMultiScan");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.continueMultiScan");
		}

	      TabletClientService_continueMultiScan_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.continueMultiScan", bytes);
		}

	      TabletClientService_continueMultiScan_result result;
	      try
		{
		  iface_->continueMultiScan (result.success, args.tinfo,
					     args.scanID);
		  result.__isset.success = true;
		}
	      catch (NoSuchScanIDException &nssi)
		{
		  result.nssi = nssi;
		  result.__isset.nssi = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.continueMultiScan");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "continueMultiScan",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.continueMultiScan");
		}

	      oprot->writeMessageBegin ("continueMultiScan",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.continueMultiScan", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_closeMultiScan (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.closeMultiScan", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.closeMultiScan");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.closeMultiScan");
		}

	      TabletClientService_closeMultiScan_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.closeMultiScan", bytes);
		}

	      TabletClientService_closeMultiScan_result result;
	      try
		{
		  iface_->closeMultiScan (args.tinfo, args.scanID);
		}
	      catch (NoSuchScanIDException &nssi)
		{
		  result.nssi = nssi;
		  result.__isset.nssi = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.closeMultiScan");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "closeMultiScan", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.closeMultiScan");
		}

	      oprot->writeMessageBegin ("closeMultiScan",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.closeMultiScan", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_startUpdate (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.startUpdate", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.startUpdate");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.startUpdate");
		}

	      TabletClientService_startUpdate_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.startUpdate", bytes);
		}

	      TabletClientService_startUpdate_result result;
	      try
		{
		  result.success = iface_->startUpdate (args.tinfo,
							args.credentials);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.startUpdate");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "startUpdate", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.startUpdate");
		}

	      oprot->writeMessageBegin ("startUpdate",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.startUpdate", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_applyUpdates (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.applyUpdates", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.applyUpdates");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.applyUpdates");
		}

	      TabletClientService_applyUpdates_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.applyUpdates", bytes);
		}

	      try
		{
		  iface_->applyUpdates (args.tinfo, args.updateID,
					args.keyExtent, args.mutations);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.applyUpdates");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.applyUpdates");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_closeUpdate (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.closeUpdate", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.closeUpdate");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.closeUpdate");
		}

	      TabletClientService_closeUpdate_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.closeUpdate", bytes);
		}

	      TabletClientService_closeUpdate_result result;
	      try
		{
		  iface_->closeUpdate (result.success, args.tinfo,
				       args.updateID);
		  result.__isset.success = true;
		}
	      catch (NoSuchScanIDException &nssi)
		{
		  result.nssi = nssi;
		  result.__isset.nssi = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.closeUpdate");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "closeUpdate", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.closeUpdate");
		}

	      oprot->writeMessageBegin ("closeUpdate",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.closeUpdate", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_update (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.update", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.update");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (ctx,
						"TabletClientService.update");
		}

	      TabletClientService_update_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (ctx,
						 "TabletClientService.update",
						 bytes);
		}

	      TabletClientService_update_result result;
	      try
		{
		  iface_->update (args.tinfo, args.credentials, args.keyExtent,
				  args.mutation);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (NotServingTabletException &nste)
		{
		  result.nste = nste;
		  result.__isset.nste = true;
		}
	      catch (ConstraintViolationException &cve)
		{
		  result.cve = cve;
		  result.__isset.cve = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.update");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "update", ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (ctx,
						 "TabletClientService.update");
		}

	      oprot->writeMessageBegin ("update",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (ctx,
						  "TabletClientService.update",
						  bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_startConditionalUpdate (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.startConditionalUpdate",
		      callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.startConditionalUpdate");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.startConditionalUpdate");
		}

	      TabletClientService_startConditionalUpdate_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.startConditionalUpdate", bytes);
		}

	      TabletClientService_startConditionalUpdate_result result;
	      try
		{
		  iface_->startConditionalUpdate (result.success, args.tinfo,
						  args.credentials,
						  args.authorizations,
						  args.tableID);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.startConditionalUpdate");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "startConditionalUpdate",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.startConditionalUpdate");
		}

	      oprot->writeMessageBegin ("startConditionalUpdate",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.startConditionalUpdate", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_conditionalUpdate (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.conditionalUpdate", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.conditionalUpdate");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.conditionalUpdate");
		}

	      TabletClientService_conditionalUpdate_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.conditionalUpdate", bytes);
		}

	      TabletClientService_conditionalUpdate_result result;
	      try
		{
		  iface_->conditionalUpdate (result.success, args.tinfo,
					     args.sessID, args.mutations,
					     args.symbols);
		  result.__isset.success = true;
		}
	      catch (NoSuchScanIDException &nssi)
		{
		  result.nssi = nssi;
		  result.__isset.nssi = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.conditionalUpdate");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "conditionalUpdate",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.conditionalUpdate");
		}

	      oprot->writeMessageBegin ("conditionalUpdate",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.conditionalUpdate", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_invalidateConditionalUpdate (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.invalidateConditionalUpdate",
		      callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.invalidateConditionalUpdate");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.invalidateConditionalUpdate");
		}

	      TabletClientService_invalidateConditionalUpdate_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.invalidateConditionalUpdate",
		      bytes);
		}

	      TabletClientService_invalidateConditionalUpdate_result result;
	      try
		{
		  iface_->invalidateConditionalUpdate (args.tinfo, args.sessID);
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx,
			  "TabletClientService.invalidateConditionalUpdate");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "invalidateConditionalUpdate",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.invalidateConditionalUpdate");
		}

	      oprot->writeMessageBegin ("invalidateConditionalUpdate",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.invalidateConditionalUpdate",
		      bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_closeConditionalUpdate (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.closeConditionalUpdate",
		      callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.closeConditionalUpdate");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.closeConditionalUpdate");
		}

	      TabletClientService_closeConditionalUpdate_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.closeConditionalUpdate", bytes);
		}

	      try
		{
		  iface_->closeConditionalUpdate (args.tinfo, args.sessID);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.closeConditionalUpdate");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.closeConditionalUpdate");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_bulkImport (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.bulkImport", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.bulkImport");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.bulkImport");
		}

	      TabletClientService_bulkImport_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.bulkImport", bytes);
		}

	      TabletClientService_bulkImport_result result;
	      try
		{
		  iface_->bulkImport (result.success, args.tinfo,
				      args.credentials, args.tid, args.files,
				      args.setTime);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.bulkImport");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "bulkImport", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.bulkImport");
		}

	      oprot->writeMessageBegin ("bulkImport",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.bulkImport", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_splitTablet (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.splitTablet", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.splitTablet");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.splitTablet");
		}

	      TabletClientService_splitTablet_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.splitTablet", bytes);
		}

	      TabletClientService_splitTablet_result result;
	      try
		{
		  iface_->splitTablet (args.tinfo, args.credentials,
				       args.extent, args.splitPoint);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (NotServingTabletException &nste)
		{
		  result.nste = nste;
		  result.__isset.nste = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.splitTablet");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "splitTablet", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.splitTablet");
		}

	      oprot->writeMessageBegin ("splitTablet",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.splitTablet", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_loadTablet (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.loadTablet", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.loadTablet");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.loadTablet");
		}

	      TabletClientService_loadTablet_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.loadTablet", bytes);
		}

	      try
		{
		  iface_->loadTablet (args.tinfo, args.credentials, args.lock,
				      args.extent);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.loadTablet");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.loadTablet");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_unloadTablet (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.unloadTablet", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.unloadTablet");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.unloadTablet");
		}

	      TabletClientService_unloadTablet_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.unloadTablet", bytes);
		}

	      try
		{
		  iface_->unloadTablet (args.tinfo, args.credentials, args.lock,
					args.extent, args.save);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.unloadTablet");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.unloadTablet");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_flush (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.flush", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx, "TabletClientService.flush");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (ctx,
						"TabletClientService.flush");
		}

	      TabletClientService_flush_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (ctx,
						 "TabletClientService.flush",
						 bytes);
		}

	      try
		{
		  iface_->flush (args.tinfo, args.credentials, args.lock,
				 args.tableId, args.startRow, args.endRow);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.flush");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.flush");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_flushTablet (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.flushTablet", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.flushTablet");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.flushTablet");
		}

	      TabletClientService_flushTablet_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.flushTablet", bytes);
		}

	      try
		{
		  iface_->flushTablet (args.tinfo, args.credentials, args.lock,
				       args.extent);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.flushTablet");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.flushTablet");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_chop (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.chop", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx, "TabletClientService.chop");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (ctx,
						"TabletClientService.chop");
		}

	      TabletClientService_chop_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (ctx,
						 "TabletClientService.chop",
						 bytes);
		}

	      try
		{
		  iface_->chop (args.tinfo, args.credentials, args.lock,
				args.extent);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.chop");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.chop");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_compact (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.compact", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.compact");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (ctx,
						"TabletClientService.compact");
		}

	      TabletClientService_compact_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (ctx,
						 "TabletClientService.compact",
						 bytes);
		}

	      try
		{
		  iface_->compact (args.tinfo, args.credentials, args.lock,
				   args.tableId, args.startRow, args.endRow);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.compact");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.compact");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_getTabletServerStatus (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.getTabletServerStatus", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.getTabletServerStatus");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.getTabletServerStatus");
		}

	      TabletClientService_getTabletServerStatus_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.getTabletServerStatus", bytes);
		}

	      TabletClientService_getTabletServerStatus_result result;
	      try
		{
		  iface_->getTabletServerStatus (result.success, args.tinfo,
						 args.credentials);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.getTabletServerStatus");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "getTabletServerStatus",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.getTabletServerStatus");
		}

	      oprot->writeMessageBegin ("getTabletServerStatus",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.getTabletServerStatus", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_getTabletStats (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.getTabletStats", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.getTabletStats");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.getTabletStats");
		}

	      TabletClientService_getTabletStats_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.getTabletStats", bytes);
		}

	      TabletClientService_getTabletStats_result result;
	      try
		{
		  iface_->getTabletStats (result.success, args.tinfo,
					  args.credentials, args.tableId);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.getTabletStats");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "getTabletStats", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.getTabletStats");
		}

	      oprot->writeMessageBegin ("getTabletStats",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.getTabletStats", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_getHistoricalStats (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.getHistoricalStats", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.getHistoricalStats");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.getHistoricalStats");
		}

	      TabletClientService_getHistoricalStats_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.getHistoricalStats", bytes);
		}

	      TabletClientService_getHistoricalStats_result result;
	      try
		{
		  iface_->getHistoricalStats (result.success, args.tinfo,
					      args.credentials);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.getHistoricalStats");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "getHistoricalStats",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.getHistoricalStats");
		}

	      oprot->writeMessageBegin ("getHistoricalStats",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.getHistoricalStats", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_halt (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.halt", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx, "TabletClientService.halt");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (ctx,
						"TabletClientService.halt");
		}

	      TabletClientService_halt_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (ctx,
						 "TabletClientService.halt",
						 bytes);
		}

	      TabletClientService_halt_result result;
	      try
		{
		  iface_->halt (args.tinfo, args.credentials, args.lock);
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.halt");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "halt", ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (ctx,
						 "TabletClientService.halt");
		}

	      oprot->writeMessageBegin ("halt",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (ctx,
						  "TabletClientService.halt",
						  bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_fastHalt (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.fastHalt", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.fastHalt");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (ctx,
						"TabletClientService.fastHalt");
		}

	      TabletClientService_fastHalt_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (ctx,
						 "TabletClientService.fastHalt",
						 bytes);
		}

	      try
		{
		  iface_->fastHalt (args.tinfo, args.credentials, args.lock);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.fastHalt");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.fastHalt");
		}

	      return;
	    }

	    void
	    TabletClientServiceProcessor::process_getActiveScans (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.getActiveScans", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.getActiveScans");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.getActiveScans");
		}

	      TabletClientService_getActiveScans_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.getActiveScans", bytes);
		}

	      TabletClientService_getActiveScans_result result;
	      try
		{
		  iface_->getActiveScans (result.success, args.tinfo,
					  args.credentials);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.getActiveScans");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "getActiveScans", ::apache::thrift::protocol::T_EXCEPTION,
		      seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.getActiveScans");
		}

	      oprot->writeMessageBegin ("getActiveScans",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.getActiveScans", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_getActiveCompactions (
		int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.getActiveCompactions", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.getActiveCompactions");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.getActiveCompactions");
		}

	      TabletClientService_getActiveCompactions_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.getActiveCompactions", bytes);
		}

	      TabletClientService_getActiveCompactions_result result;
	      try
		{
		  iface_->getActiveCompactions (result.success, args.tinfo,
						args.credentials);
		  result.__isset.success = true;
		}
	      catch (::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException &sec)
		{
		  result.sec = sec;
		  result.__isset.sec = true;
		}
	      catch (const std::exception& e)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.getActiveCompactions");
		    }

		  ::apache::thrift::TApplicationException x (e.what ());
		  oprot->writeMessageBegin (
		      "getActiveCompactions",
		      ::apache::thrift::protocol::T_EXCEPTION, seqid);
		  x.write (oprot);
		  oprot->writeMessageEnd ();
		  oprot->getTransport ()->writeEnd ();
		  oprot->getTransport ()->flush ();
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preWrite (
		      ctx, "TabletClientService.getActiveCompactions");
		}

	      oprot->writeMessageBegin ("getActiveCompactions",
					::apache::thrift::protocol::T_REPLY,
					seqid);
	      result.write (oprot);
	      oprot->writeMessageEnd ();
	      bytes = oprot->getTransport ()->writeEnd ();
	      oprot->getTransport ()->flush ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postWrite (
		      ctx, "TabletClientService.getActiveCompactions", bytes);
		}
	    }

	    void
	    TabletClientServiceProcessor::process_removeLogs (
		int32_t, ::apache::thrift::protocol::TProtocol* iprot,
		::apache::thrift::protocol::TProtocol*, void* callContext)
	    {
	      void* ctx = NULL;
	      if (this->eventHandler_.get () != NULL)
		{
		  ctx = this->eventHandler_->getContext (
		      "TabletClientService.removeLogs", callContext);
		}
	      ::apache::thrift::TProcessorContextFreer freer (
		  this->eventHandler_.get (), ctx,
		  "TabletClientService.removeLogs");

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->preRead (
		      ctx, "TabletClientService.removeLogs");
		}

	      TabletClientService_removeLogs_args args;
	      args.read (iprot);
	      iprot->readMessageEnd ();
	      uint32_t bytes = iprot->getTransport ()->readEnd ();

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->postRead (
		      ctx, "TabletClientService.removeLogs", bytes);
		}

	      try
		{
		  iface_->removeLogs (args.tinfo, args.credentials,
				      args.filenames);
		}
	      catch (const std::exception&)
		{
		  if (this->eventHandler_.get () != NULL)
		    {
		      this->eventHandler_->handlerError (
			  ctx, "TabletClientService.removeLogs");
		    }
		  return;
		}

	      if (this->eventHandler_.get () != NULL)
		{
		  this->eventHandler_->asyncComplete (
		      ctx, "TabletClientService.removeLogs");
		}

	      return;
	    }

	    ::boost::shared_ptr<::apache::thrift::TProcessor>
	    TabletClientServiceProcessorFactory::getProcessor (
		const ::apache::thrift::TConnectionInfo& connInfo)
	    {
	      ::apache::thrift::ReleaseHandler<TabletClientServiceIfFactory> cleanup (
		  handlerFactory_);
	      ::boost::shared_ptr<TabletClientServiceIf> handler (
		  handlerFactory_->getHandler (connInfo), cleanup);
	      ::boost::shared_ptr<::apache::thrift::TProcessor> processor (
		  new TabletClientServiceProcessor (handler));
	      return processor;
	    }
	  }
	}
      }
    }
  }
} // namespace

