#include <cstdio>
#include <iostream>

using namespace std;

struct S {
	int m;
	int f();
	static int sm;
};

int S::f() { 
	cout << "I am calling f()." << endl;
	return m;
}

int g() {
	return 0;
}

int S::sm = 7;

int (S::*pmf)() = &S::f;

int main() {
	S s1;
	(s1.*pmf)();
	return 0;
}
