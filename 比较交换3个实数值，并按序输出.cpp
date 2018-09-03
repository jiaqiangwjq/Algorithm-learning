/*
题目描述
从键盘输入3个实数a, b, c，通过比较交换，将最小值存储在变量a中，最大值存储在变量c中，中间值存储在变量b中，并按照从小到大的顺序输出这三个数a, b, c。

末尾输出换行。

输入
输入以空格分隔的三个实数
输出
按照从小到大的顺序输出这三个实数，中间以空格分隔，最小值在前，最大值在后。小数点后保留2位小数。

注意末尾的换行。

样例输入
3 7 1
样例输出
1.00 3.00 7.00
*/

#include<stdio.h>
int main()
{
	double a,b,c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double arr[3] = { a,b,c };
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 0; j < 3 - j; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("%.2f %.2f %.2f\n", arr[0], arr[1], arr[2]);
	return 0;
}