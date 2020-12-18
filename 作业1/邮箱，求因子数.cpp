#include<iostream>
using namespace std;

const int N = 150;

int IsPrime[N+5];
int Prime[N];
void GetPrime()//筛法求素数 
{
	int t = 0;
	IsPrime[0] = 1;
	IsPrime[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (IsPrime[i] == 0)//i是素数 
		{
			Prime[t++] = i;
			for (int j = i * 2; j <= N; j += i)
			{
				IsPrime[j] = 1;//i的倍数都是非素数； 
			}
		}
	}
	return;
}

int f(int n)//求n的因数个数 
{
	if (IsPrime[n] == 0) return 2;//如果是素数，因子数是2，1和其本身 
	else
	{
		int tmp[N] = { 0 };//存放每个质因子的个数
		int t = 0;//tmp计数器 
		int p = 0;//Prime计数器 
		for (int i = Prime[p++]; n != 1;)
		{
			if (n % i == 0)//若i是质因子 
			{
				n /= i;
				tmp[t]++;//同一个质因子的指数加一 
			}
			else
			{
				if (tmp[t] != 0) t++;//存下一个指质因子数 
				i = Prime[p++];//i变成下一个质数 
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