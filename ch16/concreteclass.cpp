#include <string>
#include <iostream>

using namespace std;

namespace Chrono {
	enum Month {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
	class Date {
	public:
		class Bad_date {};
		explicit Date(int dd = 0, Month mm = static_cast<Month>(0), int yy = 0);
		// nonmodifying function to examine the data
		int day() const;
		Month month() const;
		int year() const;

		string string_rep() const;
		void char_rep(char s[], int max) const;

		// modifying function to for changing the Date
		Date &add_year(int n);
		Date &add_month(int n);
		Date &add_day(int n);
	private:
		bool is_valid();
		int d, m, y;
	};

	bool is_date(int d, Month m, int year);
	bool is_leapyear(int y);

	bool operator==(const Date &a, const Date &b);
	bool operator!=(const Date &a, const Date &b);

	const Date& default_date();

	ostream &operator<<(ostream &os, const Date &d); // print d to os
	istream &operator>>(istream &os, Date &d); // read Date from is
} // Chrono

using namespace Chrono;

int main() {
	Date d;
	Date d1(23, jun, 1984);
	cout << d << endl;
	cout << d1 << endl;
	return 0;
}

namespace Chrono {
	Date::Date(int dd, Month mm, int yy) : d(dd), m(mm), y(yy) {
		if (dd == 0)
			d = default_date().day();
		if (mm == 0)
			m = default_date().month();
		if (yy == 0)
			y = default_date().year();

		if (!is_valid())
			throw Bad_date();
	}

	inline bool Date::is_valid() {
		return is_date(d, static_cast<Month>(m), y);
	}

	int Date::day() const {
		return d;
	}
	Month Date::month() const {
		return static_cast<Month>(m);
	}
	int Date::year() const {
		return y;
	}

	ostream &operator<<(ostream &os, const Date &d) {
		os << d.day() << d.month() << d.year();
		return os;
	}

	const Date& default_date() {
		static Date mellon_birthday(28, dec, 2012);
		return mellon_birthday;
	}

	bool is_date(int d, Month m, int y) {

		int ndays;
		if (y < 0 || m < 1 || d < 1)
			return false;

		switch (m) {
			case feb:
			      ndays = is_leapyear(y) + 28;
			      break;
			case jan: case mar: case may: case jul: case aug: case oct: case dec:
			      ndays = 31;
			      break;
			case apr: case jun: case sep: case nov:
			      ndays = 30;
			      break;
			default:
			      return false;
		}
		return d <= ndays;
	}

	bool is_leapyear(int y) {
		return (y % 4 == 0);
	}
}
