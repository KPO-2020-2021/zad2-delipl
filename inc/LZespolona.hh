#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  Complex {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


Complex  operator + (Complex  Skl1,  Complex  Skl2);
Complex  operator - (Complex  Skl1,  Complex  Skl2);
Complex  operator - (Complex  Skl1);
Complex  operator * (Complex  Skl1,  Complex  Skl2);
Complex  operator / (Complex  Skl1,  Complex  Skl2);
Complex  operator / (Complex  Skl1,  double  number);
Complex MakeEmptyComplex();
std::ostream&  operator << (std::ostream& os,  Complex  Skl);
std::ostream&  operator >> (std::ostream& os,  Complex  Skl);


#endif
