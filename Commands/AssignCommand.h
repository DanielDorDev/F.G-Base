#ifndef ED1_ASSIGNCOMMAND_H
#define ED1_ASSIGNCOMMAND_H

#include "../Utility/Interface/ICommand.h"
#include "VarCommand.h"
#include "../Expression/Expression.h"

class AssignCommand : public ICommand {

    Expression *right;
    VarCommand *left;
public:

    AssignCommand(Expression *setRight, VarCommand *setLeft) {
        right = setRight;
        left = setLeft;

    }

    void doCommand() override {
        *this->left = this->right->calculate();
    }

    ~AssignCommand() override {
      delete right;
    }
};

#endif //ED1_ASSIGNCOMMAND_H
