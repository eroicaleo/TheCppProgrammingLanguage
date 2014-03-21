class X {
public:
	X& operator=(const X &) = delete;
	void *operator&() = delete;
	X& operator,(const X &) = delete;
};

int main() {
	X a, b;
	a = b;
	void *p = &a;
	X c = (a, b);
	p = nullptr;
}
