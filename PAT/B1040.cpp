#include<cstdio>
#include<cstring>
#define MOD 1000000007 

char s[100005];
int numP[100005] = { 0 };

int main(void)
{
	scanf("%s", s);
	int len = strlen(s);
	
	for (int i = 0; i < len; i++)
	{
		if (i > 0)
		{
			numP[i] = numP[i - 1];
		}
		if (s[i] == 'P')
		{
			numP[i]++;
		}
	}

	int res = 0, numT = 0;
	for (int j = len - 1; j >= 0; j--)
	{
		if (s[j] == 'T')
		{
			numT++;
		}
		else if(s[j] == 'A')
		{
			res = (res + numP[j] * numT) % MOD;
		}
	}

	printf("%d\n", res);

	return 0;
}