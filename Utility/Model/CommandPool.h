

#ifndef FLIGHTGEAR_COMMANDPOOL_H
#define FLIGHTGEAR_COMMANDPOOL_H
#include <mutex>
#include <condition_variable>
#include <future>
#include <deque>
#include <vector>
#include <iostream>
#include <stack>
#include "../Interface/ICommand.h"

class CommandPool {

  std::mutex m;
  std::condition_variable v;
  std::deque<std::packaged_task<void()>> work;
  std::vector<std::future<void>> finished;

  void thread_task();

 public:

  void abort() {
    cancel_pending();
    finish();
  }

  void cancel_pending();

  template<class F, class R=std::result_of_t<F&()>>
  std::future<R>queue(F &&f) {
    std::packaged_task<R()> p(std::forward<F>(f));

    auto r = p.get_future();
    {
      std::unique_lock<std::mutex> l(m);
      work.emplace_back(std::move(p));
    }
    v.notify_one();
    return r;
  }

  void finish();

  void start(std::size_t N=1);

  ~CommandPool() {
    finish();

  }
};

#endif //FLIGHTGEAR_COMMANDPOOL_H
