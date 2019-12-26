

#ifndef FLIGHTGEAR_EXPPRINTEXPRESSION_H
#define FLIGHTGEAR_EXPPRINTEXPRESSION_H

#include "../Utility/Interface/IPrintExpression.h"
#include "Expression.h"
#include <memory>
class ExpPrintExpression : public IPrintExpression {

  std::unique_ptr<Expression> value;
 public:

  explicit ExpPrintExpression(Expression* sValue) {
    value = std::unique_ptr<Expression>(sValue);
  }
  std::string to_String() override {
    return std::to_string(value->calculate());
  }

};

#endif //FLIGHTGEAR_EXPPRINTEXPRESSION_H
