/*
 * Copyright (c) 2016 Marc Parisi marc.parisi@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
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
