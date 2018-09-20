/*考虑到每行只能放置一个皇后，每列也只能放置一个皇后，那么如果把
n 列皇后所在的行数写出。将会是一个 1~n 的排列
*/

int count = 0;
const int maxn = 10;
int P[maxn], hashTable[maxn] = {false};
void generateP(int index)
{
    if(index == n+1)    //递归边界，生成一个排列
    {
        bool flag = true;   //flag 为 true,表示当前排列为一个合法方案

        for(int i = 1; i <= n; i++) //遍历任意两个皇后
        {
            for(int j = i+1; j <= n; j++)
                if(abs(i - j) == abs(P[i] - P[j]))  //如果在一条对角线上:i、j 为列号，P[i]、P[j] 为行号
                    flag = false;
        }
        if(flag)
            count++;    //若当前方案合法，count 加一
        return;
    }

    for(int x = 1; x <= n; x++)
    {
        if(hashTable[x] == false)
        {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}



/*回溯法优化 n 皇后问题
当已经放置了一部分皇后后，可能剩下的皇后无论怎样放置都不可能合法，
此时就没必要往下递归了，直接返回上一层
*/
void generateP(int index)
{
    if(index == n+1)    //递归边界
    {
        count++;
        return;
    }

    for(int x = 1; x <= n; x++)
    {
        if(hashTable[x] == false)
        {
            bool flag = true;   //flag 为 true 表示当前皇后不会和之前的皇后冲突(这里是先假设不冲突)
            
            for(int pre = 1; pre < index; pre++)    //遍历之前的皇后
            {
                if(abs(pre - index) == abs(P[pre] - P[index]))  //与之前的皇后在一条对角线上
                {
                    flag = false;
                    break;
                }
            }

            if(flag)    //flag 为 true 表示当前皇后不会和之前的皇后冲突
            {
                P[index] = x;
                hashTable[x] = true;
                generateP(index + 1);
                hashTable[x] = false;
            }
        }
    }
}

