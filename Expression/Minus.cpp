
#include "Minus.h"

/**
 * Minus expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
Minus::Minus(Expression *left, Expression *right) : BinaryExpression(left,
                                                                     right) {}

/**
* calculates the expression.
* @return the calculated expression.
*/
double Minus::calculate() {

    return getLeft()->calculate() - getRight()->calculate();
}
