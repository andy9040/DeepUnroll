#include<stdio.h>

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
  int a[n],c=0,d=0;
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    c+=a[i];
  }
   for(int i=0;i<n;i++){
    if((double)c/(4*m)<=a[i]){
      d++;
    }
   }
  if(d>=m){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
return 0;
}
