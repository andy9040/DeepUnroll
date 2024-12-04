#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "Hello World, from C!";
    int wordLength = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i]) || str[i + 1] == '\0') {
            if (str[i + 1] == '\0' && !isspace(str[i]))
                wordLength++;
            if (wordLength > 0)
                printf("Word length: %d\n", wordLength);
            wordLength = 0;
        } else {
            wordLength++;
        }
    }

    return 0;
}
