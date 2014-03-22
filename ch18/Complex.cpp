#include <iostream>

using namespace std;

class Complex {
	double re, im;
public:
	Complex(double r, double i) : re {r}, im {i} {}
	Complex operator+(Complex);
	Complex operator*(Complex);
	friend ostream &operator<<(ostream &os, Complex c);
};

ostream &operator<<(ostream &os, Complex c) {
	os << c.re;
	os << ((c.im >= 0) ? "+" : "-");
	os << c.im << "*i";
	return os;
}

Complex Complex::operator+(Complex c) {
	return Complex{this->re+c.re, this->im+c.im};
}

Complex Complex::operator*(Complex c) {
	double r = this->re*c.re - this->im*c.im;
	double i = this->im*c.re + this->re*c.im;
	// This is OK, probably because this is considered
	// as initializer
	return {r, i};
}

void f() {
	Complex a = {1, 3.1};
	cout << a << endl;
	Complex b {1.2, 2};
	cout << b << endl;
	Complex c {b};
	cout << c << endl;

	cout << b+c << endl;
	cout << a*b + Complex{1, 2} << endl;
}

int main() {
	Complex c0 {0, 0};
	f();
	return 0;
}
