#include<stdio.h>

int main(){

  int N , M , M_max = 0; /*商品数N、人気商品数M、選べる人気商品数の最大M_max*/
  int A[99]; /*得票数*/
  int sum =0; /*総得票数*/
  
  
  
  scanf("%d %d",&N,&M);
  
  for(int i=0 ;i < N ; i++){
    scanf("%d",&A[i]);
    sum = sum +A[i]; /*総得票数を計算する*/
  }
  
   for(int i=0 ;i < N ; i++){
     if(A[i]=>( sum/(4*M))){
       M_max ++;
     }else{
       /*何もしない*/
     }
   }
  
  if(M <= M_max){
    printf("Yes");
  }else{
    printf("No");
  }
  
  return 0;
  
  }