#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int f() {
	return 100;
}

int& g() {
	int j = 66;
	int& i = j;
	return i;
}

struct S {
	S() { cout << "I am in S()!" << endl; }
	S(const S &) { cout << "I am in S(const S&)!" << endl; }
	S(S &&) { cout << "I am in S(S&&)!" << endl; }
};

S foo() {
	S s0;
	return s0;
}

int main() {
	// This is undefined behaviour
	int &li0 = g();
	cout << li0 << endl;
	// The output is a strange number
	cout << li0 << endl;

	// This is correct
	int &&ri0 = f();
	cout << ri0 << endl;
	cout << ri0 << endl;
	cout << ri0 << endl;

	string var {"Cambridge"};
	string f();

	string& r1(var);
	// The following two are wrong
	// string& r2 {f()};
	// string& r3 {"Princeton"};

	// The first should be wrong, but why the compiler does not complain?
	// string&& rr1 {var};
	// string&& rr2 {f()};
	string&& rr3 {"Princeton"};

	// vector<int> v {1, 2, 3};
	// This can not compile, because swap is like swap(T&, T&)
	// However vector<int>{4, 5, 6} is a temporary object (rvalue)
	// swap(v, vector<int>{4, 5, 6});
	
	S s1;
	S s2 = s1;
	S s3 = move(foo());
	return 0;
}
