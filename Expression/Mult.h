

#ifndef ED1_MULT_H
#define ED1_MULT_H

#include "BinaryExpression.h"

class Mult : public BinaryExpression {
public:

    /**
 * Multiply Expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
    Mult(Expression *left, Expression *right);

/**
* calculates the expression.
* @return the calculated expression.
*/
    double calculate() override;

};

#endif //ED1_MULT_H
