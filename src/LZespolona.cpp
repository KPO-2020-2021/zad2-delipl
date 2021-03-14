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
    else if((int)input.length()>2){
        if(input[i-2] == 'i' && input[i-1] == ')'){
            comp.im = comp.re;
            comp.re = 0;
            return cin;
        }
    }
    else if(i == (int)input.length()){
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
Complex StringToComplex(std::string input, int *i){
    Complex comp;
    try{
        comp.re = FindDoubleFromString(input, i);
    }
    catch(const char* e){
        std::cerr << e << std::endl;
        comp = MakeEmptyComplex();
        return comp;
    }
    if(input[*i-1] == 'i'){
        comp.im = comp.re;
        comp.re = 0;
        return comp;
    }
    else if((int)input.length()>2){
        if(input[*i-2] == 'i' && input[*i-1] == ')'){
            comp.im = comp.re;
            comp.re = 0;
            return comp;
        }
    }
    else if(*i == (int)input.length()){
        comp.im = 0;
        return comp;
    }
    try{
        comp.im = FindDoubleFromString(input, i);
    }
    catch(const char* e){
        if(input[*i-1] == 'i'){
            if(input[*i-2] == '-')   comp.im = -1;
            else                    comp.im = 1;
            return comp;
        }
        else{
            std::cerr << e << std::endl;
        }
    }
    return comp;
}