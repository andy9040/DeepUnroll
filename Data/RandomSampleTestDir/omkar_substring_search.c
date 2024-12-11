
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    char substr[] = "World";
    if (strstr(str, substr)) {
        printf("Substring found.\n");
    } else {
        printf("Substring not found.\n");
    }
    return 0;
}
