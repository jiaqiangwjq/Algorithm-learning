/*题目描述
输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）。

输入
测试数据有多组，输入n(1<=n<=200)，接着输入n个数，然后输入x。

输出
对于每组输入,请输出结果。

样例输入
4
1 2 3 4
3
样例输出
2*/

/*这道题很简单，就是题目要求 !多组测试数据! 这一点需要注意*/
#include<cstdio>
int num[210];
int main()
{
	int n, number;
	while (scanf("%d", &n) != EOF)	//多组测试数据 要记得这样写！
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}

		scanf("%d", &number);
		int i;
		for (i = 0; i < n; i++)
		{
			if (num[i] == number)
			{
				printf("%d\n", i);
				break;
			}
		}
		if (i == n)
			printf("-1\n");
	}
	return 0;
}