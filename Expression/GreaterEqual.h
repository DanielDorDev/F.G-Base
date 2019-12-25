
#ifndef ED1_GREATEREQUAL_H
#define ED1_GREATEREQUAL_H


#include "BinaryExpression.h"

class GreaterEqual : public BinaryExpression {
public:
    /**
* calculates the expression.
* @return the calculated expression.
*/
    double calculate() override;


    /**
* Greater Equal boolean Expression ">="
* @param left - the left expression.
* @param right - the right expression.
*/
    GreaterEqual(Expression *left, Expression *right);


};

#endif //ED1_GREATEREQUAL_H
