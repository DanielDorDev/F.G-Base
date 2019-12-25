
#ifndef FLIGHTGEAR_IPARSER_H
#define FLIGHTGEAR_IPARSER_H

#include "ICommand.h"
#include <vector>
#include <string>
#include "../NotImplementedException.h"
#include "IFactory.h"

class IParser {

 public:
  void InjectTable(IFactory<std::string ,ICommand*> *) {
    throw NotImplementedException();

  }


  virtual ICommand* parser(const std::vector<std::string> &) {
    throw NotImplementedException();
  };
};

#endif //FLIGHTGEAR_IPARSER_H
