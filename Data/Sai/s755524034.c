#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int p(int i){
  int d,dmax;

  if(i == 2)
    return 1;

  dmax = sqrt(i)+1;
  for(d = 2; d <= dmax; d++){
	if(i%d == 0){
	  return 0;
	}

      }
  return 1;
}

int main(){
  int n;
  int i,j,count;

  

  while(1){
    scanf("%d", &n);
    if(n == 0)
      break;
    count=0;
    for(i = n+1  ; i <= 2*n ; i++){
      count += p(i);
    }
    printf("%d\n",count);
    
  }
  return 0;
}
	
	
  

