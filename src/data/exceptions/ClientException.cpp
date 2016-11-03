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
#include "../../../include/data/exceptions/ClientException.h"

using namespace cclient::exceptions;

const map<uint16_t, string> CLIENT_ERROR_CODES = {
  {INVALID_ZK_DATA,"Invalid return from zookeeper"},
  {INVALID_ZK_SERVER_DATA,"Invalid ZK server string retrieved from Zookeeper"},
  {INVALID_ZK_SERVER_PORT,"Invalid ZK server port"},
  {INVALID_SERVER_PORT,"Invalid server port"},
  {NO_MASTER_FOUND,"No master running at specified host and port"},
  {INVALID_USERNAME_PASSWORD,"Invalid username and password combination"},
  {COULD_NOT_CREATE_NAMESPACE,"Could not create namespace"},
  {DELETE_DEFAULT_NAMESPACE,"Cannot Delete default namespace"},
  
};
