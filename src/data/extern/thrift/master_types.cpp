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
#include "../../../../include/data/extern/thrift/master_types.h"

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
	namespace master
	{
	  namespace thrift
	  {

	    int _kMasterStateValues[] =
	      { MasterState::INITIAL, MasterState::HAVE_LOCK,
		  MasterState::SAFE_MODE, MasterState::NORMAL,
		  MasterState::UNLOAD_METADATA_TABLETS,
		  MasterState::UNLOAD_ROOT_TABLET, MasterState::STOP };
	    const char* _kMasterStateNames[] =
	      { "INITIAL", "HAVE_LOCK", "SAFE_MODE", "NORMAL",
		  "UNLOAD_METADATA_TABLETS", "UNLOAD_ROOT_TABLET", "STOP" };
	    const std::map<int, const char*> _MasterState_VALUES_TO_NAMES (
		::apache::thrift::TEnumIterator (7, _kMasterStateValues,
						 _kMasterStateNames),
		::apache::thrift::TEnumIterator (-1, NULL, NULL));

	    int _kMasterGoalStateValues[] =
	      { MasterGoalState::CLEAN_STOP, MasterGoalState::SAFE_MODE,
		  MasterGoalState::NORMAL };
	    const char* _kMasterGoalStateNames[] =
	      { "CLEAN_STOP", "SAFE_MODE", "NORMAL" };
	    const std::map<int, const char*> _MasterGoalState_VALUES_TO_NAMES (
		::apache::thrift::TEnumIterator (3, _kMasterGoalStateValues,
						 _kMasterGoalStateNames),
		::apache::thrift::TEnumIterator (-1, NULL, NULL));

	    int _kTabletLoadStateValues[] =
	      { TabletLoadState::LOADED, TabletLoadState::LOAD_FAILURE,
		  TabletLoadState::UNLOADED,
		  TabletLoadState::UNLOAD_FAILURE_NOT_SERVING,
		  TabletLoadState::UNLOAD_ERROR, TabletLoadState::CHOPPED };
	    const char* _kTabletLoadStateNames[] =
	      { "LOADED", "LOAD_FAILURE", "UNLOADED",
		  "UNLOAD_FAILURE_NOT_SERVING", "UNLOAD_ERROR", "CHOPPED" };
	    const std::map<int, const char*> _TabletLoadState_VALUES_TO_NAMES (
		::apache::thrift::TEnumIterator (6, _kTabletLoadStateValues,
						 _kTabletLoadStateNames),
		::apache::thrift::TEnumIterator (-1, NULL, NULL));

	    int _kFateOperationValues[] =
	      { FateOperation::TABLE_CREATE, FateOperation::TABLE_CLONE,
		  FateOperation::TABLE_DELETE, FateOperation::TABLE_RENAME,
		  FateOperation::TABLE_ONLINE, FateOperation::TABLE_OFFLINE,
		  FateOperation::TABLE_MERGE, FateOperation::TABLE_DELETE_RANGE,
		  FateOperation::TABLE_BULK_IMPORT,
		  FateOperation::TABLE_COMPACT, FateOperation::TABLE_IMPORT,
		  FateOperation::TABLE_EXPORT,
		  FateOperation::TABLE_CANCEL_COMPACT,
		  FateOperation::NAMESPACE_CREATE,
		  FateOperation::NAMESPACE_DELETE,
		  FateOperation::NAMESPACE_RENAME };
	    const char* _kFateOperationNames[] =
	      { "TABLE_CREATE", "TABLE_CLONE", "TABLE_DELETE", "TABLE_RENAME",
		  "TABLE_ONLINE", "TABLE_OFFLINE", "TABLE_MERGE",
		  "TABLE_DELETE_RANGE", "TABLE_BULK_IMPORT", "TABLE_COMPACT",
		  "TABLE_IMPORT", "TABLE_EXPORT", "TABLE_CANCEL_COMPACT",
		  "NAMESPACE_CREATE", "NAMESPACE_DELETE", "NAMESPACE_RENAME" };
	    const std::map<int, const char*> _FateOperation_VALUES_TO_NAMES (
		::apache::thrift::TEnumIterator (16, _kFateOperationValues,
						 _kFateOperationNames),
		::apache::thrift::TEnumIterator (-1, NULL, NULL));

	    Compacting::~Compacting () throw ()
	    {
	    }

	    void
	    Compacting::__set_running (const int32_t val)
	    {
	      this->running = val;
	    }

	    void
	    Compacting::__set_queued (const int32_t val)
	    {
	      this->queued = val;
	    }

	    const char* Compacting::ascii_fingerprint =
		"989D1F1AE8D148D5E2119FFEC4BBBEE3";
	    const uint8_t Compacting::binary_fingerprint[16] =
	      { 0x98, 0x9D, 0x1F, 0x1A, 0xE8, 0xD1, 0x48, 0xD5, 0xE2, 0x11,
		  0x9F, 0xFE, 0xC4, 0xBB, 0xBE, 0xE3 };

	    uint32_t
	    Compacting::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readI32 (this->running);
			  this->__isset.running = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->queued);
			  this->__isset.queued = true;
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
	    Compacting::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("Compacting");

	      xfer += oprot->writeFieldBegin ("running",
					      ::apache::thrift::protocol::T_I32,
					      1);
	      xfer += oprot->writeI32 (this->running);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("queued",
					      ::apache::thrift::protocol::T_I32,
					      2);
	      xfer += oprot->writeI32 (this->queued);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (Compacting &a, Compacting &b)
	    {
	      using ::std::swap;
	      swap (a.running, b.running);
	      swap (a.queued, b.queued);
	      swap (a.__isset, b.__isset);
	    }

	    Compacting::Compacting (const Compacting& other0)
	    {
	      running = other0.running;
	      queued = other0.queued;
	      __isset = other0.__isset;
	    }
	    Compacting&
	    Compacting::operator= (const Compacting& other1)
	    {
	      running = other1.running;
	      queued = other1.queued;
	      __isset = other1.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const Compacting& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "Compacting(";
	      out << "running=" << to_string (obj.running);
	      out << ", " << "queued=" << to_string (obj.queued);
	      out << ")";
	      return out;
	    }

	    TableInfo::~TableInfo () throw ()
	    {
	    }

	    void
	    TableInfo::__set_recs (const int64_t val)
	    {
	      this->recs = val;
	    }

	    void
	    TableInfo::__set_recsInMemory (const int64_t val)
	    {
	      this->recsInMemory = val;
	    }

	    void
	    TableInfo::__set_tablets (const int32_t val)
	    {
	      this->tablets = val;
	    }

	    void
	    TableInfo::__set_onlineTablets (const int32_t val)
	    {
	      this->onlineTablets = val;
	    }

	    void
	    TableInfo::__set_ingestRate (const double val)
	    {
	      this->ingestRate = val;
	    }

	    void
	    TableInfo::__set_ingestByteRate (const double val)
	    {
	      this->ingestByteRate = val;
	    }

	    void
	    TableInfo::__set_queryRate (const double val)
	    {
	      this->queryRate = val;
	    }

	    void
	    TableInfo::__set_queryByteRate (const double val)
	    {
	      this->queryByteRate = val;
	    }

	    void
	    TableInfo::__set_minors (const Compacting& val)
	    {
	      this->minors = val;
	    }

	    void
	    TableInfo::__set_majors (const Compacting& val)
	    {
	      this->majors = val;
	    }

	    void
	    TableInfo::__set_scans (const Compacting& val)
	    {
	      this->scans = val;
	    }

	    void
	    TableInfo::__set_scanRate (const double val)
	    {
	      this->scanRate = val;
	    }

	    const char* TableInfo::ascii_fingerprint =
		"D1B40B6CDBBA041D2E4F3215B5A7FF49";
	    const uint8_t TableInfo::binary_fingerprint[16] =
	      { 0xD1, 0xB4, 0x0B, 0x6C, 0xDB, 0xBA, 0x04, 0x1D, 0x2E, 0x4F,
		  0x32, 0x15, 0xB5, 0xA7, 0xFF, 0x49 };

	    uint32_t
	    TableInfo::read (::apache::thrift::protocol::TProtocol* iprot)
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
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->recs);
			  this->__isset.recs = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->recsInMemory);
			  this->__isset.recsInMemory = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->tablets);
			  this->__isset.tablets = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->onlineTablets);
			  this->__isset.onlineTablets = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
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
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->ingestByteRate);
			  this->__isset.ingestByteRate = true;
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
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->queryByteRate);
			  this->__isset.queryByteRate = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 9:
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
		    case 10:
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
		    case 11:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->scans.read (iprot);
			  this->__isset.scans = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 12:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->scanRate);
			  this->__isset.scanRate = true;
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
	    TableInfo::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TableInfo");

	      xfer += oprot->writeFieldBegin ("recs",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->recs);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("recsInMemory",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->recsInMemory);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("tablets",
					      ::apache::thrift::protocol::T_I32,
					      3);
	      xfer += oprot->writeI32 (this->tablets);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("onlineTablets",
					      ::apache::thrift::protocol::T_I32,
					      4);
	      xfer += oprot->writeI32 (this->onlineTablets);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ingestRate", ::apache::thrift::protocol::T_DOUBLE, 5);
	      xfer += oprot->writeDouble (this->ingestRate);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "ingestByteRate", ::apache::thrift::protocol::T_DOUBLE, 6);
	      xfer += oprot->writeDouble (this->ingestByteRate);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "queryRate", ::apache::thrift::protocol::T_DOUBLE, 7);
	      xfer += oprot->writeDouble (this->queryRate);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "queryByteRate", ::apache::thrift::protocol::T_DOUBLE, 8);
	      xfer += oprot->writeDouble (this->queryByteRate);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "minors", ::apache::thrift::protocol::T_STRUCT, 9);
	      xfer += this->minors.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "majors", ::apache::thrift::protocol::T_STRUCT, 10);
	      xfer += this->majors.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "scans", ::apache::thrift::protocol::T_STRUCT, 11);
	      xfer += this->scans.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "scanRate", ::apache::thrift::protocol::T_DOUBLE, 12);
	      xfer += oprot->writeDouble (this->scanRate);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TableInfo &a, TableInfo &b)
	    {
	      using ::std::swap;
	      swap (a.recs, b.recs);
	      swap (a.recsInMemory, b.recsInMemory);
	      swap (a.tablets, b.tablets);
	      swap (a.onlineTablets, b.onlineTablets);
	      swap (a.ingestRate, b.ingestRate);
	      swap (a.ingestByteRate, b.ingestByteRate);
	      swap (a.queryRate, b.queryRate);
	      swap (a.queryByteRate, b.queryByteRate);
	      swap (a.minors, b.minors);
	      swap (a.majors, b.majors);
	      swap (a.scans, b.scans);
	      swap (a.scanRate, b.scanRate);
	      swap (a.__isset, b.__isset);
	    }

	    TableInfo::TableInfo (const TableInfo& other2)
	    {
	      recs = other2.recs;
	      recsInMemory = other2.recsInMemory;
	      tablets = other2.tablets;
	      onlineTablets = other2.onlineTablets;
	      ingestRate = other2.ingestRate;
	      ingestByteRate = other2.ingestByteRate;
	      queryRate = other2.queryRate;
	      queryByteRate = other2.queryByteRate;
	      minors = other2.minors;
	      majors = other2.majors;
	      scans = other2.scans;
	      scanRate = other2.scanRate;
	      __isset = other2.__isset;
	    }
	    TableInfo&
	    TableInfo::operator= (const TableInfo& other3)
	    {
	      recs = other3.recs;
	      recsInMemory = other3.recsInMemory;
	      tablets = other3.tablets;
	      onlineTablets = other3.onlineTablets;
	      ingestRate = other3.ingestRate;
	      ingestByteRate = other3.ingestByteRate;
	      queryRate = other3.queryRate;
	      queryByteRate = other3.queryByteRate;
	      minors = other3.minors;
	      majors = other3.majors;
	      scans = other3.scans;
	      scanRate = other3.scanRate;
	      __isset = other3.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TableInfo& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TableInfo(";
	      out << "recs=" << to_string (obj.recs);
	      out << ", " << "recsInMemory=" << to_string (obj.recsInMemory);
	      out << ", " << "tablets=" << to_string (obj.tablets);
	      out << ", " << "onlineTablets=" << to_string (obj.onlineTablets);
	      out << ", " << "ingestRate=" << to_string (obj.ingestRate);
	      out << ", " << "ingestByteRate="
		  << to_string (obj.ingestByteRate);
	      out << ", " << "queryRate=" << to_string (obj.queryRate);
	      out << ", " << "queryByteRate=" << to_string (obj.queryByteRate);
	      out << ", " << "minors=" << to_string (obj.minors);
	      out << ", " << "majors=" << to_string (obj.majors);
	      out << ", " << "scans=" << to_string (obj.scans);
	      out << ", " << "scanRate=" << to_string (obj.scanRate);
	      out << ")";
	      return out;
	    }

	    RecoveryStatus::~RecoveryStatus () throw ()
	    {
	    }

	    void
	    RecoveryStatus::__set_name (const std::string& val)
	    {
	      this->name = val;
	    }

	    void
	    RecoveryStatus::__set_runtime (const int32_t val)
	    {
	      this->runtime = val;
	    }

	    void
	    RecoveryStatus::__set_progress (const double val)
	    {
	      this->progress = val;
	    }

	    const char* RecoveryStatus::ascii_fingerprint =
		"EDDD3E9D46980BDB38F82C7B45738053";
	    const uint8_t RecoveryStatus::binary_fingerprint[16] =
	      { 0xED, 0xDD, 0x3E, 0x9D, 0x46, 0x98, 0x0B, 0xDB, 0x38, 0xF8,
		  0x2C, 0x7B, 0x45, 0x73, 0x80, 0x53 };

	    uint32_t
	    RecoveryStatus::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readString (this->name);
			  this->__isset.name = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->runtime);
			  this->__isset.runtime = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->progress);
			  this->__isset.progress = true;
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
	    RecoveryStatus::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("RecoveryStatus");

	      xfer += oprot->writeFieldBegin (
		  "name", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->name);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("runtime",
					      ::apache::thrift::protocol::T_I32,
					      5);
	      xfer += oprot->writeI32 (this->runtime);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "progress", ::apache::thrift::protocol::T_DOUBLE, 6);
	      xfer += oprot->writeDouble (this->progress);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (RecoveryStatus &a, RecoveryStatus &b)
	    {
	      using ::std::swap;
	      swap (a.name, b.name);
	      swap (a.runtime, b.runtime);
	      swap (a.progress, b.progress);
	      swap (a.__isset, b.__isset);
	    }

	    RecoveryStatus::RecoveryStatus (const RecoveryStatus& other4)
	    {
	      name = other4.name;
	      runtime = other4.runtime;
	      progress = other4.progress;
	      __isset = other4.__isset;
	    }
	    RecoveryStatus&
	    RecoveryStatus::operator= (const RecoveryStatus& other5)
	    {
	      name = other5.name;
	      runtime = other5.runtime;
	      progress = other5.progress;
	      __isset = other5.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const RecoveryStatus& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "RecoveryStatus(";
	      out << "name=" << to_string (obj.name);
	      out << ", " << "runtime=" << to_string (obj.runtime);
	      out << ", " << "progress=" << to_string (obj.progress);
	      out << ")";
	      return out;
	    }

	    TabletServerStatus::~TabletServerStatus () throw ()
	    {
	    }

	    void
	    TabletServerStatus::__set_tableMap (
		const std::map<std::string, TableInfo> & val)
	    {
	      this->tableMap = val;
	    }

	    void
	    TabletServerStatus::__set_lastContact (const int64_t val)
	    {
	      this->lastContact = val;
	    }

	    void
	    TabletServerStatus::__set_name (const std::string& val)
	    {
	      this->name = val;
	    }

	    void
	    TabletServerStatus::__set_osLoad (const double val)
	    {
	      this->osLoad = val;
	    }

	    void
	    TabletServerStatus::__set_holdTime (const int64_t val)
	    {
	      this->holdTime = val;
	    }

	    void
	    TabletServerStatus::__set_lookups (const int64_t val)
	    {
	      this->lookups = val;
	    }

	    void
	    TabletServerStatus::__set_indexCacheHits (const int64_t val)
	    {
	      this->indexCacheHits = val;
	    }

	    void
	    TabletServerStatus::__set_indexCacheRequest (const int64_t val)
	    {
	      this->indexCacheRequest = val;
	    }

	    void
	    TabletServerStatus::__set_dataCacheHits (const int64_t val)
	    {
	      this->dataCacheHits = val;
	    }

	    void
	    TabletServerStatus::__set_dataCacheRequest (const int64_t val)
	    {
	      this->dataCacheRequest = val;
	    }

	    void
	    TabletServerStatus::__set_logSorts (
		const std::vector<RecoveryStatus> & val)
	    {
	      this->logSorts = val;
	    }

	    const char* TabletServerStatus::ascii_fingerprint =
		"DD8B6FED027FCEF184342CD2B4178461";
	    const uint8_t TabletServerStatus::binary_fingerprint[16] =
	      { 0xDD, 0x8B, 0x6F, 0xED, 0x02, 0x7F, 0xCE, 0xF1, 0x84, 0x34,
		  0x2C, 0xD2, 0xB4, 0x17, 0x84, 0x61 };

	    uint32_t
	    TabletServerStatus::read (
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
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->tableMap.clear ();
			      uint32_t _size6;
			      ::apache::thrift::protocol::TType _ktype7;
			      ::apache::thrift::protocol::TType _vtype8;
			      xfer += iprot->readMapBegin (_ktype7, _vtype8,
							   _size6);
			      uint32_t _i10;
			      for (_i10 = 0; _i10 < _size6; ++_i10)
				{
				  std::string _key11;
				  xfer += iprot->readString (_key11);
				  TableInfo& _val12 = this->tableMap[_key11];
				  xfer += _val12.read (iprot);
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.tableMap = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->lastContact);
			  this->__isset.lastContact = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
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
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_DOUBLE)
			{
			  xfer += iprot->readDouble (this->osLoad);
			  this->__isset.osLoad = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->holdTime);
			  this->__isset.holdTime = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 8:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->lookups);
			  this->__isset.lookups = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 10:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->indexCacheHits);
			  this->__isset.indexCacheHits = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 11:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->indexCacheRequest);
			  this->__isset.indexCacheRequest = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 12:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->dataCacheHits);
			  this->__isset.dataCacheHits = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 13:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->dataCacheRequest);
			  this->__isset.dataCacheRequest = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 14:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->logSorts.clear ();
			      uint32_t _size13;
			      ::apache::thrift::protocol::TType _etype16;
			      xfer += iprot->readListBegin (_etype16, _size13);
			      this->logSorts.resize (_size13);
			      uint32_t _i17;
			      for (_i17 = 0; _i17 < _size13; ++_i17)
				{
				  xfer += this->logSorts[_i17].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.logSorts = true;
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
	    TabletServerStatus::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TabletServerStatus");

	      xfer += oprot->writeFieldBegin ("tableMap",
					      ::apache::thrift::protocol::T_MAP,
					      1);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->tableMap.size ()));
		  std::map<std::string, TableInfo>::const_iterator _iter18;
		  for (_iter18 = this->tableMap.begin ();
		      _iter18 != this->tableMap.end (); ++_iter18)
		    {
		      xfer += oprot->writeString (_iter18->first);
		      xfer += _iter18->second.write (oprot);
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("lastContact",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->lastContact);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "name", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->name);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "osLoad", ::apache::thrift::protocol::T_DOUBLE, 5);
	      xfer += oprot->writeDouble (this->osLoad);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("holdTime",
					      ::apache::thrift::protocol::T_I64,
					      7);
	      xfer += oprot->writeI64 (this->holdTime);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("lookups",
					      ::apache::thrift::protocol::T_I64,
					      8);
	      xfer += oprot->writeI64 (this->lookups);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("indexCacheHits",
					      ::apache::thrift::protocol::T_I64,
					      10);
	      xfer += oprot->writeI64 (this->indexCacheHits);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("indexCacheRequest",
					      ::apache::thrift::protocol::T_I64,
					      11);
	      xfer += oprot->writeI64 (this->indexCacheRequest);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("dataCacheHits",
					      ::apache::thrift::protocol::T_I64,
					      12);
	      xfer += oprot->writeI64 (this->dataCacheHits);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("dataCacheRequest",
					      ::apache::thrift::protocol::T_I64,
					      13);
	      xfer += oprot->writeI64 (this->dataCacheRequest);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "logSorts", ::apache::thrift::protocol::T_LIST, 14);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->logSorts.size ()));
		  std::vector<RecoveryStatus>::const_iterator _iter19;
		  for (_iter19 = this->logSorts.begin ();
		      _iter19 != this->logSorts.end (); ++_iter19)
		    {
		      xfer += (*_iter19).write (oprot);
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
	    swap (TabletServerStatus &a, TabletServerStatus &b)
	    {
	      using ::std::swap;
	      swap (a.tableMap, b.tableMap);
	      swap (a.lastContact, b.lastContact);
	      swap (a.name, b.name);
	      swap (a.osLoad, b.osLoad);
	      swap (a.holdTime, b.holdTime);
	      swap (a.lookups, b.lookups);
	      swap (a.indexCacheHits, b.indexCacheHits);
	      swap (a.indexCacheRequest, b.indexCacheRequest);
	      swap (a.dataCacheHits, b.dataCacheHits);
	      swap (a.dataCacheRequest, b.dataCacheRequest);
	      swap (a.logSorts, b.logSorts);
	      swap (a.__isset, b.__isset);
	    }

	    TabletServerStatus::TabletServerStatus (
		const TabletServerStatus& other20)
	    {
	      tableMap = other20.tableMap;
	      lastContact = other20.lastContact;
	      name = other20.name;
	      osLoad = other20.osLoad;
	      holdTime = other20.holdTime;
	      lookups = other20.lookups;
	      indexCacheHits = other20.indexCacheHits;
	      indexCacheRequest = other20.indexCacheRequest;
	      dataCacheHits = other20.dataCacheHits;
	      dataCacheRequest = other20.dataCacheRequest;
	      logSorts = other20.logSorts;
	      __isset = other20.__isset;
	    }
	    TabletServerStatus&
	    TabletServerStatus::operator= (const TabletServerStatus& other21)
	    {
	      tableMap = other21.tableMap;
	      lastContact = other21.lastContact;
	      name = other21.name;
	      osLoad = other21.osLoad;
	      holdTime = other21.holdTime;
	      lookups = other21.lookups;
	      indexCacheHits = other21.indexCacheHits;
	      indexCacheRequest = other21.indexCacheRequest;
	      dataCacheHits = other21.dataCacheHits;
	      dataCacheRequest = other21.dataCacheRequest;
	      logSorts = other21.logSorts;
	      __isset = other21.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TabletServerStatus& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TabletServerStatus(";
	      out << "tableMap=" << to_string (obj.tableMap);
	      out << ", " << "lastContact=" << to_string (obj.lastContact);
	      out << ", " << "name=" << to_string (obj.name);
	      out << ", " << "osLoad=" << to_string (obj.osLoad);
	      out << ", " << "holdTime=" << to_string (obj.holdTime);
	      out << ", " << "lookups=" << to_string (obj.lookups);
	      out << ", " << "indexCacheHits="
		  << to_string (obj.indexCacheHits);
	      out << ", " << "indexCacheRequest="
		  << to_string (obj.indexCacheRequest);
	      out << ", " << "dataCacheHits=" << to_string (obj.dataCacheHits);
	      out << ", " << "dataCacheRequest="
		  << to_string (obj.dataCacheRequest);
	      out << ", " << "logSorts=" << to_string (obj.logSorts);
	      out << ")";
	      return out;
	    }

	    DeadServer::~DeadServer () throw ()
	    {
	    }

	    void
	    DeadServer::__set_server (const std::string& val)
	    {
	      this->server = val;
	    }

	    void
	    DeadServer::__set_lastStatus (const int64_t val)
	    {
	      this->lastStatus = val;
	    }

	    void
	    DeadServer::__set_status (const std::string& val)
	    {
	      this->status = val;
	    }

	    const char* DeadServer::ascii_fingerprint =
		"FA35BEC6F4D26D79A7E0AD1366489BCC";
	    const uint8_t DeadServer::binary_fingerprint[16] =
	      { 0xFA, 0x35, 0xBE, 0xC6, 0xF4, 0xD2, 0x6D, 0x79, 0xA7, 0xE0,
		  0xAD, 0x13, 0x66, 0x48, 0x9B, 0xCC };

	    uint32_t
	    DeadServer::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readString (this->server);
			  this->__isset.server = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->lastStatus);
			  this->__isset.lastStatus = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->status);
			  this->__isset.status = true;
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
	    DeadServer::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("DeadServer");

	      xfer += oprot->writeFieldBegin (
		  "server", ::apache::thrift::protocol::T_STRING, 1);
	      xfer += oprot->writeString (this->server);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("lastStatus",
					      ::apache::thrift::protocol::T_I64,
					      2);
	      xfer += oprot->writeI64 (this->lastStatus);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "status", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->status);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (DeadServer &a, DeadServer &b)
	    {
	      using ::std::swap;
	      swap (a.server, b.server);
	      swap (a.lastStatus, b.lastStatus);
	      swap (a.status, b.status);
	      swap (a.__isset, b.__isset);
	    }

	    DeadServer::DeadServer (const DeadServer& other22)
	    {
	      server = other22.server;
	      lastStatus = other22.lastStatus;
	      status = other22.status;
	      __isset = other22.__isset;
	    }
	    DeadServer&
	    DeadServer::operator= (const DeadServer& other23)
	    {
	      server = other23.server;
	      lastStatus = other23.lastStatus;
	      status = other23.status;
	      __isset = other23.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const DeadServer& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "DeadServer(";
	      out << "server=" << to_string (obj.server);
	      out << ", " << "lastStatus=" << to_string (obj.lastStatus);
	      out << ", " << "status=" << to_string (obj.status);
	      out << ")";
	      return out;
	    }

	    MasterMonitorInfo::~MasterMonitorInfo () throw ()
	    {
	    }

	    void
	    MasterMonitorInfo::__set_tableMap (
		const std::map<std::string, TableInfo> & val)
	    {
	      this->tableMap = val;
	    }

	    void
	    MasterMonitorInfo::__set_tServerInfo (
		const std::vector<TabletServerStatus> & val)
	    {
	      this->tServerInfo = val;
	    }

	    void
	    MasterMonitorInfo::__set_badTServers (
		const std::map<std::string, int8_t> & val)
	    {
	      this->badTServers = val;
	    }

	    void
	    MasterMonitorInfo::__set_state (const MasterState::type val)
	    {
	      this->state = val;
	    }

	    void
	    MasterMonitorInfo::__set_goalState (const MasterGoalState::type val)
	    {
	      this->goalState = val;
	    }

	    void
	    MasterMonitorInfo::__set_unassignedTablets (const int32_t val)
	    {
	      this->unassignedTablets = val;
	    }

	    void
	    MasterMonitorInfo::__set_serversShuttingDown (
		const std::set<std::string> & val)
	    {
	      this->serversShuttingDown = val;
	    }

	    void
	    MasterMonitorInfo::__set_deadTabletServers (
		const std::vector<DeadServer> & val)
	    {
	      this->deadTabletServers = val;
	    }

	    const char* MasterMonitorInfo::ascii_fingerprint =
		"97129B4CC16BA8DA7D678FBCE0016340";
	    const uint8_t MasterMonitorInfo::binary_fingerprint[16] =
	      { 0x97, 0x12, 0x9B, 0x4C, 0xC1, 0x6B, 0xA8, 0xDA, 0x7D, 0x67,
		  0x8F, 0xBC, 0xE0, 0x01, 0x63, 0x40 };

	    uint32_t
	    MasterMonitorInfo::read (
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
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->tableMap.clear ();
			      uint32_t _size24;
			      ::apache::thrift::protocol::TType _ktype25;
			      ::apache::thrift::protocol::TType _vtype26;
			      xfer += iprot->readMapBegin (_ktype25, _vtype26,
							   _size24);
			      uint32_t _i28;
			      for (_i28 = 0; _i28 < _size24; ++_i28)
				{
				  std::string _key29;
				  xfer += iprot->readString (_key29);
				  TableInfo& _val30 = this->tableMap[_key29];
				  xfer += _val30.read (iprot);
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.tableMap = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->tServerInfo.clear ();
			      uint32_t _size31;
			      ::apache::thrift::protocol::TType _etype34;
			      xfer += iprot->readListBegin (_etype34, _size31);
			      this->tServerInfo.resize (_size31);
			      uint32_t _i35;
			      for (_i35 = 0; _i35 < _size31; ++_i35)
				{
				  xfer += this->tServerInfo[_i35].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.tServerInfo = true;
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
			      this->badTServers.clear ();
			      uint32_t _size36;
			      ::apache::thrift::protocol::TType _ktype37;
			      ::apache::thrift::protocol::TType _vtype38;
			      xfer += iprot->readMapBegin (_ktype37, _vtype38,
							   _size36);
			      uint32_t _i40;
			      for (_i40 = 0; _i40 < _size36; ++_i40)
				{
				  std::string _key41;
				  xfer += iprot->readString (_key41);
				  int8_t& _val42 = this->badTServers[_key41];
				  xfer += iprot->readByte (_val42);
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.badTServers = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast43;
			  xfer += iprot->readI32 (ecast43);
			  this->state = (MasterState::type) ecast43;
			  this->__isset.state = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 8:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast44;
			  xfer += iprot->readI32 (ecast44);
			  this->goalState = (MasterGoalState::type) ecast44;
			  this->__isset.goalState = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->unassignedTablets);
			  this->__isset.unassignedTablets = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 9:
		      if (ftype == ::apache::thrift::protocol::T_SET)
			{
			    {
			      this->serversShuttingDown.clear ();
			      uint32_t _size45;
			      ::apache::thrift::protocol::TType _etype48;
			      xfer += iprot->readSetBegin (_etype48, _size45);
			      uint32_t _i49;
			      for (_i49 = 0; _i49 < _size45; ++_i49)
				{
				  std::string _elem50;
				  xfer += iprot->readString (_elem50);
				  this->serversShuttingDown.insert (_elem50);
				}
			      xfer += iprot->readSetEnd ();
			    }
			  this->__isset.serversShuttingDown = true;
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
			      this->deadTabletServers.clear ();
			      uint32_t _size51;
			      ::apache::thrift::protocol::TType _etype54;
			      xfer += iprot->readListBegin (_etype54, _size51);
			      this->deadTabletServers.resize (_size51);
			      uint32_t _i55;
			      for (_i55 = 0; _i55 < _size51; ++_i55)
				{
				  xfer += this->deadTabletServers[_i55].read (
				      iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.deadTabletServers = true;
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
	    MasterMonitorInfo::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("MasterMonitorInfo");

	      xfer += oprot->writeFieldBegin ("tableMap",
					      ::apache::thrift::protocol::T_MAP,
					      1);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->tableMap.size ()));
		  std::map<std::string, TableInfo>::const_iterator _iter56;
		  for (_iter56 = this->tableMap.begin ();
		      _iter56 != this->tableMap.end (); ++_iter56)
		    {
		      xfer += oprot->writeString (_iter56->first);
		      xfer += _iter56->second.write (oprot);
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tServerInfo", ::apache::thrift::protocol::T_LIST, 2);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->tServerInfo.size ()));
		  std::vector<TabletServerStatus>::const_iterator _iter57;
		  for (_iter57 = this->tServerInfo.begin ();
		      _iter57 != this->tServerInfo.end (); ++_iter57)
		    {
		      xfer += (*_iter57).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("badTServers",
					      ::apache::thrift::protocol::T_MAP,
					      3);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRING,
		      ::apache::thrift::protocol::T_BYTE,
		      static_cast<uint32_t> (this->badTServers.size ()));
		  std::map<std::string, int8_t>::const_iterator _iter58;
		  for (_iter58 = this->badTServers.begin ();
		      _iter58 != this->badTServers.end (); ++_iter58)
		    {
		      xfer += oprot->writeString (_iter58->first);
		      xfer += oprot->writeByte (_iter58->second);
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("state",
					      ::apache::thrift::protocol::T_I32,
					      6);
	      xfer += oprot->writeI32 ((int32_t) this->state);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("unassignedTablets",
					      ::apache::thrift::protocol::T_I32,
					      7);
	      xfer += oprot->writeI32 (this->unassignedTablets);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("goalState",
					      ::apache::thrift::protocol::T_I32,
					      8);
	      xfer += oprot->writeI32 ((int32_t) this->goalState);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("serversShuttingDown",
					      ::apache::thrift::protocol::T_SET,
					      9);
		{
		  xfer +=
		      oprot->writeSetBegin (
			  ::apache::thrift::protocol::T_STRING,
			  static_cast<uint32_t> (this->serversShuttingDown.size ()));
		  std::set<std::string>::const_iterator _iter59;
		  for (_iter59 = this->serversShuttingDown.begin ();
		      _iter59 != this->serversShuttingDown.end (); ++_iter59)
		    {
		      xfer += oprot->writeString ((*_iter59));
		    }
		  xfer += oprot->writeSetEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "deadTabletServers", ::apache::thrift::protocol::T_LIST, 10);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->deadTabletServers.size ()));
		  std::vector<DeadServer>::const_iterator _iter60;
		  for (_iter60 = this->deadTabletServers.begin ();
		      _iter60 != this->deadTabletServers.end (); ++_iter60)
		    {
		      xfer += (*_iter60).write (oprot);
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
	    swap (MasterMonitorInfo &a, MasterMonitorInfo &b)
	    {
	      using ::std::swap;
	      swap (a.tableMap, b.tableMap);
	      swap (a.tServerInfo, b.tServerInfo);
	      swap (a.badTServers, b.badTServers);
	      swap (a.state, b.state);
	      swap (a.goalState, b.goalState);
	      swap (a.unassignedTablets, b.unassignedTablets);
	      swap (a.serversShuttingDown, b.serversShuttingDown);
	      swap (a.deadTabletServers, b.deadTabletServers);
	      swap (a.__isset, b.__isset);
	    }

	    MasterMonitorInfo::MasterMonitorInfo (
		const MasterMonitorInfo& other61)
	    {
	      tableMap = other61.tableMap;
	      tServerInfo = other61.tServerInfo;
	      badTServers = other61.badTServers;
	      state = other61.state;
	      goalState = other61.goalState;
	      unassignedTablets = other61.unassignedTablets;
	      serversShuttingDown = other61.serversShuttingDown;
	      deadTabletServers = other61.deadTabletServers;
	      __isset = other61.__isset;
	    }
	    MasterMonitorInfo&
	    MasterMonitorInfo::operator= (const MasterMonitorInfo& other62)
	    {
	      tableMap = other62.tableMap;
	      tServerInfo = other62.tServerInfo;
	      badTServers = other62.badTServers;
	      state = other62.state;
	      goalState = other62.goalState;
	      unassignedTablets = other62.unassignedTablets;
	      serversShuttingDown = other62.serversShuttingDown;
	      deadTabletServers = other62.deadTabletServers;
	      __isset = other62.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const MasterMonitorInfo& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "MasterMonitorInfo(";
	      out << "tableMap=" << to_string (obj.tableMap);
	      out << ", " << "tServerInfo=" << to_string (obj.tServerInfo);
	      out << ", " << "badTServers=" << to_string (obj.badTServers);
	      out << ", " << "state=" << to_string (obj.state);
	      out << ", " << "goalState=" << to_string (obj.goalState);
	      out << ", " << "unassignedTablets="
		  << to_string (obj.unassignedTablets);
	      out << ", " << "serversShuttingDown="
		  << to_string (obj.serversShuttingDown);
	      out << ", " << "deadTabletServers="
		  << to_string (obj.deadTabletServers);
	      out << ")";
	      return out;
	    }

	    TabletSplit::~TabletSplit () throw ()
	    {
	    }

	    void
	    TabletSplit::__set_oldTablet (
		const ::org::apache::accumulo::core::data::thrift::TKeyExtent& val)
	    {
	      this->oldTablet = val;
	    }

	    void
	    TabletSplit::__set_newTablets (
		const std::vector<
		    ::org::apache::accumulo::core::data::thrift::TKeyExtent> & val)
	    {
	      this->newTablets = val;
	    }

	    const char* TabletSplit::ascii_fingerprint =
		"512446FDB691C6A2252369D371A5BDE9";
	    const uint8_t TabletSplit::binary_fingerprint[16] =
	      { 0x51, 0x24, 0x46, 0xFD, 0xB6, 0x91, 0xC6, 0xA2, 0x25, 0x23,
		  0x69, 0xD3, 0x71, 0xA5, 0xBD, 0xE9 };

	    uint32_t
	    TabletSplit::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += this->oldTablet.read (iprot);
			  this->__isset.oldTablet = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_LIST)
			{
			    {
			      this->newTablets.clear ();
			      uint32_t _size63;
			      ::apache::thrift::protocol::TType _etype66;
			      xfer += iprot->readListBegin (_etype66, _size63);
			      this->newTablets.resize (_size63);
			      uint32_t _i67;
			      for (_i67 = 0; _i67 < _size63; ++_i67)
				{
				  xfer += this->newTablets[_i67].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.newTablets = true;
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
	    TabletSplit::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TabletSplit");

	      xfer += oprot->writeFieldBegin (
		  "oldTablet", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->oldTablet.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "newTablets", ::apache::thrift::protocol::T_LIST, 2);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->newTablets.size ()));
		  std::vector<
		      ::org::apache::accumulo::core::data::thrift::TKeyExtent>::const_iterator _iter68;
		  for (_iter68 = this->newTablets.begin ();
		      _iter68 != this->newTablets.end (); ++_iter68)
		    {
		      xfer += (*_iter68).write (oprot);
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
	    swap (TabletSplit &a, TabletSplit &b)
	    {
	      using ::std::swap;
	      swap (a.oldTablet, b.oldTablet);
	      swap (a.newTablets, b.newTablets);
	      swap (a.__isset, b.__isset);
	    }

	    TabletSplit::TabletSplit (const TabletSplit& other69)
	    {
	      oldTablet = other69.oldTablet;
	      newTablets = other69.newTablets;
	      __isset = other69.__isset;
	    }
	    TabletSplit&
	    TabletSplit::operator= (const TabletSplit& other70)
	    {
	      oldTablet = other70.oldTablet;
	      newTablets = other70.newTablets;
	      __isset = other70.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TabletSplit& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TabletSplit(";
	      out << "oldTablet=" << to_string (obj.oldTablet);
	      out << ", " << "newTablets=" << to_string (obj.newTablets);
	      out << ")";
	      return out;
	    }

	    RecoveryException::~RecoveryException () throw ()
	    {
	    }

	    void
	    RecoveryException::__set_why (const std::string& val)
	    {
	      this->why = val;
	    }

	    const char* RecoveryException::ascii_fingerprint =
		"EFB929595D312AC8F305D5A794CFEDA1";
	    const uint8_t RecoveryException::binary_fingerprint[16] =
	      { 0xEF, 0xB9, 0x29, 0x59, 0x5D, 0x31, 0x2A, 0xC8, 0xF3, 0x05,
		  0xD5, 0xA7, 0x94, 0xCF, 0xED, 0xA1 };

	    uint32_t
	    RecoveryException::read (
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
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->why);
			  this->__isset.why = true;
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
	    RecoveryException::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("RecoveryException");

	      xfer += oprot->writeFieldBegin (
		  "why", ::apache::thrift::protocol::T_STRING, 1);
	      xfer += oprot->writeString (this->why);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (RecoveryException &a, RecoveryException &b)
	    {
	      using ::std::swap;
	      swap (a.why, b.why);
	      swap (a.__isset, b.__isset);
	    }

	    RecoveryException::RecoveryException (
		const RecoveryException& other71) :
		TException ()
	    {
	      why = other71.why;
	      __isset = other71.__isset;
	    }
	    RecoveryException&
	    RecoveryException::operator= (const RecoveryException& other72)
	    {
	      why = other72.why;
	      __isset = other72.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const RecoveryException& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "RecoveryException(";
	      out << "why=" << to_string (obj.why);
	      out << ")";
	      return out;
	    }

	  }
	}
      }
    }
  }
} // namespace
