/*
斐波那契数列的 动态规划 写法
*/

#include <cstdio>
#define MAXN 100
int dp[MAXN];

int F(int n)
{
    if(n == 0 || n == 1)    //递归边界
        return 1;   

    /*
    用 dp[n] == -1 表示当前 F(n) 还没有被计算过
    所以，main 函数里应该有 
    memset(dp, -1, sizeof(dp))
    */
    if(dp[n] != -1)     //已经计算过，直接返回结果，不再重复计算
        return dp[n];
    else
    {
        dp[n] = F(n-1) + F(n-2);    //计算 F(n), 并保存至 dp[n]
        return dp[n];   //返回 F(n) 的结果
    }
}