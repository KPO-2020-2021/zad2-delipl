#include "WyrazenieZesp.hh"
std::ostream&  operator << (std::ostream& cout,  Operator op){
    switch(op){
        case Operator::Op_Dodaj:    return cout << " + "; 
        case Operator::Op_Odejmij:  return cout << " - "; 
        case Operator::Op_Mnoz:     return cout << " * "; 
        case Operator::Op_Dziel:    return cout << " / "; 
        default: 
            std::cerr << "Can't find an operator!" << std::endl;
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
            std::cerr << "Can't find an operator!" << std::endl;
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
            std::cerr << "Can't find an operator!" << std::endl;
            return Operator::Op_Dodaj;
            break;
    }
}
std::istream&  operator >> (std::istream &cin, Expression &exp){
    std::string input;
    cin >> input;
    if(input.compare(0,1,"(") || input.compare(input.length()-1,1,")") ){
        std::cerr << "Wrong Expression input!" << std::endl;
        exp = MakeEmptyExpression();
        return cin;
    }
    std::string rawNumber;
    int i = 0;
    exp.Arg1.re = FindDoubleFromString(input, &i);
    exp.Arg1.im = FindDoubleFromString(input, &i);
    i += 2;
    exp.Op = FindOperator(input, &i);
    i++;
    exp.Arg2.re = FindDoubleFromString(input, &i);
    exp.Arg2.im = FindDoubleFromString(input, &i);
    return cin;
}
void Display(Expression WyrZ){
    std::cout << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2 << " = "<< std::endl;
}
void WriteComplex(Complex &comp){
    std::cin >> comp;
}
Complex CalculateExpression(Expression exp){
    Complex comp;
    switch(exp.Op){
        case Operator::Op_Dodaj:
            comp = exp.Arg1 + exp.Arg2;
            break;
        case Operator::Op_Odejmij:
            comp = exp.Arg1 - exp.Arg2;
            break;
        case  Operator::Op_Mnoz:
            comp = exp.Arg1 * exp.Arg2;
            break;
        case Operator::Op_Dziel:
            comp = exp.Arg1 / exp.Arg2;
            break;
        default:
            std::cerr << "Can't find operator!" << std::endl;
            break;
    }
    return comp;
}
Expression MakeEmptyExpression(){
  Expression result;
  result.Arg1 = MakeEmptyComplex();
  result.Arg2 = MakeEmptyComplex();
  result.Op = Operator::Op_Dodaj;
  return result;
}