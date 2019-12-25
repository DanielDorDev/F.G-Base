

#ifndef ED1_DIFFERENT_H
#define ED1_DIFFERENT_H


#include "BinaryExpression.h"

class Different : public BinaryExpression {
public:
/**
 * Different execute the boolean operator '!='
 * @param left the left expression.
 * @param right the right expression.
 */
    Different(Expression *left, Expression *right);

/**
 * calculates the expression.
 * @return the calculated expression.
 */
    double calculate() override;
};

#endif //ED1_DIFFERENT_H
