#include<iostream>
#include<queue>
#include <iomanip>
#include"radomNumber.h"
using namespace std;
const int N = 100000;//��������С
int aaa[N];//����
int bbb[N];//����
int ccc[N];//����
int aa[N];//����
int bb[N];//����
int cc[N];//����

void reset();//������������
string check(int a[]);//����Ƿ�����

double ExchangeSort(int a[]);//��������
double SelectSort(int a[]);//ѡ������
double BubbleSort(int a[]);//ð������
double BubbleSort_S(int a[]);//ð������
double InsertSort(int a[]);//��������

double QuickSort(int a[]);//��������
void quicksort(int a[], int begin, int end);//��������
double MergeSort(int a[]);//�鲢����
void mergesort(int a[], int begin, int end);//�鲢����
void merge(int a[], int begin, int mid, int end);//�鲢
double HeapSort(int a[]);//������
void heapsort(int a[]);//������
void adjustheap(int a[], int i, int n);//�ѵ���

double RadixSort(int a[]);//��������
int main()
{
	randomNumber r;

	for (int i = 0; i < N; i++)
	{
		aaa[i] = r.random(N);
		bbb[i] = i;
		ccc[i] = N - i - 1;
		//cout << aa[i] << " " << bb[i] << " " << cc[i] << endl;
	}
	
	cout << "\t ����ʱ��\t������" << endl;
	//cout << "��������" << endl;
	//cout << "����ʱ�䣺" << setw(6) << ExchangeSort(aa); cout << check(aa) << endl;
	//cout << "����ʱ�䣺" << setw(6) << ExchangeSort(bb); cout << check(bb) << endl;
	//cout << "����ʱ�䣺" << setw(6) << ExchangeSort(cc); cout << check(cc) << endl;
	////for (int i = 0; i < N; i++)cout << aa[i] << endl;
	//reset();
	//cout << "ѡ������" << endl;
	//cout << "����ʱ�䣺" << setw(6) << SelectSort(aa); cout << check(aa) << endl;
	//cout << "����ʱ�䣺" << setw(6) << SelectSort(bb); cout << check(bb) << endl;
	//cout << "����ʱ�䣺" << setw(6) << SelectSort(cc); cout << check(cc) << endl;
	//reset();
	//cout << "ð������" << endl;
	//cout << "����ʱ�䣺" << setw(6) << BubbleSort(aa); cout << check(aa) << endl;
	//cout << "����ʱ�䣺" << setw(6) << BubbleSort(bb); cout << check(bb) << endl;
	//cout << "����ʱ�䣺" << setw(6) << BubbleSort(cc); cout << check(cc) << endl;
	//reset();
	//cout << "ð������ ���ڱ�" << endl;
	//cout << "����ʱ�䣺" << setw(6) << BubbleSort_S(aa); cout << check(aa) << endl;
	//cout << "����ʱ�䣺" << setw(6) << BubbleSort_S(bb); cout << check(bb) << endl;
	//cout << "����ʱ�䣺" << setw(6) << BubbleSort_S(cc); cout << check(cc) << endl;
	//reset();
	//cout << "��������" << endl;
	//cout << "����ʱ�䣺" << setw(6) << InsertSort(aa); cout << check(aa) << endl;
	//cout << "����ʱ�䣺" << setw(6) << InsertSort(bb); cout << check(bb) << endl;
	//cout << "����ʱ�䣺" << setw(6) << InsertSort(cc); cout << check(cc) << endl;
	reset();
	cout << "��������" << endl;
	cout << "����ʱ�䣺" << setw(6) << QuickSort(aa); cout << check(aa) << endl;
	cout << "����ʱ�䣺" << setw(6) << QuickSort(bb); cout << check(bb) << endl;
	cout << "����ʱ�䣺" << setw(6) << QuickSort(cc); cout << check(cc) << endl;
	reset();
	cout << "�鲢����" << endl;
	cout << "����ʱ�䣺" << setw(6) << MergeSort(aa); cout << check(aa) << endl;
	cout << "����ʱ�䣺" << setw(6) << MergeSort(bb); cout << check(bb) << endl;
	cout << "����ʱ�䣺" << setw(6) << MergeSort(cc); cout << check(cc) << endl;
	reset();
	cout << "������" << endl;
	cout << "����ʱ�䣺" << setw(6) << HeapSort(aa); cout << check(aa) << endl;
	cout << "����ʱ�䣺" << setw(6) << HeapSort(bb); cout << check(bb) << endl;
	cout << "����ʱ�䣺" << setw(6) << HeapSort(cc); cout << check(cc) << endl;
	reset();
	cout << "��������" << endl;
	cout << "����ʱ�䣺" << setw(6) << RadixSort(aa); cout << check(aa) << endl;
	cout << "����ʱ�䣺" << setw(6) << RadixSort(bb); cout << check(bb) << endl;
	cout << "����ʱ�䣺" << setw(6) << RadixSort(cc); cout << check(cc) << endl;
}
void reset()//������������
{
	memcpy(aa, aaa, sizeof(int) * N);
	memcpy(bb, bbb, sizeof(int) * N);
	memcpy(cc, ccc, sizeof(int) * N);
}
string check(int a[])//����Ƿ�����
{
	for (int i = 1; i < N; i++)
	{
		if (a[i] < a[i - 1])
		{
			//cout << " " << a[i] << "<" << a[i - 1] << " ";
			return "\tfalse";
		}
	}
	return "\ttrue";
}
double ExchangeSort(int a[])//��������
{
	double start, end;
	start = clock();
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (a[i] > a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	end = clock();
	return (end - start) / double(CLOCKS_PER_SEC);
}
double SelectSort(int a[])//ѡ������
{
	double start, end;
	start = clock();
	for (int i = 0; i < N - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < N; j++)
		{
			if (a[j] < a[k])
				k = j;
		}
		if (k != i)
		{
			int tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}
	}
	end = clock();
	//for (int i = 0; i < N; i++)cout << a[i] << endl;
	return (end - start) / double(CLOCKS_PER_SEC);
}
double BubbleSort(int a[])//ð������
{
	double start, end;
	start = clock();
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			if (a[j] > a[j+1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	end = clock();
	return (end - start) / double(CLOCKS_PER_SEC);
}
double BubbleSort_S(int a[])//ð������ ���ڱ�
{
	double start, end;
	start = clock();
	bool flag = false;
	for (int i = 1; i < N; i++)
	{
		flag = false;
		for (int j = 0; j < N - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = true;
			}
		}
		if (!flag) break;
	}
	end = clock();
	return (end - start) / double(CLOCKS_PER_SEC);
}
double InsertSort(int a[])//��������
{
	double start, end;
	start = clock();
	for (int i = 1; i < N; i++)
	{
		int j = i;
		int tmp = a[i];
		while (j > 0 && tmp < a[j - 1])
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
	}
	end = clock();
	return (end - start) / double(CLOCKS_PER_SEC);
}
double QuickSort(int a[])//��������
{
	double start, end;
	start = clock();
	quicksort(a, 0, N-1);
	end = clock();
	//for (int i = 0; i < N; i++)cout << a[i] << endl;
	return (end - start) / double(CLOCKS_PER_SEC);
}
void quicksort(int a[], int begin, int end)//��������
{
	if (begin >= end)return;
	if (end - begin == 1)
	{
		if (a[end] < a[begin])
		{
			int tmp = a[end];
			a[end] = a[begin];
			a[begin] = tmp;
		}
		return;
	}
	int mid = (begin + end) / 2;
	int pivot = a[mid];
	a[mid] = a[begin];
	a[begin] = pivot;
	int i = begin;
	int j = end;
	while (i != j)
	{
		while (i < j && a[j] >= pivot)
			j--;
		while (i < j && a[i] <= pivot)
			i++;
		if (i < j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	a[begin] = a[i];
	a[i] = pivot;
	quicksort(a, begin, i - 1);
	quicksort(a, j + 1, end);
}
double MergeSort(int a[])//�鲢����
{
	double start, end;
	start = clock();
	mergesort(a, 0, N - 1);
	end = clock();
	//for (int i = 0; i < N; i++)cout << a[i] << endl;
	return (end - start) / double(CLOCKS_PER_SEC);
}
void mergesort(int a[], int begin, int end)//�鲢����
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergesort(a, begin, mid);
		mergesort(a, mid + 1, end);
		merge(a, begin, mid, end);
	}
}
void merge(int a[], int begin, int mid, int end)//�鲢
{
	int tmp[N] = { 0 };
	int i = begin;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			tmp[k++] = a[i];
			i++;
		}
		else
		{
			tmp[k++] = a[j];
			j++;
		}
	}
	while (i <= mid)
	{
		tmp[k++] = a[i];
		i++;
	}
	while (j <= end)
	{
		tmp[k++] = a[j];
		j++;
	}
	memcpy(a + begin, tmp, sizeof(int) * (end - begin + 1));
}
double HeapSort(int a[])//������
{
	double start, end;
	start = clock();
	heapsort(a);
	end = clock();
	//for (int i = 0; i < N; i++)cout << a[i] << endl;
	return (end - start) / double(CLOCKS_PER_SEC);
}
void heapsort(int a[])
{
	//����󶥶�
	for (int i = (N - 1) / 2; i >= 0; i--)
	{
		adjustheap(a, i, N);
	}
	for (int i = 0; i < N; i++)
	{
		int tmp = a[0];
		a[0] = a[N - i - 1];
		a[N - i - 1] = tmp;
		adjustheap(a, 0, N - i - 1);
	}
}
void adjustheap(int a[], int i, int n)
{
	int tmp = a[i];
	int k = i;
	while (k < n)
	{
		//��ȡ���Ķ���
		k = k * 2 + 1;
		if (k + 1 < n && a[k] < a[k + 1])
		{
			k++;
		}
		//����������Ӷ�����С��˵���ҵ��˺��ʵ�λ�ã��˳�ѭ��
		if (tmp >= a[k])break;
		a[i] = a[k];
		i = k;
	}
	a[(k - 1) / 2] = tmp;
}
double RadixSort(int a[])//��������
{
	double start, end;
	start = clock();
	queue<int> q[10];
	int k = N;
	int l = 0;
	int p = 1;
	while (k != 0) { k /= 10; l++; }
	for (int i = 0; i < l - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//q[(a[j] / p) % 10].push(a[j]);
		}
		k = 0;
		for (int j = 0; j < 10; j++)
		{
			while (!q[j].empty())
			{
				//a[k++] = q[j].front();
				//q[j].pop();
			}
		}
		p *= 10;
	}
	end = clock();
	//for (int i = 0; i < N; i++)cout << a[i] << endl;
	return (end - start) / double(CLOCKS_PER_SEC);
}
