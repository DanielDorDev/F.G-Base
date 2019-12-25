#include <utility>
#include "IfCommand.h"

/**
  * Construct the if command, contain expression(condition) and commands.
  */
IfCommand::IfCommand(Expression *condSet, vector<Command *> setList) {

    if (condSet == nullptr) {
        throw invalid_argument("Trouble in condition command arguments");
    }
    this->condition = condSet;
    this->listCommand = std::move(setList);

}

/**
 * Execute the command 'if'- check for condition and if true, execute.
 */
void IfCommand::doCommand() {

    if (this->conditionApply()) {
        for (Command *execute : this->listCommand) {
            execute->doCommand();
        }
    }
}

/**
 * Check for condition apply, return true if condition is valid (not zero).
 * @return - similar to c syntax, a non zero value is true, otherwise false.
 */
bool IfCommand::conditionApply() {

    return this->condition->calculate() != 0;

}

/**
 * Get rid of the list and delete expression.
 */
IfCommand::~IfCommand() {

    // Iterate over list.
    for (auto &deleteIt : this->listCommand) {
        delete (deleteIt);
    }
    // Delete expression.
    delete (this->condition);
}

/**
* check for valid command.
* @return - true if command is valid, other wise - false.
*/
bool IfCommand::checkValid(const vector<string> &commands) const {
    return true;
}

