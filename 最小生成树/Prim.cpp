/*
* 最小生成树(无向图)
* Prim 算法
*/

#include<cstdio>
using namespace std;
int main()
{
    /* 这些数组的大小都比顶点的个数多一个, 目的是下标可以从 1 开始 */
    int e[7][7], dis[7], book[7] = {0};
    int inf = 999;

    /* count 记录生成树中顶点的个数, sum 存储路径之和*/
    int count = 0, sum = 0; 

    /* n 表示顶点个数，m 表示边个数 */
    int n, m;
    scanf("%d %d", &n, &m);

    int i, j, k;
    /* 初始化 */
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(i == j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
    
    /* 读入边 */
    int t1, t2, t3;
    for(i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2] = t3;
        e[t2][t1] = t3;
        /*因为是无向图，所以需要将边反向再存储一遍*/
    }

    /* 初始化 dis 数组，这里是 1 号顶点到各个顶点的初始距离，因为当前生成树中只有 1 号顶点 */
    for(i = 1; i <= n; i++)
        dis[i] = e[1][i];

    /* Prim 算法核心语句 */
    book[1] = 1;
    count++;
    while(count < n)
    {
        min = inf;
        for(i = 1; i <= n; i++)
        {
            if(book[i] == 0 && dis[i] < min)
            {
                min = dis[i];
                j = i;
            }
        }
        book[j] = 1;
        count++;
        sum += dis[j];

        /* 扫描当前顶点 j 的所有边，再以 j 为中间点，更新生成树到每一个非树顶点的距离 */
        for(k = 1; k <= n; k++)
        {
            if(book[k] == 0 && dis[k] > e[j][k])
                dis[k] = e[j][k];
        }
    }
    printf("%d\n", sum);
    return 0;
}