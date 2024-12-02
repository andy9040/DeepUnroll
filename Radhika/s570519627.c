#include<stdio.h>

int main(){

   char a[4],b[4];

   scanf("%s",a);
   scanf("%s",b);

   if(a[0] == b[2] && a[1] == b[1] && a[2] == b[0]){
      printf("YES\n");
   }else{
      printf("NO\n");
   }

   return 0;
}
