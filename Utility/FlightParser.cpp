

#include "FlightParser.h"


ICommand *FlightParser::parser(std::vector<std::string> &a) {
  return table->GetCommand(a.front(), std::vector<std::string>(a.begin() + 1, a.end()));
}

void FlightParser::InjectTable(IFactory<std::string,ICommand*> *sTable) {
  table = std::make_unique<IFactory<std::string ,ICommand*>>(*sTable);
}
