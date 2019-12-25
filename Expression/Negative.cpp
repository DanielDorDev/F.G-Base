
#include "Negative.h"

/**
 * Negative Expression.
 * @param unary - the only expression.
 */
Negative::Negative(Expression *unary) : UnaryExpression(unary) {}

/**
* calculates the expression.
* @return the calculated expression.
*/
double Negative::calculate() {
    return -1 * getUnary()->calculate();
}
