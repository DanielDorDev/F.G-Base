#ifndef ED1_IFCOMMAND_H
#define ED1_IFCOMMAND_H

#include "../Utility/Interface/ICommand.h"
#include "../Expression/Expression.h"
#include <vector>
#include <string>
class IfCommand : public ICommand {

    // Expression will be our condition, and list of commands are the execute.
    Expression *condition;
    std::vector<ICommand *> listCommand;

public:

    /**
     * Construct the if command, contain expression(condition) and commands.
     */
    explicit IfCommand(Expression*, std::vector<ICommand *>);

/**
 * Check for condition apply, return true if condition is valid (not zero).
 * @return - similar to c syntax, a non zero value is true, otherwise false.
 */
    bool conditionApply();

    /**
     * check for valid command.
     * @return - true if command is valid, other wise - false.
     */
    bool checkValid(const std::vector<std::string> &) const ;

    /**
     * Execute the command 'if'- check for condition and if true, execute.
     */
    void doCommand() override;

    /**
     * Get rid of the list and delete expression.
     */
    ~IfCommand() override;
};

#endif //ED1_IFCOMMAND_H
