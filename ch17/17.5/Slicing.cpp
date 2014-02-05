#include <iostream>

using namespace std;

struct B {
	int b {66};
	B() {}
	B(const B& b) {
		cout << "I am in B()" << endl;
	}
};

struct D : B {
	int d {88};
	D() {}
	D(const D& d) {
		cout << "I am in D()" << endl;
	}
};

void naive(B *b) {
	B bb = *b;
};

int main() {
	D d;
	naive(&d);
	B b = d;
	cout << b.b << " " << d.d << endl;
}
