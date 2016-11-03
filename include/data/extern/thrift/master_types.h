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
#ifndef master_TYPES_H
#define master_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "data_types.h"
#include "security_types.h"
#include "client_types.h"
#include "trace_types.h"


namespace org { namespace apache { namespace accumulo { namespace core { namespace master { namespace thrift {

struct MasterState {
  enum type {
    INITIAL = 0,
    HAVE_LOCK = 1,
    SAFE_MODE = 2,
    NORMAL = 3,
    UNLOAD_METADATA_TABLETS = 4,
    UNLOAD_ROOT_TABLET = 5,
    STOP = 6
  };
};

extern const std::map<int, const char*> _MasterState_VALUES_TO_NAMES;

struct MasterGoalState {
  enum type {
    CLEAN_STOP = 0,
    SAFE_MODE = 1,
    NORMAL = 2
  };
};

extern const std::map<int, const char*> _MasterGoalState_VALUES_TO_NAMES;

struct TabletLoadState {
  enum type {
    LOADED = 0,
    LOAD_FAILURE = 1,
    UNLOADED = 2,
    UNLOAD_FAILURE_NOT_SERVING = 3,
    UNLOAD_ERROR = 4,
    CHOPPED = 5
  };
};

extern const std::map<int, const char*> _TabletLoadState_VALUES_TO_NAMES;

struct FateOperation {
  enum type {
    TABLE_CREATE = 0,
    TABLE_CLONE = 1,
    TABLE_DELETE = 2,
    TABLE_RENAME = 3,
    TABLE_ONLINE = 4,
    TABLE_OFFLINE = 5,
    TABLE_MERGE = 6,
    TABLE_DELETE_RANGE = 7,
    TABLE_BULK_IMPORT = 8,
    TABLE_COMPACT = 9,
    TABLE_IMPORT = 10,
    TABLE_EXPORT = 11,
    TABLE_CANCEL_COMPACT = 12,
    NAMESPACE_CREATE = 13,
    NAMESPACE_DELETE = 14,
    NAMESPACE_RENAME = 15
  };
};

extern const std::map<int, const char*> _FateOperation_VALUES_TO_NAMES;

class Compacting;

class TableInfo;

class RecoveryStatus;

class TabletServerStatus;

class DeadServer;

class MasterMonitorInfo;

class TabletSplit;

class RecoveryException;

typedef struct _Compacting__isset {
  _Compacting__isset() : running(false), queued(false) {}
  bool running :1;
  bool queued :1;
} _Compacting__isset;

class Compacting {
 public:

  static const char* ascii_fingerprint; // = "989D1F1AE8D148D5E2119FFEC4BBBEE3";
  static const uint8_t binary_fingerprint[16]; // = {0x98,0x9D,0x1F,0x1A,0xE8,0xD1,0x48,0xD5,0xE2,0x11,0x9F,0xFE,0xC4,0xBB,0xBE,0xE3};

  Compacting(const Compacting&);
  Compacting& operator=(const Compacting&);
  Compacting() : running(0), queued(0) {
  }

  virtual ~Compacting() throw();
  int32_t running;
  int32_t queued;

  _Compacting__isset __isset;

  void __set_running(const int32_t val);

  void __set_queued(const int32_t val);

  bool operator == (const Compacting & rhs) const
  {
    if (!(running == rhs.running))
      return false;
    if (!(queued == rhs.queued))
      return false;
    return true;
  }
  bool operator != (const Compacting &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Compacting & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Compacting& obj);
};

void swap(Compacting &a, Compacting &b);

typedef struct _TableInfo__isset {
  _TableInfo__isset() : recs(false), recsInMemory(false), tablets(false), onlineTablets(false), ingestRate(false), ingestByteRate(false), queryRate(false), queryByteRate(false), minors(false), majors(false), scans(false), scanRate(false) {}
  bool recs :1;
  bool recsInMemory :1;
  bool tablets :1;
  bool onlineTablets :1;
  bool ingestRate :1;
  bool ingestByteRate :1;
  bool queryRate :1;
  bool queryByteRate :1;
  bool minors :1;
  bool majors :1;
  bool scans :1;
  bool scanRate :1;
} _TableInfo__isset;

class TableInfo {
 public:

  static const char* ascii_fingerprint; // = "D1B40B6CDBBA041D2E4F3215B5A7FF49";
  static const uint8_t binary_fingerprint[16]; // = {0xD1,0xB4,0x0B,0x6C,0xDB,0xBA,0x04,0x1D,0x2E,0x4F,0x32,0x15,0xB5,0xA7,0xFF,0x49};

  TableInfo(const TableInfo&);
  TableInfo& operator=(const TableInfo&);
  TableInfo() : recs(0), recsInMemory(0), tablets(0), onlineTablets(0), ingestRate(0), ingestByteRate(0), queryRate(0), queryByteRate(0), scanRate(0) {
  }

  virtual ~TableInfo() throw();
  int64_t recs;
  int64_t recsInMemory;
  int32_t tablets;
  int32_t onlineTablets;
  double ingestRate;
  double ingestByteRate;
  double queryRate;
  double queryByteRate;
  Compacting minors;
  Compacting majors;
  Compacting scans;
  double scanRate;

  _TableInfo__isset __isset;

  void __set_recs(const int64_t val);

  void __set_recsInMemory(const int64_t val);

  void __set_tablets(const int32_t val);

  void __set_onlineTablets(const int32_t val);

  void __set_ingestRate(const double val);

  void __set_ingestByteRate(const double val);

  void __set_queryRate(const double val);

  void __set_queryByteRate(const double val);

  void __set_minors(const Compacting& val);

  void __set_majors(const Compacting& val);

  void __set_scans(const Compacting& val);

  void __set_scanRate(const double val);

  bool operator == (const TableInfo & rhs) const
  {
    if (!(recs == rhs.recs))
      return false;
    if (!(recsInMemory == rhs.recsInMemory))
      return false;
    if (!(tablets == rhs.tablets))
      return false;
    if (!(onlineTablets == rhs.onlineTablets))
      return false;
    if (!(ingestRate == rhs.ingestRate))
      return false;
    if (!(ingestByteRate == rhs.ingestByteRate))
      return false;
    if (!(queryRate == rhs.queryRate))
      return false;
    if (!(queryByteRate == rhs.queryByteRate))
      return false;
    if (!(minors == rhs.minors))
      return false;
    if (!(majors == rhs.majors))
      return false;
    if (!(scans == rhs.scans))
      return false;
    if (!(scanRate == rhs.scanRate))
      return false;
    return true;
  }
  bool operator != (const TableInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TableInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TableInfo& obj);
};

void swap(TableInfo &a, TableInfo &b);

typedef struct _RecoveryStatus__isset {
  _RecoveryStatus__isset() : name(false), runtime(false), progress(false) {}
  bool name :1;
  bool runtime :1;
  bool progress :1;
} _RecoveryStatus__isset;

class RecoveryStatus {
 public:

  static const char* ascii_fingerprint; // = "EDDD3E9D46980BDB38F82C7B45738053";
  static const uint8_t binary_fingerprint[16]; // = {0xED,0xDD,0x3E,0x9D,0x46,0x98,0x0B,0xDB,0x38,0xF8,0x2C,0x7B,0x45,0x73,0x80,0x53};

  RecoveryStatus(const RecoveryStatus&);
  RecoveryStatus& operator=(const RecoveryStatus&);
  RecoveryStatus() : name(), runtime(0), progress(0) {
  }

  virtual ~RecoveryStatus() throw();
  std::string name;
  int32_t runtime;
  double progress;

  _RecoveryStatus__isset __isset;

  void __set_name(const std::string& val);

  void __set_runtime(const int32_t val);

  void __set_progress(const double val);

  bool operator == (const RecoveryStatus & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(runtime == rhs.runtime))
      return false;
    if (!(progress == rhs.progress))
      return false;
    return true;
  }
  bool operator != (const RecoveryStatus &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RecoveryStatus & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const RecoveryStatus& obj);
};

void swap(RecoveryStatus &a, RecoveryStatus &b);

typedef struct _TabletServerStatus__isset {
  _TabletServerStatus__isset() : tableMap(false), lastContact(false), name(false), osLoad(false), holdTime(false), lookups(false), indexCacheHits(false), indexCacheRequest(false), dataCacheHits(false), dataCacheRequest(false), logSorts(false) {}
  bool tableMap :1;
  bool lastContact :1;
  bool name :1;
  bool osLoad :1;
  bool holdTime :1;
  bool lookups :1;
  bool indexCacheHits :1;
  bool indexCacheRequest :1;
  bool dataCacheHits :1;
  bool dataCacheRequest :1;
  bool logSorts :1;
} _TabletServerStatus__isset;

class TabletServerStatus {
 public:

  static const char* ascii_fingerprint; // = "DD8B6FED027FCEF184342CD2B4178461";
  static const uint8_t binary_fingerprint[16]; // = {0xDD,0x8B,0x6F,0xED,0x02,0x7F,0xCE,0xF1,0x84,0x34,0x2C,0xD2,0xB4,0x17,0x84,0x61};

  TabletServerStatus(const TabletServerStatus&);
  TabletServerStatus& operator=(const TabletServerStatus&);
  TabletServerStatus() : lastContact(0), name(), osLoad(0), holdTime(0), lookups(0), indexCacheHits(0), indexCacheRequest(0), dataCacheHits(0), dataCacheRequest(0) {
  }

  virtual ~TabletServerStatus() throw();
  std::map<std::string, TableInfo>  tableMap;
  int64_t lastContact;
  std::string name;
  double osLoad;
  int64_t holdTime;
  int64_t lookups;
  int64_t indexCacheHits;
  int64_t indexCacheRequest;
  int64_t dataCacheHits;
  int64_t dataCacheRequest;
  std::vector<RecoveryStatus>  logSorts;

  _TabletServerStatus__isset __isset;

  void __set_tableMap(const std::map<std::string, TableInfo> & val);

  void __set_lastContact(const int64_t val);

  void __set_name(const std::string& val);

  void __set_osLoad(const double val);

  void __set_holdTime(const int64_t val);

  void __set_lookups(const int64_t val);

  void __set_indexCacheHits(const int64_t val);

  void __set_indexCacheRequest(const int64_t val);

  void __set_dataCacheHits(const int64_t val);

  void __set_dataCacheRequest(const int64_t val);

  void __set_logSorts(const std::vector<RecoveryStatus> & val);

  bool operator == (const TabletServerStatus & rhs) const
  {
    if (!(tableMap == rhs.tableMap))
      return false;
    if (!(lastContact == rhs.lastContact))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(osLoad == rhs.osLoad))
      return false;
    if (!(holdTime == rhs.holdTime))
      return false;
    if (!(lookups == rhs.lookups))
      return false;
    if (!(indexCacheHits == rhs.indexCacheHits))
      return false;
    if (!(indexCacheRequest == rhs.indexCacheRequest))
      return false;
    if (!(dataCacheHits == rhs.dataCacheHits))
      return false;
    if (!(dataCacheRequest == rhs.dataCacheRequest))
      return false;
    if (!(logSorts == rhs.logSorts))
      return false;
    return true;
  }
  bool operator != (const TabletServerStatus &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletServerStatus & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletServerStatus& obj);
};

void swap(TabletServerStatus &a, TabletServerStatus &b);

typedef struct _DeadServer__isset {
  _DeadServer__isset() : server(false), lastStatus(false), status(false) {}
  bool server :1;
  bool lastStatus :1;
  bool status :1;
} _DeadServer__isset;

class DeadServer {
 public:

  static const char* ascii_fingerprint; // = "FA35BEC6F4D26D79A7E0AD1366489BCC";
  static const uint8_t binary_fingerprint[16]; // = {0xFA,0x35,0xBE,0xC6,0xF4,0xD2,0x6D,0x79,0xA7,0xE0,0xAD,0x13,0x66,0x48,0x9B,0xCC};

  DeadServer(const DeadServer&);
  DeadServer& operator=(const DeadServer&);
  DeadServer() : server(), lastStatus(0), status() {
  }

  virtual ~DeadServer() throw();
  std::string server;
  int64_t lastStatus;
  std::string status;

  _DeadServer__isset __isset;

  void __set_server(const std::string& val);

  void __set_lastStatus(const int64_t val);

  void __set_status(const std::string& val);

  bool operator == (const DeadServer & rhs) const
  {
    if (!(server == rhs.server))
      return false;
    if (!(lastStatus == rhs.lastStatus))
      return false;
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const DeadServer &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeadServer & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const DeadServer& obj);
};

void swap(DeadServer &a, DeadServer &b);

typedef struct _MasterMonitorInfo__isset {
  _MasterMonitorInfo__isset() : tableMap(false), tServerInfo(false), badTServers(false), state(false), goalState(false), unassignedTablets(false), serversShuttingDown(false), deadTabletServers(false) {}
  bool tableMap :1;
  bool tServerInfo :1;
  bool badTServers :1;
  bool state :1;
  bool goalState :1;
  bool unassignedTablets :1;
  bool serversShuttingDown :1;
  bool deadTabletServers :1;
} _MasterMonitorInfo__isset;

class MasterMonitorInfo {
 public:

  static const char* ascii_fingerprint; // = "97129B4CC16BA8DA7D678FBCE0016340";
  static const uint8_t binary_fingerprint[16]; // = {0x97,0x12,0x9B,0x4C,0xC1,0x6B,0xA8,0xDA,0x7D,0x67,0x8F,0xBC,0xE0,0x01,0x63,0x40};

  MasterMonitorInfo(const MasterMonitorInfo&);
  MasterMonitorInfo& operator=(const MasterMonitorInfo&);
  MasterMonitorInfo() : state((MasterState::type)0), goalState((MasterGoalState::type)0), unassignedTablets(0) {
  }

  virtual ~MasterMonitorInfo() throw();
  std::map<std::string, TableInfo>  tableMap;
  std::vector<TabletServerStatus>  tServerInfo;
  std::map<std::string, int8_t>  badTServers;
  MasterState::type state;
  MasterGoalState::type goalState;
  int32_t unassignedTablets;
  std::set<std::string>  serversShuttingDown;
  std::vector<DeadServer>  deadTabletServers;

  _MasterMonitorInfo__isset __isset;

  void __set_tableMap(const std::map<std::string, TableInfo> & val);

  void __set_tServerInfo(const std::vector<TabletServerStatus> & val);

  void __set_badTServers(const std::map<std::string, int8_t> & val);

  void __set_state(const MasterState::type val);

  void __set_goalState(const MasterGoalState::type val);

  void __set_unassignedTablets(const int32_t val);

  void __set_serversShuttingDown(const std::set<std::string> & val);

  void __set_deadTabletServers(const std::vector<DeadServer> & val);

  bool operator == (const MasterMonitorInfo & rhs) const
  {
    if (!(tableMap == rhs.tableMap))
      return false;
    if (!(tServerInfo == rhs.tServerInfo))
      return false;
    if (!(badTServers == rhs.badTServers))
      return false;
    if (!(state == rhs.state))
      return false;
    if (!(goalState == rhs.goalState))
      return false;
    if (!(unassignedTablets == rhs.unassignedTablets))
      return false;
    if (!(serversShuttingDown == rhs.serversShuttingDown))
      return false;
    if (!(deadTabletServers == rhs.deadTabletServers))
      return false;
    return true;
  }
  bool operator != (const MasterMonitorInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MasterMonitorInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const MasterMonitorInfo& obj);
};

void swap(MasterMonitorInfo &a, MasterMonitorInfo &b);

typedef struct _TabletSplit__isset {
  _TabletSplit__isset() : oldTablet(false), newTablets(false) {}
  bool oldTablet :1;
  bool newTablets :1;
} _TabletSplit__isset;

class TabletSplit {
 public:

  static const char* ascii_fingerprint; // = "512446FDB691C6A2252369D371A5BDE9";
  static const uint8_t binary_fingerprint[16]; // = {0x51,0x24,0x46,0xFD,0xB6,0x91,0xC6,0xA2,0x25,0x23,0x69,0xD3,0x71,0xA5,0xBD,0xE9};

  TabletSplit(const TabletSplit&);
  TabletSplit& operator=(const TabletSplit&);
  TabletSplit() {
  }

  virtual ~TabletSplit() throw();
   ::org::apache::accumulo::core::data::thrift::TKeyExtent oldTablet;
  std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent>  newTablets;

  _TabletSplit__isset __isset;

  void __set_oldTablet(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  void __set_newTablets(const std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent> & val);

  bool operator == (const TabletSplit & rhs) const
  {
    if (!(oldTablet == rhs.oldTablet))
      return false;
    if (!(newTablets == rhs.newTablets))
      return false;
    return true;
  }
  bool operator != (const TabletSplit &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletSplit & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletSplit& obj);
};

void swap(TabletSplit &a, TabletSplit &b);

typedef struct _RecoveryException__isset {
  _RecoveryException__isset() : why(false) {}
  bool why :1;
} _RecoveryException__isset;

class RecoveryException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  RecoveryException(const RecoveryException&);
  RecoveryException& operator=(const RecoveryException&);
  RecoveryException() : why() {
  }

  virtual ~RecoveryException() throw();
  std::string why;

  _RecoveryException__isset __isset;

  void __set_why(const std::string& val);

  bool operator == (const RecoveryException & rhs) const
  {
    if (!(why == rhs.why))
      return false;
    return true;
  }
  bool operator != (const RecoveryException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RecoveryException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const RecoveryException& obj);
};

void swap(RecoveryException &a, RecoveryException &b);

}}}}}} // namespace

#endif
