#include <stdio.h>
#include <stdlib.h>
#define N 110

void main()
{
    int x, n, p[N], check[N], min, sub = N;
    for (int i = 0; i < n; i++)
        check[i] = 0;

    scanf("%d %d", &x, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (int i = 0; i < n; i++)
        check[p[i]] = 1;

    for (int i = 0; i < N; i++)
    {
        if (check[i] == 0)
        {
            if (abs(x - i) < sub)
            {
                min = i;
                sub = x - i;
            }
        }
    }

    printf("%d", min);
}