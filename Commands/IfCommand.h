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


    explicit IfCommand(Expression*, std::vector<ICommand *>);

    bool conditionApply();


    bool checkValid(const std::vector<std::string> &) const ;


    void doCommand() override;


    ~IfCommand() override {
        for (auto &var : listCommand) {
            delete var;
        };
        delete condition;

    }
};

#endif //ED1_IFCOMMAND_H
