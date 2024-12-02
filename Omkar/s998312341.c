#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int
int main(void)
{
    int s[3][3] = {0};
    int i, j, k, n, m, l;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &m);
            s[i][j] = m;
        }
    }
    scanf("%d", &n);
    for (k = 0; k < n; k++)
    {
        scanf("%d", &l);
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (s[i][j] == l)
                    s[i][j] = 0;
            }
        }
    }
    if (((s[0][0] == s[0][1]) && (s[0][0] == s[0][2])) || ((s[1][0] == s[1][1]) && (s[1][0] == s[1][2])) || ((s[2][0] == s[2][1]) && (s[2][0] == s[2][2])) || ((s[0][0] == s[1][0]) && (s[0][0] == s[2][0])) || ((s[0][1] == s[1][1]) && (s[0][1] == s[2][1])) || ((s[0][2] == s[1][2]) && (s[0][2] == s[2][2])) || ((s[0][0] == s[1][1]) && (s[0][0] == s[2][2])) || ((s[0][2] == s[1][1]) && (s[0][2] == s[2][0])))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}