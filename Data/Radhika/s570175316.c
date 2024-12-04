#include <stdio.h>

int main(void)
{
    int n, m, sum=0;
    int a[100];

    scanf("%d%d", &n, &m);

    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);

    sum = 0;
    for (int i=0; i<n; i++)
        sum += a[i];

    int c=0;
    for (int i=0; i<n; i++) {
        if (a[i]>=sum/(4.0*m))  c++;
    }

    if (c>=m)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}