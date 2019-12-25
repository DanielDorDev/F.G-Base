
#include "Smaller.h"

/**
 * Smaller boolean Expression "<"
 * @param left - the left expression.
 * @param right - the right expression.
 */
Smaller::Smaller(Expression *left, Expression *right) : BinaryExpression(left,
                                                                         right) {}

/**
* calculates the expression.
* @return the calculated expression.
*/
double Smaller::calculate() {
    return getLeft()->calculate() < getRight()->calculate();
}
