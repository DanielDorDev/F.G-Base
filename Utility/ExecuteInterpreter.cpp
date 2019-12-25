
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "ExecuteInterpreter.h"
#include "CommandPool.h"
#include "Interface/IFactory.h"

ICommand* ExecuteInterpreter::InterpretCommand(std::istream & source) const {

    std::string commandString, buffer;
    long left = 0, right = 0;
    do {
      std::getline(source, buffer);
      commandString.append(buffer);
      left = std::count(commandString.begin(), commandString.end(), '{');
      right = std::count(commandString.begin(), commandString.end(), '}');

    } while (left > right);
    std::vector<std::string>* vectorLexer = lexer->lexer(commandString);
    return parser->parser(*vectorLexer);
}

void ExecuteInterpreter::ExecuteBySource(std::istream & source) const {
  CommandPool pool;
  pool.start(1);
  while(!stop) {
    try {
      ICommand *command = InterpretCommand(source);
      pool.queue([&command]() { command->doCommand(); });

    } catch (NotImplementedException& e) {
       e.what();
    } catch (...) {}
  }
}

void ExecuteInterpreter::ExecuteFromTerminal() const {
  ExecuteBySource(std::cin);
}

void ExecuteInterpreter::ExecuteFromFile(const char * path) const {
  // Open file and check it.
  std::ifstream stream(path);
  if (stream.is_open()) {
    ExecuteBySource(stream);
    stream.close();
  } else {
    throw std::invalid_argument(
        "Problem in opening file: " + std::string(path));
  }
}

void ExecuteInterpreter::ExecuteFromSource(std::istream& source) const {
  ExecuteBySource(source);
}

ExecuteInterpreter::ExecuteInterpreter(ILexer * sLexer, IParser * sParser,
    IFactory<std::string, ICommand*>* sFactory) {
  stop = false;
  lexer = std::make_unique<ILexer>(*sLexer);
  parser = std::make_unique<IParser>(*sParser);

  class ExitCommand : public ICommand {
    std::atomic_bool *bStop;
   public:
    explicit ExitCommand(std::atomic_bool &b) {
      bStop = &b;
    }
    void doCommand() override {
      *bStop = true;
    }
  };

  sFactory->RegisterCommand("Exit", new ExitCommand(this->stop));
  sParser->InjectTable(sFactory);

}




