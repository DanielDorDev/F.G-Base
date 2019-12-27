

#ifndef FLIGHTGEAR_ILEXER_H
#define FLIGHTGEAR_ILEXER_H
#include <vector>
#include <string>
#include "../Exception/NotImplementedException.h"

class ILexer {


 public:
  virtual std::vector<std::string> lexer(std::string&) {
    throw NotImplementedException();
  }
  virtual ~ILexer() = default;
};



#endif //FLIGHTGEAR_ILEXER_H
