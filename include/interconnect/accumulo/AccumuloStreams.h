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

#ifndef SRC_INTERCONNECT_ACCUMULO_ACCUMULOSTREAMS_H_
#define SRC_INTERCONNECT_ACCUMULO_ACCUMULOSTREAMS_H_

#include "../../scanner/impl/Scanner.h"
#include "../../writer/impl/SinkImpl.h"

namespace interconnect
{
using namespace scanners;
using namespace writer;
class AccumuloStreams : public Scanner, public BatchWriter
{
public:
    AccumuloStreams (Instance *instance,
                     TableOperations<KeyValue*, ResultBlock<KeyValue*>> *tops,
                     Authorizations *auths, uint16_t threads);
    virtual
    ~AccumuloStreams ();

};

} /* namespace data */

#endif /* SRC_INTERCONNECT_ACCUMULO_ACCUMULOSTREAMS_H_ */
