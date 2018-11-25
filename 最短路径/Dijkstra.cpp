/*
* 单源最短路径
* 求的是某个固定的点，到其他所有点的最短距离
*/

#include <cstdio>
using namespace std;
int main()
{
    int e[10][10], dis[10], book[10];
    int inf = 999;

    /* n 表示顶点个数，m 表示边的条数 */
    int n, m;
    scanf("%d %d", &n, &m);

    /* 初始化 */
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(i == j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
    
    /* 读入边 */
    int t1, t2, t3;
    for(i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2] = t3;
    }

    /* 初始化 dis 数组, 这里是 1 号顶点到其余各个顶点的初始距离 */
    for(i = 1; i <= n; i++)
        dis[i] = e[1][i];
    
    /* book 数组初始化 */
    for(i = 1; i <= n; i++)
        book[i] = 0;
    book[1] = 1;


    /* Dijkstra 算法核心语句 */
    int u, min, v;
    for(i = 1; i <= n-1; i++)
    {
        /* 找到离 1 号顶点最近的顶点 */
        min = inf;
        for(j = 1; j <= n; j++)
        {
            /* 在未松弛的点中找离源点最近的点 */
            if(book[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                u = j;
            }
        }
        /* 从离源点最近的那个点开始松弛 */
        book[u] = 1;
        for(v = 1; v <= n; v++)
        {
            if(e[u][v] < inf)
            {
                if(dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
    }

    /* 输出最终结果 */
    for(i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    
    return 0;
}