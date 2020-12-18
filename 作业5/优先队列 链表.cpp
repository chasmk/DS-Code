//#include<iostream>
//#include<string>
//#include"q_except.h"
//using namespace std;
//
//template<class T>
//class node {
//public:
//	node(const T& item, node<T>* nextnode = nullptr) :data(item), next(nextnode) {}
//	T data;
//	node<T>* next;
//};
//template<class T>
//class priority_queue_list {
//public:
//	priority_queue_list();
//	priority_queue_list(string r);
//	void pop();
//	void push(const T& item);
//	T& front();
//	int size()const;
//	bool empty() const;
//	void print();
//private:
//	node<T>* head;
//	node<T>* rear;
//	int Size;
//	string rule;
//};
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	priority_queue_list<int> q_list_max;
//	priority_queue_list<int> q_list_min("greater");
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int item;
//		cin >> item;
//		q_list_max.push(item);
//		q_list_min.push(item);
//		cout << q_list_max.size()<<" "<<q_list_min.size() << endl;
//	}
//
//	q_list_max.print();
//	q_list_min.print();
//	cout << "最大优先 front()：" << q_list_max.front() << endl;
//	q_list_max.pop();
//	cout << "最小优先 front()：" << q_list_min.front() << endl;
//	q_list_min.pop();
//	cout << "最小优先 front()：" << q_list_min.front() << endl;
//	q_list_min.pop();
//	cout << "最小优先 front()：" << q_list_min.front() << endl;
//	q_list_min.pop();
//	cout << "最大优先 front()：" << q_list_max.front() << endl;
//	q_list_max.pop();
//	cout << "最大优先 front()：" << q_list_max.front() << endl;
//	q_list_max.pop();
//	cout << "最大优先 front()：" << q_list_max.front() << endl;
//	q_list_max.pop();
//	q_list_max.print();
//	q_list_min.print();
//
//	return 0;
//}
////***************************************************************************//
//template<class T>
//priority_queue_list<T>::priority_queue_list()
//{
//	head = new node<T>(0, nullptr);
//	rear = head;
//	Size = 0;
//	rule = "less";
//}
//template<class T>
//priority_queue_list<T>::priority_queue_list(string r)
//{
//	head = new node<T>(0, nullptr);
//	rear = head;
//	Size = 0;
//	rule = r;
//}
//template<class T>
//void priority_queue_list<T>::pop()
//{
//	if (empty())
//	{
//		cout << "队列已空，无法删除" << endl;
//		return;
//	}
//	node<T>* ptr = head->next;
//	node<T>* pre = head;
//	node<T>* priority_ptr = ptr;
//	node<T>* priority_pre = pre;
//	if (rule == "less")
//	{
//		while (ptr != nullptr)
//		{
//			if (ptr->data > priority_ptr->data)
//			{
//				priority_ptr = ptr;
//				priority_pre = pre;
//			}
//			pre = ptr;
//			ptr = ptr->next;
//		}
//	}
//	else if (rule == "greater")
//	{
//		while (ptr != nullptr)
//		{
//			if (ptr->data < priority_ptr->data)
//			{
//				priority_ptr = ptr;
//				priority_pre = pre;
//			}
//			pre = ptr;
//			ptr = ptr->next;
//		}
//	}
//	node<T>* tmp = priority_ptr;
//	priority_pre->next = tmp->next;
//	delete tmp;
//	Size--;
//}
//template<class T>
//void priority_queue_list<T>::push(const T& item)
//{
//	rear->next = new node<T>(item, nullptr);
//	rear = rear->next;
//	Size++;
//}
//template<class T>
//T& priority_queue_list<T>::front()
//{
//	if (empty())
//	{
//		cout << "队列已空，无法获取front" << endl;
//	}
//	node<T>* ptr = head->next;
//	node<T>* pre = head;
//	node<T>* priority_ptr = ptr;
//	node<T>* priority_pre = head;
//	if (rule == "less")
//	{
//		while (ptr != nullptr)
//		{
//			if (ptr->data > priority_ptr->data)
//			{
//				priority_ptr = ptr;
//				priority_pre = pre;
//			}
//			pre = ptr;
//			ptr = ptr->next;
//		}
//	}
//	else if (rule == "greater")
//	{
//		while (ptr != nullptr)
//		{
//			if (ptr->data < priority_ptr->data)
//			{
//				priority_ptr = ptr;
//				priority_pre = pre;
//			}
//			pre = ptr;
//			ptr = ptr->next;
//		}
//	}
//	return priority_ptr->data;
//}
//template<class T>
//int priority_queue_list<T>::size()const
//{
//	return Size;
//}
//template<class T>
//bool priority_queue_list<T>::empty() const
//{
//	return Size == 0;
//}
//template<class T>
//void priority_queue_list<T>::print()
//{
//	node<T>* tmp = head->next;
//	while (tmp != nullptr)
//	{
//		cout << tmp->data << " ";
//		tmp = tmp->next;
//	}
//	cout << endl;
//}