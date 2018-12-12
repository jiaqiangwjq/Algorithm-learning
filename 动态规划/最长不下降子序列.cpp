/*
在一个数字序列中，找到一个最长的子序列(可以不连续),使得
这个子序列是不下降的(非递减的)
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100;
int A[N], dp[N];
int main()
{
    int n;
    scanf("%d",&n)
    for(int i = 1; i <= n; i++)
        scanf("%d",&A[i]);
    
    int ans = -1;   /*记录最大的 dp[i]*/

    for(int i = 1; i <= n; i++)     /*按顺序计算出 dp[i] 的值*/
    {
        dp[i] = 1; /*边界初始条件(即先假设每个元素自成一个子序列)*/

        for(int j = 1; j < i; j++)
        {
            if(A[i] >= A[j] && (dp[j]+1 > dp[i]) )
            {
                /*状态转移方程, 用以更新 dp[i]*/
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}