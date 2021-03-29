#include "Complex.h"
#include <cmath>
Complex::Complex(): re{0}, im{0}   {}
Complex::Complex(double x, double y): re{x}, im{y}{ 
    re = (int)(re * pow(MIN_DIFF, -1));
    re = x* pow(MIN_DIFF, -1);
    re = round(re);
    re = re * MIN_DIFF;

    im = (int)(im * pow(MIN_DIFF, -1));
    im = y* pow(MIN_DIFF, -1);
    im = round(im);
    im = im * MIN_DIFF;
}
Complex::Complex(Complex const &comp): re{comp.Re()}, im{comp.Im()}    {}
Complex Complex::operator+(const Complex &comp) const{
    return Complex(this->re + comp.Re(), this->im + comp.Im());
}
Complex Complex::operator+=(const Complex &comp){
    *this = *this + comp;
    return *this;
}
Complex Complex::operator-(const Complex &comp) const{
    return Complex(this->re - comp.Re(), this->im - comp.Im());
}
Complex Complex::operator-=(const Complex &comp){
    *this = *this - comp;
    return *this;
}
Complex Complex::operator-(){
    return Complex(-this->re , -this->im);
}
Complex Complex::operator*(const double &x) const{
    return Complex(x * this->re, x * this->im);
}
Complex Complex::operator*=(const double &x){
    *this = (*this) * x;
    return *this;
}
Complex Complex::operator*(const Complex &comp) const{  
    double  x = this->re*comp.Re() - this->im*comp.Im();
    double  y = this->re*comp.Im() + this->im*comp.Re();
    return  Complex(x,y);      
}
Complex Complex::operator*=(const Complex &comp){
    *this = *this * comp;
    return *this;
}
Complex Complex::operator/(const double &x) const{
    if(x == 0) throw std::domain_error("Can't divide Complex by 0");
    return Complex(this->re/x, this->im/x);
}
Complex Complex::operator/=(const double &x){
    *this = (*this)/x;
    return *this;
}
Complex Complex::operator/(const Complex &comp) const{
    double mod = pow(comp.Module(), 2);
    if(mod == 0) throw std::domain_error("Can't divide Complex by 0");
    return Complex( ( (*this) * Conjugate(comp) )/ mod );
}
Complex Complex::operator/=(const Complex &comp){
    *this = (*this)/comp;
    return *this;
}
bool Complex::operator==(const Complex &comp) const{
    return fabs(this->re - comp.Re()) < MIN_DIFF && fabs(this->im - comp.Im()) < MIN_DIFF;
}
bool Complex::operator!=(const Complex &comp) const{
    return fabs(this->re - comp.Re()) > MIN_DIFF || fabs(this->im - comp.Im()) > MIN_DIFF;
}
bool Complex::operator!() const{
    return (*this) == Complex(0, 0);
}
Complex Complex::Conjugate(const Complex &comp) const{
    return Complex(comp.Re(), -comp.Im());
}
double Complex::Module() const{
    return sqrt(pow(this->re, 2) + pow(this->im, 2));
}
double Complex::Arg() const{
    return this->re > 0? atan2(this->re, this->im): atan2(this->re, this->im) + M_PI;
}
std::ostream& operator<<(std::ostream& cout, const Complex comp){
	cout << "(";
	if (!comp.Re() && !comp.Im())
		cout << 0;
	else if (!comp.Im())
		cout << comp.Re();
	else{
		if (comp.Re())
			cout << comp.Re();
		if (fabs(comp.Im()) == 1){
			if (comp.Im() > 0){
				if (comp.Re())
					cout << "+";
			}
			else
				cout << "-";
		}
		else{
			if (comp.Re())
				cout << std::showpos;
			cout << comp.Im() << std::noshowpos;
		}
		cout << "i";
	}
	cout << ")";
	return cout;
}
std::istream& operator>>(std::istream& cin, Complex& comp){
    double x = 0.0, y = 0.0, im = 0.0, re = 0.0;
    char c;
    enum  State {openBracket, number, checkChar, closeBracket};
    State state = State::openBracket;
    bool end = false;
    while(!end){
        switch(state){
            case State::openBracket:
                cin >> std::ws >> c;
                if(cin.fail())
                    throw std::logic_error("Blednie podana liczba zespolona");
                if(c != '(' || cin.peek() == ')')
                    throw std::logic_error("Blednie podana liczba zespolona");
                state = State::checkChar;
                break;
            case State::checkChar:
                cin >> std::ws >> c;
                if(cin.fail())
                    throw std::logic_error("Blednie podana liczba zespolona");
                if(c == '-') {
                    x = -1;
                    state = State::number;
                }
                else if(c == '+'){
                    x = 1;
                    state = State::number;
                }
                else if(isdigit(c)){
                    x = 1;
                    cin.putback(c);
                    state = State::number;
                }
                else if(c == 'i'){
                    im = 1;
                    state = State::closeBracket;
                }
                else if(c == ')'){
                    cin.putback(c);
                    state = State::closeBracket;
                }
                else {
                    throw std::logic_error("Blednie podana liczba zespolona");
                } 
                break;
            case State::number:
                if(cin.peek() == 'i'){
                    im = x;
                    cin.get();
                    state = State::closeBracket;
                    break;
                }
                cin >> std::ws >> y;
                if(cin.fail())
                    throw std::logic_error("Blednie podana liczba zespolona");
                y *= x;
                if(cin.peek() == 'i'){
                    im += y;
                    cin.get();
                    state = State::checkChar;
                }
                else{
                    re += y;
                    state = State::checkChar;
                }
                break;
            case State::closeBracket: 
                cin >> std::ws >> c;
                if(cin.fail())
                    throw std::logic_error("Blednie podana liczba zespolona");
                if(c != ')')
                    throw std::logic_error("Blednie podana liczba zespolona");
                end = true;
                break;
        }
    }
    comp = Complex(re, im);
	return cin;
}

