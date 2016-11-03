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
#include "../../../include/writer/impl/WriterHeuristic.h"

namespace writer
{

WriterHeuristic::WriterHeuristic (short numThreads) :
    threadCount (numThreads), threads (NULL), started (false)
{
    closed = false;
  
    threads = new pthread_t[threadCount];

    queue = new moodycamel::ConcurrentQueue<WritePair*> ();

    conditionals = new SinkConditions ();

}

WriterHeuristic::~WriterHeuristic ()
{
    close();
    cout << "delete queue" << endl;
    WritePair *pair = NULL;
    while(queue->size_approx() > 0)
    {
	cout << "deleting p" << endl;
	if (queue->try_dequeue(pair))
	{
	  cout << "found something to delete" << endl;
	  delete pair->rangeDef;
	  delete pair->mutations;
	  
	}
    }
    delete queue;
    cout << "delete conditionals" << endl;
    delete conditionals;
    cout << "deleted heuristic " << endl;
}

} /* namespace data */
