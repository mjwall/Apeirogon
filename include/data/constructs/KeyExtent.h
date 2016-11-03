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
#ifndef KEYEXTENT_H_
#define KEYEXTENT_H_

#include "inputvalidation.h"
#include "../exceptions/ClientException.h"
#include "../exceptions/IllegalArgumentException.h"
#include "StructureDefinitions.h"
#include <string>
#include <iostream>
#include "value.h"
using namespace std;

namespace cclient
{
namespace data
{

using namespace exceptions;
class KeyExtent
{
public:
    KeyExtent (string flattenedText, Value *prevEndRow);

    KeyExtent (string tableIdIn, string endRowIn) :
        KeyExtent (tableIdIn, endRowIn, "")
    {

    }
    
    KeyExtent (KeyExtent *copy) : tableId(copy->getTableId()), endRow ( copy->getEndRow() ), prevEndRow(copy->getPrevEndRow())
    {
    }

    KeyExtent (string tableIdIn, string endRowIn, string prevEndRowIn)
    {
        if (IsEmpty (&tableIdIn))
        {
            throw IllegalArgumentException ("Table Id cannot be null");
        }
        if (!IsEmpty (&endRowIn) && !IsEmpty (&prevEndRowIn))
        {
            if (prevEndRowIn.compare (endRowIn) >= 0)
            {
                throw IllegalArgumentException ("PrevEndRow >= endRow");
            }
        }
        setTableId (tableIdIn);
        endRow = endRowIn;
        prevEndRow = prevEndRowIn;

    }

    static string
    createMetadataEntry (string table, string row)
    {
        string entry (table);
        if (IsEmpty (&row))
        {
            entry.append ("<");
        }
        else
        {
            entry.append (";");
            entry.append (row);
        }

        return entry;
    }

    virtual
    ~KeyExtent ();

    bool
    operator < (const KeyExtent &rhs) const
    {
        int result = tableId.compare (rhs.tableId);

        if (result < 0)
            return result;
        else if (result > 0)
            return false;

        result = endRow.compare (rhs.endRow);

        if (result < 0)
            return result;
        else if (result > 0)
            return false;

        result = prevEndRow.compare (rhs.prevEndRow);

        if (result < 0)
            return true;
        else
            return false;
    }

    bool
    operator == (const KeyExtent &rhs) const
    {
        int result = tableId.compare (rhs.tableId);

        if (result != 0)
            return (result == 0);

        result = endRow.compare (rhs.endRow);

        if (result != 0)
            return (result == 0);

        result = prevEndRow.compare (rhs.prevEndRow);

        if (result != 0)
            return (result == 0);

        return true;
    }

    void
    setTableId (string id)
    {
        tableId = id;
    }

    string
    getTableId ()
    {
        return tableId;
    }

    string
    getEndRow ()
    {
        return endRow;
    }

    string
    getPrevEndRow ()
    {
        return prevEndRow;
    }

protected:
    void
    setPrevEndRow (Value *prevEndRow)
    {
        std::pair<unsigned char *, size_t> valuePair = prevEndRow->getValue ();
        setPrevEndRow ((char*) valuePair.first, valuePair.second);

    }
    void
    setPrevEndRow (char *text, size_t text_len)
    {
        prevEndRow = string (text + 1, text_len - 1);
    }
    void
    decodeMetadataRow (string flattenedText)
    {
        int16_t semiPos = -1;
        int16_t ltPos = -1;

        if (flattenedText.at (flattenedText.size () - 1) == '<')
        {
            ltPos = flattenedText.size () - 1;
        }
        else
        {
            for (uint32_t i = 0; i < flattenedText.size (); i++)
            {
                if (flattenedText.at (i) == ';')
                {
                    semiPos = i;
                    break;
                }
            }
        }
        if (semiPos < 0 && ltPos < 0)
        {
            throw new ClientException ("Metadata row does not contain ; or <");
        }

        if (semiPos < 0)
        {
            tableId = flattenedText.substr (0, flattenedText.size () - 1);
            endRow = "";
        }
        else
        {

            tableId = flattenedText.substr (0, semiPos);

            endRow = flattenedText.substr (
                         semiPos + 1, flattenedText.size () - (semiPos + 1));
        }

    }
    string tableId;
    string endRow;
    string prevEndRow;
};

static const KeyExtent ROOT_TABLET_EXTENT (
    METADATA_TABLE_ID,
    KeyExtent::createMetadataEntry (METADATA_TABLE_ID, ""));

} /* namespace data */
} /* namespace cclient */
#endif /* KEYEXTENT_H_ */
