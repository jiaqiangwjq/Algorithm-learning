#include<cstdio>

int numbers[10] = { 0 };
char res[51];

int main(void)
{
	int count;
	
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &count);
		numbers[i] = count;
	}

	for (int i = 1; i < 10; i++)
	{
		if (numbers[i] != 0)
		{
			res[0] = i + 48;
			numbers[i]--;
			break;
		}
	}

	int j = 0;
	for (int i = 0; i < 10;)
	{
		if (numbers[i] > 0)
		{
			res[++j] = i + 48;
			numbers[i]--;
		}
		else
			i++;
	}

	for (int i = 0; i <= j; i++)
	{
		printf("%c", res[i]);
	}

	return 0;
}