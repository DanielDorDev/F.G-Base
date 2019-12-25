
#ifndef ED1_EXPRESSION_H
#define ED1_EXPRESSION_H

class Expression {
public:
    /**
 * calculates the expression.
 * @return the calculated expression.
 */
    virtual double calculate() = 0;

    virtual ~Expression() = default;

};

#endif //ED1_EXPRESSION_H
