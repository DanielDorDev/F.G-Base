
#include "Number.h"

/**
 * Number Expression.
 * @param number - the actual number.
 */
Number::Number(double number) : number(number) {}

/**
 * Get number func.
 * @return - returns the number.
 */
double Number::getNumber() const {
    return number;
}

/**
* calculates the expression.
* @return the calculated expression.
*/
double Number::calculate() {
    return this->getNumber();
}
