#include <stdio.h>

int main() {
    for (int i = 0; i < 1000000; i++) {
        if (i % 2 == 0) {
            printf("Even: %d\n", i);
        } else {
            printf("Odd: %d\n", i);
        }
    }
    return 0;
}
