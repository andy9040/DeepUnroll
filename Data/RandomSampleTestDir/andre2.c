#include <stdio.h>

int main() {
    int i = 0, j;
    while (i < 50) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
        i += 5;
    }
    return 0;
}