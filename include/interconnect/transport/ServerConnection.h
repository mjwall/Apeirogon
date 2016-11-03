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

#ifndef SERVERCONNECTION_H_
#define SERVERCONNECTION_H_

#include "../../data/constructs/inputvalidation.h"
#include "../../data/exceptions/IllegalArgumentException.h"

namespace interconnect
{

using namespace cclient::exceptions;


class ServerConnection
{
public:
  
    ServerConnection(ServerConnection *other ) : host(other->host), port(other->port), timeout( other->timeout)
    {
      
    }
    ServerConnection(string loc, uint16_t port, uint64_t timeout) :
        host(loc), port(port), timeout(timeout)
    {
        if (IsEmpty(&loc))
        {
            throw IllegalArgumentException("Invalid Input; host name is empty");
        }

    }
    
    virtual ~ServerConnection()
    {
      
    }


    string getHost() const
    {
        return host;
    }

    uint16_t getPort() const
    {
        return port;
    }

    uint64_t getTimeout() const
    {
        return timeout;
    }
    
    std::ostream& operator<<(std::ostream& os)
    {
      return os << host << ":" << port << " " << timeout << endl;
    }

    ServerConnection &operator=(const ServerConnection &rhs)
    {

        host = rhs.host;
        port = rhs.port;
        timeout = rhs.timeout;
        return *this;
    }

    bool operator==(const ServerConnection &rhs)
    {
        bool result = true;
        result = (host == rhs.host);
        if (!result)
            return false;
        result = (port == rhs.port);
        if (!result)
            return false;
        result = (timeout == rhs.timeout);
        if (!result)
            return false;
        else
            return true;
    }
    
    bool operator!=(const ServerConnection &rhs)
    {
        return !(*this==rhs);
    }

    bool operator<(const ServerConnection &rhs) const
    {
        bool result = true;
        result = (host < rhs.host);
        if (!result)
            return false;
        result = (port < rhs.port);
        if (!result)
            return false;
        result = (timeout < rhs.timeout);
        if (!result)
            return false;
        else
            return true;
    }

    bool operator>(const ServerConnection &rhs) const
    {
        bool result = true;
        result = (host > rhs.host);
        if (!result)
            return false;
        result = (port > rhs.port);
        if (!result)
            return false;
        result = (timeout > rhs.timeout);
        if (!result)
            return false;
        else
            return true;
    }

protected:
    string host;
    uint16_t port;
    uint64_t timeout;
};

struct Cmp_ServerConnection
{
    bool operator()(const ServerConnection& first,
                    const ServerConnection& second)
    {
        bool less = first.getHost() < second.getHost();
        if (less)
            return true;
        else
        {
            if (first.getHost() > second.getHost())
                return false;
            else
            {
                less = first.getPort() < second.getPort();
                if (less)
                    return true;
                else
                {
                    if (first.getPort() > second.getPort())
                        return false;
                    else
                    {
                        return first.getTimeout() < second.getTimeout();
                    }
                }
            }
        }
    }
};

}
#endif /* SERVERCONNECTION_H_ */
