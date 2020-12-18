#include<iostream>
using namespace std;

const int N = 150;

int IsPrime[N+5];
int Prime[N];
void GetPrime()//ɸ�������� 
{
	int t = 0;
	IsPrime[0] = 1;
	IsPrime[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (IsPrime[i] == 0)//i������ 
		{
			Prime[t++] = i;
			for (int j = i * 2; j <= N; j += i)
			{
				IsPrime[j] = 1;//i�ı������Ƿ������� 
			}
		}
	}
	return;
}

int f(int n)//��n���������� 
{
	if (IsPrime[n] == 0) return 2;//�������������������2��1���䱾�� 
	else
	{
		int tmp[N] = { 0 };//���ÿ�������ӵĸ���
		int t = 0;//tmp������ 
		int p = 0;//Prime������ 
		for (int i = Prime[p++]; n != 1;)
		{
			if (n % i == 0)//��i�������� 
			{
				n /= i;
				tmp[t]++;//ͬһ�������ӵ�ָ����һ 
			}
			else
			{
				if (tmp[t] != 0) t++;//����һ��ָ�������� 
				i = Prime[p++];//i�����һ������ 
			}
		}
		int res = 1;
		for (int i = 0; i <= t; i++)
		{
			res *= (tmp[i] + 1);
		}
		return res;
	}
}


int main()
{
	GetPrime();
	
	for (int i = 1; i <= N; i++)
	{
		//cout << i << " " << f(IsPrime, Prime,i) << endl;
		if (f(i) % 2 == 1)
			cout << i << endl;
	}
	return 0;
}