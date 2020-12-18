#include<iostream>
#include<list>
using namespace std;

class node {//存放结点信息
public:
	node(int a,int b):x(a),e(b){}
	int x;//系数
	int e;//指数
};
list<node> merge(list<node> a, list<node> b)//合并两个有序链表
{
	list<node> res;
	list<node>::iterator p1 = a.begin();
	list<node>::iterator p2 = b.begin();
	while (p1 != a.end() && p2 != b.end())
	{
		if (p1->e == p2->e)
		{
			if (p1->x + p2->x != 0)
			{
				node tmp(p1->x + p2->x, p1->e);
				res.push_back(tmp);
			}
			p1++;
			p2++;
		}
		else if (p1->e > p2->e)
		{
			res.push_back(*p1);
			p1++;
		}
		else
		{
			res.push_back(*p2);
			p2++;
		}
	}
	//将没遍历完的接着遍历
	while (p1 != a.end())
	{
		res.push_back(*p1);
		p1++;
	}
	while (p2 != b.end())
	{
		res.push_back(*p2);
		p2++;
	}
	return res;
}
void print(list<node>& a)//打印链表
{
	list<node>::iterator p = a.begin();
	bool flag = true;
	while (p != a.end())
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
		cout << " ";
		p++;
	}
	cout << endl;
}
int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n)
	{
		list<node> a;
		list<node> b;
		int e, x;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> e;
			node tmp(x, e);
			a.push_back(tmp);
		}
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> e;
			node tmp(x, e);
			b.push_back(tmp);
		}

		list<node> res = merge(a, b);
		cout << "f(x) = "; print(a);
		cout << "g(x) = "; print(b);
		cout << "f(x)+g(x) = ";  print(res);
		cout << endl;

		reverse(a.begin(), a.end());
		print(a);
	}
	return 0;
}