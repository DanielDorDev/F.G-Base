//
// Created by daniel on 12/25/19.
//

#include "FlightCommandFactory.h"
void FlightCommandFactory::RegisterCommand(std::string hash, ICommand* command) {
  factory[hash] = command;
}

ICommand *FlightCommandFactory::GetCommand(std::string &command) const {
  auto got = factory.find(command);
  return got == factory.end() ? nullptr : got->second;
}
