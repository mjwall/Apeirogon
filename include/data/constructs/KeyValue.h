/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * Key/value connector. Copyright (C)  2015
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef KEYVALUE_H_
#define KEYVALUE_H_

#include <stdint.h>
#include "Key.h"
#include "value.h"
#include "rkey.h"
#include "../streaming/Streams.h"




namespace cclient
{
namespace data
{

class KeyValue : public StreamInterface
{
public:
	KeyValue();


	virtual ~KeyValue();

	void setKey(Key *k, bool set_ownership = false);

	Key *getKey();
	
	inline bool hasOwnerShip()
	{
	  return my_alloc;
	}

	StreamInterface *getStream();

	Value *getValue();
	void setValue(Value *v);
	void setValue(uint8_t *b, size_t size);
	uint64_t write(OutputStream *outStream);
	KeyValue &operator=(const KeyValue &other);
	bool operator <(const KeyValue &rhs) const;
	bool operator <(const KeyValue *rhs) const;
	bool operator == (const KeyValue *rhs) const;
	bool operator == (const KeyValue & rhs) const;
	bool operator != (const KeyValue &rhs) const;
	bool operator != (const KeyValue *rhs) const;




protected:
	Key *key;
	Value *value;
	bool my_alloc;

};

} /* namespace data */
} /* namespace cclient */
#endif /* KEYVALUE_H_ */
