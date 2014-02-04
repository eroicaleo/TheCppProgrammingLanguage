#include <array>
#include <iostream>
#include <memory>

using namespace std;

template<class T>
class Matrix {
	array<int, 2> dim;
	T *elem;
public:
	Matrix(int d1, int d2): dim{{d1, d2}}, elem { new T[d1*d2] } {}
	size_t size() const { return dim[0]*dim[1]; }

	Matrix(const Matrix &);
	Matrix &operator=(const Matrix &);

	Matrix(Matrix&&) {};
	Matrix& operator=(Matrix&&) {};

	~Matrix() { delete[] elem; }

	T& operator[](size_t i);
};

template<class T>
Matrix<T>::Matrix(const Matrix& m):
	dim(m.dim),
	elem{new T[m.size()]} {
		cout << "Call the copy constructor " << endl;
		uninitialized_copy(m.elem, m.elem+m.size(), elem);
	}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m) {
	cout << "Call the operator= " << endl;
	if (dim[0] != m.dim[0] || dim[1] != m.dim[1]) {
		throw runtime_error("bad size in Matrix =");
	}
	copy(m.elem, m.elem+m.size(), elem);
	return *this;
}

template<class T>
T& Matrix<T>::operator[](size_t i) {
	if (i < size()) {
		return elem[i];
	}
	return elem[0];
}

int f() {
	int i;
	cout << i << endl;
	return i;
}

int main() {

	Matrix<int> m0(10, 9);
	for (size_t i = 0; i < m0.size(); ++i) {
		m0[i] = i;
	}
	for (size_t i = 0; i < m0.size(); ++i) {
		cout << m0[i] << " ";
	}
	cout << endl;
	Matrix<int> m1{m0};
	for (size_t i = 0; i < m1.size(); ++i) {
		cout << m1[i] << " ";
	}
	cout << endl;
	Matrix<int> m2(10, 9);
	m2 = m0;
	for (size_t i = 0; i < m2.size(); ++i) {
		cout << m2[i] << " ";
	}
	cout << endl;
	return 0;
}
