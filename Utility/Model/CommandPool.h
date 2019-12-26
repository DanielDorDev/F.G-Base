

#ifndef FLIGHTGEAR_COMMANDPOOL_H
#define FLIGHTGEAR_COMMANDPOOL_H
#include <mutex>
#include <condition_variable>
#include <future>
#include <deque>
#include <vector>
#include <iostream>
#include "../Interface/ICommand.h"
class CommandPool {

  std::mutex m;
  std::condition_variable v;
  std::deque<std::packaged_task<void()>> work;
  // this holds futures representing the worker threads being done:
  std::vector<std::future<void>> finished;

  void thread_task();

 public:

  // abort() cancels all non-started tasks, and tells every working thread
  // stop running, and waits for them to finish up.
  void abort() {
    cancel_pending();
    finish();
  }

  // cancel_pending() merely cancels all non-started tasks:
  void cancel_pending();

  // queue( lambda ) will enqueue the lambda into the tasks for the threads
  // to use.  A future of the type the lambda returns is given to let you get
  // the result out.
  template<class F, class R=std::result_of_t<F&()>>
  std::future<R>queue(F &&f) {
    // wrap the function object into a packaged task, splitting
    // execution from the return value:
    std::packaged_task<R()> p(std::forward<F>(f));

    auto r = p.get_future(); // get the return value before we hand off the task
    {
      std::unique_lock<std::mutex> l(m);
      work.emplace_back(std::move(p)); // store the task<R()> as a task<void()>
    }
    v.notify_one(); // wake a thread to work on the task
    return r; // return the future result of the task
  }

  // finish enques a "stop the thread" message  every thread, waits for them:
  void finish();

  // start N threads in the thread pool.
  void start(std::size_t N=1);

  ~CommandPool() {
    finish();
  }
};

#endif //FLIGHTGEAR_COMMANDPOOL_H
