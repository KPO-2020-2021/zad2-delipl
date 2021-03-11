#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
std::ostream&  operator << (std::ostream& cout,  Operator op){
    switch(op){
        case Operator::Op_Dodaj:    return cout << " + "; 
        case Operator::Op_Odejmij:  return cout << " - "; 
        case Operator::Op_Mnoz:     return cout << " * "; 
        case Operator::Op_Dziel:    return cout << " / "; 
        default: return cout << "ERROR";
    }
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
            std::cerr << "Nie znaleziono operatora" << std::endl;
            return Operator::Op_Dodaj;
            break;
    }
}
double FindDoubleFromString(std::string text, int *index){
    int start = 0;
    int end = 0;
    int i = 0;
    for(i = *index; i < (int)text.length(); i++){
        if(i == (int)text.length() -1){
            std::cerr << "Nie znaleziono liczby double" << std::endl;
            return 0.0;
        }
        else if(!start && (text[i] == '(' || text[i] == '+' || text[i] == '-')){
            start = i;
            if(text[i] == '(' ) start++;
            i++;
        } 
        else if(!end && (text[i] == 'i' || text[i] == '+' || text[i] == '-')){
            end = i;
            break;
        }
    }
    std::string rawNumber;
    for(i = start; i < end; i++)
        rawNumber += text[i];
    *index = i;
    std::cout << "RAW: " << rawNumber << std::endl;
    return std::stod(rawNumber);
}

std::istream&  operator >> (std::istream &cin, Expression &exp){
    std::string input;
    cin >> input;
    if(input.compare(0,1,"(") || input.compare(input.length()-1,1,")") ) return cin;
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
