#include <stdio.h>

int main() {
    int array[100000];
    for (int i = 0; i < 100000; i++) { // Large array processing
        array[i] = i * 2;
    }

    for (int i = 99999; i >= 0; i--) {
        if (i % 10000 == 0) {
            printf("array[%d] = %d\n", i, array[i]);
        }
    }
    return 0;
}
