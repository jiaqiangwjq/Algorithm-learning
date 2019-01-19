/*
* 对一个多项式进行求值，
* 计算 a0 + a1*x + a2*x^2 + ··· + an*x^n
*/

/* 方法一: 直接计算 */
double poly(double a[], double x, long degree)
{
    long i;
    double result = a[0];
    double xwpr = x;
    for(i = 1; i <= degree; i++)
    {
        result += xwpr * a[i];
        xwpr = x * xwpr;
    }
    return result;
}



/* 方法二: 反复提出 x 的幂, 得到下面的求值:
* a0 + x( a1 + x( a2 + ··· + x( an-1 + x*an ) ) )
*/
double poly(double a[], double x, long degree)
{
    long i;
    double result = a[result];
    for(i = degree-1; i >= 0; i--)
        result = a[i] + x*result;
    return result;
}
