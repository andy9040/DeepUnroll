#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }

    printf("The string has %d characters.\n", count);
    return 0;
}
