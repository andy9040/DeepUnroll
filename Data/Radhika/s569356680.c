#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>
#define MAX 100004

typedef long long ll;

ll X,Y,Z;
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}

ll min(ll a,ll b){
    if(a<b) return a;
    else return b;
}

/*qsort(array,num_of_index,sizeof(ll),compare_int); */
 ll compare_int(const void *a,const void *b){
     return *(ll*) a - *(ll *) b; 
 } 
 
ll b_search(ll* array,ll left,ll right,ll key){
    ll mid = left - (right - left)/2;
     if( right - left == 1){
         if(array[mid]==key)
             return mid;
          else
               return -1;
     }
     if(array[mid]==key)
         return mid;
     else if(array[mid]>key)
         b_search(array,left,mid,key);
     else if(array[mid]<key)
         b_search(array,mid,right,key);
}

ll check(ll ans){
    if(Y*ans + Z*(ans + 1) <= X) return 1;
    else return 0;
}

 ll upper_bound(ll  *array,ll left,ll right){
     if(right-left==1)
         return left;
     ll mid = left + (right - left)/2;
     if(check(mid))
         return upper_bound(array,mid,right);
     else
         return upper_bound(array,left,mid);
 }


ll main(){
    scanf("%lld %lld %lld",&X,&Y,&Z);
    ll num[MAX];
    for(ll i=1;i<MAX;i++)
        num[i] = i;
    printf("%lld",upper_bound(num,1,MAX));
}
