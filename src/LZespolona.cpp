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
    result.im = 0.0 - comp1.im;
    result.re = 0.0 - comp1.re;
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
std::ostream&  operator << (std::ostream& cout, const Complex  comp){
    cout << "(" << std::noshowpos << comp.re << std::showpos << comp.im << "i)";
    return cout;
}
std::istream&  operator >> (std::istream& cin,  Complex  &comp){
    char brac, letter;
    double x;
    cin >> brac;
    if(cin.fail()){
        throw std::logic_error("Wrong input 1");
    }
    if(brac != '('){
        cin.setstate(std::ios::failbit);
        throw std::logic_error("Wrong input 2");
    }
    cin >> comp.re;
    if(cin.fail()){
        // cin.clear();
        // cin >> letter;
        // if(cin.fail())  throw std::logic_error("Wrong input 4");
        // if(letter == 'i'){
        //     comp.re = 0;
        //     comp.im = 1;
        // } 
        // else if(letter == '-'){
        //     cin >> letter;
        //     if(letter == 'i'){
        //         comp.re = 0;
        //         comp.im = -1;
        //     } 
        // }
        // else
            throw std::logic_error("Wrong input 4");
    }
    if(cin.fail()){
        throw std::logic_error("Wrong input 3");
    }
    cin >> comp.im;
    cin >> letter;
    if(cin.fail()){
        throw std::logic_error("Wrong input 4");
    }
    if(letter != 'i'){
        cin.setstate(std::ios::failbit);
        throw std::logic_error("Wrong input 5");
    }
    cin >> brac;
    if(cin.fail()){
        throw std::logic_error("Wrong input 4");
    }
    if(brac != ')'){
        cin.setstate(std::ios::failbit);
        throw std::logic_error("Wrong input 6");
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
    return MakeEmptyComplex();
}