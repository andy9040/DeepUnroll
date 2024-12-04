/* ex3_3
   kohei0713 */

#include <stdio.h>

int main(void){
    
    int number, base;
    int digits = 0;
    
    //input
    scanf("%d %d", &number, &base);

    //numberがbase以上の間繰り返す
    while(number >= base){
        //桁数を1増やす
        digits = digits + 1;
        //numberをbaseで割った商を計算
        number = number / base;
    }

    //最後に桁数を1増やす
    digits = digits + 1;

    //digitsを表示
    printf("%d\n", digits);

    return 0;
}