#include <utility>

#include <regex>
#include "SampleTable.h"

#define COMMA ','


/**
 * Check if string exist in table.
 * @return  - true if so, otherwise false.
 */
bool SampleTable::checkExist(string nameCheck) const {
  try {
    return this->stringToSampleName.find(nameCheck) !=
            this->stringToSampleName.end();

  } catch (...) {
    perror("Problem in check valid name in string sample table\n");
    return false;
  }
}


/**
 * Get sample from table, uses sample name enum, return 0 if noting found.
 * User responsable for correct input.
 * @return - value if sample exist.
 */
double SampleTable::getSample(string name) const {

  try {
    return stod(this->sampleTable[this->stringToSampleName.at(name)]);

  } catch (...) {
    throw invalid_argument("Trouble in get sample");
  }
}


/**
 * Update fully sample table, given all data in buffer.
 * Update as strings, for prevent heavy run time usage of stod.
 * @param buffer - buffer to update by.
 */
void SampleTable::doFullUpdate(string sampleList) {

  int counter = 0;

  // Token taken from sampleList.
  string token;

  // String stream to  iterate over.
  istringstream tokenStream(sampleList);

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

/**
 * Change unique variable from given path, if not exist, throw runtime.
 * @param path - path to change.
 * @param value - value to set by.
 */
void SampleTable::doSingleUpdate(string path, double value) {

  this->sampleTable[this->stringToSampleName[path]] = to_string(value);

}

