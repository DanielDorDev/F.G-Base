
#ifndef ED1_DIV_H
#define ED1_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:

    /**
 * calculates the expression.
 * @return the calculated expression.
 */
    double calculate() override;

    /**
 * Division expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
    Div(Expression *left, Expression *right);
};

#endif //ED1_DIV_H
