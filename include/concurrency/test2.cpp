#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/move/move.hpp>
#include <iostream>

using namespace std;

#include "ThreadPool.h"
#include "Executor.h"


class TestExecutor : public Executor
{
public:
 ReturnType *run()
 {
  cout << "Hello world" << endl;
  return new ReturnType(SUCCESS,NULL);
 }
};
int main()
{
  ThreadPool poo;
  
  boost::shared_future<ReturnType*> ret = poo.submit(new TestExecutor());
  
   std::vector<boost::shared_future<ReturnType*> > pending_data; // vector of futures

   pending_data.push_back(ret);

 //   boost::wait_for_all(pending_data.begin(), pending_data.end());
 sleep(1);
 
  poo.close();
  
  
 
}