#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
//#include<string.h>
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
typedef struct {
    int num;
    int d;
}STRUCT;
int main() {
    STRUCT *D=(STRUCT*)malloc(10000*sizeof(int));
    int n, i,max,tmp,d,dd;
    for (; fscanf(stdin, "%d", &n), n != 0;fprintf(stdout,"%d %d\n",(D+tmp)->num,(D+tmp)->d)) {
        i = 0;
        fscanf(stdin, "%d%d%d", &(D + i)->num, &d, &dd);
        max = (D + i)->d = d + dd,tmp=i;
        for (i = 1; i < n; i++) {
            fscanf(stdin, "%d%d%d", &(D + i)->num, &d, &dd);
            (D + i)->d = d + dd;
            if (d + dd > max)max = d + dd, tmp = i;
        }
    }
    free(D);
    return 0;
}