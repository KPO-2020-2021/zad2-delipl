#include <string>
#include <iostream>
bool isDigit(char c){
    switch (c){
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
        return true;
        break;
    default:
        return false;
        break;
    }
}
bool isPosSign(char c){
    return c == '+' || c == '-' ? true: false;
}
bool isSign(char c){
    return isPosSign(c) || c == '*' || c == '/' || c == 'i'? true: false;
}
double FindDoubleFromString(std::string text, int *index){
    bool began = false;
    int i = 0;
    std::string rawNumber;
    for(i = *index; i < (int)text.length(); i++){
        if(!began&& (isDigit(text[i]) || isPosSign(text[i]))) {
            began = true;
            rawNumber += text[i];
        }
        else if(isSign(text[i])){
            break;
        }
        else if(began){
            rawNumber += text[i];
        }
    }
    *index = i;
    double result;
    try{
        result = std::stod(rawNumber);
    }
    catch(...){
        throw("In double FindDoubleFromString(std::string text, int *index) Can't find a double number!");
        return 0;
    }
    
    return result;
}