#include <stdio.h>
#define LENGTH 256
#define NUM 5

int main(void) {
    char input[LENGTH];
    int n;
    fgets(input, LENGTH-1, stdin);
    sscanf(input, "%d", &n);
    int m = n % 1000;
    if (m == 0) {
        printf("0");
    }else{
        //int result = 1000 - m;
        printf("%d",1000-m);
    }
    //printf("%d",n);
    
    return 0;
}
