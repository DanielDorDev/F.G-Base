#ifndef ED1_VARCOMMAND_H
#define ED1_VARCOMMAND_H

#include "BindCommand.h"

class VarCommand : public Command {

    BindCommand *bind = nullptr;
    double value;

    bool checkValid(const vector<string> &) const override;

public:


    BindCommand *getBind() const;

    /**
   * Set var command.
   * @param bindSet - bind to set by, and a name of variable.
   * @param name, name of the variable(string).
   */
    explicit VarCommand(double bindSet);

    /**
     * Set var command.
     * @param bindSet - bind to set by, and a name of variable.
     * @param name, name of the variable.
     */
    explicit VarCommand(BindCommand *bindSet);

    /**
   * @return - the value of the variable.
   */
    double getValue() const;


    void doCommand() override;

    /**
   * Change var command by given another var command with a value inside.
   * @return - VarCommand changed.
   */
    VarCommand &operator=(const VarCommand &);

    VarCommand &operator=(double setValue);


    /**
   * Change var command by given path, bind it to the path.
   * @return - VarCommand changed.
   */
    VarCommand &operator=(BindCommand *);

    ~VarCommand() override;
};


#endif //ED1_VARCOMMAND_H
