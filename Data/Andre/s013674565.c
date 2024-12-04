#include<stdio.h>

int main(void)
{ 
  int d,n,i,j,k,cnt,dis;
  double distance;
  int za[10][10]={0};
  scanf("%d %d",&n,&d);
 k=cnt=dis=0;
 distance=0;
 for(i=0;i<n;i++){
   for(k=0;k<d;k++){
     scanf("%d",&j);
     za[i][k]=j;
   }
 }
for(i=0;i<n;i++)
 for(k=i+1;k<n;k++){
   dis=distance=0;
   for(j=0;j<d;j++)
    dis+=(za[i][j]-za[k][j])*(za[i][j]-za[k][j]);
    distance=sqrt((double)dis);
    dis=sqrt(dis);
    if(distance==dis)cnt++;
 }
 printf("%d",cnt);
  return 0;
}