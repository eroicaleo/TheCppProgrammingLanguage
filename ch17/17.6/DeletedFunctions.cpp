#include <iostream>

class Base {
public:
	Base() {}
	Base(const Base &) = delete;
	Base& operator=(const Base &) = delete;

	Base(Base &&) = delete;
	Base& operator=(Base &&) = delete;
};

struct Z {
	Z(double) {}
	Z(int) = delete;
};

class Not_on_stack {
private:
	~Not_on_stack();
};

class Not_on_free_store {
public:
	void* operator new(size_t) = delete;
};

int main() {
	Base b1;
	// This will give a compile error
	// Base b2(b1);

	Z z1 {1.0};
	// This will not compile
	// Z z2 {1};

	// This will not compile
	// Not_on_stack v1;
	Not_on_free_store v2;

	Not_on_stack *p1 = new Not_on_stack;
	// This will not compile
	Not_on_free_store *p2 = new Not_on_free_store;
}
