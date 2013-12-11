#include <iostream>

using namespace std;

class X {
public:
	X();
	X(int);
	X(int, int);
	int x1;
	int x2;
};

class Y {
public:
	explicit Y();
	explicit Y(int);
	explicit Y(int, int);
	int y1;
	int y2;
};

void fx(X X) {
	cout << X.x1 << " " << X.x2 << endl;
	return;
}

void fy(Y Y) {
	cout << Y.y1 << " " << Y.y2 << endl;
	return;
}

int main() {
	fx(1); // Should be OK
	fx((1, 2)); // Should be OK
	// fy(1); // Error
	// fy((1, 2)); // Error
	fy(Y(1)); // OK
	fy(Y(1, 2)); // OK
	fy(Y()); // OK
	return 0;
}

X::X() {}
X::X(int x) : x1(x), x2(x) {}
X::X(int x1, int x2) : x1(x1), x2(x1) {}

inline Y::Y() {}
Y::Y(int y) : y1(y), y2(y) {}
Y::Y(int y1, int y2) : y1(y1), y2(y2) {}
