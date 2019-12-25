
#include "Equal.h"

/**
 * Equal expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
Equal::Equal(Expression *left, Expression *right) : BinaryExpression(left,
                                                                     right) {}

/**
 * calculates the expression.
 * @return the calculated expression.
 */
double Equal::calculate() {
    return getLeft()->calculate() == getRight()->calculate();
}
