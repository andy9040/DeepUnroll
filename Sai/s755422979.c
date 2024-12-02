#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    intmax_t A[3][3], N, b[10];
    intmax_t ans = 0;

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            scanf("%jd", &A[i][j]);
        }
    }
    scanf("%jd", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%jd", &b[i]);
    }

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            for (size_t k = 0; k < N; k++) {
                if (A[i][j] == b[k]) {
                    A[i][j] = 0;
                }
            }
        }
    }

    for (size_t i = 0; i < 3; i++) {
        bool bingo = true;
        for (size_t j = 0; j < 3; j++) {
            if (A[i][j] != 0)
                bingo = false;
        }
        if (bingo) {
            puts("Yes");
            return 0;
        }
    }

    for (size_t j = 0; j < 3; j++) {
        bool bingo = true;
        for (size_t i = 0; i < 3; i++) {
            if (A[i][j] != 0)
                bingo = false;
        }
        if (bingo) {
            puts("Yes");
            return 0;
        }
    }

    if (A[0][0] == 0 && A[1][1] == 0 && A[2][2] == 0) {
        puts("Yes");
        return 0;
    }

    if (A[0][2] == 0 && A[1][1] == 0 && A[2][0] == 0) {
        puts("Yes");
        return 0;
    }

    puts("No");

    return 0;
}
