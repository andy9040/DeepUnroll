/* ex3_3
        fmuacshai */

#include<stdio.h>
//math関数を導入
#include<math.h>
int main(void){
    //整数n、進数k、桁数mを整数定義
    int n,k,m;
    //nの入力
    scanf("%d",&n);
    //kの入力
    scanf("%d",&k);
    //mの初期設定
    m=1;
    //(m+1)桁の最小の数字以上であるかチェック
    while(n>=pow(k,m)){
        m=m+1;
    }
    //求めた桁数mの出力
    printf("%d\n",m);
    return 0;
}
    
    