
#include "SmallerEqual.h"

/**
* Smaller Equal boolean Expression "<="
* @param left - the left expression.
* @param right - the right expression.
*/
SmallerEqual::SmallerEqual(Expression *left, Expression *right)
        : BinaryExpression(left, right) {}


double SmallerEqual::calculate() {
    return getLeft()->calculate() <= getRight()->calculate();
}
