
struct Date {
	int d, m, y;

	void init(int dd, int mm, int yy);
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);
};

Date my_birthday;

void f() {
	Date today;
	today.init(16, 10, 1996);
	my_birthday.init(29, 7, 1985);

	Date tomorrow = today;
	tomorrow.add_day(1);

	Date d1 = today;
	Date d2(today);
}

int main() {
	return 0;
}

void Date::init(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}

void Date::add_day(int n) {
	d += n;
}
