
#ifndef FLIGHTGEAR_FLIGHTPARSER_H
#define FLIGHTGEAR_FLIGHTPARSER_H
#include "Interface/IParser.h"
#include "Interface/IFactory.h"
#include "Exception/InvalidCommand.h"
#include "Exception/NoCommandExist.h"
#include <memory>

class FlightParser : public IParser {
  std::unique_ptr<IFactory<std::string,ICommand *>> table;

 public:
  void InjectTable(IFactory<std::string, ICommand *> *) override;
  ICommand *parser(std::vector<std::string> &) override;

};

#endif //FLIGHTGEAR_FLIGHTPARSER_H
