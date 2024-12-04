#include <stdio.h>

int main() {
    int i = 1;
    do {
        printf("Loop iteration: %d\n", i);
        i *= 2;
    } while (i < 1024);
    return 0;
}
