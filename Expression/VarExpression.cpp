
#include "VarExpression.h"



VarExpression::VarExpression(VarCommand &setCommand) {

    command = &setCommand;
}

double VarExpression::calculate() {
    return this->command->getValue();
}
