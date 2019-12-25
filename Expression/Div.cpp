
#include "Div.h"

/**
 * Division expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
Div::Div(Expression *left, Expression *right) : BinaryExpression(left, right) {}

/**
 * calculates the expression.
 * @return the calculated expression.
 */
double Div::calculate() {
    return getLeft()->calculate() / getRight()->calculate();
}