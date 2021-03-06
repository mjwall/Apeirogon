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
#ifndef tabletserver_TYPES_H
#define tabletserver_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "data_types.h"
#include "security_types.h"
#include "client_types.h"
#include "master_types.h"
#include "trace_types.h"


namespace org { namespace apache { namespace accumulo { namespace core { namespace tabletserver { namespace thrift {

struct ScanType {
  enum type {
    SINGLE = 0,
    BATCH = 1
  };
};

extern const std::map<int, const char*> _ScanType_VALUES_TO_NAMES;

struct ScanState {
  enum type {
    IDLE = 0,
    RUNNING = 1,
    QUEUED = 2
  };
};

extern const std::map<int, const char*> _ScanState_VALUES_TO_NAMES;

struct CompactionType {
  enum type {
    MINOR = 0,
    MERGE = 1,
    MAJOR = 2,
    FULL = 3
  };
};

extern const std::map<int, const char*> _CompactionType_VALUES_TO_NAMES;

struct CompactionReason {
  enum type {
    USER = 0,
    SYSTEM = 1,
    CHOP = 2,
    IDLE = 3,
    CLOSE = 4
  };
};

extern const std::map<int, const char*> _CompactionReason_VALUES_TO_NAMES;

typedef int32_t TabletID;

class NotServingTabletException;

class TooManyFilesException;

class NoSuchScanIDException;

class ConstraintViolationException;

class ActionStats;

class TabletStats;

class ActiveScan;

class ActiveCompaction;

class TIteratorSetting;

class IteratorConfig;

typedef struct _NotServingTabletException__isset {
  _NotServingTabletException__isset() : extent(false) {}
  bool extent :1;
} _NotServingTabletException__isset;

class NotServingTabletException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "636807D016867BC3A79FD54005E0677E";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x68,0x07,0xD0,0x16,0x86,0x7B,0xC3,0xA7,0x9F,0xD5,0x40,0x05,0xE0,0x67,0x7E};

  NotServingTabletException(const NotServingTabletException&);
  NotServingTabletException& operator=(const NotServingTabletException&);
  NotServingTabletException() {
  }

  virtual ~NotServingTabletException() throw();
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;

  _NotServingTabletException__isset __isset;

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  bool operator == (const NotServingTabletException & rhs) const
  {
    if (!(extent == rhs.extent))
      return false;
    return true;
  }
  bool operator != (const NotServingTabletException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NotServingTabletException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const NotServingTabletException& obj);
};

void swap(NotServingTabletException &a, NotServingTabletException &b);

typedef struct _TooManyFilesException__isset {
  _TooManyFilesException__isset() : extent(false) {}
  bool extent :1;
} _TooManyFilesException__isset;

class TooManyFilesException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "636807D016867BC3A79FD54005E0677E";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x68,0x07,0xD0,0x16,0x86,0x7B,0xC3,0xA7,0x9F,0xD5,0x40,0x05,0xE0,0x67,0x7E};

  TooManyFilesException(const TooManyFilesException&);
  TooManyFilesException& operator=(const TooManyFilesException&);
  TooManyFilesException() {
  }

  virtual ~TooManyFilesException() throw();
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;

  _TooManyFilesException__isset __isset;

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  bool operator == (const TooManyFilesException & rhs) const
  {
    if (!(extent == rhs.extent))
      return false;
    return true;
  }
  bool operator != (const TooManyFilesException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TooManyFilesException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TooManyFilesException& obj);
};

void swap(TooManyFilesException &a, TooManyFilesException &b);


class NoSuchScanIDException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  NoSuchScanIDException(const NoSuchScanIDException&);
  NoSuchScanIDException& operator=(const NoSuchScanIDException&);
  NoSuchScanIDException() {
  }

  virtual ~NoSuchScanIDException() throw();

  bool operator == (const NoSuchScanIDException & /* rhs */) const
  {
    return true;
  }
  bool operator != (const NoSuchScanIDException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NoSuchScanIDException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const NoSuchScanIDException& obj);
};

void swap(NoSuchScanIDException &a, NoSuchScanIDException &b);

typedef struct _ConstraintViolationException__isset {
  _ConstraintViolationException__isset() : violationSummaries(false) {}
  bool violationSummaries :1;
} _ConstraintViolationException__isset;

class ConstraintViolationException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "3884B00559CED48471BE62CF7B94E4D1";
  static const uint8_t binary_fingerprint[16]; // = {0x38,0x84,0xB0,0x05,0x59,0xCE,0xD4,0x84,0x71,0xBE,0x62,0xCF,0x7B,0x94,0xE4,0xD1};

  ConstraintViolationException(const ConstraintViolationException&);
  ConstraintViolationException& operator=(const ConstraintViolationException&);
  ConstraintViolationException() {
  }

  virtual ~ConstraintViolationException() throw();
  std::vector< ::org::apache::accumulo::core::data::thrift::TConstraintViolationSummary>  violationSummaries;

  _ConstraintViolationException__isset __isset;

  void __set_violationSummaries(const std::vector< ::org::apache::accumulo::core::data::thrift::TConstraintViolationSummary> & val);

  bool operator == (const ConstraintViolationException & rhs) const
  {
    if (!(violationSummaries == rhs.violationSummaries))
      return false;
    return true;
  }
  bool operator != (const ConstraintViolationException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ConstraintViolationException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ConstraintViolationException& obj);
};

void swap(ConstraintViolationException &a, ConstraintViolationException &b);

typedef struct _ActionStats__isset {
  _ActionStats__isset() : status(false), elapsed(false), num(false), count(false), sumDev(false), fail(false), queueTime(false), queueSumDev(false) {}
  bool status :1;
  bool elapsed :1;
  bool num :1;
  bool count :1;
  bool sumDev :1;
  bool fail :1;
  bool queueTime :1;
  bool queueSumDev :1;
} _ActionStats__isset;

class ActionStats {
 public:

  static const char* ascii_fingerprint; // = "38F10F0BD2F539F3CA606E0480459450";
  static const uint8_t binary_fingerprint[16]; // = {0x38,0xF1,0x0F,0x0B,0xD2,0xF5,0x39,0xF3,0xCA,0x60,0x6E,0x04,0x80,0x45,0x94,0x50};

  ActionStats(const ActionStats&);
  ActionStats& operator=(const ActionStats&);
  ActionStats() : status(0), elapsed(0), num(0), count(0), sumDev(0), fail(0), queueTime(0), queueSumDev(0) {
  }

  virtual ~ActionStats() throw();
  int32_t status;
  double elapsed;
  int32_t num;
  int64_t count;
  double sumDev;
  int32_t fail;
  double queueTime;
  double queueSumDev;

  _ActionStats__isset __isset;

  void __set_status(const int32_t val);

  void __set_elapsed(const double val);

  void __set_num(const int32_t val);

  void __set_count(const int64_t val);

  void __set_sumDev(const double val);

  void __set_fail(const int32_t val);

  void __set_queueTime(const double val);

  void __set_queueSumDev(const double val);

  bool operator == (const ActionStats & rhs) const
  {
    if (!(status == rhs.status))
      return false;
    if (!(elapsed == rhs.elapsed))
      return false;
    if (!(num == rhs.num))
      return false;
    if (!(count == rhs.count))
      return false;
    if (!(sumDev == rhs.sumDev))
      return false;
    if (!(fail == rhs.fail))
      return false;
    if (!(queueTime == rhs.queueTime))
      return false;
    if (!(queueSumDev == rhs.queueSumDev))
      return false;
    return true;
  }
  bool operator != (const ActionStats &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ActionStats & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ActionStats& obj);
};

void swap(ActionStats &a, ActionStats &b);

typedef struct _TabletStats__isset {
  _TabletStats__isset() : extent(false), majors(false), minors(false), splits(false), numEntries(false), ingestRate(false), queryRate(false), splitCreationTime(false) {}
  bool extent :1;
  bool majors :1;
  bool minors :1;
  bool splits :1;
  bool numEntries :1;
  bool ingestRate :1;
  bool queryRate :1;
  bool splitCreationTime :1;
} _TabletStats__isset;

class TabletStats {
 public:

  static const char* ascii_fingerprint; // = "EDECD13D47255249DE8E10225F40F87E";
  static const uint8_t binary_fingerprint[16]; // = {0xED,0xEC,0xD1,0x3D,0x47,0x25,0x52,0x49,0xDE,0x8E,0x10,0x22,0x5F,0x40,0xF8,0x7E};

  TabletStats(const TabletStats&);
  TabletStats& operator=(const TabletStats&);
  TabletStats() : numEntries(0), ingestRate(0), queryRate(0), splitCreationTime(0) {
  }

  virtual ~TabletStats() throw();
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;
  ActionStats majors;
  ActionStats minors;
  ActionStats splits;
  int64_t numEntries;
  double ingestRate;
  double queryRate;
  int64_t splitCreationTime;

  _TabletStats__isset __isset;

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  void __set_majors(const ActionStats& val);

  void __set_minors(const ActionStats& val);

  void __set_splits(const ActionStats& val);

  void __set_numEntries(const int64_t val);

  void __set_ingestRate(const double val);

  void __set_queryRate(const double val);

  void __set_splitCreationTime(const int64_t val);

  bool operator == (const TabletStats & rhs) const
  {
    if (!(extent == rhs.extent))
      return false;
    if (!(majors == rhs.majors))
      return false;
    if (!(minors == rhs.minors))
      return false;
    if (!(splits == rhs.splits))
      return false;
    if (!(numEntries == rhs.numEntries))
      return false;
    if (!(ingestRate == rhs.ingestRate))
      return false;
    if (!(queryRate == rhs.queryRate))
      return false;
    if (!(splitCreationTime == rhs.splitCreationTime))
      return false;
    return true;
  }
  bool operator != (const TabletStats &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletStats & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletStats& obj);
};

void swap(TabletStats &a, TabletStats &b);

typedef struct _ActiveScan__isset {
  _ActiveScan__isset() : client(false), user(false), tableId(false), age(false), idleTime(false), type(false), state(false), extent(false), columns(false), ssiList(false), ssio(false), authorizations(false), scanId(false) {}
  bool client :1;
  bool user :1;
  bool tableId :1;
  bool age :1;
  bool idleTime :1;
  bool type :1;
  bool state :1;
  bool extent :1;
  bool columns :1;
  bool ssiList :1;
  bool ssio :1;
  bool authorizations :1;
  bool scanId :1;
} _ActiveScan__isset;

class ActiveScan {
 public:

  static const char* ascii_fingerprint; // = "B3549C14C0C72FCBA06F1947AA8A1F62";
  static const uint8_t binary_fingerprint[16]; // = {0xB3,0x54,0x9C,0x14,0xC0,0xC7,0x2F,0xCB,0xA0,0x6F,0x19,0x47,0xAA,0x8A,0x1F,0x62};

  ActiveScan(const ActiveScan&);
  ActiveScan& operator=(const ActiveScan&);
  ActiveScan() : client(), user(), tableId(), age(0), idleTime(0), type((ScanType::type)0), state((ScanState::type)0), scanId(0) {
  }

  virtual ~ActiveScan() throw();
  std::string client;
  std::string user;
  std::string tableId;
  int64_t age;
  int64_t idleTime;
  ScanType::type type;
  ScanState::type state;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;
  std::vector< ::org::apache::accumulo::core::data::thrift::TColumn>  columns;
  std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo>  ssiList;
  std::map<std::string, std::map<std::string, std::string> >  ssio;
  std::vector<std::string>  authorizations;
  int64_t scanId;

  _ActiveScan__isset __isset;

  void __set_client(const std::string& val);

  void __set_user(const std::string& val);

  void __set_tableId(const std::string& val);

  void __set_age(const int64_t val);

  void __set_idleTime(const int64_t val);

  void __set_type(const ScanType::type val);

  void __set_state(const ScanState::type val);

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  void __set_columns(const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & val);

  void __set_ssiList(const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & val);

  void __set_ssio(const std::map<std::string, std::map<std::string, std::string> > & val);

  void __set_authorizations(const std::vector<std::string> & val);

  void __set_scanId(const int64_t val);

  bool operator == (const ActiveScan & rhs) const
  {
    if (!(client == rhs.client))
      return false;
    if (!(user == rhs.user))
      return false;
    if (!(tableId == rhs.tableId))
      return false;
    if (!(age == rhs.age))
      return false;
    if (!(idleTime == rhs.idleTime))
      return false;
    if (!(type == rhs.type))
      return false;
    if (!(state == rhs.state))
      return false;
    if (!(extent == rhs.extent))
      return false;
    if (!(columns == rhs.columns))
      return false;
    if (!(ssiList == rhs.ssiList))
      return false;
    if (!(ssio == rhs.ssio))
      return false;
    if (!(authorizations == rhs.authorizations))
      return false;
    if (__isset.scanId != rhs.__isset.scanId)
      return false;
    else if (__isset.scanId && !(scanId == rhs.scanId))
      return false;
    return true;
  }
  bool operator != (const ActiveScan &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ActiveScan & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ActiveScan& obj);
};

void swap(ActiveScan &a, ActiveScan &b);

typedef struct _ActiveCompaction__isset {
  _ActiveCompaction__isset() : extent(false), age(false), inputFiles(false), outputFile(false), type(false), reason(false), localityGroup(false), entriesRead(false), entriesWritten(false), ssiList(false), ssio(false) {}
  bool extent :1;
  bool age :1;
  bool inputFiles :1;
  bool outputFile :1;
  bool type :1;
  bool reason :1;
  bool localityGroup :1;
  bool entriesRead :1;
  bool entriesWritten :1;
  bool ssiList :1;
  bool ssio :1;
} _ActiveCompaction__isset;

class ActiveCompaction {
 public:

  static const char* ascii_fingerprint; // = "F21BEB5FC0933DF8AFDE54B450E3AA88";
  static const uint8_t binary_fingerprint[16]; // = {0xF2,0x1B,0xEB,0x5F,0xC0,0x93,0x3D,0xF8,0xAF,0xDE,0x54,0xB4,0x50,0xE3,0xAA,0x88};

  ActiveCompaction(const ActiveCompaction&);
  ActiveCompaction& operator=(const ActiveCompaction&);
  ActiveCompaction() : age(0), outputFile(), type((CompactionType::type)0), reason((CompactionReason::type)0), localityGroup(), entriesRead(0), entriesWritten(0) {
  }

  virtual ~ActiveCompaction() throw();
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;
  int64_t age;
  std::vector<std::string>  inputFiles;
  std::string outputFile;
  CompactionType::type type;
  CompactionReason::type reason;
  std::string localityGroup;
  int64_t entriesRead;
  int64_t entriesWritten;
  std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo>  ssiList;
  std::map<std::string, std::map<std::string, std::string> >  ssio;

  _ActiveCompaction__isset __isset;

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  void __set_age(const int64_t val);

  void __set_inputFiles(const std::vector<std::string> & val);

  void __set_outputFile(const std::string& val);

  void __set_type(const CompactionType::type val);

  void __set_reason(const CompactionReason::type val);

  void __set_localityGroup(const std::string& val);

  void __set_entriesRead(const int64_t val);

  void __set_entriesWritten(const int64_t val);

  void __set_ssiList(const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & val);

  void __set_ssio(const std::map<std::string, std::map<std::string, std::string> > & val);

  bool operator == (const ActiveCompaction & rhs) const
  {
    if (!(extent == rhs.extent))
      return false;
    if (!(age == rhs.age))
      return false;
    if (!(inputFiles == rhs.inputFiles))
      return false;
    if (!(outputFile == rhs.outputFile))
      return false;
    if (!(type == rhs.type))
      return false;
    if (!(reason == rhs.reason))
      return false;
    if (!(localityGroup == rhs.localityGroup))
      return false;
    if (!(entriesRead == rhs.entriesRead))
      return false;
    if (!(entriesWritten == rhs.entriesWritten))
      return false;
    if (!(ssiList == rhs.ssiList))
      return false;
    if (!(ssio == rhs.ssio))
      return false;
    return true;
  }
  bool operator != (const ActiveCompaction &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ActiveCompaction & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ActiveCompaction& obj);
};

void swap(ActiveCompaction &a, ActiveCompaction &b);

typedef struct _TIteratorSetting__isset {
  _TIteratorSetting__isset() : priority(false), name(false), iteratorClass(false), properties(false) {}
  bool priority :1;
  bool name :1;
  bool iteratorClass :1;
  bool properties :1;
} _TIteratorSetting__isset;

class TIteratorSetting {
 public:

  static const char* ascii_fingerprint; // = "985C857916964E43205EAC92A157CB4E";
  static const uint8_t binary_fingerprint[16]; // = {0x98,0x5C,0x85,0x79,0x16,0x96,0x4E,0x43,0x20,0x5E,0xAC,0x92,0xA1,0x57,0xCB,0x4E};

  TIteratorSetting(const TIteratorSetting&);
  TIteratorSetting& operator=(const TIteratorSetting&);
  TIteratorSetting() : priority(0), name(), iteratorClass() {
  }

  virtual ~TIteratorSetting() throw();
  int32_t priority;
  std::string name;
  std::string iteratorClass;
  std::map<std::string, std::string>  properties;

  _TIteratorSetting__isset __isset;

  void __set_priority(const int32_t val);

  void __set_name(const std::string& val);

  void __set_iteratorClass(const std::string& val);

  void __set_properties(const std::map<std::string, std::string> & val);

  bool operator == (const TIteratorSetting & rhs) const
  {
    if (!(priority == rhs.priority))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(iteratorClass == rhs.iteratorClass))
      return false;
    if (!(properties == rhs.properties))
      return false;
    return true;
  }
  bool operator != (const TIteratorSetting &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TIteratorSetting & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TIteratorSetting& obj);
};

void swap(TIteratorSetting &a, TIteratorSetting &b);

typedef struct _IteratorConfig__isset {
  _IteratorConfig__isset() : iterators(false) {}
  bool iterators :1;
} _IteratorConfig__isset;

class IteratorConfig {
 public:

  static const char* ascii_fingerprint; // = "FFF95A9CEF69279C7B1115140EF9F6D7";
  static const uint8_t binary_fingerprint[16]; // = {0xFF,0xF9,0x5A,0x9C,0xEF,0x69,0x27,0x9C,0x7B,0x11,0x15,0x14,0x0E,0xF9,0xF6,0xD7};

  IteratorConfig(const IteratorConfig&);
  IteratorConfig& operator=(const IteratorConfig&);
  IteratorConfig() {
  }

  virtual ~IteratorConfig() throw();
  std::vector<TIteratorSetting>  iterators;

  _IteratorConfig__isset __isset;

  void __set_iterators(const std::vector<TIteratorSetting> & val);

  bool operator == (const IteratorConfig & rhs) const
  {
    if (!(iterators == rhs.iterators))
      return false;
    return true;
  }
  bool operator != (const IteratorConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IteratorConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IteratorConfig& obj);
};

void swap(IteratorConfig &a, IteratorConfig &b);

}}}}}} // namespace

#endif
