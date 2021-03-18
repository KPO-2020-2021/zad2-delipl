#include "LZespolona.hh"
#include <cmath>
Complex::Complex(): re{0}, im{0}    {}
Complex::Complex(double x, double y): re{x}, im{y}  {}
Complex::Complex(Complex const &comp): re{comp.Re()}, im{comp.Im()}    {}
Complex Complex::operator+(Complex const comp){
    return Complex(re + comp.Re(), im + comp.Im());
}
Complex Complex::operator-(Complex const comp){
    return Complex(re - comp.Re(), im - comp.Im());
}
Complex Complex::operator-(){
    return Complex(-re , -im);
}
Complex Complex::operator*(double const x){
    return Complex(x * re, x * im);
}
Complex Complex::operator*(Complex const comp){
    return  Complex(re*comp.Re() - im*comp.Im(), 
                    re*comp.Im() + im*comp.Re());
}
Complex Complex::operator/(double const x){
    if(x == 0) throw std::domain_error("Can't divide Complex by 0");
    return Complex(re/x, im/x);
}
Complex Complex::operator/(Complex const &comp){
    double mod = pow(Module(comp), 2);
    if(mod == 0) throw std::domain_error("Can't divide Complex by 0");
    return Complex( ( (*this) * Conjugate(comp) )/ mod );
}
// bool    Complex::operator==(const Complex& comp){
//     return re == comp.Re() && im == comp.Im()? true: false;
// }
// bool    Complex::operator!=(const Complex& comp){
//     return re != comp.Re() || im != comp.Im()? false: true;
// }
Complex Complex::Conjugate(const Complex& comp){
    return Complex(comp.Re(), -comp.Im());
}
double Complex::Module(const Complex& comp){
    return sqrt(pow(comp.Re(), 2) + pow(comp.Im(), 2));
}
bool    operator==(const Complex& comp1,const Complex& comp2){
    return comp1.Re() == comp2.Re() && comp1.Im() == comp2.Im()? true: false;
}
bool    operator!=(const Complex& comp1, const Complex& comp2){
    return comp1.Re() != comp2.Re() || comp1.Im() != comp2.Im()? false: true;
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
				else
					;
			}
			else
				cout << "-";
		}
		else{
			if (comp.Re())
				cout << std::showpos;
			else
				;
			cout << comp.Im() << std::noshowpos;
		}
		cout << "i";
	}
	cout << ")";
	return cout;
}
std::istream& operator>>(std::istream& cin, Complex& z){
	std::string temp; char a, b = 'f';
	cin >> std::ws >> a;
	if(a != '(')
		throw std::logic_error("Blednie podana liczba zespolona");
	cin >> std::ws >> a;
	if (a == 'i'){
		z.re = 0; z.im = 1;

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
			z.re = 0; z.im = (b == '+' ? 1 : -1);
			cin >> std::ws >> a;
			if (a != ')')
				throw std::logic_error("Blednie podana liczba zespolona");
			return cin;
		}
	}
	cin.putback(a);
	cin >> z.re;
	if(cin.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
	if (b == '-')
		z.re *= -1;
	b = 'f';
	cin >> std::ws >> a;
	if (a == ')')
		return cin;
	else if (a == 'i'){
		z.im = z.re;  z.re = 0;
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
			z.im = (b == '+' ? 1 : -1);
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

    cin >> z.im;
	if (cin.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
	if (b == '-')
		z.im *= -1;

	cin >> std::ws >> a;
	if (a != 'i')
		throw std::logic_error("Blednie podana liczba zespolona");


	cin >> std::ws >> a;
	if (a != ')')
		throw std::logic_error("Blednie podana liczba zespolona");

	return cin;

}