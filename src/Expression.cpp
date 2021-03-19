#include "Expression.hpp"

std::ostream&  operator << (std::ostream& cout, const Operator& op){
    return cout << op;
}
std::istream&  operator >> (std::istream &cin, Operator &op){
    // return cin >> op;
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
Expression::Expression(){
    arg1 = Complex();
    op = Operator::Op_Add;
    arg2 = Complex();
} 
Expression::Expression(const Complex &x, const Operator &o, const Complex &y){
    arg1 = x;
    op = o;
    arg2 = y;

}
Expression::Expression(const Expression &exp){
    arg1 = exp.Arg1();
    op = exp.Op();
    arg2 = exp.Arg2();
}
Complex Expression::Calculate() const{
    Complex comp;
    switch(op){
        case Operator::Op_Add:
            comp = arg1 + arg2;
            break;
        case Operator::Op_Sub:
            comp = arg1 - arg2;
            break;
        case  Operator::Op_Mul:
            comp = arg1 * arg2;
            break;
        case Operator::Op_Div:
            comp = arg1 / arg2;
            break;
        default:
            throw std::logic_error("In Complex CalculateExpression(Expression exp) Can't find operator!");
            break;
    }
    return comp;
}
bool Expression::operator == (const Expression& exp) const{
    return arg1 == exp.Arg1() && arg2 == exp.Arg2() && op == exp.Op();
}
bool Expression::operator != (const Expression& exp) const{
    return arg1 !=exp.Arg1() || arg2 != exp.Arg2() || op != exp.Op();
}

std::istream&  operator >> (std::istream &cin, Expression &exp){         
    return cin >> exp.arg1 >> exp.op >> exp.arg2;
}
std::ostream&  operator << (std::ostream &cout, const Expression &exp){         
    return cout << exp.Arg1() << static_cast<char>(exp.Op()) << exp.Arg2();
}
