

#ifndef ED1_BINARYEXPRESSION_H
#define ED1_BINARYEXPRESSION_H

using namespace std;

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression *left;
    Expression *right;


/**
 * binary expression inherits from Expression.
 * @param left - the left expression.
 * @param right - the right expression.
 */
    BinaryExpression(Expression *left, Expression *right);

/**
 * get right - gets the right expression.
 * @return returns the right expression.
 */
    virtual Expression *getRight() const;

/**
 * get left - gets the left expression.
 * @return returns the left expression.
 */
    virtual Expression *getLeft() const;

public:
    ~BinaryExpression() override {
        delete (left);
        delete (right);
    }
};

#endif //ED1_BINARYEXPRESSION_H
