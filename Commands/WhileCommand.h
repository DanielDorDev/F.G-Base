#ifndef ED1_WHILECOMMAND_H
#define ED1_WHILECOMMAND_H

#include "Command.h"
#include "IfCommand.h"

class WhileCommand : public Command {

    // The body of the function (very similar to if, had condition and list).
    IfCommand *condition;

    /**
   * check for valid command.
   * @return - true if command is valid, other wise - false.
   */
    bool checkValid(const vector<string> &) const override;

public:

    /**
     * Construct the while command using if command.
     */
    explicit WhileCommand(IfCommand *);

/**
 * Execute the command 'if'- check for condition and if true, execute.
 * The Different is that, the while contain a loop, and if execute once.
 */
    void doCommand() override;

    /**
     * Destruct the command (that point to if condition).
     */
    ~WhileCommand() override;
};

#endif //ED1_WHILECOMMAND_H
