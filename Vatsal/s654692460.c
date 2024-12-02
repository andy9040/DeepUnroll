// AtCoder165 C

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>

// qsortで用いる比較用関数．*a<*bならaが先になる．
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int revcompare(const void* a, const void* b) {
    return *(int*)b- *(int*)a;
}


int main() {
    int i,j;
    int n;
    char s[11];
    int cnt=0,max = 0;;

    scanf("%s", s);

    for(i=0;i<strlen(s)-1; i++){
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
            cnt++;
        }else{
            if(cnt > max) max = cnt;
            cnt = 0;
        }
    }
    if(cnt > max) max = cnt;
    printf("%d", max);
    return 0;
}