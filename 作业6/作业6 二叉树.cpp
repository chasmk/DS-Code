#include <iomanip>
#include<iostream>
#include<queue>
#include<stack>
#include <string> 
using namespace std;

class tnodeShadow//Ӱ�ӽ����
{
public:
	string nodeValueStr;	// formatted node value
	int level, column;
	tnodeShadow* left, * right;
	tnodeShadow()
	{}
};


template<class T>
class tnode {//���������ģ����
public:
	T nodeValue;
	tnode<T>* left, * right;

	tnode() {};
	tnode(const T& item, tnode<T>* lptr = nullptr, tnode<T>* rptr = nullptr) :
		nodeValue(item), left(lptr), right(rptr) {}
};


template<typename T>
void preorderOutput(tnode<T>* t, const string& separator = " ")//�������
{
	if (t != NULL)
	{
		cout << t->nodeValue << separator;
		preorderOutput<T>(t->left, separator);
		preorderOutput<T>(t->right, separator);
	}
}

//�����ӡ
//������չ����ͨ���������չ��
template <typename T>
tnodeShadow* buildShadowTree(tnode<T>* t, int level, int& column)//����һ��Ӱ����
{						//level��ֵΪ0, column��ֵΪ10
	tnodeShadow* newNode = NULL;
	if (t != NULL) {//�������ҵ�˳�����
		newNode = new tnodeShadow;//�½����
		tnodeShadow* newLeft = buildShadowTree(t->left, level + 1, column);//�½�������
		//��ֵ
		newNode->left = newLeft;
		newNode->nodeValueStr = to_string(t->nodeValue);
		newNode->level = level;
		newNode->column = column;//���ý�㸳ֵ
		/*
			��������ֵ�꣬column+1���ٹ����Լ���+1���ٹ�������������֤һ��һ��
		*/
		column++;//��ֵ����ټ�1
		tnodeShadow* newRight = buildShadowTree(t->right, level + 1, column);//�½�������
		newNode->right = newRight;
	}
	return newNode;
}
template<class T>
void displayTree(tnode<T>* root,int num)//��Ӱ���������ӡ������
{
	int column = 10;
	tnodeShadow* s = buildShadowTree<T>(root, 0, column);
	queue<tnodeShadow*> q;
	tnodeShadow* p;
	q.push(s);
	int level;
	int curlevel;
	bool flag = true;
	column = 0;//�ϸ�����Ľ���columnֵ
	int curcolumn = 0;//��ǰ����column
	while (!q.empty())//ÿ�������ͷ��㣬�ٰ��������Ҷ������
	{
		p = q.front();
		if (flag)//����ֵ
		{
			level = p->level;
			curlevel = p->level;
			column = p->column;
			curcolumn = p->column;
			flag = false;
		}
		//����ǰֵ
		curlevel = p->level;
		curcolumn = p->column;
		if (curlevel != level)//������һ�£�˵���û�����
		{
			level = curlevel;
			column = p->column;
			cout << endl;
		}
		int len = column;//len�Ǵ˴�����ո����������ֵ���ϴ�column��ֵ
		if (curcolumn > column)
		{
			len = curcolumn - column - 1;
			column = curcolumn;
		}
		q.pop();
		for (int i = 0; i < len; i++)cout << " ";
		if(num==1)//���ַ����
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
void displayPreOrder(tnode<T>* root)//��������ӡ
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
tnode<T>* pre_inTotree(string pre, string in)//��ǰ��������ַ���ת��Ϊһ�Ŷ�����
{
	if (pre.length() == 1)//�ݹ��յ㣬ֻ��һ�����
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
	/*p589 15��*/
	cout << "p589 15��:" << endl;
	string pre = "ADFGHKLPQRWZ";
	string in = "GFHKDLAWRQPZ";
	tnode<char>* r = pre_inTotree<char>(pre, in);
	cout << "�����ӡ��" << endl;
	displayTree(r,1);

	/*p615 20,21��*/
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

	//cout << "�����ӡ��" << endl;
	//displayTree(root,2);//�����ӡ

	//cout << "ǰ�������" << endl;
	//preorderOutput(root);//ǰ�����
	//cout << endl << endl;

	cout << "p615 20��:\n" << endl;
	traceInorder(root);//20��
	cout << endl;

	cout << "\np615 21��:" << endl;
	displayPreOrder(root);//21��

	return 0;
}
