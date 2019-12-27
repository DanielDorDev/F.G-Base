

#ifndef FLIGHTGEAR_FLIGHTCOMMANDFACTORY_H
#define FLIGHTGEAR_FLIGHTCOMMANDFACTORY_H
#include "../Interface/ICommand.h"
#include "../Interface/IFactory.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include "FlightCommandFactory.h"
#include "../../Expression/Expression.h"
#include "../../Commands/SleepCommand.h"
#include "../../Commands/PrintCommand.h"
#include "../../Commands/WhileCommand.h"
#include "../../Commands/AssignCommand.h"
#include "../../Expression/Expression.h"
#include "../../Expression/Plus.h"
#include "../../Expression/Minus.h"
#include "../../Expression/Mult.h"
#include "../../Expression/Div.h"
#include "../../Expression/Equal.h"
#include "../../Expression/Different.h"
#include "../../Expression/Greater.h"
#include "../../Expression/Smaller.h"
#include "../../Expression/Negative.h"
#include "../../Expression/Number.h"
#include "../../Expression/VarExpression.h"
#include "../../Expression/GreaterEqual.h"
#include "../../Expression/SmallerEqual.h"
#include "ShuntingYard.h"
#include "../Interface/IParser.h"

#define LEFT_BRACKET "("
#define RIGHT_BRACKET ")"



using namespace std;

class FlightCommandFactory : public IFactory<std::string, ICommand*>{

  std::unordered_map<std::string, std::function<ICommand*(const std::vector<std::string>&)>> factory;
  unordered_map<string, VarCommand *> tableVar;

  VarCommand* GetVariable(const std::string&) const;

  Expression *fromPostfixToExpression(stack<string> &postfix);

  IfCommand *handleIf(vector<string> line);

 public:
  FlightCommandFactory();

  void RegisterCommand(std::string, std::function<ICommand*(const std::vector<std::string>&)>) override;
  ICommand* GetCommand(const std::string &command, const std::vector<std::string>&) const override;

  virtual ~FlightCommandFactory() {
    factory.rehash(0);
    tableVar.rehash(0);


  }
};

#endif //FLIGHTGEAR_FLIGHTCOMMANDFACTORY_H
