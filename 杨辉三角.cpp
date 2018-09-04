/*
题目描述
按要求输入如下格式的杨辉三角

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1

最多输出10层

输入
输入只包含一个正整数n，表示将要输出的杨辉三角的层数。
输出
对应于该输入，请输出相应层数的杨辉三角，每一层的整数之间用一个空格隔开
样例输入
5
样例输出
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