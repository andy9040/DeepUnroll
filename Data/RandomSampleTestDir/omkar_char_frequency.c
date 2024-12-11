
#include <stdio.h>

int main() {
    char str[] = "Programming";
    char target = 'g';
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            count++;
        }
    }

    printf("Character '%c' appears %d times.\n", target, count);
    return 0;
}
