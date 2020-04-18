#include<cstdio>
#include<algorithm>
using namespace std;

int N, M, sum = 0;
int dis[100005], A[100005];

int main(void)
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
		sum += A[i];
		dis[i] = sum;
	}

	scanf("%d", &M);
	
	while (M--)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		if (start > end)
			swap(start, end);
		int temp = dis[end - 1] - dis[start - 1];
		int result = min(temp, sum - temp);

		printf("%d\n", result);
	}

	return 0;
}