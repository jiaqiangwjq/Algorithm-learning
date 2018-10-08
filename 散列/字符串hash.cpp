/*字符串 hash 是指将一个字符串 s 映射为一个整数，
使得该整数可以尽可能唯一地代表字符串 s
*/

/*假设字符串只由大写字符 A~Z 组成，不妨把 A~Z 视为 0~25，
这样就把 26 个大写字母对应到了 26 进制中
*/

int hashFunc(char s[], int len) //hash 函数，将字符串 s 转换成整数
{
    int id = 0;
    for(int i = 0; i < len; i++)
        id = id*26 + (s[i] - 'A');  //26 进制转换成 10 进制
    return id;
}


/*如果有大写字母、小写字母和数字组成的字符串，则对应的是 62 进制
26 + 26 + 10 = 62
*/

int hashFunc(char s[], int len)
{
    int id = 0;
    for(int i = 0; i < len; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            id = id*62 + (s[i] - 'A');
        if(s[i] >= 'a' && s[i] <= 'z')
            id = id*62 + (s[i] - 'a') + 26;
        if(s[i] >= '0' && s[i] <= '9')
            id = id*62 + (s[i] - '0') +  10;    
    }
    return id;
}