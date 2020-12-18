#include<iostream>
using namespace std;

template <typename DataType>
class BST {//����������ģ����
public:  BST();
	  bool empty() const;
	  bool search(const DataType& item) const;
	  void insert(const DataType& item);
	  void remove(const DataType& item);
	  void inorder(ostream& out) const;
	  void graph(ostream& out) const;
private:
	class BinNode { //���������� ���
	public:   DataType data;
		  BinNode* left;
		  BinNode* right;
		  BinNode() : left(0), right(0) {}
		  BinNode(DataType item) : data(item), left(0), right(0) {}
	};
	typedef BinNode* BinNodePointer; 
	void search2(const DataType& item, bool& found, BinNodePointer& locptr, BinNodePointer& parent) const;
	void inorderAux(ostream& out, BST<DataType>::BinNodePointer subtreePtr) const;
	void graphAux(ostream& out, int indent, BST<DataType>::BinNodePointer subtreeRoot) const;

	BinNodePointer myRoot;//�����ָ��
};

int main()
{
	BST<int> r;
	for (int i = 1; i < 10; i++)
	{
		r.insert(i);
	}
	ostream& out=cout;
	r.graph(out);

	return 0;
}





template <typename DataType>
inline BST<DataType>::BST() : myRoot(0)
{}

template <typename DataType>
inline bool BST<DataType>::empty() const
{
	return myRoot == 0;
}
template <typename DataType> //public
bool BST<DataType>::search(const DataType& item) const
{
	BST<DataType>::BinNodePointer locptr = myRoot;
	bool found = false;
	while (!found && locptr != 0) {//ֻҪ��û�ҵ���û���������ף��ͼ���ѭ��
		if (item < locptr->data)
			locptr = locptr->left;
		else if (locptr->data < item)
			locptr = locptr->right;
		else found = true;
	}
	return found;
}
template <typename DataType> //private
void BST<DataType>::search2(const DataType& item, bool& found, BST<DataType>::BinNodePointer& locptr, BST<DataType>::BinNodePointer& parent) const
{
	locptr = myRoot;
	parent = 0;
	found = false;
	while (!found && locptr != 0) {
		if (item < locptr->data) {
			parent = locptr;
			locptr = locptr->left;
		}
		else if (locptr->data < item) {
			parent = locptr;
			locptr = locptr->right;
		}
		else   found = true;
	}
}
template <typename DataType>		//public
inline void BST<DataType>::insert(const DataType& item)//����һ�����
{
	BST<DataType>::BinNodePointer locptr = myRoot, parent = 0;
	bool found = false;
	while (!found && locptr != 0) {//�������в��Ҵ�����Ԫ��
		parent = locptr;//parent��¼�µ�ǰλ��
		if (item < locptr->data) locptr = locptr->left;
		else if (locptr->data < item)  locptr = locptr->right;
		else    found = true;
	}
	if (!found) { //���û�ҵ��ٲ���
		locptr = new BST<DataType>::BinNode(item);
		if (parent == 0) myRoot = locptr;
		else if (item < parent->data) parent->left = locptr;
		else  parent->right = locptr;
	}
	else
		cout << "Item already in the tree\n";
}
template <typename DataType>		//public
void BST<DataType>::remove(const DataType& item)//ɾ��һ�����
{
	bool found;
	BST<DataType>::BinNodePointer  x, parent;
	search2(item, found, x, parent);//�Ȳ��Ҹý���Ƿ����
	if (!found) {
		cout << "Item not in the BST\n";
		return;
	}
	if (x->left != 0 && x->right != 0) {//has 2 children 
		BST<DataType>::BinNodePointer xSucc = x->right;      
		parent = x;
		while (xSucc->left != 0) { //���������󵽵�
			parent = xSucc;
			xSucc = xSucc->left;
		}
		x->data = xSucc->data;     
		x = xSucc;   //��������ڵ�
	}
	//��������ڵ㡡��ֻ��һ���ӽڵ��û���ӽڵ�����
	BST<DataType>::BinNodePointer    subtree = x->left; 
	if (subtree == 0)      subtree = x->right;
	if (parent == 0)        myRoot = subtree;//Ҫɾ���Ľ����Ǹ��ڵ�
	else if (parent->left == x)
		parent->left = subtree;
	else parent->right = subtree;
	delete x;
}
template <typename DataType>		//public
inline void BST<DataType>::inorder(ostream& out) const//����������
{
	inorderAux(out, myRoot);
}

template <typename DataType>		//public
inline void BST<DataType>::graph(ostream& out) const
{
	graphAux(out, 0, myRoot);
}
template <typename DataType>		//private
void BST<DataType>::inorderAux(ostream& out, BST<DataType>::BinNodePointer subtreeRoot) const
{//����������
	if (subtreeRoot != 0) {
		inorderAux(out, subtreeRoot->left);
		out << subtreeRoot->data << "  ";
		inorderAux(out, subtreeRoot->right);
	}
}
#include <iomanip>
template <typename DataType>		//private
void BST<DataType>::graphAux(ostream& out, int indent, BST<DataType>::BinNodePointer subtreeRoot) const
{//��ʱ����ת90�ȴ�ӡ
	if (subtreeRoot != 0) {
		graphAux(out, indent + 8, subtreeRoot->right);
		out << setw(indent) << " " << subtreeRoot->data << endl;
		graphAux(out, indent + 8, subtreeRoot->left);
	}
}
//#include"stree.h"
//template<class T>
//class iterator
//{
//	friend class stree<T>;
//	friend class const_iterator;
//public:
//	iterator() {}
//	bool operator== (const iterator& rhs) const;
//	bool operator!= (const iterator& rhs) const;
//	T& operator* () const;
//	iterator& operator++ ();
//	iterator operator++ (int);
//	iterator& operator-- ();
//	iterator operator-- (int);
//private:
//	stnode<T>* nodePtr;
//	stree<T>* tree;
//	iterator(stnode<T>* p, stree<T>* t) : nodePtr(p), tree(t)
//	{}
//};
//template<class T>
//iterator<T>& iterator<T>::operator++ ()//�������˳���ҵ���һ�����
//{
//	stnode<T>* p;
//	if (nodePtr == NULL)
//	{
//		nodePtr = tree->root;	//�Ӹ������
//		if (nodePtr == NULL)
//			throw underflowError("stree iterator operator++ (): tree empty");
//		while (nodePtr->left != NULL)	//�ߵ�����ߵ�
//			nodePtr = nodePtr->left;
//	}
//	else if (nodePtr->right != NULL)	//λ�ڵ�ǰ��������
//	{
//		nodePtr = nodePtr->right;
//		while (nodePtr->left != NULL)
//			nodePtr = nodePtr->left;	//�ߵ�����ߵ�	
//	}
//	else	//�����ҷ�֧�������ϲ�����
//	{
//		p = nodePtr->parent;
//		while (p != NULL && nodePtr == p->right)
//		{
//			nodePtr = p;	//�����������ؼ�������
//			p = p->parent;
//		}
//		nodePtr = p;	//�����������أ��򵽸���	
//	}
//		return *this;
//	}
//template <typename T>
//void removeDuplicates(vector<T>& v)//ɾ���ظ���
//{
//	stree<T> t;
//	stree<T>::iterator treeIter;
//	vector<T>::iterator vectorIter;
//	vectorIter = v.begin();
//	while (vectorIter != v.end())//��vectorԪ�ض����뵽������������
//	{
//		t.insert(*vectorIter);
//		vectorIter++;
//	}
//	v.resize(0);
//	treeIter = t.begin();
//	while (treeIter != t.end()) //�ٰѶ��������������������˳����뵽������
//	{
//		v.push_back(*treeIter);
//		treeIter++;
//	}
//}
