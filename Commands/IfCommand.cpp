#include <utility>
#include "IfCommand.h"
#include "../Utility/Exception/InvalidCommand.h"


IfCommand::IfCommand(Expression *condSet, std::vector<ICommand *> setList) {

    if (condSet == nullptr) {
        throw InvalidCommand();
    }
    condition = condSet;
    listCommand = std::move(setList);

}


void IfCommand::doCommand() {

    if (conditionApply()) {
        for (const auto& execute : listCommand) {
            execute->doCommand();
        }
    }
}


bool IfCommand::conditionApply() {

    return condition->calculate() != 0;

}

IfCommand::~IfCommand() {

    // Iterate over list.
    for (auto &deleteIt : listCommand) {
        delete (deleteIt);
    }
    // Delete expression.
    delete (condition);
}


bool IfCommand::checkValid(const std::vector<std::string> &commands) const {
    return true;
}

