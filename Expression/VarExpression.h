
#ifndef ED1_VAREXPRESSION_H
#define ED1_VAREXPRESSION_H

#include "Expression.h"
#include "../Commands/VarCommand.h"

class VarExpression : public Expression {
  VarCommand *command;
 public:
  /**
* Var Exspression.
* @param setCommand - the command to set.
*/
  explicit VarExpression(VarCommand &command);

  /**
* calculates the expression.
* @return the calculated expression.
*/
  double calculate() override;

  ~VarExpression() override {
      delete command;
  }

};

#endif //ED1_VAREXPRESSION_H
