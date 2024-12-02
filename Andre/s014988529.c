#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int gcd(int x, int y)
{
    int r;
    r = x % y;
    while (r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
int getrand(int min, int max)
{
    return min + (int)(rand()*(max - min + 1) / (1 + RAND_MAX));
}
int main()
{
    int n;
    scanf("%d", &n);
    int ans[20000];
    int i;
    int x;
    int sum;
    int j;
    ans[0] = 2;
    ans[1] = 5;
    ans[2] = 63;
    ans[3] = 20;
    for (;;)
    {
        srand((unsigned int)time(NULL));
        sum = 90;
        x = 0;
        for (i = 4; i < n; i++)
        {
            x = 0;
            ans[i] = getrand(1, 30000);
            for (j = 0; j < i; j++)
            {
                if (ans[i] == ans[j])
                {
                    i -= 1;
                    x++;
                    break;
                }
            }
            if(x==0)
                sum += ans[i];
        }
        x = 0;
        for (i = 0; i < n; i++)
        {
            if (gcd(ans[i], sum - ans[i]) == 1)
            {
                x++;
                break;
            }
        }
        if (x == 0)
        {
            for (i = 0; i < n - 1; i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[n - 1]);
            return 0;
        }
    }
}