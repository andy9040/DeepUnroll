#include<stdio.h>
#include<math.h>

int main(){
  int N,D,i,j,,count = 0;
  double s;

  
  scanf("%d %d", &N, &D);
   int X[N][D];
  int k = (N * (N-1))/2;
  for(i = 0; i<N; i++){
    for(j = 0; j<D; j++){
      scanf("%d",&X[i][j]);
    }
  }

  for(i=0; i<N-1; i++){
    for(j=i+1; j<D; j++){
       s = 0;
       for(int a =0;a<D;a++){
        s += pow(X[i][j] - X[i+1][j],2);
       }
        double m = sqrt(s);
        if(ceil(m) == floor(m)){
          count++;
        }
    }
  }
  
  printf("%d",count);
  return 0;

}