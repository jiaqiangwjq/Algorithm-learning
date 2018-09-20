#include<cstdio>
const int maxn = 11;

//P 中存放的是当前排列，hashTable 记录整数 x 是否已经在 P 中
int n, P[maxn], hashTable[maxn] = {false};

void generateP(int index)   //当前处理排列的第 index 位
{
    if(index == n + 1)  //递归边界，已经处理完排列的 1~n 位
    {
        for(int i = 1; i <= n; i++)
            printf("%d ",P[i]);
        return;
    }
    
    for(int x = 1; x <= n; x++) //枚举 1~n,试图将 x 填入 P 中
    {
        if(hashTable[x] == false)
        {
            P[index] = x;   //令 P 的第 index 位为 x
            hashTable[x] = true;
            generateP(index + 1);   //处理排列的 index+1 位
            hashTable[x] = false;   //已处理完排列的第 index 位为 x 的子问题，还原状态
        }
    }
    return;
}