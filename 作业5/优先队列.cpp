#include<iostream>
#include<string>
#include"q_except.h"
using namespace std;

const int MaxCapacity = 10;//�������

template<class T>
class priority_queue {//����ʵ�����ȶ���
public:
	//���캯��
	priority_queue();
	priority_queue(string r);
	void pop();
	void push(const T& item);
	T& front();
	int size()const;
	bool empty() const;
	bool full()const;
private:
	T data[MaxCapacity];
	int qfront;
	int qback;
	int Size;
	string rule;//���Ϊ"less" ��СΪ"greater"
};

template<class T>
class node {
public:
	node(const T& item, node<T>* nextnode = nullptr) :data(item), next(nextnode) {}
	T data;
	node<T>* next;
};
template<class T>
class priority_queue_list {//����ʵ�����ȶ���
public:
	priority_queue_list();
	priority_queue_list(string r);
	void pop();
	void push(const T& item);
	T& front();
	int size()const;
	bool empty() const;
	void print();
private:
	node<T>* head;
	node<T>* rear;
	int Size;
	string rule;
};


template<class T>
void print(priority_queue<T> q)//��ӡ����
{
	priority_queue<T> tmp = q;
	bool flag = true;
	while (!tmp.empty())
	{
		flag = false;
		cout << tmp.front() << " ";
		tmp.pop();
	}
	if (flag)cout << "����Ϊ��";
	cout << endl;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	priority_queue<int> q_max;//������ȶ���
	priority_queue<int> q_min("greater");//��С���ȶ���
	priority_queue_list<int> q_list_max;//������ȶ��� ����
	priority_queue_list<int> q_list_min("greater");//��С���ȶ��� ����

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		q_max.push(item);
		q_min.push(item);
		q_list_max.push(item);
		q_list_min.push(item);
	}
	cout << "q_max: "; print(q_max);
	cout << "q_min: "; print(q_min);
	cout << "�������q_max front()��" << q_max.front() << endl;
	q_max.pop();
	cout << "��С����q_min front()��" << q_min.front() << endl;
	q_min.pop();
	cout << "��С����q_min front()��" << q_min.front() << endl;
	q_min.pop();
	cout << "��С����q_min front()��" << q_min.front() << endl;
	q_min.pop();
	cout << "�������q_max front()��" << q_max.front() << endl;
	q_max.pop();
	cout << "�������q_max front()��" << q_max.front() << endl;
	q_max.pop();
	cout << "�������q_max front()��" << q_max.front() << endl;
	q_max.pop();
	cout << "�������q_max front()��" << q_max.front() << endl;
	q_max.pop();
	cout << "�������q_max front()��" << q_max.front() << endl;
	q_max.pop();
	cout << "q_max: "; print(q_max);
	cout << "q_min: "; print(q_min);

	cout << endl;

	cout << "q_list_max: "; q_list_max.print();
	cout << "q_list_min: "; q_list_min.print();
	cout << "�������q_list_max front()��" << q_list_max.front() << endl;
	q_list_max.pop();
	cout << "��С����q_list_min front()��" << q_list_min.front() << endl;
	q_list_min.pop();
	cout << "��С����q_list_min front()��" << q_list_min.front() << endl;
	q_list_min.pop();
	cout << "��С����q_list_min front()��" << q_list_min.front() << endl;
	q_list_min.pop();
	cout << "�������q_list_max front()��" << q_list_max.front() << endl;
	q_list_max.pop();
	cout << "�������q_list_max front()��" << q_list_max.front() << endl;
	q_list_max.pop();
	cout << "�������q_list_max front()��" << q_list_max.front() << endl;
	q_list_max.pop();
	cout << "�������q_list_max front()��" << q_list_max.front() << endl;
	q_list_max.pop();

	cout << "q_list_max: "; q_list_max.print();
	cout << "q_list_min: "; q_list_min.print();

	return 0;
}
template<class T>
priority_queue<T>::priority_queue()
{
	qfront = 0;
	qback = -1;
	Size = 0;
	rule = "less";//Ĭ�Ϲ���Ϊ�������
}
template<class T>
priority_queue<T>::priority_queue(string r)
{
	qfront = 0;
	qback = -1;
	Size = 0;
	rule = r;
}
template<class T>
void priority_queue<T>::pop()
{
	if (empty())
	{
		cout << "�����ѿգ��޷�ɾ��" << endl;
		return;
	}
	int index = qfront;//�������е�ָ��
	int priority_index = qfront;//���ȼ�����Ԫ�ص�ָ��
	if (rule == "less") {
		int next = (qback + 1) % MaxCapacity;
		while (index != next)
		{
			if (data[index] > data[priority_index])
				priority_index = index;
			index = (index + 1) % MaxCapacity;
		}
	}
	else if (rule == "greater")
	{
		int next = (qback + 1) % MaxCapacity;
		while (index != next)
		{
			if (data[index] < data[priority_index])
				priority_index = index;
			index = (index + 1) % MaxCapacity;
		}
	}
	if (priority_index == qfront)
	{
		qfront = (qfront + 1) % MaxCapacity;
	}
	else
	{
		while (priority_index != qback)
		{
			int next = (priority_index + 1) % MaxCapacity;
			data[priority_index] = data[next];
			priority_index = next;
		}
		if (qback == 0)qback = MaxCapacity - 1;
		else qback--;
	}
	Size--;
}
template<class T>
void priority_queue<T>::push(const T& item)
{
	if (full())
	{
		cout << "�����������޷�����" << endl;
		return;
	}
	int next = (qback + 1) % MaxCapacity;
	data[next] = item;
	qback = next;
	Size++;
}
template<class T>
T& priority_queue<T>::front()
{
	if (empty())
	{
		cout << "�����ѿգ��޷���ȡfront" << endl;
		throw underflowError("priority_queue front(): empty queue");
	}
	int index = qfront;
	int priority_index = qfront;
	if (rule == "less")
	{
		int next = (qback + 1) % MaxCapacity;
		while (index != next)
		{
			if (data[index] > data[priority_index])
				priority_index = index;
			index = (index + 1) % MaxCapacity;
		}
	}
	else if (rule == "greater")
	{
		int next = (qback + 1) % MaxCapacity;
		while (index != next)
		{
			if (data[index] < data[priority_index])
				priority_index = index;
			index = (index + 1) % MaxCapacity;
		}
	}
	return data[priority_index];
}
template<class T>
int priority_queue<T>::size()const
{
	return Size;
}
template<class T>
bool priority_queue<T>::empty() const
{
	return (Size == 0);
}
template<class T>
bool priority_queue<T>::full()const
{
	return Size == MaxCapacity;
}

//***************************************************************************//
template<class T>
priority_queue_list<T>::priority_queue_list()
{
	head = new node<T>(0, nullptr);
	rear = head;
	Size = 0;
	rule = "less";
}
template<class T>
priority_queue_list<T>::priority_queue_list(string r)
{
	head = new node<T>(0, nullptr);
	rear = head;
	Size = 0;
	rule = r;
}
template<class T>
void priority_queue_list<T>::pop()
{
	if (empty())
	{
		cout << "�����ѿգ��޷�ɾ��" << endl;
		return;
	}
	node<T>* ptr = head->next;
	node<T>* pre = head;
	node<T>* priority_ptr = ptr;
	node<T>* priority_pre = pre;
	if (rule == "less")
	{
		while (ptr != nullptr)
		{
			if (ptr->data > priority_ptr->data)
			{
				priority_ptr = ptr;
				priority_pre = pre;
			}
			pre = ptr;
			ptr = ptr->next;
		}
	}
	else if (rule == "greater")
	{
		while (ptr != nullptr)
		{
			if (ptr->data < priority_ptr->data)
			{
				priority_ptr = ptr;
				priority_pre = pre;
			}
			pre = ptr;
			ptr = ptr->next;
		}
	}
	node<T>* tmp = priority_ptr;
	priority_pre->next = tmp->next;
	delete tmp;
	Size--;
}
template<class T>
void priority_queue_list<T>::push(const T& item)
{
	rear->next = new node<T>(item, nullptr);
	rear = rear->next;
	Size++;
}
template<class T>
T& priority_queue_list<T>::front()
{
	if (empty())
	{
		cout << "�����ѿգ��޷���ȡfront" << endl;
	}
	node<T>* ptr = head->next;
	node<T>* pre = head;
	node<T>* priority_ptr = ptr;
	node<T>* priority_pre = head;
	if (rule == "less")
	{
		while (ptr != nullptr)
		{
			if (ptr->data > priority_ptr->data)
			{
				priority_ptr = ptr;
				priority_pre = pre;
			}
			pre = ptr;
			ptr = ptr->next;
		}
	}
	else if (rule == "greater")
	{
		while (ptr != nullptr)
		{
			if (ptr->data < priority_ptr->data)
			{
				priority_ptr = ptr;
				priority_pre = pre;
			}
			pre = ptr;
			ptr = ptr->next;
		}
	}
	return priority_ptr->data;
}
template<class T>
int priority_queue_list<T>::size()const
{
	return Size;
}
template<class T>
bool priority_queue_list<T>::empty() const
{
	return Size == 0;
}
template<class T>
void priority_queue_list<T>::print()
{
	node<T>* tmp = head->next;
	while (tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
