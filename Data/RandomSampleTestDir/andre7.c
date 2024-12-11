#include <stdio.h>

int main() {
    int primes[50] = {0};
    int count = 0;
    for (int i = 2; i < 100; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            primes[count++] = i;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("Prime: %d\n", primes[i]);
    }
    return 0;
}
