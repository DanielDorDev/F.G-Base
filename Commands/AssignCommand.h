#ifndef ED1_ASSIGNCOMMAND_H
#define ED1_ASSIGNCOMMAND_H

#include "Command.h"
#include "VarCommand.h"
#include "../Expression/Expression.h"

class AssignCommand : public Command {

    Expression *right;
    VarCommand *left;
public:
    /**
     * Assign Command execute the boolean operator '='
     * @param setRight - the right expression
     * @param setLeft  - the left expression
     */
    AssignCommand(Expression *setRight, VarCommand *setLeft) {
        this->right = setRight;
        this->left = setLeft;

    }

/**
 * checks if valid.
 */
    bool checkValid(const vector<string> &) const override {};

    /**
     * execute the command.
     */
    void doCommand() override {
        *this->left = this->right->calculate();
    }

    ~AssignCommand() override {
        delete left;
        delete right;
    }
};

#endif //ED1_ASSIGNCOMMAND_H
