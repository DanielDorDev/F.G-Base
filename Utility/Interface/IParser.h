
#ifndef FLIGHTGEAR_IPARSER_H
#define FLIGHTGEAR_IPARSER_H

#include "ICommand.h"
#include <vector>
#include <string>
#include "../Exception/NotImplementedException.h"
#include "IFactory.h"

class IParser {

 public:
  virtual void InjectTable(IFactory<std::string ,ICommand*> *) {
    throw NotImplementedException();

  }


  virtual ICommand* parser(std::vector<std::string> &) const {
    throw NotImplementedException();
  };

  virtual ~IParser() = default;

};

#endif //FLIGHTGEAR_IPARSER_H
