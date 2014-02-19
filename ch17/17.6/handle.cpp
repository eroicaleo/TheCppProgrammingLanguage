template<class T>
class Handle {
	T *p;
public:
	Handle(T* pp): p(pp) {}
	~Handle() { delete p; }
private:
	Handle(const Handle &h);
	Handle& operator=(const Handle &h);
};

int main() {
	Handle<int> h {new int {99}};
	// Thi is wrong behaviour
	// By the way, the declaration of destructor does not 
	// prohibit the generation of default copy constructor in g++ 4.7.2
	// So we have to declare the copy constructor/assignment private
	// Handle<int> h1(h);
	Handle<int> h1 {new int {100}};
	// h1 = h;

	return 0;
}
