#include <stdio.h>

int main() {
    unsigned long long factorial = 1;
    for (int i = 1; i <= 1000000; i++) { // Long factorial calculation
        factorial *= i;
        if (i % 100000 == 0) {
            printf("Factorial at %d: %llu\n", i, factorial);
        }
    }
    return 0;
}
