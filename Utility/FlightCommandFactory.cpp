
#include "FlightCommandFactory.h"
void FlightCommandFactory::RegisterCommand(
    std::string hash, std::function<ICommand*(const std::vector<std::string>&)> command) {
  factory[hash] = command;
}
ICommand *FlightCommandFactory::GetCommand(
    const std::string &command, const std::vector<std::string> & args) const {
  auto got = factory.find(command);

  if (got == factory.end() ) {
    return nullptr;
  } else {
    return got->second(args);
  }
}
FlightCommandFactory::FlightCommandFactory() {

  factory["sleep"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };
  factory["print"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };
  factory["while"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };
  factory["if"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };
  factory["var"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };
  factory["bind"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };
  factory["connect"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };
  factory["openDataServer"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };
  factory["if"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };
  factory["assign"] = [](const std::vector<std::string>& args) {
    return nullptr;
  };

}

