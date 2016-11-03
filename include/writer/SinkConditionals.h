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
#ifndef SRC_SCANNER_CONSTRUCTS_SOURCECONDITIONS_H_
#define SRC_SCANNER_CONSTRUCTS_SOURCECONDITIONS_H_

#include <iostream>
using namespace std;
#include <pthread.h>
namespace writer {

class SinkConditions {
public:
    SinkConditions() {
        pthread_mutex_init(&resultMutex, 0);

        pthread_mutexattr_t Attr;
        pthread_mutexattr_init(&Attr);
        pthread_mutexattr_settype(&Attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&resultMutex, &Attr);
        pthread_cond_init(&moreResults, 0);
        alive = true;
	closing = false;
    }

    void waitForResults() {
        pthread_mutex_lock(&resultMutex);
        if (alive && !closing) {
            pthread_cond_wait(&moreResults, &resultMutex);
        }
        pthread_mutex_unlock(&resultMutex);
    }

    void awakeThreadsForResults() {
        pthread_cond_broadcast(&moreResults);
    }

    bool isAlive() {
        return alive;
    }
    
    bool isClosing()
    {
      return closing;
    }
    
    void close()
    {
      closing = false;
      alive = true;
    }

    void awakeThreadsFinished() {
        pthread_mutex_lock(&resultMutex);
        closing = true;
        awakeThreadsForResults();
        pthread_mutex_unlock(&resultMutex);
    }
protected:
    volatile bool closing;
    volatile bool alive;
    pthread_cond_t moreResults;
    pthread_mutex_t resultMutex;

};

}
#endif /* SRC_SCANNER_CONSTRUCTS_SOURCECONDITIONS_H_ */
