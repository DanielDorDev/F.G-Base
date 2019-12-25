
#include "Mult.h"

/**
 * Multiply Expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
Mult::Mult(Expression *left, Expression *right) : BinaryExpression(left,
                                                                   right) {}

/**
* calculates the expression.
* @return the calculated expression.
*/
double Mult::calculate() {
    return getLeft()->calculate() * getRight()->calculate();
}
