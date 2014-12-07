#include <string>
#include <iostream>

using namespace std;

struct employee {
    employee(string f, string l) :
        first_name(f),
        last_name(l) {}
    string first_name;
    string last_name;
};

struct manager : public employee {
    manager(string f, string l) :
        employee {f, l} {}
};

struct manager2 {
    employee e;
    manager2(string f, string l) :
        e {f, l} {}
};

void print_employee(employee *e) {
    cout << "First name: " << e->first_name << ", Last name: " << e->last_name << endl;
}

void print_manager2(manager2 *m) {
    cout << "First name: " << m->e.first_name << ", Last name: " << m->e.last_name << endl;
}

int main() {
    employee e {"Yang", "Ge"};
    manager m {"Mike", "Le"};

    manager2 m2 {"Mike", "Le2"};
    print_employee(&e);
    print_employee(&m);

    print_manager2(&m2);
}
