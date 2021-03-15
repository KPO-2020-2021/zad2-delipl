#include "LZespolona.hh"
Complex  operator + (Complex  comp1,  Complex  comp2){
    Complex  result;
    result.re = comp1.re + comp2.re;
    result.im = comp1.im + comp2.im;
    return result;
}
Complex  operator - (Complex  comp1,  Complex  comp2){
    Complex  result;
    result.re = comp1.re - comp2.re;
    result.im = comp1.im - comp2.im;
    return result;
}
Complex  operator - (Complex  comp1){
    Complex result;
    result.im = -comp1.im;
    result.re = -comp1.re;
    return result;
}
Complex  operator * (Complex  comp,  double number){
    Complex result;
    result.re = comp.re * number;
    result.im = comp.im* number;
    return result;
}
Complex  operator * (Complex  comp1,  Complex  comp2){
    Complex result;
    result.re = comp1.re*comp2.re - comp1.im*comp2.im;
    result.im = comp1.re*comp2.im - comp1.im*comp2.re;
    return result;
}
Complex  operator / (Complex  comp,  double  number){
    Complex result;
    if(number == 0) throw "In Complex  operator / (Complex  comp,  double  number) You can't divide by 0";
    result.im = comp.im / number;
    result.re = comp.re / number;
    return result;
}
Complex  operator / (Complex  comp1,  Complex  comp2){
    Complex result;
    Complex conjugate2 = comp2;
    conjugate2.im = -conjugate2.im;
    double module = comp2.im*comp2.im + comp2.re*comp2.re;
    if(module == 0) throw "In Complex  operator / (Complex  comp,  double  number) You can't divide by 0";
    result = comp1 * conjugate2;
    result = result / module;
    return result;
}
bool  operator == (Complex  comp1,  Complex  comp2){
    return comp1.re == comp2.re && comp1.im == comp2.im? true: false;
}
bool  operator != (Complex  comp1,  Complex  comp2){
    return comp1.re != comp2.re || comp1.im != comp2.im? false: true;
}
std::ostream&  operator << (std::ostream& cout,  Complex  comp){
    cout << "(" << std::noshowpos << comp.re << std::showpos << comp.im << "i)";
    return cout;
}
std::istream&  operator >> (std::istream& cin,  Complex  &comp){
    std::string input;
    cin >> input;
    int length = (int)input.length();
    int i = 0;
    try{
        comp.re = FindDoubleFromString(input, &i);
    }
    catch(const char* e){
        std::cerr << e << std::endl;
        comp = MakeEmptyComplex();
        return cin;
    }
    if(input[i-1] == 'i'){
        comp.im = comp.re;
        comp.re = 0;
        return cin;
    }
    else if(length > 2){
        if(input[i-2] == 'i' && input[i-1] == ')'){
            comp.im = comp.re;
            comp.re = 0;
            return cin;
        }
        else if(input[i-1] == ')'){
            comp.im = 0;
            return cin;
        }
        else if(i == length){
            comp.im = 0;
            return cin;
        }
    }
    else if(i == length){
        comp.im = 0;
        return cin;
    }
    try{
        comp.im = FindDoubleFromString(input, &i);
    }
    catch(const char* e){
        if(input[i-1] == 'i'){
            if(input[i-2] == '-')   comp.im = -1;
            else                    comp.im = 1;
            return cin;
        }
        else{
            std::cerr << e << std::endl;
        }
    }
    return cin;
}
Complex MakeEmptyComplex(){
    Complex comp;
    comp.im = 0;
    comp.re = 0;
    return comp;
}
// Complex StringToComplex(std::string input, int *i){
//     Complex comp;
//     int length = (int)input.length();
//     try{
//         comp.re = FindDoubleFromString(input, i);
        
//     }
//     catch(const char* e){
//         std::cerr << "Koncze na: " << input[*i] << " w indexie " << *i << "\n";
//         if(length > 0){
//             if(length > 1){
//                 if(input[*i-1] == '-' && input[*i] == 'i'){
//                     comp.im = -1;
//                     comp.re = 0;
//                     (*i)++;
//                     return comp;
//                 }
//                 else if(input[*i] == 'i'){
//                     comp.im = 1;
//                     comp.re = 0;
//                     (*i)++;
//                     return comp;
//                 }
//             }
//             else if(input[*i] == 'i'){
//                 comp.im = 1;
//                 comp.re = 0;
//                 (*i)++;
//                 return comp;
//             }
//         }
//         std::cerr << e << std::endl;
//         comp = MakeEmptyComplex();
//         return comp;
//     }
    
//     if(input[*i-1] == 'i'){
//         comp.im = comp.re;
//         comp.re = 0;
//         return comp;
//     }
//     else if(length>2){
//         if(input[*i-2] == 'i' && input[*i-1] == ')'){
//             comp.im = comp.re;
//             comp.re = 0;
//             return comp;
//         }
//         else if(input[*i-1] == ')'){
//             comp.im = 0;
//             return comp;
//         }
//         else if(*i == length){
//             comp.im = 0;
//             return comp;
//         }
//     }
//     else if(*i == length){
//         comp.im = 0;
//         return comp;
//     }
//     try{
//         comp.im = FindDoubleFromString(input, i);
//     }
//     catch(const char* e){
//         if(input[*i-1] == 'i'){
//             if(input[*i-2] == '-')   comp.im = -1;
//             else                    comp.im = 1;
//             return comp;
//         }
//         else{
//             std::cerr << e << std::endl;
//         }
//     }
//     return comp;
// }
Complex StringToComplex(std::string input, int *i){
    Complex comp;
    int length = (int)input.length();
    int start = -1;
    int end = -1;
    int op = -1;
    for(int j = *i; j < length; j++){
        if(start == -1 && input[j]]== '(') start = j;
        else if(start > j + 1 && end == -1 && isPosSign(input[j])) op = j;
        else if(end == -1 && start != -1 input[j]== ')') end = j;
    }
    std::string rawText;
    if(op == -1){
        for(*i; *i < end; (*i)++){
            if(*i == end - 1 && input[*i] == 'i'){
                try{
                    comp.im = std::stod(rawText);
                    comp.re = 0;
                }
                catch(...){
                    throw("In double StrignToComplex(std::string input, int *i) Can't find a double number!");
                    return MakeEmptyComplex();
                }
            }
            else if(*i == end){
                try{
                    comp.im = 0;
                    comp.re = std::stod(rawText);
                }
                catch(...){
                    throw("In double StrignToComplex(std::string input, int *i) Can't find a double number!");
                    return MakeEmptyComplex();
                }
            }
            rawText += input[*i];
        }
    }
}