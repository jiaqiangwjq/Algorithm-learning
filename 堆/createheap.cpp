/*
* 利用不断向下调整的方式建立最小堆
* 使用最小堆实现从小到大的堆排序
* 完全二叉树以一维数组的形式实现
*/

#include<cstdio>
using namespace std;
int h[101];     /* 用来存放堆的数组 */
int n;     /* 堆元素的个数 */
void create()
{
    int i;

    /* 从最后一个非叶结点到第 i 个结点依次进行向上调整 */
    for(i = n / 2; i >= 1; i--)
        siftdown(i);
}

int main()
{
    int i, num;

    /* 读入要排序的数字的个数 */
    scanf("%d", &num);
    
    n = num;
    for(i = 1; i <= num; i++)
        scanf("%d", &h[i]);
    create();

    /* 删除顶部元素，连续删除 n 次，其实也就是从小到大把元素数出来 */
    for(i = 1; i <= numl i++)
        printf("%d ", deletemin());

    return 0;
}

/* 删除顶点最小值 */
int deletemin()
{
    int t;
    
    t = h[1];   /* 堆顶点的值 */
    h[1] = h[n];    /* 将堆的最后一个顶点赋值到堆顶 */
    n--;    /* 堆的元素减一 */

    siftdown(1);
    return t;
}