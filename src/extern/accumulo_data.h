/**
 * Hello, this is Apeirogon, a free and open implementation of a c++ 
 * big table connector. Copyright (C)  2015
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
#ifndef SRC_EXTERN_ACCUMULO_DATA_H_
#define SRC_EXTERN_ACCUMULO_DATA_H_

struct Key
{
  /**
   * Row part of key
   */
  uint8_t *row;
  uint32_t rowMaxSize;
  uint32_t rowLength;

  /**
   * Column family
   */
  uint32_t columnFamilyLength;
  uint8_t *colFamily;
  uint32_t columnFamilySize;

  /**
   * Column qualifier.
   */
  uint8_t *colQualifier;
  uint32_t colQualSize;
  uint32_t colQualLen;

  uint8_t *keyVisibility;
  uint32_t colVisSize;
  uint64_t timestamp;

  bool deleted;

};

struct Value
{
  // value array.
  uint8_t *value;
  // offset;
  uint16_t offset;
  // value size.
  size_t valueSize;
};

struct KeyValue
{
  struct Key *key;
  struct Value *value;
};

struct KeyValueList
{
  struct KeyValue **kvs;
  uint32_t kv_size;
};

struct Range
{
  struct Key *start;
  struct Key *stop;
  bool startKeyInclusive;
  bool stopKeyInclusive;
  bool infiniteStartKey;
  bool infiniteStopKey;
};

#endif /* SRC_EXTERN_ACCUMULO_DATA_H_ */
