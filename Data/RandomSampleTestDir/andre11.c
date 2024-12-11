#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 0; i < 1000000; i++) { // Long loop
        sum += i;
        if (i % 100000 == 0) {
            printf("Sum at %d: %d\n", i, sum);
        }
    }
    printf("Final Sum: %d\n", sum);
    return 0;
}
