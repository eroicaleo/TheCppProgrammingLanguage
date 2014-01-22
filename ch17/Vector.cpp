#include <iostream>

using namespace std;

class Vector {
public:
	Vector(int s);
	~Vector();
private:
	double *elem; 
	int sz;
};

class Bad_size {
public:
	Bad_size(int s) : sz(s) {}
private:
	int sz;
};

Vector::Vector(int s) {
	if (s < 0) throw Bad_size(s);
	sz = s;
	elem = new double[s];
}

Vector::~Vector() {
	delete [] elem;
}

int main() {
	Vector v(10);
	try {
		Vector v(-10);
	} catch (Bad_size) {
		cerr << "Can not create Vector!" << endl;
		exit(66);
	}
	return 0;
}
