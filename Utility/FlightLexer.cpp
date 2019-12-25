

#include <sstream>
#include <iostream>
#include "FlightLexer.h"
#include <regex>

#define DELIMITER "\"(.*?)\"|([0-9.]+)|([a-zA-Z0-9]+)|+|-|*|/|,|^|(|)|=|<|>|}|{|!"

std::vector<std::string>* FlightLexer::lexer(std::string & input) {

  auto * lexerVector = new std::vector<std::string>();


  std::regex sepByRegex (DELIMITER);

    std::regex_iterator<std::string::iterator> rit (
        input.begin(), input.end(), sepByRegex );
    std::regex_iterator<std::string::iterator> rend;

    while (rit!=rend) {
      lexerVector->push_back(rit->str());
      ++rit;
  }

  return lexerVector;
}
