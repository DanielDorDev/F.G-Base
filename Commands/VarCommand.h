#ifndef ED1_VARCOMMAND_H
#define ED1_VARCOMMAND_H


#include "BindCommand.h"
#include "../Expression/Number.h"

class VarCommand {

    BindCommand *bind = nullptr;
    Expression* value;

public:
    BindCommand *getBind() const;
    VarCommand();
    explicit VarCommand(double bindSet);
    explicit VarCommand(BindCommand *bindSet);
    double getValue() const;
    VarCommand &operator=(const VarCommand &);
    VarCommand &operator=(double setValue);
    VarCommand &operator=(BindCommand *);

    ~VarCommand() {
      delete bind;
      delete value;
    }
};


#endif //ED1_VARCOMMAND_H
