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

