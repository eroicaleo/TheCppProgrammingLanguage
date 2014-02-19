#include <valarray>

using namespace std;

class mygslice {
	valarray<size_t> size;
	valarray<size_t> stride;
	valarray<size_t> d1;
public:
	mygslice() = default;
	~mygslice() = default;
	mygslice(const mygslice &) = default;
	mygslice& operator=(const mygslice &) = default;
	mygslice(mygslice &&) = default;
	mygslice& operator=(mygslice &&) = default;
};

int main() {
	mygslice gs;
}
