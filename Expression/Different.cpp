

#include "Different.h"

/**
 * Different execute the boolean operator '!='
 * @param left the left expression.
 * @param right the right expression.
 */
Different::Different(Expression *left, Expression *right) : BinaryExpression(
        left, right) {}

/**
 * calculates the expression.
 * @return the calculated expression.
 */
double Different::calculate() {
    return getLeft()->calculate() != getRight()->calculate();

}
