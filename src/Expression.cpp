#include "Expression.h"

std::ostream&  operator << (std::ostream& cout, const Operator& op){
    return cout << static_cast<char>(op);
}
std::istream&  operator >> (std::istream &cin, Operator &op){
    char c = '+';
    cin >> c;
    if(cin.fail()) 
        throw std::logic_error("Can't write operator");
    switch (c){
    case '+':
        op = Operator::Op_Add;
        return cin;
        break;
    case '-':
        op = Operator::Op_Sub;
        return cin;
        break;
    case '*':
        op = Operator::Op_Mul;
        return cin;
        break;
    case '/':
        op = Operator::Op_Div;
        return cin;
        break;
    default:
        throw std::logic_error("Can't write operator");
        break;
    }
}
bool operator== (const Operator op, const char c){
    return static_cast<char>(op) == c;
}
bool operator== (const Operator x, const Operator y){
    return static_cast<char>(x) == static_cast<char>(y);
}
Expression::Expression(){
    this->arg1 = Complex();
    this->op = Operator::Op_Add;
    this->arg2 = Complex();
} 
Expression::Expression(const Complex &x, const Operator &o, const Complex &y){
    this->arg1 = x;
    this->op = o;
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
        case Operator::Op_Add:
            comp = this->arg1 + this->arg2;
            break;
        case Operator::Op_Sub:
            comp = this->arg1 - this->arg2;
            break;
        case  Operator::Op_Mul:
            comp = this->arg1 * this->arg2;
            break;
        case Operator::Op_Div:
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
