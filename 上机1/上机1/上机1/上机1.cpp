#include"d_vector.h"
#include<iostream>
#include<cstdio>
using namespace std;

int* bubblesort(int* a, int n)
{
	int* b = new int[n];
	memcpy(b, a, n*sizeof(int));
	int end = n - 1;
	while(end!=1)
	{
		bool flag = false;
		for (int j = 1,i=0; j <= end;i++, j++)
		{
			if (b[i] > b[j])
			{
				int tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;
				flag = true;
			}
		}
		end--;
		if (flag == false)break;
	}
	return b;
}
template <typename T>
miniVector<T>& bubblesort(miniVector<T>& a)
{
	miniVector<T> b(a);
	int end = b.size() - 1;
	while (end != 1)
	{
		bool flag = false;
		for (int j = 1, i = 0; j <= end; i++, j++)
		{
			if (b[i] > b[j])
			{
				T tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;
				flag = true;
			}
		}
		end--;
		if (flag == false)break;
	}
	return b;
}
template <typename T>
miniVector<T> unique_NEW(miniVector<T> a)
{
	miniVector<T> tmp;
	for (int i = 0,j=0; i < a.size(); i++)
	{
		bool flag = true;
		for (j = 0; j < tmp.size(); j++)
		{
			if (a[i] == tmp[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			tmp.push_back(a[i]);
		}
	}
	return tmp;
}

template<class T>
void print(miniVector<T> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void print(int * a,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	miniVector<int> a(10);
	int b[10];
	//freopen("in.txt", "r", stdin);
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	
	/*int *tmp1=bubblesort(b, 10); 
	print(tmp1, 10);
	
	miniVector<int> tmp2=bubblesort(a); 
	print(tmp2);*/

	miniVector<int> aa(unique_NEW(a)); print(aa);
	return 0;
}
