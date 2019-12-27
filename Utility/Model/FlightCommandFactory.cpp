
#include <regex>
#include <list>
#include <algorithm>
#include <iterator>
#include "FlightCommandFactory.h"
#include "../../Commands/OpenServerCommand.h"
#include "../../Expression/StringPrintExpression.h"
#include "../../Expression/PrintListExpression.h"
#include "../../Expression/ExpPrintExpression.h"

#define SPACE ' '
void FlightCommandFactory::RegisterCommand(
    std::string hash, std::function<ICommand*(const std::vector<std::string>&)> command) {
  factory[hash] = command;
}

VarCommand *FlightCommandFactory::GetVariable(const std::string & command) const {
  auto got = tableVar.find(command);

  if (got == tableVar.end()) {
    return nullptr;
  } else {
    return got->second;
  }
};

ICommand *FlightCommandFactory::GetCommand(
    const std::string &command, const std::vector<std::string> & args) const {

  try {
    auto got = factory.find(command);

    if (got == factory.end()) {
      VarCommand *variableExist = GetVariable(command);
      std::vector<std::string> vec;
      vec.emplace_back(command);
      vec.insert(std::end(vec), std::begin(args), std::end(args));
      return GetCommand(args[0], vec);
    } else {
      return got->second(args);
    }
  } catch (invalid_argument &e) {
    perror(e.what());
    throw invalid_argument("Error in GetCommand\n");
  } catch (...) {
    throw invalid_argument("Unknown error in GetCommand\n");

  }
};


FlightCommandFactory::FlightCommandFactory() {

  factory["openDataServer"] = [](const std::vector<std::string> &args) {

    try {
      return new OpenServerCommand(args);

    } catch (invalid_argument &e) {
      perror(e.what());
      throw InvalidCommand();
    } catch (...) {
      throw InvalidCommand();
    }
  };

  factory["connect"] = [](const std::vector<std::string> &args) {
    try {
      return new ConnectCommand(args);
    } catch (...) {
      throw InvalidCommand();
    }
  };


  factory["print"] = [&](const std::vector<std::string> &args) {

    std::list<IPrintExpression *> values;
    for (const auto &var : args) {

      if (var.at(0) == '\"') {
        std::string subVar(var.substr(1, var.length() - 2));
        values.emplace_back(new StringPrintExpression(subVar));
      } else {
        auto postfixParam = ShuntingYard::postfix(var);
        Expression *exp = fromPostfixToExpression(postfixParam);
        values.emplace_back(new ExpPrintExpression(exp));
      }
    }
    return new PrintCommand(new PrintListExpression(values));

  };

  factory["sleep"] = [&](const std::vector<std::string> &args) {
    try {

      stringstream dataString;
      ostream_iterator<std::string> output_iterator(dataString, " ");
      std::copy(args.begin(), args.end(), output_iterator);
      auto postfixParam = ShuntingYard::postfix(dataString.str());
      Expression *exp = fromPostfixToExpression(postfixParam);
      string toReturn = to_string(exp->calculate());
      delete (exp);
      return new SleepCommand(toReturn);

    } catch (...) {
      throw InvalidCommand();
    }

  };

  factory["while"] = [&](const std::vector<std::string> &args) {

    try {
      return new WhileCommand(handleIf(args));
    } catch (...) {
      throw InvalidCommand();
    }
  };

  factory["if"] = [&](const std::vector<std::string> &args) {

    try {

      return this->handleIf(args);

    } catch (...) {
      throw InvalidCommand();
    }
  };
  factory["var"] = [&](const std::vector<std::string> &args) {

    try {
      if (GetVariable(args[0]) != nullptr) {
        throw std::invalid_argument("var already exist in map");
      }
      auto *newVar = new VarCommand();
      tableVar[args[0]] = newVar;
      if (args[1] == "=") {
        return GetCommand("=",
                          std::vector<std::string>(args.begin(),
                                                   args.end()));
      } else {
        throw InvalidCommand();
      }
    } catch (...) {
      throw InvalidCommand();
    }
  };

  factory["="] = [&](const std::vector<std::string> &args) {

    try {

      if (args[1] != "=") {
        throw InvalidCommand();
      }
      VarCommand *varAssign = GetVariable(args[0]);
      if (varAssign == nullptr) {
        throw invalid_argument("Var " + args[0] + " doesn't exist, can't assign\n");
      }
      if (args[2] == "bind") {

        VarCommand* server = GetVariable("connectedToServer");
        if (server == nullptr) {
          throw invalid_argument("No connection appear, can't create bind\n");
        }
        BindCommand* serverBind = server->getBind();
        std::string s;
        std::for_each(args.begin() + 3, args.end() - 1,
                      [&](const std::string &piece) { s += piece; });
        serverBind->changePath(s);
        *varAssign = serverBind;
        return new AssignCommand(
            new VarExpression(*new VarCommand(*varAssign)), varAssign);
      } else {

        stringstream dataString;
        ostream_iterator<std::string> output_iterator(dataString, " ");
        std::copy(args.begin() + 2, args.end(), output_iterator);


        stack<string> tempStack = ShuntingYard::postfix(std::string(dataString.str()));
        return new AssignCommand(
            fromPostfixToExpression(tempStack), varAssign);
      }

    } catch (invalid_argument &e) {
      throw InvalidCommand();
    } catch (...) {
      throw InvalidCommand();
    }
  };
};
IfCommand *FlightCommandFactory::handleIf(vector<string> line) {
  try {
    string condition;
    auto itCond = line.begin();

    while (*itCond != "{" && itCond != line.end()) {
      condition += *itCond;
      if(!ShuntingYard::isOperator(*(itCond)) ||
      !ShuntingYard::isOperator(*(itCond + 1))) {
        condition += ' ';
      }
      ++itCond;
    }

    stack<string> stack1 = ShuntingYard::postfix(condition);

    Expression *expression = fromPostfixToExpression(stack1);

    vector<ICommand *> listCommands;
    vector<string> temp;


    for (auto it = itCond + 2 ; it != line.end() - 1; ++it) {

      auto until = find(it, line.end(), "\n");
      listCommands.emplace_back(GetCommand(*it, std::vector<std::string>(it + 1, until)));
      it = until;

    }
    return new IfCommand(expression, listCommands);
  } catch (runtime_error &e) {
    cout << e.what() << endl;
    return nullptr;
  } catch (...) {
    cout << "Error while building if command\n";
    return nullptr;
  }
}


Expression *FlightCommandFactory::fromPostfixToExpression(stack<string> &postfix) {
  if (postfix.empty()) {
    perror("Postfix is zero");
    return nullptr;
  }
  string sign = postfix.top();
  postfix.pop();

  if (sign == "+") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new Plus(leftExp, rightExp);
  } else if (sign == "-") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new Minus(leftExp, rightExp);
  } else if (sign == "*") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new Mult(leftExp, rightExp);
  } else if (sign == "/") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new Div(leftExp, rightExp);
  } else if (sign == "<=") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new SmallerEqual(leftExp, rightExp);
  } else if (sign == ">=") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new GreaterEqual(leftExp, rightExp);
  } else if (sign == ">") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new Greater(leftExp, rightExp);
  } else if (sign == "<") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new Smaller(leftExp, rightExp);
  } else if (sign == "==") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new Equal(leftExp, rightExp);
  } else if (sign == "!=") {
    Expression *rightExp = fromPostfixToExpression(postfix);
    Expression *leftExp = fromPostfixToExpression(postfix);
    return new Different(leftExp, rightExp);

  } else if (sign.length() > 1 && sign.at(0) == '-') {
    string number = sign.substr(1, sign.length() - 1);
    postfix.push(number);
    return new Negative(fromPostfixToExpression(postfix));
  } else {
    if (isalpha(sign[0])) {

      auto* a = GetVariable(sign);
      if (a != nullptr) {
        return new VarExpression(*a);
      }
      throw invalid_argument("Variable doesn't exist: " + sign);
    } else {
      //from string to double.
      return new Number(stod(sign));
    }
  }
}






