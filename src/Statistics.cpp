#include "Statistics.h"

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
Statistics::Statistics(){
    quantity = 0;
    correctEvents = 0;
}
unsigned int Statistics::operator++(int){
    quantity++;
    correctEvents++;
    return quantity;
}
unsigned int Statistics::operator--(int){
    quantity++;
    return quantity;
}
double Statistics::Calculate() const{
    double x = (double)correctEvents/(double)quantity *100;
    return x;
}
std::ostream& operator<<(std::ostream& cout, const Statistics& stats) {
    cout << "Ilosc dobrych odpowiedzi: " << stats.CountCorrect() << std::endl;
	cout << "Ilosc blednych odpowiedzi: " << stats.Count() - stats.CountCorrect() << std::endl;
	cout << "Wynik procentowy poprawnych odpowiedzi: " << stats.Calculate() << "%" << std::endl;

	return cout;    
}