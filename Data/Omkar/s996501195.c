#include <stdio.h>
int main(void){
  int N;
  int i,judge=0;
  int A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++)
 	 scanf("%d",&A[i]);
  for(i=0;i<N;i++){
  	if(A[i]%2==0)
      if(A[i]%3!=0||A[i]%3!=0){
        judge=1;
        break;
  	  }
  }
  if(judge=0)
    printf("APPROVED");
  else
    printf("DENIED");
  
  return 0;
}