#include<iostream>
using namespace std;

template<class T>
class node {
public:
	T data;//�������
	node<T>* next; //nextָ��

	//���Ĺ��캯��
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
bool func1(node<T>* first)//�ж������Ƿ�����
{
	while (first->next != nullptr)
	{
		if (first->data >= first->next->data)
			return false;
		first = first->next;
	}
	return true;
}


void func2(node<int>* first, int n)//������n����n�����֮��
{
	node<int>* tmp = new node<int>(n, nullptr);
	for (int i = 1; i < n && first != nullptr; i++)//first�ҵ�����λ��
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
		cout << n << "������Χ���޷�����" << endl;
	}
}

template<class T>
void func3(node<T>*& first)//������ת
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
	//����������
	node<int>* a;
	a = new node<int>(0, nullptr);
	for (int i = 1; i < 10; i++)
	{
		a = new node<int>(i, a);
	}
	//����������
	node<int>* b;
	b = new node<int>(10, nullptr);
	for (int i = 9; i > 0; i--)
	{
		b = new node<int>(i, b);
	}

	//�ж��Ƿ�����
	cout << "����"; print(a);
	cout << "�Ƿ�����" << (func1(a) == true ? "��" : "��") << endl;
	cout << "����"; print(b);
	cout << "�Ƿ�����" << (func1(b) == true ? "��" : "��") << endl;

	//��5��Ԫ�غ����5
	cout << endl << "��5��Ԫ�غ����5" << endl;
	cout << "ԭ����"; print(a);
	func2(a, 5);
	cout << "������"; print(a);

	//������ת
	cout << endl << "������ת" << endl;
	cout << "ԭ����"; print(a);
	func3(a);
	cout << "������"; print(a);

	return 0;
}