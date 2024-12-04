
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "programming";
    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }

    printf("Duplicate characters: ");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 1) {
            printf("%c ", i);
        }
    }
    printf("\n");
    return 0;
}
