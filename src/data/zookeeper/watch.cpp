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

#include "../../../include/data/constructs/client/zookeeper/watch.h"

using namespace cclient::data::zookeeper;

Event
Watch::popEvent ()
{
    Event my_event;

    pthread_mutex_lock (&mutex);
    my_event = events.front ();
    events.pop_back ();
    pthread_mutex_unlock (&mutex);
    return my_event;
}

int
Watch::size ()
{
    int size = 0;
    pthread_mutex_lock (&mutex);
    size = events.size ();
    pthread_mutex_unlock (&mutex);

    return size;
}

void
Watch::setHandle (zhandle_t *zh)
{
    zookeeperReference = zh;
}

void
Watch::pushEvent (Event event)
{
    pthread_mutex_lock (&mutex);
    events.push_back (event);
    pthread_mutex_unlock (&mutex);
}

bool
Watch::waitForConnected (zhandle_t *zh)
{
    time_t expires = time (0) + 10;
    while (!connected && time (0) < expires)
    {
        yield (zh, 1);
    }
    return connected;
}

bool
Watch::waitForDisconnected (zhandle_t *zh)
{
    time_t expires = time (0) + 15;
    while (connected && time (0) < expires)
    {
        yield (zh, 1);
    }
    return !connected;
}
