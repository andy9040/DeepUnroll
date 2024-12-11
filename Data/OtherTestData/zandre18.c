#include <stdio.h>

int main() {
    long long sum = 0;
    for (int i = 1; i <= 1000000; i++) {
        sum += i * i * i; // Long cubic sum
        if (i % 100000 == 0) {
            printf("Sum of cubes at %d: %lld\n", i, sum);
        }
    }
    printf("Final cubic sum: %lld\n", sum);
    return 0;
}
