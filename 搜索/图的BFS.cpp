/*
* 图的广度优先搜索
*
* 主要思想：首先以一个未被访问过的顶点作为起始顶点，访问其所有相邻的顶点，
*           然后对每个相邻的顶点，再访问它们相邻的未被访问过的顶点，直到
*           所有顶点都被访问过
*/

#include<cstdio>
using namespace std;
#define inf 9999

int main()
{
    int i, j, n, m, a, b, cur, book[101] = {0}, e[101][101];
    int que[10001], head, tail;

    /* 初始化二维矩阵 */
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(i == j)e[i][j] = 0;
            else e[i][j] = inf;
    
    /* 读入顶点之间的边 */
    for(i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;    /* 无向图 */
    }

    /* 队列初始化 */
    head = 1;
    tail = 1;

    /* 从 1 号顶点出发，将 1 号顶点加入队列 */
    que[tail] = 1;
    tail++;
    book[1] = 1;    /* 标记 1 号顶点入队 */

    /* 当队列不为空的时候循环 */
    while(head < tail)
    {
        cur = que[head];    /* 当前正在访问的节点编号 */
        for(i = 1; i <= n; i++)
        {
            /* 判断从顶点 cur 到顶点 i 是否有边，并判断顶点 i 是否已经访问过 */
            if(e[cur][i] == 1 && book[i] == 0)
            {
                /* 将顶点 i 入队 */
                que[tail] = i;
                tail++;
                book[i] = 1;
            }

            /* 若 tail > n, 则表明所有顶点都已经被访问过 */
            if(tail > n)
                break;
        }
        head++;     /* 当一个顶点扩展结束后, head++, 继续向下扩展 */
    }

    /* 打印广度优先搜索访问节点的顺序 */
    for(i = 1; i <= n; i++)
        printf("%d ", que[i]);
    
    return 0;
}