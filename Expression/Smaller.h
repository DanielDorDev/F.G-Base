

#ifndef ED1_SMALLER_H
#define ED1_SMALLER_H


#include "BinaryExpression.h"

class Smaller : public BinaryExpression {
public:

/**
* calculates the expression.
* @return the calculated expression.
*/
    double calculate() override;

    /**
 * Smaller boolean Expression "<"
 * @param left - the left expression.
 * @param right - the right expression.
 */
    Smaller(Expression *left, Expression *right);
};

#endif //ED1_SMALLER_H
