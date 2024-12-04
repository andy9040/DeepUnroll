#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<tgmath.h>
#include<stdbool.h>
#include<sys/queue.h>
#include<time.h>
#define ll long long
#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, k, a[200200], b[200200];

int main(){
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++)scanf("%d", &a[i]);
    while(k--){
        bool flg = true;
        for(int j=0; j<=n; j++)b[j] = 0;
        for(int i=0; i<n; i++){
            b[max(0, i-a[i])]++;
            b[min(n, i+a[i]+1)]--;
        }
        for(int i=0; i<n; i++){
            if(i)b[i]+=b[i-1];
            flg &= (a[i]=b[i]) == n;
        }
        if(flg)break;
    }
    for(int i=0; i<n; i++){
        if(i)putchar(32);
        printf("%d", a[i]);
    }putchar(10);
   return 0;
}