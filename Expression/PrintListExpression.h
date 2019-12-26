

#ifndef FLIGHTGEAR_PRINTLISTEXPRESSION_H
#define FLIGHTGEAR_PRINTLISTEXPRESSION_H
#include "../Utility/Interface/IPrintExpression.h"
#include <list>
#include <string>
#include <ostream>
#include <algorithm>
#include <regex>

class PrintListExpression : public IPrintExpression {

  std::list<IPrintExpression*> listValues;
 public:

  explicit PrintListExpression(const std::list<IPrintExpression*> &values) {
    listValues = values;
  }
  std::string to_String() override {
    std::string retValue;
    for (const auto& var : listValues) {
      retValue += var->to_String();
    }
    return retValue;
  }

  ~PrintListExpression() {
    listValues.clear();
  }
};
#endif //FLIGHTGEAR_PRINTLISTEXPRESSION_H
