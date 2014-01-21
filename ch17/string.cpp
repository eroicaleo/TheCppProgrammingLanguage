#include <iostream>
#include <string>

using namespace std;

string ident(string arg) {
	return arg;
}

int main() {
	string s1{"Adams"};
	s1 = ident(s1);

	string s2{"Pratchett"};
	s2 = s1;

	cout << s1 << " " << s2 << endl;
}
