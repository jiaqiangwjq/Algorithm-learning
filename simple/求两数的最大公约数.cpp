/* 求两个正整数的最大公约数
* 欧几里得算法: Gcd(a, b) = Gcd(b, a mod b)
*/

int Gcd(int M, int N)
{
    int Rem;    /* 余数 */
    while(N > 0)
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;   /* 最大公约数 */
}