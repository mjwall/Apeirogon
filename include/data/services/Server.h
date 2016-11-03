/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2015
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
#ifndef INCLUDE_DATA_SERVICES_SERVER_H_
#define INCLUDE_DATA_SERVICES_SERVER_H_

#include "../../concurrency/ThreadPool.h"
#include "../../concurrency/Executor.h"
#include "../../concurrency/ReturnType.h"

namespace services
{
class Server
{
protected:
    ThreadPool *executor;
public:
    Server() {
        executor = new ThreadPool();
    }

    void open()
    {
        //boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
        //boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        //boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    }
};
}

#endif /* INCLUDE_DATA_SERVICES_SERVER_H_ */
