
#include <stdio.h>
#include <string.h>

int main() {
    char str[100] = "HelloWorld";
    char insert[] = " ";
    int position = 5;

    for (int i = strlen(str); i >= position; i--) {
        str[i + strlen(insert)] = str[i];
    }

    for (int i = 0; i < strlen(insert); i++) {
        str[position + i] = insert[i];
    }

    printf("String after insertion: %s\n", str);
    return 0;
}
