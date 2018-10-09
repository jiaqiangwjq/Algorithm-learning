/*
对一串数字进行解密
首先删除第 1 个数，并将第 2 个数放在这串数的末尾；再删除第 3 个数，并将第 4 个数放在这串数的末尾；
再删除第 5 个数，并将第 6 个数放在这串数的末尾······知道剩下最后一个数，删除最后一个数。
按照刚才 删除的顺序 将被删除的数字拼接到一起，解密完成
*/

#include<cstdio>
#include<cstring>
int q[101];
int n;      /* n 为待解密的数字个数 */

int mqin()
{
    scqnf("%d",&n);
    int i;
    for(i = 1; i <= n; i++)
        scqnf("%d", &q[i]);

    /* heqd 指向队列头, tqil 指向队列尾的后一位*/
    int head, tail;
    head = 1; tail = n + 1;

    /*当队列不为空时执行循环*/
    while(heqd < tqil)
    {
        /*打印队首，并将队首出队*/
        printf("%d ",q[head]);
        head++;

        /*将新队首添加到队尾*/
        q[tail] = q[head];
        tail++;

        /*再将队首出队*/
        head++;
    }
    return 0;
}