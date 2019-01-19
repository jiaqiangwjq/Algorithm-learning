#include<cstdio>
int D[32];
int main()
{
	int a,b,d;
	scanf("%d%d%d",&a,&b,&d);
	if(a == 0 && b == 0)
		printf("0");
	long long sum = a + b;
	int i = 0;
	while(sum != 0)
	{
		D[i++] = sum % d;
		sum /= d;
	}
	//D[i] = sum;
	for(int j = i-1; j >= 0; j--)
	{
		printf("%d",D[j]);
	}
	return 0;
}
