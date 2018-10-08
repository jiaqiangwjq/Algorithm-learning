/*
桶排序
*/

#include<cstdio>
#include<cstring>
int main()
{
    int book[1001], i, j, t, n;

    //初始化数组
    memset(book, 0, sizeof(book));

    //输入一个数 n, 表示接下来有 n 个数  
    scanf("%d",&n);

    for(i = 1; i <= n; i++)
    {
        //把每一个数读到变量 t 中
        scanf("%d",&t);

        //对编号为 t 的桶进行计数
        book[t]++;
    }

    for(i = 0; i <= 1000; i++)  //依次判断编号 0 ~ 1000 的桶
        for(j = 1; j <= book[i]; j++)   //出现了几次就将桶的编号打印几次
            print("%d ",i);

    return 0;
}