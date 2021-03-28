#include "Expression.h"

std::ostream&  operator << (std::ostream& cout, const Expression::Operator& op){
    return cout << static_cast<char>(op);
}
std::istream&  operator >> (std::istream &cin, Expression::Operator &op){
    char c = '+';
    cin >> c;
    if(cin.fail()) 
        throw std::logic_error("Can't write operator");
    switch (c){
    case '+':
        op = Expression::Operator::Op_Add;
        return cin;
        break;
    case '-':
        op = Expression::Operator::Op_Sub;
        return cin;
        break;
    case '*':
        op = Expression::Operator::Op_Mul;
        return cin;
        break;
    case '/':
        op = Expression::Operator::Op_Div;
        return cin;
        break;
    default:
        throw std::logic_error("Can't write operator");
        break;
    }
}
bool operator== (const Expression::Operator op, const char c){
    return static_cast<char>(op) == c;
}
bool operator== (const Expression::Operator x, const Expression::Operator y){
    return static_cast<char>(x) == static_cast<char>(y);
}
Expression::Expression(){
    this->arg1 = Complex();
    this->op = Expression::Operator::Op_Add;
    this->arg2 = Complex();
} 
Expression::Expression(const Complex &x, const Expression::Operator &op, const Complex &y){
    this->arg1 = x;
    this->op = op;
    this->arg2 = y;

}
Expression::Expression(const Expression &exp){
    this->arg1 = exp.Arg1();
    this->op = exp.Op();
    this->arg2 = exp.Arg2();
}
Complex Expression::Calculate() const{
    Complex comp;
    switch(op){
        case Expression::Operator::Op_Add:
            comp = this->arg1 + this->arg2;
            break;
        case Expression::Operator::Op_Sub:
            comp = this->arg1 - this->arg2;
            break;
        case  Expression::Operator::Op_Mul:
            comp = this->arg1 * this->arg2;
            break;
        case Expression::Operator::Op_Div:
            comp = this->arg1 / this->arg2;
            break;
        default:
            throw std::logic_error("In Complex CalculateExpression(Expression exp) Can't find operator!");
            break;
    }
    return comp;
}
bool Expression::operator == (const Expression& exp) const{
    return this->arg1 == exp.Arg1() && this->arg2 == exp.Arg2() && this->op == exp.Op();
}
bool Expression::operator != (const Expression& exp) const{
    return this->arg1 !=exp.Arg1() || this->arg2 != exp.Arg2() || this->op != exp.Op();
}

std::istream&  operator >> (std::istream &cin, Expression &exp){         
    return cin >> exp.arg1 >> exp.op >> exp.arg2;
}
std::ostream&  operator << (std::ostream &cout, const Expression &exp){         
    return cout << exp.Arg1() << static_cast<char>(exp.Op()) << exp.Arg2();
}
