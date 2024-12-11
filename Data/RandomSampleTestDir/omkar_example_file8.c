#include <stdio.h>

int main() {
    char str[] = "Hello, World! Welcome to C programming.";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            str[i] = '-';
        }
    }

    printf("Modified string: %s\n", str);
    return 0;
}
