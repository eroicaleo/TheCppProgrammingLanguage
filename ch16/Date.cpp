
class Date {
	int d, m, y;

	public:
	void init(int dd, int mm, int yy);
	Date(int dd, int mm, int yy);
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);
	int day() const { return d; }
	int month() const { return m; }
	int year() const { return y; }
};

void f() {
	Date today(16, 10, 1996);
	today.init(16, 10, 1996);
	Date my_birthday(29, 7, 1985);

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
	return 0;
}

void Date::init(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}

Date::Date(int dd, int mm, int yy) {
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
