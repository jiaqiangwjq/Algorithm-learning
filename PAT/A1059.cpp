#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 100001;
int prime[maxn] = { 0 };
int num = 0;
bool p[maxn] = { 0 };

int N;

void findPrime()
{
	for (int i = 2; i < maxn; i++)
	{
		if (!p[i])
		{
			prime[num++] = i;
		}
		else
		{
			for (int j = i + i; i < maxn; j += i)
			{
				p[j] = true;
			}
		}
	}
}

struct factor {
	int fac;
	int count;
}factors[11];

int main(void)
{
	findPrime();
	int cnt = 0;
	scanf("%d", &N);
	int tmp = N;

	if (N == 1)
	{
		printf("1=1");
		return 0;
	}

	int flag = (int)sqrt(1.0 * N);

	for (int i = 0; prime[i] <= flag; i++)
	{
		if (N % prime[i] == 0)
		{
			factors[cnt].fac = prime[i];
			factors[cnt].count = 0;

			while (N % prime[i] == 0)
			{
				factors[cnt].count++;
				N /= prime[i];
			}
			cnt++;
		}
	}

	if (N != 1)
	{
		factors[cnt].fac = N;
		factors[cnt].count = 1;
		cnt++;
	}

	printf("%d=", tmp);
	for (int i = 0; i < cnt; i++)
	{
		if (i > 0)
			printf("*");
		printf("%d", factors[i].fac);
		if (factors[i].count > 1)
			printf("^%d", factors[i].count);
	}

	return 0;
}