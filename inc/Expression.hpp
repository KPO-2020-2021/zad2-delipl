#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include "Complex.hpp"
#include <iostream>
enum class Operator : char {
    Op_Add = '+',
    Op_Sub = '-',
    Op_Mul = '*',
    Op_Div = '/'
};
std::ostream& operator<<(std::ostream&, const Operator&);
std::istream& operator>>(std::istream&, Operator&);
class Expression {
    Complex arg1;
    Operator op;
    Complex arg2;

public:
    Complex Arg1() const { return arg1; }
    Complex Arg2() const { return arg2; }
    Operator Op() const { return op; }
    Expression();
    Expression(const Expression&);
    Expression(const Complex&, const Operator&, const Complex&);
    Complex Calculate() const;
    bool operator==(const Expression&) const;
    bool operator!=(const Expression&) const;
    friend std::istream& operator>>(std::istream&, Expression&);
};
std::ostream& operator<<(std::ostream&, const Expression&);
#endif
