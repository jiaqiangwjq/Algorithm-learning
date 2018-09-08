/*
��������
  */
#include<stdio.h>
#include<string.h>
#define MAX 100

/*
����SubStract���ܣ�
�ó���Ϊlen1�Ĵ�����p1��ȥ����Ϊlen2�Ĵ�����p2
�������p1�У�����ֵ�������ĳ���
������������-1 �� ���ù�������0
 */ 
int substract(int *p1, int len1, int *p2, int len2)
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)
	{
		for (i = len1 - 1; i >= 0; i--)	//�ж� p1 > p2
		{
			if (p1[i] > p2[i])
				break;
			else if (p1[i] < p2[i])
				return -1;
		}
	}
	for (i = 0; i < len1; i++)	//������
	{
		p1[i] -= p2[i];
		if (p1[i] < 0)
		{
			p1[i] += 10;
			p1[i + 1]--;
		}
	}
	for (i = len1 - 1; i >= 0; i--)	//���ҽ�������λ
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
	int dvalue;	//���������λ��
	int ntemp;	//substract ��������ֵ
	int num_a[MAX] = { 0 };	//������
	int num_b[MAX] = { 0 };	//����
	int num_c[MAX] = { 0 };	//��

	len1 = strlen(num1);
	len2 = strlen(num2);

	for (j = 0, i = len1 - 1; i >= 0; j++, i--)
		num_a[j] = num1[i] - '0';
	for (j = 0, i = len2 - 1; i >= 0; j++, i--)
		num_b[j] = num2[i] - '0';

	if (len1 < len2)	//������С�ڳ���
		return -1;
	dvalue = len1 - len2;

	//����������ʹ�ó����ͱ��������
	for (i = len1 - 1; i >= 0; i--)
	{
		if (i >= dvalue)
			num_b[i] = num_b[i - dvalue];
		else
			num_b[i] = 0;	//��λ�� 0
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
	//�����̵�λ���������̷��� sum �ַ�������

	//������λ 0����ȡ�̵�λ��
	for (i = MAX - 1; num_c[i] == 0 && i >= 0; i--);
	if (i >= 0)
		len1 = i + 1;	//����λ��

	//��������Ƶ� sum ������
	for (j = 0; i >= 0; i--, j++)
		sum[j] = num_c[i] + '0';
	sum[j] = '\0';
	return len;
}

