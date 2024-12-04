#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){

  int N,M;
  int i;
  
  scanf("%d %d",&N,&M);

  int A[N];

  for(i=0; i<N; i++){
      scanf("%d", &A[i]);
   }

  int Awa;
  Awa = 0;
  for(i=0; i<N; i++){
    Awa += A[i];
   }

  int counter;
  counter = 0;

  for(i=0; i<N; i++){
   if( A[i] < Awa/(4*(float)(M)) ){
   }
   else{
     counter += 1;
    }
   }

  if (counter >= M){
    printf("Yes");
  }

  else{
    printf("No");
  }

  return(0);

}

