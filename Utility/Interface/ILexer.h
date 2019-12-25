

#ifndef FLIGHTGEAR_ILEXER_H
#define FLIGHTGEAR_ILEXER_H
#include <vector>
#include <string>
#include "../NotImplementedException.h"

class ILexer {


 public:
  virtual std::vector<std::string>* lexer(std::string&) {
    throw NotImplementedException();
  }
};



#endif //FLIGHTGEAR_ILEXER_H
