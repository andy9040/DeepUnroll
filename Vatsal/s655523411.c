#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

#define rep(i,begin,end) for(int i=begin; i<end; i++)
#define revrep(i,begin,end) for(int i=begin; i>end; i--)
#define lld long long int

#define MOD 1000000007

int main(){
    char s[100001];
    scanf("%s", s);
    int len = strlen(s);
    int dp[len+1][13];
    rep(i, 0, len+1){
        rep(j, 0, 13){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    rep(i, 1, len+1){
        if(s[i-1] == '?'){
            rep(j, 0, 13){
                rep(k, 0, 10){
                    dp[i][(j*10 + k) % 13] += dp[i-1][j];
                    dp[i][(j*10 + k) % 13] %= MOD;
                }
            }
        }else{
            rep(j, 0, 13){
                dp[i][(j*10 + (s[i-1]-'0')) % 13] += dp[i-1][j];
                dp[i][(j*10 + (s[i-1]-'0')) % 13] %= MOD;
            }
        }
        rep(j, 0, 13){
            dp[i][j] %= MOD;
        }
    }
    printf("%d", dp[len][5]);

    return 0;
}