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

#ifndef SERVERTRANSPORT_H_
#define SERVERTRANSPORT_H_

#include "Transport.h"

#include "../scanrequest/ScanRequest.h"
#include "../Scan.h"
#include "../../data/constructs/KeyExtent.h"
#include "../../data/constructs/Range.h"

namespace interconnect {

template<class T, class K, class V, class W>
class ServerTransport: public Transporter<T> {
public:

    ServerTransport(ServerConnection *conn) :
        Transporter<T>(conn) {

    }
    virtual ~ServerTransport() {

    }

    virtual void authenticate(AuthInfo *auth) = 0;

    virtual Scan *beginScan(ScanRequest<ScanIdentifier<K, V> > *req) = 0;

    virtual void *write(AuthInfo *auth, map<K, vector<W>> *request) = 0;
};

} /* namespace interconnect */
#endif /* SERVERTRANSPORT_H_ */
