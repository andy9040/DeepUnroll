#include <stdio.h>
signed main(){
  int N,M,i,j,count=0;
  double sum=0;
  scanf("%d %d",&N,&M);
  int A[100];
  for(i=0;i<N;i++){
    scanf("%d",A+i);
    sum+=A[i];
  }
  sum=sum/(4*M);
  for(i=0;i<N;i++){
    if(A[i]>=sum){
      count++;
    }
  }
  if(count>=M){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return(0);
}