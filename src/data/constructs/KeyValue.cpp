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

#include "../../../include/data/constructs/KeyValue.h"

namespace cclient
{
namespace data
{

KeyValue::KeyValue () :
	key (new Key ()), value (new Value()), my_alloc (true)
{

}

KeyValue::~KeyValue ()
{
	if (my_alloc)
		delete key;
	if (NULL != value)
		delete value;
}

void
KeyValue::setKey (Key *k, bool set_ownership)
{
	if (my_alloc) {
		delete key;
		my_alloc = set_ownership;
	}
	key = k;
}

Key *
KeyValue::getKey ()
{
	return key;
}

StreamInterface *
KeyValue::getStream ()
{
	return key->getStream ();
}

Value *
KeyValue::getValue ()
{
	return value;
}

void
KeyValue::setValue (Value *v)
{
	if (NULL != value) {
		delete value;

	}
	value = new Value ();
	value->setValue (v->getValue ().first, v->getValue ().second);
}

void
KeyValue::setValue (uint8_t *b, size_t size)
{
	if (NULL == value) {
		value = new Value ();
	}
	value->setValue (b, size);
}

uint64_t
KeyValue::write (OutputStream *outStream)
{

	key->write (outStream);

	return value->write (outStream);
}

KeyValue &
KeyValue::operator= (const KeyValue &other)
{

	key = other.key;

	std::pair<uint8_t*, uint32_t> p = other.value->getValue ();

	value->setValue (p.first, p.second);
	return *this;
}

bool
KeyValue::operator < (const KeyValue &rhs) const
{
	return (*(Key*) key->getStream () < *(Key*) (rhs.key->getStream ()));
}

bool
KeyValue::operator < (const KeyValue *rhs) const
{
	return *this < *rhs;

}

bool
KeyValue::operator == (const KeyValue & rhs) const
{
	return ((Key*) key->getStream () == (Key*) (rhs.key->getStream ()))
	       && (value == rhs.value);
}
bool
KeyValue::operator != (const KeyValue &rhs) const
{
	return !(*this == rhs);
}

bool
KeyValue::operator == (const KeyValue *rhs) const
{
	return *this == *rhs;
}
bool
KeyValue::operator != (const KeyValue *rhs) const
{
	return !(*this == *rhs);
}

} /* namespace data */
} /* namespace cclient */
