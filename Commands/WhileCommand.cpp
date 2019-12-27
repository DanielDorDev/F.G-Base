
#include "WhileCommand.h"
#include "../Utility/Exception/InvalidCommand.h"


WhileCommand::WhileCommand(IfCommand *setIf) {
    try {


        this->condition = setIf;

    } catch (...) {
        throw InvalidCommand();
    }
}

void WhileCommand::doCommand() {
    while (this->condition->conditionApply()) {
        this->condition->doCommand();
    }

}
