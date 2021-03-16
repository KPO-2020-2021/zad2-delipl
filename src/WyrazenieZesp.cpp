#include "WyrazenieZesp.hh"
ComplexOrDouble::ComplexOrDouble(){}
ComplexOrDouble::ComplexOrDouble(double x, double y){
    if(y == 0){
        number = x;
        type = Types::t_double;
    }
    else{
        comp.re = x;
        comp.im = y;
        type = Types::t_complex;
    }
}
std::ostream&  operator << (std::ostream& cout,  Operator op){
    switch(op){
        case Operator::Op_Dodaj:    return cout << "+"; 
        case Operator::Op_Odejmij:  return cout << "-"; 
        case Operator::Op_Mnoz:     return cout << "*"; 
        case Operator::Op_Dziel:    return cout << "/"; 
        default: 
            throw "In std::ostream&  operator << (std::ostream& cout,  Operator op) Can't find an operator!";
            return cout;
    }
}
std::istream&  operator >> (std::istream &cin, Operator &op){
    std::string text;
    cin >> text;
    switch(text[0]){
        case '+':
            op =  Operator::Op_Dodaj;
            break;
        case '-':
            op = Operator::Op_Odejmij;
            break;
        case '*':
            op = Operator::Op_Mnoz;
            break;
        case '/':
            op = Operator::Op_Dziel;
            break;
        default:
            throw "In std::istream&  operator >> (std::istream &cin, Operator &op) Can't find an operator!";
            op = Operator::Op_Dodaj;
            break;
    }
    return cin;
}
Operator FindOperator(std::string text, int *index){
    switch(text[*index++]){
        case '+':
            return Operator::Op_Dodaj;
            break;
        case '-':
            return Operator::Op_Odejmij;
            break;
        case '*':
            return Operator::Op_Mnoz;
            break;
        case '/':
            return Operator::Op_Dziel;
            break;
        default:
            throw "In Operator FindOperator(std::string text, int *index) Can't find an operator!";
            return Operator::Op_Dodaj;
            break;
    }
}
std::istream&  operator >> (std::istream &cin, Expression &exp){         
    return cin;
}
void Display(Expression exp){
    if(exp.Arg2.type == Types::t_complex)
        std::cout << exp.Arg1 << exp.Op << exp.Arg2.comp << " = "<< std::endl;
    else
        std::cout << exp.Arg1 << exp.Op << std::noshowpos << exp.Arg2.number << " = "<< std::endl;
}
void WriteComplex(Complex &comp){
    std::cin >> comp;
}
Complex CalculateExpression(Expression exp){
    Complex comp;
    switch(exp.Op){
        case Operator::Op_Dodaj:
            comp = exp.Arg1 + exp.Arg2.comp;
            break;
        case Operator::Op_Odejmij:
            comp = exp.Arg1 - exp.Arg2.comp;
            break;
        case  Operator::Op_Mnoz:
            if(exp.Arg2.type == Types::t_complex)
                comp = exp.Arg1 * exp.Arg2.comp;
            else
                comp = exp.Arg1 * exp.Arg2.number;
            break;
        case Operator::Op_Dziel:
            if(exp.Arg2.type == Types::t_complex)
                comp = exp.Arg1 / exp.Arg2.comp;
            else{
                try{

                }
                catch(std::domain_error &e){
                    comp = exp.Arg1 / exp.Arg2.number;
                    std::cerr << "Nie mozna dzielic przez 0" << std::endl;
                    throw;
                }   
            }   
            break;
        default:
            throw "In Complex CalculateExpression(Expression exp) Can't find operator!";
            break;
    }
    return comp;
}
Expression MakeEmptyExpression(){
  Expression result;
  result.Arg1 = MakeEmptyComplex();
  result.Arg2.comp = MakeEmptyComplex();
  result.Op = Operator::Op_Dodaj;
  return result;
}