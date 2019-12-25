

#include "UnaryExpression.h"

/**
 * Unary Expression.
 * @param unary - the only expression.
 */
UnaryExpression::UnaryExpression(Expression *unary) : unary(unary) {}

/**
 * Get unary func.
 * @return
 */
Expression *UnaryExpression::getUnary() const {
    return unary;
}
