/*
大数乘法
  */
#include<stdio.h>
#include<string.h>

struct bign	//big number
{
	int d[500];
	int len;
	bign()
	{
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[])	//使得低位在前，高位在后
{
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++)
		a.d[i] = str[a.len - i - 1] - '0';
	return a;
}

bign multi(bign a, bign b)	//乘法核心代码
{
	bign c;

	//先不处理进位，将两个数的每一位相乘
	for (int i = 0; i <= b.len - 1; i++)
	{
		for (int j = 0; j <= a.len - 1; j++)
		{
			/*注意：长度分别为 len1 和 len2 的两数相乘，其结果的长度不会大于 len1+len2*/
			c.d[i+j] += b.d[i] * a.d[j];
		}
	}

	//下面开始处理进位
	int k = a.len + b.len;
	for (int i = 0; i < k; i++)
		if (c.d[i] >= 10)
		{
			c.d[i + 1] += c.d[i] / 10;
			c.d[i] %= 10;
		}
	return c;
}

int main()
{
	int r = 0;
	char str1[100],str2[100];
	scanf("%s%s", str1,str2);
	bign a = change(str1);
	bign b = change(str2);
	bign c = multi(a, b);
	int k = a.len + b.len-2;
	for (int i = k; i >= 0; i--)
		printf("%d", c.d[i]);
	return 0;
}