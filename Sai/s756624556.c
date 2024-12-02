#include <stdio.h>

int main(int argc, const char * argv[])
{

    int H, W;
    int i, j;
    
    while (scanf("%d %d",&H ,&W) != EOF) {
        if (H == 0 && W == 0) break;
        for (i = 0; i < W; i++) {
            printf("#");
        }
        printf("\n");
        for (i = 2; i < H; i++) {
            for (j = 0; j < W; j++) {
                if (j != 0 && j != W - 1) printf(" ");
                else printf("#");
            }
            printf("\n");
        }
        for (i = 0; i < W; i++) {
            printf("#");
        }
        printf("\n\n");
    }
    return 0;
}