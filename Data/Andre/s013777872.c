#include<stdio.h>
#include <stdlib.h>

int cmp( const void *p, const void *q ) {
    return *(int*)p - *(int*)q;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    
    int a[100000];
    int b[100000];
    int sum[100000];
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
        sum[i]=a[i]+b[i];
    }
    
    int ss = sizeof(sum)/sizeof( int );
    qsort(sum, ss, sizeof(int), cmp );
    
    long int score=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            score+=a[i];
        }else{
            score-=b[i];
        }
    }
    
    printf("%ld\n",score);
    
    return 0;
}