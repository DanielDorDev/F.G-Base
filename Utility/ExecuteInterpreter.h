

#ifndef FLIGHTGEAR_EXECUTEINTERPRETER_H
#define FLIGHTGEAR_EXECUTEINTERPRETER_H

#include "Interface/Interpreter.h"
#include "Interface/ILexer.h"
#include "Interface/IParser.h"
#include "Interface/ICommand.h"
#include "Interface/IFactory.h"
#include <memory>
#include <atomic>

class ExecuteInterpreter : Interpreter{

  std::atomic_bool stop;

  std::unique_ptr<ILexer> lexer;
  std::unique_ptr<IParser> parser;

  ICommand* InterpretCommand(std::istream &) const;

  void ExecuteBySource(std::istream&) const override;

 public:

  ExecuteInterpreter(ILexer*, IParser*, IFactory<std::string, ICommand*>*);

  void ExecuteFromFile(const char *) const;

  void ExecuteFromSource(std::istream&) const;

  void ExecuteFromTerminal() const;

};

#endif //FLIGHTGEAR_EXECUTEINTERPRETER_H
