#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "Hello, World!";
    
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }

    printf("Uppercase: %s\n", str);
    return 0;
}
