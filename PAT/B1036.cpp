#include<cstdio>
using namespace std;

int N;
char c;

int main(void)
{
	scanf("%d %c", &N, & c);
	
	int column = int((double)N / 2 + 0.5) - 2;

	for (int i = 0; i < N; i++)
		printf("%c", c);
	printf("\n");
	
	for (int i = 0; i < column; i++)
	{
		printf("%c", c);
		for (int i = 0; i < N - 2; i++)
			printf(" ");
		printf("%c\n", c);
	}

	for (int i = 0; i < N; i++)
		printf("%c", c);
	printf("\n");
}