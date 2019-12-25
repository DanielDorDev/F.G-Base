

#ifndef FLIGHTGEAR_INTERPRETER_H
#define FLIGHTGEAR_INTERPRETER_H
#include <ios>

class Interpreter {
  virtual void ExecuteBySource(std::istream&) const = 0;
};


#endif //FLIGHTGEAR_INTERPRETER_H
