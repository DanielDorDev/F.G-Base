
#ifndef ED1_NEGATIVE_H
#define ED1_NEGATIVE_H

using namespace std;

#include "UnaryExpression.h"

class Negative : public UnaryExpression {
public:

    /**
* calculates the expression.
* @return the calculated expression.
*/
    double calculate() override;

    /**
 * Negative Expression.
 * @param unary - the only expression.
 */
    Negative(Expression *unary);
};

#endif //ED1_NEGATIVE_H
