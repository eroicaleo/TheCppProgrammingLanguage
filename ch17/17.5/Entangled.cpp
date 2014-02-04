#include <iostream>
#include <memory>

using namespace std;

struct S2 {
	shared_ptr<int> p;
};

int main() {
	S2 x {shared_ptr<int>(new int{1})};
	S2 y (x);
	cout << *x.p << endl;
	cout << *y.p << endl;
	cout << x.p.use_count() << endl;
	cout << y.p.use_count() << endl;
	x.p.reset(new int{100});
	cout << *x.p << endl;
	cout << *y.p << endl;
	cout << x.p.use_count() << endl;
	cout << y.p.use_count() << endl;
	return 0;
}
