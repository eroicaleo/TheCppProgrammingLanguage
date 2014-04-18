#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Assoc {
    vector<pair<string, int>> vec;
    const int& operator[](const string &) const;
    int& operator[](const string &);
};

int& Assoc::operator[](const string &s) {
    for (auto& x: vec) {
	if (x.first == s)
	    return x.second;
    }

    vec.push_back({s, 0});

    return vec.back().second;
}

int main() {
    Assoc values;
    ++values["x_x"];
    ++values["n_n"];
    ++values["n_n"];
    ++values["g_g"];
    ++values["g_g"];
    ++values["g_g"];

    for (auto x:  values.vec) {
	cout << x.first << " " << x.second << endl;
    }
    return 0;
}
