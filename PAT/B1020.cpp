#include<cstdio>
#include<algorithm>
using namespace std;

struct moonCake {
	double mass;
	double totalPrice;
	double perPrice;
} cakes[1005];

bool cmp(moonCake a, moonCake b)
{
	return a.perPrice > b.perPrice;
}

int N;
double D;
double reward = 0.0;

int main(void)
{
	scanf("%d %lf", &N, &D);

	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &cakes[i].mass);
	}
	for (int j = 0; j < N; j++)
	{
		scanf("%lf", &cakes[j].totalPrice);
		cakes[j].perPrice = cakes[j].totalPrice / cakes[j].mass;
	}

	sort(cakes, cakes + N, cmp);

	for (int i = 0; i < N; i++)
	{
		if (cakes[i].mass <= D)
		{
			reward += cakes[i].totalPrice;
			D -= cakes[i].mass;
		}
		else
		{
			reward += D * cakes[i].perPrice;
			break;	// 这个 break 可太重要了！！！
		}
	}

	printf("%.2f", reward);

	return 0;
}