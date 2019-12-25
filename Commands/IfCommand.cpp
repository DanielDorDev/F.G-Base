#include <utility>
#include "IfCommand.h"
#include "../Utility/Exception/InvalidCommand.h"


IfCommand::IfCommand(Expression *condSet, std::vector<ICommand *> setList) {

    if (condSet == nullptr) {
        throw InvalidCommand();
    }
    this->condition = condSet;
    this->listCommand = std::move(setList);

}


void IfCommand::doCommand() {

    if (this->conditionApply()) {
        for (ICommand *execute : this->listCommand) {
            execute->doCommand();
        }
    }
}


bool IfCommand::conditionApply() {

    return this->condition->calculate() != 0;

}

IfCommand::~IfCommand() {

    // Iterate over list.
    for (auto &deleteIt : this->listCommand) {
        delete (deleteIt);
    }
    // Delete expression.
    delete (this->condition);
}


bool IfCommand::checkValid(const std::vector<std::string> &commands) const {
    return true;
}

