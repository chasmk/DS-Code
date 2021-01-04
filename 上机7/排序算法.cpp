#include<iostream>
#include<queue>
#include <iomanip>
#include"radomNumber.h"
using namespace std;
const int N = 100000;//数据量大小
int aaa[N];//乱序
int bbb[N];//升序
int ccc[N];//降序
int aa[N];//乱序
int bb[N];//升序
int cc[N];//降序

void reset();//重新设置数组
string check(int a[]);//检查是否升序

double ExchangeSort(int a[]);//交换排序
double SelectSort(int a[]);//选择排序
double BubbleSort(int a[]);//冒泡排序
double BubbleSort_S(int a[]);//冒泡排序
double InsertSort(int a[]);//插入排序

double QuickSort(int a[]);//快速排序
void quicksort(int a[], int begin, int end);//快速排序
double MergeSort(int a[]);//归并排序
void mergesort(int a[], int begin, int end);//归并排序
void merge(int a[], int begin, int mid, int end);//归并
double HeapSort(int a[]);//堆排序
void heapsort(int a[]);//堆排序
void adjustheap(int a[], int i, int n);//堆调整

double RadixSort(int a[]);//基数排序
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
	
	cout << "\t 运行时间\t升序检查" << endl;
	//cout << "交换排序" << endl;
	//cout << "乱序时间：" << setw(6) << ExchangeSort(aa); cout << check(aa) << endl;
	//cout << "升序时间：" << setw(6) << ExchangeSort(bb); cout << check(bb) << endl;
	//cout << "降序时间：" << setw(6) << ExchangeSort(cc); cout << check(cc) << endl;
	////for (int i = 0; i < N; i++)cout << aa[i] << endl;
	//reset();
	//cout << "选择排序" << endl;
	//cout << "乱序时间：" << setw(6) << SelectSort(aa); cout << check(aa) << endl;
	//cout << "升序时间：" << setw(6) << SelectSort(bb); cout << check(bb) << endl;
	//cout << "降序时间：" << setw(6) << SelectSort(cc); cout << check(cc) << endl;
	//reset();
	//cout << "冒泡排序" << endl;
	//cout << "乱序时间：" << setw(6) << BubbleSort(aa); cout << check(aa) << endl;
	//cout << "升序时间：" << setw(6) << BubbleSort(bb); cout << check(bb) << endl;
	//cout << "降序时间：" << setw(6) << BubbleSort(cc); cout << check(cc) << endl;
	//reset();
	//cout << "冒泡排序 带哨兵" << endl;
	//cout << "乱序时间：" << setw(6) << BubbleSort_S(aa); cout << check(aa) << endl;
	//cout << "升序时间：" << setw(6) << BubbleSort_S(bb); cout << check(bb) << endl;
	//cout << "降序时间：" << setw(6) << BubbleSort_S(cc); cout << check(cc) << endl;
	//reset();
	//cout << "插入排序" << endl;
	//cout << "乱序时间：" << setw(6) << InsertSort(aa); cout << check(aa) << endl;
	//cout << "升序时间：" << setw(6) << InsertSort(bb); cout << check(bb) << endl;
	//cout << "降序时间：" << setw(6) << InsertSort(cc); cout << check(cc) << endl;
	reset();
	cout << "快速排序" << endl;
	cout << "乱序时间：" << setw(6) << QuickSort(aa); cout << check(aa) << endl;
	cout << "升序时间：" << setw(6) << QuickSort(bb); cout << check(bb) << endl;
	cout << "降序时间：" << setw(6) << QuickSort(cc); cout << check(cc) << endl;
	reset();
	cout << "归并排序" << endl;
	cout << "乱序时间：" << setw(6) << MergeSort(aa); cout << check(aa) << endl;
	cout << "升序时间：" << setw(6) << MergeSort(bb); cout << check(bb) << endl;
	cout << "降序时间：" << setw(6) << MergeSort(cc); cout << check(cc) << endl;
	reset();
	cout << "堆排序" << endl;
	cout << "乱序时间：" << setw(6) << HeapSort(aa); cout << check(aa) << endl;
	cout << "升序时间：" << setw(6) << HeapSort(bb); cout << check(bb) << endl;
	cout << "降序时间：" << setw(6) << HeapSort(cc); cout << check(cc) << endl;
	reset();
	cout << "基数排序" << endl;
	cout << "乱序时间：" << setw(6) << RadixSort(aa); cout << check(aa) << endl;
	cout << "升序时间：" << setw(6) << RadixSort(bb); cout << check(bb) << endl;
	cout << "降序时间：" << setw(6) << RadixSort(cc); cout << check(cc) << endl;
}
void reset()//重新设置数组
{
	memcpy(aa, aaa, sizeof(int) * N);
	memcpy(bb, bbb, sizeof(int) * N);
	memcpy(cc, ccc, sizeof(int) * N);
}
string check(int a[])//检查是否升序
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
double ExchangeSort(int a[])//交换排序
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
double SelectSort(int a[])//选择排序
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
double BubbleSort(int a[])//冒泡排序
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
double BubbleSort_S(int a[])//冒泡排序 带哨兵
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
double InsertSort(int a[])//插入排序
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
double QuickSort(int a[])//快速排序
{
	double start, end;
	start = clock();
	quicksort(a, 0, N-1);
	end = clock();
	//for (int i = 0; i < N; i++)cout << a[i] << endl;
	return (end - start) / double(CLOCKS_PER_SEC);
}
void quicksort(int a[], int begin, int end)//快速排序
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
double MergeSort(int a[])//归并排序
{
	double start, end;
	start = clock();
	mergesort(a, 0, N - 1);
	end = clock();
	//for (int i = 0; i < N; i++)cout << a[i] << endl;
	return (end - start) / double(CLOCKS_PER_SEC);
}
void mergesort(int a[], int begin, int end)//归并排序
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergesort(a, begin, mid);
		mergesort(a, mid + 1, end);
		merge(a, begin, mid, end);
	}
}
void merge(int a[], int begin, int mid, int end)//归并
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
double HeapSort(int a[])//堆排序
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
	//构造大顶堆
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
		//获取最大的儿子
		k = k * 2 + 1;
		if (k + 1 < n && a[k] < a[k + 1])
		{
			k++;
		}
		//如果两个儿子都比它小，说明找到了合适的位置，退出循环
		if (tmp >= a[k])break;
		a[i] = a[k];
		i = k;
	}
	a[(k - 1) / 2] = tmp;
}
double RadixSort(int a[])//基数排序
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
