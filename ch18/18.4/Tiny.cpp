#include <iostream>

using namespace std;

class Tiny {
    char v;
    void assign(int i) {
	if (i & ~077) {
	    throw Bad_range();
	}
	v = i;
    }
public:
    class Bad_range {};
    Tiny(int i) {
	assign(i);
    }
    Tiny& operator=(int i) {
	assign(i);
	return *this;
    }

    operator int() const {
	return v;
    }
};

int operator+(Tiny t1, Tiny t2) {
    cout << "I am in operator+ for Tiny!" << endl;
    return int(t1)+int(t2);
}

int main() {
    Tiny t(10);
    Tiny t1(20);
    // Runtime exception
    // Tiny t0(1024);

    // Not compile without opertor int()
    cout << "Tiny t = " << t << endl;

    cout << "t + t1 = " << t + t1 << endl;
    // Will cause ambiguity because of defining opertor+(Tiny t1, Tiny t2)
    // cout << "t + 23 = " << t + 23 << endl;
}
