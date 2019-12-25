
#include "GreaterEqual.h"

/**
* Greater Equal boolean Expression ">="
* @param left - the left expression.
* @param right - the right expression.
*/
GreaterEqual::GreaterEqual(Expression *left, Expression *right)
        : BinaryExpression(left, right) {}

/**
* calculates the expression.
* @return the calculated expression.
*/
double GreaterEqual::calculate() {
    return getLeft()->calculate() >= getRight()->calculate();
}