/**
 * @brief   Library to use Complex numbers in one Expression
 * @author  Jakub Delicat
 * @version 1.0v
 * @date    28.03.2021r.
 */

#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include "Complex.h"
#include <iostream>

/**
 * @brief   Class with Expression of Complex numbers. Allow to read and calculate 
 *          Complex Expression.          
 */
class Expression {
public:
    /**
     * @brief Mathematical operators saved as char to print easly.
    */
    enum class Operator : char {
        Op_Add = '+',
        Op_Sub = '-',
        Op_Mul = '*',
        Op_Div = '/'
    };

    /**
     * @brief Print Operator.
     * @return std::istream& input stream.
     */
    friend std::istream& operator>>(std::istream&, Operator&);

private:
    /**
     * @brief First Complex of mathematic operation.
     */
    Complex arg1;

    /**
     * @brief Matemathical operator between two Complex numbers.
     */
    Operator op;

    /**
     * @brief Second Complex of mathematic operation.
     */
    Complex arg2;

public:
    /**
     * @brief   Construct a new Expression object and 
                set Complex to 0 and Operator to addition.
     */
    Expression();

    /**
     * @brief Construct a new Expression object.
     * @param Complex First Complex.
     * @param Operator Mathemathic Operator.
     * @param Complex Second Complex.
     */
    Expression(const Complex&, const Operator&, const Complex&);

    /**
     * @brief Construct a new Expression object.
     * @param Expression Copy arg1, arg2 and op.
     */
    Expression(const Expression&);

    /**
     * @brief Acces to read first Complex.
     * @return Complex arg1.
     */
    Complex Arg1() const { return arg1; }

    /**
     * @brief Acces to read second Complex.
     * @return Complex arg2.
     */
    Complex Arg2() const { return arg2; }

    /**
     * @brief Accest to read Operator.
     * @return Operator @a op.
     */
    Operator Op() const { return op; }

    /**
     * @brief Execute Expression.
     * @return Complex result of Expression.
     */
    Complex Calculate() const;

    /**
     * @brief Compare two Expressions.
     * @return  True when they are the same. 
                False when they are not the same.
     */
    bool operator==(const Expression&) const;

    /**
     * @brief Compare two Expressions.
     * @return  False when they are the same. 
                True when they are not the same.
     */
    bool operator!=(const Expression&) const;

    /**
     * @brief Read Expression.
     * @return std::ostream& input stream.
    */
    friend std::istream& operator>>(std::istream&, Expression&);
};

/**
 * @brief Compare Operator and char
 * @return  True when Operator value is the char value. 
            False when Operator value is not the char value.
 */
bool operator== (const Expression::Operator, const char);

/**
 * @brief Compare two Operators
 * @return  True when they are the same.
            False when they are not.
 */
bool operator== (const Expression::Operator, const Expression::Operator);

/**
 * @brief Read Operator.
 * @return std::ostream& output stream.
 */
std::ostream& operator<<(std::ostream&, const Expression::Operator&);

/**
 * @brief Print Expression.
 * @return std::ostream& output stream.
 */
std::ostream& operator<<(std::ostream&, const Expression&);

#endif
