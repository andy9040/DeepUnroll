#include <stdio.h>

int main() {
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if ((i * j) % 7 == 0) {
                count++;
            }
        }
    }
    printf("Count of divisible by 7: %d\n", count);
    return 0;
}
