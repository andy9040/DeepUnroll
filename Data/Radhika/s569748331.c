/*2019/08/25 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MOD 1000000007
#define MIN 1000000009
#define MAX -1000000009
typedef long long int ll;
typedef unsigned long long int ull;
void llswap(ll *x,ll *y){ll temp;temp=*x;*x=*y;*y=temp;}
void swap(int *x,int *y){int tmp;tmp=*x;*x=*y;*y=tmp;}
int rmax(int x,int y){return x>y?x:y;}
int rmin(int x,int y){return x>y?y:x;}
ll llrmax(ll x,ll y){return x>y?x:y;}
ll llrmin(ll x,ll y){return x>y?y:x;}
int asc(const void *a,const void *b){return *(int*)a-*(int*)b;}
int desc(const void *a,const void *b){return *(int*)b-*(int*)a;}
int llasc(const void *a,const void *b){return *(ll*)a-*(ll*)b;}
int lldesc(const void *a,const void *b){return *(ll*)b-*(ll*)a;}
int gcd(int x,int y){if(y==0)return x;return gcd(y,x%y);}
/*
int asc_t(const void *a,const void *b){return ((struct_t*)a)->member - ((struct_t*)b)->member;}
int desc_t(const void *a,const void *b){return ((struct_t*)b)->member - ((struct_t*)a)->member;}
*/


int main(){
    int N,X,x[200000],d[200000];

    scanf("%d %d",&N,&X);
    for(int i=0;i<N;i++){
        scanf("%d",&x[i]);
    }
    x[N]=X;

    qsort(x,N+1,sizeof(int),asc);
    int tmp=x[1]-x[0];
    for(int i=2;i<=N;i++){
        tmp=gcd(x[i]-x[i-1],tmp);    
    }
    printf("%d\n",tmp);
    return 0;

}
