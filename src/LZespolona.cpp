#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
Complex  operator + (Complex  Skl1,  Complex  Skl2){
  Complex  result;

  result.re = Skl1.re + Skl2.re;
  result.im = Skl1.im + Skl2.im;
  return result;
}
Complex  operator - (Complex  Skl1,  Complex  Skl2){
  Complex  result;

  result.re = Skl1.re - Skl2.re;
  result.im = Skl1.im - Skl2.im;
  return result;
}
/*cout << Zesp;*/
std::ostream&  operator << (std::ostream& os,  Complex  Skl){
  os << "(" << std::noshowpos << Skl.re << std::showpos << Skl.im << "i)";
  return os;
}
Complex MakeEmptyComplex(){
  Complex com;
  com.im = 0;
  com.re = 0;
  return com;
}