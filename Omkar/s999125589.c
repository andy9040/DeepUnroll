#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, l, i, j, k, m;
    char s[100][100], tmp[100];
    scanf("%d %d", &n, &l);
    for (i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
    }

    for (k = n - 1; k > 0; k--)
    {
        for (j = 0; j < k; j++)
        {
            for (i = 0; i < l; i++)
            {
                if (s[j][i] > s[j + 1][i]) {
                    for (m = 0; m < l; m++)
                    {
                        tmp[m] = s[j + 1][m];
                        s[j + 1][m] = s[j][m];
                        s[j][m] = tmp[m];
                    }
                    break;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%s\n", s[i]);
    }

    return 0;

}
