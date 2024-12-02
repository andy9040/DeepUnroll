#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int desc(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}
int main(void){
    int n,m,i,sum=0;
    scanf("%d%d",&n,&m);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    qsort(a,n,sizeof(int),desc);
    int s=ceil(sum/(4*m)+0.9);
    if(a[m-1]>=s) printf("Yes");
    else printf("No");
    return 0;
}
