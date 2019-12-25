

#ifndef FLIGHTGEAR_COMMANDFACTORY_H
#define FLIGHTGEAR_COMMANDFACTORY_H

#include <string>
#include "../Exception/NotImplementedException.h"
template<class L, class R>
class IFactory {

 public:

  virtual void RegisterCommand(L, R) {
    throw NotImplementedException();
  }
  virtual R GetCommand(std::string &command) const {
    throw NotImplementedException();
  }
};

#endif //FLIGHTGEAR_COMMANDFACTORY_H
