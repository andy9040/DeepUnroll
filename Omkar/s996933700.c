#include <stdio.h>
int main(void){
   int n;
   long sum=0;
   int j,i;
   int c=0;
   
   scanf("%d",&n);
   
   for(i=1; i<=n; i++){
       c=0;
       for(j=1;j<=i; j++){
           if(i%j==0){
               c++;
           }
       }
       sum+=i*c;
   }
   
   printf("%d",sum);
    return 0;
}