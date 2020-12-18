//#include <iomanip>
//#include<iostream>
//#include<queue>
//#include<stack>
//#include <string> 
//using namespace std;
//
//template<class T>
//class stnode//每个结点包含父节点的指针
//{
//public:
//	T nodeValue;
//	stnode<T>* left, * right, * parent;
//	stnode(const T& item, stnode<T>* lptr = NULL,stnode<T>* rptr = NULL, stnode<T>* pptr = NULL) :
//		nodeValue(item), left(lptr), right(rptr), parent(pptr) {}
//};
//
//class tnodeShadow
//{
//public:
//	string nodeValueStr;	// formatted node value
//	int level, column;
//	tnodeShadow* left, * right;
//	tnodeShadow()
//	{}
//};
//
//
//template<class T>
//class tnode {
//public:
//	T nodeValue;
//	tnode<T>* left, * right;
//
//	tnode() {};
//	tnode(const T& item, tnode<T>* lptr = nullptr, tnode<T>* rptr = nullptr) :
//		nodeValue(item), left(lptr), right(rptr){}
//};
//tnode<char>* buildTree(int n)
//{
//	tnode<char>* root=nullptr, * b, * c, * d, * e, * f, * g, * h, * i;
//	switch (n)
//	{
//	case 0:
//		d = new tnode<char>('D');
//		e = new tnode<char>('E');
//		b = new tnode<char>('B', (tnode<char>*)NULL, d);
//		c = new tnode<char>('C', e, (tnode<char>*)NULL);
//		root = new tnode<char>('A', b, c);
//		break;
//		/*
//		         A 
//		      B     C
//			   D   E
//		*/
//	case 1:
//		g = new tnode<char>('G');
//		h = new tnode<char>('H');
//		i = new tnode<char>('I');
//		d = new tnode<char>('D');
//		e = new tnode<char>('E', g, (tnode<char>*)NULL);
//		f = new tnode<char>('F', h, i);
//		b = new tnode<char>('B', d, e);
//		c = new tnode<char>('C', (tnode<char>*)NULL, f);
//		root = new tnode<char>('A', b, c);
//		break;
//		/*
//						A
//				B				C
//			D		E				F
//			      G                H  I
//		*/						   
//	case 2:
//		g = new tnode<char>('G');
//		h = new tnode<char>('H');
//		i = new tnode<char>('I');
//		d = new tnode<char>('D', (tnode<char>*)NULL, g);
//		e = new tnode<char>('E', h, i);
//		f = new tnode<char>('F');
//		b = new tnode<char>('B', d, (tnode<char>*)NULL);
//		c = new tnode<char>('C', e, f);
//		root = new tnode<char>('A', b, c);
//		break;
//		/*
//							A
//					B				C
//				D				E		F
//				 G			   H I
//		*/
//	}
//	return root;
//}
///**********深度优先搜索************/
//template<typename T>
//void inorderOutput(tnode<T>* t, const string& separator = " ")//中序遍历
//{
//	if (t != NULL)
//	{
//		inorderOutput<T>(t->left, separator);
//		cout << t->nodeValue << separator;
//		inorderOutput<T>(t->right, separator);
//	}
//}
//template<typename T>
//void preorderOutput(tnode<T>* t, const string& separator = " ")//先序遍历
//{
//	if (t != NULL)
//	{
//		cout << t->nodeValue << separator;
//		preorderOutput<T>(t->left, separator);
//		preorderOutput<T>(t->right, separator);
//	}
//}
//template<typename T>
//void postorderOutput(tnode<T>* t, const string& separator = " ")//后序遍历
//{
//	if (t != NULL)
//	{
//		postorderOutput<T>(t->left, separator);
//		postorderOutput<T>(t->right, separator);
//		cout << t->nodeValue << separator;
//	}
//}
///**********广度优先搜索************/
//template <typename T>
//void levelorderOutput(tnode<T>* t, const string& separator = " ")
//{
//	queue<tnode<T>*> q;
//	tnode<T>* p;
//	q.push(t);
//	while (!q.empty())//每次输出队头结点，再把它的左右儿子入队
//	{
//		p = q.front();
//		q.pop();
//		cout << p->nodeValue << separator;
//		if (p->left != NULL)		q.push(p->left);
//		if (p->right != NULL)		q.push(p->right);
//	}
//}
//template <typename T>
//tnode<T>* copyTree(tnode<T>* t)//复制一颗二叉树
//{
//	tnode<T>* newLeft, * newRight, * newNode;
//	if (t == NULL)  return NULL;//到叶子节点之后就开始返回
//	newLeft = copyTree(t->left);
//	newRight = copyTree(t->right);
//	newNode = new tnode<T>(t->nodeValue, newLeft, newRight);//新建结点并返回
//	return newNode;
//}
//template <typename T>
//stnode<T>* copyTree(tnode<T>* t,tnode<T>* parent)//复制为一颗影子二叉树
//{
//	stnode<T>* newLeft, * newRight, * newNode,* newParent;
//	if (t == NULL)  return NULL;//到叶子节点之后就开始返回
//	newParent = parent;
//	newLeft = copyTree(t->left,newLeft);
//	newRight = copyTree(t->right,newRight);
//	newNode = new tnodeShadow(t->nodeValue, newLeft, newRight,newParent);//新建结点并返回
//	return newNode;
//}
//template <typename T>
//void deleteTree(tnode<T>* t)//删除一颗树
//{
//	if (t != NULL)//到达叶子结点时就停止删除，开始返回
//	{
//		deleteTree(t->left);
//		deleteTree(t->right);
//		delete t;
//	}
//}
//template <typename T>
//void clearTree(tnode<T>*& t)
//{
//	deleteTree(t);
//	t = NULL;
//}
//template<typename T>
//void countleaf(tnode<T>* t, int& count)//统计叶子结点个数
//{
//	if (t != NULL)
//	{
//		if (t->left == NULL && t->right == NULL)//当前结点左右儿子都为空，则是叶子结点
//			count++;
//		countleaf(t->left, count);
//		countleaf(t->right, count);
//	}
//}
//template<typename T>
//void CountOneChild(tnode<T>* t, int& count)//统计单儿子结点个数
//{
//	if (t != NULL)
//	{
//		if ((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL))
//			count++;
//		CountOneChild(t->left, count);
//		CountOneChild(t->right, count);
//	}
//}
//template<typename T>
//int CountOneChild(tnode<T>* t)//统计单儿子结点个数
//{
//	int count = 0;
//	if (t != NULL)
//	{
//		if ((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL))
//			count++;
//		int countleft = CountOneChild(t->left);
//		int countright = CountOneChild(t->right);
//		return count + countleft + countright;
//	}
//	return count;
//}
//template<typename T>
//int depth(tnode<T>* t)//计算二叉树深度（根节点算第0层）
//{
//	int depthval;
//	if (t == NULL)depthval = -1;
//	else {
//		int depthleft = depth(t->left);
//		int depthright = depth(t->right);
//		depthval = 1 +(depthleft > depthright ? depthleft : depthright);
//	}
//	return depthval;
//}
///*
//	ABD--E--C--
//			A
//		B		C
//	  D   E
//*/
////template<typename T>
////tnode<T>* CreatingBTree()//创建二叉树
////{
////	tnode<T>* t;
////	char ch;
////	cin >> ch;
////	if (ch == ' ')t = NULL;
////	else {
////		t = new tnode<char>(ch);
////		t->left = CreatingBTree();
////		t->right = CreatingBTree();
////	}
////	return t;
////}
////转向打印二叉树(逆时针转90度打印)
////打印顺序：右中左，即中序遍历的逆序
//template <typename T>
//void print(tnode<T>* node_ptr, int depth)//depth代表结点层数，以及打印时的空格距离
//{
//	if (node_ptr != NULL)//停止条件
//	{
//		print(node_ptr->right, depth + 1);//打印右儿子
//		cout << setw(4 * depth) << "";
//		cout << node_ptr->nodeValue << endl;//打印自己
//		print(node_ptr->left, depth + 1);//打印左儿子。
//	}
//}
////正向打印
////从左到右展开，通过步进逐次展开
//template <typename T>
//tnodeShadow* buildShadowTree(tnode<T>* t, int level, int& column)//建立影子树
//{						//level初值为0, column初值为10
//	tnodeShadow* newNode = NULL;
//	if (t != NULL) {//按左中右的顺序遍历
//		newNode = new tnodeShadow;//新建结点
//		tnodeShadow* newLeft = buildShadowTree(t->left, level + 1, column);//新建左子树
//		//赋值
//		newNode->left = newLeft;
//		newNode->nodeValueStr = to_string(t->nodeValue);
//		newNode->level = level;
//		newNode->column = column;//给该结点赋值
//		/*
//			左子树赋值完，column+1，再构造自己，+1，再构造右子树，保证一人一列
//		*/
//		column++;//赋值完后再加1
//		tnodeShadow* newRight = buildShadowTree(t->right, level + 1, column);//新建右子树
//		newNode->right = newRight;
//	}
//	return newNode;
//}
//template<class T>
//void displayTree(tnode<T>* root)//正向打印二叉树
//{
//	int column = 10;
//	tnodeShadow* s = buildShadowTree<T>(root, 0, column);
//	queue<tnodeShadow*> q;
//	tnodeShadow* p;
//	q.push(s);
//	int level;
//	int curlevel;
//	bool flag = true;
//	column = 0;
//	int curcolumn = 0;
//	while (!q.empty())//每次输出队头结点，再把它的左右儿子入队
//	{
//		p = q.front();
//		if (flag)//赋初值
//		{
//			level = p->level;
//			curlevel = p->level;
//			column = p->column;
//			curcolumn = p->column;
//			flag = false;
//		}
//		//赋当前值
//		curlevel = p->level;
//		curcolumn = p->column;
//		if (curlevel != level)//一行输出完后换行
//		{
//			level = curlevel;
//			column = p->column;
//			cout << endl;
//		}
//		int len = column;//len是此次输出空格的数量，初值是上次column的值
//		if (curcolumn > column)
//		{
//			len = curcolumn - column - 1;
//			column = curcolumn;
//		}
//		q.pop();
//		for (int i = 0; i < len; i++)cout << " ";
//		cout << p->nodeValueStr/*<<p->column*/;
//		if (p->left != NULL)	q.push(p->left);
//		if (p->right != NULL)	q.push(p->right);
//	}
//	cout << endl;
//}
////深度优先搜索：Depth - first search　（使用栈）
////广度优先搜索：Breadth - first search（使用队列）
//template <typename T>
//void Inorder(tnode<T> * t)// 中序遍历 非递归
//{
//	stack<tnode<T>*> s;
//	tnode<T>* p;
//	s.push(t);
//	while (!s.empty()) 
//	{
//		while (s.top()) 
//		{
//			p = s.top(); 
//			s.push(p->left); 
//		}
//		//左儿子一路走到底
//		s.pop();//弹出空结点
//		if (!s.empty()) {
//			p = s.top();
//			cout << p->nodeValue;//输出栈顶结点
//			s.pop();//弹出栈顶结点
//			s.push(p->right);//把其右儿子压入栈
//		}
//	}
//	cout << endl;
//}
//template <typename T>
//void Preorder(tnode<T>* t)//前序遍历 非递归
//{
//	stack<tnode<T>*> s;
//	tnode<T>* p;
//	s.push(t);//根节点入栈
//
//	while (!s.empty())
//	{
//		while (s.top())
//		{
//			p = s.top();
//			cout << p->nodeValue;
//			s.push(p->left);
//		}
//		s.pop();//弹出栈顶空指针
//		if (!s.empty())
//		{
//			p = s.top();
//			s.pop();//此时栈顶元素的左儿子和自己都已经输出，所以弹出
//			s.push(p->right);
//		}
//	}
//
//}
//template <typename T>
//void Postorder(tnode<T>* t)//后序遍历 非递归
//{
//	stack<tnode<T>*> s;
//	tnode<T>* p, * pre = NULL; 	
//	s.push(t);
//
//	while (!s.empty()) 
//	{
//		while (s.top()) 
//		{ 
//			p = s.top(); 	
//			s.push(p->left);
//		}
//		s.pop();//弹出空结点
//		if (!s.empty()) 
//		{
//			p = s.top();
//			if (p->right == NULL || p->right == pre) 
//			{//如果p没有右孩子或者其右孩子刚刚被访问过;
//				cout << p->nodeValue;
//				s.pop();
//				pre = p;
//				s.push(NULL);
//			}	//对应前面的pop操作
//			else 
//				s.push(p->right);
//		}
//	}
//}
////求二叉树中最远的两个节点的距离
//int _Height(tnode<int>* root, int& distance)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int leftH = _Height(root->left, distance);
//	int rightH = _Height(root->right, distance);
//	if (leftH + rightH > distance)
//	{
//		distance = leftH + rightH;//当前根结点的最大距离为左子树高度加上右子树高度
//	}
//	//cout << root->nodeValue << "#" << (leftH > rightH ? leftH + 1 : rightH + 1) << endl;
//	return leftH > rightH ? leftH + 1 : rightH + 1;//当前根节点的高度是左右子树较大者再加1
//}
//int GetFarDistance(tnode<int>* root)
//{
//	int distance = -1;
//	_Height(root, distance);
//	return distance;
//}
//
////判断一棵树是不是完全二叉树(每层都满)
//template<class T>
//bool IsCompleteTree(tnode<T>* pRoot)
//{
//	if (pRoot == NULL) return false;
//	queue<tnode<T>*> q;
//	q.push(pRoot);
//	tnode<T>* pCur = q.front();
//	while (pCur != NULL)
//	{
//		q.pop();
//		q.push(pCur->left);
//		q.push(pCur->right);
//		pCur = q.front();
//	}
//	q.pop();//把空pop出来，若队列不为空就不是完全二叉树
//	while (!q.empty())
//	{
//		if (q.front() != NULL) return false;
//		q.pop();
//	}
//	return true;
//}
//
////求二叉树的宽度  就是二叉树各层节点个数的最大值
//template<class T>
//int Width(tnode<T>* root)
//{
//	queue<tnode<T>*> q;
//	if (root) q.push(root);
//	int maxwidth = 1;
//	while (!q.empty())
//	{
//		int length = q.size();
//		while (length-- > 0)
//		{
//			tnode<T>* front = q.front();
//			q.pop();
//			if (front->_left)      q.push(front->_left);
//			if (front->_right)    q.push(front->_right);
//		}
//		maxwidth = maxwidth > q.size() ? maxwidth : q.size();
//	}
//	return maxwidth;
//}
//
////判断二叉树是否是平衡二叉树（二叉树中每一个节点的左右子树高度之差均小于2即为平衡二叉树）
//template<class T>
//bool IsBalance(tnode<T>* root, int& depth)  //O(N)
//{
//	if (root == NULL)
//	{
//		depth = 0;
//		return true;
//	}
//	//分别判断当前根节点的左右子树是否平衡，若不平衡，直接返回false
//	int leftdepth = 0;
//	if (IsBalance(root->_left, leftdepth) == false)
//		return false;
//	int rightdepth = 0;
//	if (IsBalance(root->_right, rightdepth) == false)
//		return false;
//
//	depth = rightdepth > leftdepth ? rightdepth + 1 : leftdepth + 1;
//	return abs(leftdepth - rightdepth) < 2;
//}
////将二叉搜索树转换成一个排序的双向链表
//template<class T>
//void  ToList(tnode<T>* cur, tnode<T>*& prev)
//{
//	if (cur == NULL)
//		return;
//
//	ToList(cur->left, prev);
//
//	cur->left = prev;
//
//	if (prev)
//		prev->right = cur;
//	prev = cur;
//	ToList(cur->right, prev);
//}
//
//
//
//
////void InThreading(BiThrTree p)
////{
////	if (p)
////	{
////		InThreading(p->lchild);//左子树线索化
////		if (p->lchild == NULL)
////		{
////			p->LTag = Thread; p->lchild = pre;
////		}//前驱线索
////		if (pre->rchild == NULL)
////		{
////			pre->RTag = Thread; pre->rchild = p;
////		}//后续线索
////		pre = p; //保持pre指向p的前驱
////		InThreading(p->rchild);//右子树线索化
////	}
////}
//
//
////第六次作业 书上的题目
//template<class T>
//void traceInorder(tnode<T>* root)
//{
//	if (root != nullptr)
//	{
//		cout << "L";
//		traceInorder(root->left);
//		cout << "/" << root->nodeValue << endl;
//		cout << "R";
//		traceInorder(root->right);
//	}
//	cout << "U";
//}
//template<class T>
//void displayPreOrder(tnode<T>* root)
//{
//	cout << "\tNode.Data\tLChild.Data\tRChild.Data" << endl;
//	cout << "\t=========\t===========\t===========" << endl;
//	stack<tnode<T>*> s;
//	tnode<T>* p;
//	s.push(root);
//
//	while (!s.empty())
//	{
//		cout << "\t";
//		p = s.top();
//		s.pop();
//		cout << p->nodeValue << "\t\t";
//
//		if (p->right)
//		{
//			s.push(p->right);
//		}
//		if (p->left)
//		{
//			s.push(p->left);
//		}
//
//		if (p->left)
//		{
//			cout << p->left->nodeValue << "\t\t";
//		}
//		else cout << "-\t\t";
//		if (p->right)
//		{
//			cout << p->right->nodeValue << "\t\t";
//		}
//		else cout << "-\t\t";
//
//		
//
//		cout << endl;
//	}
//
//
//}
//int main()
//{
//	//tnode<char>* root1, * root2;
//	//root1 = buildTree(2);
//	//cout << "Original tree (Tree 2)" << endl;
//	//print(root1, 0);
//	//cout << endl << endl;
//	//root2 = copyTree(root1);
//	//cout << "Copy of Tree 2" << endl;
//	//print(root2, 0);
//	//cout << endl;
//	//displayTree(root1);
//	//displayTree(root2);
//	//Inorder(root1);
//	//clearTree(root1);
//	//clearTree(root2);
//
//
//	tnode<int>* p3 = new tnode<int>(3);
//	tnode<int>* p8 = new tnode<int>(8);
//	tnode<int>* p24 = new tnode<int>(24);
//	tnode<int>* p60 = new tnode<int>(60);
//	tnode<int>* p91 = new tnode<int>(91);
//	tnode<int>* p37 = new tnode<int>(37, p24, (tnode<int>*)NULL);
//	tnode<int>* p58 = new tnode<int>(58, (tnode<int>*)NULL, p60);
//	tnode<int>* p5 = new tnode<int>(5, p3, p8);
//	tnode<int>* p20 = new tnode<int>(20, (tnode<int>*)NULL, p37);
//	tnode<int>* p15 = new tnode<int>(15, p5, p20);
//	tnode<int> * p62 = new tnode<int>(62, p58, p91);
//	tnode<int>* root = new tnode<int>(50, p15, p62);
//	Inorder(root);
//	displayTree(root);
//	Preorder(root);
//
//	traceInorder(root); 
//	cout << endl;
//	displayPreOrder(root);
//
//	cout << "最大距离为：" << GetFarDistance(root) << endl;
//
//	return 0;
//}
