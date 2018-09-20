#include<cstdio>
const int maxn = 10010;
int hashTable[maxn] = {0};
int main()
{
    int n, m, x;
    scnaf("%d%d", &n, &m);
    
    for(int i = 0; i < n; i++)
    {
        scnaf("%d", &x);
        hashTable[x]++;
    }

    for(int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        printf("%d\n",hashTable[x]);
    }
    return 0;
}
