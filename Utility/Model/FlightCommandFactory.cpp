
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
    throw invalid_argument("Can't find variable");
  } else {
    return got->second;
  }
};

ICommand *FlightCommandFactory::GetCommand(
    const std::string &command, const std::vector<std::string> & args) const {
  auto got = factory.find(command);

  if (got == factory.end()) {
    VarCommand *variableExist = GetVariable(command);

      return GetCommand(
          args.front(), std::vector<std::string>(args.begin() + 1, args.end()));
  } else {
    return got->second(args);
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
      if (GetVariable(args[0]) == nullptr) {
        throw std::invalid_argument("var already exist in map");
      }
      auto *newVar = new VarCommand();
      tableVar[args[0]] = newVar;
      if (args[1] == "=") {
        return GetCommand("=",
                          std::vector<std::string>(args.begin() + 1,
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
      if (args[2] == "bind") {

        VarCommand* server = GetVariable("connectedToServer");
        BindCommand* serverBind = server->getBind();
        std::string s;
        std::for_each(args.begin() + 3, args.end() - 1,
                      [&](const std::string &piece) { s += piece; });
        serverBind->changePath(s);
        *varAssign = serverBind;
        return new AssignCommand(
            new VarExpression(*new VarCommand(*varAssign)), varAssign);
      } else {

        std::string s;
        std::for_each(args.begin() + 2, args.end(),
                      [&](const std::string &piece) { s += piece; });
        stack<string> tempStack = ShuntingYard::postfix(s);
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
      if(!ShuntingYard::isOperator(*(itCond)) || !ShuntingYard::isOperator(*(itCond + 1))) {
        condition += ' ';

      }
      ++itCond;
    }


    stack<string> stack1 = ShuntingYard::postfix(condition);

    Expression *expression = fromPostfixToExpression(stack1);

    vector<ICommand *> listCommands;
    vector<string> temp;

    for (auto it = line.begin(); it != line.end(); it++) {


      if (*it == "}") {
        line.erase(it);
      }


      if (*it == "\n" & !temp.empty()) {
        listCommands.push_back(parser(temp));
        temp.clear();
      }
      if (*it != "\n") {
        temp.push_back(*it);
      }

      if (*it == "while" | *it == "if") {

        int count = 1;
        while (*it != "{") {
          listCommands.push_back(parser(temp));
        }
        while (count != 0) {
          if (*it == "{") {
            ++count;
          }
          if (*it == "}") {
            --count;
          }

          listCommands.push_back(parser(temp));
          ++it;
        }
        listCommands.push_back(parser(temp));
      }
    }
    return new IfCommand(expression, listCommands);
  } catch (runtime_error &e) {
    cout << e.what() << endl;
    return nullptr;
  } catch (...) {
    cout << "Error while building loop command\n";
    return nullptr;
  }
}


Expression *FlightCommandFactory::fromPostfixToExpression(stack<string> &postfix) {

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






