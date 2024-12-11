
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "  Hello,   World!   ";
    char result[100];
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            result[index++] = str[i];
        }
    }
    result[index] = '\0';

    printf("String without whitespace: %s\n", result);
    return 0;
}
