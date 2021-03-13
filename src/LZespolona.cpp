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
  comp.re = FindDoubleFromString(input, &i);
  comp.im = FindDoubleFromString(input, &i);
  return cin;
}
Complex MakeEmptyComplex(){
  Complex comp;
  comp.im = 0;
  comp.re = 0;
  return comp;
}