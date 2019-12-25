
#ifndef ED1_PRINTCOMMAND_H
#define ED1_PRINTCOMMAND_H

#include "ICommand.h"
#include "VarCommand.h"
#include "../Expression/Expression.h"

/**
 * Printing class, print massage or printable objects.
 */
class PrintCommand : public ICommand {

  // String to print, or expression if asked.
  string printString;
  Expression *printExp = nullptr;

 public:

  /**
   * Execute the command , print the printExp value if exsit, other wise string.
   */
  void doCommand() override {

      if (this->printExp != nullptr) {
          cout << to_string(this->printExp->calculate()) << endl;
      } else {
        cout << this->printString << endl;
      }
  }

  /**
   * Construct print command with string.
   * @param setPrint - string to construct by.
   */
  explicit PrintCommand(const string &setPrint) {

      if (!setPrint.empty()) {
          this->printString = setPrint;

      } else {
          throw invalid_argument("Empty string, nothing will be printed");
      }
  }

  /**
   * Print command construct using expression (can return variable values).
   * @param printValue - expression with who to construct.
   */
  explicit PrintCommand(Expression *printValue) {
      this->printExp = printValue;
  }

  /**
  * Print printable object, use predefined print function.
  * @param printable
  */
  bool checkValid(const vector<string> &checkIt) const override {
      return (!checkIt.empty());
  }

  /**
   * Construct safe delete the print exp.
   */
  ~PrintCommand() override {
      if (this->printExp != nullptr) {
          delete (this->printExp);
      }
  }

};

#endif //ED1_PRINTCOMMAND_H
