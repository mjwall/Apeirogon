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
#ifndef ZOOKEEPERS_H
#define ZOOKEEPERS_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cstdint>
//#include <zookeeper/recordio.h>
//#include <zookeeper/proto.h>
//#include <zookeeper.h>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/utility.hpp>
#include <sys/select.h>

using namespace std;
#include "watch.h"

#include <pthread.h>

#define  TIME_BETWEEN_CONNECT_CHECKS_MS  100
#define  TOTAL_CONNECT_TIME_WAIT_MS  10 * 1000

#define ZROOT "/accumulo"
#define ZINSTANCES "/instances"
#define ZMASTERS "/masters"
#define ZMASTER_LOCK "/masters/lock"
#define ZROOT_TABLET "/root_tablet"
#define ZROOT_TABLET_LOCATION "/root_tablet/location"
#define TSERVERS "/tservers"

namespace cclient {
namespace data {
namespace zookeeper {

static pthread_mutex_t syncBarrier = PTHREAD_MUTEX_INITIALIZER;

static void watcher_function(zhandle_t *, int type, int state, const char *path,
                             void*v) {

    Watch *ctx = ((WatchFn*) v)->ptr;

    if (state == ZOO_CONNECTED_STATE) {
        ctx->setConnected(true);
    } else {
        ctx->setConnected(false);
    }

    ctx->setState(state);

    if (type != ZOO_SESSION_EVENT) {
        Event event;
        event.path = path;
        event.type = type;
        ctx->pushEvent(event);
    }
}

class ZooKeeper {
public:
    ZooKeeper(const char *hostPorts, uint32_t timeout) :
        hostPorts((char*) hostPorts), timeout(timeout), zookeeperReference(
            0),  initWatchFp(0) {

    }

    ~ZooKeeper() {
        if (NULL != zookeeperReference)
	{
            zookeeper_close(zookeeperReference);
	}
	if (NULL != initWatchFp)
	{
	  delete initWatchFp;
	}
    }
    void setWatch(Watch *watch) {
        myWatch = watch;
    }

    bool isConnected() {
        return myWatch->isConnected();
    }

    bool exists(string path, watcher_fn fn, WatchFn *ptr = NULL) {
        Stat stat = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

        // watcher will execute our function pointer
        if (ptr != NULL && ptr->ptr != myWatch) {
            ptr->ptr = myWatch;
        } else {
            fn = NULL;
        }

        zoo_wexists(zookeeperReference, path.c_str(), fn, ptr, &stat);

        return !stat_empty(&stat);
    }

    char *getData(string path, watcher_fn fn, WatchFn *ptr = NULL) {
        Stat stat = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

        // watcher will execute our function pointer

        if (ptr != NULL && ptr->ptr != myWatch) {
            ptr->ptr = myWatch;
        } else {
            fn = NULL;
        }

        int len = 1024;
        char *buffer = new char[len];
        memset(buffer, 0x00, len);

        zoo_wget(zookeeperReference, path.c_str(), fn, ptr, buffer, &len,
                 &stat);

        if (len == -1) {
            delete[] buffer;
            buffer = NULL;
        }

        return buffer;
    }

    list<string> *getChildren(string path, watcher_fn fn, WatchFn *ptr = NULL) {
        struct String_vector str_vec = { 0, 0 };

        // watcher will execute our function pointer

        if (ptr != NULL && ptr->ptr != myWatch) {
            ptr->ptr = myWatch;
        } else {
            fn = NULL;
        }

        zoo_wget_children(zookeeperReference, path.c_str(), fn, ptr,
                                    &str_vec);

        // add the children paths iff we have results
        list<string> *newList = 0;

        if (str_vec.count > 0) {
            newList = new list<string>();
            for (int i = 0; i < str_vec.count; i++) {
                newList->push_back(string(str_vec.data[i]));
            }
        }
        deallocate_String_vector(&str_vec);

        return newList;
    }

    void init(Watch *watch) {
        myWatch = watch;
        // init zk with our zk info, and the watcher_function will
        // label our watch as 'connected'
        initWatchFp = new WatchFn();
        initWatchFp->ptr = myWatch;
        zookeeperReference = zookeeper_init(hostPorts, watcher_function,
                                            timeout, 0, initWatchFp, 0);
	
        myWatch->setHandle(zookeeperReference);

    }

protected:

    inline static bool stat_empty(struct Stat* a) {
        Stat statB = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

        return (stat_eq(a, &statB) == 1);
    }

    inline static int stat_eq(struct Stat* a, struct Stat* b) {
        if (a->czxid != b->czxid)
            return 0;
        if (a->mzxid != b->mzxid)
            return 0;
        if (a->ctime != b->ctime)
            return 0;
        if (a->mtime != b->mtime)
            return 0;
        if (a->version != b->version)
            return 0;
        if (a->cversion != b->cversion)
            return 0;
        if (a->aversion != b->aversion)
            return 0;
        if (a->ephemeralOwner != b->ephemeralOwner)
            return 0;
        if (a->dataLength != b->dataLength)
            return 0;
        if (a->numChildren != b->numChildren)
            return 0;
        if (a->pzxid != b->pzxid)
            return 0;
        return 1;
    }
    
    char *hostPorts;
    uint32_t timeout;
    zhandle_t *zookeeperReference;
    Watch *myWatch;
    WatchFn *initWatchFp;
    
    
};

class ZooSession {
public:
    ZooSession(ZooKeeper *keeper, Watch *watcher) :
        zooKeeper(keeper) {

        keeper->init(watcher);

    }

    ZooSession(ZooKeeper *keeper) :
        zooKeeper(keeper) {
        // already initialized session

    }

    ZooKeeper *getZooKeeper() {
        return zooKeeper;
    }

protected:
    ZooKeeper *zooKeeper;
};

class ZooKeepers {
private:
    static map<string, ZooSession*> sessions;
public:

    static string sessionKey(string keepers, uint16_t timeout, string auth) {
        stringstream ss(stringstream::in | stringstream::out);
        ss << keepers << ":" << timeout << ":" << (auth.size() > 0 ? auth : "");
        return ss.str();
    }

    static ZooSession *getSession(string zookeepers, uint16_t timeout,
                                  string auth) {
        pthread_mutex_lock(&syncBarrier);
        string sessionKey = ZooKeepers::sessionKey(zookeepers, timeout, auth);
        string readOnlyKey = ZooKeepers::sessionKey(zookeepers, timeout, "");

        map<string, ZooSession*>::iterator it = sessions.find(sessionKey);

        // it exists

        ZooSession *zsi = NULL;

        if (it != sessions.end()) {
            zsi = (*it).second;
            if (!zsi->getZooKeeper()->isConnected()) {
                map<string, ZooSession*>::iterator pt;
                if ((pt = sessions.find(readOnlyKey)) == it) {
                    sessions.erase(pt);
                }
                sessions.erase(it);
            }

        } else {
            Watch *watcher = new Watch();

            zsi = new ZooSession(connect(zookeepers, timeout, auth, watcher));

            sessions.insert(std::make_pair(sessionKey, zsi));
        }

        pthread_mutex_unlock(&syncBarrier);

        return zsi;
    }

    static ZooKeeper *connect(string &hosts, uint32_t timeout, string auth,
                              Watch *watcher) {
        bool tryAgain = true;
        ZooKeeper *zk = NULL;
        do {
            zk = new ZooKeeper(hosts.c_str(), timeout);

            zk->init(watcher);

            for (int i = 0;
                    i
                    < TOTAL_CONNECT_TIME_WAIT_MS
                    / TIME_BETWEEN_CONNECT_CHECKS_MS && tryAgain;
                    i++) {

                if (zk->isConnected()) {
                    if (auth.size() > 0) {
                        break;
                        tryAgain = false;
                    } else {
                        // sleep
                        sleep(1);
                    }
                }
            }
            //else if (ret == ReturnCode::type::

        } while (tryAgain);

        return zk;
    }
};
}
}
}
//const map<string,

#endif // ZOOKEEPERS_H
