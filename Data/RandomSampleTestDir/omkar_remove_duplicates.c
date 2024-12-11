
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "programming";
    char result[100];
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        int found = 0;
        for (int j = 0; j < index; j++) {
            if (result[j] == str[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[index++] = str[i];
        }
    }
    result[index] = '\0';

    printf("String without duplicates: %s\n", result);
    return 0;
}
