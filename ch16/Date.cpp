
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct cache {
	cache() : cache_valid(false), rep("") {}
	bool cache_valid;
	string rep;
};

inline bool leapyear(int n) {
	return (n % 4 == 0);
}

class Date {
	int d, m, y;
	mutable bool cache_valid;
	mutable string rep;
	cache *c;

	void compute_cache_value() const;
	void compute_cache_value_indirection() const;

	public:
	void init(int dd, int mm, int yy);
	Date(int dd, int mm, int yy);
	Date();
	Date(const Date &);
	~Date();
	Date &add_year(int n);
	Date &add_month(int n);
	Date &add_day(int n);
	int day() const { return d; }
	int month() const { return m; }
	int year() const { return y; }
	string string_rep() const;
	string string_rep_indirection() const;

	const Date &operator=(const Date &);
};

Date::Date(const Date &d1) {
	d = d1.d;
	m = d1.m;
	y = d1.y;
	cache_valid = d1.cache_valid;
	rep = d1.rep;

	if ((c = new cache()) == NULL) {
		cerr << "Can not get space for cache!" << endl;
		exit(66);
	}
	c->cache_valid = d1.c->cache_valid;
	c->rep = d1.c->rep;
}

const Date & Date::operator=(const Date &d1) {
	d = d1.d;
	m = d1.m;
	y = d1.y;
	cache_valid = d1.cache_valid;
	rep = d1.rep;

	if (c == NULL) {
		if ((c = new cache()) == NULL) {
			cerr << "Can not get space for cache!" << endl;
			exit(66);
		}
	}
	c->cache_valid = d1.c->cache_valid;
	c->rep = d1.c->rep;

	return *this;
}

void Date::compute_cache_value() const {
	char tmp[20];
	sprintf(tmp, "%04d-%02d-%02d", y, m, d);
	string tmpstr(tmp);
	rep = tmpstr;
	cache_valid = true;
	return;
}

void Date::compute_cache_value_indirection() const {
	char tmp[20];
	sprintf(tmp, "%04d-%02d-%02d", y, m, d);
	string tmpstr(tmp);
	c->rep = tmpstr;
	c->cache_valid = true;
	return;
}

string Date::string_rep_indirection() const {
	if (!c->cache_valid) {
		compute_cache_value_indirection();
	}
	return c->rep;
}

string Date::string_rep() const {
	if (!cache_valid) {
		compute_cache_value();
	}
	return rep;
}

void f() {
	Date today(16, 10, 1996);
	cout << today.string_rep() << endl;
	cout << today.string_rep_indirection() << endl;
	today.init(16, 10, 1996);
	Date my_birthday(29, 7, 1985);
	cout << my_birthday.string_rep() << endl;
	cout << my_birthday.string_rep_indirection() << endl;

	Date tomorrow = today;
	tomorrow.add_day(1);
	cout << tomorrow.string_rep() << endl;
	cout << tomorrow.string_rep_indirection() << endl;

	Date d1 = today;
	Date d2(today);
}

void f2(Date &d, const Date &cd) {
	int i = d.day();
	d.add_year(1);

	i = cd.day();
	// cd.add_year(1); // Error

	return;
}

int main() {
	f();
	return 0;
}

void Date::init(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}

Date::Date(int dd, int mm, int yy) : 
	cache_valid(false),
	rep("")
{
	d = dd;
	m = mm;
	y = yy;
	c = new cache();
}

Date::Date() :
	cache_valid(false),
	rep(""),
	c(NULL)
{
	d = 0;
	m = 0;
	y = 0;
}

Date& Date::add_day(int n) {
	d += n;
	// This is an error
	// this = NULL;
	// This is another error
	// Date **d1 = &this;
	return *this;
}

Date& Date::add_year(int n) {
	if (d == 29 && m == 2 && !leapyear(y+n)) {
		d = 1;
		m = 3;
	}
	y += n;
	return *this;
}

Date::~Date() {
	delete c;
}
