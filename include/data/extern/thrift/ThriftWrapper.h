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

#ifndef THRIFTWRAPPER_H_
#define THRIFTWRAPPER_H_

#include "../../constructs/security/AuthInfo.h"
#include "../../constructs/security/Authorizations.h"
#include "../../constructs/inputvalidation.h"
#include "../../constructs/IterInfo.h"
#include "../../constructs/Key.h"
#include "../../constructs/Range.h"
#include "../../constructs/KeyValue.h"
#include "../../constructs/Mutation.h"
#include "../../constructs/KeyExtent.h"
#include "../../constructs/column.h"
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_stream.hpp>

#include "../../streaming/ByteOutputStream.h"
#include "../../streaming/NetworkOrderStream.h"
#include "../../streaming/input/NetworkOrderInputStream.h"
#include "data_types.h"
#include "security_types.h"
namespace interconnect
{

using namespace cclient::data;
using namespace cclient::data::streams;

using namespace boost::iostreams;

class ThriftWrapper
{
protected:
	static string decompress(const char *compressed, uint32_t size)
	{
		std::string decompressed;

		boost::iostreams::filtering_ostream os;

		os.push(boost::iostreams::gzip_decompressor());
		os.push(boost::iostreams::back_inserter(decompressed));

		boost::iostreams::write(os, compressed, size);

		return decompressed;
	}
public:

	static cclient::data::KeyExtent *convert( ::org::apache::accumulo::core::data::thrift::TKeyExtent extent)
	{
		return new KeyExtent(extent.table,extent.endRow,extent.prevEndRow);

	}
	static vector<cclient::data::Column*> convert( std::vector< ::org::apache::accumulo::core::data::thrift::TColumn> columns)
	{
		vector<cclient::data::Column*> cols;
		for(auto it = columns.begin(); it != columns.end(); it++) {
			cols.push_back(new cclient::data::Column((*it).columnFamily,(*it).columnQualifier,(*it).columnVisibility));
		}

		return cols;
	}

	static vector<cclient::data::IterInfo*> convert( vector<::org::apache::accumulo::core::data::thrift::IterInfo> iters)
	{
		vector<cclient::data::IterInfo*> convertedIters;
		for (auto it = iters.begin(); it != iters.end(); it++) {
			cclient::data::IterInfo *iterInfo = new cclient::data::IterInfo( (*it).iterName, (*it).className, (*it).priority );
			convertedIters.push_back(iterInfo);
		}

		return convertedIters;
	}
	static cclient::data::security::AuthInfo *convert( org::apache::accumulo::core::security::thrift::TCredentials creds)
	{
		EndianInputStream inputStream((char*)creds.token.c_str(),creds.token.length());
		int compressedLength = inputStream.readInt();
		char *array = new char[ compressedLength ];
		string decompressed = decompress( array, compressedLength );
		delete [] array;
		return new cclient::data::security::AuthInfo(creds.principal,decompressed,creds.instanceId);
	}
	static org::apache::accumulo::core::security::thrift::TCredentials convert(
	        cclient::data::security::AuthInfo *authInfo)
	{
		org::apache::accumulo::core::security::thrift::TCredentials stackAuthInfo;
		stackAuthInfo.instanceId = authInfo->getInstanceId();
		// password token needs to be compressed

		std::string compressedString;
		{
			filtering_ostream compressingStream;
			compressingStream.push(
			        boost::iostreams::gzip_compressor(
			                gzip_params(gzip::best_compression)));
			compressingStream.push(
			        boost::iostreams::back_inserter(compressedString));
			compressingStream << authInfo->getPassword();
			boost::iostreams::close(compressingStream);
		}

		BigEndianByteStream writeStream(0);
		writeStream.writeInt(compressedString.size());
		writeStream.write(compressedString.c_str(), compressedString.size());

		stackAuthInfo.tokenClassName =
		        "org.apache.accumulo.core.client.security.tokens.PasswordToken";
		stackAuthInfo.principal = authInfo->getUserName();

		stackAuthInfo.token = string(writeStream.getByteArray(),
		                             writeStream.getPos());
		return stackAuthInfo;
	}



	static vector<org::apache::accumulo::core::data::thrift::IterInfo> convert(
	        vector<cclient::data::IterInfo*> *iters)
	{

		vector<org::apache::accumulo::core::data::thrift::IterInfo> convertedIters;
		if (!IsEmpty(iters)) {
			for (auto it = iters->begin(); it != iters->end(); it++) {
				org::apache::accumulo::core::data::thrift::IterInfo iterInfo;
				iterInfo.className = (*it)->getClass();
				iterInfo.iterName = (*it)->getName();
				iterInfo.priority = (*it)->getPriority();
				convertedIters.push_back(iterInfo);
			}
		}

		return convertedIters;

	}

	static vector<org::apache::accumulo::core::data::thrift::TMutation> convert(
	        vector<cclient::data::Mutation*> *iters)
	{

		vector<org::apache::accumulo::core::data::thrift::TMutation> convertedMutations;
		if (!IsEmpty(iters)) {
			for (auto it = iters->begin(); it != iters->end(); it++) {
				org::apache::accumulo::core::data::thrift::TMutation mut;
				mut.row = (*it)->getRow();

				mut.data = (*it)->getDataStr();
				mut.entries = (*it)->size();
				convertedMutations.push_back(mut);
			}
		}

		return convertedMutations;

	}

	static Range* convert(org::apache::accumulo::core::data::thrift::TRange range)
	{
		Key *startKey = convert(range.start);
		Key *endKey = convert(range.stop);
		return new Range(startKey,range.startKeyInclusive,endKey,range.stopKeyInclusive);

	}

	static org::apache::accumulo::core::data::thrift::ScanBatch convert(
	        vector<ScanIdentifier<KeyExtent*, Range*> *> *rangeIdentifiers)
	{

		using namespace org::apache::accumulo::core::data::thrift;
		ScanBatch littleBatch;

		//typedef std::map<class TKeyExtent, std::vector<class TRange> >  ScanBatch;
		for (auto it : *rangeIdentifiers) {

			ScanIdentifier<KeyExtent*, Range*> *identifier = it;
			vector<KeyExtent*> extents = identifier->getGlobalMapping();
			for (KeyExtent *ot : extents) {
				TKeyExtent keyExtent;

				keyExtent.table = ot->getTableId();
				string endRow = ot->getEndRow();
				if (!IsEmpty(&endRow))
					keyExtent.endRow = ot->getEndRow();

				string prevEndRow = ot->getEndRow();
				if (!IsEmpty(&prevEndRow))
					keyExtent.prevEndRow = ot->getPrevEndRow();


				vector<TRange> thriftRanges;
				vector<Range*> ranges = identifier->getIdentifiers(ot);
				for (Range *rt : ranges) {

					TRange range = convert(rt);
					thriftRanges.push_back(range);

				}
				littleBatch.insert(
				        std::pair<TKeyExtent, vector<TRange>>(keyExtent,
				                        thriftRanges));
			}

		}

		return littleBatch;
	}

	static org::apache::accumulo::core::data::thrift::TKey convert(Key *key)
	{
		org::apache::accumulo::core::data::thrift::TKey newKey;
		/*
		 * std::string row;
		 std::string colFamily;
		 std::string colQualifier;
		 std::string colVisibility;
		 int64_t timestamp;
		 */
		if (NULL != key) {
			std::pair<char*, size_t> rowPair = key->getRow();
			newKey.row = string(rowPair.first, rowPair.second);

			std::pair<char*, size_t> cfPair = key->getColFamily();
			if (cfPair.second > 0)
				newKey.colFamily = string(cfPair.first, cfPair.second);

			std::pair<char*, size_t> cqPair = key->getColQualifier();
			if (cqPair.second > 0)
				newKey.colQualifier = string(cqPair.first, cqPair.second);

			std::pair<char*, size_t> cvPair = key->getColVisibility();
			if (cvPair.second > 0)
				newKey.colVisibility = string(cvPair.first, cvPair.second);

			newKey.timestamp = key->getTimeStamp();
		} else {
			newKey.row = "";
			newKey.colFamily = "";
			newKey.colQualifier = "";
			newKey.colVisibility = "";

		}

		return newKey;
	}

	static Key *convert(org::apache::accumulo::core::data::thrift::TKey key)
	{
		Key *newKey = new Key();
		newKey->setRow(key.row);
		newKey->setColFamily(key.colFamily);
		newKey->setColQualifier(key.colQualifier);
		newKey->setColVisibility(key.colVisibility);
		newKey->setTimeStamp(key.timestamp);
		return newKey;
	}

	static org::apache::accumulo::core::data::thrift::TKeyExtent convert(
	        KeyExtent *ot)
	{
		org::apache::accumulo::core::data::thrift::TKeyExtent keyExtent;
		keyExtent.table = ot->getTableId();
		string endRow = ot->getEndRow();

		if (!IsEmpty(&endRow))
			keyExtent.endRow = endRow;

		string prevEndRow = ot->getPrevEndRow();
		if (!IsEmpty(&prevEndRow))
			keyExtent.prevEndRow = prevEndRow;

		return keyExtent;
	}

	static vector<KeyValue*> *convert(
	        vector<org::apache::accumulo::core::data::thrift::TKeyValue> tkvVec)
	{
		vector<KeyValue*> *newvector = new vector<KeyValue*>();
		Key *prevKey = NULL;

		for (uint32_t i = 0; i < tkvVec.size(); i++) {

			org::apache::accumulo::core::data::thrift::TKeyValue tkv =
			        tkvVec.at(i);
			Key *key = new Key();
			if (!IsEmpty(&(tkv.key.row))) {
				key->setRow(tkv.key.row.c_str(), tkv.key.row.size());
			} else {
				if (NULL != prevKey) {
					std::pair<char*, size_t> prevRow = prevKey->getRow();
					key->setRow(prevRow.first, prevRow.second);
				}

			}
			if (!IsEmpty(&(tkv.key.colFamily))) {
				key->setColFamily(tkv.key.colFamily.c_str(),
				                  tkv.key.colFamily.size());
			} else {
				if (NULL != prevKey) {
					std::pair<char*, size_t> prevCf = prevKey->getColFamily();
					key->setColFamily(prevCf.first, prevCf.second);
				}
			}
			if (!IsEmpty(&(tkv.key.colQualifier))) {
				key->setColQualifier(tkv.key.colQualifier.c_str(),
				                     tkv.key.colQualifier.size());
			} else {
				if (NULL != prevKey) {
					std::pair<char*, size_t> prevCq =
					        prevKey->getColQualifier();
					key->setColQualifier(prevCq.first, prevCq.second);
				}
			}

			if (!IsEmpty(&(tkv.key.colVisibility))) {
				key->setColVisibility(tkv.key.colVisibility.c_str(),
				                      tkv.key.colVisibility.size());
			} else {
				if (NULL != prevKey) {
					std::pair<char*, size_t> prevCv =
					        prevKey->getColVisibility();
					key->setColVisibility(prevCv.first, prevCv.second);
				}
			}

			key->setTimeStamp(tkv.key.timestamp);
			KeyValue *kv = new KeyValue();
			kv->setKey(key,true);
			kv->setValue((uint8_t*) tkv.value.c_str(), tkv.value.size());

			newvector->push_back(kv);

			prevKey = key;
		}
		return newvector;
	}

	static org::apache::accumulo::core::data::thrift::TRange convert(
	        Range *range)
	{
		org::apache::accumulo::core::data::thrift::TRange newRange;
		if (NULL != range->getStartKey())
			newRange.start = convert(range->getStartKey());

		if (NULL != range->getStopKey())
			newRange.stop = convert(range->getStopKey());

		newRange.startKeyInclusive = range->getStartKeyInclusive();
		newRange.stopKeyInclusive = range->getStopKeyInclusive();
		newRange.infiniteStartKey = range->getInfiniteStartKey();
		newRange.infiniteStopKey = range->getInfiniteStopKey();
		return newRange;
	}

	static vector<org::apache::accumulo::core::data::thrift::TColumn> convert(
	        vector<cclient::data::Column*> *columns)
	{

		vector<org::apache::accumulo::core::data::thrift::TColumn> convertedColumns;

		if (!IsEmpty(columns)) {
			for (auto it = columns->begin(); it != columns->end(); it++) {
				org::apache::accumulo::core::data::thrift::TColumn column;
				std::pair<char*, size_t> cf = (*it)->getColFamily();
				column.columnFamily = string(cf.first, cf.second);
				std::pair<char*, size_t> cq = (*it)->getColQualifier();
				if (cq.second > 0)
					column.columnQualifier = string(cq.first, cq.second);
				std::pair<char*, size_t> cv = (*it)->getColVisibility();
				if (cv.second > 0)
					column.columnVisibility = string(cv.first, cv.second);

				convertedColumns.push_back(column);
			}
		}

		return convertedColumns;

	}

	static vector<string> convert(Authorizations *auths)
	{

		return auths->getAuthorizations();

	}

protected:
	ThriftWrapper()
	{

	}
	virtual ~ThriftWrapper()
	{

	}
}
;

} /* namespace interconnect */
#endif /* THRIFTWRAPPER_H_ */

