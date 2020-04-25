#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

void getNum(int N);
bool cmp_big(int a, int b);
bool cmp_small(int a, int b);
int sub();

int N;
int big[4] = { 0 };

int bigNum = 0, smallNum = 0;

int main(void)
{
	scanf("%d", &N);
	getNum(N);

	int res = sub();

	while (res != 6174 && res != 0)
	{
		bigNum = 0, smallNum = 0;
		getNum(res);
		res = sub();
	}

	return 0;
}

int sub()
{
	for (int i = 0; i < 4; i++)
	{
		bigNum = bigNum * 10 + big[i];
	}

	for (int i = 3; i >= 0; i--)
	{
		smallNum = smallNum * 10 + big[i];
	}

	int result = bigNum - smallNum;

	if (!result)
	{
		printf("%04d - %04d = 0000\n", bigNum, smallNum);
	}
	else
	{
		printf("%04d - %04d = %04d\n", bigNum, smallNum, result);

	}
	return result;
}

void getNum(int N)
{
	int i = 0;

	while (N)
	{
		big[i++] =  N % 10;
		N /= 10;
	}

	sort(big, big + 4, cmp_big);
}

bool cmp_big(int a, int b)
{
	return a > b;
}