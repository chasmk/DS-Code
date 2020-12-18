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
template<class T>
void InsertSort(node<T>*& a)//��������(������ֱ���޸�ͷ�ڵ�ָ��)
{
	if (a == nullptr)return;
	node<T>* front = a;
	node<T>* cur = front->next;//�������ĵ�һ��Ԫ��
	node<T>* curs = nullptr;//����cur�ĺ�̽��λ��
	front->next = nullptr;//nullptr��Ϊ��ʼ��������β
	while (cur != nullptr)
	{
		curs = cur->next;//curs�ȱ����cur��next
		node<T>* tmp = front;//��������������
		node<T>* pre = nullptr;//����tmp��ǰ�����
		while (cur->data > tmp->data)//���Ҳ���λ��
		{
			pre = tmp;
			tmp = tmp->next;
			if (tmp == nullptr)break;
		}
		if (tmp == front)//�����ڶ���
		{
			cur->next = front;
			front = cur;
		}
		else//���ڶ��л��β
		{
			cur->next = tmp;
			pre->next = cur;
		}
		cur = curs;//cur����һλ
	}
	a = front;//�޸Ķ��׵�ֵ
}
template<class T>
node<T>* InsertSort_new(node<T>* a)//��������(�������ŵ�һ����������)
{
	if (a == nullptr)return a;//�жϿ�����
	node<T>* front = new node<T>(a->data, nullptr);//�½�һ��������ʼֵ����ԭ����ĵ�һ�����ֵ
	node<T>* cur = a->next;//�������ĵ�һ��Ԫ��
	node<T>* curs = nullptr;//����cur�ĺ�̽��λ��
	front->next = nullptr;//��Ϊ��ʼ��������β
	while (cur != nullptr)
	{
		curs = cur->next;
		node<T>* tmp = front;
		node<T>* pre = nullptr;
		while (cur->data > tmp->data)//���Ҳ���λ��
		{
			pre = tmp;
			tmp = tmp->next;
			if (tmp == nullptr)break;
		}
		if (tmp == front)//�����ڶ���
		{
			front = new node<T>(cur->data, front);
		}
		else//���ڶ��кͶ�β
		{
			pre->next = new node<T>(cur->data, tmp);
		}
		cur = curs;//cur����һλ
	}
	return front;
}
template<class T>
node<T>* MergeSort1(node<T>* front1, node<T>* front2)//�ϲ����ʹ��ԭ�еĽ��
{
	node<T>* front = new node<T>(0, nullptr);
	node<T>* tail = front;//�Ѻϲ������β��
	node<T>* f1 = front1;//����front1
	node<T>* f2 = front2;//����front2
	while (f1 && f2)//��������������һ��������ʱ�˳�ѭ��
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
	if (f1)//��û��������������
	{
		tail->next = f1;
	}
	else
	{
		tail->next = f2;
	}
	//ɾ���ڱ�
	node<T>* tmp = front;
	front = front->next;
	delete tmp;
	return front;

}

template<class T>
node<T>* MergeSort(node<T>* front1,node<T>* front2)//����������
{
	node<T>* front = new node<T>(0, nullptr);//�ڱ�ͷ���
	node<T>* tail = front;
	node<T>* cur1 = front1;//����front1
	node<T>* cur2 = front2;//����front2
	while (cur1 && cur2)//��������������һ��������ʱ�˳�ѭ��
	{
		if (cur1->data <= cur2->data)
		{
			tail->next = new node<T>(cur1->data, nullptr);//ÿ�ζ���Ҫ�½�һ�����ռ�
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
		while (cur1)//��Ҫ�������β��������½��ռ�
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
	//ɾ���ڱ�
	node<T>* tmp = front;
	front = front->next;
	delete tmp;
	return front;
}
template<class T>
void Print(node<T>* front)//��ӡ����
{
	if (front == nullptr) cout << "������Ϊ��";
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
	cout << "�������������ݣ�ÿ������10��Ԫ�أ�" << endl;
	node<int>* front1 = nullptr;
	node<int>* front2 = nullptr;
	cout << "����f1��";
	for (int i = 0; i < 10; i++)
	{
		int k; cin >> k;
		front1 = new node<int>(k, front1);
	}
	cout << "����f2��";
	for (int i = 0; i < 10; i++)
	{
		int k; cin >> k;
		front2 = new node<int>(k, front2);
	}
	cout << endl;

	InsertSort(front1); cout << "f1��������";
	Print(front1);

	InsertSort(front2); cout << "f2��������";
	Print(front2);

	cout << endl;

	node<int>* front = MergeSort(front1, front2); cout << "f1 f2�ϲ�(����������)��";
	Print(front);

	front1 = MergeSort1(front1, front2); cout << "f1 f2�ϲ�(����ԭ���)��";
	Print(front1);

	return 0;
}