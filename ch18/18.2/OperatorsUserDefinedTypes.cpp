#include <iostream>

using namespace std;

class X {
public:
	X& operator+(int) {
		cout << "I am in operator +" << endl;
		return *this;
	}
};

enum Days {sun, mon, tue, wed, thu, fri, sat};

Days &operator++(Days &d) {
	return d = (d == sat) ? sun : static_cast<Days>(d + 1);
}

int main() {
	X x;
	x + 2;
	// This does not compile
	// 2 + x
	Days d {sun};
	for (int i = 0; i < 21; ++i, ++d) {
		cout << d << endl;
	}
}
