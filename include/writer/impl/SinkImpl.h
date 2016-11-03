/*
 * Copyright (c) 2016 Marc Parisi marc.parisi@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
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
