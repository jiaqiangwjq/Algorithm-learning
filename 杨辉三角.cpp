/*
��Ŀ����
��Ҫ���������¸�ʽ���������

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1

������10��

����
����ֻ����һ��������n����ʾ��Ҫ�����������ǵĲ�����
���
��Ӧ�ڸ����룬�������Ӧ������������ǣ�ÿһ�������֮����һ���ո����
��������
5
�������
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
  */

#include<stdio.h>
int main()
{
	int array[10][10] = { {1},{1,1} };
	for (int i = 2; i < 10; i++)
		for (int j = 1; j < 9; j++)
		{
			array[i][0] = 1;
			array[i][i] = 1;
			array[i][j] = array[i - 1][j-1] + array[i-1][j];
		}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (array[i][j] == 0)
				continue;
			else
			{
				printf("%d ", array[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}