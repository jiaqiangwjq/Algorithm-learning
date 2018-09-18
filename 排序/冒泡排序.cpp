/*
题目描述
从键盘上输入10个整数，用冒泡法对这10个数进行排序（由小到大）。
输入
以空格分隔的10个整数
输出
依次输出排好序的10个整数，每个数占一行。
样例输入
1 3 5 7 9 2 4 6 8 0
样例输出
0
1
2
3
4
5
6
7
8
9
  */

#include<stdio.h>

int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= 9; i++)
		for (int j = 0; j <= 8; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	for (int i = 0; i < 10; i++)
		printf("%d\n", a[i]);
	return 0;
}