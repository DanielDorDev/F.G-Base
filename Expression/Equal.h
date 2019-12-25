#ifndef ED1_EQUAL_H
#define ED1_EQUAL_H

#include "BinaryExpression.h"

class Equal : public BinaryExpression {

public:


/**
 * Equal expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
    Equal(Expression *left, Expression *right);

    /**
 * calculates the expression.
 * @return the calculated expression.
 */
    double calculate() override;

};

#endif //ED1_EQUAL_H
