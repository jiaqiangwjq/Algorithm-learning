/*
* 广度优先搜索 走迷宫
* Breadth First Search
*/

#include<cstdio>
using namespace std;

struct node{
    int x;
    int y;
    int f;  /* 父亲在队列中的编号 */
    int s;  /* 步数 */
}
struct node que[2501];  /*地图大小为 50*50 */
int n, m, p, q;

int main()
{
    int i, j, startx, starty, tx, ty;

    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            scanf("%d",&a[i][j]);

    scanf("%d %d %d %d", &startx, &starty, &p, &q);

    bfs(startx, starty, 0);
    
    return 0;
}

void bfs(int startx, int starty, int step)
{
    int k, flag;
    /* 定义方向数组 */
    int next[4][2] = {
        {0, 1},     //向右走
        {0, -1},
        {-1, 0},    //向上走
        {1, 0}
    }

    int head, tail;
    head = 1;
    tail = 1;

    /* 往队列插入迷宫入口坐标 */
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    book[startx][starty] = 1;

    flag = 0;   /* 用来标记是否到达目标点 */

    /* 当队列不为空的时候循环 */
    while(head < tail)
    {
        /* 枚举 4 个方向 */
        for(k = 0; k <= 3; k++)
        {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];

            /* 判断是否越界 */
            if(tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            
            /* 判断是否是障碍物或已经在路径中 */
            if(a[tx][ty] == 0 && book[tx][ty] == 0)
            {
                /* 把这个点标记为已走过 */
                /* 注意 BFS 每个点只入队一次，所以和 DFS 不同，不需要将 book 数组还原 */
                book[tx][ty] = 1;

                /* 插入新的点到队列中 */
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].s = que[head].s + 1;
                tail++;
            }
            /* 如果到目标点了，停止扩展，任务结束，退出循环 */
            if(tx == p && ty == q)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
        /* 当一个点扩展结束后，head++ 才能对后面的点再进行扩展 */    
        head++;
    }
    printf("%d", que[tail-1].s);
}