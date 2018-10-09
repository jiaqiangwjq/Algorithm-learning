/*
棋盘覆盖问题

dr:特殊方格的行号
dc:特殊方格的列号

tr:棋盘的行号
tc:棋盘的列号
*/

#include<cstdio>
int num = 0;
int matrix[100][100];   /*棋盘*/

void chessBoard(int tr, int tc, int dr, int dc, int size)
{
    /*对于四中形状L行骨牌的表示:引入参数t，初始化为0，每进入一轮递归，t++ */
    int s, t;
    if(size == 1)
        return;

    /*分割棋盘*/
    s = size / 2;

    /* L 型骨牌号*/
    t = ++num;

    /*覆盖左上角棋盘*/
    if(dr < tr+s && dc < tc+s)
    {
        /*特殊方格在此棋盘中*/
        chessBoard(tr, tc, dr, dc, s);
    }
    else
    {
        /*用 t 号 L 型骨牌覆盖右下角*/
        matrix[tr+s-1][tc+s-1] = t;

        /*覆盖其余方格*/
        chessBoard(tr, tc, tr+s-1, tc+s-1, s);
    }

    /*覆盖右上角棋盘*/
    if(dr < tr+s && dc >= tc+s)
    {
        /*特殊方格在此棋盘中*/
        chessBoard(tr, tc+s, dr, dc, s);
    }
    else
    {
        /*用 t 号 L 型骨牌覆盖左下角*/
        matrix[tr+s-1][tc+s] = t;

        /*覆盖其余方格*/
        chessBoard(tr, tc, tr+s, tr+s-1, s);
    }

    /*覆盖左下角棋盘*/
    if(dr >= tr+s && dc < tc+s)
    {
        /*特殊方格在此棋盘中*/
        chessBoard(tr+s, tc, dr, dc, s);
    }
    else
    {
        /*用 t 号 L 型骨牌覆盖右上角*/
        matrix[tr+s][tc+s-1] = t;

        /*覆盖其余方格*/
        chessBoard(tr+s, tc, tr+s, tc+s-1, s);
    }

    /*覆盖右下角棋盘*/
    if(dr >= tr+s && dc >= tc+s)
    {
        /*特殊方格在此棋盘中*/
        chessBoard(tr+s, tc+s, dr, dc, s);
    }
    else
    {
        /*用 t 号 L 型骨牌覆盖左上角*/
        matrix[tr+s][tc+s] = t;

        /*覆盖其余方格*/
        chessBoard(tr+s, tc+s, tr+s, tc+s, s);
    }
}