/*给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

输出格式：
每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
*/
#include<cstdio>
#include<cstring>
char s[50][50];
char s1[90];
int main()
{
	fgets(s1,90,stdin);	//使用 gets 居然会报错
	
	int len = strlen(s1);
	//因为 fgets()的原因，需要去掉倒数第二个换行 \n
	if(s1[len - 1] == '\n' && s1[len] == '\0') 
	{
	    s1[len - 1] = '\0';
	}

	int j = 0;
	int k = 0;
	for(int i = 0; i < len; i++)
	{
		if(s1[i] == ' ')
		{
			j = 0;
			k++;
			continue;
		}
		else
			{
				s[k][j++] = s1[i];
			}
	}
	for(int i = k; i >= 0; i--)
	{
		if(i > 0)
			printf("%s ",s[i]);
		else
			printf("%s",s[i]);
	}
	return 0;
}
