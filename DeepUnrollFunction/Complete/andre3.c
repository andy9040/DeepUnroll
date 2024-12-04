#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += i;
        if (i % 100 == 0) {
            printf("Sum up to %d: %d\n", i, sum);
        }
    }
    return 0;
}
