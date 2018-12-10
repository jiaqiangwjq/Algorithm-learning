/*
* 深度优先搜索遍历图
* 该图使用一个二维矩阵存储, 如下所示
*   
*   0 1 1 ∞ 1
*   1 0 ∞ 1 ∞
*   1 ∞ 0 ∞ 1
*   ∞ 1 ∞ 0 ∞
*   1 ∞ 1 ∞ 0
*
*/

#include<cstdio>
int book[101], sum, n, m, e[101][101];
#define inf 99999

void dfs(int cur)   /* cur 是当前所在节点的编号 */
{
    int i;
    printf("%d ", cur);
    sum++;      /* 每访问一个节点, sum 就加一 */
    
    if(sum == n)
        return;     /* 所有节点都已访问过，就退出 */

    /* 从 1 号顶点到 n 号顶点依次尝试 */
    for(i = 1; i <= n; i++)
    {
        /* 判断当前顶点 cur 到顶点 i 是否有边, 并判断顶点 i 是否已访问过 */
        if(e[cur][i] == 1 && book[i] == 0)
        {
            book[i] = 1;    /* 标记顶点 i 已访问过 */
            dfs(i);     /* 从顶点 i 再出发继续遍历 */
        }
    }
    return;     
}

int main()
{
    int i, j, m, a, b;
    scanf("%d %d", &n, &m);

    /* 初始化二维矩阵 */
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(i == j)e[i][j] = 0;
            else e[i][j] = inf;
    for(i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;        /* 这里是无向图，所以要反向也存储一下 */
    }

    /* 从 1 号顶点出发，开始遍历 */
    book[1] = 1;
    dfs(1);

    return 0;
}