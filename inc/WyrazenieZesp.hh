#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"
#include "string"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct Expression {
  Complex   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  Complex   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

std::ostream&  operator << (std::ostream& os,  Expression WyrZ);
std::istream&  operator << (std::istream& os,  Operator &op);
std::istream&  operator >> (std::istream &cin, Expression &exp);

void Display(Expression  WyrZ);
Complex Calculate(Expression  WyrZ);
bool FindOperator(std::string text, Operator *op);
double FindDoubleFromString(std::string text, int index);
#endif
