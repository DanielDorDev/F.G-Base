
#include "BinaryExpression.h"


/**
 * binary expression inherits from Expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
BinaryExpression::BinaryExpression(Expression *left, Expression *right) : left(
        left), right(right) {}

/**
 * get right - gets the right expression.
 * @return returns the right expression.
 */
Expression *BinaryExpression::getRight() const {
    return right;
}

/**
 * get left - gets the left expression.
 * @return returns the left expression.
 */
Expression *BinaryExpression::getLeft() const {
    return left;
}
