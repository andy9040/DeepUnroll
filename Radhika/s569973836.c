#include <stdio.h>
int main(void){

  int	n;
  int	p[20] = {0};
  int	i;
  int	cnt=0;
  
  scanf("%d", &n);
  for(i=0; i<n; i++){ scanf("%d", &p[i]); }
  
  for(i=1; i<n-1; i++){
    if( ((p[i]<p[i-1]) && (p[i]>p[i+1])) || ((p[i]>p[i-1]) && (p[i]<p[i+1])) ){ cnt++; }
  }
  printf("%d",cnt);
  
  return 0;
}