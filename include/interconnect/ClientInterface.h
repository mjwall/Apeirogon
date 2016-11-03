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

#ifndef CLIENTINTERFACE_H_
#define CLIENTINTERFACE_H_

#include <boost/shared_ptr.hpp>
#include <type_traits>
#include <string>

#include "transport/Transport.h"

#include "../data/constructs/security/AuthInfo.h"

using namespace boost;

using namespace std;

namespace interconnect
{

using namespace cclient::data;
using namespace cclient::data::security;

template<typename Tr>
class ClientInterface
{
public:
	ClientInterface (const string host, const int port);

	ClientInterface ()
	{

	}

	virtual ~ClientInterface ();

	virtual void
	authenticate (string username, string password) = 0;

	void
	authenticate (AuthInfo *auth)
	{
		authenticate (auth->getUserName (), auth->getPassword ());
	}

	void
	setTransport (boost::shared_ptr<Tr> transporty)
	{

		transport = transporty;
		transport->registerService (instanceId, zookeepers);
	}

	bool
	setAuthenticated (bool auth)
	{
		authenticated = auth;
		return auth;
	}

	void
	setCredentials (string user, string password)
	{
		authenticated_user = user;
		authenticated_password = password;

	}

	boost::shared_ptr<Tr>
	getTransport ()
	{
		return transport;
	}

protected:

	boost::shared_ptr<Tr> transport;

	string server_host;
	int server_port;
	bool authenticated;

	string authenticated_user;
	string authenticated_password;
	// info abt cluster
	string instanceId;
	string zookeepers;

};

template<typename Tr>
ClientInterface<Tr>::ClientInterface (const string host, const int port) :
	server_host (host), server_port (port)
{

}

template<typename Tr>
ClientInterface<Tr>::~ClientInterface ()
{
}

}
#endif /* CLIENTINTERFACE_H_ */
