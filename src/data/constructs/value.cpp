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

#include <utility>
#include <iostream>

using namespace std;

#include "../../../include/data/constructs/value.h"


using namespace cclient::data;


Value::Value () :
    valueSize (0)
{
    value = new uint8_t[0];
    offset = 0;
}

Value::~Value ()
{
    if (value != NULL)
        delete[] value;
}

/**
 * Sets the value using the value and the corresponding size and offset.
 */
void
Value::setValue (uint8_t *val, size_t size, uint32_t ptrOff)
{

    if ((size + ptrOff) > valueSize)
    {
        uint8_t *oldVal = value;
        value = new uint8_t[size + ptrOff];
        if (oldVal != NULL)
        {
            memcpy (value, oldVal, ptrOff);
            delete[] oldVal;
        }
        valueSize = size + ptrOff;
    }

    memcpy (value + ptrOff, val, size);

    offset = size;

}

/**
 * Appends val to the current value.
 */
void
Value::append (uint8_t *val, size_t size)
{
    if ((size + offset) > valueSize)
    {
        uint8_t *oldVal = value;
        value = new uint8_t[size + offset];
        memcpy (value, oldVal, offset);
        delete[] oldVal;
        valueSize = size + offset;
    }

    memcpy (value + offset, val, size);

    offset += size;
}

/**
 * Deep copies the object.
 */
void
Value::deepCopy (Value *v)
{

    v->value = value;
    v->valueSize = valueSize;
    v->offset = offset;
    value = NULL;
    offset = 0;
    valueSize = 0;
}

uint8_t *
Value::data ()
{
    return value;
}

size_t
Value::size ()
{
    return offset;
}

StreamInterface *
Value::getStream ()
{
    return this;
}

std::pair<uint8_t*, size_t>
Value::getValue () const
{
    return make_pair (value, offset);
}

uint64_t
Value::write (OutputStream *outStream)
{
    outStream->writeInt (offset);
    return outStream->writeBytes (value, offset);
}

uint64_t
Value::read(InputStream *in)
{
    if (value != NULL)
        delete[] value;

    uint32_t size = in->readInt();
    value = new uint8_t[ size ];
    return in->readBytes(value, size );
}

bool
Value::operator == (const Value & rhs) const
{
    if (valueSize == rhs.valueSize && offset == rhs.offset)
    {
        return (memcmp (value, rhs.value, valueSize) == 0);
    }
    else
        return false;
}

bool
Value::operator != (const Value &rhs) const
{
    return !(*this == rhs);
}
