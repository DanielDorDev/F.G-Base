#include <iostream>
#include "Utility/ExecuteInterpreter.h"
#include "Utility/FlightLexer.h"
#include "Utility/FlightParser.h"
#include "Utility/FlightCommandFactory.h"
#include <memory>
#define SCRIPT_EXIST  (argc == 2)

int main(int argc, char *argv[]) {

  std::unique_ptr<ExecuteInterpreter> flightInterpreter(new ExecuteInterpreter(
      new FlightLexer(), new FlightParser(), new FlightCommandFactory()));


  // Check for script existence (Two args, [1] for file name).
  if (SCRIPT_EXIST) {

    // Execute interpreter for script.
    flightInterpreter->ExecuteFromFile(argv[1]);

  } else {
    // Execute from terminal.
    flightInterpreter->ExecuteFromTerminal();
  }
  exit (0);
}