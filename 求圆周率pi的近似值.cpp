/*
题目描述
用如下公式
π/4=1-1/3+1/5-1/7...求π的近似值

求圆周率PI的近似值，直到发现某一项的绝对值小于10-6为止（该项不累加）。

要求输出的结果总宽度占10位，其中小数部分为8位。

程序中使用浮点型数据时，请定义为双精度double类型。

如果需要计算绝对值，可以使用C语言数学库提供的函数fabs，如求x的绝对值，则为fabs(x).

输入
无

输出
PI=圆周率的近似值

输出的结果总宽度占10位，其中小数部分为8位。

末尾输出换行。

样例输入
无
样例输出
PI=3.14159065
  */

#include<stdio.h>
#include<math.h>
#define eps 1e-6
int main()
{
	int n = 1;
	double pi_4 = 0.0,x = 999;
	
	while (x >= eps)
	{
		x = 1.0 / double((2 * n - 1));
		++n;
	}

	int flag = 1;
	for (int i = 1; i <= n; i++)
	{
		pi_4 += flag * (1.0 / double((2 * i - 1)));
		flag *= -1;
	}
	double pi = 4 * pi_4;
	printf("PI=%10.8f\n", pi);
}