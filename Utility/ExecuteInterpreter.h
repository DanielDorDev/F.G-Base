

#ifndef FLIGHTGEAR_EXECUTEINTERPRETER_H
#define FLIGHTGEAR_EXECUTEINTERPRETER_H

#include "Interface/Interpreter.h"
#include "Interface/ILexer.h"
#include "Interface/IParser.h"
#include "Interface/ICommand.h"
#include "Interface/IFactory.h"
#include <memory>
#include <atomic>
#include <stack>
class ExecuteInterpreter : public Interpreter{

  std::atomic_bool stop;

  std::unique_ptr<ILexer> lexerExe;
  std::unique_ptr<IParser> parserExe;
  std::stack<ICommand*> undo;


  ICommand* InterpretCommand(std::istream &) const;

  void ExecuteBySource(std::istream&) override;

 public:

  ExecuteInterpreter(ILexer*, IParser*, IFactory<std::string, ICommand*>*);

  void ExecuteFromFile(const char *);

  void ExecuteFromSource(std::istream&);

  void ExecuteFromTerminal();

  ~ExecuteInterpreter() override {

    while (!undo.empty()) {
      auto undoCommand = undo.top();
      undo.pop();
      delete undoCommand;
    }
  }
};

#endif //FLIGHTGEAR_EXECUTEINTERPRETER_H
