
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "Hello, World!";
    char result[100];
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            result[index++] = str[i];
        }
    }
    result[index] = '\0';

    printf("String without vowels: %s\n", result);
    return 0;
}
