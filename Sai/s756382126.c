/* ex3-3
   Sagzar1993  */


#include <stdio.h>

int main(void) {
    //表す整数と基数を定義
    int num, numBase;

    //入力を受け取る
    scanf("%d %d", &num, &numBase);

    int i = 0, quot;

    if(num <= numBase){
        i = 1;
    }else{
        do{
            quot = num / numBase;
            num = quot;
            i++;
        
            if(quot == 1){
                i++;
                break;
            }
        }while(1);
    }

    printf("%d\n", i);
    
    return 0;
}