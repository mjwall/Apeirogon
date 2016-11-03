/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2016
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

#ifndef CLIENTEXCEPTION_H_
#define CLIENTEXCEPTION_H_

#include <string>

#include <map>
#include <iostream>
using namespace std;


#define INVALID_ZK_DATA 0
#define INVALID_ZK_SERVER_DATA 1
#define INVALID_ZK_SERVER_PORT 2
#define INVALID_SERVER_PORT 3
#define NO_MASTER_FOUND 4
#define INVALID_USERNAME_PASSWORD 5
#define COULD_NOT_CREATE_NAMESPACE 6
#define DELETE_DEFAULT_NAMESPACE 7
extern const map<uint16_t, string> CLIENT_ERROR_CODES;



namespace cclient {
namespace exceptions {
  


class ClientException: public std::exception {
public:
    ClientException(string excp) : errorCode(-1),
        excp_str(excp) {

    }
    
    ClientException(const uint16_t errorCode) :errorCode(errorCode)
    {
    }
    
    
    ~ClientException() throw () {

    }
    const char *what() {
	if (errorCode != -1) 
	{	
	  return CLIENT_ERROR_CODES.at(errorCode).c_str();
	}
	else
        return excp_str.c_str();
    }
private:
    int16_t errorCode;
    string excp_str;
};
} /* namespace data */
} /* namespace cclient */
#endif /* CLIENTEXCEPTION_H_ */
