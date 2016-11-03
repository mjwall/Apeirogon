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

#ifndef RESULTS_H_
#define RESULTS_H_

#include <iostream>
#include <set>
#include <string>
#include <pthread.h>

using namespace std;

#include "SourceConditions.h"
#include "../../data/constructs/inputvalidation.h"
#include "../../data/extern/concurrentqueue/concurrentqueue.h"

namespace scanners {
template<typename T> class ResultBlock;
template<typename T> class ResultIter;
template<typename T, class BlockType> class Results;

template<typename T>
class ResultBlock: public std::iterator<std::forward_iterator_tag, T> {
protected:

    SourceConditions *sourceConditionals;

    moodycamel::ConcurrentQueue<T> *resultSet;

    T current;

    bool isEnd;

    virtual void setEnd(bool val) {
        isEnd = val;
    }

public:

    ResultBlock(SourceConditions *conditionals,
                moodycamel::ConcurrentQueue<T> *queue, bool setEnd = false) :
        isEnd(setEnd) {
        resultSet = queue;

        sourceConditionals = conditionals;
    }

    ResultBlock<T> begin() {
        getNextResult();
        return *this;
    }

    bool isEndOfRange() {
        return isEnd;
    }

    ResultBlock<T> end() {
        return static_cast<ResultBlock<T> >(ResultBlock(sourceConditionals,
                                            resultSet, true));
    }

    T &operator*() {

        return current;
    }

    inline void getNextResult() {
        do {

            if (!resultSet->try_dequeue(current)) {
                sourceConditionals->waitForResults();
                if (resultSet->try_dequeue(current))
                    break;
                if (!sourceConditionals->isAlive()
                        && resultSet->size_approx() <= 0) {
                    isEnd = true;
                }

            } else
                break;
        } while (sourceConditionals->isAlive());

    }
    ResultBlock& operator++() {
        getNextResult();
        return *this;
    }

    ResultBlock& operator++(int t) {
        for (int i = 0; i < (t + 1); i++) {
            getNextResult();
        }

        return *this;
    }

    ResultBlock& operator=(const ResultBlock &rhs) {
        resultSet = rhs.resultSet;
        sourceConditionals = rhs.sourceConditionals;
        isEnd = rhs.isEnd;
        return *this;
    }

    bool operator==(const ResultIter<T> &rhs) {
        return isEnd == rhs.getParent();
    }

    bool operator!=(const ResultBlock &rhs) {
        return !(isEnd == rhs.isEnd);
    }

    void add(T t) {
        resultSet->enqueue(t);
        sourceConditionals->awakeThreadsForResults();
    }

    void add(vector<T> *t) {
        for (typename vector<T>::iterator it = t->begin(); it != t->end();
                it++) {
            resultSet->enqueue(*it);
        }

        sourceConditionals->awakeThreadsForResults();
    }

    virtual ~ResultBlock() {

    }
    friend class ResultIter<T> ;
};

template<typename T>
class ResultIter: public ResultBlock<T> {
protected:
    ResultBlock<T> *parent;

    void setEnd(bool val) {
        ResultBlock<T>::setEnd(val);
    }
public:

    ResultIter(ResultBlock<T> *copyResultSet, bool end = false) :
        ResultBlock<T>(copyResultSet->sourceConditionals,
                       copyResultSet->resultSet,
                       (end ? end : copyResultSet->isEndOfRange()))

    {
        setEnd((end ? end : copyResultSet->isEndOfRange()));
        parent = copyResultSet;
    }

    ResultIter(ResultIter<T> *copyResultSet, bool end = false) :
        ResultBlock<T>(copyResultSet->sourceConditionals,
                       copyResultSet->resultSet,
                       (end ? end : copyResultSet->isEndOfRange()))

    {
        setEnd((end ? end : copyResultSet->isEndOfRange()));
        parent = copyResultSet;
    }

    ResultBlock<T> begin() {
        return *this;
    }

    ResultBlock<T> end() {

        return parent->end();
    }

    ResultBlock<T> *getParent() {
        return parent;
    }

    T &operator*() {
        return *(*parent);
    }

    ResultIter& operator++() {
        (*parent)++;
        return *this;
    }

    ResultIter& operator++(int t) {
        (*parent)++;
        return *this;
    }

    bool operator==(const ResultIter &rhs) {
        return *(*parent) == *(*rhs.parent);
    }

    bool operator==(const ResultBlock<T> &rhs) {
        return parent->isEnd == rhs.isEnd;
    }

    bool operator!=(const ResultIter<T> &rhs) {
        return !(*this == rhs);
    }

    bool operator!=(const ResultBlock<T> &rhs) {
        return !(*this == rhs);
    }

    virtual ~ResultIter() {

    }
};

template<typename T, class BlockType>
class Results {
protected:

    moodycamel::ConcurrentQueue<T> *resultSet;

    BlockType *iter;

    SourceConditions conditions;

    volatile uint16_t producers;

public:

    typedef BlockType iterator;

    Results() /*-> decltype(static_cast<BlockType>(T))*/
    {
        resultSet = new moodycamel::ConcurrentQueue<T>();

        iter = new BlockType(&conditions, resultSet);

        producers = 0;
    }

    void add(T t) {
        iter->add(t);
    }

    void add(vector<T> *t) {
        iter->add(t);
    }

    iterator begin() {
        return iter->begin();
    }

    iterator end() {
        return iter->end();
    }

    void decrementProducers() {
        if (--producers <= 0) {

            conditions.awakeThreadsFinished();
        }
    }

    void registerProducer() {
        producers++;
    }

    ~Results() {
        delete resultSet;
    }

protected:

};
} /* namespace scanners */
#endif /* RESULTS_H_ */
