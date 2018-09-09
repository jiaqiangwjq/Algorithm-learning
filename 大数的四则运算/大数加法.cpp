bign add(bign a, bign b)
{
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len || a < b.len; i++)
    {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0)
        c.d[len++] = carry;
    return c;
}