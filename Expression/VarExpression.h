
#ifndef ED1_VAREXPRESSION_H
#define ED1_VAREXPRESSION_H

#include "../Commands/VarCommand.h"
class VarExpression : public Expression {

  VarCommand* command;
 public:

   explicit VarExpression(const VarCommand&);

   double calculate() override;

   ~VarExpression() override {
     delete command;
   }

};

#endif //ED1_VAREXPRESSION_H
