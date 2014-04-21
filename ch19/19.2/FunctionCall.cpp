#include <algorithm>
#include <iostream>
#include <complex>
#include <vector>

using namespace std;

class Add {
    complex<double> val;
public:
    Add(complex<double> c) : val{c} {}
    Add(double r, double i) : val{r, i} {}

    void operator()(complex<double> &c) const {
	c += val;
    }
};

int main() {
    complex<double> c{1, 2}; 

    vector<complex<double>> vec {complex<double>{3, 4}, complex<double>{5, 6}, complex<double>{7, 8}};

    for_each(vec.begin(), vec.end(), Add(c));
    for_each(vec.begin(), vec.end(), [](complex<double> &a){cout << a << endl;});
}
