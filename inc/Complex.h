/**
 * @brief   Library to use Complex numbers
 * @author  Jakub Delicat
 * @version 1.0v
 * @date    28.03.2021r.
 */

#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <cmath>
#include <iostream>

/**
 * @brief Minimal diffrence to compare and round two double numbers.
 * For example 0.00003 = 0 or 0.00006 = 0.0001 for MIN_DIFF = 0.0001. 
 * For 1.00056 == 1.0006 it gives true.
 */
#define MIN_DIFF 0.0001

/**
 * @brief Class with Complex numbers. Allows to use many mathematical operations.
 */
class Complex {

    /**
     * @brief Real number.
     */
    double re;

    /**
     * @brief Imaginary number.
     */
    double im;

public:
    /**
     * @brief Construct a new Complex object and set real and imaginary numbers to 0.
    */
    Complex();

    /**
     * @brief Construct a new Complex object.
     * @param x set real number.
     * @param y set imaginary number.
     */
    Complex(double x, double y);

    /**
     * @brief Construct a new Complex object.
     * @param Complex Copy variables of real and imaginary numbers to new object.
     */
    Complex(const Complex&);

    /**
     * @brief Access to read real number.
     * @return @a re.
     */
    double Re() const { return re; }

    /**
     * @brief Access to read imaginary number.
     * @return @a re.
     */
    double Im() const { return im; }

    /**
     * @brief Addition two complex numbers.
     * @return Complex result of addition.
     */
    Complex operator+(const Complex&) const;

     /**
     * @brief Addition two complex numbers.
     * @return Changed Complex result of addition.
     */
    Complex operator+=(const Complex&);

    /**
     * @brief Subtraction two complex numbers.
     * @return Complex result of subtraction.
     */
    Complex operator-(const Complex&) const;

     /**
     * @brief Subtraction two complex numbers.
     * @return Changed Complex result of subtraction.
     */
    Complex operator-=(const Complex&);

    /**
     * @brief Create the opposite number.
     * @return Complex result of the opposite number.
     */
    Complex operator-();

    /**
     * @brief Multiplicate Complex and double numbers.
     * @return Complex result of multiplication.
     */
    Complex operator*(const double&) const;

    /**
     * @brief Multiplicate Complex and double numbers.
     * @return Changed Complex result of multiplication.
     */
    Complex operator*=(const double&);

    /**
     * @brief Multiplicate two Complex numbers.
     * @return Complex result of multiplication.
     */
    Complex operator*(const Complex&) const;

    /**
     * @brief Multiplicate two Complex numbers.
     * @return Changed Complex result of multiplication.
     */
    Complex operator*=(const Complex&);

    /**
     * @brief Divide Complex and double numbers.
     * @return Complex result of division.
     */
    Complex operator/(const double&) const;

    /**
     * @brief Divide Complex and double numbers.
     * @return Changed Complex result of division.
     */
    Complex operator/=(const double&);

    /**
     * @brief Divide two Complex numbers.
     * @return Complex result of division.
     */
    Complex operator/(const Complex&) const;

    /**
     * @brief Divide two Complex numbers.
     * @return Changed Complex result of division.
     */
    Complex operator/=(const Complex&);

    /**
     * @brief Conjugate Complex number.
     * @param Compex Complex number to conjugate.
     * @return Complex result of Conjugation.
     */
    Complex Conjugate(const Complex&) const;

     /**
     * @brief Modulate Complex number.
     * @param Compex Complex number to module.
     * @return double result of modulation.
     */
    double Module() const;

    /**
     * @brief Argumnent of Complex number
     * @return double argument
     */
    double Arg() const;

    /**
     * @brief Compare two Complex numbers.
     * @return  True when diffrence is less than MIN_DIFF.
                False when diffrence is greater and equal than MIN_DIFF.
     */
    bool operator==(const Complex&) const;

    /**
     * @brief Compare two Complex numbers.
     * @return  False when diffrence is less than MIN_DIFF.
                True when diffrence is greater and equal than MIN_DIFF.
     */
    bool operator!=(const Complex&) const;

    /**
     * @brief Check if Complex is 0.
     * @return  True when Complex is 0.
                False when Complex is not 0.
     */
    bool operator!() const;

    /**
     * @brief Read Complex.
     * @return std::istream& input stream.
     */
    friend std::istream& operator>>(std::istream&, Complex&);
};

/**
 * @brief Print Complex.
 * @return std::ostream& output stream.
 */
std::ostream& operator<<(std::ostream&, const Complex);
#endif