
#ifndef ED1_NUMBER_H
#define ED1_NUMBER_H

#include "Expression.h"

class Number : public Expression {
    double number;

public:

    /**
 * Number Expression.
 * @param number - the actual number.
 */
    Number(double number);

    /**
 * Get number func.
 * @return - returns the number.
 */
    double getNumber() const;

    /**
* calculates the expression.
* @return the calculated expression.
*/
    double calculate() override;
};


#endif //ED1_NUMBER_H
