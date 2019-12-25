

#ifndef FLIGHTGEAR_FLIGHTCOMMANDFACTORY_H
#define FLIGHTGEAR_FLIGHTCOMMANDFACTORY_H
#include "Interface/ICommand.h"
#include "Interface/IFactory.h"
#include <string>
#include <unordered_map>


class FlightCommandFactory : public IFactory<std::string, ICommand*>{

  std::unordered_map<std::string, ICommand*> factory;

 public:

   void RegisterCommand(std::string, ICommand*) override;
   ICommand* GetCommand(std::string& command) const override;

};

#endif //FLIGHTGEAR_FLIGHTCOMMANDFACTORY_H
