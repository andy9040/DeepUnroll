#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "Hello, World!";
    int vowels = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        }
    }

    printf("Number of vowels: %d\n", vowels);
    return 0;
}
