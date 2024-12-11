#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "C programming 101 is fun!";
    char result[100];
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            result[index++] = str[i];
        }
    }
    result[index] = '\0';

    printf("String without digits: %s\n", result);
    return 0;
}
