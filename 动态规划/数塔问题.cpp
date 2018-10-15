/*
将一些数字排列成数塔的形状，第一层有 1 个数字，第二层有 2 个数字······
第 n 层有 n 个数字。现在要从第一层走到第 n 层，每次只能走到下一层连接的两个数字中的一个，
问：最后将路径上所有数字的和相加后得到的和最大是多少？
*/

/*
具体图可见：算法笔记 P427
思路如下：
    1. 如果要求出 dp[i][j],那么一定要先求出它的两个子问题 ———— "从位置 (i+1,j) 
    到达最底层的最大和 dp[i+1][j]" 和 "从位置 (i+1,j+1) 到达最底层的最大和 dp[i+1][j+1]"。
    于是，dp[i][j] 就是 dp[i+1][j] 和 dp[i+1][j+1] 的最大值再加上 f[i][j],写成式子就是：
    dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j]; 这就是状态转移方程

    2. 那么，如果总是将层号增大，什么时候到头呢？可以发现：数塔的最后一层的 dp 值总是等于元素本身，
    即 dp[n][j] == f[n][j];(1 <= j <= n) 这就是边界！
*/

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn];
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i = 1; i <= n; i++)     /*下标从 1 开始*/
        for(int j = 1; j <= i; j++)
            scanf("%d",&f[i][j]);   /*输入数塔*/

    //边界
    for(int j = 1; j <= n; j++)
        dp[n][j] = f[n][j];

    /*从第 n-1 层不断往上计算出 dp[i][j]*/
    for(int i = n-1; i >= 1; i--)
        for(int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];     /*状态转移方程*/

    printf("%d\n",dp[1][1]);    /*dp[1][1] 即为所需要的答案*/
    return 0;
}