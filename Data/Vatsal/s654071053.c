#include <stdio.h>
#include <stdlib.h>
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)


int main()
{
    int N;
    int ans[101][101];
    int hmax[101][101];
    scanf("%d", &N);

    REP(l, 101) REP(w, 101)
    {
        ans[l][w] = -1;
    }
    REP(l, 101) REP(w, 101)
    {
        hmax[l][w] = 1000000300;
    }

    REP(i, N)
    {
        int x, y, h;
        scanf("%d %d %d", &x, &y, &h);

        REP(l, 101) REP(w, 101) if (ans[l][w] != -2)
        {
            int estimated_top = h + abs(l - x) + abs(w - y);
            if (h > 0)
            {
                if (ans[l][w] == -1) ans[l][w] = estimated_top;
                else if (ans[l][w] != estimated_top) ans[l][w] = -2;
            }
            else
            {
                if (estimated_top < hmax[l][w]) hmax[l][w] = estimated_top;
            }
        }
    }

    REP(l, 101) REP(w, 101) if (ans[l][w] > 0 && hmax[l][w] >= ans[l][w]) printf("%d %d %d", l, w, ans[l][w]);
}
