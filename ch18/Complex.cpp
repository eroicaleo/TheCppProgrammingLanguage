#include <iostream>

using namespace std;

class Complex {
	double re, im;
public:
	Complex(double r = 0, double i = 0) : re {r}, im {i} {}
	Complex &operator+=(Complex);
	Complex &operator+=(double);
	Complex operator*(Complex);
	double imag() const { return im; }
	double real() const { return re; }
	void imag(double i) { im = i; }
	void real(double r) { re = r; }
	friend ostream &operator<<(ostream &os, Complex c);
};

Complex& Complex::operator+=(Complex c) {
	re += c.re;
	im += c.im;
	return *this;
}

Complex& Complex::operator+=(double d) {
	re += d;
	return *this;
}

ostream &operator<<(ostream &os, Complex c) {
	os << c.re;
	os << ((c.im >= 0) ? "+" : "-");
	os << c.im << "*i";
	return os;
}

Complex operator+(Complex c1, Complex c2) {
	return c1 += c2;
}

bool operator==(Complex c1, Complex c2) {
	return (c1.imag() == c2.imag()) && (c1.real() == c2.real());
}

// Complex operator+(Complex c1, double d) {
// 	return c1 += d;
// }
// 
// Complex operator+(double d, Complex c1) {
// 	return c1 += d;
// }

Complex Complex::operator*(Complex c) {
	double r = this->re*c.re - this->im*c.im;
	double i = this->im*c.re + this->re*c.im;
	// This is OK, probably because this is considered
	// as initializer
	return {r, i};
}

void f() {
	Complex a = {1, 3.1};
	cout << "a = " <<  a << endl;
	Complex b {1.2, 2};
	cout << "b = " << b << endl;
	Complex c {b};
	cout << "c = " << c << endl;

	cout << "b+c = " << b+c << endl;
	cout << "a*b + (1+2i) = " << a*b + Complex{1, 2} << endl;
	cout << "b+2 = " << b+2 << endl;
	cout << "3+b = " << 3+b << endl;

	Complex d {3};
	cout << "d = " << d << endl;
	Complex e;
	cout << "e = " << e << endl;

	cout << "a == b ? " << (a == b) << endl;
	cout << "3 == d ? " << (3 == d) << endl;
}

int main() {
	Complex c0 {0, 0};
	f();
	return 0;
}
