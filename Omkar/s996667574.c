
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long
#define SIZE 4005

int max(int aa, int bb);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long

int max(int aa, int bb);

int main(void) {
    int a_len,b_len,itr,itrA,itrB,dp[4055][4055],tmp,piv_x,piv_y,piv_ans=0,ans_len;
    char a_str[4055],b_str[4055], ans[4055];
    ans[0] = '\0';
    scanf("%s %s",a_str,b_str);
    //配列の長さを取得
    a_len = strlen(a_str);
    b_len = strlen(b_str);
    //初期化
    for(itr = 0;itr <= a_len; itr++){
        dp[itr][0] = 0;
    }
    for(itr = 0;itr <= b_len; itr++){
        dp[0][itr] = 0;
    }
    /*
    dpの計算
    三通りあるので、それらの最大値を取る
    */
    for(itrA = 1;itrA <= a_len; itrA++){
        for(itrB = 1;itrB <= b_len; itrB++){
            dp[itrA][itrB] = max(dp[itrA][itrB-1],dp[itrA-1][itrB]);
            if(a_str[itrA-1]==b_str[itrB-1]){
                tmp = dp[itrA-1][itrB-1] + 1;
                dp[itrA][itrB] = max(dp[itrA][itrB],tmp);
            }
        }
    }
    //右下から探索を始める
    piv_x = a_len;
    piv_y = b_len;
    
    while(piv_x != 0 && piv_y != 0){
        if(dp[piv_x][piv_y] == dp[piv_x-1][piv_y]){
            piv_x--;
        }
        else if(dp[piv_x][piv_y] == dp[piv_x][piv_y-1]){
            piv_y--;
        }
        else{
            //左上なのでansに追加
            ans[piv_ans] = a_str[piv_x-1];
            piv_ans++;
            piv_y--;
        }
    }
    ans_len = strlen(ans);
    //反転しながら出力
    for(itr = ans_len-1;itr >= 0; itr--){
        printf("%c",ans[itr]);
    }
    printf("\n");
    
    return 0;
}
//maxを計算する関数
int max(int aa, int bb) {
    if (aa > bb)
        return aa;
    else
        return bb;
}
