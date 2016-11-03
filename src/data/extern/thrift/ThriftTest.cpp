/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "../../../../include/data/extern/thrift/ThriftTest.h"

namespace org
{
  namespace apache
  {
    namespace accumulo
    {
      namespace core
      {
	namespace client
	{
	  namespace impl
	  {
	    namespace thrift
	    {

	      ThriftTest_success_args::~ThriftTest_success_args () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_success_args::read (
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
		    xfer += iprot->skip (ftype);
		    xfer += iprot->readFieldEnd ();
		  }

		xfer += iprot->readStructEnd ();

		return xfer;
	      }

	      uint32_t
	      ThriftTest_success_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("ThriftTest_success_args");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ThriftTest_success_pargs::~ThriftTest_success_pargs () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_success_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("ThriftTest_success_pargs");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ThriftTest_success_result::~ThriftTest_success_result () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_success_result::read (
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
	      ThriftTest_success_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin ("ThriftTest_success_result");

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

	      ThriftTest_success_presult::~ThriftTest_success_presult () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_success_presult::read (
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

	      ThriftTest_fails_args::~ThriftTest_fails_args () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_fails_args::read (
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
		    xfer += iprot->skip (ftype);
		    xfer += iprot->readFieldEnd ();
		  }

		xfer += iprot->readStructEnd ();

		return xfer;
	      }

	      uint32_t
	      ThriftTest_fails_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("ThriftTest_fails_args");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ThriftTest_fails_pargs::~ThriftTest_fails_pargs () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_fails_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("ThriftTest_fails_pargs");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ThriftTest_fails_result::~ThriftTest_fails_result () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_fails_result::read (
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
	      ThriftTest_fails_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin ("ThriftTest_fails_result");

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

	      ThriftTest_fails_presult::~ThriftTest_fails_presult () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_fails_presult::read (
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

	      ThriftTest_throwsError_args::~ThriftTest_throwsError_args () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_throwsError_args::read (
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
		    xfer += iprot->skip (ftype);
		    xfer += iprot->readFieldEnd ();
		  }

		xfer += iprot->readStructEnd ();

		return xfer;
	      }

	      uint32_t
	      ThriftTest_throwsError_args::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin ("ThriftTest_throwsError_args");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ThriftTest_throwsError_pargs::~ThriftTest_throwsError_pargs () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_throwsError_pargs::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {
		uint32_t xfer = 0;
		oprot->incrementRecursionDepth ();
		xfer += oprot->writeStructBegin (
		    "ThriftTest_throwsError_pargs");

		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		oprot->decrementRecursionDepth ();
		return xfer;
	      }

	      ThriftTest_throwsError_result::~ThriftTest_throwsError_result () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_throwsError_result::read (
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
		      case 1:
			if (ftype == ::apache::thrift::protocol::T_STRUCT)
			  {
			    xfer += this->ex.read (iprot);
			    this->__isset.ex = true;
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
	      ThriftTest_throwsError_result::write (
		  ::apache::thrift::protocol::TProtocol* oprot) const
	      {

		uint32_t xfer = 0;

		xfer += oprot->writeStructBegin (
		    "ThriftTest_throwsError_result");

		if (this->__isset.success)
		  {
		    xfer += oprot->writeFieldBegin (
			"success", ::apache::thrift::protocol::T_BOOL, 0);
		    xfer += oprot->writeBool (this->success);
		    xfer += oprot->writeFieldEnd ();
		  }
		else if (this->__isset.ex)
		  {
		    xfer += oprot->writeFieldBegin (
			"ex", ::apache::thrift::protocol::T_STRUCT, 1);
		    xfer += this->ex.write (oprot);
		    xfer += oprot->writeFieldEnd ();
		  }
		xfer += oprot->writeFieldStop ();
		xfer += oprot->writeStructEnd ();
		return xfer;
	      }

	      ThriftTest_throwsError_presult::~ThriftTest_throwsError_presult () throw ()
	      {
	      }

	      uint32_t
	      ThriftTest_throwsError_presult::read (
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
		      case 1:
			if (ftype == ::apache::thrift::protocol::T_STRUCT)
			  {
			    xfer += this->ex.read (iprot);
			    this->__isset.ex = true;
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
	      ThriftTestClient::success ()
	      {
		send_success ();
		return recv_success ();
	      }

	      void
	      ThriftTestClient::send_success ()
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("success",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ThriftTest_success_pargs args;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ThriftTestClient::recv_success ()
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
		if (fname.compare ("success") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ThriftTest_success_presult result;
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
		    "success failed: unknown result");
	      }

	      bool
	      ThriftTestClient::fails ()
	      {
		send_fails ();
		return recv_fails ();
	      }

	      void
	      ThriftTestClient::send_fails ()
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("fails",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ThriftTest_fails_pargs args;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ThriftTestClient::recv_fails ()
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
		if (fname.compare ("fails") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ThriftTest_fails_presult result;
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
		    "fails failed: unknown result");
	      }

	      bool
	      ThriftTestClient::throwsError ()
	      {
		send_throwsError ();
		return recv_throwsError ();
	      }

	      void
	      ThriftTestClient::send_throwsError ()
	      {
		int32_t cseqid = 0;
		oprot_->writeMessageBegin ("throwsError",
					   ::apache::thrift::protocol::T_CALL,
					   cseqid);

		ThriftTest_throwsError_pargs args;
		args.write (oprot_);

		oprot_->writeMessageEnd ();
		oprot_->getTransport ()->writeEnd ();
		oprot_->getTransport ()->flush ();
	      }

	      bool
	      ThriftTestClient::recv_throwsError ()
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
		if (fname.compare ("throwsError") != 0)
		  {
		    iprot_->skip (::apache::thrift::protocol::T_STRUCT);
		    iprot_->readMessageEnd ();
		    iprot_->getTransport ()->readEnd ();
		  }
		bool _return;
		ThriftTest_throwsError_presult result;
		result.success = &_return;
		result.read (iprot_);
		iprot_->readMessageEnd ();
		iprot_->getTransport ()->readEnd ();

		if (result.__isset.success)
		  {
		    return _return;
		  }
		if (result.__isset.ex)
		  {
		    throw result.ex;
		  }
		throw ::apache::thrift::TApplicationException (
		    ::apache::thrift::TApplicationException::MISSING_RESULT,
		    "throwsError failed: unknown result");
	      }

	      bool
	      ThriftTestProcessor::dispatchCall (
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
	      ThriftTestProcessor::process_success (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext ("ThriftTest.success",
							   callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx, "ThriftTest.success");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (ctx, "ThriftTest.success");
		  }

		ThriftTest_success_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (ctx, "ThriftTest.success",
						   bytes);
		  }

		ThriftTest_success_result result;
		try
		  {
		    result.success = iface_->success ();
		    result.__isset.success = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ThriftTest.success");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"success", ::apache::thrift::protocol::T_EXCEPTION,
			seqid);
		    x.write (oprot);
		    oprot->writeMessageEnd ();
		    oprot->getTransport ()->writeEnd ();
		    oprot->getTransport ()->flush ();
		    return;
		  }

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preWrite (ctx, "ThriftTest.success");
		  }

		oprot->writeMessageBegin ("success",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (ctx, "ThriftTest.success",
						    bytes);
		  }
	      }

	      void
	      ThriftTestProcessor::process_fails (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext ("ThriftTest.fails",
							   callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx, "ThriftTest.fails");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (ctx, "ThriftTest.fails");
		  }

		ThriftTest_fails_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (ctx, "ThriftTest.fails",
						   bytes);
		  }

		ThriftTest_fails_result result;
		try
		  {
		    result.success = iface_->fails ();
		    result.__isset.success = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (ctx,
							   "ThriftTest.fails");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"fails", ::apache::thrift::protocol::T_EXCEPTION,
			seqid);
		    x.write (oprot);
		    oprot->writeMessageEnd ();
		    oprot->getTransport ()->writeEnd ();
		    oprot->getTransport ()->flush ();
		    return;
		  }

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preWrite (ctx, "ThriftTest.fails");
		  }

		oprot->writeMessageBegin ("fails",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (ctx, "ThriftTest.fails",
						    bytes);
		  }
	      }

	      void
	      ThriftTestProcessor::process_throwsError (
		  int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
		  ::apache::thrift::protocol::TProtocol* oprot,
		  void* callContext)
	      {
		void* ctx = NULL;
		if (this->eventHandler_.get () != NULL)
		  {
		    ctx = this->eventHandler_->getContext (
			"ThriftTest.throwsError", callContext);
		  }
		::apache::thrift::TProcessorContextFreer freer (
		    this->eventHandler_.get (), ctx, "ThriftTest.throwsError");

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preRead (ctx,
						  "ThriftTest.throwsError");
		  }

		ThriftTest_throwsError_args args;
		args.read (iprot);
		iprot->readMessageEnd ();
		uint32_t bytes = iprot->getTransport ()->readEnd ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postRead (ctx,
						   "ThriftTest.throwsError",
						   bytes);
		  }

		ThriftTest_throwsError_result result;
		try
		  {
		    result.success = iface_->throwsError ();
		    result.__isset.success = true;
		  }
		catch (ThriftSecurityException &ex)
		  {
		    result.ex = ex;
		    result.__isset.ex = true;
		  }
		catch (const std::exception& e)
		  {
		    if (this->eventHandler_.get () != NULL)
		      {
			this->eventHandler_->handlerError (
			    ctx, "ThriftTest.throwsError");
		      }

		    ::apache::thrift::TApplicationException x (e.what ());
		    oprot->writeMessageBegin (
			"throwsError", ::apache::thrift::protocol::T_EXCEPTION,
			seqid);
		    x.write (oprot);
		    oprot->writeMessageEnd ();
		    oprot->getTransport ()->writeEnd ();
		    oprot->getTransport ()->flush ();
		    return;
		  }

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->preWrite (ctx,
						   "ThriftTest.throwsError");
		  }

		oprot->writeMessageBegin ("throwsError",
					  ::apache::thrift::protocol::T_REPLY,
					  seqid);
		result.write (oprot);
		oprot->writeMessageEnd ();
		bytes = oprot->getTransport ()->writeEnd ();
		oprot->getTransport ()->flush ();

		if (this->eventHandler_.get () != NULL)
		  {
		    this->eventHandler_->postWrite (ctx,
						    "ThriftTest.throwsError",
						    bytes);
		  }
	      }

	      ::boost::shared_ptr<::apache::thrift::TProcessor>
	      ThriftTestProcessorFactory::getProcessor (
		  const ::apache::thrift::TConnectionInfo& connInfo)
	      {
		::apache::thrift::ReleaseHandler<ThriftTestIfFactory> cleanup (
		    handlerFactory_);
		::boost::shared_ptr<ThriftTestIf> handler (
		    handlerFactory_->getHandler (connInfo), cleanup);
		::boost::shared_ptr<::apache::thrift::TProcessor> processor (
		    new ThriftTestProcessor (handler));
		return processor;
	      }
	    }
	  }
	}
      }
    }
  }
} // namespace
