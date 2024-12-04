/* ex4_1
	kanon */

#include <stdio.h>
#include <math.h>

int main(void)
{

    //与えられる値を入れる数を宣言
    float num,d;

    //変数に値を入力する
    scanf("%f %f",&num,&d);
  

    //全体の長さ/(１人の人が見張れる範囲)を計算
    int ans=ceil(num/(2*d+1));

    printf("%d",ans);

    return 0;
}
