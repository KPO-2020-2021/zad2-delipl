#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>
#include "header.hh"
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  Complex {
  /**
   * @brief 
   * 
   */
  double   re;    ///< Pole repezentuje czesc rzeczywista. 
  double   im;    ///< Pole repezentuje czesc urojona. 
};
Complex  operator + (Complex  comp1,  Complex  comp2);
Complex  operator - (Complex  comp1,  Complex  comp2); 
Complex  operator - (Complex  comp1);
Complex  operator * (Complex  comp,  double number);
Complex  operator * (Complex  comp1,  Complex  comp2);
Complex  operator / (Complex  comp1,  double  number);
Complex  operator / (Complex  comp1,  Complex  comp2);
bool  operator == (Complex  comp1,  Complex  comp2);
bool  operator != (Complex  comp1,  Complex  comp2);

std::ostream& operator << (std::ostream& cout,  Complex  comp);

std::istream& operator >> (std::istream& cin,  Complex& comp);

Complex MakeEmptyComplex();
Complex StringToComplex(std::string input, int *i);

#endif