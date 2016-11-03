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
