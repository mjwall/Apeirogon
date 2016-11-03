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
