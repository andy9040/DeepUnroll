#include <stdio.h>

int main() {
    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= 100; j++) {
            printf("i = %d, j = %d\n", i, j);
        }
    }
    return 0;
}
