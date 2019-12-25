
#include "WhileCommand.h"

/**
 * Construct the while command using if command.
 */
WhileCommand::WhileCommand(IfCommand *setIf) {
    try {


        this->condition = setIf;

    } catch (...) {
        throw invalid_argument("Can't create while command\n");
    }
}

/**
 * check for valid command.
 * @return - true if command is valid, other wise - false.
 */
bool WhileCommand::checkValid(const vector<string> &commands) const {

    return this->condition->checkValid(commands);
}


/**
 * Execute the command 'if'- check for condition and if true, execute.
 * The Different is that, the while contain a loop, and if execute once.
 */
void WhileCommand::doCommand() {

    while (this->condition->conditionApply()) {
        this->condition->doCommand();
    }

}

/**
 * Destruct the command (that point to if condition).
 */
WhileCommand::~WhileCommand() {

    delete (this->condition);

}
