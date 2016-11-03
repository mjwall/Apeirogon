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

#ifndef SRC_INTERCONNECT_ROOTINTERFACE_H_
#define SRC_INTERCONNECT_ROOTINTERFACE_H_

#include <string>

#include "ClientInterface.h"
using namespace std;

#include <boost/shared_ptr.hpp>
using boost::shared_ptr;

#include "tableOps/TableOperations.h"
#include "AccumuloConnector.h"
#include "../scanner/Source.h"
#include "../scanner/constructs/Results.h"
#include "../data/constructs/client/Instance.h"
#include "../data/constructs/security/AuthInfo.h"

namespace interconnect
{
using namespace cclient::data;
using namespace cclient::data::security;

/**
 * Root interface connector
 * Purpose: acts as the root interface for master and root connectors
 * Design: Extends the base Accumulo connector, which has accumulo references for
 * thrift rpc calls
 */
template<class T, class S1, class S2>
class RootInterface : public AccumuloConnector<T>
{
public:
    /**
     * Constructor, requires credentials and base instance
     * @param creds credential pointer
     * @param instance pointer to the current instance
     */
    RootInterface (AuthInfo *creds, Instance *instance) :
        AccumuloConnector<T> ()
    {

    }
    virtual
    ~RootInterface ()
    {

    }

    /**
     * authenticate the user 
     * @param username username to authenticate
     * @param password password used to authenticate username
     **/
    virtual void
    authenticate (string username, string password)
    {

    }

};

} /* namespace interconnect */

#endif /* SRC_INTERCONNECT_ROOTINTERFACE_H_ */

