#pragma once
#include<iostream>
using namespace std;
template<class T>
class myStack
{
public:
	myStack();
	void push(int, const T&);
	void pop(int);
	T& top(int);
	bool empty(int) const;
	bool full() const;
	int size(int) const;
	void display(int);
private:
	int top1;
	int top2;
	const int MaxCapacity = 10;
	T *Array;
};
template<class T>
myStack<T>::myStack()
{
	Array = new T[MaxCapacity];
	top1 = -1;
	top2 = MaxCapacity;
}
template<class T>
void myStack<T>::push(int flag, const T& item)
{
	if (!full())
	{
		if (flag == 1)
		{
			top1++;
			Array[top1] = item;
		}
		else if (flag == 2)
		{
			top2--;
			Array[top2] = item;
		}
		else cout << "堆栈不存在" << endl;
	}
	else cout << "堆栈已满，无法push" << endl;
}
template<class T>
void myStack<T>::pop(int flag)
{
	if (flag == 1)
	{
		if (top1 != -1)
		{
			top1--;
		}
	}
	else if (flag == 2)
	{
		if (top2 != MaxCapacity)
		{
			top2++;
		}
	}
	else cout << "堆栈不存在" << endl;
}
template<class T>
T& myStack<T>::top(int flag)
{
	if (flag == 1)
	{
		if (top1 != -1)
		{
			return Array[top1];
		}
		else cout << "Stack1为空！" << endl;
	}
	else if (flag == 2)
	{
		if (top1 != MaxCapacity)
		{
			return Array[top2];
		}
		else cout << "Stack2为空！" << endl;
	}
	else cout << "堆栈不存在" << endl;
}
template<class T>
bool myStack<T>::empty(int flag) const
{
	if (flag == 1)
	{
		if (top1 != -1)return true;
		else return false;
	}
	else if (flag == 2)
	{
		if (top2 == MaxCapacity)return true;
		else return false;
	}
	else if (top1 == -1 && top2 == MaxCapacity)
		return true;
	else
		return false;
}
template<class T>
bool myStack<T>::full() const
{
	if (size(0) == MaxCapacity)return true;
	else return false;
}
template<class T>
int myStack<T>::size(int flag) const
{
	if (flag == 1)
	{
		return top1 + 1;
	}
	else if (flag == 2)
	{
		return MaxCapacity - top2;
	}
	return top1 - (-1) + MaxCapacity - top2;
}
template<class T>
void myStack<T>::display(int flag)
{
	int a = top1;
	int b = top2;
	if (flag != 2)
	{
		cout << "Stack1: ";
		while (a != -1)cout << Array[a--] << " ";
		cout << endl;
	}
	if (flag != 1)
	{
		cout << "Stack2: ";
		while (b != MaxCapacity)cout << Array[b++] << " ";
		cout << endl;
	}
}

