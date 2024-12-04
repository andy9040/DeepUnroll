#include<stdio.h>
#include<math.h>
int main(){
  int n,d;
  double tmp=0;
  int x[10][10]={};
  int ans=0;
  scanf("%d %d",&n,&d);
  for(int i=0;i<n;i++){
    for(int j=0;j<d;j++){
      scanf("%d",&x[i][j]);
      //printf("%d\n",x[i][j]);
    }
  }
  for(int i=0;i<n-1;i++){
    for(int a=i+1;a<n;a++){
      for(int j=0;j<d;j++){
        //printf("i,a,j=%d,%d,%d\n",i,a,j);
        tmp=tmp+pow(abs(x[i][j]-x[a][j]),2.0);
      }
      if(ceil(sqrt(tmp)) == floor(sqrt(tmp))){
        ans++;
        tmp=0;
        //printf("a=%d,i=%d\n",a,i);
      }
    }
  }
printf("%d\n",ans);
return 0;
}