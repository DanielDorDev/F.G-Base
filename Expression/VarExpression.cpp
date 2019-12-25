
#include "VarExpression.h"



VarExpression::VarExpression(const VarCommand &setCommand) {

    command = new VarCommand(setCommand);
}

double VarExpression::calculate() {
    return this->command->getValue();
}
