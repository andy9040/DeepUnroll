#include <stdio.h>
#define A 20
#define M 200

int n,a[A],f=0;
 

int cal(int i, int m)
{
 
  if(m == 0){
    f = 1;
   return 1;
  }
   
   else if(i < n){
    cal(i+1, m);
    cal(i+1, m - a[i]);
  
     }
}

int main()
{
 
  int i,j;
  int b[M];
  int q;
   
  scanf("%d",&n);
   
  for(i = 0; i < n; i++){
    
     scanf("%d",&a[i]);
  }
 
  scanf("%d",&q);
   
  for(j = 0; j < q; j++){
    
     scanf("%d",&b[j]);
  }
   
   
  for(i = 0; i < q; i++){
    f = 0;
    cal(0,b[i]);
    
    if(f == 1) printf("yes\n");
    
    else  printf("no\n");
    
  }
 
  return 0;
}
 
 