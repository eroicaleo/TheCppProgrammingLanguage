#include <memory>
#include <iostream>

using namespace std;

template<typename T>
class my_unique_ptr {
public:
    explicit operator bool() {
	return true;
    }
};

int main() {
    my_unique_ptr<int> p;

    if (!p)
	cout << "not valid!" << endl;

    // This does not compile
    // bool b0 = p;
    bool b = bool(p);
    bool b0 {p};

    return 0;
}
