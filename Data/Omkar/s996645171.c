#include<stdio.h>
int main(void){
  int x,y,n,i=0,j=0;
  scanf("%d",&x);
  scanf("%d",&y);
  scanf("%d",&n);
  int a[n][3],s1=x,s2=0,t1=0,t2=y;
  while(i<n){
    scanf("%d",&a[i][0]);
    scanf("%d",&a[i][1]);
    scanf("%d",&a[i][2]);
  }
  n=0;
  for(i=0;i<n;i++){
    if(a[n][2]==1&&(s1>(x-a[n][0]))){
      s1=x-a[n][0];
    }
    if(a[n][2]==2&&(t1<a[n][0])){
      t1=a[n][0];
    }
    if(a[n][2]==3&&(s2<a[n][1])){
      s2=a[n][0];
    }
    if(a[n][2]==4&&(t2>y-a[n][1])){
      t2=y-a[n][1];
    }      
  }
  int tate=s1-t1,yoko=t2-s2;
  if(tate>0&&tate>0){
    printf("%d",tate*yoko);
  }else{
    printf("0");
  }
  return 0;
}
      
        
          
      