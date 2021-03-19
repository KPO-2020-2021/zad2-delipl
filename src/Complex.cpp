#include "Complex.hpp"
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
    return Complex(re + comp.Re(), im + comp.Im());
}
Complex Complex::operator-(const Complex &comp) const{
    return Complex(re - comp.Re(), im - comp.Im());
}
Complex Complex::operator-(){
    return Complex(-re , -im);
}
Complex Complex::operator*(double const &x) const{
    return Complex(x * re, x * im);
}
Complex Complex::operator*(const Complex &comp) const{
    
    double  x = re*comp.Re() - im*comp.Im();
    double  y = re*comp.Im() + im*comp.Re();
    return  Complex(x,y);      
}
Complex Complex::operator/(const double &x) const{
    if(x == 0) throw std::domain_error("Can't divide Complex by 0");
    return Complex(re/x, im/x);
}
Complex Complex::operator/(const Complex &comp) const{
    double mod = pow(Module(comp), 2);
    if(mod == 0) throw std::domain_error("Can't divide Complex by 0");
    return Complex( ( (*this) * Conjugate(comp) )/ mod );
}
bool Complex::operator==(const Complex &comp) const{
    return fabs(re - comp.Re()) < MIN_DIFF && fabs(im - comp.Im()) < MIN_DIFF;
    // return re == comp.Re() && im == comp.Im();
}
bool Complex::operator!=(const Complex &comp) const{
    return fabs(re - comp.Re()) > MIN_DIFF || fabs(im - comp.Im()) > MIN_DIFF;
    // return re != comp.Re() || im != comp.Im();
}
bool Complex::operator!() const{
    return (*this) == Complex(0, 0);
}
Complex Complex::Conjugate(const Complex &comp) const{
    return Complex(comp.Re(), -comp.Im());
}
double Complex::Module(const Complex &comp) const{
    return sqrt(pow(comp.Re(), 2) + pow(comp.Im(), 2));
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
	std::string temp; char a, b = 'f';
	cin >> std::ws >> a;
	if(a != '(')
		throw std::logic_error("Blednie podana liczba zespolona");
	cin >> std::ws >> a;
	if (a == 'i'){  //(i)
		comp.re = 0; comp.im = 1;

		cin >> std::ws >> a;
		if (a != ')')
			throw std::logic_error("Blednie podana liczba zespolona");

		return cin;
	}
	else if (a == '+' || a == '-'){
		b = a;
		cin >> std::ws >> a;
		if (a == 'i') //(+i) (-i)
		{
			comp.re = 0; comp.im = (b == '+' ? 1 : -1);
			cin >> std::ws >> a;
			if (a != ')')
				throw std::logic_error("Blednie podana liczba zespolona");
			return cin;
		}
	}
	cin.putback(a);
	cin >> comp.re;
	if(cin.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
    if(comp.re < MIN_DIFF){
        comp.re = comp.re < MIN_DIFF/2? 0.0: MIN_DIFF;
    }
	if (b == '-')
		comp.re *= -1;
    
    
	b = 'f';
	cin >> std::ws >> a;
	if (a == ')')
		return cin;
	else if (a == 'i'){
		comp.im = comp.re;  comp.re = 0;
		cin >> std::ws >> a;
		if (a != ')')
			throw std::logic_error("Blednie podana liczba zespolona");

		return cin;
	}
	else if (a == '+' || a == '-'){
		b = a;
		cin >> std::ws >> a;
		if (a == 'i')
		{
			comp.im = (b == '+' ? 1 : -1);
			cin >> std::ws >> a;
			if (a != ')')
				throw std::logic_error("Blednie podana liczba zespolona");

			return cin;
		}
		cin.putback(a);
	}
	else{
		throw std::logic_error("Blednie podana liczba zespolona");
	}

    cin >> comp.im;
	if (cin.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
    if(comp.im < MIN_DIFF){
        comp.im = comp.im < MIN_DIFF/2? 0.0: MIN_DIFF;
    }
	if (b == '-')
		comp.im *= -1;

	cin >> std::ws >> a;
	if (a != 'i')
		throw std::logic_error("Blednie podana liczba zespolona");


	cin >> std::ws >> a;
	if (a != ')')
		throw std::logic_error("Blednie podana liczba zespolona");

	return cin;

}