

#ifndef FLIGHTGEAR_NOCOMMANDEXIST_H
#define FLIGHTGEAR_NOCOMMANDEXIST_H
#include <stdexcept>
class NoCommandExist : public std::logic_error
{
 public:
  NoCommandExist () : std::logic_error{"ICommand doesn't exist"} {}
};

#endif //FLIGHTGEAR_NOCOMMANDEXIST_H
