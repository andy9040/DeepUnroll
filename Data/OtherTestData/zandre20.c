#include <stdio.h>

int main() {
    unsigned long long fib[100000];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 100000; i++) { // Long Fibonacci sequence
        fib[i] = fib[i - 1] + fib[i - 2];
        if (i % 10000 == 0) {
            printf("Fib[%d]: %llu\n", i, fib[i]);
        }
    }
    printf("Fib[99999]: %llu\n", fib[99999]);
    return 0;
}
