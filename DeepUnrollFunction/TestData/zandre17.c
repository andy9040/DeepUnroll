#include <stdio.h>

int main() {
    int array[10000];
    for (int i = 0; i < 10000; i++) {
        array[i] = i;
    }

    for (int i = 0; i < 1000; i++) { // Long nested loop with memory operations
        for (int j = 0; j < 10000; j++) {
            array[j] += i;
        }
        if (i % 100 == 0) {
            printf("Processed iteration %d\n", i);
        }
    }

    printf("Final array[9999]: %d\n", array[9999]);
    return 0;
}
