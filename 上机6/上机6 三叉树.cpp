#include<iostream>
#include<queue>
#include<string>
using namespace std;

class tnodeShadow//Ӱ�ӽ����
{
public:
	string nodeValueStr;	// formatted node value
	int level, column;//level����ڼ��㣬column�����������ߵľ���
	tnodeShadow* left, * mid, * right;
	tnodeShadow()
	{}
};

template<class T>
class tnode {//���������
public:
	T nodeValue;
	tnode<T>* left, * mid, * right;
	tnode(const T& item, tnode<T>* lptr = nullptr,tnode<T>* mptr = nullptr, tnode<T>* rptr = nullptr) :
		nodeValue(item), left(lptr),mid(mptr), right(rptr) {}
};

//�����ӡ
//������չ����ͨ���������չ��
template <typename T>
tnodeShadow* buildShadowTree(tnode<T>* t, int level, int& column,int mid=10)//����һ��Ӱ����
{						//level��ֵΪ0, column��ֵΪ10
	tnodeShadow* newNode = NULL;
	if (t != NULL) {//��������ҵ�˳�����

		newNode = new tnodeShadow;//�½����

		tnodeShadow* newLeft = buildShadowTree(t->left, level + 1, column);//�½�������
		newNode->left = newLeft;//��ֵ������

		bool ismid = false;
		if (t->mid)
		{
			ismid = false;
		}
		else ismid = true;
		//����mid���
		tnodeShadow* newMid = buildShadowTree(t->mid, level + 1, column);//�½�������
		newNode->mid = newMid;//��ֵ������

		//������ڵ㣨�Լ���
		newNode->nodeValueStr = to_string(97+t->nodeValue%26);
		//newNode->nodeValueStr = to_string(t->nodeValue);
		newNode->level = level;
		if (newNode->mid)
			newNode->column = newNode->mid->column;//���ý�㸳ֵ
		else
			newNode->column = column;

		/*
			��������ֵ�꣬column+1���ٹ����Լ�����������+1���ٹ�������������֤һ��һ��
		*/
		if (ismid)
			column++; //��ֵ����ټ�1
		tnodeShadow* newRight = buildShadowTree(t->right, level + 1, column);//�½�������
		newNode->right = newRight;
	}
	//if (newNode)cout << newNode->nodeValueStr << "#" << newNode->column << endl;
	return newNode;
}
template<class T>
void displayTree(tnode<T>* root, int num)//��Ӱ���������ӡ������
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
		if (num == 1)//���ַ����
			cout << (char)stoi(p->nodeValueStr);
		else
			cout << p->nodeValueStr;/*<<p->column*/;
		if (p->left != NULL)	q.push(p->left);
		if (p->mid != NULL)	q.push(p->mid);
		if (p->right != NULL)	q.push(p->right);
	}
	cout << endl;
}




template<typename T>
void inorderOutput(tnode<T>* t, const string& separator = " ")//�������
{
	if (t != NULL)
	{
		inorderOutput<T>(t->left, separator);
		cout << t->nodeValue << separator;
		inorderOutput<T>(t->mid, separator);
		inorderOutput<T>(t->right, separator);
	}
}
template<typename T>
void preorderOutput(tnode<T>* t, const string& separator = " ")//�������
{
	if (t != NULL)
	{
		cout << t->nodeValue << separator;
		preorderOutput<T>(t->left, separator);
		preorderOutput<T>(t->mid, separator);
		preorderOutput<T>(t->right, separator);
	}
}
template<typename T>
void postorderOutput(tnode<T>* t, const string& separator = " ")//�������
{
	if (t != NULL)
	{
		postorderOutput<T>(t->left, separator);
		postorderOutput<T>(t->mid, separator);
		postorderOutput<T>(t->right, separator);
		cout << t->nodeValue << separator;
	}
}
/**********����������������������************/
template <typename T>
void levelorderOutput(tnode<T>* t, const string& separator = " ")
{
	queue<tnode<T>* > q;
	tnode<T>* p;
	q.push(t);
	while (!q.empty())//ÿ�������ͷ��㣬�ٰ����������Ҷ������
	{
		p = q.front();
		q.pop();
		cout << p->nodeValue << separator;
		if (p->left != NULL)	q.push(p->left);
		if (p->mid != NULL)	q.push(p->mid);
		if (p->right != NULL)	q.push(p->right);
	}
}
int main()
{
	tnode<int>* p14 = new tnode<int>(14);
	tnode<int>* p15 = new tnode<int>(15);
	tnode<int>* p16 = new tnode<int>(16);
	tnode<int>* p17 = new tnode<int>(17);
	tnode<int>* p18 = new tnode<int>(18);
	tnode<int>* p19 = new tnode<int>(19);
	tnode<int>* p20 = new tnode<int>(20);
	tnode<int>* p21 = new tnode<int>(21);
	tnode<int>* p22 = new tnode<int>(22);
	tnode<int>* p23 = new tnode<int>(23);
	tnode<int>* p24 = new tnode<int>(24);
	tnode<int>* p25 = new tnode<int>(25);
	tnode<int>* p26 = new tnode<int>(26);
	tnode<int>* p27 = new tnode<int>(27);
	tnode<int>* p28 = new tnode<int>(28);
	tnode<int>* p29 = new tnode<int>(29);
	tnode<int>* p30 = new tnode<int>(30);
	tnode<int>* p31 = new tnode<int>(31);
	tnode<int>* p32 = new tnode<int>(32);
	tnode<int>* p33 = new tnode<int>(33);
	tnode<int>* p34 = new tnode<int>(34);
	tnode<int>* p35 = new tnode<int>(35);
	tnode<int>* p36 = new tnode<int>(36);
	tnode<int>* p37 = new tnode<int>(37);
	tnode<int>* p38 = new tnode<int>(38);
	tnode<int>* p39 = new tnode<int>(39);
	tnode<int>* p40 = new tnode<int>(40);
	tnode<int>* p11 = new tnode<int>(11, p32, p33, p34);
	tnode<int>* p12 = new tnode<int>(12, p35, p36, p37);
	tnode<int>* p13 = new tnode<int>(13, p38, p39, p40);
	
	tnode<int>* p5 = new tnode<int>(5, p14, p15, p16);
	tnode<int>* p6 = new tnode<int>(6, p17, p18, p19);
	tnode<int>* p7 = new tnode<int>(7, p20, p21, p22);
	tnode<int>* p8 = new tnode<int>(8, p23, p24, p25);
	tnode<int>* p9 = new tnode<int>(9, p26, p27, p28);
	tnode<int>* p10 = new tnode<int>(10, p29, p30, p31);
	tnode<int>* p2 = new tnode<int>(2,p5,p6,p7);
	tnode<int>* p3 = new tnode<int>(3,p8,p9,p10);
	tnode<int>* p4 = new tnode<int>(4,p11,p12,p13);
	tnode<int>* p1 = new tnode<int>(1, p2, p3, p4);

	/*
			�ȸ�����˳��Ϊ������������������������������

			�и�����˳��Ϊ������������������������������

			�������˳��Ϊ������������������������������
	*/
	cout << "���������";
	preorderOutput(p1);
	cout << "\n���������";
	inorderOutput(p1);
	cout << "\n���������";
	postorderOutput(p1);
	cout << "\n���������";
	levelorderOutput(p1);
	cout << "\n�����ӡ(ת��ΪСд��ĸ)\n";
	displayTree(p1, 1);

	return 0;
}