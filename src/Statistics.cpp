#include "Statistics.hpp"

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
Statistics::Statistics(){
    quantity = 0;
    correctAnswers = 0;
}
unsigned int Statistics::operator++(int){
    quantity++;
    correctAnswers++;
    return quantity;
}
unsigned int Statistics::operator--(int){
    quantity++;
    return quantity;
}
double Statistics::Calculate() const{
    double x = correctAnswers/quantity;
    return x;
}
std::ostream& operator<<(std::ostream& cout, const Statistics& stats) {
    cout << "Ilosc dobrych odpowiedzi: " << stats.CountCorrect() << std::endl;
	cout << "Ilosc blednych odpowiedzi: " << stats.Count() - stats.CountCorrect() << std::endl;
	cout << "Wynik procentowy poprawnych odpowiedzi: " << stats.Calculate() << "%" << std::endl;

	return cout;    
}