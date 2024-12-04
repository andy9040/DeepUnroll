#include <stdio.h>
int arr[105];
int k;

void answer(){
   scanf("&d",&k); 
   for(int i = 1;i <= k;i = i + 1){
    scanf("%d",&arr[i]);
    if(arr[i] % 2 ==0){
      if(arr[i] % 5 !=0 && arr[i] % 3 !=0){
        printf("DENIED\n");
        return;
      }
    }
   }
 printf("APPROVED\n");
 return;
}

int main (){
  solve();
  return 0;
}