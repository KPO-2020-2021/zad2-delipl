#ifndef STATISTICS_HPP
#define STATISTICS_HPP
#include <iostream>
/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki 
 */
class Statistics{
    unsigned int correctAnswers;
    unsigned int quantity;

    public:
    Statistics();
    unsigned int CountCorrect() const { return correctAnswers;}
    unsigned int Count() const { return quantity;}
    double Calculate() const;
    
    unsigned int operator++(int);
    unsigned int operator--(int);

};
std::ostream& operator<<(std::ostream&, const Statistics&);
#endif
