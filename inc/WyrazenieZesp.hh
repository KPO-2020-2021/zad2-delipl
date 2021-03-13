#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include "LZespolona.hh"
#include "header.hh"
#include "string"


/**
 * @brief 
 * Math operators to choose math calculation 
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };
/**
 * @brief 
 * Union for the second argument in expresion to recognize if it is a double or complex number
 */
struct ComplexOrDouble{
  typedef enum types{
    t_double,
    t_complex
  } type;
  union{
    Complex comp;
    double number;
  };
};
/**
 * @brief 
 * Expression of 2 Complex numbers and math operator
 */
struct Expression {
  Complex           Arg1;   
  Operator          Op;     
  ComplexOrDouble   Arg2;   
};
/**
 * @brief 
 * Output overload operator for enum: Operator
 * @param cout Standard output
 * @param op operator
 * @return standard output of Operator
 */
std::ostream&  operator << (std::ostream& cout,  Operator op);
/**
 * @brief 
 * Input overload operator for enum: Operator
 * @param cout Standard input
 * @param op operator
 * @return standard intput of Operator
 */
std::istream&  operator >> (std::istream &cin, Operator &op);
/**
 * @brief Looking for math operator
 * 
 * @param text one char with operator
 * @param op Operator to save
 * @return true when found Operator and false when didn't
 */
Operator FindOperator(std::string text, int *index);
/**
 * @brief 
 * Output overload operator for struct: Expression
 * @param cout Standard output
 * @param exp  Complex Expression to print 
 * @return standard output of Expression
 */
std::ostream&  operator << (std::ostream& cout,  Expression exp);
/**
 * @brief 
 * Input overload operator for struct Expression 
 * @param cin 
 * @param exp 
 * @return std::istream& 
 */
std::istream&  operator >> (std::istream &cin, Expression &exp);
/**
 * @brief 
 * Display function for struct: Expression
 * @param exp Expression to print
 * @see std::ostream&  operator << (std::ostream& cout,  Expression exp)
 */
void Display(Expression  exp);
/**
 * @brief 
 * Allow to write into complex number
 * @param comp Writable complex number
 */
void WriteComplex(Complex &comp);
/**
 * @brief 
 * CalculateExpression Expression
 * @param exp - expression to solve
 * @return complex number which is the result of expression
 */
Complex CalculateExpression(Expression  exp);
/**
 * @brief 
 * Function fills Agr1, op and Arg2 with 0 and add operator
 * @return returns expresion (0+0i)+(0+0i) 
 */
Expression MakeEmptyExpression();
#endif
