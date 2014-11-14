#include <cstdio>

class A {
public:
	int a = 1;
};

class AA : public A {
public:
	int aa {};
};

int main() {
	int i = {};
	int j {};
	printf("%d %d\n", i, j);
	A A;
	AA AA;
	printf("A.a = %d, AA.aa = %d, AA.a = %d\n", A.a, AA.aa, AA.a);
	return 0;
}
