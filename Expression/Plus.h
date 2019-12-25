
#ifndef ED1_PLUS_H
#define ED1_PLUS_H


#include "BinaryExpression.h"

using namespace std;

class Plus : public BinaryExpression {
public:
    /**
* calculates the expression.
* @return the calculated expression.
*/
    double calculate() override;

    /**
 * Plus Expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
    Plus(Expression *left, Expression *right);
};

#endif //ED1_PLUS_H
