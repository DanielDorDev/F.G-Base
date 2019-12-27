

#ifndef FLIGHTGEAR_INTERPRETER_H
#define FLIGHTGEAR_INTERPRETER_H
#include <ios>

class Interpreter {
  virtual void ExecuteBySource(std::istream&) = 0;
 public:
  virtual ~Interpreter() = default;

};


#endif //FLIGHTGEAR_INTERPRETER_H
