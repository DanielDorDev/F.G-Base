
#ifndef FLIGHTGEAR_IPRINTEXPRESSION_H
#define FLIGHTGEAR_IPRINTEXPRESSION_H

#include <string>
class IPrintExpression {

 public:
  virtual std::string to_String() = 0;
};

#endif //FLIGHTGEAR_IPRINTEXPRESSION_H
