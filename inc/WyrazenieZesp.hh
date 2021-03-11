#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"
#include "string"


/**
 * @brief 
 * Math operators to choose math calculation 
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/**
 * @brief 
 * Expression of 2 Complex numbers and math operator
 */
struct Expression {
  Complex   Arg1;   
  Operator     Op;     
  Complex   Arg2;   
};


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
 * Output overload operator for enum: Operator
 * @param cout Standard output
 * @param op 
 * @return standard output of Operator
 */
std::istream&  operator << (std::istream& cout,  Operator &op);
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
 * Calculate Expression
 * @param exp - expression to solve
 * @return complex number which is the result of expression
 */
Complex Calculate(Expression  exp);
/**
 * @brief Looking for math operator
 * 
 * @param text one char with operator
 * @param op Operator to save
 * @return true when found Operator and false when didn't
 */
bool FindOperator(std::string text, Operator *op);
/**
 * @brief Looking for double number from string
 * 
 * @param text input text to search
 * @param index first index to start search
 * @return found double number or 0.0 if didn't find
 */
double FindDoubleFromString(std::string text, int index);
#endif
