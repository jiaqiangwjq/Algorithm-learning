#include<cstdio>

int M, N;
const int MAXN = 900005;
int array[MAXN] = { 0 };
int prime[MAXN] = { 0 };

int pNum = 0;

void findPrime()
{
	for (int i = 2; i < MAXN; i++)
	{
		if (!array[i])
		{
			prime[pNum++] = i;

			for (int j = i + i; j < MAXN; j += i)
			{
				array[j] = 1;
			}
		}
	}
}

int main(void)
{
	findPrime();
	scanf("%d %d", &M, &N);

	int j = 0;
	for (int i = M-1; i <= N-2; i++)
	{
		++j;
		if (j == 10)
		{
			j = 0;
			printf("%d\n", prime[i]);
		}
		else
		{
			printf("%d ", prime[i]);
		}
	}

	printf("%d", prime[N - 1]);

	return 0;
}