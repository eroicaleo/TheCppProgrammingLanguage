#include <iostream>
#include <string>

using namespace std;

template<typename T>
class DiskPtr {
    string identifier;
    T* in_core_address;
    T* read_from_disk() {
	cout << "I am in read_from_disk." << endl;
	return nullptr;
    }
    void write_to_disk() {
	cout << "I am in write_from_disk." << endl;
    }
public:
    DiskPtr(const string& name) : identifier{name}, in_core_address{nullptr} {}
    ~DiskPtr() { write_to_disk(); }

    T* operator->() {
	if (in_core_address == nullptr)
	    in_core_address = read_from_disk();
	return in_core_address;
    }
};

int main() {
    DiskPtr<int> di("lala");
    di.operator->();
    return 0;
}
