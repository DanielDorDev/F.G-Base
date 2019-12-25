
#ifndef ED1_PRINTCOMMAND_H
#define ED1_PRINTCOMMAND_H

#include "../Utility/Interface/ICommand.h"
#include "VarCommand.h"
#include "../Expression/Expression.h"

/**
 * Printing class, print massage or printable objects.
 */

class PrintCommand : public ICommand {

  Expression* printIt;
  std::string printString;
 public:

  /**
   * Execute the command , print the printExp value if exsit, other wise string.
   */
  void doCommand() override {
    cout << (printIt->calculate()) << endl;
  }


  /**
   * Print command construct using expression (can return variable values).
   * @param printValue - expression with who to construct.
   */
  explicit PrintCommand(Expression* printValue) {
      printIt = printValue;
  }

  explicit PrintCommand(std::string printValue) {
    printString = printValue;
  }
};

#endif //ED1_PRINTCOMMAND_H
