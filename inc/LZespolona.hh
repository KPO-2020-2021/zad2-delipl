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
class  Complex {
    double   re;    ///< Pole repezentuje czesc rzeczywista. 
    double   im;    ///< Pole repezentuje czesc urojona. 

    public:
    Complex();
    Complex(double x, double y);
    Complex(const Complex&);
    double Re() const { return re;}
    double Im() const { return im;}
    Complex operator + (Complex const);
    Complex operator - (Complex const); 
    Complex operator - ();
    Complex operator * (double const);
    Complex operator * (Complex const);
    Complex operator / (double const);
    Complex operator / (Complex const);
    Complex Module(Complex const);
    Complex Conjugate(Complex const);
    bool operator == (Complex const);
    bool operator != (Complex const);

    friend std::istream& operator >> (std::istream&,  Complex&);
};
std::ostream& operator << (std::ostream&,  Complex const);
#endif