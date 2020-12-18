#include<iostream>
#include<deque>
using namespace std;
template<class T>
class myStack
{
public:
	myStack();//���캯��
	void push(int, const T&);//Ԫ����ջ
	void pop(int);//Ԫ�س�ջ
	T& top(int);//ȡջ��Ԫ�ص�ֵ
	bool empty(int) const;//�ж�ջ�Ƿ�Ϊ��
	bool full() const;//�ж�ջ�Ƿ�����
	int size(int) const;//ջ��ǰ�Ĵ�С
	void display(int);//��ӡ��ջ
private:
	int top1;//��ջ1ջ��Ԫ��λ��
	int top2;//��ջ2ջ��Ԫ��λ��
	const int MaxCapacity = 10;//��ջ�������
	T* Array;//��Ŷ�ջ������

};
/*-----------------------------------------------------------------------
------------------------------------------------------------------------*/
template<class T>
class myDeque
{
public:
	myDeque();
	void push(int flag, const T& item);//Ԫ����ջ
	void pop(int flag);//Ԫ�س�ջ
	T& top(int flag);//ȡջ��Ԫ�ص�ֵ
	bool empty(int flag) const;//�ж�ջ�Ƿ�Ϊ��
	int size(int flag) const;//ջ��ǰ�Ĵ�С
	void display(int flag);//��ӡ��ջ
private:
	deque<T> d;
	int size1;//��ջ1�Ĵ�С
	int size2;//��ջ2�Ĵ�С
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
	cout << "��ջs�Ƿ�Ϊ�գ� " << (s.empty(0) ? "true" : "false") << endl;
	cout << "��ջs�Ƿ������� " << (s.full() ? "true" : "false") << endl;
	cout << "��ջd�Ƿ�Ϊ�գ� " << (d.empty(0) ? "true" : "false") << endl;
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
		else cout << "��ջ������" << endl;
	}
	else cout << "��ջ"<<flag<<"�������޷�push" << item << endl;
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
		else cout << "Stack1Ϊ�գ��޷�pop" << endl;
	}
	else if (flag == 2)
	{
		if (top2 != MaxCapacity)
		{
			top2++;
		}
		else cout << "Stack2Ϊ�գ��޷�pop" << endl;
	}
	else cout << "��ջ������" << endl;
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
		else cout << "Stack1Ϊ�գ�" << endl;
	}
	else if (flag == 2)
	{
		if (top1 != MaxCapacity)
		{
			return Array[top2];
		}
		else cout << "Stack2Ϊ�գ�" << endl;
	}
	else cout << "��ջ������" << endl;
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
		if (top1 == -1)cout << "��";
		cout << endl;
	}
	if (flag != 1)
	{
		cout << "Stack2: ";
		while (b != MaxCapacity)cout << Array[b++] << " ";
		if (top2 == MaxCapacity)cout << "��";
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
	else cout << "��ջ������" << endl;
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
		else cout << "Stack1Ϊ�գ��޷�pop" << endl;
	}
	else if (flag == 2)
	{
		if (size2 != 0)
		{
			size2--;
			d.pop_back();
		}
		else cout << "Stack2Ϊ�գ��޷�pop" << endl;
	}
	else cout << "��ջ������" << endl;
}
template<class T>
T& myDeque<T>::top(int flag)
{
	if (flag == 1)
	{
		if (size1 != 0)
		{
			return d.front();//������Ԫ������
		}
		else cout << "Stack1Ϊ�գ�" << endl;
	}
	else if (flag == 2)
	{
		if (size2 != 0)
		{
			return d.back();
		}
		else cout << "Stack2Ϊ�գ�" << endl;
	}
	else cout << "��ջ������" << endl;
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
		if (size1 == 0)cout << "��";
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
		if (size2 == 0)cout << "��";
		cout << endl;
	}
}

