

#ifndef FLIGHTGEAR_COMMANDFACTORY_H
#define FLIGHTGEAR_COMMANDFACTORY_H

#include <string>
#include <vector>
#include <functional>
#include "../Exception/NotImplementedException.h"
template<class L, class R>

class IFactory {

 public:

  virtual void RegisterCommand(L,
                               std::function
                                   <
                                       R(const std::vector<std::string> &)
                                   >) {
    throw NotImplementedException();
  }

  virtual R GetCommand(const std::string &command,
                       const std::vector<std::string> &) const {
    throw NotImplementedException();
  }
};

#endif //FLIGHTGEAR_COMMANDFACTORY_H
