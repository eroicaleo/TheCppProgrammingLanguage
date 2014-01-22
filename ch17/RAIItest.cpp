#include <iostream>
#include <stdexcept>

using namespace std;

struct X {
	X(int s);
	~X();
private:
	int *def;
	int sz;
	int *elem;
};

X::X(int s) {
	def = new int[10];
	if (s < 0) { 
		throw invalid_argument("size less than 0");
	}
	sz = s;
	elem = new int[sz];
}

X::~X() {
	clog << "I am in ~X() sz = " << sz << endl;
	delete [] elem;
	clog << "I have freed elem" << endl;
	delete [] def;
	clog << "I have freed def" << endl;
}

int main() {
	X x2(10);
	X x3(15);
	try {
		X x1(-10);
	} catch (invalid_argument &ia) {
		clog << "Something Bad!" << endl;
		clog << ia.what() << endl;
	}
	clog << "I am gonna return!" << endl;
	return 0;
}
