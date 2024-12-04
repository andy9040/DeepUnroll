#include<stdio.h>
#include<math.h>
int main() {
    int n, i;
    double m, a, s[1000], sum;
    while (1) {
        a = 0;
        sum = 0;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        for (i = 0;i < n;i++) {
            scanf("%lf", &s[i]);
            sum += s[i];
        }
        m = sum / n;
        for (i = 0;i < n;i++) {
            a += (s[i] - m)*(s[i] - m) / n;
        }
        printf("%.8lf\n", sqrt(a));
    }
    return 0;
}