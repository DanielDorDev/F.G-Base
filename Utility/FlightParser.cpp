

#include "FlightParser.h"


ICommand *FlightParser::parser(std::vector<std::string> &a) {

  ICommand* commandBuilder = table->GetCommand(a.front());
  if (commandBuilder == nullptr) {
    throw NoCommandExist();
  } else {



    return commandBuilder;

  }
}

void FlightParser::InjectTable(IFactory<std::string, ICommand *> *sTable) {
  table = std::make_unique<IFactory<std::string ,ICommand*>>(*sTable);
}
