#include<iostream>
#include<deque>
using namespace std;
template<class T>
class myStack
{
public:
	myStack();//构造函数
	void push(int, const T&);//元素入栈
	void pop(int);//元素出栈
	T& top(int);//取栈顶元素的值
	bool empty(int) const;//判断栈是否为空
	bool full() const;//判断栈是否已满
	int size(int) const;//栈当前的大小
	void display(int);//打印堆栈
private:
	int top1;//堆栈1栈顶元素位置
	int top2;//堆栈2栈顶元素位置
	const int MaxCapacity = 10;//堆栈最大容量
	T* Array;//存放堆栈的数组

};
/*-----------------------------------------------------------------------
------------------------------------------------------------------------*/
template<class T>
class myDeque
{
public:
	myDeque();
	void push(int flag, const T& item);//元素入栈
	void pop(int flag);//元素出栈
	T& top(int flag);//取栈顶元素的值
	bool empty(int flag) const;//判断栈是否为空
	int size(int flag) const;//栈当前的大小
	void display(int flag);//打印堆栈
private:
	deque<T> d;
	int size1;//堆栈1的大小
	int size2;//堆栈2的大小
};
/*-----------------------------------------------------------------------
------------------------------------------------------------------------*/
int main()
{
	myStack<int> s;
	myDeque<int> d;
	for (int i = 0; i < 15; i++)
	{
		if (i % 2)
		{
			s.push(1, i);
			d.push(2, i);
		}
		else
		{
			s.push(2, i);
			d.push(1, i);
		}
	}
	cout << "堆栈s是否为空？ " << (s.empty(0) ? "true" : "false") << endl;
	cout << "堆栈s是否已满？ " << (s.full() ? "true" : "false") << endl;
	cout << "堆栈d是否为空？ " << (d.empty(0) ? "true" : "false") << endl;
	cout << "<--******************************-->" << endl;
	s.display(0);
	cout << s.size(0) << endl;
	for (int i = 0; i < 7; i ++)s.pop(1);
	s.display(0);
	s.pop(2); cout << "s.pop(2)" << endl;
	s.display(0);
	
	cout << "<--******************************-->" << endl;
	d.display(0);
	cout << d.size(0) << endl;
	for (int i = 0; i < 10; i++)d.pop(2);
	d.display(0);
	cout << "d.top(1) " << d.top(1) << endl;
	d.pop(2); cout << "d.pop(2)" << endl;
	d.display(0);
	return 0;
}
/*-----------------------------------------------------------------------
------------------------------------------------------------------------*/
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
	else cout << "堆栈"<<flag<<"已满，无法push" << item << endl;
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
		else cout << "Stack1为空，无法pop" << endl;
	}
	else if (flag == 2)
	{
		if (top2 != MaxCapacity)
		{
			top2++;
		}
		else cout << "Stack2为空，无法pop" << endl;
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
		if (top1 == -1)cout << "空";
		cout << endl;
	}
	if (flag != 1)
	{
		cout << "Stack2: ";
		while (b != MaxCapacity)cout << Array[b++] << " ";
		if (top2 == MaxCapacity)cout << "空";
		cout << endl;
	}
}
/*-----------------------------------------------------------------------
------------------------------------------------------------------------*/
template<class T>
myDeque<T>::myDeque()
{
	size1 = 0;
	size2 = 0;
}
template<class T>
void myDeque<T>::push(int flag, const T& item)
{
	if (flag == 1)
	{
		size1++;
		d.push_front(item);
	}
	else if (flag == 2)
	{
		size2++;
		d.push_back(item);
	}
	else cout << "堆栈不存在" << endl;
}
template<class T>
void myDeque<T>::pop(int flag)
{
	if (flag == 1)
	{
		if (size1 != 0)
		{
			size1--;
			d.pop_front();
		}
		else cout << "Stack1为空，无法pop" << endl;
	}
	else if (flag == 2)
	{
		if (size2 != 0)
		{
			size2--;
			d.pop_back();
		}
		else cout << "Stack2为空，无法pop" << endl;
	}
	else cout << "堆栈不存在" << endl;
}
template<class T>
T& myDeque<T>::top(int flag)
{
	if (flag == 1)
	{
		if (size1 != 0)
		{
			return d.front();//返回首元素引用
		}
		else cout << "Stack1为空！" << endl;
	}
	else if (flag == 2)
	{
		if (size2 != 0)
		{
			return d.back();
		}
		else cout << "Stack2为空！" << endl;
	}
	else cout << "堆栈不存在" << endl;
}
template<class T>
bool myDeque<T>::empty(int flag) const
{
	if (flag == 1)
	{
		if (size1 == 0)return true;
		else return false;
	}
	else if (flag == 2)
	{
		if (size2 == 0)return true;
		else return false;
	}
	else return d.empty();
}
template<class T>
int myDeque<T>::size(int flag) const
{
	if (flag == 1) return size1;
	else if (flag == 2) return size2;
	else return d.size();
}
template<class T>
void myDeque<T>::display(int flag)
{
	if (flag != 2)
	{
		cout << "Stack1: ";
		for (int i = 0; i < size1; i++)
		{
			cout << d.at(i) << " ";
		}
		if (size1 == 0)cout << "空";
		cout << endl;
	}
	if (flag != 1)
	{
		cout << "Stack2: ";
		int s = d.size();
		for (int i = 0; i < size2; i++)
		{
			cout << d.at(s - i - 1) << " ";
		}
		if (size2 == 0)cout << "空";
		cout << endl;
	}
}

