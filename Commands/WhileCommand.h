#ifndef ED1_WHILECOMMAND_H
#define ED1_WHILECOMMAND_H

#include "../Utility/Interface/ICommand.h"
#include "IfCommand.h"

class WhileCommand : public ICommand {

    IfCommand *condition;


public:

    explicit WhileCommand(IfCommand *);

    void doCommand() override;

    ~WhileCommand() override;
};

#endif //ED1_WHILECOMMAND_H
