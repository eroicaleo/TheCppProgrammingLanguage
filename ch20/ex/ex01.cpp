#include <iostream>

using namespace std;

class Base {
public:
	virtual void iam() {
		cout << "I am in Base!" << endl;
	}
};

class Derived1 : public Base {
public:
	virtual void iam() {
		cout << "I am in Derived1!" << endl;
	}
};

class Derived2 : public Base {
public:
	virtual void iam() {
		cout << "I am in Derived2!" << endl;
	}
};

int main() {
	Derived1 d1;
	Derived2 d2;
	d1.iam();
	d2.iam();

	Base *bp {};
	bp = &d1;
	bp->iam();
	bp = &d2;
	bp->iam();

	return 0;
}
