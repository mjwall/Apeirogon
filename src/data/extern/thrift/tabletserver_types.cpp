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
#include "../../../../include/data/extern/thrift/tabletserver_types.h"

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
	namespace tabletserver
	{
	  namespace thrift
	  {

	    int _kScanTypeValues[] =
	      { ScanType::SINGLE, ScanType::BATCH };
	    const char* _kScanTypeNames[] =
	      { "SINGLE", "BATCH" };
	    const std::map<int, const char*> _ScanType_VALUES_TO_NAMES (
		::apache::thrift::TEnumIterator (2, _kScanTypeValues,
						 _kScanTypeNames),
		::apache::thrift::TEnumIterator (-1, NULL, NULL));

	    int _kScanStateValues[] =
	      { ScanState::IDLE, ScanState::RUNNING, ScanState::QUEUED };
	    const char* _kScanStateNames[] =
	      { "IDLE", "RUNNING", "QUEUED" };
	    const std::map<int, const char*> _ScanState_VALUES_TO_NAMES (
		::apache::thrift::TEnumIterator (3, _kScanStateValues,
						 _kScanStateNames),
		::apache::thrift::TEnumIterator (-1, NULL, NULL));

	    int _kCompactionTypeValues[] =
	      { CompactionType::MINOR, CompactionType::MERGE,
		  CompactionType::MAJOR, CompactionType::FULL };
	    const char* _kCompactionTypeNames[] =
	      { "MINOR", "MERGE", "MAJOR", "FULL" };
	    const std::map<int, const char*> _CompactionType_VALUES_TO_NAMES (
		::apache::thrift::TEnumIterator (4, _kCompactionTypeValues,
						 _kCompactionTypeNames),
		::apache::thrift::TEnumIterator (-1, NULL, NULL));

	    int _kCompactionReasonValues[] =
	      { CompactionReason::USER, CompactionReason::SYSTEM,
		  CompactionReason::CHOP, CompactionReason::IDLE,
		  CompactionReason::CLOSE };
	    const char* _kCompactionReasonNames[] =
	      { "USER", "SYSTEM", "CHOP", "IDLE", "CLOSE" };
	    const std::map<int, const char*> _CompactionReason_VALUES_TO_NAMES (
		::apache::thrift::TEnumIterator (5, _kCompactionReasonValues,
						 _kCompactionReasonNames),
		::apache::thrift::TEnumIterator (-1, NULL, NULL));

	    NotServingTabletException::~NotServingTabletException () throw ()
	    {
	    }

	    void
	    NotServingTabletException::__set_extent (
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& val)
	    {
	      this->extent = val;
	    }

	    const char* NotServingTabletException::ascii_fingerprint =
		"636807D016867BC3A79FD54005E0677E";
	    const uint8_t NotServingTabletException::binary_fingerprint[16] =
	      { 0x63, 0x68, 0x07, 0xD0, 0x16, 0x86, 0x7B, 0xC3, 0xA7, 0x9F,
		  0xD5, 0x40, 0x05, 0xE0, 0x67, 0x7E };

	    uint32_t
	    NotServingTabletException::read (
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
	    NotServingTabletException::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("NotServingTabletException");

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (NotServingTabletException &a, NotServingTabletException &b)
	    {
	      using ::std::swap;
	      swap (a.extent, b.extent);
	      swap (a.__isset, b.__isset);
	    }

	    NotServingTabletException::NotServingTabletException (
		const NotServingTabletException& other0) :
		TException ()
	    {
	      extent = other0.extent;
	      __isset = other0.__isset;
	    }
	    NotServingTabletException&
	    NotServingTabletException::operator= (
		const NotServingTabletException& other1)
	    {
	      extent = other1.extent;
	      __isset = other1.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const NotServingTabletException& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "NotServingTabletException(";
	      out << "extent=" << to_string (obj.extent);
	      out << ")";
	      return out;
	    }

	    TooManyFilesException::~TooManyFilesException () throw ()
	    {
	    }

	    void
	    TooManyFilesException::__set_extent (
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& val)
	    {
	      this->extent = val;
	    }

	    const char* TooManyFilesException::ascii_fingerprint =
		"636807D016867BC3A79FD54005E0677E";
	    const uint8_t TooManyFilesException::binary_fingerprint[16] =
	      { 0x63, 0x68, 0x07, 0xD0, 0x16, 0x86, 0x7B, 0xC3, 0xA7, 0x9F,
		  0xD5, 0x40, 0x05, 0xE0, 0x67, 0x7E };

	    uint32_t
	    TooManyFilesException::read (
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
	    TooManyFilesException::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TooManyFilesException");

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TooManyFilesException &a, TooManyFilesException &b)
	    {
	      using ::std::swap;
	      swap (a.extent, b.extent);
	      swap (a.__isset, b.__isset);
	    }

	    TooManyFilesException::TooManyFilesException (
		const TooManyFilesException& other2) :
		TException ()
	    {
	      extent = other2.extent;
	      __isset = other2.__isset;
	    }
	    TooManyFilesException&
	    TooManyFilesException::operator= (
		const TooManyFilesException& other3)
	    {
	      extent = other3.extent;
	      __isset = other3.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TooManyFilesException& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TooManyFilesException(";
	      out << "extent=" << to_string (obj.extent);
	      out << ")";
	      return out;
	    }

	    NoSuchScanIDException::~NoSuchScanIDException () throw ()
	    {
	    }

	    const char* NoSuchScanIDException::ascii_fingerprint =
		"99914B932BD37A50B983C5E7C90AE93B";
	    const uint8_t NoSuchScanIDException::binary_fingerprint[16] =
	      { 0x99, 0x91, 0x4B, 0x93, 0x2B, 0xD3, 0x7A, 0x50, 0xB9, 0x83,
		  0xC5, 0xE7, 0xC9, 0x0A, 0xE9, 0x3B };

	    uint32_t
	    NoSuchScanIDException::read (
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
	    NoSuchScanIDException::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("NoSuchScanIDException");

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (NoSuchScanIDException &a, NoSuchScanIDException &b)
	    {
	      using ::std::swap;
	      (void) a;
	      (void) b;
	    }

	    NoSuchScanIDException::NoSuchScanIDException (
		const NoSuchScanIDException& other4) :
		TException ()
	    {
	      (void) other4;
	    }
	    NoSuchScanIDException&
	    NoSuchScanIDException::operator= (
		const NoSuchScanIDException& other5)
	    {
	      (void) other5;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const NoSuchScanIDException& obj)
	    {
	      using ::apache::thrift::to_string;
	      (void) obj;
	      out << "NoSuchScanIDException(";
	      out << ")";
	      return out;
	    }

	    ConstraintViolationException::~ConstraintViolationException () throw ()
	    {
	    }

	    void
	    ConstraintViolationException::__set_violationSummaries (
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::TConstraintViolationSummary> & val)
	    {
	      this->violationSummaries = val;
	    }

	    const char* ConstraintViolationException::ascii_fingerprint =
		"3884B00559CED48471BE62CF7B94E4D1";
	    const uint8_t ConstraintViolationException::binary_fingerprint[16] =
	      { 0x38, 0x84, 0xB0, 0x05, 0x59, 0xCE, 0xD4, 0x84, 0x71, 0xBE,
		  0x62, 0xCF, 0x7B, 0x94, 0xE4, 0xD1 };

	    uint32_t
	    ConstraintViolationException::read (
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
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->violationSummaries.clear ();
			      uint32_t _size6;
			      ::apache::thrift::protocol::TType _etype9;
			      xfer += iprot->readListBegin (_etype9, _size6);
			      this->violationSummaries.resize (_size6);
			      uint32_t _i10;
			      for (_i10 = 0; _i10 < _size6; ++_i10)
				{
				  xfer += this->violationSummaries[_i10].read (
				      iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.violationSummaries = true;
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
	    ConstraintViolationException::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("ConstraintViolationException");

	      xfer += oprot->writeFieldBegin (
		  "violationSummaries", ::apache::thrift::protocol::T_LIST, 1);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->violationSummaries.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::TConstraintViolationSummary>::const_iterator _iter11;
		  for (_iter11 = this->violationSummaries.begin ();
		      _iter11 != this->violationSummaries.end (); ++_iter11)
		    {
		      xfer += (*_iter11).write (oprot);
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
	    swap (ConstraintViolationException &a,
		  ConstraintViolationException &b)
	    {
	      using ::std::swap;
	      swap (a.violationSummaries, b.violationSummaries);
	      swap (a.__isset, b.__isset);
	    }

	    ConstraintViolationException::ConstraintViolationException (
		const ConstraintViolationException& other12) :
		TException ()
	    {
	      violationSummaries = other12.violationSummaries;
	      __isset = other12.__isset;
	    }
	    ConstraintViolationException&
	    ConstraintViolationException::operator= (
		const ConstraintViolationException& other13)
	    {
	      violationSummaries = other13.violationSummaries;
	      __isset = other13.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out,
			const ConstraintViolationException& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "ConstraintViolationException(";
	      out << "violationSummaries="
		  << to_string (obj.violationSummaries);
	      out << ")";
	      return out;
	    }

	    ActionStats::~ActionStats () throw ()
	    {
	    }

	    void
	    ActionStats::__set_status (const int32_t val)
	    {
	      this->status = val;
	    }

	    void
	    ActionStats::__set_elapsed (const double val)
	    {
	      this->elapsed = val;
	    }

	    void
	    ActionStats::__set_num (const int32_t val)
	    {
	      this->num = val;
	    }

	    void
	    ActionStats::__set_count (const int64_t val)
	    {
	      this->count = val;
	    }

	    void
	    ActionStats::__set_sumDev (const double val)
	    {
	      this->sumDev = val;
	    }

	    void
	    ActionStats::__set_fail (const int32_t val)
	    {
	      this->fail = val;
	    }

	    void
	    ActionStats::__set_queueTime (const double val)
	    {
	      this->queueTime = val;
	    }

	    void
	    ActionStats::__set_queueSumDev (const double val)
	    {
	      this->queueSumDev = val;
	    }

	    const char* ActionStats::ascii_fingerprint =
		"38F10F0BD2F539F3CA606E0480459450";
	    const uint8_t ActionStats::binary_fingerprint[16] =
	      { 0x38, 0xF1, 0x0F, 0x0B, 0xD2, 0xF5, 0x39, 0xF3, 0xCA, 0x60,
		  0x6E, 0x04, 0x80, 0x45, 0x94, 0x50 };

	    uint32_t
	    ActionStats::read (::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->status);
			  this->__isset.status = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->elapsed);
			  this->__isset.elapsed = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->num);
			  this->__isset.num = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->count);
			  this->__isset.count = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->sumDev);
			  this->__isset.sumDev = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->fail);
			  this->__isset.fail = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->queueTime);
			  this->__isset.queueTime = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 8:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->queueSumDev);
			  this->__isset.queueSumDev = true;
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
	    ActionStats::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("ActionStats");

	      xfer += oprot->writeFieldBegin ("status",
					      ::apache::thrift::protocol::T_I32,
					      1);
	      xfer += oprot->writeI32 (this->status);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "elapsed", ::apache::thrift::protocol::T_DOUBLE, 2);
	      xfer += oprot->writeDouble (this->elapsed);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("num",
					      ::apache::thrift::protocol::T_I32,
					      3);
	      xfer += oprot->writeI32 (this->num);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("count",
					      ::apache::thrift::protocol::T_I64,
					      4);
	      xfer += oprot->writeI64 (this->count);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "sumDev", ::apache::thrift::protocol::T_DOUBLE, 5);
	      xfer += oprot->writeDouble (this->sumDev);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("fail",
					      ::apache::thrift::protocol::T_I32,
					      6);
	      xfer += oprot->writeI32 (this->fail);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "queueTime", ::apache::thrift::protocol::T_DOUBLE, 7);
	      xfer += oprot->writeDouble (this->queueTime);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "queueSumDev", ::apache::thrift::protocol::T_DOUBLE, 8);
	      xfer += oprot->writeDouble (this->queueSumDev);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (ActionStats &a, ActionStats &b)
	    {
	      using ::std::swap;
	      swap (a.status, b.status);
	      swap (a.elapsed, b.elapsed);
	      swap (a.num, b.num);
	      swap (a.count, b.count);
	      swap (a.sumDev, b.sumDev);
	      swap (a.fail, b.fail);
	      swap (a.queueTime, b.queueTime);
	      swap (a.queueSumDev, b.queueSumDev);
	      swap (a.__isset, b.__isset);
	    }

	    ActionStats::ActionStats (const ActionStats& other14)
	    {
	      status = other14.status;
	      elapsed = other14.elapsed;
	      num = other14.num;
	      count = other14.count;
	      sumDev = other14.sumDev;
	      fail = other14.fail;
	      queueTime = other14.queueTime;
	      queueSumDev = other14.queueSumDev;
	      __isset = other14.__isset;
	    }
	    ActionStats&
	    ActionStats::operator= (const ActionStats& other15)
	    {
	      status = other15.status;
	      elapsed = other15.elapsed;
	      num = other15.num;
	      count = other15.count;
	      sumDev = other15.sumDev;
	      fail = other15.fail;
	      queueTime = other15.queueTime;
	      queueSumDev = other15.queueSumDev;
	      __isset = other15.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const ActionStats& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "ActionStats(";
	      out << "status=" << to_string (obj.status);
	      out << ", " << "elapsed=" << to_string (obj.elapsed);
	      out << ", " << "num=" << to_string (obj.num);
	      out << ", " << "count=" << to_string (obj.count);
	      out << ", " << "sumDev=" << to_string (obj.sumDev);
	      out << ", " << "fail=" << to_string (obj.fail);
	      out << ", " << "queueTime=" << to_string (obj.queueTime);
	      out << ", " << "queueSumDev=" << to_string (obj.queueSumDev);
	      out << ")";
	      return out;
	    }

	    TabletStats::~TabletStats () throw ()
	    {
	    }

	    void
	    TabletStats::__set_extent (
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& val)
	    {
	      this->extent = val;
	    }

	    void
	    TabletStats::__set_majors (const ActionStats& val)
	    {
	      this->majors = val;
	    }

	    void
	    TabletStats::__set_minors (const ActionStats& val)
	    {
	      this->minors = val;
	    }

	    void
	    TabletStats::__set_splits (const ActionStats& val)
	    {
	      this->splits = val;
	    }

	    void
	    TabletStats::__set_numEntries (const int64_t val)
	    {
	      this->numEntries = val;
	    }

	    void
	    TabletStats::__set_ingestRate (const double val)
	    {
	      this->ingestRate = val;
	    }

	    void
	    TabletStats::__set_queryRate (const double val)
	    {
	      this->queryRate = val;
	    }

	    void
	    TabletStats::__set_splitCreationTime (const int64_t val)
	    {
	      this->splitCreationTime = val;
	    }

	    const char* TabletStats::ascii_fingerprint =
		"EDECD13D47255249DE8E10225F40F87E";
	    const uint8_t TabletStats::binary_fingerprint[16] =
	      { 0xED, 0xEC, 0xD1, 0x3D, 0x47, 0x25, 0x52, 0x49, 0xDE, 0x8E,
		  0x10, 0x22, 0x5F, 0x40, 0xF8, 0x7E };

	    uint32_t
	    TabletStats::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += this->extent.read (iprot);
			  this->__isset.extent = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->majors.read (iprot);
			  this->__isset.majors = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->minors.read (iprot);
			  this->__isset.minors = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->splits.read (iprot);
			  this->__isset.splits = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->numEntries);
			  this->__isset.numEntries = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->ingestRate);
			  this->__isset.ingestRate = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->queryRate);
			  this->__isset.queryRate = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 8:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->splitCreationTime);
			  this->__isset.splitCreationTime = true;
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
	    TabletStats::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TabletStats");

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "majors", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->majors.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "minors", ::apache::thrift::protocol::T_STRUCT, 3);
	      xfer += this->minors.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "splits", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->splits.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("numEntries",
					      ::apache::thrift::protocol::T_I64,
					      5);
	      xfer += oprot->writeI64 (this->numEntries);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ingestRate", ::apache::thrift::protocol::T_DOUBLE, 6);
	      xfer += oprot->writeDouble (this->ingestRate);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "queryRate", ::apache::thrift::protocol::T_DOUBLE, 7);
	      xfer += oprot->writeDouble (this->queryRate);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("splitCreationTime",
					      ::apache::thrift::protocol::T_I64,
					      8);
	      xfer += oprot->writeI64 (this->splitCreationTime);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TabletStats &a, TabletStats &b)
	    {
	      using ::std::swap;
	      swap (a.extent, b.extent);
	      swap (a.majors, b.majors);
	      swap (a.minors, b.minors);
	      swap (a.splits, b.splits);
	      swap (a.numEntries, b.numEntries);
	      swap (a.ingestRate, b.ingestRate);
	      swap (a.queryRate, b.queryRate);
	      swap (a.splitCreationTime, b.splitCreationTime);
	      swap (a.__isset, b.__isset);
	    }

	    TabletStats::TabletStats (const TabletStats& other16)
	    {
	      extent = other16.extent;
	      majors = other16.majors;
	      minors = other16.minors;
	      splits = other16.splits;
	      numEntries = other16.numEntries;
	      ingestRate = other16.ingestRate;
	      queryRate = other16.queryRate;
	      splitCreationTime = other16.splitCreationTime;
	      __isset = other16.__isset;
	    }
	    TabletStats&
	    TabletStats::operator= (const TabletStats& other17)
	    {
	      extent = other17.extent;
	      majors = other17.majors;
	      minors = other17.minors;
	      splits = other17.splits;
	      numEntries = other17.numEntries;
	      ingestRate = other17.ingestRate;
	      queryRate = other17.queryRate;
	      splitCreationTime = other17.splitCreationTime;
	      __isset = other17.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TabletStats& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TabletStats(";
	      out << "extent=" << to_string (obj.extent);
	      out << ", " << "majors=" << to_string (obj.majors);
	      out << ", " << "minors=" << to_string (obj.minors);
	      out << ", " << "splits=" << to_string (obj.splits);
	      out << ", " << "numEntries=" << to_string (obj.numEntries);
	      out << ", " << "ingestRate=" << to_string (obj.ingestRate);
	      out << ", " << "queryRate=" << to_string (obj.queryRate);
	      out << ", " << "splitCreationTime="
		  << to_string (obj.splitCreationTime);
	      out << ")";
	      return out;
	    }

	    ActiveScan::~ActiveScan () throw ()
	    {
	    }

	    void
	    ActiveScan::__set_client (const std::string& val)
	    {
	      this->client = val;
	    }

	    void
	    ActiveScan::__set_user (const std::string& val)
	    {
	      this->user = val;
	    }

	    void
	    ActiveScan::__set_tableId (const std::string& val)
	    {
	      this->tableId = val;
	    }

	    void
	    ActiveScan::__set_age (const int64_t val)
	    {
	      this->age = val;
	    }

	    void
	    ActiveScan::__set_idleTime (const int64_t val)
	    {
	      this->idleTime = val;
	    }

	    void
	    ActiveScan::__set_type (const ScanType::type val)
	    {
	      this->type = val;
	    }

	    void
	    ActiveScan::__set_state (const ScanState::type val)
	    {
	      this->state = val;
	    }

	    void
	    ActiveScan::__set_extent (
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& val)
	    {
	      this->extent = val;
	    }

	    void
	    ActiveScan::__set_columns (
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::TColumn> & val)
	    {
	      this->columns = val;
	    }

	    void
	    ActiveScan::__set_ssiList (
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::IterInfo> & val)
	    {
	      this->ssiList = val;
	    }

	    void
	    ActiveScan::__set_ssio (
		const std::map<std::string, std::map<std::string, std::string> > & val)
	    {
	      this->ssio = val;
	    }

	    void
	    ActiveScan::__set_authorizations (
		const std::vector<std::string> & val)
	    {
	      this->authorizations = val;
	    }

	    void
	    ActiveScan::__set_scanId (const int64_t val)
	    {
	      this->scanId = val;
	      __isset.scanId = true;
	    }

	    const char* ActiveScan::ascii_fingerprint =
		"B3549C14C0C72FCBA06F1947AA8A1F62";
	    const uint8_t ActiveScan::binary_fingerprint[16] =
	      { 0xB3, 0x54, 0x9C, 0x14, 0xC0, 0xC7, 0x2F, 0xCB, 0xA0, 0x6F,
		  0x19, 0x47, 0xAA, 0x8A, 0x1F, 0x62 };

	    uint32_t
	    ActiveScan::read (::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->client);
			  this->__isset.client = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->user);
			  this->__isset.user = true;
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
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->age);
			  this->__isset.age = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->idleTime);
			  this->__isset.idleTime = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast18;
			  xfer += iprot->readI32 (ecast18);
			  this->type = (ScanType::type) ecast18;
			  this->__isset.type = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 8:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast19;
			  xfer += iprot->readI32 (ecast19);
			  this->state = (ScanState::type) ecast19;
			  this->__isset.state = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 9:
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
		    case 10:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->columns.clear ();
			      uint32_t _size20;
			      ::apache::thrift::protocol::TType _etype23;
			      xfer += iprot->readListBegin (_etype23, _size20);
			      this->columns.resize (_size20);
			      uint32_t _i24;
			      for (_i24 = 0; _i24 < _size20; ++_i24)
				{
				  xfer += this->columns[_i24].read (iprot);
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
		    case 11:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->ssiList.clear ();
			      uint32_t _size25;
			      ::apache::thrift::protocol::TType _etype28;
			      xfer += iprot->readListBegin (_etype28, _size25);
			      this->ssiList.resize (_size25);
			      uint32_t _i29;
			      for (_i29 = 0; _i29 < _size25; ++_i29)
				{
				  xfer += this->ssiList[_i29].read (iprot);
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
		    case 12:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->ssio.clear ();
			      uint32_t _size30;
			      ::apache::thrift::protocol::TType _ktype31;
			      ::apache::thrift::protocol::TType _vtype32;
			      xfer += iprot->readMapBegin (_ktype31, _vtype32,
							   _size30);
			      uint32_t _i34;
			      for (_i34 = 0; _i34 < _size30; ++_i34)
				{
				  std::string _key35;
				  xfer += iprot->readString (_key35);
				  std::map<std::string, std::string> & _val36 =
				      this->ssio[_key35];
				    {
				      _val36.clear ();
				      uint32_t _size37;
				      ::apache::thrift::protocol::TType _ktype38;
				      ::apache::thrift::protocol::TType _vtype39;
				      xfer += iprot->readMapBegin (_ktype38,
								   _vtype39,
								   _size37);
				      uint32_t _i41;
				      for (_i41 = 0; _i41 < _size37; ++_i41)
					{
					  std::string _key42;
					  xfer += iprot->readString (_key42);
					  std::string& _val43 = _val36[_key42];
					  xfer += iprot->readString (_val43);
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
		    case 13:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->authorizations.clear ();
			      uint32_t _size44;
			      ::apache::thrift::protocol::TType _etype47;
			      xfer += iprot->readListBegin (_etype47, _size44);
			      this->authorizations.resize (_size44);
			      uint32_t _i48;
			      for (_i48 = 0; _i48 < _size44; ++_i48)
				{
				  xfer += iprot->readBinary (
				      this->authorizations[_i48]);
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
		    case 14:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->scanId);
			  this->__isset.scanId = true;
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
	    ActiveScan::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("ActiveScan");

	      xfer += oprot->writeFieldBegin (
		  "client", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->client);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "user", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->user);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tableId", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString (this->tableId);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("age",
					      ::apache::thrift::protocol::T_I64,
					      5);
	      xfer += oprot->writeI64 (this->age);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("idleTime",
					      ::apache::thrift::protocol::T_I64,
					      6);
	      xfer += oprot->writeI64 (this->idleTime);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("type",
					      ::apache::thrift::protocol::T_I32,
					      7);
	      xfer += oprot->writeI32 ((int32_t) this->type);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("state",
					      ::apache::thrift::protocol::T_I32,
					      8);
	      xfer += oprot->writeI32 ((int32_t) this->state);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 9);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "columns", ::apache::thrift::protocol::T_LIST, 10);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->columns.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::TColumn>::const_iterator _iter49;
		  for (_iter49 = this->columns.begin ();
		      _iter49 != this->columns.end (); ++_iter49)
		    {
		      xfer += (*_iter49).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ssiList", ::apache::thrift::protocol::T_LIST, 11);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->ssiList.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::IterInfo>::const_iterator _iter50;
		  for (_iter50 = this->ssiList.begin ();
		      _iter50 != this->ssiList.end (); ++_iter50)
		    {
		      xfer += (*_iter50).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("ssio",
					      ::apache::thrift::protocol::T_MAP,
					      12);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_MAP,
		      static_cast<uint32_t> (this->ssio.size ()));
		  std::map<std::string, std::map<std::string, std::string> >::const_iterator _iter51;
		  for (_iter51 = this->ssio.begin ();
		      _iter51 != this->ssio.end (); ++_iter51)
		    {
		      xfer += oprot->writeString (_iter51->first);
			{
			  xfer += oprot->writeMapBegin (
			      ::apache::thrift::protocol::T_STRING,
			      ::apache::thrift::protocol::T_STRING,
			      static_cast<uint32_t> (_iter51->second.size ()));
			  std::map<std::string, std::string>::const_iterator _iter52;
			  for (_iter52 = _iter51->second.begin ();
			      _iter52 != _iter51->second.end (); ++_iter52)
			    {
			      xfer += oprot->writeString (_iter52->first);
			      xfer += oprot->writeString (_iter52->second);
			    }
			  xfer += oprot->writeMapEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "authorizations", ::apache::thrift::protocol::T_LIST, 13);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->authorizations.size ()));
		  std::vector<std::string>::const_iterator _iter53;
		  for (_iter53 = this->authorizations.begin ();
		      _iter53 != this->authorizations.end (); ++_iter53)
		    {
		      xfer += oprot->writeBinary ((*_iter53));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      if (this->__isset.scanId)
		{
		  xfer += oprot->writeFieldBegin (
		      "scanId", ::apache::thrift::protocol::T_I64, 14);
		  xfer += oprot->writeI64 (this->scanId);
		  xfer += oprot->writeFieldEnd ();
		}
	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (ActiveScan &a, ActiveScan &b)
	    {
	      using ::std::swap;
	      swap (a.client, b.client);
	      swap (a.user, b.user);
	      swap (a.tableId, b.tableId);
	      swap (a.age, b.age);
	      swap (a.idleTime, b.idleTime);
	      swap (a.type, b.type);
	      swap (a.state, b.state);
	      swap (a.extent, b.extent);
	      swap (a.columns, b.columns);
	      swap (a.ssiList, b.ssiList);
	      swap (a.ssio, b.ssio);
	      swap (a.authorizations, b.authorizations);
	      swap (a.scanId, b.scanId);
	      swap (a.__isset, b.__isset);
	    }

	    ActiveScan::ActiveScan (const ActiveScan& other54)
	    {
	      client = other54.client;
	      user = other54.user;
	      tableId = other54.tableId;
	      age = other54.age;
	      idleTime = other54.idleTime;
	      type = other54.type;
	      state = other54.state;
	      extent = other54.extent;
	      columns = other54.columns;
	      ssiList = other54.ssiList;
	      ssio = other54.ssio;
	      authorizations = other54.authorizations;
	      scanId = other54.scanId;
	      __isset = other54.__isset;
	    }
	    ActiveScan&
	    ActiveScan::operator= (const ActiveScan& other55)
	    {
	      client = other55.client;
	      user = other55.user;
	      tableId = other55.tableId;
	      age = other55.age;
	      idleTime = other55.idleTime;
	      type = other55.type;
	      state = other55.state;
	      extent = other55.extent;
	      columns = other55.columns;
	      ssiList = other55.ssiList;
	      ssio = other55.ssio;
	      authorizations = other55.authorizations;
	      scanId = other55.scanId;
	      __isset = other55.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const ActiveScan& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "ActiveScan(";
	      out << "client=" << to_string (obj.client);
	      out << ", " << "user=" << to_string (obj.user);
	      out << ", " << "tableId=" << to_string (obj.tableId);
	      out << ", " << "age=" << to_string (obj.age);
	      out << ", " << "idleTime=" << to_string (obj.idleTime);
	      out << ", " << "type=" << to_string (obj.type);
	      out << ", " << "state=" << to_string (obj.state);
	      out << ", " << "extent=" << to_string (obj.extent);
	      out << ", " << "columns=" << to_string (obj.columns);
	      out << ", " << "ssiList=" << to_string (obj.ssiList);
	      out << ", " << "ssio=" << to_string (obj.ssio);
	      out << ", " << "authorizations="
		  << to_string (obj.authorizations);
	      out << ", " << "scanId=";
	      (obj.__isset.scanId ?
		  (out << to_string (obj.scanId)) : (out << "<null>"));
	      out << ")";
	      return out;
	    }

	    ActiveCompaction::~ActiveCompaction () throw ()
	    {
	    }

	    void
	    ActiveCompaction::__set_extent (
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& val)
	    {
	      this->extent = val;
	    }

	    void
	    ActiveCompaction::__set_age (const int64_t val)
	    {
	      this->age = val;
	    }

	    void
	    ActiveCompaction::__set_inputFiles (
		const std::vector<std::string> & val)
	    {
	      this->inputFiles = val;
	    }

	    void
	    ActiveCompaction::__set_outputFile (const std::string& val)
	    {
	      this->outputFile = val;
	    }

	    void
	    ActiveCompaction::__set_type (const CompactionType::type val)
	    {
	      this->type = val;
	    }

	    void
	    ActiveCompaction::__set_reason (const CompactionReason::type val)
	    {
	      this->reason = val;
	    }

	    void
	    ActiveCompaction::__set_localityGroup (const std::string& val)
	    {
	      this->localityGroup = val;
	    }

	    void
	    ActiveCompaction::__set_entriesRead (const int64_t val)
	    {
	      this->entriesRead = val;
	    }

	    void
	    ActiveCompaction::__set_entriesWritten (const int64_t val)
	    {
	      this->entriesWritten = val;
	    }

	    void
	    ActiveCompaction::__set_ssiList (
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::IterInfo> & val)
	    {
	      this->ssiList = val;
	    }

	    void
	    ActiveCompaction::__set_ssio (
		const std::map<std::string, std::map<std::string, std::string> > & val)
	    {
	      this->ssio = val;
	    }

	    const char* ActiveCompaction::ascii_fingerprint =
		"F21BEB5FC0933DF8AFDE54B450E3AA88";
	    const uint8_t ActiveCompaction::binary_fingerprint[16] =
	      { 0xF2, 0x1B, 0xEB, 0x5F, 0xC0, 0x93, 0x3D, 0xF8, 0xAF, 0xDE,
		  0x54, 0xB4, 0x50, 0xE3, 0xAA, 0x88 };

	    uint32_t
	    ActiveCompaction::read (
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
			  xfer += this->extent.read (iprot);
			  this->__isset.extent = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->age);
			  this->__isset.age = true;
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
			      this->inputFiles.clear ();
			      uint32_t _size56;
			      ::apache::thrift::protocol::TType _etype59;
			      xfer += iprot->readListBegin (_etype59, _size56);
			      this->inputFiles.resize (_size56);
			      uint32_t _i60;
			      for (_i60 = 0; _i60 < _size56; ++_i60)
				{
				  xfer += iprot->readString (
				      this->inputFiles[_i60]);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.inputFiles = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->outputFile);
			  this->__isset.outputFile = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast61;
			  xfer += iprot->readI32 (ecast61);
			  this->type = (CompactionType::type) ecast61;
			  this->__isset.type = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast62;
			  xfer += iprot->readI32 (ecast62);
			  this->reason = (CompactionReason::type) ecast62;
			  this->__isset.reason = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->localityGroup);
			  this->__isset.localityGroup = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 8:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->entriesRead);
			  this->__isset.entriesRead = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 9:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->entriesWritten);
			  this->__isset.entriesWritten = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 10:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->ssiList.clear ();
			      uint32_t _size63;
			      ::apache::thrift::protocol::TType _etype66;
			      xfer += iprot->readListBegin (_etype66, _size63);
			      this->ssiList.resize (_size63);
			      uint32_t _i67;
			      for (_i67 = 0; _i67 < _size63; ++_i67)
				{
				  xfer += this->ssiList[_i67].read (iprot);
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
		    case 11:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->ssio.clear ();
			      uint32_t _size68;
			      ::apache::thrift::protocol::TType _ktype69;
			      ::apache::thrift::protocol::TType _vtype70;
			      xfer += iprot->readMapBegin (_ktype69, _vtype70,
							   _size68);
			      uint32_t _i72;
			      for (_i72 = 0; _i72 < _size68; ++_i72)
				{
				  std::string _key73;
				  xfer += iprot->readString (_key73);
				  std::map<std::string, std::string> & _val74 =
				      this->ssio[_key73];
				    {
				      _val74.clear ();
				      uint32_t _size75;
				      ::apache::thrift::protocol::TType _ktype76;
				      ::apache::thrift::protocol::TType _vtype77;
				      xfer += iprot->readMapBegin (_ktype76,
								   _vtype77,
								   _size75);
				      uint32_t _i79;
				      for (_i79 = 0; _i79 < _size75; ++_i79)
					{
					  std::string _key80;
					  xfer += iprot->readString (_key80);
					  std::string& _val81 = _val74[_key80];
					  xfer += iprot->readString (_val81);
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
	    ActiveCompaction::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("ActiveCompaction");

	      xfer += oprot->writeFieldBegin (
		  "extent", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->extent.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("age",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->age);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "inputFiles", ::apache::thrift::protocol::T_LIST, 3);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->inputFiles.size ()));
		  std::vector<std::string>::const_iterator _iter82;
		  for (_iter82 = this->inputFiles.begin ();
		      _iter82 != this->inputFiles.end (); ++_iter82)
		    {
		      xfer += oprot->writeString ((*_iter82));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "outputFile", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeString (this->outputFile);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("type",
					      ::apache::thrift::protocol::T_I32,
					      5);
	      xfer += oprot->writeI32 ((int32_t) this->type);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("reason",
					      ::apache::thrift::protocol::T_I32,
					      6);
	      xfer += oprot->writeI32 ((int32_t) this->reason);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "localityGroup", ::apache::thrift::protocol::T_STRING, 7);
	      xfer += oprot->writeString (this->localityGroup);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("entriesRead",
					      ::apache::thrift::protocol::T_I64,
					      8);
	      xfer += oprot->writeI64 (this->entriesRead);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("entriesWritten",
					      ::apache::thrift::protocol::T_I64,
					      9);
	      xfer += oprot->writeI64 (this->entriesWritten);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ssiList", ::apache::thrift::protocol::T_LIST, 10);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->ssiList.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::IterInfo>::const_iterator _iter83;
		  for (_iter83 = this->ssiList.begin ();
		      _iter83 != this->ssiList.end (); ++_iter83)
		    {
		      xfer += (*_iter83).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("ssio",
					      ::apache::thrift::protocol::T_MAP,
					      11);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_MAP,
		      static_cast<uint32_t> (this->ssio.size ()));
		  std::map<std::string, std::map<std::string, std::string> >::const_iterator _iter84;
		  for (_iter84 = this->ssio.begin ();
		      _iter84 != this->ssio.end (); ++_iter84)
		    {
		      xfer += oprot->writeString (_iter84->first);
			{
			  xfer += oprot->writeMapBegin (
			      ::apache::thrift::protocol::T_STRING,
			      ::apache::thrift::protocol::T_STRING,
			      static_cast<uint32_t> (_iter84->second.size ()));
			  std::map<std::string, std::string>::const_iterator _iter85;
			  for (_iter85 = _iter84->second.begin ();
			      _iter85 != _iter84->second.end (); ++_iter85)
			    {
			      xfer += oprot->writeString (_iter85->first);
			      xfer += oprot->writeString (_iter85->second);
			    }
			  xfer += oprot->writeMapEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (ActiveCompaction &a, ActiveCompaction &b)
	    {
	      using ::std::swap;
	      swap (a.extent, b.extent);
	      swap (a.age, b.age);
	      swap (a.inputFiles, b.inputFiles);
	      swap (a.outputFile, b.outputFile);
	      swap (a.type, b.type);
	      swap (a.reason, b.reason);
	      swap (a.localityGroup, b.localityGroup);
	      swap (a.entriesRead, b.entriesRead);
	      swap (a.entriesWritten, b.entriesWritten);
	      swap (a.ssiList, b.ssiList);
	      swap (a.ssio, b.ssio);
	      swap (a.__isset, b.__isset);
	    }

	    ActiveCompaction::ActiveCompaction (const ActiveCompaction& other86)
	    {
	      extent = other86.extent;
	      age = other86.age;
	      inputFiles = other86.inputFiles;
	      outputFile = other86.outputFile;
	      type = other86.type;
	      reason = other86.reason;
	      localityGroup = other86.localityGroup;
	      entriesRead = other86.entriesRead;
	      entriesWritten = other86.entriesWritten;
	      ssiList = other86.ssiList;
	      ssio = other86.ssio;
	      __isset = other86.__isset;
	    }
	    ActiveCompaction&
	    ActiveCompaction::operator= (const ActiveCompaction& other87)
	    {
	      extent = other87.extent;
	      age = other87.age;
	      inputFiles = other87.inputFiles;
	      outputFile = other87.outputFile;
	      type = other87.type;
	      reason = other87.reason;
	      localityGroup = other87.localityGroup;
	      entriesRead = other87.entriesRead;
	      entriesWritten = other87.entriesWritten;
	      ssiList = other87.ssiList;
	      ssio = other87.ssio;
	      __isset = other87.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const ActiveCompaction& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "ActiveCompaction(";
	      out << "extent=" << to_string (obj.extent);
	      out << ", " << "age=" << to_string (obj.age);
	      out << ", " << "inputFiles=" << to_string (obj.inputFiles);
	      out << ", " << "outputFile=" << to_string (obj.outputFile);
	      out << ", " << "type=" << to_string (obj.type);
	      out << ", " << "reason=" << to_string (obj.reason);
	      out << ", " << "localityGroup=" << to_string (obj.localityGroup);
	      out << ", " << "entriesRead=" << to_string (obj.entriesRead);
	      out << ", " << "entriesWritten="
		  << to_string (obj.entriesWritten);
	      out << ", " << "ssiList=" << to_string (obj.ssiList);
	      out << ", " << "ssio=" << to_string (obj.ssio);
	      out << ")";
	      return out;
	    }

	    TIteratorSetting::~TIteratorSetting () throw ()
	    {
	    }

	    void
	    TIteratorSetting::__set_priority (const int32_t val)
	    {
	      this->priority = val;
	    }

	    void
	    TIteratorSetting::__set_name (const std::string& val)
	    {
	      this->name = val;
	    }

	    void
	    TIteratorSetting::__set_iteratorClass (const std::string& val)
	    {
	      this->iteratorClass = val;
	    }

	    void
	    TIteratorSetting::__set_properties (
		const std::map<std::string, std::string> & val)
	    {
	      this->properties = val;
	    }

	    const char* TIteratorSetting::ascii_fingerprint =
		"985C857916964E43205EAC92A157CB4E";
	    const uint8_t TIteratorSetting::binary_fingerprint[16] =
	      { 0x98, 0x5C, 0x85, 0x79, 0x16, 0x96, 0x4E, 0x43, 0x20, 0x5E,
		  0xAC, 0x92, 0xA1, 0x57, 0xCB, 0x4E };

	    uint32_t
	    TIteratorSetting::read (
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
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->priority);
			  this->__isset.priority = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->name);
			  this->__isset.name = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->iteratorClass);
			  this->__isset.iteratorClass = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->properties.clear ();
			      uint32_t _size88;
			      ::apache::thrift::protocol::TType _ktype89;
			      ::apache::thrift::protocol::TType _vtype90;
			      xfer += iprot->readMapBegin (_ktype89, _vtype90,
							   _size88);
			      uint32_t _i92;
			      for (_i92 = 0; _i92 < _size88; ++_i92)
				{
				  std::string _key93;
				  xfer += iprot->readString (_key93);
				  std::string& _val94 = this->properties[_key93];
				  xfer += iprot->readString (_val94);
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.properties = true;
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
	    TIteratorSetting::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TIteratorSetting");

	      xfer += oprot->writeFieldBegin ("priority",
					      ::apache::thrift::protocol::T_I32,
					      1);
	      xfer += oprot->writeI32 (this->priority);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "name", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->name);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "iteratorClass", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->iteratorClass);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("properties",
					      ::apache::thrift::protocol::T_MAP,
					      4);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->properties.size ()));
		  std::map<std::string, std::string>::const_iterator _iter95;
		  for (_iter95 = this->properties.begin ();
		      _iter95 != this->properties.end (); ++_iter95)
		    {
		      xfer += oprot->writeString (_iter95->first);
		      xfer += oprot->writeString (_iter95->second);
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TIteratorSetting &a, TIteratorSetting &b)
	    {
	      using ::std::swap;
	      swap (a.priority, b.priority);
	      swap (a.name, b.name);
	      swap (a.iteratorClass, b.iteratorClass);
	      swap (a.properties, b.properties);
	      swap (a.__isset, b.__isset);
	    }

	    TIteratorSetting::TIteratorSetting (const TIteratorSetting& other96)
	    {
	      priority = other96.priority;
	      name = other96.name;
	      iteratorClass = other96.iteratorClass;
	      properties = other96.properties;
	      __isset = other96.__isset;
	    }
	    TIteratorSetting&
	    TIteratorSetting::operator= (const TIteratorSetting& other97)
	    {
	      priority = other97.priority;
	      name = other97.name;
	      iteratorClass = other97.iteratorClass;
	      properties = other97.properties;
	      __isset = other97.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TIteratorSetting& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TIteratorSetting(";
	      out << "priority=" << to_string (obj.priority);
	      out << ", " << "name=" << to_string (obj.name);
	      out << ", " << "iteratorClass=" << to_string (obj.iteratorClass);
	      out << ", " << "properties=" << to_string (obj.properties);
	      out << ")";
	      return out;
	    }

	    IteratorConfig::~IteratorConfig () throw ()
	    {
	    }

	    void
	    IteratorConfig::__set_iterators (
		const std::vector<TIteratorSetting> & val)
	    {
	      this->iterators = val;
	    }

	    const char* IteratorConfig::ascii_fingerprint =
		"FFF95A9CEF69279C7B1115140EF9F6D7";
	    const uint8_t IteratorConfig::binary_fingerprint[16] =
	      { 0xFF, 0xF9, 0x5A, 0x9C, 0xEF, 0x69, 0x27, 0x9C, 0x7B, 0x11,
		  0x15, 0x14, 0x0E, 0xF9, 0xF6, 0xD7 };

	    uint32_t
	    IteratorConfig::read (::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->iterators.clear ();
			      uint32_t _size98;
			      ::apache::thrift::protocol::TType _etype101;
			      xfer += iprot->readListBegin (_etype101, _size98);
			      this->iterators.resize (_size98);
			      uint32_t _i102;
			      for (_i102 = 0; _i102 < _size98; ++_i102)
				{
				  xfer += this->iterators[_i102].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.iterators = true;
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
	    IteratorConfig::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("IteratorConfig");

	      xfer += oprot->writeFieldBegin (
		  "iterators", ::apache::thrift::protocol::T_LIST, 1);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->iterators.size ()));
		  std::vector<TIteratorSetting>::const_iterator _iter103;
		  for (_iter103 = this->iterators.begin ();
		      _iter103 != this->iterators.end (); ++_iter103)
		    {
		      xfer += (*_iter103).write (oprot);
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
	    swap (IteratorConfig &a, IteratorConfig &b)
	    {
	      using ::std::swap;
	      swap (a.iterators, b.iterators);
	      swap (a.__isset, b.__isset);
	    }

	    IteratorConfig::IteratorConfig (const IteratorConfig& other104)
	    {
	      iterators = other104.iterators;
	      __isset = other104.__isset;
	    }
	    IteratorConfig&
	    IteratorConfig::operator= (const IteratorConfig& other105)
	    {
	      iterators = other105.iterators;
	      __isset = other105.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const IteratorConfig& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "IteratorConfig(";
	      out << "iterators=" << to_string (obj.iterators);
	      out << ")";
	      return out;
	    }

	  }
	}
      }
    }
  }
} // namespace
