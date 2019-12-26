
#ifndef ED1_PRINTCOMMAND_H
#define ED1_PRINTCOMMAND_H

#include "../Utility/Interface/ICommand.h"
#include "VarCommand.h"
#include "../Utility/Interface/IPrintExpression.h"

class PrintCommand : public ICommand {

  IPrintExpression* value;
 public:

  void doCommand() override {
    cout<<value->to_String()<<endl;
  }

  explicit PrintCommand(IPrintExpression* printValue) {
    value = printValue;
  }

};

#endif //ED1_PRINTCOMMAND_H
