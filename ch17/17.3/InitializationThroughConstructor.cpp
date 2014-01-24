#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct X {
	X(int a): x{a} {}
private:
	int x;
};

struct Y : X {
	X m {0};
	Y(int a): X{a}, m{a} {}
	Y(): X{0} {}
private:
};

int main() {
	X x1(0);
	Y y1;
	X a[] {1, 2, 3};
	X b[] {1, 2, 3};
	vector<X> v {1, 2, 3, 4};
	X x2 = x1;
	X x3 = {4};
	X x4 = (4);

	vector<int> c {1, 2, 3, 4};
	for (auto a : c) {
		cout << a << " ";
	}
	cout << endl;
	vector<int*> d {10, nullptr};
	for (auto a : d) {
		cout << a << " ";
	}
	cout << endl;
	vector<int*> e {nullptr, nullptr};
	for (auto a : e) {
		cout << a << " ";
	}
	cout << endl;


	return 0;
}
