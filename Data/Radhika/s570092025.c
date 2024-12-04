#include <stdio.h>

int main()
{
    int a, b, c, k, ans = 0;
    scanf("%d %d %d %d", &a, &b, &c, &k);

    if (a < k)
        ans += a;
    else
        ans += k;

    k -= a;
    k -= b;

    if (k > 0)
    {
        if (a < k)
            ans -= c;
        else
            ans -= k;
    }

    printf("%d",ans);

    return 0;
}
