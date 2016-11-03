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
#include "../../../../include/data/extern/thrift/data_types.h"

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
	namespace data
	{
	  namespace thrift
	  {

	    int _kTCMStatusValues[] =
	      { TCMStatus::ACCEPTED, TCMStatus::REJECTED, TCMStatus::VIOLATED,
		  TCMStatus::IGNORED };
	    const char* _kTCMStatusNames[] =
	      { "ACCEPTED", "REJECTED", "VIOLATED", "IGNORED" };
	    const std::map<int, const char*> _TCMStatus_VALUES_TO_NAMES (
		::apache::thrift::TEnumIterator (4, _kTCMStatusValues,
						 _kTCMStatusNames),
		::apache::thrift::TEnumIterator (-1, NULL, NULL));

	    TKey::~TKey () throw ()
	    {
	    }

	    void
	    TKey::__set_row (const std::string& val)
	    {
	      this->row = val;
	    }

	    void
	    TKey::__set_colFamily (const std::string& val)
	    {
	      this->colFamily = val;
	    }

	    void
	    TKey::__set_colQualifier (const std::string& val)
	    {
	      this->colQualifier = val;
	    }

	    void
	    TKey::__set_colVisibility (const std::string& val)
	    {
	      this->colVisibility = val;
	    }

	    void
	    TKey::__set_timestamp (const int64_t val)
	    {
	      this->timestamp = val;
	    }

	    const char* TKey::ascii_fingerprint =
		"A25840E2198F27E10AEEE70C9265C644";
	    const uint8_t TKey::binary_fingerprint[16] =
	      { 0xA2, 0x58, 0x40, 0xE2, 0x19, 0x8F, 0x27, 0xE1, 0x0A, 0xEE,
		  0xE7, 0x0C, 0x92, 0x65, 0xC6, 0x44 };

	    uint32_t
	    TKey::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readBinary (this->row);
			  this->__isset.row = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->colFamily);
			  this->__isset.colFamily = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->colQualifier);
			  this->__isset.colQualifier = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->colVisibility);
			  this->__isset.colVisibility = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->timestamp);
			  this->__isset.timestamp = true;
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
	    TKey::write (::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TKey");

	      xfer += oprot->writeFieldBegin (
		  "row", ::apache::thrift::protocol::T_STRING, 1);
	      xfer += oprot->writeBinary (this->row);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "colFamily", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeBinary (this->colFamily);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "colQualifier", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeBinary (this->colQualifier);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "colVisibility", ::apache::thrift::protocol::T_STRING, 4);
	      xfer += oprot->writeBinary (this->colVisibility);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("timestamp",
					      ::apache::thrift::protocol::T_I64,
					      5);
	      xfer += oprot->writeI64 (this->timestamp);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TKey &a, TKey &b)
	    {
	      using ::std::swap;
	      swap (a.row, b.row);
	      swap (a.colFamily, b.colFamily);
	      swap (a.colQualifier, b.colQualifier);
	      swap (a.colVisibility, b.colVisibility);
	      swap (a.timestamp, b.timestamp);
	      swap (a.__isset, b.__isset);
	    }

	    TKey::TKey (const TKey& other0)
	    {
	      row = other0.row;
	      colFamily = other0.colFamily;
	      colQualifier = other0.colQualifier;
	      colVisibility = other0.colVisibility;
	      timestamp = other0.timestamp;
	      __isset = other0.__isset;
	    }
	    TKey&
	    TKey::operator= (const TKey& other1)
	    {
	      row = other1.row;
	      colFamily = other1.colFamily;
	      colQualifier = other1.colQualifier;
	      colVisibility = other1.colVisibility;
	      timestamp = other1.timestamp;
	      __isset = other1.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TKey& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TKey(";
	      out << "row=" << to_string (obj.row);
	      out << ", " << "colFamily=" << to_string (obj.colFamily);
	      out << ", " << "colQualifier=" << to_string (obj.colQualifier);
	      out << ", " << "colVisibility=" << to_string (obj.colVisibility);
	      out << ", " << "timestamp=" << to_string (obj.timestamp);
	      out << ")";
	      return out;
	    }

	    TColumn::~TColumn () throw ()
	    {
	    }

	    void
	    TColumn::__set_columnFamily (const std::string& val)
	    {
	      this->columnFamily = val;
	    }

	    void
	    TColumn::__set_columnQualifier (const std::string& val)
	    {
	      this->columnQualifier = val;
	    }

	    void
	    TColumn::__set_columnVisibility (const std::string& val)
	    {
	      this->columnVisibility = val;
	    }

	    const char* TColumn::ascii_fingerprint =
		"AB879940BD15B6B25691265F7384B271";
	    const uint8_t TColumn::binary_fingerprint[16] =
	      { 0xAB, 0x87, 0x99, 0x40, 0xBD, 0x15, 0xB6, 0xB2, 0x56, 0x91,
		  0x26, 0x5F, 0x73, 0x84, 0xB2, 0x71 };

	    uint32_t
	    TColumn::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readBinary (this->columnFamily);
			  this->__isset.columnFamily = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->columnQualifier);
			  this->__isset.columnQualifier = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->columnVisibility);
			  this->__isset.columnVisibility = true;
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
	    TColumn::write (::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TColumn");

	      xfer += oprot->writeFieldBegin (
		  "columnFamily", ::apache::thrift::protocol::T_STRING, 1);
	      xfer += oprot->writeBinary (this->columnFamily);
	      xfer += oprot->writeFieldEnd ();

	      if (this->columnQualifier.length () > 0)
		{
		  xfer += oprot->writeFieldBegin (
		      "columnQualifier", ::apache::thrift::protocol::T_STRING,
		      2);
		  xfer += oprot->writeBinary (this->columnQualifier);
		  xfer += oprot->writeFieldEnd ();
		}

	      if (this->columnVisibility.length () > 0)
		{
		  xfer += oprot->writeFieldBegin (
		      "columnVisibility", ::apache::thrift::protocol::T_STRING,
		      3);
		  xfer += oprot->writeBinary (this->columnVisibility);
		  xfer += oprot->writeFieldEnd ();
		}

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TColumn &a, TColumn &b)
	    {
	      using ::std::swap;
	      swap (a.columnFamily, b.columnFamily);
	      swap (a.columnQualifier, b.columnQualifier);
	      swap (a.columnVisibility, b.columnVisibility);
	      swap (a.__isset, b.__isset);
	    }

	    TColumn::TColumn (const TColumn& other2)
	    {
	      columnFamily = other2.columnFamily;
	      columnQualifier = other2.columnQualifier;
	      columnVisibility = other2.columnVisibility;
	      __isset = other2.__isset;
	    }
	    TColumn&
	    TColumn::operator= (const TColumn& other3)
	    {
	      columnFamily = other3.columnFamily;
	      columnQualifier = other3.columnQualifier;
	      columnVisibility = other3.columnVisibility;
	      __isset = other3.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TColumn& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TColumn(";
	      out << "columnFamily=" << to_string (obj.columnFamily);
	      out << ", " << "columnQualifier="
		  << to_string (obj.columnQualifier);
	      out << ", " << "columnVisibility="
		  << to_string (obj.columnVisibility);
	      out << ")";
	      return out;
	    }

	    TMutation::~TMutation () throw ()
	    {
	    }

	    void
	    TMutation::__set_row (const std::string& val)
	    {
	      this->row = val;
	    }

	    void
	    TMutation::__set_data (const std::string& val)
	    {
	      this->data = val;
	    }

	    void
	    TMutation::__set_values (const std::vector<std::string> & val)
	    {
	      this->values = val;
	    }

	    void
	    TMutation::__set_entries (const int32_t val)
	    {
	      this->entries = val;
	    }

	    const char* TMutation::ascii_fingerprint =
		"FD79BD16256E16CC9822166FFB701F19";
	    const uint8_t TMutation::binary_fingerprint[16] =
	      { 0xFD, 0x79, 0xBD, 0x16, 0x25, 0x6E, 0x16, 0xCC, 0x98, 0x22,
		  0x16, 0x6F, 0xFB, 0x70, 0x1F, 0x19 };

	    uint32_t
	    TMutation::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readBinary (this->row);
			  this->__isset.row = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->data);
			  this->__isset.data = true;
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
			      this->values.clear ();
			      uint32_t _size4;
			      ::apache::thrift::protocol::TType _etype7;
			      xfer += iprot->readListBegin (_etype7, _size4);
			      this->values.resize (_size4);
			      uint32_t _i8;
			      for (_i8 = 0; _i8 < _size4; ++_i8)
				{
				  xfer += iprot->readBinary (this->values[_i8]);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.values = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  xfer += iprot->readI32 (this->entries);
			  this->__isset.entries = true;
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
	    TMutation::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TMutation");

	      xfer += oprot->writeFieldBegin (
		  "row", ::apache::thrift::protocol::T_STRING, 1);
	      xfer += oprot->writeBinary (this->row);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "data", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeBinary (this->data);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "values", ::apache::thrift::protocol::T_LIST, 3);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRING,
		      static_cast<uint32_t> (this->values.size ()));
		  std::vector<std::string>::const_iterator _iter9;
		  for (_iter9 = this->values.begin ();
		      _iter9 != this->values.end (); ++_iter9)
		    {
		      xfer += oprot->writeBinary ((*_iter9));
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("entries",
					      ::apache::thrift::protocol::T_I32,
					      4);
	      xfer += oprot->writeI32 (this->entries);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TMutation &a, TMutation &b)
	    {
	      using ::std::swap;
	      swap (a.row, b.row);
	      swap (a.data, b.data);
	      swap (a.values, b.values);
	      swap (a.entries, b.entries);
	      swap (a.__isset, b.__isset);
	    }

	    TMutation::TMutation (const TMutation& other10)
	    {
	      row = other10.row;
	      data = other10.data;
	      values = other10.values;
	      entries = other10.entries;
	      __isset = other10.__isset;
	    }
	    TMutation&
	    TMutation::operator= (const TMutation& other11)
	    {
	      row = other11.row;
	      data = other11.data;
	      values = other11.values;
	      entries = other11.entries;
	      __isset = other11.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TMutation& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TMutation(";
	      out << "row=" << to_string (obj.row);
	      out << ", " << "data=" << to_string (obj.data);
	      out << ", " << "values=" << to_string (obj.values);
	      out << ", " << "entries=" << to_string (obj.entries);
	      out << ")";
	      return out;
	    }

	    TKeyExtent::~TKeyExtent () throw ()
	    {
	    }

	    void
	    TKeyExtent::__set_table (const std::string& val)
	    {
	      this->table = val;
	    }

	    void
	    TKeyExtent::__set_endRow (const std::string& val)
	    {
	      this->endRow = val;
	    }

	    void
	    TKeyExtent::__set_prevEndRow (const std::string& val)
	    {
	      this->prevEndRow = val;
	    }

	    const char* TKeyExtent::ascii_fingerprint =
		"AB879940BD15B6B25691265F7384B271";
	    const uint8_t TKeyExtent::binary_fingerprint[16] =
	      { 0xAB, 0x87, 0x99, 0x40, 0xBD, 0x15, 0xB6, 0xB2, 0x56, 0x91,
		  0x26, 0x5F, 0x73, 0x84, 0xB2, 0x71 };

	    uint32_t
	    TKeyExtent::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readBinary (this->table);
			  this->__isset.table = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->prevEndRow);
			  this->__isset.prevEndRow = true;
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
	    TKeyExtent::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TKeyExtent");

	      xfer += oprot->writeFieldBegin (
		  "table", ::apache::thrift::protocol::T_STRING, 1);
	      xfer += oprot->writeBinary (this->table);
	      xfer += oprot->writeFieldEnd ();

	      if (this->endRow.length () > 0)
		{
		  xfer += oprot->writeFieldBegin (
		      "endRow", ::apache::thrift::protocol::T_STRING, 2);
		  xfer += oprot->writeBinary (this->endRow);
		  xfer += oprot->writeFieldEnd ();
		}

	      if (this->prevEndRow.length () > 0)
		{
		  xfer += oprot->writeFieldBegin (
		      "prevEndRow", ::apache::thrift::protocol::T_STRING, 3);
		  xfer += oprot->writeBinary (this->prevEndRow);
		  xfer += oprot->writeFieldEnd ();
		}

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TKeyExtent &a, TKeyExtent &b)
	    {
	      using ::std::swap;
	      swap (a.table, b.table);
	      swap (a.endRow, b.endRow);
	      swap (a.prevEndRow, b.prevEndRow);
	      swap (a.__isset, b.__isset);
	    }

	    TKeyExtent::TKeyExtent (const TKeyExtent& other12)
	    {
	      table = other12.table;
	      endRow = other12.endRow;
	      prevEndRow = other12.prevEndRow;
	      __isset = other12.__isset;
	    }
	    TKeyExtent&
	    TKeyExtent::operator= (const TKeyExtent& other13)
	    {
	      table = other13.table;
	      endRow = other13.endRow;
	      prevEndRow = other13.prevEndRow;
	      __isset = other13.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TKeyExtent& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TKeyExtent(";
	      out << "table=" << to_string (obj.table);
	      out << ", " << "endRow=" << to_string (obj.endRow);
	      out << ", " << "prevEndRow=" << to_string (obj.prevEndRow);
	      out << ")";
	      return out;
	    }

	    TKeyValue::~TKeyValue () throw ()
	    {
	    }

	    void
	    TKeyValue::__set_key (const TKey& val)
	    {
	      this->key = val;
	    }

	    void
	    TKeyValue::__set_value (const std::string& val)
	    {
	      this->value = val;
	    }

	    const char* TKeyValue::ascii_fingerprint =
		"8DCBA6F4B336C8854964F08FBF391943";
	    const uint8_t TKeyValue::binary_fingerprint[16] =
	      { 0x8D, 0xCB, 0xA6, 0xF4, 0xB3, 0x36, 0xC8, 0x85, 0x49, 0x64,
		  0xF0, 0x8F, 0xBF, 0x39, 0x19, 0x43 };

	    uint32_t
	    TKeyValue::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += this->key.read (iprot);
			  this->__isset.key = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->value);
			  this->__isset.value = true;
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
	    TKeyValue::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TKeyValue");

	      xfer += oprot->writeFieldBegin (
		  "key", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->key.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "value", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeBinary (this->value);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TKeyValue &a, TKeyValue &b)
	    {
	      using ::std::swap;
	      swap (a.key, b.key);
	      swap (a.value, b.value);
	      swap (a.__isset, b.__isset);
	    }

	    TKeyValue::TKeyValue (const TKeyValue& other14)
	    {
	      key = other14.key;
	      value = other14.value;
	      __isset = other14.__isset;
	    }
	    TKeyValue&
	    TKeyValue::operator= (const TKeyValue& other15)
	    {
	      key = other15.key;
	      value = other15.value;
	      __isset = other15.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TKeyValue& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TKeyValue(";
	      out << "key=" << to_string (obj.key);
	      out << ", " << "value=" << to_string (obj.value);
	      out << ")";
	      return out;
	    }

	    ScanResult::~ScanResult () throw ()
	    {
	    }

	    void
	    ScanResult::__set_results (const std::vector<TKeyValue> & val)
	    {
	      this->results = val;
	    }

	    void
	    ScanResult::__set_more (const bool val)
	    {
	      this->more = val;
	    }

	    const char* ScanResult::ascii_fingerprint =
		"6F1B73B7E271D491518DF10CFB0E8087";
	    const uint8_t ScanResult::binary_fingerprint[16] =
	      { 0x6F, 0x1B, 0x73, 0xB7, 0xE2, 0x71, 0xD4, 0x91, 0x51, 0x8D,
		  0xF1, 0x0C, 0xFB, 0x0E, 0x80, 0x87 };

	    uint32_t
	    ScanResult::read (::apache::thrift::protocol::TProtocol* iprot)
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
			      this->results.clear ();
			      uint32_t _size16;
			      ::apache::thrift::protocol::TType _etype19;
			      xfer += iprot->readListBegin (_etype19, _size16);
			      this->results.resize (_size16);
			      uint32_t _i20;
			      for (_i20 = 0; _i20 < _size16; ++_i20)
				{
				  xfer += this->results[_i20].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.results = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->more);
			  this->__isset.more = true;
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
	    ScanResult::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("ScanResult");

	      xfer += oprot->writeFieldBegin (
		  "results", ::apache::thrift::protocol::T_LIST, 1);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->results.size ()));
		  std::vector<TKeyValue>::const_iterator _iter21;
		  for (_iter21 = this->results.begin ();
		      _iter21 != this->results.end (); ++_iter21)
		    {
		      xfer += (*_iter21).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "more", ::apache::thrift::protocol::T_BOOL, 2);
	      xfer += oprot->writeBool (this->more);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (ScanResult &a, ScanResult &b)
	    {
	      using ::std::swap;
	      swap (a.results, b.results);
	      swap (a.more, b.more);
	      swap (a.__isset, b.__isset);
	    }

	    ScanResult::ScanResult (const ScanResult& other22)
	    {
	      results = other22.results;
	      more = other22.more;
	      __isset = other22.__isset;
	    }
	    ScanResult&
	    ScanResult::operator= (const ScanResult& other23)
	    {
	      results = other23.results;
	      more = other23.more;
	      __isset = other23.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const ScanResult& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "ScanResult(";
	      out << "results=" << to_string (obj.results);
	      out << ", " << "more=" << to_string (obj.more);
	      out << ")";
	      return out;
	    }

	    TRange::~TRange () throw ()
	    {
	    }

	    void
	    TRange::__set_start (const TKey& val)
	    {
	      this->start = val;
	    }

	    void
	    TRange::__set_stop (const TKey& val)
	    {
	      this->stop = val;
	    }

	    void
	    TRange::__set_startKeyInclusive (const bool val)
	    {
	      this->startKeyInclusive = val;
	    }

	    void
	    TRange::__set_stopKeyInclusive (const bool val)
	    {
	      this->stopKeyInclusive = val;
	    }

	    void
	    TRange::__set_infiniteStartKey (const bool val)
	    {
	      this->infiniteStartKey = val;
	    }

	    void
	    TRange::__set_infiniteStopKey (const bool val)
	    {
	      this->infiniteStopKey = val;
	    }

	    const char* TRange::ascii_fingerprint =
		"51C5BDA7AC16F12A08D7C8B6BB52C360";
	    const uint8_t TRange::binary_fingerprint[16] =
	      { 0x51, 0xC5, 0xBD, 0xA7, 0xAC, 0x16, 0xF1, 0x2A, 0x08, 0xD7,
		  0xC8, 0xB6, 0xBB, 0x52, 0xC3, 0x60 };

	    uint32_t
	    TRange::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += this->start.read (iprot);
			  this->__isset.start = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->stop.read (iprot);
			  this->__isset.stop = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->startKeyInclusive);
			  this->__isset.startKeyInclusive = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->stopKeyInclusive);
			  this->__isset.stopKeyInclusive = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->infiniteStartKey);
			  this->__isset.infiniteStartKey = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->infiniteStopKey);
			  this->__isset.infiniteStopKey = true;
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
	    TRange::write (::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TRange");

	      xfer += oprot->writeFieldBegin (
		  "start", ::apache::thrift::protocol::T_STRUCT, 1);
	      xfer += this->start.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "stop", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->stop.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "startKeyInclusive", ::apache::thrift::protocol::T_BOOL, 3);
	      xfer += oprot->writeBool (this->startKeyInclusive);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "stopKeyInclusive", ::apache::thrift::protocol::T_BOOL, 4);
	      xfer += oprot->writeBool (this->stopKeyInclusive);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "infiniteStartKey", ::apache::thrift::protocol::T_BOOL, 5);
	      xfer += oprot->writeBool (this->infiniteStartKey);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "infiniteStopKey", ::apache::thrift::protocol::T_BOOL, 6);
	      xfer += oprot->writeBool (this->infiniteStopKey);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TRange &a, TRange &b)
	    {
	      using ::std::swap;
	      swap (a.start, b.start);
	      swap (a.stop, b.stop);
	      swap (a.startKeyInclusive, b.startKeyInclusive);
	      swap (a.stopKeyInclusive, b.stopKeyInclusive);
	      swap (a.infiniteStartKey, b.infiniteStartKey);
	      swap (a.infiniteStopKey, b.infiniteStopKey);
	      swap (a.__isset, b.__isset);
	    }

	    TRange::TRange (const TRange& other24)
	    {
	      start = other24.start;
	      stop = other24.stop;
	      startKeyInclusive = other24.startKeyInclusive;
	      stopKeyInclusive = other24.stopKeyInclusive;
	      infiniteStartKey = other24.infiniteStartKey;
	      infiniteStopKey = other24.infiniteStopKey;
	      __isset = other24.__isset;
	    }
	    TRange&
	    TRange::operator= (const TRange& other25)
	    {
	      start = other25.start;
	      stop = other25.stop;
	      startKeyInclusive = other25.startKeyInclusive;
	      stopKeyInclusive = other25.stopKeyInclusive;
	      infiniteStartKey = other25.infiniteStartKey;
	      infiniteStopKey = other25.infiniteStopKey;
	      __isset = other25.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TRange& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TRange(";
	      out << "start=" << to_string (obj.start);
	      out << ", " << "stop=" << to_string (obj.stop);
	      out << ", " << "startKeyInclusive="
		  << to_string (obj.startKeyInclusive);
	      out << ", " << "stopKeyInclusive="
		  << to_string (obj.stopKeyInclusive);
	      out << ", " << "infiniteStartKey="
		  << to_string (obj.infiniteStartKey);
	      out << ", " << "infiniteStopKey="
		  << to_string (obj.infiniteStopKey);
	      out << ")";
	      return out;
	    }

	    MultiScanResult::~MultiScanResult () throw ()
	    {
	    }

	    void
	    MultiScanResult::__set_results (const std::vector<TKeyValue> & val)
	    {
	      this->results = val;
	    }

	    void
	    MultiScanResult::__set_failures (const ScanBatch& val)
	    {
	      this->failures = val;
	    }

	    void
	    MultiScanResult::__set_fullScans (
		const std::vector<TKeyExtent> & val)
	    {
	      this->fullScans = val;
	    }

	    void
	    MultiScanResult::__set_partScan (const TKeyExtent& val)
	    {
	      this->partScan = val;
	    }

	    void
	    MultiScanResult::__set_partNextKey (const TKey& val)
	    {
	      this->partNextKey = val;
	    }

	    void
	    MultiScanResult::__set_partNextKeyInclusive (const bool val)
	    {
	      this->partNextKeyInclusive = val;
	    }

	    void
	    MultiScanResult::__set_more (const bool val)
	    {
	      this->more = val;
	    }

	    const char* MultiScanResult::ascii_fingerprint =
		"1710A2EAC368D6E92A3F98939AD49DAF";
	    const uint8_t MultiScanResult::binary_fingerprint[16] =
	      { 0x17, 0x10, 0xA2, 0xEA, 0xC3, 0x68, 0xD6, 0xE9, 0x2A, 0x3F,
		  0x98, 0x93, 0x9A, 0xD4, 0x9D, 0xAF };

	    uint32_t
	    MultiScanResult::read (::apache::thrift::protocol::TProtocol* iprot)
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
			      this->results.clear ();
			      uint32_t _size26;
			      ::apache::thrift::protocol::TType _etype29;
			      xfer += iprot->readListBegin (_etype29, _size26);
			      this->results.resize (_size26);
			      uint32_t _i30;
			      for (_i30 = 0; _i30 < _size26; ++_i30)
				{
				  xfer += this->results[_i30].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.results = true;
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
			      this->failures.clear ();
			      uint32_t _size31;
			      ::apache::thrift::protocol::TType _ktype32;
			      ::apache::thrift::protocol::TType _vtype33;
			      xfer += iprot->readMapBegin (_ktype32, _vtype33,
							   _size31);
			      uint32_t _i35;
			      for (_i35 = 0; _i35 < _size31; ++_i35)
				{
				  TKeyExtent _key36;
				  xfer += _key36.read (iprot);
				  std::vector<TRange> & _val37 =
				      this->failures[_key36];
				    {
				      _val37.clear ();
				      uint32_t _size38;
				      ::apache::thrift::protocol::TType _etype41;
				      xfer += iprot->readListBegin (_etype41,
								    _size38);
				      _val37.resize (_size38);
				      uint32_t _i42;
				      for (_i42 = 0; _i42 < _size38; ++_i42)
					{
					  xfer += _val37[_i42].read (iprot);
					}
				      xfer += iprot->readListEnd ();
				    }
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.failures = true;
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
			      this->fullScans.clear ();
			      uint32_t _size43;
			      ::apache::thrift::protocol::TType _etype46;
			      xfer += iprot->readListBegin (_etype46, _size43);
			      this->fullScans.resize (_size43);
			      uint32_t _i47;
			      for (_i47 = 0; _i47 < _size43; ++_i47)
				{
				  xfer += this->fullScans[_i47].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.fullScans = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->partScan.read (iprot);
			  this->__isset.partScan = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->partNextKey.read (iprot);
			  this->__isset.partNextKey = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->partNextKeyInclusive);
			  this->__isset.partNextKeyInclusive = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->more);
			  this->__isset.more = true;
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
	    MultiScanResult::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("MultiScanResult");

	      xfer += oprot->writeFieldBegin (
		  "results", ::apache::thrift::protocol::T_LIST, 1);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->results.size ()));
		  std::vector<TKeyValue>::const_iterator _iter48;
		  for (_iter48 = this->results.begin ();
		      _iter48 != this->results.end (); ++_iter48)
		    {
		      xfer += (*_iter48).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("failures",
					      ::apache::thrift::protocol::T_MAP,
					      2);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      ::apache::thrift::protocol::T_LIST,
		      static_cast<uint32_t> (this->failures.size ()));
		  std::map<TKeyExtent, std::vector<TRange> >::const_iterator _iter49;
		  for (_iter49 = this->failures.begin ();
		      _iter49 != this->failures.end (); ++_iter49)
		    {
		      xfer += _iter49->first.write (oprot);
			{
			  xfer += oprot->writeListBegin (
			      ::apache::thrift::protocol::T_STRUCT,
			      static_cast<uint32_t> (_iter49->second.size ()));
			  std::vector<TRange>::const_iterator _iter50;
			  for (_iter50 = _iter49->second.begin ();
			      _iter50 != _iter49->second.end (); ++_iter50)
			    {
			      xfer += (*_iter50).write (oprot);
			    }
			  xfer += oprot->writeListEnd ();
			}
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "fullScans", ::apache::thrift::protocol::T_LIST, 3);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->fullScans.size ()));
		  std::vector<TKeyExtent>::const_iterator _iter51;
		  for (_iter51 = this->fullScans.begin ();
		      _iter51 != this->fullScans.end (); ++_iter51)
		    {
		      xfer += (*_iter51).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "partScan", ::apache::thrift::protocol::T_STRUCT, 4);
	      xfer += this->partScan.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "partNextKey", ::apache::thrift::protocol::T_STRUCT, 5);
	      xfer += this->partNextKey.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "partNextKeyInclusive", ::apache::thrift::protocol::T_BOOL,
		  6);
	      xfer += oprot->writeBool (this->partNextKeyInclusive);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "more", ::apache::thrift::protocol::T_BOOL, 7);
	      xfer += oprot->writeBool (this->more);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (MultiScanResult &a, MultiScanResult &b)
	    {
	      using ::std::swap;
	      swap (a.results, b.results);
	      swap (a.failures, b.failures);
	      swap (a.fullScans, b.fullScans);
	      swap (a.partScan, b.partScan);
	      swap (a.partNextKey, b.partNextKey);
	      swap (a.partNextKeyInclusive, b.partNextKeyInclusive);
	      swap (a.more, b.more);
	      swap (a.__isset, b.__isset);
	    }

	    MultiScanResult::MultiScanResult (const MultiScanResult& other52)
	    {
	      results = other52.results;
	      failures = other52.failures;
	      fullScans = other52.fullScans;
	      partScan = other52.partScan;
	      partNextKey = other52.partNextKey;
	      partNextKeyInclusive = other52.partNextKeyInclusive;
	      more = other52.more;
	      __isset = other52.__isset;
	    }
	    MultiScanResult&
	    MultiScanResult::operator= (const MultiScanResult& other53)
	    {
	      results = other53.results;
	      failures = other53.failures;
	      fullScans = other53.fullScans;
	      partScan = other53.partScan;
	      partNextKey = other53.partNextKey;
	      partNextKeyInclusive = other53.partNextKeyInclusive;
	      more = other53.more;
	      __isset = other53.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const MultiScanResult& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "MultiScanResult(";
	      out << "results=" << to_string (obj.results);
	      out << ", " << "failures=" << to_string (obj.failures);
	      out << ", " << "fullScans=" << to_string (obj.fullScans);
	      out << ", " << "partScan=" << to_string (obj.partScan);
	      out << ", " << "partNextKey=" << to_string (obj.partNextKey);
	      out << ", " << "partNextKeyInclusive="
		  << to_string (obj.partNextKeyInclusive);
	      out << ", " << "more=" << to_string (obj.more);
	      out << ")";
	      return out;
	    }

	    InitialScan::~InitialScan () throw ()
	    {
	    }

	    void
	    InitialScan::__set_scanID (const ScanID val)
	    {
	      this->scanID = val;
	    }

	    void
	    InitialScan::__set_result (const ScanResult& val)
	    {
	      this->result = val;
	    }

	    const char* InitialScan::ascii_fingerprint =
		"18AE44780236DD1CAB1037C71440C057";
	    const uint8_t InitialScan::binary_fingerprint[16] =
	      { 0x18, 0xAE, 0x44, 0x78, 0x02, 0x36, 0xDD, 0x1C, 0xAB, 0x10,
		  0x37, 0xC7, 0x14, 0x40, 0xC0, 0x57 };

	    uint32_t
	    InitialScan::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readI64 (this->scanID);
			  this->__isset.scanID = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->result.read (iprot);
			  this->__isset.result = true;
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
	    InitialScan::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("InitialScan");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->scanID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "result", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->result.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (InitialScan &a, InitialScan &b)
	    {
	      using ::std::swap;
	      swap (a.scanID, b.scanID);
	      swap (a.result, b.result);
	      swap (a.__isset, b.__isset);
	    }

	    InitialScan::InitialScan (const InitialScan& other54)
	    {
	      scanID = other54.scanID;
	      result = other54.result;
	      __isset = other54.__isset;
	    }
	    InitialScan&
	    InitialScan::operator= (const InitialScan& other55)
	    {
	      scanID = other55.scanID;
	      result = other55.result;
	      __isset = other55.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const InitialScan& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "InitialScan(";
	      out << "scanID=" << to_string (obj.scanID);
	      out << ", " << "result=" << to_string (obj.result);
	      out << ")";
	      return out;
	    }

	    InitialMultiScan::~InitialMultiScan () throw ()
	    {
	    }

	    void
	    InitialMultiScan::__set_scanID (const ScanID val)
	    {
	      this->scanID = val;
	    }

	    void
	    InitialMultiScan::__set_result (const MultiScanResult& val)
	    {
	      this->result = val;
	    }

	    const char* InitialMultiScan::ascii_fingerprint =
		"3D143740F405DA8C33D95336FD4CFC33";
	    const uint8_t InitialMultiScan::binary_fingerprint[16] =
	      { 0x3D, 0x14, 0x37, 0x40, 0xF4, 0x05, 0xDA, 0x8C, 0x33, 0xD9,
		  0x53, 0x36, 0xFD, 0x4C, 0xFC, 0x33 };

	    uint32_t
	    InitialMultiScan::read (
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
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRUCT)
			{
			  xfer += this->result.read (iprot);
			  this->__isset.result = true;
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
	    InitialMultiScan::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("InitialMultiScan");

	      xfer += oprot->writeFieldBegin ("scanID",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->scanID);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "result", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->result.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (InitialMultiScan &a, InitialMultiScan &b)
	    {
	      using ::std::swap;
	      swap (a.scanID, b.scanID);
	      swap (a.result, b.result);
	      swap (a.__isset, b.__isset);
	    }

	    InitialMultiScan::InitialMultiScan (const InitialMultiScan& other56)
	    {
	      scanID = other56.scanID;
	      result = other56.result;
	      __isset = other56.__isset;
	    }
	    InitialMultiScan&
	    InitialMultiScan::operator= (const InitialMultiScan& other57)
	    {
	      scanID = other57.scanID;
	      result = other57.result;
	      __isset = other57.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const InitialMultiScan& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "InitialMultiScan(";
	      out << "scanID=" << to_string (obj.scanID);
	      out << ", " << "result=" << to_string (obj.result);
	      out << ")";
	      return out;
	    }

	    IterInfo::~IterInfo () throw ()
	    {
	    }

	    void
	    IterInfo::__set_priority (const int32_t val)
	    {
	      this->priority = val;
	    }

	    void
	    IterInfo::__set_className (const std::string& val)
	    {
	      this->className = val;
	    }

	    void
	    IterInfo::__set_iterName (const std::string& val)
	    {
	      this->iterName = val;
	    }

	    const char* IterInfo::ascii_fingerprint =
		"3368C2F81F2FEF71F11EDACDB2A3ECEF";
	    const uint8_t IterInfo::binary_fingerprint[16] =
	      { 0x33, 0x68, 0xC2, 0xF8, 0x1F, 0x2F, 0xEF, 0x71, 0xF1, 0x1E,
		  0xDA, 0xCD, 0xB2, 0xA3, 0xEC, 0xEF };

	    uint32_t
	    IterInfo::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readString (this->className);
			  this->__isset.className = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->iterName);
			  this->__isset.iterName = true;
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
	    IterInfo::write (::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("IterInfo");

	      xfer += oprot->writeFieldBegin ("priority",
					      ::apache::thrift::protocol::T_I32,
					      1);
	      xfer += oprot->writeI32 (this->priority);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "className", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->className);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "iterName", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeString (this->iterName);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (IterInfo &a, IterInfo &b)
	    {
	      using ::std::swap;
	      swap (a.priority, b.priority);
	      swap (a.className, b.className);
	      swap (a.iterName, b.iterName);
	      swap (a.__isset, b.__isset);
	    }

	    IterInfo::IterInfo (const IterInfo& other58)
	    {
	      priority = other58.priority;
	      className = other58.className;
	      iterName = other58.iterName;
	      __isset = other58.__isset;
	    }
	    IterInfo&
	    IterInfo::operator= (const IterInfo& other59)
	    {
	      priority = other59.priority;
	      className = other59.className;
	      iterName = other59.iterName;
	      __isset = other59.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const IterInfo& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "IterInfo(";
	      out << "priority=" << to_string (obj.priority);
	      out << ", " << "className=" << to_string (obj.className);
	      out << ", " << "iterName=" << to_string (obj.iterName);
	      out << ")";
	      return out;
	    }

	    TConstraintViolationSummary::~TConstraintViolationSummary () throw ()
	    {
	    }

	    void
	    TConstraintViolationSummary::__set_constrainClass (
		const std::string& val)
	    {
	      this->constrainClass = val;
	    }

	    void
	    TConstraintViolationSummary::__set_violationCode (const int16_t val)
	    {
	      this->violationCode = val;
	    }

	    void
	    TConstraintViolationSummary::__set_violationDescription (
		const std::string& val)
	    {
	      this->violationDescription = val;
	    }

	    void
	    TConstraintViolationSummary::__set_numberOfViolatingMutations (
		const int64_t val)
	    {
	      this->numberOfViolatingMutations = val;
	    }

	    const char* TConstraintViolationSummary::ascii_fingerprint =
		"67DCD7E9C756B859BA6A7E138EFB1053";
	    const uint8_t TConstraintViolationSummary::binary_fingerprint[16] =
	      { 0x67, 0xDC, 0xD7, 0xE9, 0xC7, 0x56, 0xB8, 0x59, 0xBA, 0x6A,
		  0x7E, 0x13, 0x8E, 0xFB, 0x10, 0x53 };

	    uint32_t
	    TConstraintViolationSummary::read (
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
			  xfer += iprot->readString (this->constrainClass);
			  this->__isset.constrainClass = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I16)
			{
			  xfer += iprot->readI16 (this->violationCode);
			  this->__isset.violationCode = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (
			      this->violationDescription);
			  this->__isset.violationDescription = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (
			      this->numberOfViolatingMutations);
			  this->__isset.numberOfViolatingMutations = true;
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
	    TConstraintViolationSummary::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TConstraintViolationSummary");

	      xfer += oprot->writeFieldBegin (
		  "constrainClass", ::apache::thrift::protocol::T_STRING, 1);
	      xfer += oprot->writeString (this->constrainClass);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("violationCode",
					      ::apache::thrift::protocol::T_I16,
					      2);
	      xfer += oprot->writeI16 (this->violationCode);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "violationDescription", ::apache::thrift::protocol::T_STRING,
		  3);
	      xfer += oprot->writeString (this->violationDescription);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("numberOfViolatingMutations",
					      ::apache::thrift::protocol::T_I64,
					      4);
	      xfer += oprot->writeI64 (this->numberOfViolatingMutations);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TConstraintViolationSummary &a,
		  TConstraintViolationSummary &b)
	    {
	      using ::std::swap;
	      swap (a.constrainClass, b.constrainClass);
	      swap (a.violationCode, b.violationCode);
	      swap (a.violationDescription, b.violationDescription);
	      swap (a.numberOfViolatingMutations, b.numberOfViolatingMutations);
	      swap (a.__isset, b.__isset);
	    }

	    TConstraintViolationSummary::TConstraintViolationSummary (
		const TConstraintViolationSummary& other60)
	    {
	      constrainClass = other60.constrainClass;
	      violationCode = other60.violationCode;
	      violationDescription = other60.violationDescription;
	      numberOfViolatingMutations = other60.numberOfViolatingMutations;
	      __isset = other60.__isset;
	    }
	    TConstraintViolationSummary&
	    TConstraintViolationSummary::operator= (
		const TConstraintViolationSummary& other61)
	    {
	      constrainClass = other61.constrainClass;
	      violationCode = other61.violationCode;
	      violationDescription = other61.violationDescription;
	      numberOfViolatingMutations = other61.numberOfViolatingMutations;
	      __isset = other61.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out,
			const TConstraintViolationSummary& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TConstraintViolationSummary(";
	      out << "constrainClass=" << to_string (obj.constrainClass);
	      out << ", " << "violationCode=" << to_string (obj.violationCode);
	      out << ", " << "violationDescription="
		  << to_string (obj.violationDescription);
	      out << ", " << "numberOfViolatingMutations="
		  << to_string (obj.numberOfViolatingMutations);
	      out << ")";
	      return out;
	    }

	    UpdateErrors::~UpdateErrors () throw ()
	    {
	    }

	    void
	    UpdateErrors::__set_failedExtents (
		const std::map<TKeyExtent, int64_t> & val)
	    {
	      this->failedExtents = val;
	    }

	    void
	    UpdateErrors::__set_violationSummaries (
		const std::vector<TConstraintViolationSummary> & val)
	    {
	      this->violationSummaries = val;
	    }

	    void
	    UpdateErrors::__set_authorizationFailures (
		const std::map<TKeyExtent,
		    ::org::apache::accumulo::core::client::impl::thrift::SecurityErrorCode::type> & val)
	    {
	      this->authorizationFailures = val;
	    }

	    const char* UpdateErrors::ascii_fingerprint =
		"795EFE92A2DF5316A5DED38CBC5BFB32";
	    const uint8_t UpdateErrors::binary_fingerprint[16] =
	      { 0x79, 0x5E, 0xFE, 0x92, 0xA2, 0xDF, 0x53, 0x16, 0xA5, 0xDE,
		  0xD3, 0x8C, 0xBC, 0x5B, 0xFB, 0x32 };

	    uint32_t
	    UpdateErrors::read (::apache::thrift::protocol::TProtocol* iprot)
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
			      this->failedExtents.clear ();
			      uint32_t _size62;
			      ::apache::thrift::protocol::TType _ktype63;
			      ::apache::thrift::protocol::TType _vtype64;
			      xfer += iprot->readMapBegin (_ktype63, _vtype64,
							   _size62);
			      uint32_t _i66;
			      for (_i66 = 0; _i66 < _size62; ++_i66)
				{
				  TKeyExtent _key67;
				  xfer += _key67.read (iprot);
				  int64_t& _val68 = this->failedExtents[_key67];
				  xfer += iprot->readI64 (_val68);
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.failedExtents = true;
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
			      this->violationSummaries.clear ();
			      uint32_t _size69;
			      ::apache::thrift::protocol::TType _etype72;
			      xfer += iprot->readListBegin (_etype72, _size69);
			      this->violationSummaries.resize (_size69);
			      uint32_t _i73;
			      for (_i73 = 0; _i73 < _size69; ++_i73)
				{
				  xfer += this->violationSummaries[_i73].read (
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_MAP)
			{
			    {
			      this->authorizationFailures.clear ();
			      uint32_t _size74;
			      ::apache::thrift::protocol::TType _ktype75;
			      ::apache::thrift::protocol::TType _vtype76;
			      xfer += iprot->readMapBegin (_ktype75, _vtype76,
							   _size74);
			      uint32_t _i78;
			      for (_i78 = 0; _i78 < _size74; ++_i78)
				{
				  TKeyExtent _key79;
				  xfer += _key79.read (iprot);
				  ::org::apache::accumulo::core::client::impl::thrift::SecurityErrorCode::type& _val80 =
				      this->authorizationFailures[_key79];
				  int32_t ecast81;
				  xfer += iprot->readI32 (ecast81);
				  _val80 =
				      (::org::apache::accumulo::core::client::impl::thrift::SecurityErrorCode::type) ecast81;
				}
			      xfer += iprot->readMapEnd ();
			    }
			  this->__isset.authorizationFailures = true;
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
	    UpdateErrors::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("UpdateErrors");

	      xfer += oprot->writeFieldBegin ("failedExtents",
					      ::apache::thrift::protocol::T_MAP,
					      1);
		{
		  xfer += oprot->writeMapBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      ::apache::thrift::protocol::T_I64,
		      static_cast<uint32_t> (this->failedExtents.size ()));
		  std::map<TKeyExtent, int64_t>::const_iterator _iter82;
		  for (_iter82 = this->failedExtents.begin ();
		      _iter82 != this->failedExtents.end (); ++_iter82)
		    {
		      xfer += _iter82->first.write (oprot);
		      xfer += oprot->writeI64 (_iter82->second);
		    }
		  xfer += oprot->writeMapEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "violationSummaries", ::apache::thrift::protocol::T_LIST, 2);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->violationSummaries.size ()));
		  std::vector<TConstraintViolationSummary>::const_iterator _iter83;
		  for (_iter83 = this->violationSummaries.begin ();
		      _iter83 != this->violationSummaries.end (); ++_iter83)
		    {
		      xfer += (*_iter83).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("authorizationFailures",
					      ::apache::thrift::protocol::T_MAP,
					      3);
		{
		  xfer +=
		      oprot->writeMapBegin (
			  ::apache::thrift::protocol::T_STRUCT,
			  ::apache::thrift::protocol::T_I32,
			  static_cast<uint32_t> (this->authorizationFailures.size ()));
		  std::map<TKeyExtent,
		      ::org::apache::accumulo::core::client::impl::thrift::SecurityErrorCode::type>::const_iterator _iter84;
		  for (_iter84 = this->authorizationFailures.begin ();
		      _iter84 != this->authorizationFailures.end (); ++_iter84)
		    {
		      xfer += _iter84->first.write (oprot);
		      xfer += oprot->writeI32 ((int32_t) _iter84->second);
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
	    swap (UpdateErrors &a, UpdateErrors &b)
	    {
	      using ::std::swap;
	      swap (a.failedExtents, b.failedExtents);
	      swap (a.violationSummaries, b.violationSummaries);
	      swap (a.authorizationFailures, b.authorizationFailures);
	      swap (a.__isset, b.__isset);
	    }

	    UpdateErrors::UpdateErrors (const UpdateErrors& other85)
	    {
	      failedExtents = other85.failedExtents;
	      violationSummaries = other85.violationSummaries;
	      authorizationFailures = other85.authorizationFailures;
	      __isset = other85.__isset;
	    }
	    UpdateErrors&
	    UpdateErrors::operator= (const UpdateErrors& other86)
	    {
	      failedExtents = other86.failedExtents;
	      violationSummaries = other86.violationSummaries;
	      authorizationFailures = other86.authorizationFailures;
	      __isset = other86.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const UpdateErrors& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "UpdateErrors(";
	      out << "failedExtents=" << to_string (obj.failedExtents);
	      out << ", " << "violationSummaries="
		  << to_string (obj.violationSummaries);
	      out << ", " << "authorizationFailures="
		  << to_string (obj.authorizationFailures);
	      out << ")";
	      return out;
	    }

	    TCMResult::~TCMResult () throw ()
	    {
	    }

	    void
	    TCMResult::__set_cmid (const int64_t val)
	    {
	      this->cmid = val;
	    }

	    void
	    TCMResult::__set_status (const TCMStatus::type val)
	    {
	      this->status = val;
	    }

	    const char* TCMResult::ascii_fingerprint =
		"DFA40D9D2884599F3D1E7A57578F1384";
	    const uint8_t TCMResult::binary_fingerprint[16] =
	      { 0xDF, 0xA4, 0x0D, 0x9D, 0x28, 0x84, 0x59, 0x9F, 0x3D, 0x1E,
		  0x7A, 0x57, 0x57, 0x8F, 0x13, 0x84 };

	    uint32_t
	    TCMResult::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readI64 (this->cmid);
			  this->__isset.cmid = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_I32)
			{
			  int32_t ecast87;
			  xfer += iprot->readI32 (ecast87);
			  this->status = (TCMStatus::type) ecast87;
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
	    TCMResult::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TCMResult");

	      xfer += oprot->writeFieldBegin ("cmid",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->cmid);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("status",
					      ::apache::thrift::protocol::T_I32,
					      2);
	      xfer += oprot->writeI32 ((int32_t) this->status);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TCMResult &a, TCMResult &b)
	    {
	      using ::std::swap;
	      swap (a.cmid, b.cmid);
	      swap (a.status, b.status);
	      swap (a.__isset, b.__isset);
	    }

	    TCMResult::TCMResult (const TCMResult& other88)
	    {
	      cmid = other88.cmid;
	      status = other88.status;
	      __isset = other88.__isset;
	    }
	    TCMResult&
	    TCMResult::operator= (const TCMResult& other89)
	    {
	      cmid = other89.cmid;
	      status = other89.status;
	      __isset = other89.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TCMResult& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TCMResult(";
	      out << "cmid=" << to_string (obj.cmid);
	      out << ", " << "status=" << to_string (obj.status);
	      out << ")";
	      return out;
	    }

	    MapFileInfo::~MapFileInfo () throw ()
	    {
	    }

	    void
	    MapFileInfo::__set_estimatedSize (const int64_t val)
	    {
	      this->estimatedSize = val;
	    }

	    const char* MapFileInfo::ascii_fingerprint =
		"56A59CE7FFAF82BCA8A19FAACDE4FB75";
	    const uint8_t MapFileInfo::binary_fingerprint[16] =
	      { 0x56, 0xA5, 0x9C, 0xE7, 0xFF, 0xAF, 0x82, 0xBC, 0xA8, 0xA1,
		  0x9F, 0xAA, 0xCD, 0xE4, 0xFB, 0x75 };

	    uint32_t
	    MapFileInfo::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readI64 (this->estimatedSize);
			  this->__isset.estimatedSize = true;
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
	    MapFileInfo::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("MapFileInfo");

	      xfer += oprot->writeFieldBegin ("estimatedSize",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->estimatedSize);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (MapFileInfo &a, MapFileInfo &b)
	    {
	      using ::std::swap;
	      swap (a.estimatedSize, b.estimatedSize);
	      swap (a.__isset, b.__isset);
	    }

	    MapFileInfo::MapFileInfo (const MapFileInfo& other90)
	    {
	      estimatedSize = other90.estimatedSize;
	      __isset = other90.__isset;
	    }
	    MapFileInfo&
	    MapFileInfo::operator= (const MapFileInfo& other91)
	    {
	      estimatedSize = other91.estimatedSize;
	      __isset = other91.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const MapFileInfo& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "MapFileInfo(";
	      out << "estimatedSize=" << to_string (obj.estimatedSize);
	      out << ")";
	      return out;
	    }

	    TCondition::~TCondition () throw ()
	    {
	    }

	    void
	    TCondition::__set_cf (const std::string& val)
	    {
	      this->cf = val;
	    }

	    void
	    TCondition::__set_cq (const std::string& val)
	    {
	      this->cq = val;
	    }

	    void
	    TCondition::__set_cv (const std::string& val)
	    {
	      this->cv = val;
	    }

	    void
	    TCondition::__set_ts (const int64_t val)
	    {
	      this->ts = val;
	    }

	    void
	    TCondition::__set_hasTimestamp (const bool val)
	    {
	      this->hasTimestamp = val;
	    }

	    void
	    TCondition::__set_val (const std::string& val)
	    {
	      this->val = val;
	    }

	    void
	    TCondition::__set_iterators (const std::string& val)
	    {
	      this->iterators = val;
	    }

	    const char* TCondition::ascii_fingerprint =
		"7C10ECB52A73C8207C0290A240145B89";
	    const uint8_t TCondition::binary_fingerprint[16] =
	      { 0x7C, 0x10, 0xEC, 0xB5, 0x2A, 0x73, 0xC8, 0x20, 0x7C, 0x02,
		  0x90, 0xA2, 0x40, 0x14, 0x5B, 0x89 };

	    uint32_t
	    TCondition::read (::apache::thrift::protocol::TProtocol* iprot)
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
			  xfer += iprot->readBinary (this->cf);
			  this->__isset.cf = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->cq);
			  this->__isset.cq = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->cv);
			  this->__isset.cv = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 4:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->ts);
			  this->__isset.ts = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 5:
		      if (ftype == ::apache::thrift::protocol::T_BOOL)
			{
			  xfer += iprot->readBool (this->hasTimestamp);
			  this->__isset.hasTimestamp = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 6:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->val);
			  this->__isset.val = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 7:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readBinary (this->iterators);
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
	    TCondition::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TCondition");

	      xfer += oprot->writeFieldBegin (
		  "cf", ::apache::thrift::protocol::T_STRING, 1);
	      xfer += oprot->writeBinary (this->cf);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "cq", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeBinary (this->cq);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "cv", ::apache::thrift::protocol::T_STRING, 3);
	      xfer += oprot->writeBinary (this->cv);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("ts",
					      ::apache::thrift::protocol::T_I64,
					      4);
	      xfer += oprot->writeI64 (this->ts);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "hasTimestamp", ::apache::thrift::protocol::T_BOOL, 5);
	      xfer += oprot->writeBool (this->hasTimestamp);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "val", ::apache::thrift::protocol::T_STRING, 6);
	      xfer += oprot->writeBinary (this->val);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "iterators", ::apache::thrift::protocol::T_STRING, 7);
	      xfer += oprot->writeBinary (this->iterators);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TCondition &a, TCondition &b)
	    {
	      using ::std::swap;
	      swap (a.cf, b.cf);
	      swap (a.cq, b.cq);
	      swap (a.cv, b.cv);
	      swap (a.ts, b.ts);
	      swap (a.hasTimestamp, b.hasTimestamp);
	      swap (a.val, b.val);
	      swap (a.iterators, b.iterators);
	      swap (a.__isset, b.__isset);
	    }

	    TCondition::TCondition (const TCondition& other92)
	    {
	      cf = other92.cf;
	      cq = other92.cq;
	      cv = other92.cv;
	      ts = other92.ts;
	      hasTimestamp = other92.hasTimestamp;
	      val = other92.val;
	      iterators = other92.iterators;
	      __isset = other92.__isset;
	    }
	    TCondition&
	    TCondition::operator= (const TCondition& other93)
	    {
	      cf = other93.cf;
	      cq = other93.cq;
	      cv = other93.cv;
	      ts = other93.ts;
	      hasTimestamp = other93.hasTimestamp;
	      val = other93.val;
	      iterators = other93.iterators;
	      __isset = other93.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TCondition& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TCondition(";
	      out << "cf=" << to_string (obj.cf);
	      out << ", " << "cq=" << to_string (obj.cq);
	      out << ", " << "cv=" << to_string (obj.cv);
	      out << ", " << "ts=" << to_string (obj.ts);
	      out << ", " << "hasTimestamp=" << to_string (obj.hasTimestamp);
	      out << ", " << "val=" << to_string (obj.val);
	      out << ", " << "iterators=" << to_string (obj.iterators);
	      out << ")";
	      return out;
	    }

	    TConditionalMutation::~TConditionalMutation () throw ()
	    {
	    }

	    void
	    TConditionalMutation::__set_conditions (
		const std::vector<TCondition> & val)
	    {
	      this->conditions = val;
	    }

	    void
	    TConditionalMutation::__set_mutation (const TMutation& val)
	    {
	      this->mutation = val;
	    }

	    void
	    TConditionalMutation::__set_id (const int64_t val)
	    {
	      this->id = val;
	    }

	    const char* TConditionalMutation::ascii_fingerprint =
		"ECCD956F0F2184F4DDCCA904328BB05C";
	    const uint8_t TConditionalMutation::binary_fingerprint[16] =
	      { 0xEC, 0xCD, 0x95, 0x6F, 0x0F, 0x21, 0x84, 0xF4, 0xDD, 0xCC,
		  0xA9, 0x04, 0x32, 0x8B, 0xB0, 0x5C };

	    uint32_t
	    TConditionalMutation::read (
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
			      this->conditions.clear ();
			      uint32_t _size94;
			      ::apache::thrift::protocol::TType _etype97;
			      xfer += iprot->readListBegin (_etype97, _size94);
			      this->conditions.resize (_size94);
			      uint32_t _i98;
			      for (_i98 = 0; _i98 < _size94; ++_i98)
				{
				  xfer += this->conditions[_i98].read (iprot);
				}
			      xfer += iprot->readListEnd ();
			    }
			  this->__isset.conditions = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
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
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->id);
			  this->__isset.id = true;
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
	    TConditionalMutation::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TConditionalMutation");

	      xfer += oprot->writeFieldBegin (
		  "conditions", ::apache::thrift::protocol::T_LIST, 1);
		{
		  xfer += oprot->writeListBegin (
		      ::apache::thrift::protocol::T_STRUCT,
		      static_cast<uint32_t> (this->conditions.size ()));
		  std::vector<TCondition>::const_iterator _iter99;
		  for (_iter99 = this->conditions.begin ();
		      _iter99 != this->conditions.end (); ++_iter99)
		    {
		      xfer += (*_iter99).write (oprot);
		    }
		  xfer += oprot->writeListEnd ();
		}
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "mutation", ::apache::thrift::protocol::T_STRUCT, 2);
	      xfer += this->mutation.write (oprot);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("id",
					      ::apache::thrift::protocol::T_I64,
					      3);
	      xfer += oprot->writeI64 (this->id);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TConditionalMutation &a, TConditionalMutation &b)
	    {
	      using ::std::swap;
	      swap (a.conditions, b.conditions);
	      swap (a.mutation, b.mutation);
	      swap (a.id, b.id);
	      swap (a.__isset, b.__isset);
	    }

	    TConditionalMutation::TConditionalMutation (
		const TConditionalMutation& other100)
	    {
	      conditions = other100.conditions;
	      mutation = other100.mutation;
	      id = other100.id;
	      __isset = other100.__isset;
	    }
	    TConditionalMutation&
	    TConditionalMutation::operator= (
		const TConditionalMutation& other101)
	    {
	      conditions = other101.conditions;
	      mutation = other101.mutation;
	      id = other101.id;
	      __isset = other101.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TConditionalMutation& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TConditionalMutation(";
	      out << "conditions=" << to_string (obj.conditions);
	      out << ", " << "mutation=" << to_string (obj.mutation);
	      out << ", " << "id=" << to_string (obj.id);
	      out << ")";
	      return out;
	    }

	    TConditionalSession::~TConditionalSession () throw ()
	    {
	    }

	    void
	    TConditionalSession::__set_sessionId (const int64_t val)
	    {
	      this->sessionId = val;
	    }

	    void
	    TConditionalSession::__set_tserverLock (const std::string& val)
	    {
	      this->tserverLock = val;
	    }

	    void
	    TConditionalSession::__set_ttl (const int64_t val)
	    {
	      this->ttl = val;
	    }

	    const char* TConditionalSession::ascii_fingerprint =
		"FEBAC9C9DD701ABE5222D0CA33FDA432";
	    const uint8_t TConditionalSession::binary_fingerprint[16] =
	      { 0xFE, 0xBA, 0xC9, 0xC9, 0xDD, 0x70, 0x1A, 0xBE, 0x52, 0x22,
		  0xD0, 0xCA, 0x33, 0xFD, 0xA4, 0x32 };

	    uint32_t
	    TConditionalSession::read (
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
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->sessionId);
			  this->__isset.sessionId = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 2:
		      if (ftype == ::apache::thrift::protocol::T_STRING)
			{
			  xfer += iprot->readString (this->tserverLock);
			  this->__isset.tserverLock = true;
			}
		      else
			{
			  xfer += iprot->skip (ftype);
			}
		      break;
		    case 3:
		      if (ftype == ::apache::thrift::protocol::T_I64)
			{
			  xfer += iprot->readI64 (this->ttl);
			  this->__isset.ttl = true;
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
	    TConditionalSession::write (
		::apache::thrift::protocol::TProtocol* oprot) const
	    {
	      uint32_t xfer = 0;
	      oprot->incrementRecursionDepth ();
	      xfer += oprot->writeStructBegin ("TConditionalSession");

	      xfer += oprot->writeFieldBegin ("sessionId",
					      ::apache::thrift::protocol::T_I64,
					      1);
	      xfer += oprot->writeI64 (this->sessionId);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin (
		  "tserverLock", ::apache::thrift::protocol::T_STRING, 2);
	      xfer += oprot->writeString (this->tserverLock);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldBegin ("ttl",
					      ::apache::thrift::protocol::T_I64,
					      3);
	      xfer += oprot->writeI64 (this->ttl);
	      xfer += oprot->writeFieldEnd ();

	      xfer += oprot->writeFieldStop ();
	      xfer += oprot->writeStructEnd ();
	      oprot->decrementRecursionDepth ();
	      return xfer;
	    }

	    void
	    swap (TConditionalSession &a, TConditionalSession &b)
	    {
	      using ::std::swap;
	      swap (a.sessionId, b.sessionId);
	      swap (a.tserverLock, b.tserverLock);
	      swap (a.ttl, b.ttl);
	      swap (a.__isset, b.__isset);
	    }

	    TConditionalSession::TConditionalSession (
		const TConditionalSession& other102)
	    {
	      sessionId = other102.sessionId;
	      tserverLock = other102.tserverLock;
	      ttl = other102.ttl;
	      __isset = other102.__isset;
	    }
	    TConditionalSession&
	    TConditionalSession::operator= (const TConditionalSession& other103)
	    {
	      sessionId = other103.sessionId;
	      tserverLock = other103.tserverLock;
	      ttl = other103.ttl;
	      __isset = other103.__isset;
	      return *this;
	    }
	    std::ostream&
	    operator<< (std::ostream& out, const TConditionalSession& obj)
	    {
	      using ::apache::thrift::to_string;
	      out << "TConditionalSession(";
	      out << "sessionId=" << to_string (obj.sessionId);
	      out << ", " << "tserverLock=" << to_string (obj.tserverLock);
	      out << ", " << "ttl=" << to_string (obj.ttl);
	      out << ")";
	      return out;
	    }

	  }
	}
      }
    }
  }
} // namespace
