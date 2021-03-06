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
#include "../../../../include/data/extern/thrift/SpanReceiver.h"

namespace org
{
  namespace apache
  {
    namespace accumulo
    {
      namespace trace
      {
	namespace thrift
	{

	  SpanReceiver_span_args::~SpanReceiver_span_args () throw ()
	  {
	  }

	  uint32_t
	  SpanReceiver_span_args::read (
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
			xfer += this->span.read (iprot);
			this->__isset.span = true;
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
	  SpanReceiver_span_args::write (
	      ::apache::thrift::protocol::TProtocol* oprot) const
	  {
	    uint32_t xfer = 0;
	    oprot->incrementRecursionDepth ();
	    xfer += oprot->writeStructBegin ("SpanReceiver_span_args");

	    xfer += oprot->writeFieldBegin (
		"span", ::apache::thrift::protocol::T_STRUCT, 1);
	    xfer += this->span.write (oprot);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldStop ();
	    xfer += oprot->writeStructEnd ();
	    oprot->decrementRecursionDepth ();
	    return xfer;
	  }

	  SpanReceiver_span_pargs::~SpanReceiver_span_pargs () throw ()
	  {
	  }

	  uint32_t
	  SpanReceiver_span_pargs::write (
	      ::apache::thrift::protocol::TProtocol* oprot) const
	  {
	    uint32_t xfer = 0;
	    oprot->incrementRecursionDepth ();
	    xfer += oprot->writeStructBegin ("SpanReceiver_span_pargs");

	    xfer += oprot->writeFieldBegin (
		"span", ::apache::thrift::protocol::T_STRUCT, 1);
	    xfer += (*(this->span)).write (oprot);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldStop ();
	    xfer += oprot->writeStructEnd ();
	    oprot->decrementRecursionDepth ();
	    return xfer;
	  }

	  void
	  SpanReceiverClient::span (const RemoteSpan& span)
	  {
	    send_span (span);
	  }

	  void
	  SpanReceiverClient::send_span (const RemoteSpan& span)
	  {
	    int32_t cseqid = 0;
	    oprot_->writeMessageBegin ("span",
				       ::apache::thrift::protocol::T_ONEWAY,
				       cseqid);

	    SpanReceiver_span_pargs args;
	    args.span = &span;
	    args.write (oprot_);

	    oprot_->writeMessageEnd ();
	    oprot_->getTransport ()->writeEnd ();
	    oprot_->getTransport ()->flush ();
	  }

	  bool
	  SpanReceiverProcessor::dispatchCall (
	      ::apache::thrift::protocol::TProtocol* iprot,
	      ::apache::thrift::protocol::TProtocol* oprot,
	      const std::string& fname, int32_t seqid, void* callContext)
	  {
	    ProcessMap::iterator pfn;
	    pfn = processMap_.find (fname);
	    if (pfn == processMap_.end ())
	      {
		iprot->skip (::apache::thrift::protocol::T_STRUCT);
		iprot->readMessageEnd ();
		iprot->getTransport ()->readEnd ();
		::apache::thrift::TApplicationException x (
		    ::apache::thrift::TApplicationException::UNKNOWN_METHOD,
		    "Invalid method name: '" + fname + "'");
		oprot->writeMessageBegin (
		    fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
		x.write (oprot);
		oprot->writeMessageEnd ();
		oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();
		return true;
	      }
	    (this->*(pfn->second)) (seqid, iprot, oprot, callContext);
	    return true;
	  }

	  void
	  SpanReceiverProcessor::process_span (
	      int32_t, ::apache::thrift::protocol::TProtocol* iprot,
	      ::apache::thrift::protocol::TProtocol*, void* callContext)
	  {
	    void* ctx = NULL;
	    if (this->eventHandler_.get () != NULL)
	      {
		ctx = this->eventHandler_->getContext ("SpanReceiver.span",
						       callContext);
	      }
	    ::apache::thrift::TProcessorContextFreer freer (
		this->eventHandler_.get (), ctx, "SpanReceiver.span");

	    if (this->eventHandler_.get () != NULL)
	      {
		this->eventHandler_->preRead (ctx, "SpanReceiver.span");
	      }

	    SpanReceiver_span_args args;
	    args.read (iprot);
	    iprot->readMessageEnd ();
	    uint32_t bytes = iprot->getTransport ()->readEnd ();

	    if (this->eventHandler_.get () != NULL)
	      {
		this->eventHandler_->postRead (ctx, "SpanReceiver.span", bytes);
	      }

	    try
	      {
		iface_->span (args.span);
	      }
	    catch (const std::exception&)
	      {
		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->handlerError (ctx,
						       "SpanReceiver.span");
		  }
		return;
	      }

	    if (this->eventHandler_.get () != NULL)
	      {
		this->eventHandler_->asyncComplete (ctx, "SpanReceiver.span");
	      }

	    return;
	  }

	  ::boost::shared_ptr<::apache::thrift::TProcessor>
	  SpanReceiverProcessorFactory::getProcessor (
	      const ::apache::thrift::TConnectionInfo& connInfo)
	  {
	    ::apache::thrift::ReleaseHandler<SpanReceiverIfFactory> cleanup (
		handlerFactory_);
	    ::boost::shared_ptr<SpanReceiverIf> handler (
		handlerFactory_->getHandler (connInfo), cleanup);
	    ::boost::shared_ptr<::apache::thrift::TProcessor> processor (
		new SpanReceiverProcessor (handler));
	    return processor;
	  }
	}
      }
    }
  }
} // namespace

