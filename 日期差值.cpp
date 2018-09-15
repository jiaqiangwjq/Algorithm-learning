/*
题目描述
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。

输入
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD

输出
每组数据输出一行，即日期差值

样例输入
20130101
20130105
样例输出
5
*/
#include<cstdio>
#define lev(n) (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0))

void swap(int x1, int x2)
{
	if (x1 < x2)
	{
		int temp = x1;
		x1 = x2;
		x2 = temp;
	}
}

int main()
{
	int days[2][13] = { { 0,31,28,31,30,31,30,31,31,30,31,30,31 },{ 0,31,29,31,30,31,30,31,31,30,31,30,31 } };
	int x1, x2, y1, y2, m1, m2, d1, d2;
	int count = 1;
	scanf("%d%d", &x1, &x2);
	if (x1 < x2)
		swap(x1, x2);
	y1 = x1 / 10000; y2 = x2 / 10000; m1 = x1 / 100 % 100; m2 = x2 / 100 % 100; d1 = x1 % 100; d2 = x2 % 100;
	//printf("%d %d %d\n %d %d %d\n", y1, m1, d1, y2, m2, d2);
	while (y1 < y2 || m1 < m2 || d1 < d2)
	{
		d1++;
		if (d1 == days[lev(y1)][m1] + 1)
		{
			m1++;
			d1 = 1;
		}
		if (m1 == 13)
		{
			y1++;
			m1 = 1;
		}
		count++;
	}
	printf("%d\n", count);
	return 0;
}