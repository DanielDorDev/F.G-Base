
#include "VarExpression.h"

/**
 * Var Exspression.
 * @param setCommand - the command to set.
 */
VarExpression::VarExpression(VarCommand &setCommand) {
    this->command = &setCommand;
}

/**
* calculates the expression.
* @return the calculated expression.
*/
double VarExpression::calculate() {
    return this->command->getValue();
}
