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
#ifndef KEY
#define KEY 1

#include "../streaming/Streams.h"

#include <stdint.h>

#include <stdio.h>
#include <string.h>

namespace cclient
{
namespace data
{

using namespace cclient::data::streams;

/**
 * Code is partially based on some code I wrote in 2009 for a personal project, however
 * this code is replicated from the Accumulo Key class
 */
class Key : public StreamInterface
{

public:

    Key ();

    Key (Key *other) : Key()
    {
        std::pair<char*, size_t> row = other->getRow ();

        setRow (row.first, row.second);

        std::pair<char*, size_t> cf = other->getColFamily ();

        setColFamily (cf.first, cf.second);

        std::pair<char*, size_t> cq = other->getColQualifier ();

        setColQualifier (cq.first, cq.second);

        std::pair<char*, size_t> cv = other->getColVisibility ();

        setColVisibility (cv.first, cv.second);

        setTimeStamp (other->getTimeStamp ());

        setDeleted (other->isDeleted ());
    }

    virtual
    ~Key ();


    void
    setRow (const char *r, uint32_t size);

    void setRow(string row )
    {
        setRow(row.c_str(),row.length());
    }

    std::pair<char*, size_t>
    getRow ()
    {
        return std::make_pair (row, rowLength);
    }

    string
    getRowStr ()
    {
        return string (row, rowLength);
    }

    void
    setColFamily (const char *r, uint32_t size);

    void
    setColFamily (string st)
    {
        setColFamily (st.c_str (), st.size ());
    }

    inline std::pair<char*, size_t>
    getColFamily ()
    {
        return std::make_pair (colFamily, columnFamilyLength);
    }

    inline string
    getColFamilyStr ()
    {
        return string (colFamily, columnFamilyLength);
    }

    void
    setColQualifier (const char *r, uint32_t size, uint32_t offset = 0);

    void
    setColQualifier (string st)
    {
        setColQualifier (st.c_str (), st.size (), 0);
    }

    std::pair<char*, size_t>
    getColQualifier ()
    {
        return std::make_pair (colQualifier, colQualLen);
    }

    string
    getColQualifierStr ()
    {
        return string (colQualifier, colQualLen);
    }

    void
    setColVisibility (const char *r, uint32_t size);

    void
    setColVisibility (string st)
    {
        setColVisibility (st.c_str (), st.size ());
    }

    std::pair<char*, size_t>
    getColVisibility ()
    {
        return std::make_pair (keyVisibility, colVisSize);
    }

    string
    getColVisibilityStr ()
    {
        return string (keyVisibility, colVisSize);
    }

    uint64_t
    getTimeStamp ()
    {
        return timestamp;
    }

    void
    setTimeStamp (const uint64_t ts)
    {
        timestamp = ts;
    }

    bool
    isDeleted ()
    {
        return deleted;
    }

    void
    setDeleted (bool isDeleted)
    {
        deleted = isDeleted;
    }

    StreamInterface *
    getStream ()
    {
        return this;
    }

    bool
    operator < (const Key &rhs) const;

    bool
    operator < (const Key *rhs) const
    {
        cout << "ptr compare" << endl;
        return *this < *rhs;
    }

    bool
    operator == (const Key & rhs) const;
    bool
    operator != (const Key &rhs) const
    {
        return !(*this == rhs);
    }

    bool
    operator == (const Key *rhs) const
    {
        return *this == *rhs;
    }
    bool
    operator != (const Key *rhs) const
    {
        return !(*this == *rhs);
    }

//	friend ostream &operator<<(ostream&os,const Key *rhs);
    //friend ostream &operator<<(ostream&os,const Key &rhs);

    friend inline std::ostream &
    operator << (std::ostream &out, Key &rhs)
    {
        pair<char*, size_t> row = rhs.getRow ();
        out << string (row.first, row.second) << " ";
        pair<char*, size_t> cf = rhs.getColFamily ();
        pair<char*, size_t> cq = rhs.getColQualifier ();
        out << string (cf.first, cf.second) << ":"
            << string (cq.first, cq.second) << " [";
        pair<char*, size_t> viz = rhs.getColVisibility ();
        out << string (viz.first, viz.second) << "] " << rhs.getTimeStamp ();
        return out;
    }

    friend inline std::ostream &
    operator << (std::ostream &out, Key *rhs)
    {
        return operator<< (out, *rhs);
    }

    uint64_t
    write (OutputStream *outStream);

    uint64_t
    read (InputStream *in);
protected:

    /**
     * Row part of key
     */
    char *row;
    uint32_t rowMaxSize;
    uint32_t rowLength;

    /**
     * Column family
     */
    uint32_t columnFamilyLength;
    char *colFamily;
    uint32_t columnFamilySize;

    /**
     * Column qualifier.
     */
    char *colQualifier;
    uint32_t colQualSize;
    uint32_t colQualLen;
    char *keyVisibility;
    uint32_t colVisSize;
    uint64_t timestamp;
    bool deleted;

    /**
     * copied from writable comparable utils
     */
    static int
    compareBytes (const char *b1, int s1, int l1, const char *b2, int s2,
                  int l2)
    {
        int end1 = s1 + l1;
        int end2 = s2 + l2;
        for (int i = s1, j = s2; i < end1 && j < end2; i++, j++)
        {
            int a = (b1[i] & 0xff);
            int b = (b2[j] & 0xff);
            if (a != b)
            {
                return a - b;
            }
        }
        return l1 - l2;
    }
};

} /* namespace data */
}/* namespace cclient */

#endif

