
#ifndef ED1_SMALLEREQUAL_H
#define ED1_SMALLEREQUAL_H


#include "BinaryExpression.h"

class SmallerEqual : public BinaryExpression {
public:

    /**
* calculates the expression.
* @return the calculated expression.
*/
    double calculate() override;

/**
* Smaller Equal boolean Expression "<="
* @param left - the left expression.
* @param right - the right expression.
*/
    SmallerEqual(Expression *left, Expression *right);

};

#endif //ED1_SMALLEREQUAL_H
