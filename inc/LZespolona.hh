#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>
#include "header.hh"

class  Complex {
    double   re;     
    double   im;    

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
    bool operator == (const Complex&);
    bool operator != (const Complex&);

    friend std::istream& operator >> (std::istream&,  Complex&);
};
std::ostream& operator << (std::ostream&,  Complex const);
#endif