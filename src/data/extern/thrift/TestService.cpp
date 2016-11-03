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
#include "../../../../include/data/extern/thrift/TestService.h"

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

	  TestService_checkTrace_args::~TestService_checkTrace_args () throw ()
	  {
	  }

	  uint32_t
	  TestService_checkTrace_args::read (
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
			xfer += this->tinfo.read (iprot);
			this->__isset.tinfo = true;
		      }
		    else
		      {
			xfer += iprot->skip (ftype);
		      }
		    break;
		  case 2:
		    if (ftype == ::apache::thrift::protocol::T_STRING)
		      {
			xfer += iprot->readString (this->message);
			this->__isset.message = true;
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
	  TestService_checkTrace_args::write (
	      ::apache::thrift::protocol::TProtocol* oprot) const
	  {
	    uint32_t xfer = 0;
	    oprot->incrementRecursionDepth ();
	    xfer += oprot->writeStructBegin ("TestService_checkTrace_args");

	    xfer += oprot->writeFieldBegin (
		"tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	    xfer += this->tinfo.write (oprot);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin (
		"message", ::apache::thrift::protocol::T_STRING, 2);
	    xfer += oprot->writeString (this->message);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldStop ();
	    xfer += oprot->writeStructEnd ();
	    oprot->decrementRecursionDepth ();
	    return xfer;
	  }

	  TestService_checkTrace_pargs::~TestService_checkTrace_pargs () throw ()
	  {
	  }

	  uint32_t
	  TestService_checkTrace_pargs::write (
	      ::apache::thrift::protocol::TProtocol* oprot) const
	  {
	    uint32_t xfer = 0;
	    oprot->incrementRecursionDepth ();
	    xfer += oprot->writeStructBegin ("TestService_checkTrace_pargs");

	    xfer += oprot->writeFieldBegin (
		"tinfo", ::apache::thrift::protocol::T_STRUCT, 1);
	    xfer += (*(this->tinfo)).write (oprot);
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldBegin (
		"message", ::apache::thrift::protocol::T_STRING, 2);
	    xfer += oprot->writeString ((*(this->message)));
	    xfer += oprot->writeFieldEnd ();

	    xfer += oprot->writeFieldStop ();
	    xfer += oprot->writeStructEnd ();
	    oprot->decrementRecursionDepth ();
	    return xfer;
	  }

	  TestService_checkTrace_result::~TestService_checkTrace_result () throw ()
	  {
	  }

	  uint32_t
	  TestService_checkTrace_result::read (
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
		  case 0:
		    if (ftype == ::apache::thrift::protocol::T_BOOL)
		      {
			xfer += iprot->readBool (this->success);
			this->__isset.success = true;
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
	  TestService_checkTrace_result::write (
	      ::apache::thrift::protocol::TProtocol* oprot) const
	  {

	    uint32_t xfer = 0;

	    xfer += oprot->writeStructBegin ("TestService_checkTrace_result");

	    if (this->__isset.success)
	      {
		xfer += oprot->writeFieldBegin (
		    "success", ::apache::thrift::protocol::T_BOOL, 0);
		xfer += oprot->writeBool (this->success);
		xfer += oprot->writeFieldEnd ();
	      }
	    xfer += oprot->writeFieldStop ();
	    xfer += oprot->writeStructEnd ();
	    return xfer;
	  }

	  TestService_checkTrace_presult::~TestService_checkTrace_presult () throw ()
	  {
	  }

	  uint32_t
	  TestService_checkTrace_presult::read (
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
		  case 0:
		    if (ftype == ::apache::thrift::protocol::T_BOOL)
		      {
			xfer += iprot->readBool ((*(this->success)));
			this->__isset.success = true;
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

	  bool
	  TestServiceClient::checkTrace (const TInfo& tinfo,
					 const std::string& message)
	  {
	    send_checkTrace (tinfo, message);
	    return recv_checkTrace ();
	  }

	  void
	  TestServiceClient::send_checkTrace (const TInfo& tinfo,
					      const std::string& message)
	  {
	    int32_t cseqid = 0;
	    oprot_->writeMessageBegin ("checkTrace",
				       ::apache::thrift::protocol::T_CALL,
				       cseqid);

	    TestService_checkTrace_pargs args;
	    args.tinfo = &tinfo;
	    args.message = &message;
	    args.write (oprot_);

	    oprot_->writeMessageEnd ();
	    oprot_->getTransport ()->writeEnd ();
	    oprot_->getTransport ()->flush ();
	  }

	  bool
	  TestServiceClient::recv_checkTrace ()
	  {

	    int32_t rseqid = 0;
	    std::string fname;
	    ::apache::thrift::protocol::TMessageType mtype;

	    iprot_->readMessageBegin (fname, mtype, rseqid);
	    if (mtype == ::apache::thrift::protocol::T_EXCEPTION)
	      {
		::apache::thrift::TApplicationException x;
		x.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();
		throw x;
	      }
	    if (mtype != ::apache::thrift::protocol::T_REPLY)
	      {
		iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();
	      }
	    if (fname.compare ("checkTrace") != 0)
	      {
		iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();
	      }
	    bool _return;
	    TestService_checkTrace_presult result;
	    result.success = &_return;
	    result.read (iprot_);
	    iprot_->readMessageEnd ();
	    iprot_->getTransport ()->readEnd ();

	    if (result.__isset.success)
	      {
		return _return;
	      }
	    throw ::apache::thrift::TApplicationException (
		::apache::thrift::TApplicationException::MISSING_RESULT,
		"checkTrace failed: unknown result");
	  }

	  bool
	  TestServiceProcessor::dispatchCall (
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
	  TestServiceProcessor::process_checkTrace (
	      int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
	      ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
	  {
	    void* ctx = NULL;
	    if (this->eventHandler_.get () != NULL)
	      {
		ctx = this->eventHandler_->getContext ("TestService.checkTrace",
						       callContext);
	      }
	    ::apache::thrift::TProcessorContextFreer freer (
		this->eventHandler_.get (), ctx, "TestService.checkTrace");

	    if (this->eventHandler_.get () != NULL)
	      {
		this->eventHandler_->preRead (ctx, "TestService.checkTrace");
	      }

	    TestService_checkTrace_args args;
	    args.read (iprot);
	    iprot->readMessageEnd ();
	    uint32_t bytes = iprot->getTransport ()->readEnd ();

	    if (this->eventHandler_.get () != NULL)
	      {
		this->eventHandler_->postRead (ctx, "TestService.checkTrace",
					       bytes);
	      }

	    TestService_checkTrace_result result;
	    try
	      {
		result.success = iface_->checkTrace (args.tinfo, args.message);
		result.__isset.success = true;
	      }
	    catch (const std::exception& e)
	      {
		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->handlerError (
			ctx, "TestService.checkTrace");
		  }

		::apache::thrift::TApplicationException x (e.what ());
		oprot->writeMessageBegin (
		    "checkTrace", ::apache::thrift::protocol::T_EXCEPTION,
		    seqid);
		x.write (oprot);
		oprot->writeMessageEnd ();
		oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();
		return;
	      }

	    if (this->eventHandler_.get () != NULL)
	      {
		this->eventHandler_->preWrite (ctx, "TestService.checkTrace");
	      }

	    oprot->writeMessageBegin ("checkTrace",
				      ::apache::thrift::protocol::T_REPLY,
				      seqid);
	    result.write (oprot);
	    oprot->writeMessageEnd ();
	    bytes = oprot->getTransport ()->writeEnd ();
	    oprot->getTransport ()->flush ();

	    if (this->eventHandler_.get () != NULL)
	      {
		this->eventHandler_->postWrite (ctx, "TestService.checkTrace",
						bytes);
	      }
	  }

	  ::boost::shared_ptr<::apache::thrift::TProcessor>
	  TestServiceProcessorFactory::getProcessor (
	      const ::apache::thrift::TConnectionInfo& connInfo)
	  {
	    ::apache::thrift::ReleaseHandler<TestServiceIfFactory> cleanup (
		handlerFactory_);
	    ::boost::shared_ptr<TestServiceIf> handler (
		handlerFactory_->getHandler (connInfo), cleanup);
	    ::boost::shared_ptr<::apache::thrift::TProcessor> processor (
		new TestServiceProcessor (handler));
	    return processor;
	  }
	}
      }
    }
  }
} // namespace

