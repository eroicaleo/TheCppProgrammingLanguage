#include <initializer_list>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<double> v{1, 2, 3.456, 99.99};

map<vector<string>, vector<int> > years {
	{{"Maurice","Vincent", "Wilkes"}, {1913, 1945, 1951, 1967, 2000}},
	{{"Martin", "Richards"}, {1982, 2003, 2007}},
	{{"David", "John", "Wheeler"}, {1927, 1947, 1951, 2004}},
};

void f1(initializer_list<int> args) {
	for (size_t i = 0; i < args.size(); ++i) {
		cout << args.begin()[i] << endl;
	}
	return;
}

void f2(initializer_list<int> args) {
	for (auto p = args.begin(); p != args.end(); ++p) {
		cout << *p << endl;
	}
	return;
}

void f3(initializer_list<int> args) {
	for (auto p : args) {
		cout << p << endl;
	}
	return;
}

int main() {
	f1({1, 2});
	f1({23, 345, 4567, 56789});
	f1({});
	f2({1, 2});
	f2({23, 345, 4567, 56789});
	f2({});
	f3({1, 2});
	f3({23, 345, 4567, 56789});
	f3({});
	years.insert({{"Bjarne", "Stroustrup"}, {1950, 1975, 1985}});
	return 0;
}
