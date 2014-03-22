#include <array>
#include <iostream>
#include <memory>

using namespace std;

template<class T>
class Matrix {
	array<int, 2> dim;
	T *elem;
	template<class S>
		friend Matrix<S> operator+(const Matrix<S> &T1, const Matrix<S> &T2);
	template<class R> 
		friend ostream& operator<<(ostream &os, const Matrix<R>& M);
public:
	Matrix(int d1, int d2): dim{{d1, d2}}, elem { new T[d1*d2] } {}
	size_t size() const { return dim[0]*dim[1]; }

	Matrix(const Matrix &);
	Matrix &operator=(const Matrix &);

	Matrix(Matrix&&);
	Matrix& operator=(Matrix&&);

	~Matrix() { delete[] elem; }
	

	T& operator[](size_t i);
	Matrix& operator+=(const Matrix &);
};

template<class T>
ostream& operator<<(ostream &os, const Matrix<T>& M) {
	auto n = M.size();
	for (size_t i = 0; i != n; ++i) {
		os << M.elem[i] << " ";
	}
	return os;
}

template<class T>
Matrix<T> operator+(const Matrix<T> &T1, const Matrix<T> &T2) {
	
	cout << "I am in operator+ " << endl;
	Matrix<T> res {T1};
	res += T2;
	return res;
}

template<class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &a) {
	if (dim[0] != a.dim[0] || dim[1] != a.dim[1]) {
		throw runtime_error("Bad Matrix += argument");
	}
	cout << "I am in operator+= " << endl;

	T* p = elem;
	T* q = a.elem;
	T* end = elem + dim[0]*dim[1];
	while (p != end) {
		*p++ = *q++;
	}

	return *this;
}

template<class T>
Matrix<T>::Matrix(Matrix&& m):
	dim(m.dim),
	elem{m.elem} {
		cout << "Call the move constructor " << endl;
		m.dim = {{0, 0}};
		m.elem = nullptr;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix&& m) {
	cout << "Call the move operator= " << endl;
	swap(dim, m.dim);
	swap(elem, m.elem);
	return *this;
}

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
	int i = 0;
	cout << i << endl;
	return i;
}

int main() {

	Matrix<int> m0(10, 9);
	for (size_t i = 0; i < m0.size(); ++i) {
		m0[i] = i;
	}
	cout << m0 << endl;
	Matrix<int> m1{m0};
	cout << m1 << endl;
	Matrix<int> m2(10, 9);
	m2 = m0;
	for (size_t i = 0; i < m2.size(); ++i) {
		m2[i] = -i;
	}
	cout << m2 << endl;
	cout << "creating m3" << endl;
	Matrix<int> m3 = m0 + m2;
	cout << m3 << endl;
	cout << "creating m4" << endl;
	Matrix<int> m4 = m0;
	m4 = m0 + m2;
	cout << m4 << endl;
	return 0;
}
