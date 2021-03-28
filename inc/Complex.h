#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <cmath>
#include <iostream>
#define MIN_DIFF 0.0001
class Complex {
    double re;
    double im;

public:
    Complex();
    Complex(double x, double y);
    Complex(const Complex&);
    double Re() const { return re; }
    double Im() const { return im; }
    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator-();
    Complex operator*(const double&) const;
    Complex operator*(const Complex&) const;
    Complex operator/(const double&) const;
    Complex operator/(const Complex&) const;
    Complex Conjugate(const Complex&) const;
    double Module() const;
    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;
    bool operator!() const;
    friend std::istream& operator>>(std::istream&, Complex&);
};
std::ostream& operator<<(std::ostream&, const Complex);
#endif