
#include "Greater.h"


/**
 * Greater boolean Expression ">"
 * @param left - the left expression.
 * @param right - the right expression.
 */
Greater::Greater(Expression *left, Expression *right) : BinaryExpression(left,
                                                                         right) {}

/**
 * calculates the expression.
 * @return the calculated expression.
 */
double Greater::calculate() {
    return getLeft()->calculate() > getRight()->calculate();
}
