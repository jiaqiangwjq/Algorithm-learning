#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char words[81][81];

int main(void)
{
	char s[81];
	cin.getline(s, 81);

	int len = strlen(s);

	int i = 0, j = 0;

	for (int k = 0; k < len; k++)
	{
		if (s[k] == ' ')
		{
			words[i][j] = '\0';
			j = 0;
			++i;
		}
		else
		{
			words[i][j++] = s[k];
		}
	}

	for (; i >= 0; i--)
	{
		printf("%s", words[i]);
		if (i > 0)
			printf(" ");
	}

	return 0;
}