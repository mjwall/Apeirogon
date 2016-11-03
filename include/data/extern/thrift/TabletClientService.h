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
#ifndef TabletClientService_H
#define TabletClientService_H

#include <thrift/TDispatchProcessor.h>
#include "tabletserver_types.h"
#include "ClientService.h"

namespace org { namespace apache { namespace accumulo { namespace core { namespace tabletserver { namespace thrift {

class TabletClientServiceIf : virtual public  ::org::apache::accumulo::core::client::impl::thrift::ClientServiceIf {
 public:
  virtual ~TabletClientServiceIf() {}
  virtual void startScan( ::org::apache::accumulo::core::data::thrift::InitialScan& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const  ::org::apache::accumulo::core::data::thrift::TRange& range, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & columns, const int32_t batchSize, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList, const std::map<std::string, std::map<std::string, std::string> > & ssio, const std::vector<std::string> & authorizations, const bool waitForWrites, const bool isolated, const int64_t readaheadThreshold) = 0;
  virtual void continueScan( ::org::apache::accumulo::core::data::thrift::ScanResult& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID) = 0;
  virtual void closeScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID) = 0;
  virtual void startMultiScan( ::org::apache::accumulo::core::data::thrift::InitialMultiScan& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::ScanBatch& batch, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & columns, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList, const std::map<std::string, std::map<std::string, std::string> > & ssio, const std::vector<std::string> & authorizations, const bool waitForWrites) = 0;
  virtual void continueMultiScan( ::org::apache::accumulo::core::data::thrift::MultiScanResult& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID) = 0;
  virtual void closeMultiScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID) = 0;
  virtual  ::org::apache::accumulo::core::data::thrift::UpdateID startUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void applyUpdates(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID updateID, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent, const std::vector< ::org::apache::accumulo::core::data::thrift::TMutation> & mutations) = 0;
  virtual void closeUpdate( ::org::apache::accumulo::core::data::thrift::UpdateErrors& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID updateID) = 0;
  virtual void update(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent, const  ::org::apache::accumulo::core::data::thrift::TMutation& mutation) = 0;
  virtual void startConditionalUpdate( ::org::apache::accumulo::core::data::thrift::TConditionalSession& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::vector<std::string> & authorizations, const std::string& tableID) = 0;
  virtual void conditionalUpdate(std::vector< ::org::apache::accumulo::core::data::thrift::TCMResult> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID, const  ::org::apache::accumulo::core::data::thrift::CMBatch& mutations, const std::vector<std::string> & symbols) = 0;
  virtual void invalidateConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID) = 0;
  virtual void closeConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID) = 0;
  virtual void bulkImport(std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t tid, const  ::org::apache::accumulo::core::data::thrift::TabletFiles& files, const bool setTime) = 0;
  virtual void splitTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const std::string& splitPoint) = 0;
  virtual void loadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent) = 0;
  virtual void unloadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const bool save) = 0;
  virtual void flush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const std::string& tableId, const std::string& startRow, const std::string& endRow) = 0;
  virtual void flushTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent) = 0;
  virtual void chop(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent) = 0;
  virtual void compact(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const std::string& tableId, const std::string& startRow, const std::string& endRow) = 0;
  virtual void getTabletServerStatus( ::org::apache::accumulo::core::master::thrift::TabletServerStatus& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void getTabletStats(std::vector<TabletStats> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableId) = 0;
  virtual void getHistoricalStats(TabletStats& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void halt(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock) = 0;
  virtual void fastHalt(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock) = 0;
  virtual void getActiveScans(std::vector<ActiveScan> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void getActiveCompactions(std::vector<ActiveCompaction> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) = 0;
  virtual void removeLogs(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::vector<std::string> & filenames) = 0;
};

class TabletClientServiceIfFactory : virtual public  ::org::apache::accumulo::core::client::impl::thrift::ClientServiceIfFactory {
 public:
  typedef TabletClientServiceIf Handler;

  virtual ~TabletClientServiceIfFactory() {}

  virtual TabletClientServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler( ::org::apache::accumulo::core::client::impl::thrift::ClientServiceIf* /* handler */) = 0;
};

class TabletClientServiceIfSingletonFactory : virtual public TabletClientServiceIfFactory {
 public:
  TabletClientServiceIfSingletonFactory(const boost::shared_ptr<TabletClientServiceIf>& iface) : iface_(iface) {}
  virtual ~TabletClientServiceIfSingletonFactory() {}

  virtual TabletClientServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler( ::org::apache::accumulo::core::client::impl::thrift::ClientServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<TabletClientServiceIf> iface_;
};

class TabletClientServiceNull : virtual public TabletClientServiceIf , virtual public  ::org::apache::accumulo::core::client::impl::thrift::ClientServiceNull {
 public:
  virtual ~TabletClientServiceNull() {}
  void startScan( ::org::apache::accumulo::core::data::thrift::InitialScan& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& /* extent */, const  ::org::apache::accumulo::core::data::thrift::TRange& /* range */, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & /* columns */, const int32_t /* batchSize */, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & /* ssiList */, const std::map<std::string, std::map<std::string, std::string> > & /* ssio */, const std::vector<std::string> & /* authorizations */, const bool /* waitForWrites */, const bool /* isolated */, const int64_t /* readaheadThreshold */) {
    return;
  }
  void continueScan( ::org::apache::accumulo::core::data::thrift::ScanResult& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::data::thrift::ScanID /* scanID */) {
    return;
  }
  void closeScan(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::data::thrift::ScanID /* scanID */) {
    return;
  }
  void startMultiScan( ::org::apache::accumulo::core::data::thrift::InitialMultiScan& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const  ::org::apache::accumulo::core::data::thrift::ScanBatch& /* batch */, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & /* columns */, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & /* ssiList */, const std::map<std::string, std::map<std::string, std::string> > & /* ssio */, const std::vector<std::string> & /* authorizations */, const bool /* waitForWrites */) {
    return;
  }
  void continueMultiScan( ::org::apache::accumulo::core::data::thrift::MultiScanResult& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::data::thrift::ScanID /* scanID */) {
    return;
  }
  void closeMultiScan(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::data::thrift::ScanID /* scanID */) {
    return;
  }
   ::org::apache::accumulo::core::data::thrift::UpdateID startUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
     ::org::apache::accumulo::core::data::thrift::UpdateID _return = 0;
    return _return;
  }
  void applyUpdates(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::data::thrift::UpdateID /* updateID */, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& /* keyExtent */, const std::vector< ::org::apache::accumulo::core::data::thrift::TMutation> & /* mutations */) {
    return;
  }
  void closeUpdate( ::org::apache::accumulo::core::data::thrift::UpdateErrors& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::data::thrift::UpdateID /* updateID */) {
    return;
  }
  void update(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& /* keyExtent */, const  ::org::apache::accumulo::core::data::thrift::TMutation& /* mutation */) {
    return;
  }
  void startConditionalUpdate( ::org::apache::accumulo::core::data::thrift::TConditionalSession& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::vector<std::string> & /* authorizations */, const std::string& /* tableID */) {
    return;
  }
  void conditionalUpdate(std::vector< ::org::apache::accumulo::core::data::thrift::TCMResult> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::data::thrift::UpdateID /* sessID */, const  ::org::apache::accumulo::core::data::thrift::CMBatch& /* mutations */, const std::vector<std::string> & /* symbols */) {
    return;
  }
  void invalidateConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::data::thrift::UpdateID /* sessID */) {
    return;
  }
  void closeConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::data::thrift::UpdateID /* sessID */) {
    return;
  }
  void bulkImport(std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const int64_t /* tid */, const  ::org::apache::accumulo::core::data::thrift::TabletFiles& /* files */, const bool /* setTime */) {
    return;
  }
  void splitTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& /* extent */, const std::string& /* splitPoint */) {
    return;
  }
  void loadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* lock */, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& /* extent */) {
    return;
  }
  void unloadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* lock */, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& /* extent */, const bool /* save */) {
    return;
  }
  void flush(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* lock */, const std::string& /* tableId */, const std::string& /* startRow */, const std::string& /* endRow */) {
    return;
  }
  void flushTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* lock */, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& /* extent */) {
    return;
  }
  void chop(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* lock */, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& /* extent */) {
    return;
  }
  void compact(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* lock */, const std::string& /* tableId */, const std::string& /* startRow */, const std::string& /* endRow */) {
    return;
  }
  void getTabletServerStatus( ::org::apache::accumulo::core::master::thrift::TabletServerStatus& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    return;
  }
  void getTabletStats(std::vector<TabletStats> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* tableId */) {
    return;
  }
  void getHistoricalStats(TabletStats& /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    return;
  }
  void halt(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* lock */) {
    return;
  }
  void fastHalt(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::string& /* lock */) {
    return;
  }
  void getActiveScans(std::vector<ActiveScan> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    return;
  }
  void getActiveCompactions(std::vector<ActiveCompaction> & /* _return */, const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */) {
    return;
  }
  void removeLogs(const  ::org::apache::accumulo::trace::thrift::TInfo& /* tinfo */, const  ::org::apache::accumulo::core::security::thrift::TCredentials& /* credentials */, const std::vector<std::string> & /* filenames */) {
    return;
  }
};

typedef struct _TabletClientService_startScan_args__isset {
  _TabletClientService_startScan_args__isset() : tinfo(false), credentials(false), extent(false), range(false), columns(false), batchSize(false), ssiList(false), ssio(false), authorizations(false), waitForWrites(false), isolated(false), readaheadThreshold(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool extent :1;
  bool range :1;
  bool columns :1;
  bool batchSize :1;
  bool ssiList :1;
  bool ssio :1;
  bool authorizations :1;
  bool waitForWrites :1;
  bool isolated :1;
  bool readaheadThreshold :1;
} _TabletClientService_startScan_args__isset;

class TabletClientService_startScan_args {
 public:

  static const char* ascii_fingerprint; // = "938E56C846F97A4F6E13222374C5636D";
  static const uint8_t binary_fingerprint[16]; // = {0x93,0x8E,0x56,0xC8,0x46,0xF9,0x7A,0x4F,0x6E,0x13,0x22,0x23,0x74,0xC5,0x63,0x6D};

  TabletClientService_startScan_args(const TabletClientService_startScan_args&);
  TabletClientService_startScan_args& operator=(const TabletClientService_startScan_args&);
  TabletClientService_startScan_args() : batchSize(0), waitForWrites(0), isolated(0), readaheadThreshold(0) {
  }

  virtual ~TabletClientService_startScan_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;
   ::org::apache::accumulo::core::data::thrift::TRange range;
  std::vector< ::org::apache::accumulo::core::data::thrift::TColumn>  columns;
  int32_t batchSize;
  std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo>  ssiList;
  std::map<std::string, std::map<std::string, std::string> >  ssio;
  std::vector<std::string>  authorizations;
  bool waitForWrites;
  bool isolated;
  int64_t readaheadThreshold;

  _TabletClientService_startScan_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  void __set_range(const  ::org::apache::accumulo::core::data::thrift::TRange& val);

  void __set_columns(const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & val);

  void __set_batchSize(const int32_t val);

  void __set_ssiList(const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & val);

  void __set_ssio(const std::map<std::string, std::map<std::string, std::string> > & val);

  void __set_authorizations(const std::vector<std::string> & val);

  void __set_waitForWrites(const bool val);

  void __set_isolated(const bool val);

  void __set_readaheadThreshold(const int64_t val);

  bool operator == (const TabletClientService_startScan_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(extent == rhs.extent))
      return false;
    if (!(range == rhs.range))
      return false;
    if (!(columns == rhs.columns))
      return false;
    if (!(batchSize == rhs.batchSize))
      return false;
    if (!(ssiList == rhs.ssiList))
      return false;
    if (!(ssio == rhs.ssio))
      return false;
    if (!(authorizations == rhs.authorizations))
      return false;
    if (!(waitForWrites == rhs.waitForWrites))
      return false;
    if (!(isolated == rhs.isolated))
      return false;
    if (!(readaheadThreshold == rhs.readaheadThreshold))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_startScan_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_startScan_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startScan_args& obj);
};


class TabletClientService_startScan_pargs {
 public:

  static const char* ascii_fingerprint; // = "938E56C846F97A4F6E13222374C5636D";
  static const uint8_t binary_fingerprint[16]; // = {0x93,0x8E,0x56,0xC8,0x46,0xF9,0x7A,0x4F,0x6E,0x13,0x22,0x23,0x74,0xC5,0x63,0x6D};


  virtual ~TabletClientService_startScan_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const  ::org::apache::accumulo::core::data::thrift::TKeyExtent* extent;
  const  ::org::apache::accumulo::core::data::thrift::TRange* range;
  const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> * columns;
  const int32_t* batchSize;
  const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> * ssiList;
  const std::map<std::string, std::map<std::string, std::string> > * ssio;
  const std::vector<std::string> * authorizations;
  const bool* waitForWrites;
  const bool* isolated;
  const int64_t* readaheadThreshold;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startScan_pargs& obj);
};

typedef struct _TabletClientService_startScan_result__isset {
  _TabletClientService_startScan_result__isset() : success(false), sec(false), nste(false), tmfe(false) {}
  bool success :1;
  bool sec :1;
  bool nste :1;
  bool tmfe :1;
} _TabletClientService_startScan_result__isset;

class TabletClientService_startScan_result {
 public:

  static const char* ascii_fingerprint; // = "327AC6B76E1E38D60718A7BB2CBFB6FA";
  static const uint8_t binary_fingerprint[16]; // = {0x32,0x7A,0xC6,0xB7,0x6E,0x1E,0x38,0xD6,0x07,0x18,0xA7,0xBB,0x2C,0xBF,0xB6,0xFA};

  TabletClientService_startScan_result(const TabletClientService_startScan_result&);
  TabletClientService_startScan_result& operator=(const TabletClientService_startScan_result&);
  TabletClientService_startScan_result() {
  }

  virtual ~TabletClientService_startScan_result() throw();
   ::org::apache::accumulo::core::data::thrift::InitialScan success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
  NotServingTabletException nste;
  TooManyFilesException tmfe;

  _TabletClientService_startScan_result__isset __isset;

  void __set_success(const  ::org::apache::accumulo::core::data::thrift::InitialScan& val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_nste(const NotServingTabletException& val);

  void __set_tmfe(const TooManyFilesException& val);

  bool operator == (const TabletClientService_startScan_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    if (!(nste == rhs.nste))
      return false;
    if (!(tmfe == rhs.tmfe))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_startScan_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_startScan_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startScan_result& obj);
};

typedef struct _TabletClientService_startScan_presult__isset {
  _TabletClientService_startScan_presult__isset() : success(false), sec(false), nste(false), tmfe(false) {}
  bool success :1;
  bool sec :1;
  bool nste :1;
  bool tmfe :1;
} _TabletClientService_startScan_presult__isset;

class TabletClientService_startScan_presult {
 public:

  static const char* ascii_fingerprint; // = "327AC6B76E1E38D60718A7BB2CBFB6FA";
  static const uint8_t binary_fingerprint[16]; // = {0x32,0x7A,0xC6,0xB7,0x6E,0x1E,0x38,0xD6,0x07,0x18,0xA7,0xBB,0x2C,0xBF,0xB6,0xFA};


  virtual ~TabletClientService_startScan_presult() throw();
   ::org::apache::accumulo::core::data::thrift::InitialScan* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
  NotServingTabletException nste;
  TooManyFilesException tmfe;

  _TabletClientService_startScan_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startScan_presult& obj);
};

typedef struct _TabletClientService_continueScan_args__isset {
  _TabletClientService_continueScan_args__isset() : tinfo(false), scanID(false) {}
  bool tinfo :1;
  bool scanID :1;
} _TabletClientService_continueScan_args__isset;

class TabletClientService_continueScan_args {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};

  TabletClientService_continueScan_args(const TabletClientService_continueScan_args&);
  TabletClientService_continueScan_args& operator=(const TabletClientService_continueScan_args&);
  TabletClientService_continueScan_args() : scanID(0) {
  }

  virtual ~TabletClientService_continueScan_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::data::thrift::ScanID scanID;

  _TabletClientService_continueScan_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_scanID(const  ::org::apache::accumulo::core::data::thrift::ScanID val);

  bool operator == (const TabletClientService_continueScan_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(scanID == rhs.scanID))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_continueScan_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_continueScan_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_continueScan_args& obj);
};


class TabletClientService_continueScan_pargs {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};


  virtual ~TabletClientService_continueScan_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::data::thrift::ScanID* scanID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_continueScan_pargs& obj);
};

typedef struct _TabletClientService_continueScan_result__isset {
  _TabletClientService_continueScan_result__isset() : success(false), nssi(false), nste(false), tmfe(false) {}
  bool success :1;
  bool nssi :1;
  bool nste :1;
  bool tmfe :1;
} _TabletClientService_continueScan_result__isset;

class TabletClientService_continueScan_result {
 public:

  static const char* ascii_fingerprint; // = "24ED6F8BD6349FE0D7C27D0FAA14732A";
  static const uint8_t binary_fingerprint[16]; // = {0x24,0xED,0x6F,0x8B,0xD6,0x34,0x9F,0xE0,0xD7,0xC2,0x7D,0x0F,0xAA,0x14,0x73,0x2A};

  TabletClientService_continueScan_result(const TabletClientService_continueScan_result&);
  TabletClientService_continueScan_result& operator=(const TabletClientService_continueScan_result&);
  TabletClientService_continueScan_result() {
  }

  virtual ~TabletClientService_continueScan_result() throw();
   ::org::apache::accumulo::core::data::thrift::ScanResult success;
  NoSuchScanIDException nssi;
  NotServingTabletException nste;
  TooManyFilesException tmfe;

  _TabletClientService_continueScan_result__isset __isset;

  void __set_success(const  ::org::apache::accumulo::core::data::thrift::ScanResult& val);

  void __set_nssi(const NoSuchScanIDException& val);

  void __set_nste(const NotServingTabletException& val);

  void __set_tmfe(const TooManyFilesException& val);

  bool operator == (const TabletClientService_continueScan_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(nssi == rhs.nssi))
      return false;
    if (!(nste == rhs.nste))
      return false;
    if (!(tmfe == rhs.tmfe))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_continueScan_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_continueScan_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_continueScan_result& obj);
};

typedef struct _TabletClientService_continueScan_presult__isset {
  _TabletClientService_continueScan_presult__isset() : success(false), nssi(false), nste(false), tmfe(false) {}
  bool success :1;
  bool nssi :1;
  bool nste :1;
  bool tmfe :1;
} _TabletClientService_continueScan_presult__isset;

class TabletClientService_continueScan_presult {
 public:

  static const char* ascii_fingerprint; // = "24ED6F8BD6349FE0D7C27D0FAA14732A";
  static const uint8_t binary_fingerprint[16]; // = {0x24,0xED,0x6F,0x8B,0xD6,0x34,0x9F,0xE0,0xD7,0xC2,0x7D,0x0F,0xAA,0x14,0x73,0x2A};


  virtual ~TabletClientService_continueScan_presult() throw();
   ::org::apache::accumulo::core::data::thrift::ScanResult* success;
  NoSuchScanIDException nssi;
  NotServingTabletException nste;
  TooManyFilesException tmfe;

  _TabletClientService_continueScan_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_continueScan_presult& obj);
};

typedef struct _TabletClientService_closeScan_args__isset {
  _TabletClientService_closeScan_args__isset() : tinfo(false), scanID(false) {}
  bool tinfo :1;
  bool scanID :1;
} _TabletClientService_closeScan_args__isset;

class TabletClientService_closeScan_args {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};

  TabletClientService_closeScan_args(const TabletClientService_closeScan_args&);
  TabletClientService_closeScan_args& operator=(const TabletClientService_closeScan_args&);
  TabletClientService_closeScan_args() : scanID(0) {
  }

  virtual ~TabletClientService_closeScan_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::data::thrift::ScanID scanID;

  _TabletClientService_closeScan_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_scanID(const  ::org::apache::accumulo::core::data::thrift::ScanID val);

  bool operator == (const TabletClientService_closeScan_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(scanID == rhs.scanID))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_closeScan_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_closeScan_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeScan_args& obj);
};


class TabletClientService_closeScan_pargs {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};


  virtual ~TabletClientService_closeScan_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::data::thrift::ScanID* scanID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeScan_pargs& obj);
};

typedef struct _TabletClientService_startMultiScan_args__isset {
  _TabletClientService_startMultiScan_args__isset() : tinfo(false), credentials(false), batch(false), columns(false), ssiList(false), ssio(false), authorizations(false), waitForWrites(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool batch :1;
  bool columns :1;
  bool ssiList :1;
  bool ssio :1;
  bool authorizations :1;
  bool waitForWrites :1;
} _TabletClientService_startMultiScan_args__isset;

class TabletClientService_startMultiScan_args {
 public:

  static const char* ascii_fingerprint; // = "D82E8C86CE98B1574D28335C3C031FD5";
  static const uint8_t binary_fingerprint[16]; // = {0xD8,0x2E,0x8C,0x86,0xCE,0x98,0xB1,0x57,0x4D,0x28,0x33,0x5C,0x3C,0x03,0x1F,0xD5};

  TabletClientService_startMultiScan_args(const TabletClientService_startMultiScan_args&);
  TabletClientService_startMultiScan_args& operator=(const TabletClientService_startMultiScan_args&);
  TabletClientService_startMultiScan_args() : waitForWrites(0) {
  }

  virtual ~TabletClientService_startMultiScan_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
   ::org::apache::accumulo::core::data::thrift::ScanBatch batch;
  std::vector< ::org::apache::accumulo::core::data::thrift::TColumn>  columns;
  std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo>  ssiList;
  std::map<std::string, std::map<std::string, std::string> >  ssio;
  std::vector<std::string>  authorizations;
  bool waitForWrites;

  _TabletClientService_startMultiScan_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_batch(const  ::org::apache::accumulo::core::data::thrift::ScanBatch& val);

  void __set_columns(const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & val);

  void __set_ssiList(const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & val);

  void __set_ssio(const std::map<std::string, std::map<std::string, std::string> > & val);

  void __set_authorizations(const std::vector<std::string> & val);

  void __set_waitForWrites(const bool val);

  bool operator == (const TabletClientService_startMultiScan_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(batch == rhs.batch))
      return false;
    if (!(columns == rhs.columns))
      return false;
    if (!(ssiList == rhs.ssiList))
      return false;
    if (!(ssio == rhs.ssio))
      return false;
    if (!(authorizations == rhs.authorizations))
      return false;
    if (!(waitForWrites == rhs.waitForWrites))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_startMultiScan_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_startMultiScan_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startMultiScan_args& obj);
};


class TabletClientService_startMultiScan_pargs {
 public:

  static const char* ascii_fingerprint; // = "D82E8C86CE98B1574D28335C3C031FD5";
  static const uint8_t binary_fingerprint[16]; // = {0xD8,0x2E,0x8C,0x86,0xCE,0x98,0xB1,0x57,0x4D,0x28,0x33,0x5C,0x3C,0x03,0x1F,0xD5};


  virtual ~TabletClientService_startMultiScan_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const  ::org::apache::accumulo::core::data::thrift::ScanBatch* batch;
  const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> * columns;
  const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> * ssiList;
  const std::map<std::string, std::map<std::string, std::string> > * ssio;
  const std::vector<std::string> * authorizations;
  const bool* waitForWrites;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startMultiScan_pargs& obj);
};

typedef struct _TabletClientService_startMultiScan_result__isset {
  _TabletClientService_startMultiScan_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_startMultiScan_result__isset;

class TabletClientService_startMultiScan_result {
 public:

  static const char* ascii_fingerprint; // = "52F0D58BF29827C56DEADD7853F29BEB";
  static const uint8_t binary_fingerprint[16]; // = {0x52,0xF0,0xD5,0x8B,0xF2,0x98,0x27,0xC5,0x6D,0xEA,0xDD,0x78,0x53,0xF2,0x9B,0xEB};

  TabletClientService_startMultiScan_result(const TabletClientService_startMultiScan_result&);
  TabletClientService_startMultiScan_result& operator=(const TabletClientService_startMultiScan_result&);
  TabletClientService_startMultiScan_result() {
  }

  virtual ~TabletClientService_startMultiScan_result() throw();
   ::org::apache::accumulo::core::data::thrift::InitialMultiScan success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_startMultiScan_result__isset __isset;

  void __set_success(const  ::org::apache::accumulo::core::data::thrift::InitialMultiScan& val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_startMultiScan_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_startMultiScan_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_startMultiScan_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startMultiScan_result& obj);
};

typedef struct _TabletClientService_startMultiScan_presult__isset {
  _TabletClientService_startMultiScan_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_startMultiScan_presult__isset;

class TabletClientService_startMultiScan_presult {
 public:

  static const char* ascii_fingerprint; // = "52F0D58BF29827C56DEADD7853F29BEB";
  static const uint8_t binary_fingerprint[16]; // = {0x52,0xF0,0xD5,0x8B,0xF2,0x98,0x27,0xC5,0x6D,0xEA,0xDD,0x78,0x53,0xF2,0x9B,0xEB};


  virtual ~TabletClientService_startMultiScan_presult() throw();
   ::org::apache::accumulo::core::data::thrift::InitialMultiScan* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_startMultiScan_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startMultiScan_presult& obj);
};

typedef struct _TabletClientService_continueMultiScan_args__isset {
  _TabletClientService_continueMultiScan_args__isset() : tinfo(false), scanID(false) {}
  bool tinfo :1;
  bool scanID :1;
} _TabletClientService_continueMultiScan_args__isset;

class TabletClientService_continueMultiScan_args {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};

  TabletClientService_continueMultiScan_args(const TabletClientService_continueMultiScan_args&);
  TabletClientService_continueMultiScan_args& operator=(const TabletClientService_continueMultiScan_args&);
  TabletClientService_continueMultiScan_args() : scanID(0) {
  }

  virtual ~TabletClientService_continueMultiScan_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::data::thrift::ScanID scanID;

  _TabletClientService_continueMultiScan_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_scanID(const  ::org::apache::accumulo::core::data::thrift::ScanID val);

  bool operator == (const TabletClientService_continueMultiScan_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(scanID == rhs.scanID))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_continueMultiScan_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_continueMultiScan_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_continueMultiScan_args& obj);
};


class TabletClientService_continueMultiScan_pargs {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};


  virtual ~TabletClientService_continueMultiScan_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::data::thrift::ScanID* scanID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_continueMultiScan_pargs& obj);
};

typedef struct _TabletClientService_continueMultiScan_result__isset {
  _TabletClientService_continueMultiScan_result__isset() : success(false), nssi(false) {}
  bool success :1;
  bool nssi :1;
} _TabletClientService_continueMultiScan_result__isset;

class TabletClientService_continueMultiScan_result {
 public:

  static const char* ascii_fingerprint; // = "7EBE4687E1D04352AF24918C7DE1205D";
  static const uint8_t binary_fingerprint[16]; // = {0x7E,0xBE,0x46,0x87,0xE1,0xD0,0x43,0x52,0xAF,0x24,0x91,0x8C,0x7D,0xE1,0x20,0x5D};

  TabletClientService_continueMultiScan_result(const TabletClientService_continueMultiScan_result&);
  TabletClientService_continueMultiScan_result& operator=(const TabletClientService_continueMultiScan_result&);
  TabletClientService_continueMultiScan_result() {
  }

  virtual ~TabletClientService_continueMultiScan_result() throw();
   ::org::apache::accumulo::core::data::thrift::MultiScanResult success;
  NoSuchScanIDException nssi;

  _TabletClientService_continueMultiScan_result__isset __isset;

  void __set_success(const  ::org::apache::accumulo::core::data::thrift::MultiScanResult& val);

  void __set_nssi(const NoSuchScanIDException& val);

  bool operator == (const TabletClientService_continueMultiScan_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(nssi == rhs.nssi))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_continueMultiScan_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_continueMultiScan_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_continueMultiScan_result& obj);
};

typedef struct _TabletClientService_continueMultiScan_presult__isset {
  _TabletClientService_continueMultiScan_presult__isset() : success(false), nssi(false) {}
  bool success :1;
  bool nssi :1;
} _TabletClientService_continueMultiScan_presult__isset;

class TabletClientService_continueMultiScan_presult {
 public:

  static const char* ascii_fingerprint; // = "7EBE4687E1D04352AF24918C7DE1205D";
  static const uint8_t binary_fingerprint[16]; // = {0x7E,0xBE,0x46,0x87,0xE1,0xD0,0x43,0x52,0xAF,0x24,0x91,0x8C,0x7D,0xE1,0x20,0x5D};


  virtual ~TabletClientService_continueMultiScan_presult() throw();
   ::org::apache::accumulo::core::data::thrift::MultiScanResult* success;
  NoSuchScanIDException nssi;

  _TabletClientService_continueMultiScan_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_continueMultiScan_presult& obj);
};

typedef struct _TabletClientService_closeMultiScan_args__isset {
  _TabletClientService_closeMultiScan_args__isset() : tinfo(false), scanID(false) {}
  bool tinfo :1;
  bool scanID :1;
} _TabletClientService_closeMultiScan_args__isset;

class TabletClientService_closeMultiScan_args {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};

  TabletClientService_closeMultiScan_args(const TabletClientService_closeMultiScan_args&);
  TabletClientService_closeMultiScan_args& operator=(const TabletClientService_closeMultiScan_args&);
  TabletClientService_closeMultiScan_args() : scanID(0) {
  }

  virtual ~TabletClientService_closeMultiScan_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::data::thrift::ScanID scanID;

  _TabletClientService_closeMultiScan_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_scanID(const  ::org::apache::accumulo::core::data::thrift::ScanID val);

  bool operator == (const TabletClientService_closeMultiScan_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(scanID == rhs.scanID))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_closeMultiScan_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_closeMultiScan_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeMultiScan_args& obj);
};


class TabletClientService_closeMultiScan_pargs {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};


  virtual ~TabletClientService_closeMultiScan_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::data::thrift::ScanID* scanID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeMultiScan_pargs& obj);
};

typedef struct _TabletClientService_closeMultiScan_result__isset {
  _TabletClientService_closeMultiScan_result__isset() : nssi(false) {}
  bool nssi :1;
} _TabletClientService_closeMultiScan_result__isset;

class TabletClientService_closeMultiScan_result {
 public:

  static const char* ascii_fingerprint; // = "2C32A565725135A023CB591D1A993CFD";
  static const uint8_t binary_fingerprint[16]; // = {0x2C,0x32,0xA5,0x65,0x72,0x51,0x35,0xA0,0x23,0xCB,0x59,0x1D,0x1A,0x99,0x3C,0xFD};

  TabletClientService_closeMultiScan_result(const TabletClientService_closeMultiScan_result&);
  TabletClientService_closeMultiScan_result& operator=(const TabletClientService_closeMultiScan_result&);
  TabletClientService_closeMultiScan_result() {
  }

  virtual ~TabletClientService_closeMultiScan_result() throw();
  NoSuchScanIDException nssi;

  _TabletClientService_closeMultiScan_result__isset __isset;

  void __set_nssi(const NoSuchScanIDException& val);

  bool operator == (const TabletClientService_closeMultiScan_result & rhs) const
  {
    if (!(nssi == rhs.nssi))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_closeMultiScan_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_closeMultiScan_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeMultiScan_result& obj);
};

typedef struct _TabletClientService_closeMultiScan_presult__isset {
  _TabletClientService_closeMultiScan_presult__isset() : nssi(false) {}
  bool nssi :1;
} _TabletClientService_closeMultiScan_presult__isset;

class TabletClientService_closeMultiScan_presult {
 public:

  static const char* ascii_fingerprint; // = "2C32A565725135A023CB591D1A993CFD";
  static const uint8_t binary_fingerprint[16]; // = {0x2C,0x32,0xA5,0x65,0x72,0x51,0x35,0xA0,0x23,0xCB,0x59,0x1D,0x1A,0x99,0x3C,0xFD};


  virtual ~TabletClientService_closeMultiScan_presult() throw();
  NoSuchScanIDException nssi;

  _TabletClientService_closeMultiScan_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeMultiScan_presult& obj);
};

typedef struct _TabletClientService_startUpdate_args__isset {
  _TabletClientService_startUpdate_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _TabletClientService_startUpdate_args__isset;

class TabletClientService_startUpdate_args {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};

  TabletClientService_startUpdate_args(const TabletClientService_startUpdate_args&);
  TabletClientService_startUpdate_args& operator=(const TabletClientService_startUpdate_args&);
  TabletClientService_startUpdate_args() {
  }

  virtual ~TabletClientService_startUpdate_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _TabletClientService_startUpdate_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const TabletClientService_startUpdate_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_startUpdate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_startUpdate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startUpdate_args& obj);
};


class TabletClientService_startUpdate_pargs {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};


  virtual ~TabletClientService_startUpdate_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startUpdate_pargs& obj);
};

typedef struct _TabletClientService_startUpdate_result__isset {
  _TabletClientService_startUpdate_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_startUpdate_result__isset;

class TabletClientService_startUpdate_result {
 public:

  static const char* ascii_fingerprint; // = "818A97934A3C4E258585F1C39CCD5F56";
  static const uint8_t binary_fingerprint[16]; // = {0x81,0x8A,0x97,0x93,0x4A,0x3C,0x4E,0x25,0x85,0x85,0xF1,0xC3,0x9C,0xCD,0x5F,0x56};

  TabletClientService_startUpdate_result(const TabletClientService_startUpdate_result&);
  TabletClientService_startUpdate_result& operator=(const TabletClientService_startUpdate_result&);
  TabletClientService_startUpdate_result() : success(0) {
  }

  virtual ~TabletClientService_startUpdate_result() throw();
   ::org::apache::accumulo::core::data::thrift::UpdateID success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_startUpdate_result__isset __isset;

  void __set_success(const  ::org::apache::accumulo::core::data::thrift::UpdateID val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_startUpdate_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_startUpdate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_startUpdate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startUpdate_result& obj);
};

typedef struct _TabletClientService_startUpdate_presult__isset {
  _TabletClientService_startUpdate_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_startUpdate_presult__isset;

class TabletClientService_startUpdate_presult {
 public:

  static const char* ascii_fingerprint; // = "818A97934A3C4E258585F1C39CCD5F56";
  static const uint8_t binary_fingerprint[16]; // = {0x81,0x8A,0x97,0x93,0x4A,0x3C,0x4E,0x25,0x85,0x85,0xF1,0xC3,0x9C,0xCD,0x5F,0x56};


  virtual ~TabletClientService_startUpdate_presult() throw();
   ::org::apache::accumulo::core::data::thrift::UpdateID* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_startUpdate_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startUpdate_presult& obj);
};

typedef struct _TabletClientService_applyUpdates_args__isset {
  _TabletClientService_applyUpdates_args__isset() : tinfo(false), updateID(false), keyExtent(false), mutations(false) {}
  bool tinfo :1;
  bool updateID :1;
  bool keyExtent :1;
  bool mutations :1;
} _TabletClientService_applyUpdates_args__isset;

class TabletClientService_applyUpdates_args {
 public:

  static const char* ascii_fingerprint; // = "130EFC0931F8BF3EC0E86D1F760198D9";
  static const uint8_t binary_fingerprint[16]; // = {0x13,0x0E,0xFC,0x09,0x31,0xF8,0xBF,0x3E,0xC0,0xE8,0x6D,0x1F,0x76,0x01,0x98,0xD9};

  TabletClientService_applyUpdates_args(const TabletClientService_applyUpdates_args&);
  TabletClientService_applyUpdates_args& operator=(const TabletClientService_applyUpdates_args&);
  TabletClientService_applyUpdates_args() : updateID(0) {
  }

  virtual ~TabletClientService_applyUpdates_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::data::thrift::UpdateID updateID;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent keyExtent;
  std::vector< ::org::apache::accumulo::core::data::thrift::TMutation>  mutations;

  _TabletClientService_applyUpdates_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_updateID(const  ::org::apache::accumulo::core::data::thrift::UpdateID val);

  void __set_keyExtent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  void __set_mutations(const std::vector< ::org::apache::accumulo::core::data::thrift::TMutation> & val);

  bool operator == (const TabletClientService_applyUpdates_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(updateID == rhs.updateID))
      return false;
    if (!(keyExtent == rhs.keyExtent))
      return false;
    if (!(mutations == rhs.mutations))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_applyUpdates_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_applyUpdates_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_applyUpdates_args& obj);
};


class TabletClientService_applyUpdates_pargs {
 public:

  static const char* ascii_fingerprint; // = "130EFC0931F8BF3EC0E86D1F760198D9";
  static const uint8_t binary_fingerprint[16]; // = {0x13,0x0E,0xFC,0x09,0x31,0xF8,0xBF,0x3E,0xC0,0xE8,0x6D,0x1F,0x76,0x01,0x98,0xD9};


  virtual ~TabletClientService_applyUpdates_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::data::thrift::UpdateID* updateID;
  const  ::org::apache::accumulo::core::data::thrift::TKeyExtent* keyExtent;
  const std::vector< ::org::apache::accumulo::core::data::thrift::TMutation> * mutations;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_applyUpdates_pargs& obj);
};

typedef struct _TabletClientService_closeUpdate_args__isset {
  _TabletClientService_closeUpdate_args__isset() : tinfo(false), updateID(false) {}
  bool tinfo :1;
  bool updateID :1;
} _TabletClientService_closeUpdate_args__isset;

class TabletClientService_closeUpdate_args {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};

  TabletClientService_closeUpdate_args(const TabletClientService_closeUpdate_args&);
  TabletClientService_closeUpdate_args& operator=(const TabletClientService_closeUpdate_args&);
  TabletClientService_closeUpdate_args() : updateID(0) {
  }

  virtual ~TabletClientService_closeUpdate_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::data::thrift::UpdateID updateID;

  _TabletClientService_closeUpdate_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_updateID(const  ::org::apache::accumulo::core::data::thrift::UpdateID val);

  bool operator == (const TabletClientService_closeUpdate_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(updateID == rhs.updateID))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_closeUpdate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_closeUpdate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeUpdate_args& obj);
};


class TabletClientService_closeUpdate_pargs {
 public:

  static const char* ascii_fingerprint; // = "633FB0A9B6AB43498C5F54D47F45CDE8";
  static const uint8_t binary_fingerprint[16]; // = {0x63,0x3F,0xB0,0xA9,0xB6,0xAB,0x43,0x49,0x8C,0x5F,0x54,0xD4,0x7F,0x45,0xCD,0xE8};


  virtual ~TabletClientService_closeUpdate_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::data::thrift::UpdateID* updateID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeUpdate_pargs& obj);
};

typedef struct _TabletClientService_closeUpdate_result__isset {
  _TabletClientService_closeUpdate_result__isset() : success(false), nssi(false) {}
  bool success :1;
  bool nssi :1;
} _TabletClientService_closeUpdate_result__isset;

class TabletClientService_closeUpdate_result {
 public:

  static const char* ascii_fingerprint; // = "CE03716F3535B054C1C974FFE817F9FF";
  static const uint8_t binary_fingerprint[16]; // = {0xCE,0x03,0x71,0x6F,0x35,0x35,0xB0,0x54,0xC1,0xC9,0x74,0xFF,0xE8,0x17,0xF9,0xFF};

  TabletClientService_closeUpdate_result(const TabletClientService_closeUpdate_result&);
  TabletClientService_closeUpdate_result& operator=(const TabletClientService_closeUpdate_result&);
  TabletClientService_closeUpdate_result() {
  }

  virtual ~TabletClientService_closeUpdate_result() throw();
   ::org::apache::accumulo::core::data::thrift::UpdateErrors success;
  NoSuchScanIDException nssi;

  _TabletClientService_closeUpdate_result__isset __isset;

  void __set_success(const  ::org::apache::accumulo::core::data::thrift::UpdateErrors& val);

  void __set_nssi(const NoSuchScanIDException& val);

  bool operator == (const TabletClientService_closeUpdate_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(nssi == rhs.nssi))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_closeUpdate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_closeUpdate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeUpdate_result& obj);
};

typedef struct _TabletClientService_closeUpdate_presult__isset {
  _TabletClientService_closeUpdate_presult__isset() : success(false), nssi(false) {}
  bool success :1;
  bool nssi :1;
} _TabletClientService_closeUpdate_presult__isset;

class TabletClientService_closeUpdate_presult {
 public:

  static const char* ascii_fingerprint; // = "CE03716F3535B054C1C974FFE817F9FF";
  static const uint8_t binary_fingerprint[16]; // = {0xCE,0x03,0x71,0x6F,0x35,0x35,0xB0,0x54,0xC1,0xC9,0x74,0xFF,0xE8,0x17,0xF9,0xFF};


  virtual ~TabletClientService_closeUpdate_presult() throw();
   ::org::apache::accumulo::core::data::thrift::UpdateErrors* success;
  NoSuchScanIDException nssi;

  _TabletClientService_closeUpdate_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeUpdate_presult& obj);
};

typedef struct _TabletClientService_update_args__isset {
  _TabletClientService_update_args__isset() : tinfo(false), credentials(false), keyExtent(false), mutation(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool keyExtent :1;
  bool mutation :1;
} _TabletClientService_update_args__isset;

class TabletClientService_update_args {
 public:

  static const char* ascii_fingerprint; // = "07EEF3AFC642169E2806C40F961B2453";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0xEE,0xF3,0xAF,0xC6,0x42,0x16,0x9E,0x28,0x06,0xC4,0x0F,0x96,0x1B,0x24,0x53};

  TabletClientService_update_args(const TabletClientService_update_args&);
  TabletClientService_update_args& operator=(const TabletClientService_update_args&);
  TabletClientService_update_args() {
  }

  virtual ~TabletClientService_update_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent keyExtent;
   ::org::apache::accumulo::core::data::thrift::TMutation mutation;

  _TabletClientService_update_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_keyExtent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  void __set_mutation(const  ::org::apache::accumulo::core::data::thrift::TMutation& val);

  bool operator == (const TabletClientService_update_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(keyExtent == rhs.keyExtent))
      return false;
    if (!(mutation == rhs.mutation))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_update_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_update_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_update_args& obj);
};


class TabletClientService_update_pargs {
 public:

  static const char* ascii_fingerprint; // = "07EEF3AFC642169E2806C40F961B2453";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0xEE,0xF3,0xAF,0xC6,0x42,0x16,0x9E,0x28,0x06,0xC4,0x0F,0x96,0x1B,0x24,0x53};


  virtual ~TabletClientService_update_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const  ::org::apache::accumulo::core::data::thrift::TKeyExtent* keyExtent;
  const  ::org::apache::accumulo::core::data::thrift::TMutation* mutation;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_update_pargs& obj);
};

typedef struct _TabletClientService_update_result__isset {
  _TabletClientService_update_result__isset() : sec(false), nste(false), cve(false) {}
  bool sec :1;
  bool nste :1;
  bool cve :1;
} _TabletClientService_update_result__isset;

class TabletClientService_update_result {
 public:

  static const char* ascii_fingerprint; // = "67B41DCB8C94BD91159CDFCEB986535B";
  static const uint8_t binary_fingerprint[16]; // = {0x67,0xB4,0x1D,0xCB,0x8C,0x94,0xBD,0x91,0x15,0x9C,0xDF,0xCE,0xB9,0x86,0x53,0x5B};

  TabletClientService_update_result(const TabletClientService_update_result&);
  TabletClientService_update_result& operator=(const TabletClientService_update_result&);
  TabletClientService_update_result() {
  }

  virtual ~TabletClientService_update_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
  NotServingTabletException nste;
  ConstraintViolationException cve;

  _TabletClientService_update_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_nste(const NotServingTabletException& val);

  void __set_cve(const ConstraintViolationException& val);

  bool operator == (const TabletClientService_update_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(nste == rhs.nste))
      return false;
    if (!(cve == rhs.cve))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_update_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_update_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_update_result& obj);
};

typedef struct _TabletClientService_update_presult__isset {
  _TabletClientService_update_presult__isset() : sec(false), nste(false), cve(false) {}
  bool sec :1;
  bool nste :1;
  bool cve :1;
} _TabletClientService_update_presult__isset;

class TabletClientService_update_presult {
 public:

  static const char* ascii_fingerprint; // = "67B41DCB8C94BD91159CDFCEB986535B";
  static const uint8_t binary_fingerprint[16]; // = {0x67,0xB4,0x1D,0xCB,0x8C,0x94,0xBD,0x91,0x15,0x9C,0xDF,0xCE,0xB9,0x86,0x53,0x5B};


  virtual ~TabletClientService_update_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
  NotServingTabletException nste;
  ConstraintViolationException cve;

  _TabletClientService_update_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_update_presult& obj);
};

typedef struct _TabletClientService_startConditionalUpdate_args__isset {
  _TabletClientService_startConditionalUpdate_args__isset() : tinfo(false), credentials(false), authorizations(false), tableID(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool authorizations :1;
  bool tableID :1;
} _TabletClientService_startConditionalUpdate_args__isset;

class TabletClientService_startConditionalUpdate_args {
 public:

  static const char* ascii_fingerprint; // = "00A4E10F59663FA810208BC9C6964137";
  static const uint8_t binary_fingerprint[16]; // = {0x00,0xA4,0xE1,0x0F,0x59,0x66,0x3F,0xA8,0x10,0x20,0x8B,0xC9,0xC6,0x96,0x41,0x37};

  TabletClientService_startConditionalUpdate_args(const TabletClientService_startConditionalUpdate_args&);
  TabletClientService_startConditionalUpdate_args& operator=(const TabletClientService_startConditionalUpdate_args&);
  TabletClientService_startConditionalUpdate_args() : tableID() {
  }

  virtual ~TabletClientService_startConditionalUpdate_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::vector<std::string>  authorizations;
  std::string tableID;

  _TabletClientService_startConditionalUpdate_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_authorizations(const std::vector<std::string> & val);

  void __set_tableID(const std::string& val);

  bool operator == (const TabletClientService_startConditionalUpdate_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(authorizations == rhs.authorizations))
      return false;
    if (!(tableID == rhs.tableID))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_startConditionalUpdate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_startConditionalUpdate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startConditionalUpdate_args& obj);
};


class TabletClientService_startConditionalUpdate_pargs {
 public:

  static const char* ascii_fingerprint; // = "00A4E10F59663FA810208BC9C6964137";
  static const uint8_t binary_fingerprint[16]; // = {0x00,0xA4,0xE1,0x0F,0x59,0x66,0x3F,0xA8,0x10,0x20,0x8B,0xC9,0xC6,0x96,0x41,0x37};


  virtual ~TabletClientService_startConditionalUpdate_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::vector<std::string> * authorizations;
  const std::string* tableID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startConditionalUpdate_pargs& obj);
};

typedef struct _TabletClientService_startConditionalUpdate_result__isset {
  _TabletClientService_startConditionalUpdate_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_startConditionalUpdate_result__isset;

class TabletClientService_startConditionalUpdate_result {
 public:

  static const char* ascii_fingerprint; // = "26C3BBE8E5C61DAD39D37B463E6206D5";
  static const uint8_t binary_fingerprint[16]; // = {0x26,0xC3,0xBB,0xE8,0xE5,0xC6,0x1D,0xAD,0x39,0xD3,0x7B,0x46,0x3E,0x62,0x06,0xD5};

  TabletClientService_startConditionalUpdate_result(const TabletClientService_startConditionalUpdate_result&);
  TabletClientService_startConditionalUpdate_result& operator=(const TabletClientService_startConditionalUpdate_result&);
  TabletClientService_startConditionalUpdate_result() {
  }

  virtual ~TabletClientService_startConditionalUpdate_result() throw();
   ::org::apache::accumulo::core::data::thrift::TConditionalSession success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_startConditionalUpdate_result__isset __isset;

  void __set_success(const  ::org::apache::accumulo::core::data::thrift::TConditionalSession& val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_startConditionalUpdate_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_startConditionalUpdate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_startConditionalUpdate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startConditionalUpdate_result& obj);
};

typedef struct _TabletClientService_startConditionalUpdate_presult__isset {
  _TabletClientService_startConditionalUpdate_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_startConditionalUpdate_presult__isset;

class TabletClientService_startConditionalUpdate_presult {
 public:

  static const char* ascii_fingerprint; // = "26C3BBE8E5C61DAD39D37B463E6206D5";
  static const uint8_t binary_fingerprint[16]; // = {0x26,0xC3,0xBB,0xE8,0xE5,0xC6,0x1D,0xAD,0x39,0xD3,0x7B,0x46,0x3E,0x62,0x06,0xD5};


  virtual ~TabletClientService_startConditionalUpdate_presult() throw();
   ::org::apache::accumulo::core::data::thrift::TConditionalSession* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_startConditionalUpdate_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_startConditionalUpdate_presult& obj);
};

typedef struct _TabletClientService_conditionalUpdate_args__isset {
  _TabletClientService_conditionalUpdate_args__isset() : tinfo(false), sessID(false), mutations(false), symbols(false) {}
  bool tinfo :1;
  bool sessID :1;
  bool mutations :1;
  bool symbols :1;
} _TabletClientService_conditionalUpdate_args__isset;

class TabletClientService_conditionalUpdate_args {
 public:

  static const char* ascii_fingerprint; // = "5BE736D1DFB95712D44BBFFB57336155";
  static const uint8_t binary_fingerprint[16]; // = {0x5B,0xE7,0x36,0xD1,0xDF,0xB9,0x57,0x12,0xD4,0x4B,0xBF,0xFB,0x57,0x33,0x61,0x55};

  TabletClientService_conditionalUpdate_args(const TabletClientService_conditionalUpdate_args&);
  TabletClientService_conditionalUpdate_args& operator=(const TabletClientService_conditionalUpdate_args&);
  TabletClientService_conditionalUpdate_args() : sessID(0) {
  }

  virtual ~TabletClientService_conditionalUpdate_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::data::thrift::UpdateID sessID;
   ::org::apache::accumulo::core::data::thrift::CMBatch mutations;
  std::vector<std::string>  symbols;

  _TabletClientService_conditionalUpdate_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_sessID(const  ::org::apache::accumulo::core::data::thrift::UpdateID val);

  void __set_mutations(const  ::org::apache::accumulo::core::data::thrift::CMBatch& val);

  void __set_symbols(const std::vector<std::string> & val);

  bool operator == (const TabletClientService_conditionalUpdate_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(sessID == rhs.sessID))
      return false;
    if (!(mutations == rhs.mutations))
      return false;
    if (!(symbols == rhs.symbols))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_conditionalUpdate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_conditionalUpdate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_conditionalUpdate_args& obj);
};


class TabletClientService_conditionalUpdate_pargs {
 public:

  static const char* ascii_fingerprint; // = "5BE736D1DFB95712D44BBFFB57336155";
  static const uint8_t binary_fingerprint[16]; // = {0x5B,0xE7,0x36,0xD1,0xDF,0xB9,0x57,0x12,0xD4,0x4B,0xBF,0xFB,0x57,0x33,0x61,0x55};


  virtual ~TabletClientService_conditionalUpdate_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::data::thrift::UpdateID* sessID;
  const  ::org::apache::accumulo::core::data::thrift::CMBatch* mutations;
  const std::vector<std::string> * symbols;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_conditionalUpdate_pargs& obj);
};

typedef struct _TabletClientService_conditionalUpdate_result__isset {
  _TabletClientService_conditionalUpdate_result__isset() : success(false), nssi(false) {}
  bool success :1;
  bool nssi :1;
} _TabletClientService_conditionalUpdate_result__isset;

class TabletClientService_conditionalUpdate_result {
 public:

  static const char* ascii_fingerprint; // = "3CA9486E799766B253FD434AED41DA5D";
  static const uint8_t binary_fingerprint[16]; // = {0x3C,0xA9,0x48,0x6E,0x79,0x97,0x66,0xB2,0x53,0xFD,0x43,0x4A,0xED,0x41,0xDA,0x5D};

  TabletClientService_conditionalUpdate_result(const TabletClientService_conditionalUpdate_result&);
  TabletClientService_conditionalUpdate_result& operator=(const TabletClientService_conditionalUpdate_result&);
  TabletClientService_conditionalUpdate_result() {
  }

  virtual ~TabletClientService_conditionalUpdate_result() throw();
  std::vector< ::org::apache::accumulo::core::data::thrift::TCMResult>  success;
  NoSuchScanIDException nssi;

  _TabletClientService_conditionalUpdate_result__isset __isset;

  void __set_success(const std::vector< ::org::apache::accumulo::core::data::thrift::TCMResult> & val);

  void __set_nssi(const NoSuchScanIDException& val);

  bool operator == (const TabletClientService_conditionalUpdate_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(nssi == rhs.nssi))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_conditionalUpdate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_conditionalUpdate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_conditionalUpdate_result& obj);
};

typedef struct _TabletClientService_conditionalUpdate_presult__isset {
  _TabletClientService_conditionalUpdate_presult__isset() : success(false), nssi(false) {}
  bool success :1;
  bool nssi :1;
} _TabletClientService_conditionalUpdate_presult__isset;

class TabletClientService_conditionalUpdate_presult {
 public:

  static const char* ascii_fingerprint; // = "3CA9486E799766B253FD434AED41DA5D";
  static const uint8_t binary_fingerprint[16]; // = {0x3C,0xA9,0x48,0x6E,0x79,0x97,0x66,0xB2,0x53,0xFD,0x43,0x4A,0xED,0x41,0xDA,0x5D};


  virtual ~TabletClientService_conditionalUpdate_presult() throw();
  std::vector< ::org::apache::accumulo::core::data::thrift::TCMResult> * success;
  NoSuchScanIDException nssi;

  _TabletClientService_conditionalUpdate_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_conditionalUpdate_presult& obj);
};

typedef struct _TabletClientService_invalidateConditionalUpdate_args__isset {
  _TabletClientService_invalidateConditionalUpdate_args__isset() : tinfo(false), sessID(false) {}
  bool tinfo :1;
  bool sessID :1;
} _TabletClientService_invalidateConditionalUpdate_args__isset;

class TabletClientService_invalidateConditionalUpdate_args {
 public:

  static const char* ascii_fingerprint; // = "91E7F93A0F3914A8D24DBAECBD84A0A6";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0xE7,0xF9,0x3A,0x0F,0x39,0x14,0xA8,0xD2,0x4D,0xBA,0xEC,0xBD,0x84,0xA0,0xA6};

  TabletClientService_invalidateConditionalUpdate_args(const TabletClientService_invalidateConditionalUpdate_args&);
  TabletClientService_invalidateConditionalUpdate_args& operator=(const TabletClientService_invalidateConditionalUpdate_args&);
  TabletClientService_invalidateConditionalUpdate_args() : sessID(0) {
  }

  virtual ~TabletClientService_invalidateConditionalUpdate_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::data::thrift::UpdateID sessID;

  _TabletClientService_invalidateConditionalUpdate_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_sessID(const  ::org::apache::accumulo::core::data::thrift::UpdateID val);

  bool operator == (const TabletClientService_invalidateConditionalUpdate_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(sessID == rhs.sessID))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_invalidateConditionalUpdate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_invalidateConditionalUpdate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_invalidateConditionalUpdate_args& obj);
};


class TabletClientService_invalidateConditionalUpdate_pargs {
 public:

  static const char* ascii_fingerprint; // = "91E7F93A0F3914A8D24DBAECBD84A0A6";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0xE7,0xF9,0x3A,0x0F,0x39,0x14,0xA8,0xD2,0x4D,0xBA,0xEC,0xBD,0x84,0xA0,0xA6};


  virtual ~TabletClientService_invalidateConditionalUpdate_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::data::thrift::UpdateID* sessID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_invalidateConditionalUpdate_pargs& obj);
};


class TabletClientService_invalidateConditionalUpdate_result {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  TabletClientService_invalidateConditionalUpdate_result(const TabletClientService_invalidateConditionalUpdate_result&);
  TabletClientService_invalidateConditionalUpdate_result& operator=(const TabletClientService_invalidateConditionalUpdate_result&);
  TabletClientService_invalidateConditionalUpdate_result() {
  }

  virtual ~TabletClientService_invalidateConditionalUpdate_result() throw();

  bool operator == (const TabletClientService_invalidateConditionalUpdate_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const TabletClientService_invalidateConditionalUpdate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_invalidateConditionalUpdate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_invalidateConditionalUpdate_result& obj);
};


class TabletClientService_invalidateConditionalUpdate_presult {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~TabletClientService_invalidateConditionalUpdate_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_invalidateConditionalUpdate_presult& obj);
};

typedef struct _TabletClientService_closeConditionalUpdate_args__isset {
  _TabletClientService_closeConditionalUpdate_args__isset() : tinfo(false), sessID(false) {}
  bool tinfo :1;
  bool sessID :1;
} _TabletClientService_closeConditionalUpdate_args__isset;

class TabletClientService_closeConditionalUpdate_args {
 public:

  static const char* ascii_fingerprint; // = "91E7F93A0F3914A8D24DBAECBD84A0A6";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0xE7,0xF9,0x3A,0x0F,0x39,0x14,0xA8,0xD2,0x4D,0xBA,0xEC,0xBD,0x84,0xA0,0xA6};

  TabletClientService_closeConditionalUpdate_args(const TabletClientService_closeConditionalUpdate_args&);
  TabletClientService_closeConditionalUpdate_args& operator=(const TabletClientService_closeConditionalUpdate_args&);
  TabletClientService_closeConditionalUpdate_args() : sessID(0) {
  }

  virtual ~TabletClientService_closeConditionalUpdate_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::data::thrift::UpdateID sessID;

  _TabletClientService_closeConditionalUpdate_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_sessID(const  ::org::apache::accumulo::core::data::thrift::UpdateID val);

  bool operator == (const TabletClientService_closeConditionalUpdate_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(sessID == rhs.sessID))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_closeConditionalUpdate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_closeConditionalUpdate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeConditionalUpdate_args& obj);
};


class TabletClientService_closeConditionalUpdate_pargs {
 public:

  static const char* ascii_fingerprint; // = "91E7F93A0F3914A8D24DBAECBD84A0A6";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0xE7,0xF9,0x3A,0x0F,0x39,0x14,0xA8,0xD2,0x4D,0xBA,0xEC,0xBD,0x84,0xA0,0xA6};


  virtual ~TabletClientService_closeConditionalUpdate_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::data::thrift::UpdateID* sessID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_closeConditionalUpdate_pargs& obj);
};

typedef struct _TabletClientService_bulkImport_args__isset {
  _TabletClientService_bulkImport_args__isset() : tinfo(false), credentials(false), tid(false), files(false), setTime(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tid :1;
  bool files :1;
  bool setTime :1;
} _TabletClientService_bulkImport_args__isset;

class TabletClientService_bulkImport_args {
 public:

  static const char* ascii_fingerprint; // = "F2F59BDB7741BE6062B004405272FA78";
  static const uint8_t binary_fingerprint[16]; // = {0xF2,0xF5,0x9B,0xDB,0x77,0x41,0xBE,0x60,0x62,0xB0,0x04,0x40,0x52,0x72,0xFA,0x78};

  TabletClientService_bulkImport_args(const TabletClientService_bulkImport_args&);
  TabletClientService_bulkImport_args& operator=(const TabletClientService_bulkImport_args&);
  TabletClientService_bulkImport_args() : tid(0), setTime(0) {
  }

  virtual ~TabletClientService_bulkImport_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  int64_t tid;
   ::org::apache::accumulo::core::data::thrift::TabletFiles files;
  bool setTime;

  _TabletClientService_bulkImport_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tid(const int64_t val);

  void __set_files(const  ::org::apache::accumulo::core::data::thrift::TabletFiles& val);

  void __set_setTime(const bool val);

  bool operator == (const TabletClientService_bulkImport_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tid == rhs.tid))
      return false;
    if (!(files == rhs.files))
      return false;
    if (!(setTime == rhs.setTime))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_bulkImport_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_bulkImport_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_bulkImport_args& obj);
};


class TabletClientService_bulkImport_pargs {
 public:

  static const char* ascii_fingerprint; // = "F2F59BDB7741BE6062B004405272FA78";
  static const uint8_t binary_fingerprint[16]; // = {0xF2,0xF5,0x9B,0xDB,0x77,0x41,0xBE,0x60,0x62,0xB0,0x04,0x40,0x52,0x72,0xFA,0x78};


  virtual ~TabletClientService_bulkImport_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const int64_t* tid;
  const  ::org::apache::accumulo::core::data::thrift::TabletFiles* files;
  const bool* setTime;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_bulkImport_pargs& obj);
};

typedef struct _TabletClientService_bulkImport_result__isset {
  _TabletClientService_bulkImport_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_bulkImport_result__isset;

class TabletClientService_bulkImport_result {
 public:

  static const char* ascii_fingerprint; // = "5B94D0AAF81BFB3FD6B1CFB0FFBF5972";
  static const uint8_t binary_fingerprint[16]; // = {0x5B,0x94,0xD0,0xAA,0xF8,0x1B,0xFB,0x3F,0xD6,0xB1,0xCF,0xB0,0xFF,0xBF,0x59,0x72};

  TabletClientService_bulkImport_result(const TabletClientService_bulkImport_result&);
  TabletClientService_bulkImport_result& operator=(const TabletClientService_bulkImport_result&);
  TabletClientService_bulkImport_result() {
  }

  virtual ~TabletClientService_bulkImport_result() throw();
  std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent>  success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_bulkImport_result__isset __isset;

  void __set_success(const std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent> & val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_bulkImport_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_bulkImport_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_bulkImport_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_bulkImport_result& obj);
};

typedef struct _TabletClientService_bulkImport_presult__isset {
  _TabletClientService_bulkImport_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_bulkImport_presult__isset;

class TabletClientService_bulkImport_presult {
 public:

  static const char* ascii_fingerprint; // = "5B94D0AAF81BFB3FD6B1CFB0FFBF5972";
  static const uint8_t binary_fingerprint[16]; // = {0x5B,0x94,0xD0,0xAA,0xF8,0x1B,0xFB,0x3F,0xD6,0xB1,0xCF,0xB0,0xFF,0xBF,0x59,0x72};


  virtual ~TabletClientService_bulkImport_presult() throw();
  std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent> * success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_bulkImport_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_bulkImport_presult& obj);
};

typedef struct _TabletClientService_splitTablet_args__isset {
  _TabletClientService_splitTablet_args__isset() : tinfo(false), credentials(false), extent(false), splitPoint(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool extent :1;
  bool splitPoint :1;
} _TabletClientService_splitTablet_args__isset;

class TabletClientService_splitTablet_args {
 public:

  static const char* ascii_fingerprint; // = "CADFECC97EB7B4491C3E53E5BC5AF146";
  static const uint8_t binary_fingerprint[16]; // = {0xCA,0xDF,0xEC,0xC9,0x7E,0xB7,0xB4,0x49,0x1C,0x3E,0x53,0xE5,0xBC,0x5A,0xF1,0x46};

  TabletClientService_splitTablet_args(const TabletClientService_splitTablet_args&);
  TabletClientService_splitTablet_args& operator=(const TabletClientService_splitTablet_args&);
  TabletClientService_splitTablet_args() : splitPoint() {
  }

  virtual ~TabletClientService_splitTablet_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;
  std::string splitPoint;

  _TabletClientService_splitTablet_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  void __set_splitPoint(const std::string& val);

  bool operator == (const TabletClientService_splitTablet_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(extent == rhs.extent))
      return false;
    if (!(splitPoint == rhs.splitPoint))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_splitTablet_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_splitTablet_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_splitTablet_args& obj);
};


class TabletClientService_splitTablet_pargs {
 public:

  static const char* ascii_fingerprint; // = "CADFECC97EB7B4491C3E53E5BC5AF146";
  static const uint8_t binary_fingerprint[16]; // = {0xCA,0xDF,0xEC,0xC9,0x7E,0xB7,0xB4,0x49,0x1C,0x3E,0x53,0xE5,0xBC,0x5A,0xF1,0x46};


  virtual ~TabletClientService_splitTablet_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const  ::org::apache::accumulo::core::data::thrift::TKeyExtent* extent;
  const std::string* splitPoint;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_splitTablet_pargs& obj);
};

typedef struct _TabletClientService_splitTablet_result__isset {
  _TabletClientService_splitTablet_result__isset() : sec(false), nste(false) {}
  bool sec :1;
  bool nste :1;
} _TabletClientService_splitTablet_result__isset;

class TabletClientService_splitTablet_result {
 public:

  static const char* ascii_fingerprint; // = "26B89C54F808FB5D87E6ECEA638B8094";
  static const uint8_t binary_fingerprint[16]; // = {0x26,0xB8,0x9C,0x54,0xF8,0x08,0xFB,0x5D,0x87,0xE6,0xEC,0xEA,0x63,0x8B,0x80,0x94};

  TabletClientService_splitTablet_result(const TabletClientService_splitTablet_result&);
  TabletClientService_splitTablet_result& operator=(const TabletClientService_splitTablet_result&);
  TabletClientService_splitTablet_result() {
  }

  virtual ~TabletClientService_splitTablet_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
  NotServingTabletException nste;

  _TabletClientService_splitTablet_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  void __set_nste(const NotServingTabletException& val);

  bool operator == (const TabletClientService_splitTablet_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    if (!(nste == rhs.nste))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_splitTablet_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_splitTablet_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_splitTablet_result& obj);
};

typedef struct _TabletClientService_splitTablet_presult__isset {
  _TabletClientService_splitTablet_presult__isset() : sec(false), nste(false) {}
  bool sec :1;
  bool nste :1;
} _TabletClientService_splitTablet_presult__isset;

class TabletClientService_splitTablet_presult {
 public:

  static const char* ascii_fingerprint; // = "26B89C54F808FB5D87E6ECEA638B8094";
  static const uint8_t binary_fingerprint[16]; // = {0x26,0xB8,0x9C,0x54,0xF8,0x08,0xFB,0x5D,0x87,0xE6,0xEC,0xEA,0x63,0x8B,0x80,0x94};


  virtual ~TabletClientService_splitTablet_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;
  NotServingTabletException nste;

  _TabletClientService_splitTablet_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_splitTablet_presult& obj);
};

typedef struct _TabletClientService_loadTablet_args__isset {
  _TabletClientService_loadTablet_args__isset() : tinfo(false), credentials(false), lock(false), extent(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool lock :1;
  bool extent :1;
} _TabletClientService_loadTablet_args__isset;

class TabletClientService_loadTablet_args {
 public:

  static const char* ascii_fingerprint; // = "390EA21384A9C935F272E9B52858E750";
  static const uint8_t binary_fingerprint[16]; // = {0x39,0x0E,0xA2,0x13,0x84,0xA9,0xC9,0x35,0xF2,0x72,0xE9,0xB5,0x28,0x58,0xE7,0x50};

  TabletClientService_loadTablet_args(const TabletClientService_loadTablet_args&);
  TabletClientService_loadTablet_args& operator=(const TabletClientService_loadTablet_args&);
  TabletClientService_loadTablet_args() : lock() {
  }

  virtual ~TabletClientService_loadTablet_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string lock;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;

  _TabletClientService_loadTablet_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_lock(const std::string& val);

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  bool operator == (const TabletClientService_loadTablet_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(lock == rhs.lock))
      return false;
    if (!(extent == rhs.extent))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_loadTablet_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_loadTablet_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_loadTablet_args& obj);
};


class TabletClientService_loadTablet_pargs {
 public:

  static const char* ascii_fingerprint; // = "390EA21384A9C935F272E9B52858E750";
  static const uint8_t binary_fingerprint[16]; // = {0x39,0x0E,0xA2,0x13,0x84,0xA9,0xC9,0x35,0xF2,0x72,0xE9,0xB5,0x28,0x58,0xE7,0x50};


  virtual ~TabletClientService_loadTablet_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* lock;
  const  ::org::apache::accumulo::core::data::thrift::TKeyExtent* extent;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_loadTablet_pargs& obj);
};

typedef struct _TabletClientService_unloadTablet_args__isset {
  _TabletClientService_unloadTablet_args__isset() : tinfo(false), credentials(false), lock(false), extent(false), save(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool lock :1;
  bool extent :1;
  bool save :1;
} _TabletClientService_unloadTablet_args__isset;

class TabletClientService_unloadTablet_args {
 public:

  static const char* ascii_fingerprint; // = "626B4A4039226430D49DB852FFC0B31B";
  static const uint8_t binary_fingerprint[16]; // = {0x62,0x6B,0x4A,0x40,0x39,0x22,0x64,0x30,0xD4,0x9D,0xB8,0x52,0xFF,0xC0,0xB3,0x1B};

  TabletClientService_unloadTablet_args(const TabletClientService_unloadTablet_args&);
  TabletClientService_unloadTablet_args& operator=(const TabletClientService_unloadTablet_args&);
  TabletClientService_unloadTablet_args() : lock(), save(0) {
  }

  virtual ~TabletClientService_unloadTablet_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string lock;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;
  bool save;

  _TabletClientService_unloadTablet_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_lock(const std::string& val);

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  void __set_save(const bool val);

  bool operator == (const TabletClientService_unloadTablet_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(lock == rhs.lock))
      return false;
    if (!(extent == rhs.extent))
      return false;
    if (!(save == rhs.save))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_unloadTablet_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_unloadTablet_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_unloadTablet_args& obj);
};


class TabletClientService_unloadTablet_pargs {
 public:

  static const char* ascii_fingerprint; // = "626B4A4039226430D49DB852FFC0B31B";
  static const uint8_t binary_fingerprint[16]; // = {0x62,0x6B,0x4A,0x40,0x39,0x22,0x64,0x30,0xD4,0x9D,0xB8,0x52,0xFF,0xC0,0xB3,0x1B};


  virtual ~TabletClientService_unloadTablet_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* lock;
  const  ::org::apache::accumulo::core::data::thrift::TKeyExtent* extent;
  const bool* save;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_unloadTablet_pargs& obj);
};

typedef struct _TabletClientService_flush_args__isset {
  _TabletClientService_flush_args__isset() : tinfo(false), credentials(false), lock(false), tableId(false), startRow(false), endRow(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool lock :1;
  bool tableId :1;
  bool startRow :1;
  bool endRow :1;
} _TabletClientService_flush_args__isset;

class TabletClientService_flush_args {
 public:

  static const char* ascii_fingerprint; // = "FDD99EA6F273BCEABE422F631D4D2A17";
  static const uint8_t binary_fingerprint[16]; // = {0xFD,0xD9,0x9E,0xA6,0xF2,0x73,0xBC,0xEA,0xBE,0x42,0x2F,0x63,0x1D,0x4D,0x2A,0x17};

  TabletClientService_flush_args(const TabletClientService_flush_args&);
  TabletClientService_flush_args& operator=(const TabletClientService_flush_args&);
  TabletClientService_flush_args() : lock(), tableId(), startRow(), endRow() {
  }

  virtual ~TabletClientService_flush_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string lock;
  std::string tableId;
  std::string startRow;
  std::string endRow;

  _TabletClientService_flush_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_lock(const std::string& val);

  void __set_tableId(const std::string& val);

  void __set_startRow(const std::string& val);

  void __set_endRow(const std::string& val);

  bool operator == (const TabletClientService_flush_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(lock == rhs.lock))
      return false;
    if (!(tableId == rhs.tableId))
      return false;
    if (!(startRow == rhs.startRow))
      return false;
    if (!(endRow == rhs.endRow))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_flush_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_flush_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_flush_args& obj);
};


class TabletClientService_flush_pargs {
 public:

  static const char* ascii_fingerprint; // = "FDD99EA6F273BCEABE422F631D4D2A17";
  static const uint8_t binary_fingerprint[16]; // = {0xFD,0xD9,0x9E,0xA6,0xF2,0x73,0xBC,0xEA,0xBE,0x42,0x2F,0x63,0x1D,0x4D,0x2A,0x17};


  virtual ~TabletClientService_flush_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* lock;
  const std::string* tableId;
  const std::string* startRow;
  const std::string* endRow;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_flush_pargs& obj);
};

typedef struct _TabletClientService_flushTablet_args__isset {
  _TabletClientService_flushTablet_args__isset() : tinfo(false), credentials(false), lock(false), extent(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool lock :1;
  bool extent :1;
} _TabletClientService_flushTablet_args__isset;

class TabletClientService_flushTablet_args {
 public:

  static const char* ascii_fingerprint; // = "85B88899FF5AB6116AE04613FB63C3A4";
  static const uint8_t binary_fingerprint[16]; // = {0x85,0xB8,0x88,0x99,0xFF,0x5A,0xB6,0x11,0x6A,0xE0,0x46,0x13,0xFB,0x63,0xC3,0xA4};

  TabletClientService_flushTablet_args(const TabletClientService_flushTablet_args&);
  TabletClientService_flushTablet_args& operator=(const TabletClientService_flushTablet_args&);
  TabletClientService_flushTablet_args() : lock() {
  }

  virtual ~TabletClientService_flushTablet_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string lock;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;

  _TabletClientService_flushTablet_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_lock(const std::string& val);

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  bool operator == (const TabletClientService_flushTablet_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(lock == rhs.lock))
      return false;
    if (!(extent == rhs.extent))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_flushTablet_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_flushTablet_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_flushTablet_args& obj);
};


class TabletClientService_flushTablet_pargs {
 public:

  static const char* ascii_fingerprint; // = "85B88899FF5AB6116AE04613FB63C3A4";
  static const uint8_t binary_fingerprint[16]; // = {0x85,0xB8,0x88,0x99,0xFF,0x5A,0xB6,0x11,0x6A,0xE0,0x46,0x13,0xFB,0x63,0xC3,0xA4};


  virtual ~TabletClientService_flushTablet_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* lock;
  const  ::org::apache::accumulo::core::data::thrift::TKeyExtent* extent;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_flushTablet_pargs& obj);
};

typedef struct _TabletClientService_chop_args__isset {
  _TabletClientService_chop_args__isset() : tinfo(false), credentials(false), lock(false), extent(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool lock :1;
  bool extent :1;
} _TabletClientService_chop_args__isset;

class TabletClientService_chop_args {
 public:

  static const char* ascii_fingerprint; // = "85B88899FF5AB6116AE04613FB63C3A4";
  static const uint8_t binary_fingerprint[16]; // = {0x85,0xB8,0x88,0x99,0xFF,0x5A,0xB6,0x11,0x6A,0xE0,0x46,0x13,0xFB,0x63,0xC3,0xA4};

  TabletClientService_chop_args(const TabletClientService_chop_args&);
  TabletClientService_chop_args& operator=(const TabletClientService_chop_args&);
  TabletClientService_chop_args() : lock() {
  }

  virtual ~TabletClientService_chop_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string lock;
   ::org::apache::accumulo::core::data::thrift::TKeyExtent extent;

  _TabletClientService_chop_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_lock(const std::string& val);

  void __set_extent(const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& val);

  bool operator == (const TabletClientService_chop_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(lock == rhs.lock))
      return false;
    if (!(extent == rhs.extent))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_chop_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_chop_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_chop_args& obj);
};


class TabletClientService_chop_pargs {
 public:

  static const char* ascii_fingerprint; // = "85B88899FF5AB6116AE04613FB63C3A4";
  static const uint8_t binary_fingerprint[16]; // = {0x85,0xB8,0x88,0x99,0xFF,0x5A,0xB6,0x11,0x6A,0xE0,0x46,0x13,0xFB,0x63,0xC3,0xA4};


  virtual ~TabletClientService_chop_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* lock;
  const  ::org::apache::accumulo::core::data::thrift::TKeyExtent* extent;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_chop_pargs& obj);
};

typedef struct _TabletClientService_compact_args__isset {
  _TabletClientService_compact_args__isset() : tinfo(false), credentials(false), lock(false), tableId(false), startRow(false), endRow(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool lock :1;
  bool tableId :1;
  bool startRow :1;
  bool endRow :1;
} _TabletClientService_compact_args__isset;

class TabletClientService_compact_args {
 public:

  static const char* ascii_fingerprint; // = "5E9BA0D13245E9D9F70450F9BB355692";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0x9B,0xA0,0xD1,0x32,0x45,0xE9,0xD9,0xF7,0x04,0x50,0xF9,0xBB,0x35,0x56,0x92};

  TabletClientService_compact_args(const TabletClientService_compact_args&);
  TabletClientService_compact_args& operator=(const TabletClientService_compact_args&);
  TabletClientService_compact_args() : lock(), tableId(), startRow(), endRow() {
  }

  virtual ~TabletClientService_compact_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string lock;
  std::string tableId;
  std::string startRow;
  std::string endRow;

  _TabletClientService_compact_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_lock(const std::string& val);

  void __set_tableId(const std::string& val);

  void __set_startRow(const std::string& val);

  void __set_endRow(const std::string& val);

  bool operator == (const TabletClientService_compact_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(lock == rhs.lock))
      return false;
    if (!(tableId == rhs.tableId))
      return false;
    if (!(startRow == rhs.startRow))
      return false;
    if (!(endRow == rhs.endRow))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_compact_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_compact_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_compact_args& obj);
};


class TabletClientService_compact_pargs {
 public:

  static const char* ascii_fingerprint; // = "5E9BA0D13245E9D9F70450F9BB355692";
  static const uint8_t binary_fingerprint[16]; // = {0x5E,0x9B,0xA0,0xD1,0x32,0x45,0xE9,0xD9,0xF7,0x04,0x50,0xF9,0xBB,0x35,0x56,0x92};


  virtual ~TabletClientService_compact_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* lock;
  const std::string* tableId;
  const std::string* startRow;
  const std::string* endRow;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_compact_pargs& obj);
};

typedef struct _TabletClientService_getTabletServerStatus_args__isset {
  _TabletClientService_getTabletServerStatus_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _TabletClientService_getTabletServerStatus_args__isset;

class TabletClientService_getTabletServerStatus_args {
 public:

  static const char* ascii_fingerprint; // = "B9B3A1DED3F4B408BF5E649A391FFD0D";
  static const uint8_t binary_fingerprint[16]; // = {0xB9,0xB3,0xA1,0xDE,0xD3,0xF4,0xB4,0x08,0xBF,0x5E,0x64,0x9A,0x39,0x1F,0xFD,0x0D};

  TabletClientService_getTabletServerStatus_args(const TabletClientService_getTabletServerStatus_args&);
  TabletClientService_getTabletServerStatus_args& operator=(const TabletClientService_getTabletServerStatus_args&);
  TabletClientService_getTabletServerStatus_args() {
  }

  virtual ~TabletClientService_getTabletServerStatus_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _TabletClientService_getTabletServerStatus_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const TabletClientService_getTabletServerStatus_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getTabletServerStatus_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getTabletServerStatus_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getTabletServerStatus_args& obj);
};


class TabletClientService_getTabletServerStatus_pargs {
 public:

  static const char* ascii_fingerprint; // = "B9B3A1DED3F4B408BF5E649A391FFD0D";
  static const uint8_t binary_fingerprint[16]; // = {0xB9,0xB3,0xA1,0xDE,0xD3,0xF4,0xB4,0x08,0xBF,0x5E,0x64,0x9A,0x39,0x1F,0xFD,0x0D};


  virtual ~TabletClientService_getTabletServerStatus_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getTabletServerStatus_pargs& obj);
};

typedef struct _TabletClientService_getTabletServerStatus_result__isset {
  _TabletClientService_getTabletServerStatus_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getTabletServerStatus_result__isset;

class TabletClientService_getTabletServerStatus_result {
 public:

  static const char* ascii_fingerprint; // = "BFF7CCABA4BDAD79047A219A4A18E8CF";
  static const uint8_t binary_fingerprint[16]; // = {0xBF,0xF7,0xCC,0xAB,0xA4,0xBD,0xAD,0x79,0x04,0x7A,0x21,0x9A,0x4A,0x18,0xE8,0xCF};

  TabletClientService_getTabletServerStatus_result(const TabletClientService_getTabletServerStatus_result&);
  TabletClientService_getTabletServerStatus_result& operator=(const TabletClientService_getTabletServerStatus_result&);
  TabletClientService_getTabletServerStatus_result() {
  }

  virtual ~TabletClientService_getTabletServerStatus_result() throw();
   ::org::apache::accumulo::core::master::thrift::TabletServerStatus success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getTabletServerStatus_result__isset __isset;

  void __set_success(const  ::org::apache::accumulo::core::master::thrift::TabletServerStatus& val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_getTabletServerStatus_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getTabletServerStatus_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getTabletServerStatus_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getTabletServerStatus_result& obj);
};

typedef struct _TabletClientService_getTabletServerStatus_presult__isset {
  _TabletClientService_getTabletServerStatus_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getTabletServerStatus_presult__isset;

class TabletClientService_getTabletServerStatus_presult {
 public:

  static const char* ascii_fingerprint; // = "BFF7CCABA4BDAD79047A219A4A18E8CF";
  static const uint8_t binary_fingerprint[16]; // = {0xBF,0xF7,0xCC,0xAB,0xA4,0xBD,0xAD,0x79,0x04,0x7A,0x21,0x9A,0x4A,0x18,0xE8,0xCF};


  virtual ~TabletClientService_getTabletServerStatus_presult() throw();
   ::org::apache::accumulo::core::master::thrift::TabletServerStatus* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getTabletServerStatus_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getTabletServerStatus_presult& obj);
};

typedef struct _TabletClientService_getTabletStats_args__isset {
  _TabletClientService_getTabletStats_args__isset() : tinfo(false), credentials(false), tableId(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool tableId :1;
} _TabletClientService_getTabletStats_args__isset;

class TabletClientService_getTabletStats_args {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};

  TabletClientService_getTabletStats_args(const TabletClientService_getTabletStats_args&);
  TabletClientService_getTabletStats_args& operator=(const TabletClientService_getTabletStats_args&);
  TabletClientService_getTabletStats_args() : tableId() {
  }

  virtual ~TabletClientService_getTabletStats_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string tableId;

  _TabletClientService_getTabletStats_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_tableId(const std::string& val);

  bool operator == (const TabletClientService_getTabletStats_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(tableId == rhs.tableId))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getTabletStats_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getTabletStats_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getTabletStats_args& obj);
};


class TabletClientService_getTabletStats_pargs {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};


  virtual ~TabletClientService_getTabletStats_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* tableId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getTabletStats_pargs& obj);
};

typedef struct _TabletClientService_getTabletStats_result__isset {
  _TabletClientService_getTabletStats_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getTabletStats_result__isset;

class TabletClientService_getTabletStats_result {
 public:

  static const char* ascii_fingerprint; // = "E0D179DDA15E9BE7CB414DEE900630EF";
  static const uint8_t binary_fingerprint[16]; // = {0xE0,0xD1,0x79,0xDD,0xA1,0x5E,0x9B,0xE7,0xCB,0x41,0x4D,0xEE,0x90,0x06,0x30,0xEF};

  TabletClientService_getTabletStats_result(const TabletClientService_getTabletStats_result&);
  TabletClientService_getTabletStats_result& operator=(const TabletClientService_getTabletStats_result&);
  TabletClientService_getTabletStats_result() {
  }

  virtual ~TabletClientService_getTabletStats_result() throw();
  std::vector<TabletStats>  success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getTabletStats_result__isset __isset;

  void __set_success(const std::vector<TabletStats> & val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_getTabletStats_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getTabletStats_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getTabletStats_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getTabletStats_result& obj);
};

typedef struct _TabletClientService_getTabletStats_presult__isset {
  _TabletClientService_getTabletStats_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getTabletStats_presult__isset;

class TabletClientService_getTabletStats_presult {
 public:

  static const char* ascii_fingerprint; // = "E0D179DDA15E9BE7CB414DEE900630EF";
  static const uint8_t binary_fingerprint[16]; // = {0xE0,0xD1,0x79,0xDD,0xA1,0x5E,0x9B,0xE7,0xCB,0x41,0x4D,0xEE,0x90,0x06,0x30,0xEF};


  virtual ~TabletClientService_getTabletStats_presult() throw();
  std::vector<TabletStats> * success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getTabletStats_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getTabletStats_presult& obj);
};

typedef struct _TabletClientService_getHistoricalStats_args__isset {
  _TabletClientService_getHistoricalStats_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _TabletClientService_getHistoricalStats_args__isset;

class TabletClientService_getHistoricalStats_args {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};

  TabletClientService_getHistoricalStats_args(const TabletClientService_getHistoricalStats_args&);
  TabletClientService_getHistoricalStats_args& operator=(const TabletClientService_getHistoricalStats_args&);
  TabletClientService_getHistoricalStats_args() {
  }

  virtual ~TabletClientService_getHistoricalStats_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _TabletClientService_getHistoricalStats_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const TabletClientService_getHistoricalStats_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getHistoricalStats_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getHistoricalStats_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getHistoricalStats_args& obj);
};


class TabletClientService_getHistoricalStats_pargs {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};


  virtual ~TabletClientService_getHistoricalStats_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getHistoricalStats_pargs& obj);
};

typedef struct _TabletClientService_getHistoricalStats_result__isset {
  _TabletClientService_getHistoricalStats_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getHistoricalStats_result__isset;

class TabletClientService_getHistoricalStats_result {
 public:

  static const char* ascii_fingerprint; // = "B321077325813B00EA6449E228C5CD13";
  static const uint8_t binary_fingerprint[16]; // = {0xB3,0x21,0x07,0x73,0x25,0x81,0x3B,0x00,0xEA,0x64,0x49,0xE2,0x28,0xC5,0xCD,0x13};

  TabletClientService_getHistoricalStats_result(const TabletClientService_getHistoricalStats_result&);
  TabletClientService_getHistoricalStats_result& operator=(const TabletClientService_getHistoricalStats_result&);
  TabletClientService_getHistoricalStats_result() {
  }

  virtual ~TabletClientService_getHistoricalStats_result() throw();
  TabletStats success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getHistoricalStats_result__isset __isset;

  void __set_success(const TabletStats& val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_getHistoricalStats_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getHistoricalStats_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getHistoricalStats_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getHistoricalStats_result& obj);
};

typedef struct _TabletClientService_getHistoricalStats_presult__isset {
  _TabletClientService_getHistoricalStats_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getHistoricalStats_presult__isset;

class TabletClientService_getHistoricalStats_presult {
 public:

  static const char* ascii_fingerprint; // = "B321077325813B00EA6449E228C5CD13";
  static const uint8_t binary_fingerprint[16]; // = {0xB3,0x21,0x07,0x73,0x25,0x81,0x3B,0x00,0xEA,0x64,0x49,0xE2,0x28,0xC5,0xCD,0x13};


  virtual ~TabletClientService_getHistoricalStats_presult() throw();
  TabletStats* success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getHistoricalStats_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getHistoricalStats_presult& obj);
};

typedef struct _TabletClientService_halt_args__isset {
  _TabletClientService_halt_args__isset() : tinfo(false), credentials(false), lock(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool lock :1;
} _TabletClientService_halt_args__isset;

class TabletClientService_halt_args {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};

  TabletClientService_halt_args(const TabletClientService_halt_args&);
  TabletClientService_halt_args& operator=(const TabletClientService_halt_args&);
  TabletClientService_halt_args() : lock() {
  }

  virtual ~TabletClientService_halt_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string lock;

  _TabletClientService_halt_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_lock(const std::string& val);

  bool operator == (const TabletClientService_halt_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(lock == rhs.lock))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_halt_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_halt_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_halt_args& obj);
};


class TabletClientService_halt_pargs {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};


  virtual ~TabletClientService_halt_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* lock;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_halt_pargs& obj);
};

typedef struct _TabletClientService_halt_result__isset {
  _TabletClientService_halt_result__isset() : sec(false) {}
  bool sec :1;
} _TabletClientService_halt_result__isset;

class TabletClientService_halt_result {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};

  TabletClientService_halt_result(const TabletClientService_halt_result&);
  TabletClientService_halt_result& operator=(const TabletClientService_halt_result&);
  TabletClientService_halt_result() {
  }

  virtual ~TabletClientService_halt_result() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_halt_result__isset __isset;

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_halt_result & rhs) const
  {
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_halt_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_halt_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_halt_result& obj);
};

typedef struct _TabletClientService_halt_presult__isset {
  _TabletClientService_halt_presult__isset() : sec(false) {}
  bool sec :1;
} _TabletClientService_halt_presult__isset;

class TabletClientService_halt_presult {
 public:

  static const char* ascii_fingerprint; // = "2EFF1E534C8CBE58ACF12DBD7FBA560E";
  static const uint8_t binary_fingerprint[16]; // = {0x2E,0xFF,0x1E,0x53,0x4C,0x8C,0xBE,0x58,0xAC,0xF1,0x2D,0xBD,0x7F,0xBA,0x56,0x0E};


  virtual ~TabletClientService_halt_presult() throw();
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_halt_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_halt_presult& obj);
};

typedef struct _TabletClientService_fastHalt_args__isset {
  _TabletClientService_fastHalt_args__isset() : tinfo(false), credentials(false), lock(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool lock :1;
} _TabletClientService_fastHalt_args__isset;

class TabletClientService_fastHalt_args {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};

  TabletClientService_fastHalt_args(const TabletClientService_fastHalt_args&);
  TabletClientService_fastHalt_args& operator=(const TabletClientService_fastHalt_args&);
  TabletClientService_fastHalt_args() : lock() {
  }

  virtual ~TabletClientService_fastHalt_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::string lock;

  _TabletClientService_fastHalt_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_lock(const std::string& val);

  bool operator == (const TabletClientService_fastHalt_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(lock == rhs.lock))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_fastHalt_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_fastHalt_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_fastHalt_args& obj);
};


class TabletClientService_fastHalt_pargs {
 public:

  static const char* ascii_fingerprint; // = "01074FA9CF7CC603568C306FC55EC5B0";
  static const uint8_t binary_fingerprint[16]; // = {0x01,0x07,0x4F,0xA9,0xCF,0x7C,0xC6,0x03,0x56,0x8C,0x30,0x6F,0xC5,0x5E,0xC5,0xB0};


  virtual ~TabletClientService_fastHalt_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::string* lock;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_fastHalt_pargs& obj);
};

typedef struct _TabletClientService_getActiveScans_args__isset {
  _TabletClientService_getActiveScans_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _TabletClientService_getActiveScans_args__isset;

class TabletClientService_getActiveScans_args {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};

  TabletClientService_getActiveScans_args(const TabletClientService_getActiveScans_args&);
  TabletClientService_getActiveScans_args& operator=(const TabletClientService_getActiveScans_args&);
  TabletClientService_getActiveScans_args() {
  }

  virtual ~TabletClientService_getActiveScans_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _TabletClientService_getActiveScans_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const TabletClientService_getActiveScans_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getActiveScans_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getActiveScans_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getActiveScans_args& obj);
};


class TabletClientService_getActiveScans_pargs {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};


  virtual ~TabletClientService_getActiveScans_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getActiveScans_pargs& obj);
};

typedef struct _TabletClientService_getActiveScans_result__isset {
  _TabletClientService_getActiveScans_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getActiveScans_result__isset;

class TabletClientService_getActiveScans_result {
 public:

  static const char* ascii_fingerprint; // = "0FBC679F5A8997265E60B3658B54E22D";
  static const uint8_t binary_fingerprint[16]; // = {0x0F,0xBC,0x67,0x9F,0x5A,0x89,0x97,0x26,0x5E,0x60,0xB3,0x65,0x8B,0x54,0xE2,0x2D};

  TabletClientService_getActiveScans_result(const TabletClientService_getActiveScans_result&);
  TabletClientService_getActiveScans_result& operator=(const TabletClientService_getActiveScans_result&);
  TabletClientService_getActiveScans_result() {
  }

  virtual ~TabletClientService_getActiveScans_result() throw();
  std::vector<ActiveScan>  success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getActiveScans_result__isset __isset;

  void __set_success(const std::vector<ActiveScan> & val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_getActiveScans_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getActiveScans_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getActiveScans_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getActiveScans_result& obj);
};

typedef struct _TabletClientService_getActiveScans_presult__isset {
  _TabletClientService_getActiveScans_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getActiveScans_presult__isset;

class TabletClientService_getActiveScans_presult {
 public:

  static const char* ascii_fingerprint; // = "0FBC679F5A8997265E60B3658B54E22D";
  static const uint8_t binary_fingerprint[16]; // = {0x0F,0xBC,0x67,0x9F,0x5A,0x89,0x97,0x26,0x5E,0x60,0xB3,0x65,0x8B,0x54,0xE2,0x2D};


  virtual ~TabletClientService_getActiveScans_presult() throw();
  std::vector<ActiveScan> * success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getActiveScans_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getActiveScans_presult& obj);
};

typedef struct _TabletClientService_getActiveCompactions_args__isset {
  _TabletClientService_getActiveCompactions_args__isset() : tinfo(false), credentials(false) {}
  bool tinfo :1;
  bool credentials :1;
} _TabletClientService_getActiveCompactions_args__isset;

class TabletClientService_getActiveCompactions_args {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};

  TabletClientService_getActiveCompactions_args(const TabletClientService_getActiveCompactions_args&);
  TabletClientService_getActiveCompactions_args& operator=(const TabletClientService_getActiveCompactions_args&);
  TabletClientService_getActiveCompactions_args() {
  }

  virtual ~TabletClientService_getActiveCompactions_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;

  _TabletClientService_getActiveCompactions_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  bool operator == (const TabletClientService_getActiveCompactions_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getActiveCompactions_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getActiveCompactions_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getActiveCompactions_args& obj);
};


class TabletClientService_getActiveCompactions_pargs {
 public:

  static const char* ascii_fingerprint; // = "0555E39FE2CBB19B29000CC017A18001";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x55,0xE3,0x9F,0xE2,0xCB,0xB1,0x9B,0x29,0x00,0x0C,0xC0,0x17,0xA1,0x80,0x01};


  virtual ~TabletClientService_getActiveCompactions_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getActiveCompactions_pargs& obj);
};

typedef struct _TabletClientService_getActiveCompactions_result__isset {
  _TabletClientService_getActiveCompactions_result__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getActiveCompactions_result__isset;

class TabletClientService_getActiveCompactions_result {
 public:

  static const char* ascii_fingerprint; // = "66E3AA0CA5B56667A89DDA55A6C74783";
  static const uint8_t binary_fingerprint[16]; // = {0x66,0xE3,0xAA,0x0C,0xA5,0xB5,0x66,0x67,0xA8,0x9D,0xDA,0x55,0xA6,0xC7,0x47,0x83};

  TabletClientService_getActiveCompactions_result(const TabletClientService_getActiveCompactions_result&);
  TabletClientService_getActiveCompactions_result& operator=(const TabletClientService_getActiveCompactions_result&);
  TabletClientService_getActiveCompactions_result() {
  }

  virtual ~TabletClientService_getActiveCompactions_result() throw();
  std::vector<ActiveCompaction>  success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getActiveCompactions_result__isset __isset;

  void __set_success(const std::vector<ActiveCompaction> & val);

  void __set_sec(const  ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException& val);

  bool operator == (const TabletClientService_getActiveCompactions_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(sec == rhs.sec))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_getActiveCompactions_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_getActiveCompactions_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getActiveCompactions_result& obj);
};

typedef struct _TabletClientService_getActiveCompactions_presult__isset {
  _TabletClientService_getActiveCompactions_presult__isset() : success(false), sec(false) {}
  bool success :1;
  bool sec :1;
} _TabletClientService_getActiveCompactions_presult__isset;

class TabletClientService_getActiveCompactions_presult {
 public:

  static const char* ascii_fingerprint; // = "66E3AA0CA5B56667A89DDA55A6C74783";
  static const uint8_t binary_fingerprint[16]; // = {0x66,0xE3,0xAA,0x0C,0xA5,0xB5,0x66,0x67,0xA8,0x9D,0xDA,0x55,0xA6,0xC7,0x47,0x83};


  virtual ~TabletClientService_getActiveCompactions_presult() throw();
  std::vector<ActiveCompaction> * success;
   ::org::apache::accumulo::core::client::impl::thrift::ThriftSecurityException sec;

  _TabletClientService_getActiveCompactions_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_getActiveCompactions_presult& obj);
};

typedef struct _TabletClientService_removeLogs_args__isset {
  _TabletClientService_removeLogs_args__isset() : tinfo(false), credentials(false), filenames(false) {}
  bool tinfo :1;
  bool credentials :1;
  bool filenames :1;
} _TabletClientService_removeLogs_args__isset;

class TabletClientService_removeLogs_args {
 public:

  static const char* ascii_fingerprint; // = "96FFA31F139D6DD85AE71330C8E1C559";
  static const uint8_t binary_fingerprint[16]; // = {0x96,0xFF,0xA3,0x1F,0x13,0x9D,0x6D,0xD8,0x5A,0xE7,0x13,0x30,0xC8,0xE1,0xC5,0x59};

  TabletClientService_removeLogs_args(const TabletClientService_removeLogs_args&);
  TabletClientService_removeLogs_args& operator=(const TabletClientService_removeLogs_args&);
  TabletClientService_removeLogs_args() {
  }

  virtual ~TabletClientService_removeLogs_args() throw();
   ::org::apache::accumulo::trace::thrift::TInfo tinfo;
   ::org::apache::accumulo::core::security::thrift::TCredentials credentials;
  std::vector<std::string>  filenames;

  _TabletClientService_removeLogs_args__isset __isset;

  void __set_tinfo(const  ::org::apache::accumulo::trace::thrift::TInfo& val);

  void __set_credentials(const  ::org::apache::accumulo::core::security::thrift::TCredentials& val);

  void __set_filenames(const std::vector<std::string> & val);

  bool operator == (const TabletClientService_removeLogs_args & rhs) const
  {
    if (!(tinfo == rhs.tinfo))
      return false;
    if (!(credentials == rhs.credentials))
      return false;
    if (!(filenames == rhs.filenames))
      return false;
    return true;
  }
  bool operator != (const TabletClientService_removeLogs_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TabletClientService_removeLogs_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_removeLogs_args& obj);
};


class TabletClientService_removeLogs_pargs {
 public:

  static const char* ascii_fingerprint; // = "96FFA31F139D6DD85AE71330C8E1C559";
  static const uint8_t binary_fingerprint[16]; // = {0x96,0xFF,0xA3,0x1F,0x13,0x9D,0x6D,0xD8,0x5A,0xE7,0x13,0x30,0xC8,0xE1,0xC5,0x59};


  virtual ~TabletClientService_removeLogs_pargs() throw();
  const  ::org::apache::accumulo::trace::thrift::TInfo* tinfo;
  const  ::org::apache::accumulo::core::security::thrift::TCredentials* credentials;
  const std::vector<std::string> * filenames;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const TabletClientService_removeLogs_pargs& obj);
};

class TabletClientServiceClient : virtual public TabletClientServiceIf, public  ::org::apache::accumulo::core::client::impl::thrift::ClientServiceClient {
 public:
  TabletClientServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
     ::org::apache::accumulo::core::client::impl::thrift::ClientServiceClient(prot, prot) {}
  TabletClientServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :     ::org::apache::accumulo::core::client::impl::thrift::ClientServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void startScan( ::org::apache::accumulo::core::data::thrift::InitialScan& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const  ::org::apache::accumulo::core::data::thrift::TRange& range, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & columns, const int32_t batchSize, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList, const std::map<std::string, std::map<std::string, std::string> > & ssio, const std::vector<std::string> & authorizations, const bool waitForWrites, const bool isolated, const int64_t readaheadThreshold);
  void send_startScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const  ::org::apache::accumulo::core::data::thrift::TRange& range, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & columns, const int32_t batchSize, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList, const std::map<std::string, std::map<std::string, std::string> > & ssio, const std::vector<std::string> & authorizations, const bool waitForWrites, const bool isolated, const int64_t readaheadThreshold);
  void recv_startScan( ::org::apache::accumulo::core::data::thrift::InitialScan& _return);
  void continueScan( ::org::apache::accumulo::core::data::thrift::ScanResult& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID);
  void send_continueScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID);
  void recv_continueScan( ::org::apache::accumulo::core::data::thrift::ScanResult& _return);
  void closeScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID);
  void send_closeScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID);
  void startMultiScan( ::org::apache::accumulo::core::data::thrift::InitialMultiScan& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::ScanBatch& batch, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & columns, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList, const std::map<std::string, std::map<std::string, std::string> > & ssio, const std::vector<std::string> & authorizations, const bool waitForWrites);
  void send_startMultiScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::ScanBatch& batch, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & columns, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList, const std::map<std::string, std::map<std::string, std::string> > & ssio, const std::vector<std::string> & authorizations, const bool waitForWrites);
  void recv_startMultiScan( ::org::apache::accumulo::core::data::thrift::InitialMultiScan& _return);
  void continueMultiScan( ::org::apache::accumulo::core::data::thrift::MultiScanResult& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID);
  void send_continueMultiScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID);
  void recv_continueMultiScan( ::org::apache::accumulo::core::data::thrift::MultiScanResult& _return);
  void closeMultiScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID);
  void send_closeMultiScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID);
  void recv_closeMultiScan();
   ::org::apache::accumulo::core::data::thrift::UpdateID startUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_startUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
   ::org::apache::accumulo::core::data::thrift::UpdateID recv_startUpdate();
  void applyUpdates(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID updateID, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent, const std::vector< ::org::apache::accumulo::core::data::thrift::TMutation> & mutations);
  void send_applyUpdates(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID updateID, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent, const std::vector< ::org::apache::accumulo::core::data::thrift::TMutation> & mutations);
  void closeUpdate( ::org::apache::accumulo::core::data::thrift::UpdateErrors& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID updateID);
  void send_closeUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID updateID);
  void recv_closeUpdate( ::org::apache::accumulo::core::data::thrift::UpdateErrors& _return);
  void update(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent, const  ::org::apache::accumulo::core::data::thrift::TMutation& mutation);
  void send_update(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent, const  ::org::apache::accumulo::core::data::thrift::TMutation& mutation);
  void recv_update();
  void startConditionalUpdate( ::org::apache::accumulo::core::data::thrift::TConditionalSession& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::vector<std::string> & authorizations, const std::string& tableID);
  void send_startConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::vector<std::string> & authorizations, const std::string& tableID);
  void recv_startConditionalUpdate( ::org::apache::accumulo::core::data::thrift::TConditionalSession& _return);
  void conditionalUpdate(std::vector< ::org::apache::accumulo::core::data::thrift::TCMResult> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID, const  ::org::apache::accumulo::core::data::thrift::CMBatch& mutations, const std::vector<std::string> & symbols);
  void send_conditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID, const  ::org::apache::accumulo::core::data::thrift::CMBatch& mutations, const std::vector<std::string> & symbols);
  void recv_conditionalUpdate(std::vector< ::org::apache::accumulo::core::data::thrift::TCMResult> & _return);
  void invalidateConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID);
  void send_invalidateConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID);
  void recv_invalidateConditionalUpdate();
  void closeConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID);
  void send_closeConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID);
  void bulkImport(std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t tid, const  ::org::apache::accumulo::core::data::thrift::TabletFiles& files, const bool setTime);
  void send_bulkImport(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t tid, const  ::org::apache::accumulo::core::data::thrift::TabletFiles& files, const bool setTime);
  void recv_bulkImport(std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent> & _return);
  void splitTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const std::string& splitPoint);
  void send_splitTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const std::string& splitPoint);
  void recv_splitTablet();
  void loadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent);
  void send_loadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent);
  void unloadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const bool save);
  void send_unloadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const bool save);
  void flush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const std::string& tableId, const std::string& startRow, const std::string& endRow);
  void send_flush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const std::string& tableId, const std::string& startRow, const std::string& endRow);
  void flushTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent);
  void send_flushTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent);
  void chop(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent);
  void send_chop(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent);
  void compact(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const std::string& tableId, const std::string& startRow, const std::string& endRow);
  void send_compact(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const std::string& tableId, const std::string& startRow, const std::string& endRow);
  void getTabletServerStatus( ::org::apache::accumulo::core::master::thrift::TabletServerStatus& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_getTabletServerStatus(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void recv_getTabletServerStatus( ::org::apache::accumulo::core::master::thrift::TabletServerStatus& _return);
  void getTabletStats(std::vector<TabletStats> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableId);
  void send_getTabletStats(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableId);
  void recv_getTabletStats(std::vector<TabletStats> & _return);
  void getHistoricalStats(TabletStats& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_getHistoricalStats(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void recv_getHistoricalStats(TabletStats& _return);
  void halt(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock);
  void send_halt(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock);
  void recv_halt();
  void fastHalt(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock);
  void send_fastHalt(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock);
  void getActiveScans(std::vector<ActiveScan> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_getActiveScans(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void recv_getActiveScans(std::vector<ActiveScan> & _return);
  void getActiveCompactions(std::vector<ActiveCompaction> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void send_getActiveCompactions(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials);
  void recv_getActiveCompactions(std::vector<ActiveCompaction> & _return);
  void removeLogs(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::vector<std::string> & filenames);
  void send_removeLogs(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::vector<std::string> & filenames);
};

class TabletClientServiceProcessor : public  ::org::apache::accumulo::core::client::impl::thrift::ClientServiceProcessor {
 protected:
  boost::shared_ptr<TabletClientServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TabletClientServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_startScan(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_continueScan(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_closeScan(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startMultiScan(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_continueMultiScan(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_closeMultiScan(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startUpdate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_applyUpdates(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_closeUpdate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_update(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startConditionalUpdate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_conditionalUpdate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_invalidateConditionalUpdate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_closeConditionalUpdate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_bulkImport(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_splitTablet(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_loadTablet(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_unloadTablet(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_flush(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_flushTablet(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_chop(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_compact(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getTabletServerStatus(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getTabletStats(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getHistoricalStats(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_halt(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_fastHalt(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getActiveScans(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getActiveCompactions(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeLogs(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  TabletClientServiceProcessor(boost::shared_ptr<TabletClientServiceIf> iface) :
     ::org::apache::accumulo::core::client::impl::thrift::ClientServiceProcessor(iface),
    iface_(iface) {
    processMap_["startScan"] = &TabletClientServiceProcessor::process_startScan;
    processMap_["continueScan"] = &TabletClientServiceProcessor::process_continueScan;
    processMap_["closeScan"] = &TabletClientServiceProcessor::process_closeScan;
    processMap_["startMultiScan"] = &TabletClientServiceProcessor::process_startMultiScan;
    processMap_["continueMultiScan"] = &TabletClientServiceProcessor::process_continueMultiScan;
    processMap_["closeMultiScan"] = &TabletClientServiceProcessor::process_closeMultiScan;
    processMap_["startUpdate"] = &TabletClientServiceProcessor::process_startUpdate;
    processMap_["applyUpdates"] = &TabletClientServiceProcessor::process_applyUpdates;
    processMap_["closeUpdate"] = &TabletClientServiceProcessor::process_closeUpdate;
    processMap_["update"] = &TabletClientServiceProcessor::process_update;
    processMap_["startConditionalUpdate"] = &TabletClientServiceProcessor::process_startConditionalUpdate;
    processMap_["conditionalUpdate"] = &TabletClientServiceProcessor::process_conditionalUpdate;
    processMap_["invalidateConditionalUpdate"] = &TabletClientServiceProcessor::process_invalidateConditionalUpdate;
    processMap_["closeConditionalUpdate"] = &TabletClientServiceProcessor::process_closeConditionalUpdate;
    processMap_["bulkImport"] = &TabletClientServiceProcessor::process_bulkImport;
    processMap_["splitTablet"] = &TabletClientServiceProcessor::process_splitTablet;
    processMap_["loadTablet"] = &TabletClientServiceProcessor::process_loadTablet;
    processMap_["unloadTablet"] = &TabletClientServiceProcessor::process_unloadTablet;
    processMap_["flush"] = &TabletClientServiceProcessor::process_flush;
    processMap_["flushTablet"] = &TabletClientServiceProcessor::process_flushTablet;
    processMap_["chop"] = &TabletClientServiceProcessor::process_chop;
    processMap_["compact"] = &TabletClientServiceProcessor::process_compact;
    processMap_["getTabletServerStatus"] = &TabletClientServiceProcessor::process_getTabletServerStatus;
    processMap_["getTabletStats"] = &TabletClientServiceProcessor::process_getTabletStats;
    processMap_["getHistoricalStats"] = &TabletClientServiceProcessor::process_getHistoricalStats;
    processMap_["halt"] = &TabletClientServiceProcessor::process_halt;
    processMap_["fastHalt"] = &TabletClientServiceProcessor::process_fastHalt;
    processMap_["getActiveScans"] = &TabletClientServiceProcessor::process_getActiveScans;
    processMap_["getActiveCompactions"] = &TabletClientServiceProcessor::process_getActiveCompactions;
    processMap_["removeLogs"] = &TabletClientServiceProcessor::process_removeLogs;
  }

  virtual ~TabletClientServiceProcessor() {}
};

class TabletClientServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TabletClientServiceProcessorFactory(const ::boost::shared_ptr< TabletClientServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< TabletClientServiceIfFactory > handlerFactory_;
};

class TabletClientServiceMultiface : virtual public TabletClientServiceIf, public  ::org::apache::accumulo::core::client::impl::thrift::ClientServiceMultiface {
 public:
  TabletClientServiceMultiface(std::vector<boost::shared_ptr<TabletClientServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<TabletClientServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
       ::org::apache::accumulo::core::client::impl::thrift::ClientServiceMultiface::add(*iter);
    }
  }
  virtual ~TabletClientServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<TabletClientServiceIf> > ifaces_;
  TabletClientServiceMultiface() {}
  void add(boost::shared_ptr<TabletClientServiceIf> iface) {
     ::org::apache::accumulo::core::client::impl::thrift::ClientServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  void startScan( ::org::apache::accumulo::core::data::thrift::InitialScan& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const  ::org::apache::accumulo::core::data::thrift::TRange& range, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & columns, const int32_t batchSize, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList, const std::map<std::string, std::map<std::string, std::string> > & ssio, const std::vector<std::string> & authorizations, const bool waitForWrites, const bool isolated, const int64_t readaheadThreshold) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->startScan(_return, tinfo, credentials, extent, range, columns, batchSize, ssiList, ssio, authorizations, waitForWrites, isolated, readaheadThreshold);
    }
    ifaces_[i]->startScan(_return, tinfo, credentials, extent, range, columns, batchSize, ssiList, ssio, authorizations, waitForWrites, isolated, readaheadThreshold);
    return;
  }

  void continueScan( ::org::apache::accumulo::core::data::thrift::ScanResult& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->continueScan(_return, tinfo, scanID);
    }
    ifaces_[i]->continueScan(_return, tinfo, scanID);
    return;
  }

  void closeScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->closeScan(tinfo, scanID);
    }
    ifaces_[i]->closeScan(tinfo, scanID);
  }

  void startMultiScan( ::org::apache::accumulo::core::data::thrift::InitialMultiScan& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::ScanBatch& batch, const std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> & columns, const std::vector< ::org::apache::accumulo::core::data::thrift::IterInfo> & ssiList, const std::map<std::string, std::map<std::string, std::string> > & ssio, const std::vector<std::string> & authorizations, const bool waitForWrites) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->startMultiScan(_return, tinfo, credentials, batch, columns, ssiList, ssio, authorizations, waitForWrites);
    }
    ifaces_[i]->startMultiScan(_return, tinfo, credentials, batch, columns, ssiList, ssio, authorizations, waitForWrites);
    return;
  }

  void continueMultiScan( ::org::apache::accumulo::core::data::thrift::MultiScanResult& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->continueMultiScan(_return, tinfo, scanID);
    }
    ifaces_[i]->continueMultiScan(_return, tinfo, scanID);
    return;
  }

  void closeMultiScan(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::ScanID scanID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->closeMultiScan(tinfo, scanID);
    }
    ifaces_[i]->closeMultiScan(tinfo, scanID);
  }

   ::org::apache::accumulo::core::data::thrift::UpdateID startUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->startUpdate(tinfo, credentials);
    }
    return ifaces_[i]->startUpdate(tinfo, credentials);
  }

  void applyUpdates(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID updateID, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent, const std::vector< ::org::apache::accumulo::core::data::thrift::TMutation> & mutations) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->applyUpdates(tinfo, updateID, keyExtent, mutations);
    }
    ifaces_[i]->applyUpdates(tinfo, updateID, keyExtent, mutations);
  }

  void closeUpdate( ::org::apache::accumulo::core::data::thrift::UpdateErrors& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID updateID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->closeUpdate(_return, tinfo, updateID);
    }
    ifaces_[i]->closeUpdate(_return, tinfo, updateID);
    return;
  }

  void update(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& keyExtent, const  ::org::apache::accumulo::core::data::thrift::TMutation& mutation) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->update(tinfo, credentials, keyExtent, mutation);
    }
    ifaces_[i]->update(tinfo, credentials, keyExtent, mutation);
  }

  void startConditionalUpdate( ::org::apache::accumulo::core::data::thrift::TConditionalSession& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::vector<std::string> & authorizations, const std::string& tableID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->startConditionalUpdate(_return, tinfo, credentials, authorizations, tableID);
    }
    ifaces_[i]->startConditionalUpdate(_return, tinfo, credentials, authorizations, tableID);
    return;
  }

  void conditionalUpdate(std::vector< ::org::apache::accumulo::core::data::thrift::TCMResult> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID, const  ::org::apache::accumulo::core::data::thrift::CMBatch& mutations, const std::vector<std::string> & symbols) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->conditionalUpdate(_return, tinfo, sessID, mutations, symbols);
    }
    ifaces_[i]->conditionalUpdate(_return, tinfo, sessID, mutations, symbols);
    return;
  }

  void invalidateConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->invalidateConditionalUpdate(tinfo, sessID);
    }
    ifaces_[i]->invalidateConditionalUpdate(tinfo, sessID);
  }

  void closeConditionalUpdate(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::data::thrift::UpdateID sessID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->closeConditionalUpdate(tinfo, sessID);
    }
    ifaces_[i]->closeConditionalUpdate(tinfo, sessID);
  }

  void bulkImport(std::vector< ::org::apache::accumulo::core::data::thrift::TKeyExtent> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const int64_t tid, const  ::org::apache::accumulo::core::data::thrift::TabletFiles& files, const bool setTime) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->bulkImport(_return, tinfo, credentials, tid, files, setTime);
    }
    ifaces_[i]->bulkImport(_return, tinfo, credentials, tid, files, setTime);
    return;
  }

  void splitTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const std::string& splitPoint) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->splitTablet(tinfo, credentials, extent, splitPoint);
    }
    ifaces_[i]->splitTablet(tinfo, credentials, extent, splitPoint);
  }

  void loadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->loadTablet(tinfo, credentials, lock, extent);
    }
    ifaces_[i]->loadTablet(tinfo, credentials, lock, extent);
  }

  void unloadTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent, const bool save) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->unloadTablet(tinfo, credentials, lock, extent, save);
    }
    ifaces_[i]->unloadTablet(tinfo, credentials, lock, extent, save);
  }

  void flush(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const std::string& tableId, const std::string& startRow, const std::string& endRow) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->flush(tinfo, credentials, lock, tableId, startRow, endRow);
    }
    ifaces_[i]->flush(tinfo, credentials, lock, tableId, startRow, endRow);
  }

  void flushTablet(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->flushTablet(tinfo, credentials, lock, extent);
    }
    ifaces_[i]->flushTablet(tinfo, credentials, lock, extent);
  }

  void chop(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const  ::org::apache::accumulo::core::data::thrift::TKeyExtent& extent) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->chop(tinfo, credentials, lock, extent);
    }
    ifaces_[i]->chop(tinfo, credentials, lock, extent);
  }

  void compact(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock, const std::string& tableId, const std::string& startRow, const std::string& endRow) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->compact(tinfo, credentials, lock, tableId, startRow, endRow);
    }
    ifaces_[i]->compact(tinfo, credentials, lock, tableId, startRow, endRow);
  }

  void getTabletServerStatus( ::org::apache::accumulo::core::master::thrift::TabletServerStatus& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getTabletServerStatus(_return, tinfo, credentials);
    }
    ifaces_[i]->getTabletServerStatus(_return, tinfo, credentials);
    return;
  }

  void getTabletStats(std::vector<TabletStats> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& tableId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getTabletStats(_return, tinfo, credentials, tableId);
    }
    ifaces_[i]->getTabletStats(_return, tinfo, credentials, tableId);
    return;
  }

  void getHistoricalStats(TabletStats& _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getHistoricalStats(_return, tinfo, credentials);
    }
    ifaces_[i]->getHistoricalStats(_return, tinfo, credentials);
    return;
  }

  void halt(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->halt(tinfo, credentials, lock);
    }
    ifaces_[i]->halt(tinfo, credentials, lock);
  }

  void fastHalt(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::string& lock) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->fastHalt(tinfo, credentials, lock);
    }
    ifaces_[i]->fastHalt(tinfo, credentials, lock);
  }

  void getActiveScans(std::vector<ActiveScan> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getActiveScans(_return, tinfo, credentials);
    }
    ifaces_[i]->getActiveScans(_return, tinfo, credentials);
    return;
  }

  void getActiveCompactions(std::vector<ActiveCompaction> & _return, const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getActiveCompactions(_return, tinfo, credentials);
    }
    ifaces_[i]->getActiveCompactions(_return, tinfo, credentials);
    return;
  }

  void removeLogs(const  ::org::apache::accumulo::trace::thrift::TInfo& tinfo, const  ::org::apache::accumulo::core::security::thrift::TCredentials& credentials, const std::vector<std::string> & filenames) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeLogs(tinfo, credentials, filenames);
    }
    ifaces_[i]->removeLogs(tinfo, credentials, filenames);
  }

};

}}}}}} // namespace

#endif
