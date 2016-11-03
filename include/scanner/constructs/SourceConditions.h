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

#ifndef SRC_SCANNER_CONSTRUCTS_SINKCONDITIONS_H_
#define SRC_SCANNER_CONSTRUCTS_SINKCONDITIONS_H_

#include <pthread.h>
namespace scanners {

class SourceConditions {
public:
    SourceConditions() {
        pthread_mutex_init(&resultMutex, 0);

        pthread_mutexattr_t Attr;
        pthread_mutexattr_init(&Attr);
        pthread_mutexattr_settype(&Attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&resultMutex, &Attr);
        pthread_cond_init(&moreResults, 0);
        alive = true;
    }

    void waitForResults() {

        if (alive) {
            pthread_mutex_lock(&resultMutex);
            pthread_cond_wait(&moreResults, &resultMutex);
            pthread_mutex_unlock(&resultMutex);
        }
    }

    void awakeThreadsForResults() {
	pthread_mutex_lock(&resultMutex);
        pthread_cond_broadcast(&moreResults);
	pthread_mutex_unlock(&resultMutex);
    }

    bool isAlive() {
        return alive;
    }

    void awakeThreadsFinished() {
        alive = false;
        awakeThreadsForResults();

    }
protected:
    volatile bool alive;
    pthread_cond_t moreResults;
    pthread_mutex_t resultMutex;

};

}
#endif /* SRC_SCANNER_CONSTRUCTS_SINKCONDITIONS_H_ */
