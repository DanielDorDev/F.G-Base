

#include "FlightParser.h"


ICommand *FlightParser::parser(const std::vector<std::string> &a) {

  ICommand* b;




  return b;
}
void FlightParser::InjectTable(IFactory<std::string, ICommand *> *sTable) {
  table = std::make_unique<IFactory<std::string ,ICommand*>>(*sTable);
}
