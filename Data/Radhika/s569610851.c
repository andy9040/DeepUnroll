#include <stdio.h>
int main(void){
    // Your code here!
int n;
scanf("%d",&n);
int a[n][n-1],cnt[n];
int i,j;
int flag[n];
for(i=0;i<n;i++){
    flag[i]=0;
    cnt[i]=0;
    for (j=0;j<n-1;j++){
    scanf("%d",&a[i][j]);
        
    }
}

int day=0,olast;
long last=(int)(n*(n-1)/2);
int s;

while( last!=0){
    olast=last;
    day++;
    for(i=0;i<n;i++){

        cnt[i]=0;
        
    }
    
    for(i=0;i<n;i++){
        if(cnt[i]==1 || flag[i]>=n-1){
            continue;
            
        }else{
            s=a[i][flag[i]];
            if(flag[s-1]>=n-1 || cnt[s-1]==1 || i >=s-1){
                continue;
                
            }
            
            if( i+1==a[s-1][flag[s-1]] && s==a[i][flag[i]]  ){
                cnt[i]=1;
                cnt[s-1]=1;
                last--;
                flag[i]++;
                flag[s-1]++;
              
            }
            
        }
    }
    //printf("%ld ",last);
    if(last==olast){
        day=-1;
        break;
    }
}
printf("%d\n",day);
return 0;
}
