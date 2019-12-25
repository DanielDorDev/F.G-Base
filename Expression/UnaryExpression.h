
#ifndef ED1_UNARYEXPRESSION_H
#define ED1_UNARYEXPRESSION_H

#include "Expression.h"


class UnaryExpression : public Expression {

protected:
    Expression *unary;

    /**
 * Unary Expression.
 * @param unary - the only expression.
 */
    explicit UnaryExpression(Expression *unary);

    /**
   * Get unary func.
   * @return
   */
    Expression *getUnary() const;

public:
    ~UnaryExpression() override {
        delete (unary);
    }
};

#endif //ED1_UNARYEXPRESSION_H
