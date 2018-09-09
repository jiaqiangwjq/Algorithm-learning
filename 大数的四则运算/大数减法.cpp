bign sub(bign a, bign b)
{
    bign c;
    for(int i = 0; i < a.len-1 || i < b.len-1)
    {
        if(a.d[i] < b.d[i])
        {
            a.d[i+1]--;
            a.d[i] += 10;
        }
        c.d[len++] = a.d[i] - b.d[i];
    }

    //去除高位的 0，同时至少保留一位最低位
    while(c.len - 1 >= 1 && c.d[len - 1] == 0)
        c.len--;
    return c;
}