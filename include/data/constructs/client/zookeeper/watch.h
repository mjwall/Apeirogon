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
#ifndef WATCH_H
#define WATCH_H

#include <iostream>
#include <string>
//#include <zookeeper/recordio.h>
#include <zookeeper/zookeeper.h>
#include <zookeeper/zookeeper.jute.h>
#include <list>
#include <sys/select.h>
#include <pthread.h>

using namespace std;

class Event {
public:
    string path;
    int type;
};

namespace cclient {
namespace data {
namespace zookeeper {

class Watch {
public:
    Watch() :
        connected(false), zookeeperReference(NULL), state(0) {

        pthread_mutex_init(&mutex, 0);
    }
    ~Watch() {
        pthread_mutex_destroy(&mutex);
    }

    Event popEvent();

    void setHandle(zhandle_t *zh);

    bool isConnected() {
        return connected;
    }

    bool setConnected(bool val) {
        connected = val;
        return connected;
    }

    int size();

    void pushEvent(Event event);

    bool waitForConnected(zhandle_t *zh);

    bool waitForDisconnected(zhandle_t *zh);

    void yield(zhandle_t *zh, int i) {
        pthread_yield();
    }

    void setState(int st) {
        state = st;
    }

    int getState() {
        return state;
    }

protected:
    list<Event> events;
    bool connected;
    int state;
    zhandle_t *zookeeperReference;
private:
    mutable pthread_mutex_t mutex;
};

struct WatchFn {
    Watch *ptr;
    void *Fn;
};
}
}
}
#endif // WATCH_H
