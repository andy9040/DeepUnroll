#include <stdio.h>

int main(void) {
    int x1,x2,y1,y2,a,b;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    a = y2 - y1;
    b = x2 - x1;
    printf("%d %d %d %d\n",(x1 + b - a),(y1 + a + b),(x1 - a),(y1 + b));
    return 0;
}