#include<stdio.h>

int main(void){
    int i,n,cnt0,cnt1,cnt2,cnt3,x,y,z;
    x = 0, y = 0, z = 0;
    cnt0 = 0,cnt1 = 0,cnt2 = 0; cnt3 = 0;
    scanf("%d",&n);
    long int a[n+1]; 
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(a[i] != 0 ){
            if(x == 0){
            x  = a[i];
            }else if( x != 0 && y == 0){
            y = a[i];
            }else if( x != 0 && y != 0 && z == 0){
            z = a[i];
            }
        }
    }


    for(i=0; i<n; i++){
        if(a[i] == 0){
            cnt0++;
        }else if( a[i] == x ){
            cnt1++;
        }else if( a[i] == y ){
            cnt2++;
        }else if( a[i] == z ){
            cnt3++;
        }
    }

    if( cnt0 == n  || 
      (cnt1 == 2*n/3 && cnt0 == n/3 ) ||
      (x^y^z == 0 && cnt1==n/3 && cnt2==n/3 && cnt3==n/3 ) ){
        printf("Yes\n");
    }else{
        printf("%d\n",z);
    }

    return 0;

}