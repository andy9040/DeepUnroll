#include<stdio.h>
int main(){
  
  int n,m,i,x;
  int sum = 0;
  int a[1001];
  
  scanf("%d %d",&n,&m);
  
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    sum += a[i];
  }
  
  x = (sum / 4) / m;
  
  //printf("%d\n\n",m);
  
  for(i=0;i<n;i++){
    if(x<=a[i]){
      m--;
      if(m==0){
        printf("Yes");
        break;
      }
    }
  }
  
  if(m!=0) printf("No");
  
  return 0;

}