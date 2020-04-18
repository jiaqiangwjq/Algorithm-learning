#include<cstdio>

int array[32] = { 0 };

int A, B, D;

int main(void)
{
	scanf("%d %d %d", &A, &B, &D);
	int num = A + B;
	int i = 0;
	
	do
	{
		array[i++] = num % D;
		num /= D;
	} while (num);

	i -= 1;

	for (; i >= 0; i--)
		printf("%d", array[i]);

	return 0;
}