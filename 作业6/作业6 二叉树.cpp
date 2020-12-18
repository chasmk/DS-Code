#include <iomanip>
#include<iostream>
#include<queue>
#include<stack>
#include <string> 
using namespace std;

class tnodeShadow//影子结点类
{
public:
	string nodeValueStr;	// formatted node value
	int level, column;
	tnodeShadow* left, * right;
	tnodeShadow()
	{}
};


template<class T>
class tnode {//二叉树结点模板类
public:
	T nodeValue;
	tnode<T>* left, * right;

	tnode() {};
	tnode(const T& item, tnode<T>* lptr = nullptr, tnode<T>* rptr = nullptr) :
		nodeValue(item), left(lptr), right(rptr) {}
};


template<typename T>
void preorderOutput(tnode<T>* t, const string& separator = " ")//先序遍历
{
	if (t != NULL)
	{
		cout << t->nodeValue << separator;
		preorderOutput<T>(t->left, separator);
		preorderOutput<T>(t->right, separator);
	}
}

//正向打印
//从左到右展开，通过步进逐次展开
template <typename T>
tnodeShadow* buildShadowTree(tnode<T>* t, int level, int& column)//创建一个影子树
{						//level初值为0, column初值为10
	tnodeShadow* newNode = NULL;
	if (t != NULL) {//按左中右的顺序遍历
		newNode = new tnodeShadow;//新建结点
		tnodeShadow* newLeft = buildShadowTree(t->left, level + 1, column);//新建左子树
		//赋值
		newNode->left = newLeft;
		newNode->nodeValueStr = to_string(t->nodeValue);
		newNode->level = level;
		newNode->column = column;//给该结点赋值
		/*
			左子树赋值完，column+1，再构造自己，+1，再构造右子树，保证一人一列
		*/
		column++;//赋值完后再加1
		tnodeShadow* newRight = buildShadowTree(t->right, level + 1, column);//新建右子树
		newNode->right = newRight;
	}
	return newNode;
}
template<class T>
void displayTree(tnode<T>* root,int num)//由影子树正向打印二叉树
{
	int column = 10;
	tnodeShadow* s = buildShadowTree<T>(root, 0, column);
	queue<tnodeShadow*> q;
	tnodeShadow* p;
	q.push(s);
	int level;
	int curlevel;
	bool flag = true;
	column = 0;
	int curcolumn = 0;
	while (!q.empty())//每次输出队头结点，再把它的左右儿子入队
	{
		p = q.front();
		if (flag)//赋初值
		{
			level = p->level;
			curlevel = p->level;
			column = p->column;
			curcolumn = p->column;
			flag = false;
		}
		//赋当前值
		curlevel = p->level;
		curcolumn = p->column;
		if (curlevel != level)//一行输出完后换行
		{
			level = curlevel;
			column = p->column;
			cout << endl;
		}
		int len = column;//len是此次输出空格的数量，初值是上次column的值
		if (curcolumn > column)
		{
			len = curcolumn - column - 1;
			column = curcolumn;
		}
		q.pop();
		for (int i = 0; i < len; i++)cout << " ";
		if(num==1)
			cout << (char)stoi(p->nodeValueStr);
		else
		cout << p->nodeValueStr;/*<<p->column*/;
		if (p->left != NULL)	q.push(p->left);
		if (p->right != NULL)	q.push(p->right);
	}
	cout << endl;
}


template<class T>
void traceInorder(tnode<T>* root)
{
	if (root != nullptr)
	{
		cout << "L";
		traceInorder(root->left);
		cout << "/" << root->nodeValue << endl;
		cout << "R";
		traceInorder(root->right);
	}
	cout << "U";
}
template<class T>
void displayPreOrder(tnode<T>* root)//先序次序打印
{
	cout << "\tNode.Data\tLChild.Data\tRChild.Data" << endl;
	cout << "\t=========\t===========\t===========" << endl;
	stack<tnode<T>*> s;
	tnode<T>* p;
	s.push(root);

	while (!s.empty())
	{
		cout << "\t";
		p = s.top();
		s.pop();
		cout << p->nodeValue << "\t\t";

		if (p->right)
		{
			s.push(p->right);
		}
		if (p->left)
		{
			s.push(p->left);
		}

		if (p->left)
		{
			cout << p->left->nodeValue << "\t\t";
		}
		else cout << "-\t\t";
		if (p->right)
		{
			cout << p->right->nodeValue << "\t\t";
		}
		else cout << "-\t\t";
		cout << endl;
	}
}
template<class T>
tnode<T>* pre_inTotree(string pre, string in)//由前序和中序字符串转换为一颗二叉树
{
	if (pre.length() == 1)//递归终点，只有一个结点
	{
		return new tnode<T>(pre[0], nullptr, nullptr);
	}

	int mid = in.find(pre[0]);

	tnode<T>* root,*left,*right;
	if (mid != 0)
		left = pre_inTotree<T>(pre.substr(1, mid), in.substr(0, mid));
	else left = nullptr;
	if (mid != in.length() - 1)
		right = pre_inTotree<T>(pre.substr(mid + 1), in.substr(mid + 1));
	else right = nullptr;

	root = new tnode<T>(pre[0], left, right);
	return root;
}

int main()
{
	/*p589 15题*/
	cout << "p589 15题:" << endl;
	string pre = "ADFGHKLPQRWZ";
	string in = "GFHKDLAWRQPZ";
	tnode<char>* r = pre_inTotree<char>(pre, in);
	cout << "正序打印：" << endl;
	displayTree(r,1);

	/*p615 20,21题*/
	tnode<int>* p3 = new tnode<int>(3);
	tnode<int>* p8 = new tnode<int>(8);
	tnode<int>* p24 = new tnode<int>(24);
	tnode<int>* p60 = new tnode<int>(60);
	tnode<int>* p91 = new tnode<int>(91);
	tnode<int>* p37 = new tnode<int>(37, p24, (tnode<int>*)NULL);
	tnode<int>* p58 = new tnode<int>(58, (tnode<int>*)NULL, p60);
	tnode<int>* p5 = new tnode<int>(5, p3, p8);
	tnode<int>* p20 = new tnode<int>(20, (tnode<int>*)NULL, p37);
	tnode<int>* p15 = new tnode<int>(15, p5, p20);
	tnode<int>* p62 = new tnode<int>(62, p58, p91);
	tnode<int>* root = new tnode<int>(50, p15, p62);

	//cout << "正序打印：" << endl;
	//displayTree(root,2);//正序打印

	//cout << "前序遍历：" << endl;
	//preorderOutput(root);//前序遍历
	//cout << endl << endl;

	cout << "p615 20题:\n" << endl;
	traceInorder(root);//20题
	cout << endl;

	cout << "\np615 21题:" << endl;
	displayPreOrder(root);//21题

	return 0;
}
