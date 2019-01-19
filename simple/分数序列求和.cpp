/*
题目描述
有如下分数序列
2/1，3/2，5/3，8/5，13/8，21/13…

求出次数列的前20项之和。

请将结果的数据类型定义为double类型。

输入
无
输出
小数点后保留6位小数，末尾输出换行。
样例输入
无
样例输出
32.660261
  */

#include<stdio.h>
int main()
{
	double m1 = 1.0, m2 = 2.0;
	double z1 = 2.0, z2 = 3.0;
	double z3, m3;

	double sum = 2.0 + 3.0/2.0;
	for (int i = 3; i <= 20; i++)
	{
		z3 = z1 + z2;
		m3 = m1 + m2;
		sum += z3 / m3;

		z1 = z2;
		z2 = z3;
		m1 = m2;
		m2 = m3;
	}
	printf("%.6f\n", sum);
	return 0;
}