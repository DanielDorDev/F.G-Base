
#include "Plus.h"

/**
 * Plus Expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left,
                                                                   right) {}

/**
* calculates the expression.
* @return the calculated expression.
*/
double Plus::calculate() {
    return getLeft()->calculate() + getRight()->calculate();
}
