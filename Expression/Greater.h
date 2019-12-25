
#ifndef ED1_GREATER_H
#define ED1_GREATER_H


#include "BinaryExpression.h"

class Greater : public BinaryExpression {
public:
    /**
 * calculates the expression.
 * @return the calculated expression.
 */
    double calculate() override;

    /**
 * Greater boolean Expression ">"
 * @param left - the left expression.
 * @param right - the right expression.
 */
    Greater(Expression *left, Expression *right);
};

#endif //ED1_GREATER_H
