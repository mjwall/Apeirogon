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

#ifndef SRC_WRITER_SINK_H_
#define SRC_WRITER_SINK_H_

#include <iostream>
#include <chrono>
#include <thread>
#include "../data/extern/concurrentqueue/concurrentqueue.h"
namespace writer
{

using namespace scanners;

template<class T>
class Sink
{

protected:

	moodycamel::ConcurrentQueue<T> *sinkQueue;

	virtual bool
	exceedQueue ();

	virtual bool
	enqueue (T obj);

	uint16_t queueSize;

	volatile uint16_t currentSize = 0;
	
	virtual uint64_t maxWait()
	{
	  return 0;
	}
	
	virtual uint64_t waitingSize()
	{
	  return 0;
	}

public:

	Sink (uint16_t maxQueue) :
		queueSize (maxQueue)
	{

		sinkQueue = new moodycamel::ConcurrentQueue<T> (queueSize * 1.5);

	}

	virtual
	~Sink ()
	{
		delete sinkQueue;
	}

	/**
	 * Method to put object onto the queue
	 * @param obj incoming object to push into the sink
	 */
	bool
	push (T obj);

	/**
	 * Flushes the sink
	 */
	virtual void
	flush (bool override = false) = 0;

	/**
	 * Closes the sink
	 */
	virtual void
	close ()
	{
		flush (true);
	}

	inline virtual size_t
	size ()
	{

		return sinkQueue->size_approx ();
	}

};

/**
 * Method to put object onto the queue
 * @param obj incoming object to push into the sink
 */
template<typename T>
bool
Sink<T>::push (T obj)
{
    
	while(waitingSize() >= ((maxWait()+1)*1.5)) {
		std::cout << "waitingSize " << waitingSize() << " " << maxWait() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
	/**
	 * If enqueue r
	 */
	if (enqueue (obj) && exceedQueue ()) {
		flush ();
	}
	

	
  return true;
}

/**
 * Method to put object onto the queue
 * @param obj incoming object to push into the sink
 */
template<typename T>
bool
Sink<T>::enqueue (T obj)
{
	return sinkQueue->try_enqueue (obj);

}

/**
 * Method to put object onto the queue
 * @param obj incoming object to push into the sink
 */
template<typename T>
bool
Sink<T>::exceedQueue ()
{
	if (size () > queueSize) {
		return true;
	}

	return false;

}

} /* namespace writer */

#endif /* SRC_WRITER_SINK_H_ */
