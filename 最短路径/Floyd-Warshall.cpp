/*
* 求任意两点间的最短路径
* 注意哦！这和单源最短路径可不一样哦！
*/

#include <cstdio>
using namespace std;
int inf = 999;
int main()
{
    int e[10][10], k, i, j, n, m, t1, t2, t3;
    
    /* 读入 n 和 m, n 表示顶点个数，m 表示边的条数 */
    scanf("%d %d", &n, &m);

    /* 初始化 */
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(i == j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
    
    /* 读入边 */
    for(i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2] = t3;
    }

    /* Floyd-Warshall 算法核心语句 */
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(e[i][j] > e[i][k] + e[k][j])
                    e[i][j] = e[i][k] + e[k][j];
    
    /* 输出最终的结果 */
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%10d", e[i][j]);
        
        printf("\n");
    }
    return 0;
}