#include <stdio.h>
#include <stdlib.h>

int a[3][3];
int b[10];
int main(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int n;
    scanf("%d", &n);
    for (int k = 0 ; k < n; k++) {
        int b;
        scanf("%d", &b);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i][j] == b) {
                    a[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) {
            goto YES;
        }
        if (a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0) {
            goto YES;
        }
    }
    if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) {
        goto YES;
    }
    if (a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0) {
        goto YES;
    }
    printf("No");
    return 0;

    YES:
    printf("Yes");
    return 0;
}