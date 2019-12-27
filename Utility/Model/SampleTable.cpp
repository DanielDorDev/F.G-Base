#include <utility>

#include <regex>
#include "SampleTable.h"
#include "../Exception/NoCommandExist.h"
#define COMMA ','


bool SampleTable::checkExist(std::string nameCheck) const {
  try {
    return this->stringToSampleName.find(nameCheck) !=
            this->stringToSampleName.end();

  } catch (...) {
    perror("Problem in check valid name in string sample table\n");
    return false;
  }
}


double SampleTable::getSample(std::string name) const {

  try {
    return stod(this->sampleTable[this->stringToSampleName.at(name)]);

  } catch (...) {
    throw NoCommandExist();
  }
}

void SampleTable::doFullUpdate(std::string sampleList) {

 // std::cout<<sampleList<<std::endl;
  int counter = 0;

  // Token taken from sampleList.
  std::string token;

  // String stream to  iterate over.
  std::istringstream tokenStream(sampleList);

  // Iterate over all variables separated by comma.
  while (getline(tokenStream, token, COMMA)) {
    this->sampleTable[counter] = token;
    ++counter;

    // Went over all variables, prevent out of range.
    if (counter == XML_SAMPLE_SIZE) {
      return;
    }
  }
}

void SampleTable::doSingleUpdate(std::string path, double value) {

  this->sampleTable[this->stringToSampleName[path]] = std::to_string(value);

}

