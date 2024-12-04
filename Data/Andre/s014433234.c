/* ex3-3
   Sagzar1993  */


#include <stdio.h>

int main(void) {
    //表す整数と基数を定義
    int num, numBase;

    //入力を受け取る
    scanf("%d %d", &num, &numBase);

    int i = 0, quot;

    do{
        quot = num / numBase;
        num = quot;
        i++;
    }while(quot > 1);

    printf("%d\n", i);
    
    return 0;
}