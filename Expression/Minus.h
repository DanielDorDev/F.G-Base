
#ifndef ED1_MINUS_H
#define ED1_MINUS_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:

    /**
 * Minus expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
    Minus(Expression *left, Expression *right);

    /**
 * calculates the expression.
 * @return the calculated expression.
 */
    double calculate() override;

};

#endif //ED1_MINUS_H
