#include<iostream>
using namespace std;

template <typename DataType>
class BST {//二叉搜索树模板类
public:  BST();
	  bool empty() const;
	  bool search(const DataType& item) const;
	  void insert(const DataType& item);
	  void remove(const DataType& item);
	  void inorder(ostream& out) const;
	  void graph(ostream& out) const;
private:
	class BinNode { //二叉搜索树 结点
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

	BinNodePointer myRoot;//根结点指针
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
	while (!found && locptr != 0) {//只要还没找到且没有搜索到底，就继续循环
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
inline void BST<DataType>::insert(const DataType& item)//插入一个结点
{
	BST<DataType>::BinNodePointer locptr = myRoot, parent = 0;
	bool found = false;
	while (!found && locptr != 0) {//先在书中查找待插入元素
		parent = locptr;//parent记录下当前位置
		if (item < locptr->data) locptr = locptr->left;
		else if (locptr->data < item)  locptr = locptr->right;
		else    found = true;
	}
	if (!found) { //如果没找到再插入
		locptr = new BST<DataType>::BinNode(item);
		if (parent == 0) myRoot = locptr;
		else if (item < parent->data) parent->left = locptr;
		else  parent->right = locptr;
	}
	else
		cout << "Item already in the tree\n";
}
template <typename DataType>		//public
void BST<DataType>::remove(const DataType& item)//删除一个结点
{
	bool found;
	BST<DataType>::BinNodePointer  x, parent;
	search2(item, found, x, parent);//先查找该结点是否存在
	if (!found) {
		cout << "Item not in the BST\n";
		return;
	}
	if (x->left != 0 && x->right != 0) {//has 2 children 
		BST<DataType>::BinNodePointer xSucc = x->right;      
		parent = x;
		while (xSucc->left != 0) { //右子树向左到底
			parent = xSucc;
			xSucc = xSucc->left;
		}
		x->data = xSucc->data;     
		x = xSucc;   //到达替代节点
	}
	//处理替代节点　及只有一个子节点或没有子节点的情况
	BST<DataType>::BinNodePointer    subtree = x->left; 
	if (subtree == 0)      subtree = x->right;
	if (parent == 0)        myRoot = subtree;//要删除的结点就是根节点
	else if (parent->left == x)
		parent->left = subtree;
	else parent->right = subtree;
	delete x;
}
template <typename DataType>		//public
inline void BST<DataType>::inorder(ostream& out) const//中序遍历输出
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
{//中序遍历输出
	if (subtreeRoot != 0) {
		inorderAux(out, subtreeRoot->left);
		out << subtreeRoot->data << "  ";
		inorderAux(out, subtreeRoot->right);
	}
}
#include <iomanip>
template <typename DataType>		//private
void BST<DataType>::graphAux(ostream& out, int indent, BST<DataType>::BinNodePointer subtreeRoot) const
{//逆时针旋转90度打印
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
//iterator<T>& iterator<T>::operator++ ()//中序遍历顺序找到下一个结点
//{
//	stnode<T>* p;
//	if (nodePtr == NULL)
//	{
//		nodePtr = tree->root;	//从根点进入
//		if (nodePtr == NULL)
//			throw underflowError("stree iterator operator++ (): tree empty");
//		while (nodePtr->left != NULL)	//走到最左边点
//			nodePtr = nodePtr->left;
//	}
//	else if (nodePtr->right != NULL)	//位于当前子树根点
//	{
//		nodePtr = nodePtr->right;
//		while (nodePtr->left != NULL)
//			nodePtr = nodePtr->left;	//走到最左边点	
//	}
//	else	//若无右分支，返回上层子树
//	{
//		p = nodePtr->parent;
//		while (p != NULL && nodePtr == p->right)
//		{
//			nodePtr = p;	//从右子树返回继续上行
//			p = p->parent;
//		}
//		nodePtr = p;	//从左子树返回，则到根点	
//	}
//		return *this;
//	}
//template <typename T>
//void removeDuplicates(vector<T>& v)//删除重复项
//{
//	stree<T> t;
//	stree<T>::iterator treeIter;
//	vector<T>::iterator vectorIter;
//	vectorIter = v.begin();
//	while (vectorIter != v.end())//把vector元素都插入到二叉搜索树中
//	{
//		t.insert(*vectorIter);
//		vectorIter++;
//	}
//	v.resize(0);
//	treeIter = t.begin();
//	while (treeIter != t.end()) //再把二叉搜索树按中序遍历的顺序插入到向量中
//	{
//		v.push_back(*treeIter);
//		treeIter++;
//	}
//}
