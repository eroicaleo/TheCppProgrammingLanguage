#include <vector>
#include <iostream>

using namespace std;

struct Z {
	vector<int> elem;
	int my_favorite;
	int *largest;
};

int main() {
	Z v0;
	cout << v0.my_favorite << endl;
	cout << v0.largest << endl;
	Z v00 {};
	cout << v00.my_favorite << endl;
	cout << v00.largest << endl;

	Z val {{1, 2, 3}, 1, &val.elem[2]};
	cout << val.my_favorite << endl;
	cout << *val.largest << endl;
	cout << val.largest << endl;

	Z v2 = val;
	cout << v2.my_favorite << endl;
	cout << *v2.largest << endl;
	cout << v2.largest << endl;

	Z v3 = move(val);
	cout << val.my_favorite << endl;
	cout << *val.largest << endl;
	cout << val.largest << endl;
	cout << val.elem.size() << endl;

}
