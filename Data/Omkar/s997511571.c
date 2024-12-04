#include <stdio.h>
#include <math.h>

int main() {
    double q;
    while (1) {
        scanf("%lf", &q);
        if (q == -1) break;
        double d, x = q / 2.0;
        while(1) {
            d = x * x * x - q;
            if (fabs(d) < (0.00001 * q)) break;
            x -= d / 3 / x / x;
        }
        printf("%lf\n", x);
    }
}

