/*
�����˷�
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

bign change(char str[])	//ʹ�õ�λ��ǰ����λ�ں�
{
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++)
		a.d[i] = str[a.len - i - 1] - '0';
	return a;
}

bign multi(bign a, bign b)	//�˷����Ĵ���
{
	bign c;

	//�Ȳ������λ������������ÿһλ���
	for (int i = 0; i <= b.len - 1; i++)
	{
		for (int j = 0; j <= a.len - 1; j++)
		{
			/*ע�⣺���ȷֱ�Ϊ len1 �� len2 ��������ˣ������ĳ��Ȳ������ len1+len2*/
			c.d[i+j] += b.d[i] * a.d[j];
		}
	}

	//���濪ʼ�����λ
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