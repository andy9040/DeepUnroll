#include <stdio.h>

int main() {
    int primes[100000];
    int count = 0;

    for (int i = 2; i < 1000000; i++) { // Long prime number generation
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
        if (count % 10000 == 0) {
            printf("Found %d primes\n", count);
        }
        if (count >= 100000) {
            break;
        }
    }
    printf("Total primes found: %d\n", count);
    return 0;
}
