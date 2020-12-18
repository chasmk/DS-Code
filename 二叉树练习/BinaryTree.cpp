//#include <iomanip>
//#include<iostream>
//#include<queue>
//#include<stack>
//#include <string> 
//using namespace std;
//
//template<class T>
//class stnode//ÿ�����������ڵ��ָ��
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
///**********�����������************/
//template<typename T>
//void inorderOutput(tnode<T>* t, const string& separator = " ")//�������
//{
//	if (t != NULL)
//	{
//		inorderOutput<T>(t->left, separator);
//		cout << t->nodeValue << separator;
//		inorderOutput<T>(t->right, separator);
//	}
//}
//template<typename T>
//void preorderOutput(tnode<T>* t, const string& separator = " ")//�������
//{
//	if (t != NULL)
//	{
//		cout << t->nodeValue << separator;
//		preorderOutput<T>(t->left, separator);
//		preorderOutput<T>(t->right, separator);
//	}
//}
//template<typename T>
//void postorderOutput(tnode<T>* t, const string& separator = " ")//�������
//{
//	if (t != NULL)
//	{
//		postorderOutput<T>(t->left, separator);
//		postorderOutput<T>(t->right, separator);
//		cout << t->nodeValue << separator;
//	}
//}
///**********�����������************/
//template <typename T>
//void levelorderOutput(tnode<T>* t, const string& separator = " ")
//{
//	queue<tnode<T>*> q;
//	tnode<T>* p;
//	q.push(t);
//	while (!q.empty())//ÿ�������ͷ��㣬�ٰ��������Ҷ������
//	{
//		p = q.front();
//		q.pop();
//		cout << p->nodeValue << separator;
//		if (p->left != NULL)		q.push(p->left);
//		if (p->right != NULL)		q.push(p->right);
//	}
//}
//template <typename T>
//tnode<T>* copyTree(tnode<T>* t)//����һ�Ŷ�����
//{
//	tnode<T>* newLeft, * newRight, * newNode;
//	if (t == NULL)  return NULL;//��Ҷ�ӽڵ�֮��Ϳ�ʼ����
//	newLeft = copyTree(t->left);
//	newRight = copyTree(t->right);
//	newNode = new tnode<T>(t->nodeValue, newLeft, newRight);//�½���㲢����
//	return newNode;
//}
//template <typename T>
//stnode<T>* copyTree(tnode<T>* t,tnode<T>* parent)//����Ϊһ��Ӱ�Ӷ�����
//{
//	stnode<T>* newLeft, * newRight, * newNode,* newParent;
//	if (t == NULL)  return NULL;//��Ҷ�ӽڵ�֮��Ϳ�ʼ����
//	newParent = parent;
//	newLeft = copyTree(t->left,newLeft);
//	newRight = copyTree(t->right,newRight);
//	newNode = new tnodeShadow(t->nodeValue, newLeft, newRight,newParent);//�½���㲢����
//	return newNode;
//}
//template <typename T>
//void deleteTree(tnode<T>* t)//ɾ��һ����
//{
//	if (t != NULL)//����Ҷ�ӽ��ʱ��ֹͣɾ������ʼ����
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
//void countleaf(tnode<T>* t, int& count)//ͳ��Ҷ�ӽ�����
//{
//	if (t != NULL)
//	{
//		if (t->left == NULL && t->right == NULL)//��ǰ������Ҷ��Ӷ�Ϊ�գ�����Ҷ�ӽ��
//			count++;
//		countleaf(t->left, count);
//		countleaf(t->right, count);
//	}
//}
//template<typename T>
//void CountOneChild(tnode<T>* t, int& count)//ͳ�Ƶ����ӽ�����
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
//int CountOneChild(tnode<T>* t)//ͳ�Ƶ����ӽ�����
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
//int depth(tnode<T>* t)//�����������ȣ����ڵ����0�㣩
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
////tnode<T>* CreatingBTree()//����������
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
////ת���ӡ������(��ʱ��ת90�ȴ�ӡ)
////��ӡ˳�������󣬼��������������
//template <typename T>
//void print(tnode<T>* node_ptr, int depth)//depth������������Լ���ӡʱ�Ŀո����
//{
//	if (node_ptr != NULL)//ֹͣ����
//	{
//		print(node_ptr->right, depth + 1);//��ӡ�Ҷ���
//		cout << setw(4 * depth) << "";
//		cout << node_ptr->nodeValue << endl;//��ӡ�Լ�
//		print(node_ptr->left, depth + 1);//��ӡ����ӡ�
//	}
//}
////�����ӡ
////������չ����ͨ���������չ��
//template <typename T>
//tnodeShadow* buildShadowTree(tnode<T>* t, int level, int& column)//����Ӱ����
//{						//level��ֵΪ0, column��ֵΪ10
//	tnodeShadow* newNode = NULL;
//	if (t != NULL) {//�������ҵ�˳�����
//		newNode = new tnodeShadow;//�½����
//		tnodeShadow* newLeft = buildShadowTree(t->left, level + 1, column);//�½�������
//		//��ֵ
//		newNode->left = newLeft;
//		newNode->nodeValueStr = to_string(t->nodeValue);
//		newNode->level = level;
//		newNode->column = column;//���ý�㸳ֵ
//		/*
//			��������ֵ�꣬column+1���ٹ����Լ���+1���ٹ�������������֤һ��һ��
//		*/
//		column++;//��ֵ����ټ�1
//		tnodeShadow* newRight = buildShadowTree(t->right, level + 1, column);//�½�������
//		newNode->right = newRight;
//	}
//	return newNode;
//}
//template<class T>
//void displayTree(tnode<T>* root)//�����ӡ������
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
//	while (!q.empty())//ÿ�������ͷ��㣬�ٰ��������Ҷ������
//	{
//		p = q.front();
//		if (flag)//����ֵ
//		{
//			level = p->level;
//			curlevel = p->level;
//			column = p->column;
//			curcolumn = p->column;
//			flag = false;
//		}
//		//����ǰֵ
//		curlevel = p->level;
//		curcolumn = p->column;
//		if (curlevel != level)//һ����������
//		{
//			level = curlevel;
//			column = p->column;
//			cout << endl;
//		}
//		int len = column;//len�Ǵ˴�����ո����������ֵ���ϴ�column��ֵ
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
////�������������Depth - first search����ʹ��ջ��
////�������������Breadth - first search��ʹ�ö��У�
//template <typename T>
//void Inorder(tnode<T> * t)// ������� �ǵݹ�
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
//		//�����һ·�ߵ���
//		s.pop();//�����ս��
//		if (!s.empty()) {
//			p = s.top();
//			cout << p->nodeValue;//���ջ�����
//			s.pop();//����ջ�����
//			s.push(p->right);//�����Ҷ���ѹ��ջ
//		}
//	}
//	cout << endl;
//}
//template <typename T>
//void Preorder(tnode<T>* t)//ǰ����� �ǵݹ�
//{
//	stack<tnode<T>*> s;
//	tnode<T>* p;
//	s.push(t);//���ڵ���ջ
//
//	while (!s.empty())
//	{
//		while (s.top())
//		{
//			p = s.top();
//			cout << p->nodeValue;
//			s.push(p->left);
//		}
//		s.pop();//����ջ����ָ��
//		if (!s.empty())
//		{
//			p = s.top();
//			s.pop();//��ʱջ��Ԫ�ص�����Ӻ��Լ����Ѿ���������Ե���
//			s.push(p->right);
//		}
//	}
//
//}
//template <typename T>
//void Postorder(tnode<T>* t)//������� �ǵݹ�
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
//		s.pop();//�����ս��
//		if (!s.empty()) 
//		{
//			p = s.top();
//			if (p->right == NULL || p->right == pre) 
//			{//���pû���Һ��ӻ������Һ��Ӹոձ����ʹ�;
//				cout << p->nodeValue;
//				s.pop();
//				pre = p;
//				s.push(NULL);
//			}	//��Ӧǰ���pop����
//			else 
//				s.push(p->right);
//		}
//	}
//}
////�����������Զ�������ڵ�ľ���
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
//		distance = leftH + rightH;//��ǰ������������Ϊ�������߶ȼ����������߶�
//	}
//	//cout << root->nodeValue << "#" << (leftH > rightH ? leftH + 1 : rightH + 1) << endl;
//	return leftH > rightH ? leftH + 1 : rightH + 1;//��ǰ���ڵ�ĸ߶������������ϴ����ټ�1
//}
//int GetFarDistance(tnode<int>* root)
//{
//	int distance = -1;
//	_Height(root, distance);
//	return distance;
//}
//
////�ж�һ�����ǲ�����ȫ������(ÿ�㶼��)
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
//	q.pop();//�ѿ�pop�����������в�Ϊ�վͲ�����ȫ������
//	while (!q.empty())
//	{
//		if (q.front() != NULL) return false;
//		q.pop();
//	}
//	return true;
//}
//
////��������Ŀ��  ���Ƕ���������ڵ���������ֵ
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
////�ж϶������Ƿ���ƽ�����������������ÿһ���ڵ�����������߶�֮���С��2��Ϊƽ���������
//template<class T>
//bool IsBalance(tnode<T>* root, int& depth)  //O(N)
//{
//	if (root == NULL)
//	{
//		depth = 0;
//		return true;
//	}
//	//�ֱ��жϵ�ǰ���ڵ�����������Ƿ�ƽ�⣬����ƽ�⣬ֱ�ӷ���false
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
////������������ת����һ�������˫������
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
////		InThreading(p->lchild);//������������
////		if (p->lchild == NULL)
////		{
////			p->LTag = Thread; p->lchild = pre;
////		}//ǰ������
////		if (pre->rchild == NULL)
////		{
////			pre->RTag = Thread; pre->rchild = p;
////		}//��������
////		pre = p; //����preָ��p��ǰ��
////		InThreading(p->rchild);//������������
////	}
////}
//
//
////��������ҵ ���ϵ���Ŀ
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
//	cout << "������Ϊ��" << GetFarDistance(root) << endl;
//
//	return 0;
//}
