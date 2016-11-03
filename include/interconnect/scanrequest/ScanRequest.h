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

#ifndef SCANREQUEST_H_
#define SCANREQUEST_H_

#include <vector>
using namespace std;

#include "../../data/constructs/IterInfo.h"
#include "../../data/constructs/column.h"

#include "../../data/constructs/security/AuthInfo.h"
#include "../../data/constructs/security/Authorizations.h"
#include "../../data/constructs/inputvalidation.h"
#include "../../data/exceptions/IllegalArgumentException.h"
#include "../transport/ServerConnection.h"
#include "ScanIdentifier.h"

namespace interconnect
{
using namespace cclient::data;
using namespace cclient::exceptions;
using namespace cclient::data::security;
/**
 * Represents a scan request
 */

template<typename I>
class ScanRequest
{

public:
    ScanRequest(AuthInfo *credentials, Authorizations *auths,
                ServerConnection *server) :
        creds(credentials), auths(auths), connection(server)
    {

        if (IsEmpty(credentials) || IsEmpty(auths) || IsEmpty(server))
        {
            throw IllegalArgumentException(
                "credentials, authorizations, and server must not be empty");
        }

    }

    virtual ~ScanRequest()
    {
        for(auto it : identifiers)
        {
            delete it;
        }
    }

    virtual void setIters(vector<IterInfo*> *iters)
    {
        iterators.insert(iterators.end(), iters->begin(), iters->end());
    }

    void addColumn(Column *col)
    {
        columns.push_back(col);
    }

    void addColumns(vector<Column*> *cols)
    {
        columns.insert(columns.end(), cols->begin(), cols->end());
    }

    vector<Column*> *getColumns()
    {
        return &columns;
    }

    AuthInfo *getCredentials() const
    {
        return creds;
    }

    Authorizations *getAuthorizations() const
    {
        return auths;
    }

    vector<IterInfo*> *getIterators()
    {
        return &iterators;
    }

    void putIdentifier(I *ident)
    {
        identifiers.push_back(ident);
    }


    vector<I*> *getRangeIdentifiers()
    {
        return &identifiers;
    }

protected:

    vector<I*> identifiers;
    AuthInfo *creds;
    Authorizations *auths;
    vector<IterInfo*> iterators;
    vector<Column*> columns;
    ServerConnection *connection;
};

} /* namespace interconnect */
#endif /* SCANREQUEST_H_ */
