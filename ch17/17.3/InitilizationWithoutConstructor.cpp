#include <iostream>
#include <string>

using namespace std;

struct Work {
	string author;
	string name;
	int year;
};

Work s9 { "Beethoven",
			"Symphony No.9, in D minor, op.125; Choral",
			1824};

// Work current_playing{s9};
Work current_playing(s9);

Work none {};

void f() {
	Work beta;
	cout << beta.author << beta.name << beta.year << endl;
	Work gamma {};
	cout << gamma.author << gamma.name << gamma.year << endl;
}

int main() {
	int a {0};
	char *p {nullptr};

	printf("a = %d, p = 0x%p\n", a, p);
	cout << s9.author << s9.name << s9.year << endl;
	cout << current_playing.author << current_playing.name << current_playing.year << endl;
	cout << none.author << none.name << none.year << endl;

	Work beta;
	cout << beta.author << beta.name << beta.year << endl;

	f();
}
