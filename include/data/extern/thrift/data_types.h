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
#ifndef data_TYPES_H
#define data_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "security_types.h"
#include "client_types.h"


namespace org { namespace apache { namespace accumulo { namespace core { namespace data { namespace thrift {

struct TCMStatus {
  enum type {
    ACCEPTED = 0,
    REJECTED = 1,
    VIOLATED = 2,
    IGNORED = 3
  };
};

extern const std::map<int, const char*> _TCMStatus_VALUES_TO_NAMES;

typedef int64_t ScanID;

typedef int64_t UpdateID;

typedef std::map<class TKeyExtent, std::vector<class TRange> >  ScanBatch;

typedef std::map<class TKeyExtent, std::vector<class TConditionalMutation> >  CMBatch;

typedef std::map<class TKeyExtent, std::vector<class TMutation> >  UpdateBatch;

typedef std::map<class TKeyExtent, std::map<std::string, class MapFileInfo> >  TabletFiles;

class TKey;

class TColumn;

class TMutation;

class TKeyExtent;

class TKeyValue;

class ScanResult;

class TRange;

class MultiScanResult;

class InitialScan;

class InitialMultiScan;

class IterInfo;

class TConstraintViolationSummary;

class UpdateErrors;

class TCMResult;

class MapFileInfo;

class TCondition;

class TConditionalMutation;

class TConditionalSession;

typedef struct _TKey__isset {
  _TKey__isset() : row(false), colFamily(false), colQualifier(false), colVisibility(false), timestamp(false) {}
  bool row :1;
  bool colFamily :1;
  bool colQualifier :1;
  bool colVisibility :1;
  bool timestamp :1;
} _TKey__isset;

class TKey {
 public:

  static const char* ascii_fingerprint; // = "A25840E2198F27E10AEEE70C9265C644";
  static const uint8_t binary_fingerprint[16]; // = {0xA2,0x58,0x40,0xE2,0x19,0x8F,0x27,0xE1,0x0A,0xEE,0xE7,0x0C,0x92,0x65,0xC6,0x44};

  TKey(const TKey&);
  TKey& operator=(const TKey&);
  TKey() : row(), colFamily(), colQualifier(), colVisibility(), timestamp(0) {
  }

  virtual ~TKey() throw();
  std::string row;
  std::string colFamily;
  std::string colQualifier;
  std::string colVisibility;
  int64_t timestamp;

  _TKey__isset __isset;

  void __set_row(const std::string& val);

  void __set_colFamily(const std::string& val);

  void __set_colQualifier(const std::string& val);

  void __set_colVisibility(const std::string& val);

  void __set_timestamp(const int64_t val);

  bool operator == (const TKey & rhs) const
  {
    if (!(row == rhs.row))
      return false;
    if (!(colFamily == rhs.colFamily))
      return false;
    if (!(colQualifier == rhs.colQualifier))
      return false;
    if (!(colVisibility == rhs.colVisibility))
      return false;
    if (!(timestamp == rhs.timestamp))
      return false;
    return true;
  }
  bool operator != (const TKey &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TKey & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TKey& obj);
};

void swap(TKey &a, TKey &b);

typedef struct _TColumn__isset {
  _TColumn__isset() : columnFamily(false), columnQualifier(false), columnVisibility(false) {}
  bool columnFamily :1;
  bool columnQualifier :1;
  bool columnVisibility :1;
} _TColumn__isset;

class TColumn {
 public:

  static const char* ascii_fingerprint; // = "AB879940BD15B6B25691265F7384B271";
  static const uint8_t binary_fingerprint[16]; // = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

  TColumn(const TColumn&);
  TColumn& operator=(const TColumn&);
  TColumn() : columnFamily(), columnQualifier(), columnVisibility() {
  }

  virtual ~TColumn() throw();
  std::string columnFamily;
  std::string columnQualifier;
  std::string columnVisibility;

  _TColumn__isset __isset;

  void __set_columnFamily(const std::string& val);

  void __set_columnQualifier(const std::string& val);

  void __set_columnVisibility(const std::string& val);

  bool operator == (const TColumn & rhs) const
  {
    if (!(columnFamily == rhs.columnFamily))
      return false;
    if (!(columnQualifier == rhs.columnQualifier))
      return false;
    if (!(columnVisibility == rhs.columnVisibility))
      return false;
    return true;
  }
  bool operator != (const TColumn &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TColumn & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TColumn& obj);
};

void swap(TColumn &a, TColumn &b);

typedef struct _TMutation__isset {
  _TMutation__isset() : row(false), data(false), values(false), entries(false) {}
  bool row :1;
  bool data :1;
  bool values :1;
  bool entries :1;
} _TMutation__isset;

class TMutation {
 public:

  static const char* ascii_fingerprint; // = "FD79BD16256E16CC9822166FFB701F19";
  static const uint8_t binary_fingerprint[16]; // = {0xFD,0x79,0xBD,0x16,0x25,0x6E,0x16,0xCC,0x98,0x22,0x16,0x6F,0xFB,0x70,0x1F,0x19};

  TMutation(const TMutation&);
  TMutation& operator=(const TMutation&);
  TMutation() : row(), data(), entries(0) {
  }

  virtual ~TMutation() throw();
  std::string row;
  std::string data;
  std::vector<std::string>  values;
  int32_t entries;

  _TMutation__isset __isset;

  void __set_row(const std::string& val);

  void __set_data(const std::string& val);

  void __set_values(const std::vector<std::string> & val);

  void __set_entries(const int32_t val);

  bool operator == (const TMutation & rhs) const
  {
    if (!(row == rhs.row))
      return false;
    if (!(data == rhs.data))
      return false;
    if (!(values == rhs.values))
      return false;
    if (!(entries == rhs.entries))
      return false;
    return true;
  }
  bool operator != (const TMutation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TMutation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TMutation& obj);
};

void swap(TMutation &a, TMutation &b);

typedef struct _TKeyExtent__isset {
  _TKeyExtent__isset() : table(false), endRow(false), prevEndRow(false) {}
  bool table :1;
  bool endRow :1;
  bool prevEndRow :1;
} _TKeyExtent__isset;

class TKeyExtent {
 public:

  static const char* ascii_fingerprint; // = "AB879940BD15B6B25691265F7384B271";
  static const uint8_t binary_fingerprint[16]; // = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

  TKeyExtent(const TKeyExtent&);
  TKeyExtent& operator=(const TKeyExtent&);
  TKeyExtent() : table(), endRow(), prevEndRow() {
  }

  virtual ~TKeyExtent() throw();
  std::string table;
  std::string endRow;
  std::string prevEndRow;

  _TKeyExtent__isset __isset;

  void __set_table(const std::string& val);

  void __set_endRow(const std::string& val);

  void __set_prevEndRow(const std::string& val);

  bool operator == (const TKeyExtent & rhs) const
  {
    if (!(table == rhs.table))
      return false;
    if (!(endRow == rhs.endRow))
      return false;
    if (!(prevEndRow == rhs.prevEndRow))
      return false;
    return true;
  }
  bool operator != (const TKeyExtent &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TKeyExtent &rhs ) const
  {
	  if (table.compare(rhs.table) < 0)
		  return true;

	  if (endRow.compare(rhs.endRow) < 0)
	  		  return true;

	  if (prevEndRow.compare(rhs.prevEndRow) < 0)
	  	  		  return true;
	  return false;
  }

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TKeyExtent& obj);
};

void swap(TKeyExtent &a, TKeyExtent &b);

typedef struct _TKeyValue__isset {
  _TKeyValue__isset() : key(false), value(false) {}
  bool key :1;
  bool value :1;
} _TKeyValue__isset;

class TKeyValue {
 public:

  static const char* ascii_fingerprint; // = "8DCBA6F4B336C8854964F08FBF391943";
  static const uint8_t binary_fingerprint[16]; // = {0x8D,0xCB,0xA6,0xF4,0xB3,0x36,0xC8,0x85,0x49,0x64,0xF0,0x8F,0xBF,0x39,0x19,0x43};

  TKeyValue(const TKeyValue&);
  TKeyValue& operator=(const TKeyValue&);
  TKeyValue() : value() {
  }

  virtual ~TKeyValue() throw();
  TKey key;
  std::string value;

  _TKeyValue__isset __isset;

  void __set_key(const TKey& val);

  void __set_value(const std::string& val);

  bool operator == (const TKeyValue & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const TKeyValue &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TKeyValue & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TKeyValue& obj);
};

void swap(TKeyValue &a, TKeyValue &b);

typedef struct _ScanResult__isset {
  _ScanResult__isset() : results(false), more(false) {}
  bool results :1;
  bool more :1;
} _ScanResult__isset;

class ScanResult {
 public:

  static const char* ascii_fingerprint; // = "6F1B73B7E271D491518DF10CFB0E8087";
  static const uint8_t binary_fingerprint[16]; // = {0x6F,0x1B,0x73,0xB7,0xE2,0x71,0xD4,0x91,0x51,0x8D,0xF1,0x0C,0xFB,0x0E,0x80,0x87};

  ScanResult(const ScanResult&);
  ScanResult& operator=(const ScanResult&);
  ScanResult() : more(0) {
  }

  virtual ~ScanResult() throw();
  std::vector<TKeyValue>  results;
  bool more;

  _ScanResult__isset __isset;

  void __set_results(const std::vector<TKeyValue> & val);

  void __set_more(const bool val);

  bool operator == (const ScanResult & rhs) const
  {
    if (!(results == rhs.results))
      return false;
    if (!(more == rhs.more))
      return false;
    return true;
  }
  bool operator != (const ScanResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ScanResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ScanResult& obj);
};

void swap(ScanResult &a, ScanResult &b);

typedef struct _TRange__isset {
  _TRange__isset() : start(false), stop(false), startKeyInclusive(false), stopKeyInclusive(false), infiniteStartKey(false), infiniteStopKey(false) {}
  bool start :1;
  bool stop :1;
  bool startKeyInclusive :1;
  bool stopKeyInclusive :1;
  bool infiniteStartKey :1;
  bool infiniteStopKey :1;
} _TRange__isset;

class TRange {
 public:

  static const char* ascii_fingerprint; // = "51C5BDA7AC16F12A08D7C8B6BB52C360";
  static const uint8_t binary_fingerprint[16]; // = {0x51,0xC5,0xBD,0xA7,0xAC,0x16,0xF1,0x2A,0x08,0xD7,0xC8,0xB6,0xBB,0x52,0xC3,0x60};

  TRange(const TRange&);
  TRange& operator=(const TRange&);
  TRange() : startKeyInclusive(0), stopKeyInclusive(0), infiniteStartKey(0), infiniteStopKey(0) {
  }

  virtual ~TRange() throw();
  TKey start;
  TKey stop;
  bool startKeyInclusive;
  bool stopKeyInclusive;
  bool infiniteStartKey;
  bool infiniteStopKey;

  _TRange__isset __isset;

  void __set_start(const TKey& val);

  void __set_stop(const TKey& val);

  void __set_startKeyInclusive(const bool val);

  void __set_stopKeyInclusive(const bool val);

  void __set_infiniteStartKey(const bool val);

  void __set_infiniteStopKey(const bool val);

  bool operator == (const TRange & rhs) const
  {
    if (!(start == rhs.start))
      return false;
    if (!(stop == rhs.stop))
      return false;
    if (!(startKeyInclusive == rhs.startKeyInclusive))
      return false;
    if (!(stopKeyInclusive == rhs.stopKeyInclusive))
      return false;
    if (!(infiniteStartKey == rhs.infiniteStartKey))
      return false;
    if (!(infiniteStopKey == rhs.infiniteStopKey))
      return false;
    return true;
  }
  bool operator != (const TRange &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TRange & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TRange& obj);
};

void swap(TRange &a, TRange &b);

typedef struct _MultiScanResult__isset {
  _MultiScanResult__isset() : results(false), failures(false), fullScans(false), partScan(false), partNextKey(false), partNextKeyInclusive(false), more(false) {}
  bool results :1;
  bool failures :1;
  bool fullScans :1;
  bool partScan :1;
  bool partNextKey :1;
  bool partNextKeyInclusive :1;
  bool more :1;
} _MultiScanResult__isset;

class MultiScanResult {
 public:

  static const char* ascii_fingerprint; // = "1710A2EAC368D6E92A3F98939AD49DAF";
  static const uint8_t binary_fingerprint[16]; // = {0x17,0x10,0xA2,0xEA,0xC3,0x68,0xD6,0xE9,0x2A,0x3F,0x98,0x93,0x9A,0xD4,0x9D,0xAF};

  MultiScanResult(const MultiScanResult&);
  MultiScanResult& operator=(const MultiScanResult&);
  MultiScanResult() : partNextKeyInclusive(0), more(0) {
  }

  virtual ~MultiScanResult() throw();
  std::vector<TKeyValue>  results;
  ScanBatch failures;
  std::vector<TKeyExtent>  fullScans;
  TKeyExtent partScan;
  TKey partNextKey;
  bool partNextKeyInclusive;
  bool more;

  _MultiScanResult__isset __isset;

  void __set_results(const std::vector<TKeyValue> & val);

  void __set_failures(const ScanBatch& val);

  void __set_fullScans(const std::vector<TKeyExtent> & val);

  void __set_partScan(const TKeyExtent& val);

  void __set_partNextKey(const TKey& val);

  void __set_partNextKeyInclusive(const bool val);

  void __set_more(const bool val);

  bool operator == (const MultiScanResult & rhs) const
  {
    if (!(results == rhs.results))
      return false;
    if (!(failures == rhs.failures))
      return false;
    if (!(fullScans == rhs.fullScans))
      return false;
    if (!(partScan == rhs.partScan))
      return false;
    if (!(partNextKey == rhs.partNextKey))
      return false;
    if (!(partNextKeyInclusive == rhs.partNextKeyInclusive))
      return false;
    if (!(more == rhs.more))
      return false;
    return true;
  }
  bool operator != (const MultiScanResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MultiScanResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MultiScanResult& obj);
};

void swap(MultiScanResult &a, MultiScanResult &b);

typedef struct _InitialScan__isset {
  _InitialScan__isset() : scanID(false), result(false) {}
  bool scanID :1;
  bool result :1;
} _InitialScan__isset;

class InitialScan {
 public:

  static const char* ascii_fingerprint; // = "18AE44780236DD1CAB1037C71440C057";
  static const uint8_t binary_fingerprint[16]; // = {0x18,0xAE,0x44,0x78,0x02,0x36,0xDD,0x1C,0xAB,0x10,0x37,0xC7,0x14,0x40,0xC0,0x57};

  InitialScan(const InitialScan&);
  InitialScan& operator=(const InitialScan&);
  InitialScan() : scanID(0) {
  }

  virtual ~InitialScan() throw();
  ScanID scanID;
  ScanResult result;

  _InitialScan__isset __isset;

  void __set_scanID(const ScanID val);

  void __set_result(const ScanResult& val);

  bool operator == (const InitialScan & rhs) const
  {
    if (!(scanID == rhs.scanID))
      return false;
    if (!(result == rhs.result))
      return false;
    return true;
  }
  bool operator != (const InitialScan &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InitialScan & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const InitialScan& obj);
};

void swap(InitialScan &a, InitialScan &b);

typedef struct _InitialMultiScan__isset {
  _InitialMultiScan__isset() : scanID(false), result(false) {}
  bool scanID :1;
  bool result :1;
} _InitialMultiScan__isset;

class InitialMultiScan {
 public:

  static const char* ascii_fingerprint; // = "3D143740F405DA8C33D95336FD4CFC33";
  static const uint8_t binary_fingerprint[16]; // = {0x3D,0x14,0x37,0x40,0xF4,0x05,0xDA,0x8C,0x33,0xD9,0x53,0x36,0xFD,0x4C,0xFC,0x33};

  InitialMultiScan(const InitialMultiScan&);
  InitialMultiScan& operator=(const InitialMultiScan&);
  InitialMultiScan() : scanID(0) {
  }

  virtual ~InitialMultiScan() throw();
  ScanID scanID;
  MultiScanResult result;

  _InitialMultiScan__isset __isset;

  void __set_scanID(const ScanID val);

  void __set_result(const MultiScanResult& val);

  bool operator == (const InitialMultiScan & rhs) const
  {
    if (!(scanID == rhs.scanID))
      return false;
    if (!(result == rhs.result))
      return false;
    return true;
  }
  bool operator != (const InitialMultiScan &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InitialMultiScan & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const InitialMultiScan& obj);
};

void swap(InitialMultiScan &a, InitialMultiScan &b);

typedef struct _IterInfo__isset {
  _IterInfo__isset() : priority(false), className(false), iterName(false) {}
  bool priority :1;
  bool className :1;
  bool iterName :1;
} _IterInfo__isset;

class IterInfo {
 public:

  static const char* ascii_fingerprint; // = "3368C2F81F2FEF71F11EDACDB2A3ECEF";
  static const uint8_t binary_fingerprint[16]; // = {0x33,0x68,0xC2,0xF8,0x1F,0x2F,0xEF,0x71,0xF1,0x1E,0xDA,0xCD,0xB2,0xA3,0xEC,0xEF};

  IterInfo(const IterInfo&);
  IterInfo& operator=(const IterInfo&);
  IterInfo() : priority(0), className(), iterName() {
  }

  virtual ~IterInfo() throw();
  int32_t priority;
  std::string className;
  std::string iterName;

  _IterInfo__isset __isset;

  void __set_priority(const int32_t val);

  void __set_className(const std::string& val);

  void __set_iterName(const std::string& val);

  bool operator == (const IterInfo & rhs) const
  {
    if (!(priority == rhs.priority))
      return false;
    if (!(className == rhs.className))
      return false;
    if (!(iterName == rhs.iterName))
      return false;
    return true;
  }
  bool operator != (const IterInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IterInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IterInfo& obj);
};

void swap(IterInfo &a, IterInfo &b);

typedef struct _TConstraintViolationSummary__isset {
  _TConstraintViolationSummary__isset() : constrainClass(false), violationCode(false), violationDescription(false), numberOfViolatingMutations(false) {}
  bool constrainClass :1;
  bool violationCode :1;
  bool violationDescription :1;
  bool numberOfViolatingMutations :1;
} _TConstraintViolationSummary__isset;

class TConstraintViolationSummary {
 public:

  static const char* ascii_fingerprint; // = "67DCD7E9C756B859BA6A7E138EFB1053";
  static const uint8_t binary_fingerprint[16]; // = {0x67,0xDC,0xD7,0xE9,0xC7,0x56,0xB8,0x59,0xBA,0x6A,0x7E,0x13,0x8E,0xFB,0x10,0x53};

  TConstraintViolationSummary(const TConstraintViolationSummary&);
  TConstraintViolationSummary& operator=(const TConstraintViolationSummary&);
  TConstraintViolationSummary() : constrainClass(), violationCode(0), violationDescription(), numberOfViolatingMutations(0) {
  }

  virtual ~TConstraintViolationSummary() throw();
  std::string constrainClass;
  int16_t violationCode;
  std::string violationDescription;
  int64_t numberOfViolatingMutations;

  _TConstraintViolationSummary__isset __isset;

  void __set_constrainClass(const std::string& val);

  void __set_violationCode(const int16_t val);

  void __set_violationDescription(const std::string& val);

  void __set_numberOfViolatingMutations(const int64_t val);

  bool operator == (const TConstraintViolationSummary & rhs) const
  {
    if (!(constrainClass == rhs.constrainClass))
      return false;
    if (!(violationCode == rhs.violationCode))
      return false;
    if (!(violationDescription == rhs.violationDescription))
      return false;
    if (!(numberOfViolatingMutations == rhs.numberOfViolatingMutations))
      return false;
    return true;
  }
  bool operator != (const TConstraintViolationSummary &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TConstraintViolationSummary & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TConstraintViolationSummary& obj);
};

void swap(TConstraintViolationSummary &a, TConstraintViolationSummary &b);

typedef struct _UpdateErrors__isset {
  _UpdateErrors__isset() : failedExtents(false), violationSummaries(false), authorizationFailures(false) {}
  bool failedExtents :1;
  bool violationSummaries :1;
  bool authorizationFailures :1;
} _UpdateErrors__isset;

class UpdateErrors {
 public:

  static const char* ascii_fingerprint; // = "795EFE92A2DF5316A5DED38CBC5BFB32";
  static const uint8_t binary_fingerprint[16]; // = {0x79,0x5E,0xFE,0x92,0xA2,0xDF,0x53,0x16,0xA5,0xDE,0xD3,0x8C,0xBC,0x5B,0xFB,0x32};

  UpdateErrors(const UpdateErrors&);
  UpdateErrors& operator=(const UpdateErrors&);
  UpdateErrors() {
  }

  virtual ~UpdateErrors() throw();
  std::map<TKeyExtent, int64_t>  failedExtents;
  std::vector<TConstraintViolationSummary>  violationSummaries;
  std::map<TKeyExtent,  ::org::apache::accumulo::core::client::impl::thrift::SecurityErrorCode::type>  authorizationFailures;

  _UpdateErrors__isset __isset;

  void __set_failedExtents(const std::map<TKeyExtent, int64_t> & val);

  void __set_violationSummaries(const std::vector<TConstraintViolationSummary> & val);

  void __set_authorizationFailures(const std::map<TKeyExtent,  ::org::apache::accumulo::core::client::impl::thrift::SecurityErrorCode::type> & val);

  bool operator == (const UpdateErrors & rhs) const
  {
    if (!(failedExtents == rhs.failedExtents))
      return false;
    if (!(violationSummaries == rhs.violationSummaries))
      return false;
    if (!(authorizationFailures == rhs.authorizationFailures))
      return false;
    return true;
  }
  bool operator != (const UpdateErrors &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UpdateErrors & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const UpdateErrors& obj);
};

void swap(UpdateErrors &a, UpdateErrors &b);

typedef struct _TCMResult__isset {
  _TCMResult__isset() : cmid(false), status(false) {}
  bool cmid :1;
  bool status :1;
} _TCMResult__isset;

class TCMResult {
 public:

  static const char* ascii_fingerprint; // = "DFA40D9D2884599F3D1E7A57578F1384";
  static const uint8_t binary_fingerprint[16]; // = {0xDF,0xA4,0x0D,0x9D,0x28,0x84,0x59,0x9F,0x3D,0x1E,0x7A,0x57,0x57,0x8F,0x13,0x84};

  TCMResult(const TCMResult&);
  TCMResult& operator=(const TCMResult&);
  TCMResult() : cmid(0), status((TCMStatus::type)0) {
  }

  virtual ~TCMResult() throw();
  int64_t cmid;
  TCMStatus::type status;

  _TCMResult__isset __isset;

  void __set_cmid(const int64_t val);

  void __set_status(const TCMStatus::type val);

  bool operator == (const TCMResult & rhs) const
  {
    if (!(cmid == rhs.cmid))
      return false;
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const TCMResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TCMResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TCMResult& obj);
};

void swap(TCMResult &a, TCMResult &b);

typedef struct _MapFileInfo__isset {
  _MapFileInfo__isset() : estimatedSize(false) {}
  bool estimatedSize :1;
} _MapFileInfo__isset;

class MapFileInfo {
 public:

  static const char* ascii_fingerprint; // = "56A59CE7FFAF82BCA8A19FAACDE4FB75";
  static const uint8_t binary_fingerprint[16]; // = {0x56,0xA5,0x9C,0xE7,0xFF,0xAF,0x82,0xBC,0xA8,0xA1,0x9F,0xAA,0xCD,0xE4,0xFB,0x75};

  MapFileInfo(const MapFileInfo&);
  MapFileInfo& operator=(const MapFileInfo&);
  MapFileInfo() : estimatedSize(0) {
  }

  virtual ~MapFileInfo() throw();
  int64_t estimatedSize;

  _MapFileInfo__isset __isset;

  void __set_estimatedSize(const int64_t val);

  bool operator == (const MapFileInfo & rhs) const
  {
    if (!(estimatedSize == rhs.estimatedSize))
      return false;
    return true;
  }
  bool operator != (const MapFileInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MapFileInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MapFileInfo& obj);
};

void swap(MapFileInfo &a, MapFileInfo &b);

typedef struct _TCondition__isset {
  _TCondition__isset() : cf(false), cq(false), cv(false), ts(false), hasTimestamp(false), val(false), iterators(false) {}
  bool cf :1;
  bool cq :1;
  bool cv :1;
  bool ts :1;
  bool hasTimestamp :1;
  bool val :1;
  bool iterators :1;
} _TCondition__isset;

class TCondition {
 public:

  static const char* ascii_fingerprint; // = "7C10ECB52A73C8207C0290A240145B89";
  static const uint8_t binary_fingerprint[16]; // = {0x7C,0x10,0xEC,0xB5,0x2A,0x73,0xC8,0x20,0x7C,0x02,0x90,0xA2,0x40,0x14,0x5B,0x89};

  TCondition(const TCondition&);
  TCondition& operator=(const TCondition&);
  TCondition() : cf(), cq(), cv(), ts(0), hasTimestamp(0), val(), iterators() {
  }

  virtual ~TCondition() throw();
  std::string cf;
  std::string cq;
  std::string cv;
  int64_t ts;
  bool hasTimestamp;
  std::string val;
  std::string iterators;

  _TCondition__isset __isset;

  void __set_cf(const std::string& val);

  void __set_cq(const std::string& val);

  void __set_cv(const std::string& val);

  void __set_ts(const int64_t val);

  void __set_hasTimestamp(const bool val);

  void __set_val(const std::string& val);

  void __set_iterators(const std::string& val);

  bool operator == (const TCondition & rhs) const
  {
    if (!(cf == rhs.cf))
      return false;
    if (!(cq == rhs.cq))
      return false;
    if (!(cv == rhs.cv))
      return false;
    if (!(ts == rhs.ts))
      return false;
    if (!(hasTimestamp == rhs.hasTimestamp))
      return false;
    if (!(val == rhs.val))
      return false;
    if (!(iterators == rhs.iterators))
      return false;
    return true;
  }
  bool operator != (const TCondition &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TCondition & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TCondition& obj);
};

void swap(TCondition &a, TCondition &b);

typedef struct _TConditionalMutation__isset {
  _TConditionalMutation__isset() : conditions(false), mutation(false), id(false) {}
  bool conditions :1;
  bool mutation :1;
  bool id :1;
} _TConditionalMutation__isset;

class TConditionalMutation {
 public:

  static const char* ascii_fingerprint; // = "ECCD956F0F2184F4DDCCA904328BB05C";
  static const uint8_t binary_fingerprint[16]; // = {0xEC,0xCD,0x95,0x6F,0x0F,0x21,0x84,0xF4,0xDD,0xCC,0xA9,0x04,0x32,0x8B,0xB0,0x5C};

  TConditionalMutation(const TConditionalMutation&);
  TConditionalMutation& operator=(const TConditionalMutation&);
  TConditionalMutation() : id(0) {
  }

  virtual ~TConditionalMutation() throw();
  std::vector<TCondition>  conditions;
  TMutation mutation;
  int64_t id;

  _TConditionalMutation__isset __isset;

  void __set_conditions(const std::vector<TCondition> & val);

  void __set_mutation(const TMutation& val);

  void __set_id(const int64_t val);

  bool operator == (const TConditionalMutation & rhs) const
  {
    if (!(conditions == rhs.conditions))
      return false;
    if (!(mutation == rhs.mutation))
      return false;
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const TConditionalMutation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TConditionalMutation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TConditionalMutation& obj);
};

void swap(TConditionalMutation &a, TConditionalMutation &b);

typedef struct _TConditionalSession__isset {
  _TConditionalSession__isset() : sessionId(false), tserverLock(false), ttl(false) {}
  bool sessionId :1;
  bool tserverLock :1;
  bool ttl :1;
} _TConditionalSession__isset;

class TConditionalSession {
 public:

  static const char* ascii_fingerprint; // = "FEBAC9C9DD701ABE5222D0CA33FDA432";
  static const uint8_t binary_fingerprint[16]; // = {0xFE,0xBA,0xC9,0xC9,0xDD,0x70,0x1A,0xBE,0x52,0x22,0xD0,0xCA,0x33,0xFD,0xA4,0x32};

  TConditionalSession(const TConditionalSession&);
  TConditionalSession& operator=(const TConditionalSession&);
  TConditionalSession() : sessionId(0), tserverLock(), ttl(0) {
  }

  virtual ~TConditionalSession() throw();
  int64_t sessionId;
  std::string tserverLock;
  int64_t ttl;

  _TConditionalSession__isset __isset;

  void __set_sessionId(const int64_t val);

  void __set_tserverLock(const std::string& val);

  void __set_ttl(const int64_t val);

  bool operator == (const TConditionalSession & rhs) const
  {
    if (!(sessionId == rhs.sessionId))
      return false;
    if (!(tserverLock == rhs.tserverLock))
      return false;
    if (!(ttl == rhs.ttl))
      return false;
    return true;
  }
  bool operator != (const TConditionalSession &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TConditionalSession & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TConditionalSession& obj);
};

void swap(TConditionalSession &a, TConditionalSession &b);

}}}}}} // namespace

#endif
