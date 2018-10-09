/*
输入一串字符，判断它是否是回文串
*/

#include<cstdio>
#include<cstring>
char a[101], s[101];

int main()
{
    int i, len, mid, next, top;

    /*读入一串字符*/
    gets(a);

    /*求字符串的中点*/
    len = strlen(a);
    mid = len / 2 - 1;

    /*栈的初始化*/
    top = 0;
    for(i = 0; i <= mid; i++)
        s[top++] = a[i];

    /*判断字符串的长度是奇数还是偶数，并找出开始进行字符匹配的起始下标*/
    if(len & 1 == 0)
        next = mid - 1;
    else
        next = mid + 2;
    
    /*开始匹配*/
    for(i = next; i <= len-1; i++)
    {
        if(a[i] != s[top])
            break;
        top--;
    }

    /*若 top == 0, 则说明栈内所有字符匹配完毕*/
    if(top == 0)
        printf("YES");
    else
        printf("NO");

    return 0;
}