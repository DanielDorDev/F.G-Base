#include <utility>

#ifndef FLIGHTGEAR_STRINGPRINTEXPRESSION_H
#define FLIGHTGEAR_STRINGPRINTEXPRESSION_H

#include "../Utility/Interface/IPrintExpression.h"
class StringPrintExpression : public IPrintExpression {

  std::string value;
 public:

  explicit StringPrintExpression(std::string& sValue) {
    value = sValue;
  }

  explicit StringPrintExpression(const char* sValue) {
    value = sValue;
  }
  std::string to_String() override {
    return value;
  }

   ~StringPrintExpression() override = default;
};

#endif //FLIGHTGEAR_STRINGPRINTEXPRESSION_H
