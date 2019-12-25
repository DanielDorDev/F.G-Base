
#ifndef FLIGHTGEAR_FLIGHTLEXER_H
#define FLIGHTGEAR_FLIGHTLEXER_H
#include "Interface/ILexer.h"

class FlightLexer : public ILexer {


 public:
  std::vector<std::string>* lexer(std::string&) override;

};

#endif //FLIGHTGEAR_FLIGHTLEXER_H
