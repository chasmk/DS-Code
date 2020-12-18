/*#include<iostream>
using namespace std;
template<typename T>
class dnode {
public:
	T x;//系数
	T e;//指数
	dnode<T>* prev;
	dnode<T>* next;
	dnode()//构造函数
	{
		prev = this;
		next = this;
	}
	dnode(const T& X, const T& E) :x(X), e(E) //构造函数
	{
		prev = this;
		next = this;
	}
	
	template<typename T>
	dnode<T>* insert(dnode<T>* curr, const T& item1, const T& item2 )//插入到curr结点前
	{
		dnode<T>* newNode, * prevNode;
		newNode = new dnode<T>(item1,item2);
		prevNode = curr->prev;
		newNode->prev = prevNode;
		newNode->next = curr;
		prevNode->next = newNode;
		curr->prev = newNode;
		return newNode;
	}
	template<typename T>
	void* erase(dnode<T>* curr)//删除curr结点
	{
		if (curr->next == curr)return;
		dnode<T>* prevNode = curr->prev,* succNode = curr->next;
		prevNode->next = succNode;
		succNode->prev = prevNode;
		delete curr;
	}
	template<typename T>
	void* push_front(dnode<T>* header, const T& item1, const T& item2)//插入到header前
	{
		insert(header->next, item1,item2);
	}
	template<typename T>
	void* pop_front(dnode<T>* header)//删除header前面一个结点
	{
		erase(header->next);
	}
	template<typename T>
	dnode<T>* front(dnode<T>* header)//返回header的第一个结点（正序）
	{
		return header->next;
	}
	template<typename T>
	void push_back(dnode<T>* header, const T& item1, const T& item2)//插入到header后
	{
		insert(header, item1, item2);
	}
	template<typename T>
	void* pop_back(dnode<T>* header)//删除header前面的结点
	{
		erase(header->prev);
	}
	template<typename T>
	dnode<T>* back(dnode<T>* header)//返回header前面的结点
	{
		return header->prev;
	}
};
template<typename T>
void writeDLinkedList(dnode<T>* header, const string& separator = " ")//打印链表
{
	dnode<T>* p = header->next;
	bool flag = true;
	while (p != header)
	{
		if (flag)
		{
			flag = false;
		}
		else
		{
			if (p->x > 0)cout << "+ ";
			else cout << "- ";
		}
		cout << (p->x > 0 ? p->x : 0 - p->x);
		if (p->e != 0)cout << "x";
		if (p->e < 0)
			cout << "^(" << p->e << ")";
		else if (p->e > 1)
			cout << "^" << p->e;
		cout << separator;

		p = p->next;
	}
	cout << endl;
}
template<typename T>
dnode<T>* merge(dnode<T>* a, dnode<T>* b)//合并链表
{
	dnode<T>* res = new dnode<int>;
	dnode<T>* p1 = a->next;
	dnode<T>* p2 = b->next;
	while (p1 != a && p2 != b)
	{
		if (p1->e == p2->e)
		{
			if(p1->x + p2->x!=0)
				res->push_back(res, p1->x + p2->x, p1->e);
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->e > p2->e)
		{
			res->push_back(res,p1->x, p1->e);
			p1 = p1->next;
		}
		else
		{
			res->push_back(res,p2->x, p2->e);
			p2 = p2->next;
		}
	}
	if (p1 != a)
	{
		while (p1 != a)
		{
			res->push_back(res, p1->x, p1->e);
			p1 = p1->next;
		}
	}
	if (p2 != b)
	{
		while (p2 != b)
		{
			res->push_back(res, p2->x, p2->e);
			p2 = p2->next;
		}
	}
	return res;
}*/
/*int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n)
	{
		dnode<int>* f = new dnode<int>();
		dnode<int>* g = new dnode<int>();
		int e, x;
		for (int i = 0; i < n ; i++)
		{
			cin >> x >> e;
			f->push_back(f, x, e);
		}
		cin >> n;
		for (int i = 0; i < n ; i++)
		{
			cin >> x >> e;
			g->push_back(g, x, e);
		}
		cout << "f(x) = ";
		writeDLinkedList(f);
		cout << "g(x) = ";
		writeDLinkedList(g);
		dnode<int>* res = merge(f, g);
		cout << "f(x)+g(x) = ";
		writeDLinkedList(res);
		cout << endl;
	}
	return 0;
}*/