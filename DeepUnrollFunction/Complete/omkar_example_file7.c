#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "Hello, World! Welcome to C programming.";
    int words = 0, inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i]) && !inWord) {
            inWord = 1;
            words++;
        } else if (isspace(str[i])) {
            inWord = 0;
        }
    }

    printf("Number of words: %d\n", words);
    return 0;
}
