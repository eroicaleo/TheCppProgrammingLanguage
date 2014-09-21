
const int short_max = 100;

class String {
public:
    String();

    explicit String(const char *); // Constructor from c string

    // copy constructor
    String(const String &);
    // copy assignment
    String& operator=(const String &);

    // move constructor
    String(const String &&);
    // move assignment
    String& operator=(const String &&);

    // Destructor
    ~String() {
	if (short_max < sz) {
	    delete [] ptr;
	}
    }

private:
    int sz;
    char *ptr;
};

int main() {
    return 0;
}
