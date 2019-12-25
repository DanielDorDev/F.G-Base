

#ifndef FLIGHTGEAR_INVALIDCOMMAND_H
#define FLIGHTGEAR_INVALIDCOMMAND_H
#include <stdexcept>

class InvalidCommand : public std::logic_error
{
 public:
  InvalidCommand () : std::logic_error{"Invalid command arguments"} {}
};

#endif //FLIGHTGEAR_INVALIDCOMMAND_H
