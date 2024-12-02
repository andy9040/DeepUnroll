#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef long long ll;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define max(l,r) ((l)>(r)?l:r)
#define min(l,r) ((l)<(r)?l:r)
#define swap(l,r) {ll tp=l;l=r;r=tp;}
const ll MOD = 1000000007;
int upcmpii(const void *a, const void *b){
        return (*(int*)a == *(int*)b ? 0 : (*(int*)a > *(int*)b ? 1 : -1));
    }
    void sort_ui(int *a, int n){ qsort(a, n, sizeof(int), upcmpii);}

int main(){
    //input
    int n;
    scanf("%d", &n);
    int a[101010];
    rep(i, n) scanf("%d", a+i);

    //solve
    sort_ui(a, n);
    int tmp[101010], cnt[101010] = {0}, idx = 0;
    tmp[0] = a[0];
    cnt[0] = 1;
    rep(i, n-1){
        if(tmp[idx] != a[i+1]){
            idx++;
            tmp[idx] = a[i+1];
        }
        cnt[idx]++;
    }

    //output
    int ng = 0;
    if(idx >= 3) ng = 1;
    else if(idx == 2){
        if(n%3 != 0 || cnt[0] != n/3 || cnt[1] != n/3 || cnt[2] != n/3 || ((tmp[0]^tmp[1])^tmp[2] != 0))
            ng = 1;
    }else if(idx == 1){
        if(n%3 != 0 || tmp[0] != 0 || cnt[1] != 2*n/3)
            ng = 1;
    }else{
        if(tmp[0] != 0)
            ng = 1;
    }
    if(ng) puts("No");
    else puts("Yes");
}