/*
题目描述
写一个函数，将一个字符串中的元音字母复制到另一个字符串中。在主函数中输入一个字符串，通过调用该函数，得到一个有该字符串中的元音字母组成的一个字符串，并输出。
输入
一个字符串（一行字符）。

输出
该字符串所有元音字母构成的字符串。行尾换行。
样例输入
CLanguage
样例输出
auae
  */
#include<stdio.h>
#include<string.h>

int main()
{
	char s1[50],s2[50];
	scanf("%s", s1);
	int len = strlen(s1);
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
		{
			s2[j++] = s1[i];
		}
		}
	for (int i = 0; i < j; i++)
		printf("%c", s2[i]);
	printf("\n");
	
	return 0;
}