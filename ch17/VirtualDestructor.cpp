#include <iostream>

using namespace std;

class X {
public:
	virtual int X_do_nothing() = 0;
	virtual ~X() {
		cout << "I am in ~X()" << endl;
	}
};

class derivedX : public X {
public:
	int X_do_nothing() {
		cout << "I am in X_do_nothing()" << endl;
		return 0;
	}
	~derivedX() { cout << "I am in ~derivedX()" << endl; }
};

int main() {
	derivedX *dxptr = new derivedX();
	X *xptr = dxptr;
	xptr->X_do_nothing();
	delete xptr;
	cout << "I am gonna return!" << endl;
	return 0;
}
