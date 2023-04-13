//HW6, Due: 11:59pm, Wednesday, March 12, 2023
//Recursive Operation with Trees
#include <iostream>
#include <typeinfo>
using namespace std;

class node {
public:
	int value;
	node* Lchild;
	node* Rchild;
	node(int i) : value(i), Lchild{ nullptr }, Rchild{ nullptr } {}
	node() { Lchild = Rchild = nullptr; }
};
class tree {//Full binary trees: 1, 3, 7, 15 ,   2^k-1 nodes
public:
	node* root;
	tree() { root = nullptr; }
	tree(int n, int m);//constructor
	node* Constructor_helper(int n, int m);
	void InOrderT(node* p);//Inorder Traveral of a subtree whose root is pointed by p
	void PreOrderT(node* p);
	void PostOrderT(node* p);

	//Implement InorderSort, Preordersot, PostorderSort and initializer_list.
	//Recursion is required in all implemenations.
	//In the three sorting implementation, you can use while loop, but not other loop stuctures (such as for).
	//pair<node*, node*> InorderSort(node* p);
	void InorderSort(node* p);
	pair<node*, node*> PreorderSort(node* p);
	pair<node*, node*> PostorderSort(node* p);
	tree(const initializer_list<int>& I);
	void IL_helper(const initializer_list<int>& I, const int*& p1, node* p2);

};






tree::tree(int n, int m) {

	root = Constructor_helper(n, m);

}

node* tree::Constructor_helper(int n, int m) {//constructor helper
	if (n == 0) return nullptr;//NULL is nullptr and zero; don't use it anymore
	//int i{ NULL }; i is 0
	node* p{ new node{ rand() % m } };
	p->Lchild = Constructor_helper(n - 1, m);
	p->Rchild = Constructor_helper(n - 1, m);
	return  p;
}




void tree::PostOrderT(node* p) {
	if (!p) return;
	PostOrderT(p->Lchild);
	//cout << p->value << " ";
	PostOrderT(p->Rchild);
	cout << p->value << " ";
}

void tree::PreOrderT(node* p) {
	if (!p) return;
	cout << p->value << " ";
	PreOrderT(p->Lchild);
	//cout << p->value << " ";
	PreOrderT(p->Rchild);
}

void tree::InOrderT(node* 	if (!p) return;
	InOrderT(p->Lchild);
	cout << p->value << " ";
	InOrderT(p->Rchild);
}
pair<node*, node*> tree::PostorderSort(node* p) {
	if (!p) return { nullptr,nullptr };
	pair<node*, node*> L{ PostorderSort(p->Lchild) };
	pair<node*, node*> R{ PostorderSort(p->Rchild) };
	p->Lchild = L.first;
	if (L.second) L.second->Rchild = p;
	p->Rchild = R.first;
	if (R.second) R.second->Rchild = nullptr;
	return { p, R.second ? R.second : (L.second ? L.second : p) };
}
pair<node*, node*> tree::PreorderSort(node* p) {
	if (!p) return { nullptr,nullptr };
	pair<node*, node*> L{ PreorderSort(p->Lchild) };
	pair<node*, node*> R{ PreorderSort(p->Rchild) };
	p->Lchild = L.first;
	if (L.second) L.second->Rchild = p;
	p->Rchild = R.first;
	if (R.second) R.second->Rchild = nullptr;
	return { p,L.first ? L.first : (R.first ? R.first : p) };
}
pair<node*, node*> tree::InorderSort(node* p) {
	if (!p) return { nullptr,nullptr };
	pair<node*, node*> L{ InorderSort(p->Lchild) };
	pair<node*, node*> R{ InorderSort(p->Rchild) };
	p->Lchild = L.first;
	if (L.second) L.second->Rchild = p;
	p->Rchild = R.first;
	if (R.second) R.second->Rchild = nullptr;
	return { L.first ? L.first : p, R.second ? R.second : p };
}
tree::tree(const initializer_list<int>& I) {
	const int* p{ I.begin() };
	IL_helper(I, p, root);
}


void tree::IL_helper(const initializer_list<int>& I, const int*& p1, node* p2) {
	if (p1 == I.end()) return;
	if (!p2) {
		p2 = new node{ *p1 };
		p1++;
	}
	IL_helper(I, p1, p2->p) {
		if (!p) return;
		InOrderT(p->Lchild);
		cout << p->value << " ";
		InOrderT(p->Rchild);
	}
}







int main() {


	tree T1(3, 9);
	T1.InOrderT(T1.root);
	cout << endl;
	T1.PreOrderT(T1.root);
	cout << endl;
	T1.PostOrderT(T1.root);
	cout << endl;

	cout << endl;


	T1.InorderSort(T1.root);
	T1.InOrderT(T1.root);
	cout << endl;
	T1.PreOrderT(T1.root);
	cout << endl;
	T1.PostOrderT(T1.root);
	cout << endl;
	cout << endl;

	T1.PreorderSort(T1.root);
	T1.InOrderT(T1.root);
	cout << endl;
	T1.PreOrderT(T1.root);
	cout << endl;
	T1.PostOrderT(T1.root);
	cout << endl;
	cout << endl;


	T1.PostorderSort(T1.root);
	T1.InOrderT(T1.root);
	cout << endl;
	T1.PreOrderT(T1.root);
	cout << endl;
	T1.PostOrderT(T1.root);
	cout << endl;
	cout << endl;

	tree T2{ 10,11,12,13,14,15,16 };
	T2.InOrderT(T2.root);
	cout << endl;
	T2.PreOrderT(T2.root);
	cout << endl;
	T2.PostOrderT(T2.root);
	cout << endl;

	return 0;
}
