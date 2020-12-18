#include<iostream>
using namespace std;

template<class T>
class node {
public:
	T data;//结点数据
	node<T>* next; //next指针

	//结点的构造函数
	node() :next(nullptr) {}
	node(const T& item, node<T>* nextnode = nullptr) :data(item), next(nextnode) {}
};
template<class T>
void InsertSort(node<T>*& a)//插入排序(函数内直接修改头节点指针)
{
	if (a == nullptr)return;
	node<T>* front = a;
	node<T>* cur = front->next;//无序区的第一个元素
	node<T>* curs = nullptr;//保存cur的后继结点位置
	front->next = nullptr;//nullptr作为初始有序区队尾
	while (cur != nullptr)
	{
		curs = cur->next;//curs先保存好cur的next
		node<T>* tmp = front;//用来遍历有序区
		node<T>* pre = nullptr;//保存tmp的前驱结点
		while (cur->data > tmp->data)//查找插入位置
		{
			pre = tmp;
			tmp = tmp->next;
			if (tmp == nullptr)break;
		}
		if (tmp == front)//插入在队首
		{
			cur->next = front;
			front = cur;
		}
		else//插在队中或队尾
		{
			cur->next = tmp;
			pre->next = cur;
		}
		cur = curs;//cur后移一位
	}
	a = front;//修改队首的值
}
template<class T>
node<T>* InsertSort_new(node<T>* a)//插入排序(排序结果放到一个新链表中)
{
	if (a == nullptr)return a;//判断空链表
	node<T>* front = new node<T>(a->data, nullptr);//新建一个链表，初始值就是原链表的第一个结点值
	node<T>* cur = a->next;//无序区的第一个元素
	node<T>* curs = nullptr;//保存cur的后继结点位置
	front->next = nullptr;//作为初始有序区队尾
	while (cur != nullptr)
	{
		curs = cur->next;
		node<T>* tmp = front;
		node<T>* pre = nullptr;
		while (cur->data > tmp->data)//查找插入位置
		{
			pre = tmp;
			tmp = tmp->next;
			if (tmp == nullptr)break;
		}
		if (tmp == front)//插入在队首
		{
			front = new node<T>(cur->data, front);
		}
		else//插在队中和队尾
		{
			pre->next = new node<T>(cur->data, tmp);
		}
		cur = curs;//cur后移一位
	}
	return front;
}
template<class T>
node<T>* MergeSort1(node<T>* front1, node<T>* front2)//合并结果使用原有的结点
{
	node<T>* front = new node<T>(0, nullptr);
	node<T>* tail = front;//已合并区域的尾部
	node<T>* f1 = front1;//遍历front1
	node<T>* f2 = front2;//遍历front2
	while (f1 && f2)//当两个链表中有一个遍历完时退出循环
	{
		if (f1->data < f2->data)
		{
			tail->next = f1;
			tail = tail->next;
			f1 = f1->next;
		}
		else
		{
			tail->next = f2;
			tail = tail->next;
			f2 = f2->next;
		}
	}
	if (f1)//把没遍历完的链表接上
	{
		tail->next = f1;
	}
	else
	{
		tail->next = f2;
	}
	//删除哨兵
	node<T>* tmp = front;
	front = front->next;
	delete tmp;
	return front;

}

template<class T>
node<T>* MergeSort(node<T>* front1,node<T>* front2)//生成新链表
{
	node<T>* front = new node<T>(0, nullptr);//哨兵头结点
	node<T>* tail = front;
	node<T>* cur1 = front1;//遍历front1
	node<T>* cur2 = front2;//遍历front2
	while (cur1 && cur2)//当两个链表中有一个遍历完时退出循环
	{
		if (cur1->data <= cur2->data)
		{
			tail->next = new node<T>(cur1->data, nullptr);//每次都需要新建一个结点空间
			cur1 = cur1->next;
		}
		else
		{
			tail->next = new node<T>(cur2->data, nullptr);
			cur2 = cur2->next;
		}
		tail = tail->next;
	}
	if (cur1)
	{
		while (cur1)//需要逐个加入尾部，逐个新建空间
		{
			tail->next = new node<T>(cur1->data, nullptr);
			tail = tail->next;
			cur1 = cur1->next;
		}
	}
	else
	{
		while (cur2)
		{
			tail->next = new node<T>(cur2->data, nullptr);
			tail = tail->next;
			cur2 = cur2->next;
		}
	}
	//删除哨兵
	node<T>* tmp = front;
	front = front->next;
	delete tmp;
	return front;
}
template<class T>
void Print(node<T>* front)//打印链表
{
	if (front == nullptr) cout << "该链表为空";
	while (front != nullptr)
	{
		cout << front->data << " ";
		front = front->next;
	}
	cout << endl;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	cout << "请输入两组数据，每组数据10个元素：" << endl;
	node<int>* front1 = nullptr;
	node<int>* front2 = nullptr;
	cout << "链表f1：";
	for (int i = 0; i < 10; i++)
	{
		int k; cin >> k;
		front1 = new node<int>(k, front1);
	}
	cout << "链表f2：";
	for (int i = 0; i < 10; i++)
	{
		int k; cin >> k;
		front2 = new node<int>(k, front2);
	}
	cout << endl;

	InsertSort(front1); cout << "f1升序排序：";
	Print(front1);

	InsertSort(front2); cout << "f2升序排序：";
	Print(front2);

	cout << endl;

	node<int>* front = MergeSort(front1, front2); cout << "f1 f2合并(生成新链表)：";
	Print(front);

	front1 = MergeSort1(front1, front2); cout << "f1 f2合并(利用原结点)：";
	Print(front1);

	return 0;
}