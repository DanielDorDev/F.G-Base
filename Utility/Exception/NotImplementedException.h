
#ifndef NOTIMPLEMENTED_H
#define NOTIMPLEMENTED_H
#include <stdexcept>
class NotImplementedException : public std::logic_error
{
 public:
  NotImplementedException () : std::logic_error{"Function not yet implemented."} {}
};

#endif