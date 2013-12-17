
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Date {
	int d, m, y;
	mutable bool cache_valid;
	mutable string cache;

	void compute_cache_value() const;

	public:
	void init(int dd, int mm, int yy);
	Date(int dd, int mm, int yy);
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);
	int day() const { return d; }
	int month() const { return m; }
	int year() const { return y; }
	string string_rep() const;
};

void Date::compute_cache_value() const {
	char tmp[20];
	sprintf(tmp, "%04d-%02d-%02d", y, m, d);
	string tmpstr(tmp);
	cache = tmpstr;
	cache_valid = true;
	return;
}

string Date::string_rep() const {
	if (!cache_valid) {
		compute_cache_value();
	}
	return cache;
}

void f() {
	Date today(16, 10, 1996);
	cout << today.string_rep() << endl;
	today.init(16, 10, 1996);
	Date my_birthday(29, 7, 1985);
	cout << my_birthday.string_rep() << endl;

	Date tomorrow = today;
	tomorrow.add_day(1);

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
	cache("")
{
	d = dd;
	m = mm;
	y = yy;
}

void Date::add_day(int n) {
	d += n;
}

void Date::add_year(int n) {
	y += n;
}
