
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char result[100];

    strcpy(result, str1);
    strcat(result, str2);

    printf("Merged string: %s\n", result);
    return 0;
}
