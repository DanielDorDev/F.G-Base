

#ifndef FLIGHTGEAR_FLIGHTCOMMANDFACTORY_H
#define FLIGHTGEAR_FLIGHTCOMMANDFACTORY_H
#include "Interface/ICommand.h"
#include "Interface/IFactory.h"
#include <string>
#include <unordered_map>
#include <vector>

class FlightCommandFactory : public IFactory<std::string, ICommand*>{

  std::unordered_map<std::string, std::function<ICommand*(const std::vector<std::string>&)>> factory;


 public:
  FlightCommandFactory();

   void RegisterCommand(std::string, std::function<ICommand*(const std::vector<std::string>&)>) override;
   ICommand* GetCommand(const std::string &command, const std::vector<std::string>&) const override;

};

#endif //FLIGHTGEAR_FLIGHTCOMMANDFACTORY_H
