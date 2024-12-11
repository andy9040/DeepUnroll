
#include <stdio.h>

int main() {
    char str[] = "banana";
    char find = 'a';
    char replace = 'o';

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == find) {
            str[i] = replace;
        }
    }

    printf("Modified string: %s\n", str);
    return 0;
}
