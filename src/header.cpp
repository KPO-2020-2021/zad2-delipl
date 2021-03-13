#include <string>
#include <iostream>
double FindDoubleFromString(std::string text, int *index){
    int start = 0;
    int end = 0;
    int i = 0;
    for(i = *index; i < (int)text.length(); i++){
        if(i == (int)text.length() -1){
            throw std::invalid_argument("In double FindDoubleFromString(std::string text, int *index) Can't find a double number!");
            return 0;
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
    if(rawNumber.length() < 1){
        throw std::invalid_argument("In double FindDoubleFromString(std::string text, int *index) Can't find a double number!");
        return 0;
    }
    return std::stod(rawNumber);
}