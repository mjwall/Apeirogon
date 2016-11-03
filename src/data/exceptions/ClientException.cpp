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
