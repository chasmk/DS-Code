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

template<typename T>
void print(node<T>* a)
{
	while (a != nullptr)
	{
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
}

template<typename T>
bool func1(node<T>* first)//判断链表是否升序
{
	while (first->next != nullptr)
	{
		if (first->data >= first->next->data)
			return false;
		first = first->next;
	}
	return true;
}


void func2(node<int>* first, int n)//插入结点n到第n个结点之后
{
	node<int>* tmp = new node<int>(n, nullptr);
	for (int i = 1; i < n && first != nullptr; i++)//first找到插入位置
	{
		first = first->next;
	}

	if (first != nullptr && n > 0)
	{
		tmp->next = first->next;
		first->next = tmp;
	}
	else
	{
		cout << n << "超出范围！无法插入" << endl;
	}
}

template<class T>
void func3(node<T>*& first)//链表逆转
{
	node<T>* ptr = first->next;
	first->next = nullptr;

	while (ptr != nullptr)
	{
		node<T>* tmp = ptr->next;
		ptr->next = first;
		first = ptr;
		ptr = tmp;
	}
}
int main()
{
	//降序链表构造
	node<int>* a;
	a = new node<int>(0, nullptr);
	for (int i = 1; i < 10; i++)
	{
		a = new node<int>(i, a);
	}
	//升序链表构造
	node<int>* b;
	b = new node<int>(10, nullptr);
	for (int i = 9; i > 0; i--)
	{
		b = new node<int>(i, b);
	}

	//判断是否升序
	cout << "链表："; print(a);
	cout << "是否升序：" << (func1(a) == true ? "是" : "否") << endl;
	cout << "链表："; print(b);
	cout << "是否升序：" << (func1(b) == true ? "是" : "否") << endl;

	//第5个元素后插入5
	cout << endl << "第5个元素后插入5" << endl;
	cout << "原链表："; print(a);
	func2(a, 5);
	cout << "新链表："; print(a);

	//链表逆转
	cout << endl << "链表逆转" << endl;
	cout << "原链表："; print(a);
	func3(a);
	cout << "新链表："; print(a);

	return 0;
}