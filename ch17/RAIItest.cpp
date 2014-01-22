#include <iostream>
#include <stdexcept>

using namespace std;

struct X {
	X(int s);
	~X();
private:
	struct def_mem {
		def_mem() {
			def = new int[10];
			clog << "I have constructed def_mem" << endl;
		}
		~def_mem() {
			delete [] def;
			clog << "I have freed def" << endl;
		}
	private:
		int *def;
	};
	struct X_sub {
		X_sub() { clog << "I'am in X_sub()" << endl; }
		~X_sub() { clog << "I'am in ~X_sub()" << endl; }
	};
	X_sub xs;
	def_mem def;
	int sz;
	int *elem;
};

X::X(int s) {
	if (s < 0) { 
		throw invalid_argument("size less than 0");
	}
	sz = s;
	elem = new int[sz];
	clog << "I have constructed X" << endl;
}

X::~X() {
	clog << "I am in ~X() sz = " << sz << endl;
	delete [] elem;
	clog << "I have freed elem" << endl;
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
