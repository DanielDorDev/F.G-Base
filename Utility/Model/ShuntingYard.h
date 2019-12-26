#ifndef ED1_SHUNTINGYARD_H
#define ED1_SHUNTINGYARD_H

#include "../../Expression/Number.h"
#include "../../Expression/Plus.h"
#include "../../Expression/Minus.h"
#include "../../Expression/Mult.h"
#include "../../Expression/Div.h"
#include "../../Expression/Equal.h"
#include "../../Expression/Different.h"
#include "../../Expression/Greater.h"
#include "../../Expression/Smaller.h"
#include "../../Expression/Negative.h"
#include "../../Utility/Interface/ICommand.h"
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>

#define PLUS "+"
#define MINUS "-"
#define MULT "*"
#define DIV "/"
#define POW "^"
#define APPLY "="
#define EQUAL "=="
#define DIFFERENT "!="
#define LEFT_BRACKET "("
#define RIGHT_BRACKET ")"
#define GREATER ">"
#define GREATER_EQUALL ">="
#define SMALLER "<"
#define SMALLER_EQUALL "<="


using namespace std;

  class ShuntingYard {

 public:
  static stack<string> postfix(string src);

    static bool isOperator(string &str);


   private:
  static int findPriority(string &str);


  static bool isNumber(string &str);

};

#endif //ED1_SHUNTINGYARD_H
