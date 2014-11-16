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
	string fullname() {
		return first_name + " " + middle_initial + " " + family_name;
	}
	void print() {
		cout << fullname() << endl;
	}
	friend ostream& operator<<(ostream &os, const Employee &e);
private:
	string first_name, family_name;
	char middle_initial = '\0';
	Date hiring_date;
	short department;
};

class Manager : public Employee {
public:
	Manager(string f, string l) :
		Employee {f, l} {
	}
	void print() {
		Employee::print();
		cout << "Level: " << level << endl;
	}
private:
	list<Employee *> group;
	short level;
};

class Director : public Manager {
public:
	Director(string f, string l) :
		// type ‘Employee’ is not a direct base of ‘Director’
		// Employee {f, l},
		Manager {f, l} {
	}
private:
	void print() {
		// This is OK.
		Manager::print();
		// This is OK too.
		Employee::print();
	}
};

class Assistant : public Employee {
public:
	Assistant(string f, string l) :
		Employee(f, l) {
	}
};

ostream& operator<<(ostream &os, const Employee &e) {
	os << "First name: " << e.first_name << ", Last name: " << e.family_name << " is hired in: ";
	return os;
}

void f(Employee *e, Manager *m) {
	list<Employee *> emlist = {e, m};
}

void g(Employee *e, Manager *m) {
	Employee *ee = m;
	// compile error: invalid conversion from ‘Employee*’ to ‘Manager*’
	// Manager *mm = e;
	// has to be:
	Manager *mm = static_cast<Manager *>(e);
	ee->print();
	// Weird number: mm's level: 20616
	// cout << "mm's level: " << mm->level << endl;
	mm->print();
}

int main() {
	Employee Yang("Yang", "Ge");
	Manager Mike("Mike", "Le");
	Director Kang("Kang", "Xiao");
	Assistant Dee("Dee", "Wilson");

	cout << Yang << endl;
	cout << Mike << endl;
	cout << Kang << endl;
	cout << "sizeof Yang: " << sizeof(Yang) << endl;
	cout << "sizeof Mike: " << sizeof(Mike) << endl;
	cout << "sizeof Kang: " << sizeof(Kang) << endl;

	f(&Yang, &Mike);
	g(&Yang, &Mike);
	f(&Mike, &Kang);

	return 0;
}
