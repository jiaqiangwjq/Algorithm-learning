/*
大数除法
  */
#include<stdio.h>
#include<string.h>
#define MAX 100

/*
函数SubStract功能：
用长度为len1的大整数p1减去长度为len2的大整数p2
结果存在p1中，返回值代表结果的长度
不够减：返回-1 ， 正好够：返回0
 */ 
int substract(int *p1, int len1, int *p2, int len2)
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)
	{
		for (i = len1 - 1; i >= 0; i--)	//判断 p1 > p2
		{
			if (p1[i] > p2[i])
				break;
			else if (p1[i] < p2[i])
				return -1;
		}
	}
	for (i = 0; i < len1; i++)	//做减法
	{
		p1[i] -= p2[i];
		if (p1[i] < 0)
		{
			p1[i] += 10;
			p1[i + 1]--;
		}
	}
	for (i = len1 - 1; i >= 0; i--)	//查找结果的最高位
	{
		if (p1[i])
			return i + 1;
	}
	return 0;
}

int divide(char num1[], char num2[], char sum[])
{
	int k, i, j;
	int len1, len2, len = 0;
	int dvalue;	//两大数相差位数
	int ntemp;	//substract 函数返回值
	int num_a[MAX] = { 0 };	//被除数
	int num_b[MAX] = { 0 };	//除数
	int num_c[MAX] = { 0 };	//商

	len1 = strlen(num1);
	len2 = strlen(num2);

	for (j = 0, i = len1 - 1; i >= 0; j++, i--)
		num_a[j] = num1[i] - '0';
	for (j = 0, i = len2 - 1; i >= 0; j++, i--)
		num_b[j] = num2[i] - '0';

	if (len1 < len2)	//被除数小于除数
		return -1;
	dvalue = len1 - len2;

	//将除数扩大，使得除数和被除数相等
	for (i = len1 - 1; i >= 0; i--)
	{
		if (i >= dvalue)
			num_b[i] = num_b[i - dvalue];
		else
			num_b[i] = 0;	//低位置 0
	}
	len2 = len1;
	for (j = 0; j <= dvalue; j++)
	{
		while ((ntemp = substract(num_a, len1, num_b + j, len2 - j)) >= 0)
		{
			len1 = ntemp;
			num_c[dvalue - j]++;
		}
	}
	//计算商的位数，并将商放在 sum 字符数组中

	//跳过高位 0，获取商的位数
	for (i = MAX - 1; num_c[i] == 0 && i >= 0; i--);
	if (i >= 0)
		len1 = i + 1;	//保存位数

	//将结果复制到 sum 数组中
	for (j = 0; i >= 0; i--, j++)
		sum[j] = num_c[i] + '0';
	sum[j] = '\0';
	return len;
}

