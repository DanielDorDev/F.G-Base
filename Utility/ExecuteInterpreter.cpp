
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "ExecuteInterpreter.h"
#include "Model/CommandPool.h"
#include "Interface/IFactory.h"
#include "Exception/InvalidCommand.h"
#include "Exception/NoCommandExist.h"

ICommand* ExecuteInterpreter::InterpretCommand(std::istream & source) const {

    std::string commandString, buffer;
    long left = 0, right = 0;


    do {
      std::getline(source, buffer);
      commandString.append(buffer);
      left = std::count(commandString.begin(), commandString.end(), '{');
      right = std::count(commandString.begin(), commandString.end(), '}');

      if (left!= right) {
        commandString.append("\n");
      }

    } while (left != right);

    std::vector<std::string>* vectorLexer = lexerExe->lexer(commandString);

    for (const auto& a : *vectorLexer) {
      std::cout<<a<<",";
    }
  std::cout<<std::endl;

  return parserExe->parser(*vectorLexer);
}

void ExecuteInterpreter::ExecuteBySource(std::istream & source) const {
  CommandPool pool;
  pool.start(1);
  while(!stop && !source.eof()) {
    try {
      ICommand *command = InterpretCommand(source);

      pool.queue([&command]() { command->doCommand(); });

    } catch (NotImplementedException& e) {
       e.what();
    } catch (InvalidCommand& e) {
       e.what();
    } catch (NoCommandExist& e) {
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
  lexerExe = std::unique_ptr<ILexer>(sLexer);
  parserExe = std::unique_ptr<IParser>(sParser);

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
  sFactory->RegisterCommand("Exit", [&](const std::vector<std::string>&) {
    return new ExitCommand(this->stop);
  });
  sParser->InjectTable(sFactory);
}




