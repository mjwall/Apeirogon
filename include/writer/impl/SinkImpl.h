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
#ifndef SRC_WRITER_IMPL_SINKIMPL_H_
#define SRC_WRITER_IMPL_SINKIMPL_H_

#include "../../data/constructs/Key.h"
#include "../../data/constructs/KeyValue.h"
#include "../../data/constructs/security/AuthInfo.h"
#include "../../data/constructs/security/Authorizations.h"
#include "../../data/constructs/value.h"
#include "../../scanner/constructs/Results.h"
#include "../../data/constructs/inputvalidation.h"
#include "../../data/client/ExtentLocator.h"
#include "../../data/constructs/client/zookeeperinstance.h"
#include "../../data/client/LocatorCache.h"
#include "../../interconnect/ClientInterface.h"
#include "../../interconnect/tableOps/TableOperations.h"
#include "../Sink.h"
#include "WriterHeuristic.h"
namespace writer
{
using namespace interconnect;
using namespace scanners;
using namespace cclient::data::zookeeper;
using namespace cclient::data;
using namespace cclient::data::security;

/*
 *
 */
class BatchWriter : public Sink<KeyValue*>
{
public:
    BatchWriter (Instance *instance,
              TableOperations<KeyValue*, ResultBlock<KeyValue*>> *tops,
              Authorizations *auths, uint16_t threads);
    virtual
    ~BatchWriter ();

    void
    flush (bool override = false);

    void
    setHeuristic (Heuristic<interconnect::ThriftTransporter> *heuristic)
    {
        writerHeuristic = (WriterHeuristic*) heuristic;
    }

protected:
  
  virtual uint64_t waitingSize()
	{
	  return writerHeuristic->size();
	}
	
	virtual uint64_t maxWait()
	{
	  return writerHeuristic->maxThreads();
	}
	
    WriterHeuristic *writerHeuristic;
    AuthInfo *credentials;
    vector<ClientInterface<interconnect::ThriftTransporter>*> servers;
    ZookeeperInstance *connectorInstance;
    TabletLocator *tableLocator;
};

} /* namespace data */

#endif /* SRC_WRITER_IMPL_SINKIMPL_H_ */
