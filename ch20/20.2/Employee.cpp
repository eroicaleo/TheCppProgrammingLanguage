#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Date {
	int day, month, year;
};

class Employee {
public:
	Employee(string f, string l) :
		first_name {f},
		family_name {l}
	{}
	string first_name, family_name;
	char middle_initial;
	Date hiring_date;
	short department;
};

class Manager : public Employee {
public:
	Manager(string f, string l) :
		Employee {f, l} {
	}
	list<Employee *> group;
	short level;
};

ostream& operator<<(ostream &os, const Employee &e) {
	os << "First name: " << e.first_name << ", Last name: " << e.family_name << " is hired in: ";
	return os;
}

int main() {
	Employee Yang("Yang", "Ge");
	Manager Mike("Mike", "Le");

	cout << Yang << endl;
	cout << Mike << endl;

	return 0;
}
