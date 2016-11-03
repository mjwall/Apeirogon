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

#ifndef CACHEDTRANSPORT_H_
#define CACHEDTRANSPORT_H_

#include <stdexcept>
#include <memory>
#include <iostream>
#include <string>


#include "Transport.h"
#include "ServerConnection.h"
namespace interconnect
{

template<typename T>
class CachedTransport
{
public:
    CachedTransport(T *transport, ServerConnection *key) :
        ioCount(0), lastCount(-1), reserved(false), threadName(""), foundError(
            false), lastReturnTime(0)
    {
      
	srand (time(NULL));
        cacheKey = new ServerConnection(key);

        serverTransport = transport;
	
	serverTransportPtr = boost::shared_ptr<T>(serverTransport);
    }
    
    ~CachedTransport()
    {
      delete cacheKey;
    }

    void reserve(bool reserve = true)
    {
        reserved = reserve;
    }

    bool isReserved()
    {
        return reserved;
    }

    bool open()
    {
        try
        {
            ioCount++;
            serverTransport->open();
        } catch (std::runtime_error &tfe)
        {
            foundError = true;
            throw tfe;
        }

        ioCount++;

        return (foundError==false);
    }

    void close()
    {
      cout << "server transport is " << std::addressof(*serverTransport) << " this is " <<  std::addressof(*this) << endl;
      if (serverTransport != NULL && serverTransport->isOpen())
	serverTransport->close();
    }

    T *getTransport() {
        return serverTransport;
    }

    bool hasError()
    {
        return foundError;
    }

    ServerConnection *getCacheKey()
    {
        return cacheKey;
    }

    boost::shared_ptr<T> getTransporter()
    {
        return serverTransportPtr;
    }

    bool operator ==(const CachedTransport *rhs) const
    {
      return std::addressof(this) == std::addressof(rhs);
        //return *this == *rhs;
    }
/*
    bool operator==(const CachedTransport &rhs) const
    {
        return threadName == rhs.threadName && (*cacheKey == *(rhs.cacheKey));
    }
    */

    bool isOpen()
    {
        return serverTransport->isOpen();
    }

    void registerService(string instance, string clusterManagers)
    {
        // no op
    }

    void setReturnTime(uint64_t t)
    {
        lastReturnTime = t;
    }

    uint64_t getLastReturnTime()
    {
        return lastReturnTime;
    }
    void sawError(bool sawError)
    {
	foundError = true;
    }

protected:

    bool foundError;
    string threadName;
    volatile bool reserved;

    string stuckThreadName;

    uint16_t ioCount;
    int16_t lastCount;
    uint64_t lastReturnTime;
    ServerConnection *cacheKey;
    T *serverTransport;
    boost::shared_ptr< T > serverTransportPtr;
};
}
#endif /* CACHEDTRANSPORT_H_ */
