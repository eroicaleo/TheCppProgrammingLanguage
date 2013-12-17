#include <iostream>

using namespace std;

template<typename T>
class Tree {
	typedef T value_type;
	enum Policy {rb, splay, treeps};
	class Node {
		Node *right;
		Node *left;
		value_type value;
	public :
		void f(Tree *);
	};
	Node *top;
public:
	void g();
};

template<typename T>
void Tree<T>::Node::f(Tree *p) {
	/* Error: the node can not see the member top in Tree class */
	// top = right;
	/* OK, can access Tree member top when given the pointer Tree *p */
	p->top = right;
	value_type v = left->value;
	cout << v << endl;
}

template<typename T>
void Tree<T>::g() {
	/* Error: the Tree class can not see the member right in Node class */
	// value_type v = right->value;
	/* Error: the Tree class can not access the member right in Node class because it is private */
	// value_type val = top->right->value;
	top->f(this);
	return;
}

int main() {
	Tree<int> tree1;
	// Calling tree1.g() is necessary, 
	// otherwise g() will not be instantiated (called lazy something).
	// And the compiler will not complain
	tree1.g();
	return 0;
}
